# Banjo-Tooie Decompilation Harness

Lokaler, fortsetzbarer Matching-Loop mit Python 3.11+, SQLite und standardmäßig
**`codex exec` mit gespeicherter ChatGPT-Anmeldung**. Ein optionaler Claude-Code-Runner
erfordert eine separat bestätigte Pro-/Max-Anmeldung. Keine Inference-SDKs, keine
eigenen Inference-HTTP-Requests, kein API-Key-Fallback. Ein Worker bearbeitet eine Funktion oder einen kleinen Batch
derselben Datei.
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
decomp-agent progress
decomp-agent next
decomp-agent patterns
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

1. Der Scheduler wählt offene Funktionen: zuerst Mitglieder bereits gelöster Formgruppen,
   dann nach Schwierigkeit, Gruppengröße, schon dekompilierten Callees und Größe.
2. Ein frischer separater Build-Snapshot muss zuerst vollständig `make check` bestehen.
3. Zuerst werden lokal erkannte Getter, Setter, Konstanten und leere Funktionen,
   bereits bestätigte C-Lösungen für identische Instruktionsmuster und übertragene
   Lösungen formgleicher Funktionen versucht, danach m2c und bei knappen Fehlschlägen der
   Permuter. Dafür startet kein Modell. Fehlgeschlagene lokale Kandidaten werden
   persistent markiert.
4. Ein kleiner Context Pack enthält Target-ASM, die genaue zu ersetzende Direktive,
   tatsächliche primitive Typdefinitionen, knappen Nachbarcode, Symbol-/Prototyp-Hits,
   in gematchtem Code bestätigte Deklarationen, einen m2c-Entwurf, relevante Kenntnisse,
   bisherigen Score und letzte Compiler-Diffs. Der Worker soll diese Angaben direkt
   verwenden und nur fehlende Fakten gezielt nachlesen.
5. Codex arbeitet in einer separaten temporären Quellkopie, mit eigenem Prozess,
   deaktiviertem Netzwerk für Werkzeuge und `workspace-write`-Sandbox ohne Freigaben.
   Persönliche Plugins, Skills, Erinnerungen und Subagenten werden nicht geladen.
   Über `./decomp-compile` lässt der Worker seinen Stand vom Elternprozess kompilieren
   und bekommt den Instruktions-Diff zurück (siehe Beschleunigung).
6. Der Harness prüft alle Dateien dieser Kopie. Einzelziele dürfen zusätzlich falsche
   Deklarationen oder bestehende C-Definitionen in ihrer Quelldatei und bis zu acht
   konkret benannten Abhängigkeitsdateien reparieren. Andere ASM-Imports,
   Präprozessoranweisungen und bestehende Funktionsnamen bleiben erhalten. Batches
   bearbeiten weiterhin nur ihre markierten Funktionen.
7. Nur geprüfte Änderungen gelangen in den vertrauenswürdigen Build-Snapshot.
   Geänderte C-Dateien werden neu kompiliert; bei Headeränderungen werden vor dem
   ROM-Check sämtliche Objekte neu gebaut, da die Make-Abhängigkeiten unvollständig sind.
8. `mips-linux-gnu-objdump -m mips:4300 -drzt --disassemble=SYMBOL` liefert den Instruktionsvergleich
   gegen das Objekt des zuvor exakt passenden Baselines. Adressen werden normalisiert,
   benannte lokale Rodata-Labels auf Section+Offset gebracht und Alignment-NOPs hinter
   `endlabel` ignoriert; Operanden, Register, Immediates und externe Relokationsnamen
   bleiben im Vergleich.
