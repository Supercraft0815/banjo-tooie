from __future__ import annotations

from dataclasses import dataclass, field
import json
import hashlib
import os
from pathlib import Path
import re
import shutil
import subprocess
import threading
import time

from .common import Control, HarnessError, command, save_json, terminate_group

# Deliberately allowlist, not a blacklist that misses the next credential override.
SAFE_ENV = {'PATH', 'HOME', 'USER', 'LOGNAME', 'LANG', 'LC_ALL', 'TMPDIR', 'TERM',
            'SSL_CERT_FILE', 'SSL_CERT_DIR', 'CODEX_CA_CERTIFICATE', 'SYSTEMROOT'}
REQUIRED_FLAGS = ('--json', '--output-schema', '--output-last-message', '--ignore-user-config',
                  '--ignore-rules', '--ephemeral', '--sandbox', '--skip-git-repo-check')


def clean_environment(environ=None, provider='codex'):
    if provider not in ('codex', 'claude'):
        raise HarnessError('Unknown credential provider')
    original = os.environ if environ is None else environ
    allowed = SAFE_ENV if provider == 'codex' else SAFE_ENV - {'CODEX_CA_CERTIFICATE'}
    env = {k: v for k, v in original.items() if k in allowed}
    key = 'CODEX_HOME' if provider == 'codex' else 'CLAUDE_CONFIG_DIR'
    env[key] = str(Path(original.get(key, str(Path(env.get('HOME', '~')).expanduser() / ('.'+provider)))).resolve())
    return env


def check_auth_document(auth):
    if not isinstance(auth, dict) or auth.get('auth_mode') != 'chatgpt' or auth.get('OPENAI_API_KEY'):
        raise HarnessError('Stored credentials are not unambiguously ChatGPT-only. Run codex logout, then codex -c cli_auth_credentials_store="file" login and sign in with ChatGPT. Never supply an API key.')
    tokens = auth.get('tokens')
    if not isinstance(tokens, dict) or not all(isinstance(tokens.get(k), str) and tokens[k] for k in ('access_token', 'refresh_token', 'id_token', 'account_id')):
        raise HarnessError('Incomplete stored ChatGPT credentials. Run codex -c cli_auth_credentials_store="file" login.')


class Redactor:
    def __init__(self, auth=None):
        self.secrets = [v for k, v in (auth or {}).get('tokens', {}).items() if k != 'account_id' and isinstance(v, str) and v]

    def __call__(self, text):
        for secret in self.secrets:
            text = text.replace(secret, '[REDACTED_SECRET]')
        text = re.sub(r'\bsk-[A-Za-z0-9_-]{12,}', '[REDACTED_SECRET]', text)
        text = re.sub(r'eyJ[A-Za-z0-9_-]{8,}\.[A-Za-z0-9_-]+\.[A-Za-z0-9_-]+', '[REDACTED_SECRET]', text)
        text = re.sub(r'("(?:access_token|refresh_token|id_token|OPENAI_API_KEY|CODEX_API_KEY)"\s*:\s*)"[^"\n]*"', r'\1"[REDACTED_SECRET]"', text)
        return text


@dataclass
class Result:
    exit_code: int
    outcome: str
    events: list = field(default_factory=list)
    usage: dict = field(default_factory=dict)
    message: dict | str | None = None
    error: str = ''
    duration: float = 0


def parse_events(text: str, exit_code: int, last_message='', interrupted=False, timed_out=False):
    events, errors, usage = [], [], {}
    malformed = 0
    for line in text.splitlines():
        try:
            event = json.loads(line)
        except ValueError:
            malformed += bool(line.strip())
            continue
        if not isinstance(event, dict):
            malformed += 1
            continue
        events.append(event)
        if event.get('type') in ('error', 'turn.failed'):
            errors.append(str(event.get('error', event.get('message', event))))
        if event.get('type') == 'turn.completed' and isinstance(event.get('usage'), dict):
            usage = event['usage']
    message = last_message.strip()
    if not message:
        messages = [e.get('item', {}).get('text', '') for e in events
                    if e.get('type') == 'item.completed' and e.get('item', {}).get('type') == 'agent_message']
        message = messages[-1] if messages else ''
    diagnostic = ' '.join(errors).lower()
    if interrupted:
        outcome = 'interrupted'
    elif timed_out:
        outcome = 'timeout'
    elif any(t in diagnostic for t in ('usage limit', 'quota', 'rate limit', 'usage_limit', 'rate_limit')):
        outcome = 'quota_error'
    elif any(t in diagnostic for t in ('not supported', 'model_not_found', 'model is not', 'unknown model', 'model does not')):
        outcome = 'model_error'
    elif any(t in diagnostic for t in ('unauthorized', 'authentication', 'login', 'token expired', 'refresh token')):
        outcome = 'auth_error'
    elif exit_code or errors or malformed:
        outcome = 'technical_error'
    elif not any(e.get('type') == 'turn.completed' for e in events) or not message:
        outcome = 'agent_error'
    else:
        outcome = 'ok'
    try:
        message = json.loads(message)
    except ValueError:
        pass
    return Result(exit_code, outcome, events, usage, message, '; '.join(errors)[-3000:])


