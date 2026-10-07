# Banjo-Tooie Decompilation Harness

Lokaler, fortsetzbarer Matching-Loop mit Python 3.11+, SQLite und **ausschließlich
`codex exec` mit gespeicherter ChatGPT-Anmeldung**. Keine OpenAI-SDKs, keine eigenen
Inference-HTTP-Requests, kein API-Key-Fallback. Ein Worker bearbeitet eine Funktion.
Ein Match benötigt einen unabhängig geprüften, vollständigen ROM-Vergleich.

## Installation

Im Repository:

```sh
uv tool install --editable ./tools/decomp_harness
decomp-agent --help
```

Alternativ ohne Installation: `./decomp-agent ...`. Oder eine Python-Umgebung
aktivieren und `python -m pip install -e tools/decomp_harness` ausführen.
Der Harness selbst hat keine externen Python-Laufzeitabhängigkeiten.

Für den Original-Build benötigt das Projekt GNU Make mit grouped-target support,
MIPS GNU binutils/GCC, IDO 5.3 sowie seine Splat-/Python-/C++-Abhängigkeiten.
Auf diesem Mac nutzt die Standardkonfiguration ein Linux/amd64-Dockerimage
(`banjo-tooie-decomp:local`); Codex läuft weiterhin **auf dem Host**, mit dessen Login.
Der Buildcontainer erhält weder Codex-Credentials noch einen Docker-Socket.

Für einen neuen Checkout:

```sh
git submodule update --init --recursive --depth 1
git switch -c codex/ai-decomp
./decomp-agent init --rom '/Pfad/Banjo-Tooie (USA).n64' --build-image --setup
```

`init --rom` erkennt die drei üblichen N64-Byteordnungen, prüft den normalisierten
SHA-1 und schreibt `baserom.us.z64`, ohne das Original zu verändern. Ein vorhandenes
falsches `baserom.us.z64` wird nicht überschrieben. Es gibt keinen ROM-Downloader.

* ROM: `baserom.us.z64`, SHA-1 `af1a89e12b638b8d82cc4c085c8e01d4cba03fb3`.
* Splat-Input: `decompressed.us.z64`, SHA-1 `af479771ff5e91ce3732f3d84146614ab71d8d79`.

`--setup` führt das vorhandene `make setup` aus. Dieses darf die im Repository
vorgesehenen Compilerpakete herunterladen, aber keine ROM. Normale Validierungs-
Builds laufen im Container ohne Netzwerk. Auf einem bereits eingerichteten Linux
Host kann in `.decomp-agent/config.toml` `[build] backend = "native"` verwendet werden.
Nicht zwischen inkompatiblen Host-Binärformaten wechseln, ohne die Toolchain neu
einzurichten. Das Harness ändert die ursprünglichen Makefiles nicht.

## ChatGPT-Abo-Authentifizierung

1. Codex CLI installieren bzw. aktualisieren: `npm install -g @openai/codex`
   oder bei einer passenden bestehenden Installation `codex update`.
2. `codex` starten.
3. Mit dem **ChatGPT-Konto** anmelden.
4. **Keinen API-Key konfigurieren.**
5. `decomp-agent doctor` ausführen.

Getestet wird CLI **0.161.0**; mindestens diese Version und die tatsächlich geprüften
Exec-Flags sind erforderlich. Die Hilfe wird beim Preflight eingelesen.
Der Harness prüft `codex login status` und benötigt für eine eindeutig überprüfbare
Entscheidung Datei-Credentials mit `auth_mode = chatgpt` und vollständigen Tokens.
Bei einer ausschließlichen Keyring-Anmeldung bricht er sicher ab. In diesem Fall:

```sh
codex -c 'cli_auth_credentials_store="file"' login
codex login status
decomp-agent doctor
```

Die vorhandene `auth.json` wird nicht kopiert oder in Logs geschrieben. Die CLI
kann ihre normalen ChatGPT-Tokens selbst aktualisieren. Bei API-/gemischter oder
unbekannter Anmeldung wird vor jedem Worker abgebrochen. Nach einer falschen
Anmeldung zuerst bewusst `codex logout` ausführen und neu mit ChatGPT anmelden.

Jeder Child-Prozess erhält eine **erlaubte Liste** von Umgebungsvariablen. Dadurch
fehlen insbesondere `OPENAI_API_KEY`, `CODEX_API_KEY`, `CODEX_ACCESS_TOKEN`, Provider-
URL-Overrides, Remote-Session-Variablen und Shell-/Node-Injections. Zugelassen sind
Pfad, Benutzer-/Locale-/temporäre Verzeichnisse und CA-Bundle-Einstellungen sowie der
explizit aufgelöste `CODEX_HOME`. `--no-daemon`, `--ignore-user-config`, der OpenAI-
Provider, der offizielle ChatGPT-Backendpfad, Datei-Auth und
`forced_login_method="chatgpt"` werden gesetzt. Es gibt weder einen API-Backend-Codepfad
noch einen automatischen Modell-Fallback.