9. Ein deterministischer Sequenzvergleich liefert Score, Zahl verschiedener
   Instruktionen, erste/letzte Diffs und Verbesserung. **100 Punkte allein reichen
   niemals.** `make check` und ein unabhängiger SHA-1 über die vollständige gelinkte,
   dekomprimierte ROM sind die endgültige Freigabe, einschließlich rodata, Padding,
   Overlays und bereits gematchtem Code. Sie laufen, sobald das Objekt normalisiert
   identisch ist, Score ≥ 99 erreicht oder ausschließlich HI16/LO16-Adressrelokationen
   abweichen. Register, Opcodes und Reihenfolge müssen für diesen letzten Fall gleich sein.
   Ein falscher Alias wird spätestens durch den verbindlichen ROM-Vergleich abgewiesen.
10. Erst dann übernimmt der Harness alle zusammengehörigen Dateien und erstellt
   mit einem wiederherstellbaren Veröffentlichungsjournal
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
von den untrusted Worker-Kopien. Worker bekommen weder Compiler noch Docker: auch ihre
Zwischenstände kompiliert ausschließlich der Elternprozess (`./decomp-compile`).

## Beschleunigung: weniger Tokens, weniger Abbrüche, schnellere Läufe

Die folgenden Stufen sind standardmäßig aktiv. Jede liefert nur **Kandidaten**; ein Match
braucht weiterhin Source-Guard, Original-Compiler, `make check` und den vollständigen ROM-Hash.

| Stufe | Kosten | Wirkung |
|---|---|---|
| Gruppen-Transfer | keine Tokens | Funktionen mit gleicher Instruktionsform (Opcodes, Register, Stack/Offsets gleich; Symbole/Immediates verschieden) übernehmen eine bestätigte Lösung mit umbenannten Symbolen und Konstanten. |
| m2c | keine Tokens | `tools/m2c` übersetzt die Ziel-ASM mit dem Projekt-Kontext (`tools/m2ctx.py`). Ein sauberer Entwurf wird kompiliert; bei `void *`-Arithmetik zusätzlich als `u8 *`-Variante. Ein knapper Fehlschlag wird Startkandidat des Modells, sonst landet der Entwurf im Context Pack. |
| Permuter | keine Tokens, `permuter_seconds` | Ab `permuter_min_score` sucht `tools/decomp-permuter` im Buildcontainer nach äquivalenten Umformungen, bevor weiter eskaliert wird. |
| Compile-Schleife | Tokens nur für eine Sitzung | Codex-Worker rufen `./decomp-compile` auf. Der vertrauenswürdige Elternprozess prüft die Datei mit denselben Guards, kompiliert das Objekt unter der Build-Sperre, stellt das Baseline-Objekt wieder her und antwortet mit einem kompakten Instruktions-Diff. Bis zu `worker_compiles` Runden pro Sitzung statt einem Blindversuch pro CLI-Start. |
| Batches | ein CLI-Overhead für bis zu `batch_size` Funktionen | Frische kleine Funktionen (≤ `batch_max_bytes`) derselben Datei teilen sich eine Sitzung. Die Ziele sind mit `/* decomp-target-begin/end NAME */` markiert; jede Funktion wird einzeln validiert und committed. |

Weitere Änderungen:

* **Score-Normalisierung:** Die Referenz (asm-processor) referenziert Rodata per Name
  (`jtbl_…`, `R_…`), IDO per `.rodata`+Offset. Über die objdump-Symboltabelle werden beide
  auf Section+Offset gebracht; Alignment-NOPs hinter `endlabel` zählen nicht mehr. Ein
  falscher Rodata-Offset bleibt eine Differenz.
* **Günstige Validierung:** Der volle `make check` läuft nur noch, wenn das Objekt normalisiert
  identisch ist, Score ≥ 99 erreicht oder nur Adressrelokationen abweichen. Nach einem Fehlschlag werden die Quellen zurückgeschrieben;
  das zuvor gesicherte Baseline-Objekt wird **im Buildcontainer** zurückkopiert und die
  gelinkten Ausgaben dort gelöscht, statt neu zu bauen und erneut zu prüfen. Der nächste
  `make check` muss dadurch neu linken. Unter `build/` schreibt nie der Host: Das führte über
  das Docker-Desktop-Dateisharing zu `ld: cannot open output file` bei allen folgenden Checks.
