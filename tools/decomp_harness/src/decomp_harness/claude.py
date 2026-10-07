"""Optional Claude Code subprocess backend. Never API/Console authentication."""
import hashlib
import json
from pathlib import Path
import re

from .codex import CodexRunner, clean_environment, parse_events
from .common import HarnessError, command


def clean_claude_environment(environ=None):
    return clean_environment(environ, provider='claude')


def check_subscription(status):
    if (not isinstance(status, dict) or status.get('loggedIn') is not True
            or status.get('authMethod') != 'claude.ai' or status.get('apiProvider') != 'firstParty'
            or status.get('subscriptionType') not in ('pro', 'max')
            or status.get('forcedLoginMethod') not in (None, 'claudeai')):
        raise HarnessError('Claude Pro/Max subscription authentication is not confirmed. Run claude, use /login and choose your Claude subscription (not Console). API keys and provider overrides are not used; no fallback.')


def parse_claude_events(text, exit_code, last_message='', interrupted=False, timed_out=False):
    converted = []
    for line in text.splitlines():
        try:
            event = json.loads(line)
        except ValueError:
            converted.append(line)
            continue
        if not isinstance(event, dict):
            converted.append(line)
            continue
        if event.get('type') != 'result':
            continue
        if event.get('is_error') or event.get('subtype') != 'success':
            converted.append(json.dumps({'type': 'error', 'message': event.get('errors') or event.get('result') or event.get('subtype')}))
            continue
        usage = event.get('usage') or {}
        uncached = usage.get('input_tokens', 0)
        cached, written = usage.get('cache_read_input_tokens', 0), usage.get('cache_creation_input_tokens', 0)
        # Same convention as Codex: total input includes cached input.
        normalized = {'input_tokens': uncached+cached+written, 'cached_input_tokens': cached,
                      'cache_write_input_tokens': written, 'output_tokens': usage.get('output_tokens', 0)}
        message = event.get('structured_output', event.get('result', ''))
        last_message = json.dumps(message) if isinstance(message, dict) else str(message)
        converted.append(json.dumps({'type': 'turn.completed', 'usage': normalized}))
    return parse_events('\n'.join(converted), exit_code, last_message, interrupted, timed_out)


class ClaudeRunner(CodexRunner):
    provider = 'claude'
    authentication_label = 'Claude Pro/Max subscription only'

    def base_args(self):
        # --bare explicitly disables OAuth: NEVER use it for subscription workers.
        return [self.executable, '--safe-mode', '--setting-sources', '',
                '--settings', '{"forceLoginMethod":"claudeai"}']

    def authenticate(self):
        self.version = command([self.executable, '--version'], env=self.env).stdout.decode().strip()
        match = re.search(r'(\d+)\.(\d+)\.(\d+)', self.version)
        if not match or tuple(map(int, match.groups())) < (2, 1, 292):
            raise HarnessError('Claude Code >=2.1.292 required for the tested restricted/safe-mode flags')
        help_text = command([self.executable, '--help'], env=self.env).stdout.decode()
        for flag in ('--safe-mode', '--restricted', '--setting-sources', '--strict-mcp-config', '--json-schema', '--tools', '--effort'):
            if flag not in help_text:
                raise HarnessError(f'Claude CLI lacks required flag {flag}; update it')
        result = command([*self.base_args(), 'auth', 'status', '--json'], cwd='/tmp', env=self.env, check=False)
        try:
            status = json.loads(result.stdout)
        except ValueError as e:
            raise HarnessError('Claude auth status was not valid JSON; failing closed') from e
        check_subscription(status)
        if result.returncode:
            raise HarnessError('Claude subscription status failed; no worker started')
        self.auth_id = hashlib.sha256(json.dumps([status.get('orgId'), status.get('email'), status['subscriptionType']]).encode()).hexdigest()
        return {'version': self.version, 'authentication': self.authentication_label,
                'credential_overrides': 'allowlisted environment; safe-mode; forced claudeai; user/project settings ignored'}

    def argv(self, cwd, model, effort, output, schema=None, read_only=False):
        args = [*self.base_args(), '--print', '--restricted', '--strict-mcp-config',
                '--no-session-persistence', '--no-chrome', '--disable-slash-commands',
                '--permission-mode', 'dontAsk', '--permission-prompts', 'none',
                '--output-format', 'stream-json', '--verbose', '--model', model, '--effort', effort,
                '--name', str(output.parent),
                '--tools', '' if read_only else 'Read,Edit',
                '--allowedTools', '' if read_only else 'Read,Edit',
                '--disallowedTools', 'Read(.git),Edit(.git),Read(.git/**),Edit(.git/**)',
                '--system-prompt', 'Return exactly the requested response; no tools.' if read_only
                else Path(__file__).with_name('worker-instructions.md').read_text()]
        if schema:
            args += ['--json-schema', Path(schema).read_text()]
        return args

    parse_output = staticmethod(parse_claude_events)
