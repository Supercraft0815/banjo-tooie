from __future__ import annotations

import contextlib
import fcntl
import hashlib
import json
import os
from pathlib import Path
import signal
import subprocess
import time
import tomllib

ROM_SHA1 = "af1a89e12b638b8d82cc4c085c8e01d4cba03fb3"
DECOMPRESSED_SHA1 = "af479771ff5e91ce3732f3d84146614ab71d8d79"


class HarnessError(Exception):
    pass


def digest(path: Path, algorithm="sha256") -> str:
    h = hashlib.new(algorithm)
    with path.open("rb") as f:
        for block in iter(lambda: f.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def atomic_write(path: Path, data: bytes | str):
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_name(path.name + ".tmp")
    with tmp.open("wb") as f:
        f.write(data.encode() if isinstance(data, str) else data)
        f.flush()
        os.fsync(f.fileno())
    tmp.replace(path)
    fd = os.open(path.parent, os.O_RDONLY)
    try:
        os.fsync(fd)
    finally:
        os.close(fd)


def save_json(path: Path, value):
    atomic_write(path, json.dumps(value, indent=2, ensure_ascii=False) + "\n")


def command(args, cwd=None, timeout=60, env=None, check=True):
    try:
        p = subprocess.run([str(a) for a in args], cwd=cwd, env=env, timeout=timeout,
                           stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    except (OSError, subprocess.TimeoutExpired) as e:
        raise HarnessError(f"Cannot run {args[0]}: {type(e).__name__}") from e
    if check and p.returncode:
        raise HarnessError(f"{args[0]} exited {p.returncode}: {p.stderr.decode(errors='replace')[-2000:]}")
    return p


def git(root: Path, *args, check=True) -> str:
    return command(["git", "-c", "core.quotePath=false", *args], root, check=check).stdout.decode().strip()


def load_config(root: Path):
    cfg = tomllib.loads(Path(__file__).with_name("default.toml").read_text())
    local = root / ".decomp-agent/config.toml"
    if local.exists():
        values = tomllib.loads(local.read_text())
        for k, v in values.items():
            if k not in cfg:
                raise HarnessError(f"Unknown configuration key: {k}")
            cfg[k] = {**cfg[k], **v} if isinstance(v, dict) else v
    if type(cfg['concurrency']) is not int or cfg['concurrency'] not in (1, 2):
        raise HarnessError('concurrency must be 1 or 2 (isolated workers)')
    for k in ('local_patterns', 'claude_enabled'):
        if type(cfg[k]) is not bool:
            raise HarnessError(f'{k} must be boolean')
    if cfg["build"]["backend"] not in ("native", "docker"):
        raise HarnessError("build.backend must be native or docker")
    for k in ("worker_timeout", "build_timeout", "context_chars", "max_attempts_per_function", "stagnation_window"):
        if not isinstance(cfg[k], int) or cfg[k] <= 0:
            raise HarnessError(f"{k} must be a positive integer")
    for k in ('technical_retries', 'extra_attempts'):
        if not isinstance(cfg[k], int) or cfg[k] < 0:
            raise HarnessError(f'{k} must be a nonnegative integer')
    for k in ('probe_cache_hours', 'minimum_gain'):
        if not isinstance(cfg[k], (int, float)) or cfg[k] < 0:
            raise HarnessError(f'{k} must be nonnegative')
    if not isinstance(cfg['build']['jobs'], int) or cfg['build']['jobs'] < 1:
        raise HarnessError('build.jobs must be a positive integer')
    if cfg['banjo_kazooie_repo'] and not Path(cfg['banjo_kazooie_repo']).expanduser().is_dir():
        raise HarnessError('Configured banjo_kazooie_repo does not exist')
    if not isinstance(cfg['routing'], list) or not cfg['routing']:
        raise HarnessError('routing must contain at least one stage')
    if type(cfg['easy_model'].get('enabled')) is not bool:
        raise HarnessError('easy_model.enabled must be boolean')
    for stage in [*cfg['routing'], cfg['easy_model']]:
        validate_stage(stage, cfg['claude_enabled'])
    return cfg


def validate_stage(stage, claude_enabled):
    if not isinstance(stage, dict) or not {'model', 'effort', 'attempts'} <= set(stage) or set(stage) - {'model', 'effort', 'attempts', 'provider', 'enabled'}:
        raise HarnessError('Each routing stage needs model, effort, attempts and an optional provider')
    if not isinstance(stage['model'], str) or not stage['model'] or type(stage['attempts']) is not int or stage['attempts'] < 1 or stage['effort'] not in ('low', 'medium', 'high', 'xhigh'):
        raise HarnessError('Invalid routing stage model, effort or attempts')
    if stage.get('provider', 'codex') not in ('codex', 'claude'):
        raise HarnessError('Only subscription CLI providers codex and claude are supported')
    if stage.get('provider') == 'claude' and not claude_enabled:
        raise HarnessError('Claude routing requires claude_enabled=true and a verified Claude Pro/Max login')
    if stage.get('provider') == 'claude' and stage['effort'] == 'xhigh':
        raise HarnessError('Claude effort must be low, medium or high; xhigh is a Codex setting')


@contextlib.contextmanager
def locked(state: Path):
    state.mkdir(parents=True, exist_ok=True, mode=0o700)
    with (state / "lock").open("a+") as f:
        try:
            fcntl.flock(f, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except BlockingIOError as e:
            raise HarnessError("Another harness process holds .decomp-agent/lock") from e
        yield


class Control:
    def __init__(self, seconds=None):
        self.deadline = time.monotonic() + seconds if seconds is not None else float("inf")
        self.cancelled = False
        self.stop_after = False
        self.old_handlers = {}

    def install(self):
        for sig in (signal.SIGINT, signal.SIGTERM):
            self.old_handlers[sig] = signal.signal(sig, self._signal)

    def _signal(self, *_):
        self.cancelled = True

    def restore(self):
        for sig, handler in self.old_handlers.items():
            signal.signal(sig, handler)

    def stopped(self):
        return self.cancelled or time.monotonic() >= self.deadline


def terminate_group(p):
    if p.poll() is not None:
        return
    try:
        os.killpg(p.pid, signal.SIGTERM)
        p.wait(timeout=3)
    except subprocess.TimeoutExpired:
        os.killpg(p.pid, signal.SIGKILL)
        p.wait()
    except ProcessLookupError:
        pass


def run_logged(args, cwd: Path, log: Path, timeout: float, control: Control, env=None):
    """Build processes also obey the global deadline and terminate as a process group."""
    log.parent.mkdir(parents=True, exist_ok=True)
    started = time.monotonic()
    with log.open("wb") as output:
        p = subprocess.Popen([str(a) for a in args], cwd=cwd, env=env, stdout=output,
                             stderr=subprocess.STDOUT, start_new_session=True)
        try:
            while p.poll() is None:
                if control.stopped() or time.monotonic() - started > timeout:
                    terminate_group(p)
                    raise HarnessError("Build interrupted or timed out; state remains resumable")
                time.sleep(0.2)
            return p.returncode
        finally:
            terminate_group(p)