* **Scheduler:** zuerst Mitglieder bereits gelöster Gruppen (lokaler Transfer), dann nach
  Schwierigkeit; innerhalb davon Vertreter großer ungelöster Gruppen, dann Funktionen, deren
  Callees schon dekompiliert sind, dann kleinere. Mitglieder derselben Gruppe laufen nie parallel.
* **Prototyp-Register:** Jeder Match speichert seine Signatur und seine lokalen
  Prototypen/Externs (ohne funktionslokale Typen). Der Context Pack nennt für Calls und Globals
  die verbindlichste bekannte Deklaration.
* **Fortschritt in Bytes:** `status` meldet `matched_code_bytes`, `code_bytes` und
  `matched_code_percent` sowie `solved_shape_groups`. `progress` rechnet das auf das ganze
  Projekt hoch: Fork-Stand (`tools/progress.py` bei `25033be6`) plus gematchte Bytes, als
  `project_percent` und `gained_percent_points`. `segments` liefert dieselbe Rechnung je
  README-Badge (Boot/Core1/Core2/Overlays), `difficulties` die offenen und gematchten
  Funktionen je Schwierigkeit.

```toml
# .decomp-agent/config.toml, oberste Ebene (Defaults)
worker_timeout = 1200      # Sitzungen mit Compile-Schleife dauern länger
worker_compiles = 12       # 0 = alter Einzelversuch pro Sitzung
m2c = true
permuter_seconds = 180     # 0 = Permuter aus
permuter_min_score = 95.0
batch_size = 6             # 1 = keine Batches
batch_max_bytes = 64
```

`--local-only` nutzt jetzt auch m2c und den Permuter (ohne Anmeldung und ohne Inferenz). Ein
lokaler Durchlauf über alle offenen Funktionen kostet damit nur Rechenzeit:

```sh
decomp-agent run --local-only --difficulty easy --max-runtime 28800
```

Für einen neuen Checkout: `git submodule update --init tools/m2c tools/decomp-permuter`.
Beide Tools bringen ihren eigenen C-Parser mit; das Docker-Image bleibt unverändert. Fehlen sie,
werden die Stufen übersprungen. Der Claude-Backend-Worker hat nur Read/Edit und deshalb keine
Compile-Schleife. Die Datenbank wird automatisch auf Schema 3 migriert (nur Ergänzungen);
ältere Harness-Versionen öffnen sie danach nicht mehr.

## Pausieren/Fortsetzen

```sh
# In einem zweiten Terminal: aktive Funktionen abschließen, dann stoppen
decomp-agent stop-after-current

# Oder direkt genau eine Funktion bearbeiten
decomp-agent run --stop-after-current

# Nach Ctrl+C, SIGTERM, Neustart, Netzwerk-/Wochenlimitunterbrechung
decomp-agent run
```

Ctrl+C/SIGTERM beendet die aktiven Prozessgruppen und stoppt den Lauf. SQLite verwendet
WAL und FULL-Synchronisierung. Hängengebliebene aktive Zustände werden beim Neustart
auf `pending` zurückgesetzt; nur eindeutig identifizierte verwaiste CLI-Prozesse
werden beendet. Ein Publikationsjournal unterscheidet Abstürze vor und nach dem
Git-Commit. Konflikte mit zwischenzeitlichen Nutzeränderungen benötigen Review.
Ein vollständig gespeicherter, noch nicht ausgewerteter Kandidat wird zunächst ohne
neuen Modellaufruf erneut validiert. Auch ein beim Abbruch geschriebenes C wird nach
Prüfung des gespeicherten Dateimanifests und der Basis-/Kandidaten-Hashes wiederverwendet.
Bestes C, Erkenntnisse und Versuchshistorie
leben auf Platte. Teilweise Worker-Ausgaben bleiben im Run-Ordner.