`doctor` führt kleine echte Exec-Probes der konfigurierten Modelle aus. Erfolgreiche
Probes werden standardmäßig 24 Stunden pro Modell, CLI-Version und Account gecacht.
Pro `doctor` und vor dem ersten neuen Worker jedes Laufs wird trotzdem mindestens
eine kleine Probe live ausgeführt; weitere Modelle können aus dem Cache kommen.
`doctor --refresh-models` erzwingt neue Probes; `doctor --offline` verbraucht kein
Kontingent und kennzeichnet den Bericht als unvollständig. `run` prüft Credentials
bei jedem Worker und probe-t ein noch nicht geprüftes Modell vor dessen Einsatz.
Ein Modell-/Auth-/Kontingentfehler stoppt den Lauf ohne alternative Abrechnung.

Referenzen: [Authentifizierung](https://learn.chatgpt.com/docs/auth),
[Konfiguration](https://learn.chatgpt.com/docs/config-file/config-reference),
[Codex-Modelle](https://learn.chatgpt.com/docs/models).

## Start

```sh
decomp-agent init
decomp-agent doctor
decomp-agent scan
decomp-agent status
decomp-agent next
decomp-agent run --dry-run --max-functions 10
decomp-agent run --max-functions 10
```

Alle Befehle werden aus diesem Repository ausgeführt; außerhalb davon
`decomp-agent --repo '/absoluter/Pfad/zum/Repository' COMMAND` verwenden.
Die Ausgabe ist JSON (Fortschrittsmeldungen bei `run` zusätzlich auf stdout).
Ein fehlgeschlagener Check liefert einen von null verschiedenen Exitcode.

`scan` erfasst `GLOBAL_ASM` in C-Quelldateien inklusive mehrzeiliger Direktiven.
Kommentare, Stringliterale und statisch deaktivierte `#if 0`-Arme werden ignoriert.
Unbekannte Präprozessorbedingungen werden konservativ erfasst; doppelte Definitionen
müssen geklärt werden. Datenimporte mit `dlabel` bleiben im Inventar als `skipped`,
werden aber nicht als Funktionen an Codex gegeben. Ungeklärtes oder fehlendes ASM
wird blockiert. Der Scanner meldet Funktionszahl und Datenimporte getrennt.

## Ablauf und exakter Match

1. Der Scheduler wählt offene Funktionen nach lokaler Schwierigkeit und Größe.
2. Ein frischer separater Build-Snapshot muss zuerst vollständig `make check` bestehen.
3. Ein kleiner Context Pack enthält Target-ASM, Nachbarcode, Symbol-/Prototyp-Hits,
   relevante Kenntnisse, bisherigen Score, letzte Patches und Compiler-Diffs.
4. Codex arbeitet in einer separaten temporären Quellkopie, mit eigenem Prozess,
   deaktiviertem Netzwerk für Werkzeuge und `workspace-write`-Sandbox ohne Freigaben.
   Persönliche Plugins, Skills, Erinnerungen und Subagenten werden nicht geladen.
5. Der Harness prüft alle Dateien dieser Kopie. Ausschließlich der Austausch der
   Target-Direktive durch eine C-Funktion ist erlaubt. Hilfsdeklarationen müssen
   innerhalb dieser Funktion liegen. ASM-/Präprozessor-Umgehungen werden abgewiesen.
6. Nur die geprüfte C-Datei gelangt in den vertrauenswürdigen Build-Snapshot. Dessen
   Original-Buildtools kompilieren das zugehörige `.c.o` neu.
7. `mips-linux-gnu-objdump -drz --disassemble=SYMBOL` liefert den Instruktionsvergleich
   gegen das Objekt des zuvor exakt passenden Baselines. Adressen werden normalisiert;
   Operanden, Register, Immediates und Relokationsnamen bleiben im Vergleich.
8. Ein deterministischer Sequenzvergleich liefert Score, Zahl verschiedener
   Instruktionen, erste/letzte Diffs und Verbesserung. **100 Punkte allein reichen
   niemals.** `make check` und ein unabhängiger SHA-1 über die vollständige gelinkte,
   dekomprimierte ROM sind die endgültige Freigabe, einschließlich rodata, Padding,
   Overlays und bereits gematchtem Code.
9. Erst dann übernimmt der Harness die C-Datei und erstellt atomar
   `decomp: match SYMBOL` mit Funktions-ID im Commit. Es gibt keinen Push-Codepfad.

`diff.py` bleibt unverändert nutzbar. Dessen Objektmodus setzt ein passendes
`expected/build/us/...c.o` voraus; das Harness verwaltet seine Referenzdisassemblierung
stattdessen pro Versuch und erfindet keine LLM-Scores. `tools/progress.py` zählt
existierende Nonmatching-ASM-Dateien; diese werden zum Schutz der Referenzen behalten.
Für den Harness-Fortschritt deshalb `status`/`report` verwenden. Ein späterer frischer
Splat-Split kann die Projekt-Progressanzeige aktualisieren.

Vor und nach jedem Worker werden Git-Zustand, HEAD, Dateifingerprints und ROM-Hashes
geprüft. Uncommittete Target-Dateien werden ausgelassen; fremde Änderungen werden
weder gestasht noch zurückgesetzt. Atomare Target-Commits bewahren anderweitig
gestagte Dateien. Kein `git reset --hard`, keine Worker-Zugriffe auf das echte `.git`.
Die Sandbox setzt eine funktionierende lokale Codex-Installation voraus; es gibt
keinen automatisch freigeschalteten Modus ohne Sandbox. Normale Builds sind getrennt
von den untrusted Worker-Kopien. Unter macOS validiert der Elternprozess im Container;
auf einem eingerichteten nativen Linux-System darf der Worker selbst das Objekt bauen.

## Pausieren/Fortsetzen

```sh
# In einem zweiten Terminal: laufende Funktion abschließen, dann stoppen
decomp-agent stop-after-current

# Oder direkt genau eine Funktion bearbeiten
decomp-agent run --stop-after-current

# Nach Ctrl+C, SIGTERM, Neustart, Netzwerk-/Wochenlimitunterbrechung
decomp-agent run
```

Ctrl+C/SIGTERM beendet die aktive Prozessgruppe und stoppt den Lauf. SQLite verwendet
WAL und FULL-Synchronisierung. Hängengebliebene aktive Zustände werden beim Neustart
auf `pending` zurückgesetzt; nur eindeutig identifizierte verwaiste Codex-Prozesse
werden beendet. Ein Publikationsjournal unterscheidet Abstürze vor und nach dem
Git-Commit. Konflikte mit zwischenzeitlichen Nutzeränderungen benötigen Review.
Ein vollständig gespeicherter, noch nicht ausgewerteter Kandidat wird zunächst ohne
neuen Modellaufruf erneut validiert. Bestes C, Erkenntnisse und Versuchshistorie
leben auf Platte. Teilweise Worker-Ausgaben bleiben im Run-Ordner.

```sh
decomp-agent inspect func_8001E7E0
decomp-agent verify func_8001E7E0
decomp-agent retry SYMBOL
```

`retry` setzt Eskalation/Zyklusbudget zurück und erhält den besten Versuch.
`verify` baut einen frischen Snapshot und prüft die vollständige ROM. Eine entfernte
Direktive allein wird nie nachträglich als erfolgreicher Match verbucht.
Die Zustände sind `pending`, `analyzing`, `attempting`, `improving`, `matched`, `blocked`,
`failed`, `skipped`, `needs_human`. Blockierte Fälle werden nicht endlos neu gestartet.

## Modellrouting

Die erzeugte `.decomp-agent/config.toml` ist die lokale Konfiguration. Modellnamen,
Reasoning und Anzahl Versuche sind editierbar; nur explizit konfigurierte Namen
werden verwendet. Default:

| Stufe | Modell | Reasoning | Versuche |
|---|---|---|---:|
| 1 | `gpt-6.1-sol` | medium | 2 |
| 2 | `gpt-6.1-sol` | high | 2 |
| 3 | `gpt-6-astra` | high | 2 |
| 4 | `gpt-6-astra` | xhigh | 2 |

Easy startet bei 1, medium bei 2, hard bei 3, extreme bei 4. Die lokale Schätzung
berücksichtigt Instruktionen, Branches, Calls, FPU, indirekte Sprünge und Switches;
Stack, Speicherzugriffe und Globals werden zusätzlich erfasst. Nach einer Stufe
oder einem konfigurierten Stagnationsfenster wird eskaliert. Am Ende wird blockiert.
`extra_attempts = 0` verhindert standardmäßig Verlängerungen. Ein explizit höherer
Wert erlaubt zusätzliche Versuche nur bei ausreichendem Scoregewinn.
`--model NAME` überschreibt die Modellwahl bewusst für diesen Lauf, nicht das Budget.

## Banjo-Kazooie-Referenz konfigurieren

```toml
# Auf oberster Ebene in .decomp-agent/config.toml
banjo_kazooie_repo = "/absoluter/Pfad/banjo-kazooie"
```

Die Suche verwendet lokal `rg` über `src`, `include` und vorhandenes `asm`, mit
Funktionsnamen, Calls, Symbol-/Typnamen und charakteristischen Konstanten. Zusätzlich
werden Opcode- und Call-Muster vorhandener ASM-Dateien lokal verglichen; ein per
Datei-Mtime aktualisierter SQLite-Index vermeidet erneutes Parsen. Ergebnisse
werden begrenzt in den Pack übernommen. Das BK-Repository wird weder verändert noch
in ein beschreibbares Worker-Verzeichnis eingebunden. Ohne BK funktioniert der Loop
weiterhin. Schwierige Änderungen an gemeinsamen Structs/Headers eskalieren zur
menschlichen Prüfung; der Worker darf sie nicht stillschweigend global ändern.

## Logs/Debugging

`.decomp-agent/` ist ignoriert und enthält:

* `state.db`: Funktionen, Versuche, Kandidaten, Scores, Modellstufen, Knowledge Base,
  Probe-Cache und Publikationsjournal. SQLite ist die primäre Datenquelle.
* `runs/ID/`: Prompt, Metadaten, JSONL-Events, redigiertes stderr, letzte Antwort,
  Exitcode/Usage, Git-Fingerprints, C vorher/nachher, Source-Diff, Compiler-/Regressions-
  Output sowie erwartetes/tatsächliches ASM und `comparison.json`.
* `context/`: begrenzte Context Packs (Standardbudget 24.000 Zeichen).
* `logs/`: Setup, Baseline, Doctor, Verify und Wiederherstellungs-Builds.
* `doctor.json`, `report.json`, `knowledge.md`: lesbare abgeleitete Berichte.

Ein technischer CLI-Fehler ist von Agent-, Compiler-, Guard-, Modell-, Auth- und
Kontingentfehlern getrennt. Technische Wiederholungen sind begrenzt und zählen zum
CLI-Run-Budget; Auth-/Modell-/Kontingentfehler haben keinen Fallback. Der beste gültige
Versuch wird gespeichert; erfolglose C-Dateien verbleiben nicht im Arbeitscheckout.

```sh
decomp-agent knowledge --tags 'IDO float' --add 'Eine lokal verifizierte kurze Erkenntnis.'
decomp-agent report
```

Modellnotizen werden nur zusammen mit einem bestätigten Match in die Knowledge Base
übernommen. Relevante kurze Notizen und echte erfolgreiche Source-Patterns werden
für spätere Funktionen wiederverwendet.

## Usage begrenzen

```sh
decomp-agent run --difficulty easy --max-functions 10 --max-attempts 20 --max-runtime 3600
decomp-agent run --max-functions 100 --max-attempts 200 --max-runtime 14400
```

`--max-attempts` begrenzt sämtliche Worker-CLI-Starts dieses Aufrufs, inklusive
technischer Retries. Kleine Modell-Preflight-Probes werden separat protokolliert und
gecacht. `max_attempts_per_function` begrenzt den persistierten Funktionszyklus über
Neustarts hinweg. `--max-runtime` ist in Sekunden; Prozessbeendigung und sicheres
Aufräumen können kurz darüber hinaus dauern. Es werden keine Funktionen parallel
gestartet (`concurrency = 1`; andere Werte sind ausdrücklich abgewiesen).

Die CLI-JSONL-Usage wird unverändert erfasst, soweit sie vorhanden ist; sie ist kein
verlässlicher Zähler des verbleibenden ChatGPT-Wochenkontingents. Zusätzlich werden
Modell, Run-Zahl, Dauer und Erfolgsrate geführt. Für die offizielle verbleibende Usage
Codex interaktiv starten und `/status` verwenden. Kein Scraping von UI-Ausgaben.

## Tests

```sh
PYTHONPATH=tools/decomp_harness/src python3 -m unittest discover -s tools/decomp_harness/tests -v
decomp-agent run --dry-run
```

Die Tests laufen ohne ROM, Docker, Netzwerk oder echte Codex-Nutzung. Sie decken Parser,
SQLite, Zustände/Resume, Scoring/Relokationen, Scheduler/Eskalation, Credential-Guard,
JSONL/Usage, echte kontrollierte Fake-CLI-Prozesse, Timeout/Abbruch, Änderungsgrenzen,
Publikations-Recovery und Erhalt fremder gestagter Änderungen ab.

Der praktische Test dieses Branches ist in [INTEGRATION.md](INTEGRATION.md) festgehalten.
