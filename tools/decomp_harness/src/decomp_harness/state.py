from __future__ import annotations

import json
from pathlib import Path
import sqlite3
import time

from .common import HarnessError

STATES = {'pending', 'analyzing', 'attempting', 'improving', 'matched', 'blocked', 'failed', 'skipped', 'needs_human'}
ACTIVE = {'analyzing', 'attempting', 'improving'}
TRANSITIONS = {
    'pending': {'analyzing', 'blocked', 'skipped', 'needs_human'},
    'analyzing': {'attempting', 'pending', 'blocked', 'failed', 'needs_human'},
    'attempting': {'improving', 'matched', 'pending', 'blocked', 'failed', 'needs_human'},
    'improving': {'attempting', 'matched', 'pending', 'blocked', 'failed', 'needs_human'},
    'matched': {'needs_human'}, 'blocked': {'pending'}, 'failed': {'pending'},
    'skipped': {'pending'}, 'needs_human': {'pending'},
}


class State:
    def __init__(self, path: Path):
        path.parent.mkdir(parents=True, exist_ok=True, mode=0o700)
        path.parent.chmod(0o700)
        self.db = sqlite3.connect(path, timeout=30)
        self.db.row_factory = sqlite3.Row
        self.db.execute('PRAGMA journal_mode=WAL')
        self.db.execute('PRAGMA foreign_keys=ON')
        self.db.execute('PRAGMA synchronous=FULL')
        version = self.db.execute('PRAGMA user_version').fetchone()[0]
        if version not in (0, 1, 2, 3, 4):
            raise HarnessError(f"Unsupported state schema {version}; do not overwrite it")
        self.db.executescript('''
            CREATE TABLE IF NOT EXISTS functions (
              id TEXT PRIMARY KEY, symbol TEXT NOT NULL, source TEXT NOT NULL, asm TEXT NOT NULL,
              segment TEXT, size INTEGER, difficulty TEXT, features TEXT, dependencies TEXT, asm_sha TEXT,
              status TEXT NOT NULL DEFAULT 'pending', attempts INTEGER NOT NULL DEFAULT 0,
              cycle_attempts INTEGER NOT NULL DEFAULT 0, stage INTEGER NOT NULL DEFAULT -1,
              stage_attempts INTEGER NOT NULL DEFAULT 0, model TEXT, best_score REAL,
              last_error TEXT, updated REAL NOT NULL, commit_sha TEXT, present INTEGER DEFAULT 1,
              best_source BLOB, base_sha TEXT, best_run TEXT);
            CREATE TABLE IF NOT EXISTS runs (
              id TEXT PRIMARY KEY, function_id TEXT REFERENCES functions(id), kind TEXT NOT NULL,
              model TEXT, effort TEXT, started REAL NOT NULL, ended REAL, outcome TEXT,
              exit_code INTEGER, score REAL, delta REAL, differences INTEGER, first_diff TEXT,
              last_diffs TEXT, usage TEXT, error TEXT, path TEXT, pid INTEGER, worker TEXT);
            CREATE INDEX IF NOT EXISTS runs_function ON runs(function_id, started);
            CREATE TABLE IF NOT EXISTS knowledge (
              id INTEGER PRIMARY KEY, tags TEXT NOT NULL, summary TEXT NOT NULL UNIQUE,
              origin TEXT, created REAL NOT NULL);
            CREATE TABLE IF NOT EXISTS metadata (key TEXT PRIMARY KEY, value TEXT NOT NULL);
            CREATE TABLE IF NOT EXISTS reference_asm (
              repo TEXT, path TEXT, mtime_ns INTEGER, symbol TEXT, calls TEXT, opcodes TEXT,
              PRIMARY KEY(repo,path));
            CREATE TABLE IF NOT EXISTS publication (
              function_id TEXT PRIMARY KEY REFERENCES functions(id), source TEXT NOT NULL,
              before BLOB NOT NULL, after BLOB NOT NULL, head TEXT NOT NULL, created REAL NOT NULL);
            CREATE TABLE IF NOT EXISTS publication_files (
              function_id TEXT REFERENCES publication(function_id) ON DELETE CASCADE,
              source TEXT NOT NULL, before BLOB NOT NULL, after BLOB NOT NULL,
              PRIMARY KEY(function_id,source));
            CREATE TABLE IF NOT EXISTS patterns (
              asm_key TEXT, replacement TEXT, origin TEXT NOT NULL, created REAL NOT NULL,
              PRIMARY KEY(asm_key,replacement));
            CREATE TABLE IF NOT EXISTS local_trials (
              function_id TEXT REFERENCES functions(id), candidate_sha TEXT, outcome TEXT,
              PRIMARY KEY(function_id,candidate_sha));
            CREATE TABLE IF NOT EXISTS solutions (
              function_id TEXT PRIMARY KEY REFERENCES functions(id), shape TEXT, symbol TEXT NOT NULL,
              asm TEXT NOT NULL, replacement TEXT NOT NULL);
            CREATE INDEX IF NOT EXISTS solutions_shape ON solutions(shape);
            CREATE TABLE IF NOT EXISTS prototypes (
              symbol TEXT NOT NULL, declaration TEXT NOT NULL, function_id TEXT NOT NULL,
              definition INTEGER NOT NULL DEFAULT 0, PRIMARY KEY(symbol,function_id));
        ''')
        columns = {r[1] for r in self.db.execute('PRAGMA table_info(functions)')}
        if 'initial_done' not in columns:
            self.db.execute('ALTER TABLE functions ADD COLUMN initial_done INTEGER NOT NULL DEFAULT 0')
        if 'shape' not in columns:
            self.db.execute('ALTER TABLE functions ADD COLUMN shape TEXT')
        if 'provider' not in {r[1] for r in self.db.execute('PRAGMA table_info(runs)')}:
            self.db.execute("ALTER TABLE runs ADD COLUMN provider TEXT NOT NULL DEFAULT 'codex'")
        self.db.execute('PRAGMA user_version=4')
        self.db.commit()

    def close(self):
        self.db.close()

    def sync(self, found):
        found = list(found)
        with self.db:
            self.db.execute('UPDATE functions SET present=0')
            for f in found:
                values = {**f, 'features': json.dumps(f['features']), 'dependencies': json.dumps(f['dependencies']), 'updated': time.time()}
                self.db.execute('''INSERT INTO functions
                    (id,symbol,source,asm,segment,size,difficulty,features,dependencies,asm_sha,shape,updated)
                    VALUES (:id,:symbol,:source,:asm,:segment,:size,:difficulty,:features,:dependencies,:asm_sha,:shape,:updated)
                    ON CONFLICT(id) DO UPDATE SET size=excluded.size,difficulty=excluded.difficulty,segment=excluded.segment,
                    features=excluded.features,dependencies=excluded.dependencies,asm_sha=excluded.asm_sha,
                    shape=excluded.shape,present=1''', {'shape': None, **values})
                if f['features'].get('kind') == 'data':
                    self.db.execute("UPDATE functions SET status='skipped',last_error='GLOBAL_ASM imports data, not a function' WHERE id=? AND status='pending'", (f['id'],))
            self.db.execute("UPDATE functions SET status='needs_human',last_error='GLOBAL_ASM reappeared after match' WHERE present=1 AND status='matched'")
            self.db.execute("UPDATE functions SET status='needs_human',last_error='Source removed outside harness; verify manually' WHERE present=0 AND status IN ('pending','analyzing','attempting','improving')")
        return len(found)

    def get(self, name):
        rows = self.db.execute('SELECT * FROM functions WHERE id=? OR symbol=?', (name, name)).fetchall()
        if len(rows) != 1:
            raise HarnessError(f"Function {name!r}: expected one result, found {len(rows)}; use source::symbol")
        return dict(rows[0])

    def update(self, identity, **values):
        values['updated'] = time.time()
        if not set(values) <= {r[1] for r in self.db.execute('PRAGMA table_info(functions)')}:
            raise HarnessError('Invalid state field')
        with self.db:
            self.db.execute('UPDATE functions SET ' + ','.join(k + '=?' for k in values) + ' WHERE id=?', (*values.values(), identity))

    def transition(self, identity, status, **values):
        old = self.get(identity)['status']
        if status not in STATES or status != old and status not in TRANSITIONS[old]:
            raise HarnessError(f"Invalid transition {old} -> {status}")
        self.update(identity, status=status, **values)

    def recover(self):
        """Workers never edit the user's checkout; publication has its own journal."""
        with self.db:
            self.db.execute("UPDATE functions SET status='pending',last_error='Interrupted; resumed from persisted best attempt' WHERE status IN ('analyzing','attempting','improving') AND id NOT IN (SELECT function_id FROM publication)")
            self.db.execute("UPDATE runs SET outcome='interrupted',ended=? WHERE ended IS NULL", (time.time(),))

    def start_run(self, identity, kind, model, effort, directory, worker=None):
        run_id = directory.name
        with self.db:
            self.db.execute('INSERT INTO runs(id,function_id,kind,model,effort,started,path,worker) VALUES (?,?,?,?,?,?,?,?)',
                            (run_id, identity, kind, model, effort, time.time(), str(directory), str(worker) if worker else None))
            if identity and kind == 'worker':
                self.db.execute('UPDATE functions SET attempts=attempts+1,model=?,updated=? WHERE id=?', (model, time.time(), identity))
        return run_id

    def finish_run(self, run_id, **values):
        allowed = {r[1] for r in self.db.execute('PRAGMA table_info(runs)')}
        if not set(values) <= allowed:
            raise HarnessError('Invalid run field')
        with self.db:
            self.db.execute('UPDATE runs SET '+','.join(k+'=?' for k in values)+' WHERE id=?', (*values.values(), run_id))

    def history(self, identity, limit=6):
        return [dict(r) for r in self.db.execute('SELECT id,model,effort,outcome,score,delta,error FROM runs WHERE function_id=? ORDER BY started DESC LIMIT ?', (identity, limit))][::-1]

    def set_meta(self, key, value):
        with self.db:
            self.db.execute('INSERT OR REPLACE INTO metadata VALUES (?,?)', (key, json.dumps(value)))

    def meta(self, key):
        row = self.db.execute('SELECT value FROM metadata WHERE key=?', (key,)).fetchone()
        return json.loads(row[0]) if row else None

    def note(self, tags, summary, origin):
        with self.db:
            self.db.execute('INSERT OR IGNORE INTO knowledge(tags,summary,origin,created) VALUES (?,?,?,?)',
                            (tags[:500], summary[:1500], origin, time.time()))