```sh
decomp-agent inspect func_8001E7E0
decomp-agent verify func_8001E7E0
decomp-agent retry SYMBOL
decomp-agent refresh-repairs
```

`retry` setzt Eskalation/Zyklusbudget und lokale Fehlversuchsmarken zurück und erhält den besten Versuch.
`refresh-repairs` aktiviert Easy-Blockaden einmalig und nur mit passender Evidenz:
inzwischen saubere Zieldateien, Relokationsfälle, jetzt erlaubte Schnittstellenreparaturen
und alte Versuche ohne Compiler-Rückmeldung. Unbegründet ausgeschöpfte Suchen bleiben
blockiert. Anschließend prüft `run --local-only --difficulty easy` gespeichertes C ohne
Modellaufruf erneut. Eine fehlgeschlagene Wiederprüfung wird für denselben Quell- und
Abhängigkeitsstand nicht endlos wiederholt.

Compilerproben speichern `compile-N.c`, `compile-N.json` und zugehörige
`support.json`-Dateien im Run-Verzeichnis. Identische Anfragen gegen denselben Buildstand
verwenden das gespeicherte Ergebnis; die endgültige ROM-Prüfung wird nie gecacht.
Der Worker behält den besten tatsächlich kompilierten Stand. Folgesitzungen erhalten
unterschiedliche Compilerergebnisse und den gemeldeten Blocker. Ziele mit 64-Bit-MIPS-
Instruktionen werden vor Inferenz als Toolchain-/ABI-Voraussetzung ausgewiesen, solange
das C-Buildprofil `-mips2` verwendet.
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
| Easy-Einstieg | `gpt-6-luna` | low | 1 |
| 1 | `gpt-6.1-sol` | medium | 2 |
| 2 | `gpt-6.1-sol` | high | 2 |
| 3 | `gpt-6-astra` | high | 2 |
| 4 | `gpt-6-astra` | xhigh | 2 |

Easy startet mit Luna, danach bei 1; medium bei 2, hard bei 3, extreme bei 4.
Luna ist ein begrenzter Versuch für einfache Fälle, keine Bewertung schwieriger
Decompilation anhand eines einzelnen Tests. Lokale Muster haben Vorrang vor Modellen.
Das gesamte persistente Zyklusbudget bleibt standardmäßig **8 Modellversuche**;
mit einem Luna-Versuch bleibt deshalb maximal ein Astra/xhigh-Versuch übrig.
Die lokale Schätzung
berücksichtigt Instruktionen, Branches, Calls, FPU, indirekte Sprünge und Switches;
Stack, Speicherzugriffe und Globals werden zusätzlich erfasst. Nach einer Stufe
oder einem konfigurierten Stagnationsfenster wird eskaliert. Am Ende wird blockiert.
`extra_attempts = 0` verhindert standardmäßig Verlängerungen. Ein explizit höherer
Wert erlaubt zusätzliche Versuche nur bei ausreichendem Scoregewinn.
`--model NAME` überschreibt die Modellwahl bewusst für diesen Lauf, nicht das Budget.
Ein nicht verfügbares Modell führt zum Abbruch. Die Sol-Eskalation erfolgt nach einem
gültigen, aber nicht passenden C-Versuch, niemals als versteckter Auth-/Provider-Fallback.

```toml
# .decomp-agent/config.toml; fehlende neue Schlüssel erhalten ihre Defaults.
[easy_model]
enabled = true
provider = "codex"
model = "gpt-6-luna"
effort = "low"
attempts = 1
```

`enabled = false` stellt den bisherigen Sol-Einstieg wieder her. Die Datenbank wird
automatisch migriert; vorhandene Matches, Versuche und Commits bleiben erhalten.

## Lokale Muster und Token-Ersparnis