class CodexRunner:
    provider = 'codex'
    authentication_label = 'stored ChatGPT only'
    def __init__(self):
        self.env = clean_environment(provider=self.provider)
        self.executable = shutil.which(self.provider, path=self.env.get('PATH'))
        if not self.executable:
            raise HarnessError(f'{self.provider} not found in PATH; install/update its official CLI and sign in with your subscription')
        self.redact = Redactor()
        self.version = ''

    def authenticate(self):
        authfile = Path(self.env['CODEX_HOME']) / 'auth.json'
        try:
            auth = json.loads(authfile.read_text())
        except (OSError, ValueError) as e:
            raise HarnessError('Cannot verify file-based ChatGPT authentication. Run codex -c cli_auth_credentials_store="file" login. Keyring-only auth fails closed in this harness.') from e
        check_auth_document(auth)
        self.auth_id = hashlib.sha256(auth['tokens']['account_id'].encode()).hexdigest()
        self.redact = Redactor(auth)
        self.version = command([self.executable, '--version'], env=self.env).stdout.decode().strip()
        match = re.search(r'(\d+)\.(\d+)\.(\d+)', self.version)
        if not match or tuple(map(int, match.groups())) < (0, 161, 0):
            raise HarnessError(f'{self.version}: CLI >=0.161.0 required for the tested isolation flags; update Codex')
        help_text = command([self.executable, 'exec', '--help'], env=self.env).stdout.decode()
        if any(flag not in help_text for flag in REQUIRED_FLAGS):
            raise HarnessError('Codex exec lacks required isolation/output flags; update the CLI')
        main_help = command([self.executable, '--help'], env=self.env).stdout.decode()
        if '--no-daemon' not in main_help:
            raise HarnessError('Codex must support --no-daemon for isolated worker authentication')
        # Status is checked from a neutral directory; exec additionally ignores user config.
        p = command([self.executable, '-c', 'cli_auth_credentials_store="file"',
                     '-c', 'forced_login_method="chatgpt"', 'login', 'status'],
                    cwd='/tmp', env=self.env, check=False)
        status = self.redact((p.stdout + p.stderr).decode(errors='replace'))
        if p.returncode or 'Logged in using ChatGPT' not in status or 'API key' in status:
            raise HarnessError('codex login status did not confirm ChatGPT. Run codex login interactively; no API fallback is permitted.')
        return {'version': self.version, 'authentication': 'ChatGPT (stored file, forced)',
                'credential_overrides': 'child environment allowlisted; user config ignored'}

    def argv(self, cwd, model, effort, output, schema=None, read_only=False):
        shell_env = ('shell_environment_policy.set={PATH='+json.dumps(self.env.get('PATH', '/usr/bin:/bin'))+
                     ',TMPDIR='+json.dumps(str(cwd/'build/tmp'))+
                     # zsh puts here-documents under TMPPREFIX (default /tmp/zsh), not TMPDIR.
                     ',TMPPREFIX='+json.dumps(str(cwd/'build/tmp/zsh'))+',PYTHONDONTWRITEBYTECODE="1"}')
        args = [self.executable, '--no-daemon', 'exec', '--ignore-user-config', '--ignore-rules',
                '--ephemeral', '--skip-git-repo-check', '--json', '--color', 'never',
                '--sandbox', 'read-only' if read_only else 'workspace-write', '--cd', str(cwd),
                '--model', model, '--output-last-message', str(output),
                '-c', 'forced_login_method="chatgpt"', '-c', 'cli_auth_credentials_store="file"',
                '-c', 'model_provider="openai"', '-c', 'chatgpt_base_url="https://chatgpt.com/backend-api/"',
                '-c', 'approval_policy="never"', '-c', 'sandbox_workspace_write.network_access=false',
                '-c', 'sandbox_workspace_write.exclude_tmpdir_env_var=true',
                '-c', 'sandbox_workspace_write.exclude_slash_tmp=true',
                '-c', 'project_doc_max_bytes=0', '-c', 'web_search="disabled"',
                '-c', 'features.multi_agent=false', '-c', 'features.memories=false',
                '-c', 'features.apps=false', '-c', 'features.plugins=false',
                '-c', 'features.skip_host_skill_discovery=true', '-c', 'features.skill_search=false',
                '-c', 'features.shell_snapshot=false',
                '-c', 'shell_environment_policy.inherit="none"', '-c', 'allow_login_shell=false',
                '-c', shell_env,
                '-c', f'model_reasoning_effort={json.dumps(effort)}']
        if not read_only:
            args += ['-c', 'model_instructions_file='+json.dumps(str(Path(__file__).with_name('worker-instructions.md')))]
        if schema:
            args += ['--output-schema', str(schema)]
        return args + ['-']

    def run(self, *, cwd: Path, prompt: str, model: str, effort: str, directory: Path,
            timeout: float, control: Control, schema=None, read_only=False, on_start=None):
        self.authenticate()  # No cached credential decision, including on retries.
        directory.mkdir(parents=True, exist_ok=True, mode=0o700)
        (directory / 'prompt.txt').write_text(self.redact(prompt))
        output = directory / 'response.json'
        (cwd/'build/tmp').mkdir(parents=True, exist_ok=True)
        args = self.argv(cwd, model, effort, output, schema, read_only)
        start, interrupted, timed_out = time.monotonic(), False, False
        started_at = time.time()
        save_json(directory/'invocation.json', {'model': model, 'effort': effort, 'cwd': str(cwd),
                  'timeout': timeout, 'started': started_at, 'version': self.version,
                  'authentication': self.authentication_label, 'provider': self.provider})
        log_overflow = threading.Event()

        def drain(stream, path):
            size = 0
            with path.open('w') as dest:
                for raw in iter(lambda: stream.readline(1024 * 1024), b''):
                    line = self.redact(raw.decode(errors='replace'))
                    size += len(line)
                    if size > 16 * 1024 * 1024:
                        log_overflow.set()
                        continue
                    dest.write(line)
                    dest.flush()
            stream.close()

        try:
            p = subprocess.Popen(args, cwd=cwd, env=self.env, stdin=subprocess.PIPE,
                                 stdout=subprocess.PIPE, stderr=subprocess.PIPE, start_new_session=True)
        except OSError as e:
            return Result(127, 'technical_error', error=str(e))
        threads = [threading.Thread(target=drain, args=(p.stdout, directory/'stdout.jsonl')),
                   threading.Thread(target=drain, args=(p.stderr, directory/'stderr.txt'))]
        for thread in threads:
            thread.start()
        try:
            if on_start:
                on_start(p.pid)
            try:
                p.stdin.write(prompt.encode())
                p.stdin.close()
            except BrokenPipeError:
                pass
            while p.poll() is None:
                interrupted = control.stopped()
                timed_out = time.monotonic() - start >= timeout
                if interrupted or timed_out or log_overflow.is_set():
                    terminate_group(p)
                    break
                time.sleep(0.15)
        finally:
            terminate_group(p)
            for thread in threads:
                thread.join(timeout=10)
        message = self.redact(output.read_text()) if output.exists() else ''
        if output.exists():
            output.write_text(message)
        result = self.parse_output((directory/'stdout.jsonl').read_text(), p.returncode, message, interrupted, timed_out)
        stderr = (directory/'stderr.txt').read_text()
        if result.outcome == 'technical_error' and stderr:
            detail = parse_events(json.dumps({'type': 'error', 'message': stderr[-3000:]}), p.returncode)
            result.outcome, result.error = detail.outcome, detail.error
        if schema and result.outcome == 'ok' and not isinstance(result.message, dict):
            result.outcome, result.error = 'agent_error', 'Final message did not satisfy the JSON object contract'
        if log_overflow.is_set():
            result.outcome, result.error = 'technical_error', 'Worker output exceeded 16 MiB limit'
        result.duration = time.monotonic() - start
        save_json(directory/'timing.json', {'started': started_at, 'ended': time.time(), 'duration': result.duration})
        save_json(directory/'result.json', {k: v for k, v in vars(result).items() if k != 'events'})
        return result

    parse_output = staticmethod(parse_events)