```sh
decomp-agent patterns
decomp-agent run --local-only --dry-run > .decomp-agent/local-plan.json
decomp-agent run --local-only
```

Ohne `--max-functions` und `--max-runtime` läuft die lokale Suche über das gesamte
offene Projekt. Zuerst werden alle `pending`-Funktionen lokal geprüft; nur Funktionen
mit einem unversuchten C-Kandidaten, einem fortsetzbaren Versuch oder (bei vorhandenem
`tools/m2c`) ohne m2c-Durchlauf für die aktuelle ASM/Datei kommen in die
Build-Warteschlange. m2c wird pro Funktion und Dateistand nur einmal versucht. Quellen werden dabei pro Datei einmal gelesen. Unbekannte Muster
verbrauchen weder einen Build noch einen Platz im `--max-functions`-Budget. Gibt es
keinen Kandidaten, endet der Lauf bereits vor dem Baseline-Build. Der Dry-Run liefert
dieselbe vollständige Auswahl ohne Compiler oder Modell; `patterns` zeigt Anzahl und
eine kurze Vorschau. `blocked`/`needs_human` bleiben bis `retry SYMBOL` ausgeschlossen.

`patterns` zeigt Kandidaten, **keine bereits bestätigten Matches**. `--local-only`
benötigt keine CLI-Anmeldung, keine Modellprobe und keine Inferenz. Die gleichen
Source-Guards, Original-Compiler, vollständigen ROM-Prüfungen und atomaren Commits
gelten auch hier. Gibt es keinen passenden Kandidaten, bleibt die Funktion `pending`.
`--no-local` überspringt diese Stufe ausdrücklich, etwa für einen Modellvergleich.

Bestätigte C-Lösungen werden in SQLite anhand ihrer Instruktionen und exakten Operanden
wiederverwendet; nur der Target-Name wird normalisiert. Es wird keine ähnliche, aber
ungeprüfte Lösung übernommen. Bei jedem neuen Ziel erfolgt erneut der vollständige
Compiler-/ROM-Vergleich. Änderungen an ASM oder Quelldatei ermöglichen einen erneuten
lokalen Versuch. `report` trennt Modell-Runs, lokale Matches und gelernte Muster.

Die ASM-Regeln erkennen unter anderem Konstanten, direkte und indirekte Getter/Setter,
Float-Setter, symbolische Adress-Rückgaben, globale Variablen, skalierte Tabellenzugriffe
und einfache Ganzzahloperationen. Symbolische `%hi`/`%lo`-Paare und beteiligte Register
müssen zusammenpassen. NOPs nach `endlabel` sind keine Funktionsinstruktionen für die
Mustererkennung; ihre korrekte Platzierung prüft weiterhin der vollständige ROM-Build.
Ein komplexer Algorithmus lässt sich damit noch nicht automatisch rekonstruieren.

Fehlversuche sind in SQLite gespeichert und werden bei unveränderter Quelle/ASM nicht
erneut kompiliert. Neue Regeln und erfolgreiche Muster werden beim nächsten Aufruf
berücksichtigt. Für eine begrenzte Sitzung beispielsweise:

```sh
decomp-agent run --local-only --max-functions 100 --max-runtime 3600
```

## Baseline-Build wiederverwenden

Der erste Lauf baut weiterhin eine unabhängige Kopie vollständig. Nach einem normal
beendeten oder mit `stop-after-current` geleerten Lauf bleibt ein Build-Cache unter
`.decomp-agent/build-cache/` erhalten. Folgeläufe prüfen Inhalts-Hashes aller kopierten
Eingaben und Build-Artefakte sowie die Docker-Image-ID. Der Cache wird in eine neue
Arbeitskopie kopiert und dort erneut geprüft. Anschließend laufen das originale
`make check` und die vollständige ROM-Hash-Prüfung auch bei einem Cache-Treffer.

Geänderte Quellen, Header, ASM, Tools, ROMs, Compiler-Image oder Build-Konfiguration
erzwingen einen frischen Build. Ein beschädigter Cache wird verworfen. Unterbrechungen
mit SIGINT/Timeout und Fehler schreiben keinen neuen Cache; der SQLite-Resume bleibt
erhalten. `stop-after-current` ist deshalb die günstigste Art, längere Läufe zu pausieren.

`build_cache = false` in der lokalen Konfiguration oder `run --no-build-cache` schaltet
die Wiederverwendung ab. Der Cache gilt nur für das Docker-Backend, dessen Toolchain
durch die Image-ID eindeutig feststeht; native Builds bleiben frisch. Pro Kandidat
bleiben Compiler-, vollständiger ROM-Vergleich und atomarer Commit nötig. Zwei lokale
Worker beschleunigen diese serialisierten Prüfungen daher kaum.

## Zwei parallele Worker

```sh
decomp-agent run --concurrency 2 --max-functions 100 --max-attempts 200 --max-runtime 14400
```

Frische Installationen bleiben bei `concurrency = 1`. Dauerhaft aktivieren lässt sich
der Parallelbetrieb mit z. B. `concurrency = 4` auf oberster Ebene der lokalen Konfiguration.
Der Scheduler sperrt dieselbe Quelldatei und gemeinsame Funktionsabhängigkeiten.
Jeder parallele Worker erhält einen eigenen Git-Worktree mit **privater Git-Datenbank**;
es gibt keine Verbindung zum `.git` des Nutzer-Repositories. Logs sind pro Run getrennt.
Die Modellarbeit kann sich überlappen. Jeder Worker kompiliert Probe- und Kandidaten-Objekte
in einer eigenen **Build-Lane** (APFS-Klon des gebauten Workspace, wird nie gelinkt), also
parallel. Eine zusätzliche unveränderte Baseline-Kopie liefert die Referenzobjekte.
Die ROM-Prüfung und Übernahme laufen nacheinander im vertrauenswürdigen Workspace;
ein zweiter Match wird damit gegen die bereits integrierte erste Änderung geprüft.
Die kurze Repository-Sperre schützt Zustandsprüfungen und Commits, wird während des
ROM-Builds aber freigegeben. Unabhängige Kandidaten können weiter vorbereitet,
kompiliert und als Nichttreffer abgeschlossen werden. Vor jeder Übernahme werden
Repository-Zustand, `make check` und vollständiger ROM-Hash weiterhin geprüft.

Jeder Build-Workspace besitzt für die Laufdauer einen eigenen Container ohne Netzwerk,
Credentials oder Docker-Socket. Compiler und Objdump laufen darin über `docker exec`.
Bei regulärem Ende und Fehlern werden diese Container entfernt; bei einem Build-Timeout
wird auch der Container beendet, damit kein Compiler weiter in die Build-Lane schreibt.
Der Baseline-Build läuft einmal
pro Harness-Aufruf. Seine Logdatei wird beim Start ausgegeben.

Funktions-, Versuchs- und Laufzeitbudgets gelten gemeinsam für alle Worker.
Ein externer `stop-after-current` lässt die bereits aktiven Funktionen fertig werden.
`run --stop-after-current` startet dagegen höchstens eine Funktion. Es darf nicht
parallel ein zweiter Harness-Prozess auf dieselbe State-Datenbank gestartet werden.
Mehr Worker sparen Wartezeit, nicht automatisch Kontingent. Ein langer Lauf amortisiert
den frischen Baseline-Build und das Anlegen der Build-Lanes.

## Optional: Haiku über Claude Code

Dieser Backend bleibt standardmäßig **deaktiviert**. Ein ChatGPT-Abo beinhaltet keine
Claude-Nutzung. Erforderlich sind die separat installierte Claude Code CLI (getestete
Flag-Oberfläche **2.1.292**) und eine aktive Claude-Pro-/Max-Anmeldung. Interaktiv
`claude` starten und über `/login` das Claude-Konto wählen, nicht die API-Console.

```toml
# Auf oberster Ebene, vor [build] oder anderen Tabellen:
claude_enabled = true

# Ersetzt nur den einfachen Einstieg; Sol/Astra bleiben Codex-Stufen.
[easy_model]
enabled = true
provider = "claude"
model = "haiku"
effort = "low"
attempts = 1
```

`haiku` ist der von Claude Code aufgelöste Modellalias. Für eine feste Version den
konkreten, für das eigene Konto freigeschalteten Modellnamen eintragen. Der Harness
behauptet nicht, dass jeder Alias dauerhaft dieselbe Version bezeichnet. Vor Nutzung:

```sh
decomp-agent doctor --provider claude --model haiku
```

Der Runner verlangt maschinenlesbar `loggedIn=true`, `authMethod=claude.ai`,
`apiProvider=firstParty` und `subscriptionType=pro|max`. Sonst **FAIL CLOSED**.
Eine positive Anmeldung garantiert noch keine Modellverfügbarkeit; dies prüft die
kleine echte Probe. Hier wurde keine angemeldete Haiku-Inferenz durchgeführt.

Die erlaubte Prozessumgebung entfernt insbesondere `ANTHROPIC_API_KEY`, Auth-Token-
Overrides, Provider-Endpunkte sowie Bedrock-/Vertex-/Foundry-Overrides. `--safe-mode`,
leere `--setting-sources`, `forceLoginMethod=claudeai` und `--strict-mcp-config`
unterbinden Konfigurations-/Hook-/MCP-Overrides. `--bare` wird ausdrücklich **nicht**
benutzt: Dieser Modus deaktiviert laut installierter Hilfe die OAuth-Anmeldung.
Worker nutzen `--restricted` mit ausschließlich `Read,Edit`; die Validierung führt
der vertrauenswürdige Elternprozess aus. Weder Shell- noch Netz- oder Subagent-Tools
sind freigeschaltet. Claude-Code-Runs haben dieselben Budgets, Guards und Logs.
Es gibt keinen Wechsel auf API-Abrechnung und keinen automatischen Provider-Ersatz.

Referenzen: [Claude-Code-Authentifizierung](https://code.claude.com/docs/en/authentication),
[CLI-Referenz](https://code.claude.com/docs/en/cli-reference).

## Banjo-Kazooie-Referenz konfigurieren

```toml
# Auf oberster Ebene in .decomp-agent/config.toml
banjo_kazooie_repo = "/absoluter/Pfad/banjo-kazooie"
```

Mit `tools/decomp_harness/bk_map.json` bekommt der Worker statt einer Textsuche das
bekannte Gegenstück: den C-Quelltext der zugeordneten BK-Funktion und die BK-Signaturen
zugeordneter Callees, live aus dem BK-Repository gelesen. Die Tabelle (BT-Funktion →
BK-Datei, BK-Funktion, Opcode-Ähnlichkeit, Beleg) entsteht aus dem Maschinencode beider
Spiele, weil ein fertiges BK-Decomp kein `asm/` mehr hat:

```sh
PYTHONPATH=tools/decomp_harness/src python3 -m decomp_harness.bkmap /pfad/zum/bk.z64 /pfad/zu/banjo-kazooie
```

Belege: `similar` (nahezu gleiche Opcode-Folge), `position` (gleiche Stelle in der
zugeordneten Datei), `call` (Callee eines zugeordneten Paars). Neu erzeugen, wenn sich
Symbolnamen oder Dateigrenzen ändern; nötig sind PyYAML, das eigene BK-ROM (US 1.0) und
ein gebauter Workspace (Linker-Map).

Ohne Tabelle sucht der Harness blind: lokal `rg` über `src`, `include` und vorhandenes `asm`, mit
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
  bestätigte C-Muster, lokale Fehlversuche, Probe-Cache und Publikationsjournal.
  SQLite ist die primäre Datenquelle (Schema 2).
* `runs/ID/`: Prompt, Metadaten, JSONL-Events, redigiertes stderr, letzte Antwort,
  Exitcode/Usage, Git-Fingerprints, C vorher/nachher, Source-Diff, Compiler-/Regressions-
  Output sowie erwartetes/tatsächliches ASM und `comparison.json`.
* `context/`: begrenzte Context Packs (Standardbudget 24.000 Zeichen).
* `logs/`: Setup, Baseline, Doctor, Verify und Wiederherstellungs-Builds.
* `build-cache/`: ein vollständig geprüfter Docker-Build als wiederverwendbare Kopie.
* `build-tmp/`: Workspace und Build-Lanes des laufenden Prozesses. Bewusst nicht im
  System-Temp: macOS löscht dort täglich um 03:35 Dateien mit mehr als drei Tage alter
  Zugriffszeit, auch aus einem laufenden Build. Reste abgebrochener Läufe räumt der nächste
  Aufruf unter dem Lock weg.
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
decomp-agent run --concurrency 2 --max-functions 100 --max-attempts 200 --max-runtime 14400
```

`--max-attempts` begrenzt sämtliche Worker-CLI-Starts dieses Aufrufs, inklusive
technischer Retries. Kleine Modell-Preflight-Probes werden separat protokolliert und
gecacht. `max_attempts_per_function` begrenzt den persistierten Funktionszyklus über
Neustarts hinweg. `--max-runtime` ist in Sekunden; Prozessbeendigung und sicheres
Aufräumen können kurz darüber hinaus dauern. Lokale Kandidaten zählen zum Funktions-,
aber nicht zum Modellversuchsbudget. Probe-Runs sind in den Logs getrennt erkennbar.

Die CLI-JSONL-Usage wird erfasst, soweit sie vorhanden ist; Claude-Eingabetokens
werden einschließlich Cache-Lese-/Schreibtokens mit den Codex-Metriken vergleichbar
zusammengezählt. Provider bleiben im Bericht getrennt. Usage ist kein
verlässlicher Zähler des verbleibenden ChatGPT-Wochenkontingents. Zusätzlich werden
Modell, Run-Zahl, Dauer und Erfolgsrate geführt. Gemeldete Tokens stehen außerdem
je Provider, Modell und Run-Art im Bericht;
die gesamte `reported_usage` ist kein gemeinsames Kontingent verschiedener Anbieter.
Für die offizielle verbleibende Usage Codex interaktiv starten und `/status` verwenden.
Kein Scraping von UI-Ausgaben.

## Tests

```sh
PYTHONPATH=tools/decomp_harness/src python3 -m unittest discover -s tools/decomp_harness/tests -v
decomp-agent run --dry-run
```

Die Tests laufen ohne ROM, Docker, Netzwerk oder echte Codex-Nutzung. Sie decken Parser,
SQLite, Zustände/Resume, Scoring/Relokationen, Scheduler/Eskalation, Credential-Guard,
JSONL/Usage, echte kontrollierte Fake-CLI-Prozesse, Timeout/Abbruch, Änderungsgrenzen,
Publikations-Recovery und Erhalt fremder gestagter Änderungen ab. Hinzu kommen lokale
Muster, Schema-Migration, Luna-Eskalation, Claude-Auth/JSONL, echte private Worktrees,
zwei überlappende Fake-Worker, serielle Publikation und gemeinsame Budgets.
Zusätzlich werden projektweite lokale Vorauswahl, Versuchsdeduplizierung, symbolische
ASM-Regeln und Cache-Invalidierung bei geänderten Eingaben/Toolchains sowie manipulierten
Artefakten geprüft. Auch mit warmem Cache bleibt die vollständige ROM-Prüfung Pflicht.

Der praktische Test dieses Branches ist in [INTEGRATION.md](INTEGRATION.md) festgehalten.
