# Checkliste: Source-Port in Ship-of-Harkinian-Qualität

Ziel: Banjo-Tooie aus dem dekompilierten C als echtes 64-Bit-Programm (x64 und arm64)
mit Little-Endian-Speicher, ohne wasm2c, ohne Emulation von Code. Grafik über die GPU,
Assets werden beim ersten Start aus der ROM des Nutzers extrahiert, und das Spiel
läuft unter Windows, Linux und macOS. Vorbild sind Ship of Harkinian, 2 Ship 2 Harkinian
und Starship (alle libultraship + Torch).

Arbeitspakete mit Schritten, Abnahme und Fallen (Stand 2026-11-16): [FAHRPLAN_SOH.md](FAHRPLAN_SOH.md).

Stand 2026-11-08: Der ILP32-Build (`pc/native/wasm`) spielt bis Spiral Mountain, und
`BT_VCLOCK=1` macht Läufe reproduzierbar (siehe PROGRESS.md).

**Arbeitsprinzip:** Jede Phase ändert eine Sache und wird gegen die vorige verglichen:
gleiches Eingabeskript, gleiche Bilder bzw. gleicher Zustands-Hash pro Frame. Der
N64-Build muss dabei byte-identisch bleiben (`make check`). Ohne diesen Vergleich gibt
es kein Orakel, und Agents raten.

Aufwand: S = Tage, M = 1–2 Wochen, L = Wochen, XL = Monate (Agent-Zeit, grob).

Kennzeichen: **[Skript]** erledigt ein Skript ohne Agent; **[Agent]** ein Agent arbeitet eine
generierte Liste nach dem Runbook unten ab; **[Mensch]** braucht Urteil oder Augen.

---

## Werkzeuge: erst Skripte, dann Agents (Stand 2026-11-09)

Alles läuft über `pc/native/wasm/port.py`; die Ausgaben sind wenige Zeilen, damit Agents
keine Logs lesen müssen. Die Arbeitslisten erzeugen Skripte; niemand pflegt sie von Hand.

| Befehl | Zweck | Laufzeit |
|---|---|---|
| `port.py status` | Zahlen aller Arbeitslisten und Checklisten-Fortschritt | < 1 s |
| `port.py gate` | Build + Unit-Tests + Intro-Lauf, Trace gegen `build/reference/intro.jsonl` | ~3 min |
| `port.py gate --full` | dazu Neues Spiel und editierter Spielstand | ~8 min |
| `port.py gate --accept` | neue Referenz speichern (nur nach bewusst gewollter Verhaltensänderung) | |
| `port.py worklist traps\|xsym\|calls\|lp64 [--file F]` | offene Punkte einer Phase, nach Quelldatei | < 1 s |
| `xsym_report.py` | Diagnose-Build mit Pass `bt-xsym` (prüft jeden Datenzugriff gegen sein Label), Korpus-Lauf, Liste der Zugriffe über fremde Symbole und der Label-Gruppen, die ein C-Objekt werden müssen | ~10 min |
| `hazards64.py` | alle Spieldateien als LP64 prüfen (`-fsyntax-only`), Liste der Pointer/int-Mischungen | 3 s |
| `lp64_words.py` | Integer, die Pointer tragen, zu `BtIntPtr` umtypisieren (bis nichts mehr geht), Rest nach `build/lp64_words_left.tsv` | ~2 min |
| `offsets.py scan\|genstruct\|apply\|verify\|check` | rohe Offsets → Struct-Felder; `verify`/`check` prüfen im Docker-Klon gegen HEAD | 5–20 min |
| `data_to_c.py scan\|apply\|verify\|revert` | Asm-`.data` eines Moduls als typisierte C-Definitionen ans Ende der C-Datei, yaml `data`→`.data`; `verify` vergleicht im Docker-Klon `.data` und Relocations jedes Objekts mit HEADs Asm-Objekt; Rest: `port.py worklist data` | 1 + 15 min |
| `protos.py`, `protos.py fix`, `protos.py n64` | Liste der Deklarationen, die ihrer Definition widersprechen; `fix` schreibt sie zeilenneutral auf die Signatur der Definition um (wo deren Typen fehlen: portable Form gleicher Registerklasse) und nimmt zurück, was clang in N64- oder nativer Sicht ablehnt; `n64` prüft im Docker-Klon gegen `build.pre` und nimmt zurück, wo IDO anderen Code erzeugt (`protos_ido_keep.txt`) | 1 + 10 min |
| `syntax_new.py` | nur die clang-Fehler, die HEAD nicht hat (N64-Sicht), vor jedem `make check` | 30 s |
| `corpus.py`, `save_editor.py`, `trace_tools.py --cross-build` | Wiederholbarkeit, Spielstände, Trace-Vergleich zweier Builds | |

### Runbook für Agents (eine Datei pro Durchgang)

1. `python3 pc/native/wasm/port.py worklist <liste>` und die oberste Datei nehmen, die
   noch niemand bearbeitet (eine Datei = ein Commit = ein Agent).
2. `port.py worklist <liste> --file <datei>` zeigt nur deren Punkte. Ändern, N64-Code
   unverändert lassen oder unter `BT_NATIVE` setzen.
3. `port.py gate` muss PASS melden. Bei FAIL nennt die Ausgabe Retrace und Feld; erst
   die Ursache klären, nie die Referenz anpassen, um eine Abweichung zu verdecken.
4. Bei Änderungen in `src/` oder `include/`: `make check` (Docker) muss grün sein.
5. Commit mit der Liste und der Zahl vorher/nachher (`port.py status`), dann nächste Datei.
6. Abbruch und Notiz in `PROGRESS.md`, wenn ein Punkt nach zwei Ansätzen nicht passt.

---

## Phase 0 – Referenz und Messwerkzeuge (M)

- [x] Matching-Decomp: alle C-Funktionen gematcht, `make check` grün
- [x] ILP32-Referenzbuild bootet, rendert, spielt Audio, nimmt Eingaben an
- [x] Virtueller Takt `BT_VCLOCK=1`, Läufe byte-identisch wiederholbar
- [x] `BT_TRACE=datei`: pro Retrace ein Hash von Framebuffer und Spielzustand (Spieler-
      Position/Status, Map-ID, Actor-Liste, Flags); ein Werkzeug zeigt den ersten
      abweichenden Frame und das abweichende Feld zweier Traces
      → `wasm/host/trace.c`, Vergleich: `python3 pc/native/wasm/trace_tools.py A B`.
      Nur headless mit virtuellem Takt und Skripteingabe; Details und Nachweise in
      `PROGRESS.md`, Abschnitt „Retrace traces“: zwei 950-s-Läufe mit 56.943
      bytegleichen Retraces bis Spiral Mountain; 31 Bilder auch bytegleich zum
      Programmstand vor dem Tracing.
- [x] Laufunabhängigkeit vom Build prüfen: Mit `BT_NOINLINE=1` zählt der Takt die
      Schleifen anders. Entweder Takt über Systemaufrufe statt Latches, oder Traces nur
      innerhalb eines Builds vergleichen
      → Die zweite Möglichkeit gilt: Build-Kennung aus Gast-Wasm, Host-Quellen und
      Build-Konfiguration; der Vergleich weist unterschiedliche Builds zurück.
      Buildübergreifende Gleichheit und Unabhängigkeit von `BT_NOINLINE` sind damit
      ausdrücklich **nicht** nachgewiesen. Nachtrag 2026-11-09: Drei verschiedene Builds
      (Datenlayout verschoben, Codemod in 52 Dateien, neuer Host-Code) liefern mit
      `--cross-build` identische Traces zur Referenz; für Änderungen ohne neue Schleifen
      taugt der Vergleich also praktisch. Vor Phase 1 bleibt ein geeigneter
      buildübergreifender Takt beziehungsweise ein validierter Vergleichspunkt nötig.
- [ ] Testkorpus: Eingabeskripte und EEPROM-Stände für jede Welt, jeden Boss, jedes
      Minispiel, jede Verwandlung, Mehrspieler. Spielstände über Flags im EEPROM
      erzeugen (Save-Editor), damit kein Skript 10 Stunden spielen muss
      → `wasm/corpus.py` führt Intro, neues Spiel und einen erzeugten Spielstand
      je zweimal in getrennten Verzeichnissen aus. `wasm/save_editor.py` erzeugt
      und bearbeitet separate 2-KiB-EEPROM-Dateien mit den originalen Prüfsummen.
      Die vollständige Welt-/Boss-/Minispiel-/Verwandlungs-/Mehrspielerabdeckung
      ist weiterhin offen; geladene Maps zählen nicht als Szenenabnahme.
- [x] Ein Befehl als Orakel für alle weiteren Phasen: `port.py gate` vergleicht den Trace
      jedes Laufs mit gespeicherten Referenzen (`build/reference/*.jsonl`, über Builds
      hinweg, nur die Build-Kennung ist ausgenommen) **[Skript]**
- [ ] Die 12 Funktions- und 4 Daten-Traps im Referenzbuild beheben
      → Jetzt 10 Funktions-Traps, **0 Daten-Platzhalter**. `_Printf` verwendet
      die originale libultra-Implementierung; Motorzugriffe melden korrekt den
      nicht initialisierten Pak. Die vier OS-Variablen sind typisiert definiert;
      `__osRunningThread` wird vom Scheduler aktualisiert. Neue fehlende Daten
      brechen den Build ab, statt durch Nullspeicher ersetzt zu werden.
      Die 10 Reste liegen auf Pfaden, die der native Build nicht nimmt: `__osSi*` (der
      CIC-Austausch läuft nativ über `native_cic_response`, nur der N64-Zweig in
      `1E35920.c`/`dbDll.c` ruft sie), `heap_update_empty_block` (`defrag.c`, aber
      `heap.c` ist durch `memory.c` ersetzt), `func_80117248` (handgeschriebenes Asm
      `1EF0820.s`), `native_render` (Codex-`.inc`), Linker-Symbole `core2_VRAM_END`,
      `overlay_syscalls(_end)`, `ovl_entrypoint`. **[Agent, S]** je Name: Aufrufer unter
      `BT_NATIVE` ausblenden oder portieren, bis `traps.txt` leer ist.
- [ ] Korpus erweitern **[Skript + Mensch]**: je Welt ein Eingabeskript ab einem per
      `save_editor.py` erzeugten Spielstand (Welt offen, Warp-Pad aktiv), Ziel-Map als
      Abnahme; `corpus.py` um die Fälle ergänzen. Welche Flags eine Welt braucht, liefert
      ein Mensch einmal mit einem echten Spielstand (`save_editor.py --input`)
- [ ] Referenzbuild durchgespielt: jede Szene des Korpus läuft ohne Trap/Crash und sieht
      richtig aus (Abgleich gegen Emulator-Screenshots). Erst dann taugt er als Referenz
      **[Mensch]**: Emulator-Screenshots (ares/mupen64plus) am selben Spielstand; der
      Bildvergleich selbst ist Skript (`BT_DUMP` + Toleranzvergleich wie `render_test.py`)

## Phase 1 – Alle Daten in C (L)

Aktuell verarbeitet `data.py` 1.715 Assembly-Eingabedateien, davon 718 mit
Datenlabels. Das Inventar zählt 5.728 noch nicht in C definierte Labels.
Bei 64 Bit wachsen Pointer-Felder, also müssen die Daten typisiert in C stehen.
Bestand reproduzieren: `python3 pc/native/wasm/data_inventory.py /pfad/inventar.json`.

- [ ] `.data`, `.rodata`, `.bss` aller Module als C-Definitionen mit echten Typen
      (Tabellen, Funktionszeiger-Tabellen, Strings, Float-Konstanten, Jump-Tables)
      **[Skript, dann Agent]**: Ein Generator schreibt aus `data.py`s Parser pro Asm-Datei
      eine C-Datei mit Byte-genauen Initialisierern und den Typen aus den Deklarationen
      der Spiel-Header (`data_inventory.py` kennt sie); Agents korrigieren nur, was der
      Generator nicht typisieren kann. Nach jeder Datei `gate`
      → Zwei Umstellungen implementiert und wegen fehlender Trace-Gleichheit
      zurückgenommen: Save-Callbacks und neun HUD-Stile. Reviewbarer Versuch:
      `build/ilp32/phase01-validation/typed-data-rejected.patch`.
- [x] Generator für `.data` **[Skript]**: `data_to_c.py` nimmt den Typ jedes Labels aus seiner
      Deklaration (libclang, N64-Sicht) und den Initialisierer aus den ROM-Bytes (Floats
      rundungsgenau, Adressen als `(T)symbol` aus den Relocations). `T x[]` bekommt die Größe aus
      dem Label; ein `u8 x[]`-Blob mit Adressen wird `ActorData[n]` (0x48, Actor-Deskriptor) oder
      `ActorDataX[n]` (0x50); s32/u32, die Adressen tragen, werden überall `BtIntPtr`/`BtUIntPtr`;
      Symbole ohne Datei-Deklaration bekommen eine im angehängten Block. Abgelehnt: Labels ohne
      Deklaration, Typ kleiner als das Label, C-Datei mit eigenem `.data` (es käme zuerst und
      verschöbe alles), nativ definierte Labels, block-lokale Typen (Kompilierprüfung je Modul).
      Stand 2026-11-10: 182 Module in C, make check OK, gate --full PASS.
      Abends 415 Module **[Skript]**: nur per `&lab` benutzte Skalare werden `T lab[n]`
      (`&lab`→`lab`, gleiche Adresse und Schrittweite); Labels, die nur die eigenen Daten
      referenzieren, werden `u8 lab[n]`; Flag-Wörter (auch `boot_thread_stack+n`) und rohe
      Core-Adressen in Zeigerfeldern (`D_8011A1BC + 0x64`) gehen ohne Overlay-Reloc in die ROM
      (`tooie_utils.cpp:221` nimmt nur Relocs ins eigene Overlay); IDO legt jede Variable auf
      ≥ 4 Bytes; das letzte Label darf in der 16-Byte-Sektionsauffüllung enden; `ActorData`
      0x44 ist `BtIntPtr unk44` (als Wort gelesen, Baddies halten dort einen Zeiger);
      `apply` prüft auch die native Sicht und kopiert nichts, was dort nicht kompiliert;
      `verify` kopiert die neue `banjotooie.ld` zurück. Jede Definition trägt
      `BT_DATA(align, modul, offset)`; der Pass `bt-datagroup` macht nativ aus den Definitionen
      eines Moduls einen gepackten Block an den N64-Offsets (Labels als Aliase, wie data.py für
      asm). Ohne ihn legt clang Globals in der Reihenfolge der ersten Erwähnung an, auf 16 Bytes
      ausgerichtet, und wasm-ld verteilt sie: Nachbarzugriffe (`su/coaster/data.c`:
      `D_808003C0 + i * 0x5C` reicht in `D_8080041C`) lasen fremde Tabellen (per Halbierung
      gefunden, new-game Retrace 46.435). Stand: 415 Module in C, make check OK, gate --full
      PASS gegen die unveränderten Referenzen; 197 in asm (152 mit Grund in der Worklist, 45
      kompilieren am Dateiende nicht: block-lokale Typen)
- [x] Parser-Fehler in `data.py` **[Skript]**: `.asciz "\x8C"` auf einer Fortsetzungszeile
      ohne Adresskommentar fiel weg (Floats 70.0/280.0 → 32.0/128.0 in boggy/kidshome,
      boy, girl und captainblubber); jetzt gelesen
- [x] Ursache der Actor-Flag-Abweichungen (Retrace 46.310/46.311, auch bei den
      zurückgenommenen HUD-/Save-Patches) **[Skript]**: Flag-Wörter in Actor-Deskriptoren
      (`ActorData` 0x24/0x3C, gelesen von `func_80102FA0`) haben zufällig den Wert einer
      Stub- oder Core-Adresse (`0x80082C10` = `_bsbtrot_entrypoint_10`, `0x80104410`);
      splat/data.py machten daraus Zeiger, nativ also Layout-abhängige Flags. `data_to_c.py
      constants` schreibt die 17 Stellen nach `pc/native/wasm/stub_constants.txt`, data.py
      gibt sie roh aus. Danach laufen die Builds mit den Modulen in C und in asm identisch
      (56.943 Retraces); Referenzen 2026-11-10 bewusst neu (`gate --accept`), alte und neue
      trennen sich genau dort (`actors[0].health_flags[2]` 0x01040000 → 0x00050000, Bit 24
      `flag64_0` jetzt wie auf dem N64 aus). Die beiden zurückgenommenen Patches erneut versuchen
- [ ] Restliche `.data`-Module **[Agent, je Modul]**: `port.py worklist data` nennt den Grund.
      2026-11-12 **[Skript + Hand]**: 415 → 497 Module in C (funktionslokale Typen zeilenneutral
      auf Dateiebene, Füllvariablen für Null-Lücken, innere Labels ohne Namen werden Teil der
      Tabelle, neun Module mit Zugriffen über innere Labels auf Felder/Spalten umgeschrieben;
      make check OK, verify 0 Abweichungen, gate --full PASS). Rest: 114 in `port.py worklist data`.
      Häufigste (Stand abends 2026-11-10): ein Label beginnt mitten in einem Array-Element
      (Nachbarzugriff, ein C-Objekt aus beiden machen); Skalar-Label vor einem größeren Objekt,
      das nicht nur per `&` benutzt wird (Struct anlegen, zeilenneutral); Struct-Felder `u32`,
      die Funktionszeiger halten (chmole-Familie); Byte-Blobs mit Zeigerarithmetik
      (`(D - 8)`, `== D`); block-lokale Typen; C-Dateien mit eigenem `.data`.
      Danach `data_to_c.py apply` und `verify`
- [x] `.bss` nach C **[Skript]** (2026-11-12): `bss_to_c.py apply`, 582 Labels typisiert, 195 als
      Bytes, 18 bleiben bis zum `.data` ihres Moduls in asm; `data.py` legt jede C-Definition per
      `__bt_place_`-Platzhalter an ihren Platz im Asm-Block (gleiches Layout, Respawn-Punkt
      `&D_80127040 + 0x10` → `D_80127050` funktioniert). Gate `--full` PASS
- [ ] Die 151 offenen `R_*`-Rodata-Symbole und der Rodata-Split (Branch
      `claude/awesome-lovelace-b12e6f`) zusammenführen
      → Die Zahl 151 ist veraltet: Im aktuellen Build sind 146 `R_*` in C
      definiert, ohne offene `R_*`-Referenz. Der Rodata-Branch ist noch nicht
      zusammengeführt: Die Vorschau hat 11 Konfliktdateien und sechs neue
      Dateisplits; bestehende gematchte/native Funktionen müssen dabei erhalten
      bleiben; die älteren Funktionskörper des Branches können diese nicht ersetzen.
- [x] Zugriffe über fremde Symbole automatisch finden **[Skript]**: Pass `bt-xsym`
      (`BT_XSYM=1`, eigener Build-Baum `build/ilp32-xsym`) prüft jeden Lade-/Speicher-
      zugriff, dessen Adresse von einem Datenlabel abgeleitet ist, gegen die Ausdehnung des
      Labels; `xsym_report.py` nennt Funktion, benutztes Label und getroffenes Symbol
      und fasst Labels zu Gruppen zusammen, die ein gemeinsames C-Objekt werden müssen
      (`build/ilp32-xsym/xsym_groups.tsv`). Stand: 2026-11-09 mit Intro, Neuem Spiel und editiertem
      Spielstand: 6.062 geprüfte Zugriffsstellen, 980 verlassen ihr Label, in 268
      Funktionen; 95 Label-Gruppen. 2026-11-12 mit dem Korpus-Fall `worlds` dazu: 6.076
      Stellen, 1.227 verlassen ihr Label, in 325 Funktionen; 109 Label-Gruppen. Beide 2026-11-08 zurückgenommenen Umstellungen
      (`glgamedata`-Callbacks, `scinfobar`-HUD) liegen genau in solchen Gruppen; der
      Patch hatte deren Zugriffe aber schon umgeschrieben, die Actor-Flag-Abweichung
      hat also eine andere Ursache (siehe Layout-Test)
- [x] Layout-Test **[Skript]**: `BT_DATA_ALIGN=256 BT_OUT=build/ilp32-shift build.py`
      verschiebt jeden Asm-Datenblock ohne Inhaltsänderung; `port.py gate --exe
      build/ilp32-shift/bt_game --case new-game` ergab 2026-11-09 56.943 identische
      Retraces. Reine Adressänderungen ändern das Verhalten nicht; eine Abweichung nach
      einer Datenumstellung liegt also an deren Inhalt oder Zugriffen. Nächster Schritt
      für den HUD-Patch **[Agent, S]**: Patch auf einen Datensatz verkleinern und mit
      `gate --exe` halbieren, bis der abweichende Wert feststeht
- [ ] Zugriffe über fremde Symbole (Code erreicht Tabelle B über die Adresse von A)
      in echte Strukturen oder Arrays umschreiben **[Agent, je Gruppe]**:
      `port.py worklist xsym`; erst die Daten der Gruppe als ein C-Objekt, dann die
      Zugriffe; `gate` muss PASS bleiben. Nur Pfade, die der Korpus ausführt, sind erfasst:
      mit wachsendem Korpus `xsym_report.py` erneut laufen lassen
      → Die versuchten C-Array-/Struct-Zugriffe sind im oben genannten Patch
      enthalten. Im aktiven Build bleiben die ursprünglichen Zugriffe erhalten,
      bis die Actor-Flag-Abweichungen geklärt sind.
- [ ] Rohe Worte, die Overlay-Stub-Adressen sind, als Funktionszeiger im C
      → Die neun HUD-Stile sind im zurückgenommenen Patch als Funktionszeiger
      typisiert und gegen jedes Originalwort geprüft. Trotz Bildgleichheit
      unterscheiden sich Actor-Flags; deshalb noch nicht im aktiven Build.
- [ ] `make check` byte-identisch; nativer Build ohne `data.py`; Trace = Referenz

## Phase 2 – Portables C statt IDO-Emulation (L)

Heute biegt der LLVM-Pass `FixCalls` IDO-Eigenheiten zur Laufzeit gerade. Für einen
normalen Compiler muss das in die Quellen. Die vollständige Liste schreibt FixCalls bei
jedem Build nach `build/ilp32/widened.txt`; `port.py worklist calls` ordnet sie den
Quelldateien zu (Stand 2026-11-09: 825 Punkte in 342 Dateien: 216 durchgereichte
Argumente `ARGS`, 339 `void`-Funktionen mit gelesenem Ergebnis `RET`, 263 fehlende
`return`s `UNDEFRET`, 4 `VOIDSTORE`, 3 `REGMAP`). Fertig, wenn die Liste leer ist.
**[Agent, je Datei]**; jeder Punkt ist eine lokale Änderung unter `BT_NATIVE`.

- [ ] Durchgereichte Argumente (fehlende a0..a3) als echte Parameter
- [ ] Fehlende `return`s und gelesene Ergebnisse von `void`-Aufrufen ausschreiben
- [ ] Zugriffe auf Nachbar-Stack-Slots (`(&sp28) - 1`, 10 Fälle) in Arrays/Structs
- [x] Liste widersprüchlicher Prototypen **[Skript]**: `protos.py` (4 s) vergleicht per
      libclang jede Deklaration mit der Definition (kanonische Typen, LP64-Sicht) →
      `build/protos.tsv`, `port.py worklist protos` (schlimmste zuerst). 2026-11-10: 8.809
      Deklarationen: float 421 (131 Funktionen: int- statt float-Register), arity 380 (159),
      ret 5.207 (meist `s32` deklariert, Definition `void`), size 2.801 (800)
- [x] Deklarationen per Skript an die Definition angleichen **[Skript]**: `protos.py fix` + `n64`
      (2026-11-10): 4.499 Deklarationen in drei Durchgängen umgeschrieben (exakte Signatur,
      portable Form, Stub-Namen `_x_entrypoint_N`); 8.809 → 4.217 Abweichungen (size 2.801 →
      1.125 nach `lp64_words.py`, ret 5.207 → 2.309), `calls` 825 → 698. `make check` OK, Gate dreimal PASS.
      Rest: 1.356 Datei/Funktion-Paare, bei denen IDO mit der echten Signatur anderen Code
      erzeugt (`protos_ido_keep.txt`: Argumentumwandlung, rohe Float-Bits im Integer-Register);
      dort bleibt FixCalls zuständig, bis ein Agent die Aufrufstelle klärt
- [ ] K&R- und widersprüchliche Prototypen: ein gemeinsamer Header pro Modul
      **[Agent, je Funktion]**: Deklaration an die Definition angleichen; wo IDO dann anderen
      Aufrufercode erzeugt (Argumentumwandlung), bleibt die alte Form unter `#ifndef
      BT_NATIVE` (Zeile nicht verschieben). Reihenfolge: float, arity, ret mit benutztem
      Ergebnis (`calls`-Liste RET/VOIDSTORE), size
- [ ] Bitfeld-Reihenfolge in den Struct-Definitionen (`#if` Endianness) statt `bitfields.py`
- [ ] IDO-only-Formen (`1 << (n + 0x1F)`, Array-Zuweisung …) unter `BT_NATIVE` ersetzt
- [ ] clang mit `-Wall -Werror` für die relevanten Warnungen; ASan/UBSan-Läufe sauber
- [ ] ILP32-Build ohne `bt-fixcalls`, `bt-stackslots`, `bitfields.py`; Trace = Referenz

## Phase 3 – Little-Endian (L)

- [ ] Pass `bt-bigendian` entfernen; der Speicher hat die Byte-Reihenfolge des Hosts
- [ ] Jede Stelle, die ROM- oder Asset-Daten liest, konvertiert beim Laden (siehe Phase 4)
- [ ] Byte-/Wort-Aliasing im Code finden (`*(u32 *)&bytes`, Unions, Byte-Offsets in
      Wörter) und endianneutral schreiben
- [ ] Display-Listen aus der ROM beim Laden in Host-Reihenfolge
- [ ] EEPROM-Format bleibt kompatibel zu echten N64-Spielständen (Konvertierung beim
      Laden und Speichern)
- [ ] Trace = Referenz für den gesamten Korpus

## Phase 4 – Asset-Pipeline wie SoH/Starship (XL)

- [ ] Katalog aller Asset-Typen in `assets.bin` und in den Overlays: Modelle (Geo-
      Layouts, Vertizes, Display-Listen, Texturen), Animationen, Sprites, Map-Daten
      (VPL, Kollision), Setup-Dateien (Actor-Spawns), Dialoge/Texte, Musik-Sequenzen,
      Soundbanks und weitere. Für jeden Typ: Format, Loader, Pointer-Felder
- [ ] Pro Typ ein Konverter: ROM-Format (BE, 32-Bit-Offsets) → native Struct; die
      vorhandenen Codex-Module (`model.c`, `geometry_data.c`, `animation_resource.c`,
      `textures.c` …) als Ausgangspunkt, jeder mit Unit-Test gegen echte ROM-Daten
- [ ] Torch-Factories für jeden Typ, YAML-Beschreibung aller Assets
- [ ] Beim ersten Start: ROM wählen, Hash prüfen (US-Version), `.o2r`-Archiv erzeugen
- [ ] Das Spiel lädt Assets per ID aus dem Archiv statt per PI-DMA aus der ROM
- [ ] Weder Repo noch Release enthalten ROM-Inhalte
- [ ] Trace = Referenz

## Phase 5 – 64 Bit (XL)

Der härteste Teil, den der frühere 64-Bit-Versuch nicht geschafft hat. Mit Phase 1–4
ist er beherrschbar, weil Daten und Assets dann typisiert sind.

- [x] Liste aller Pointer-zu-int-Casts und Kürzungen erzeugen **[Skript]**:
      `hazards64.py` (3 s) → `build/hazards64.tsv`. Erster Stand 2026-11-09: 7.236
      Stellen in 638 Dateien (2.453 pointer-to-int, 2.314 int-conversion, 1.854
      int-to-pointer, 521 void-pointer, 90 shorten-64-to-32)
- [x] Alle Spieldateien kompilieren als LP64 **[Skript]**: 52 Dateien scheiterten an
      114 statischen Tabellen `u32 X[] = { (u32)func, … }` (Spieler-Zustände `bs*`,
      Actor-Tabellen). `lp64_fnwords.py` setzt deren Elementtyp auf `BtFnWord` (`u32`
      unter IDO, `__UINTPTR_TYPE__` nativ); `make check` OK. Danach 6.539 Stellen in
      635 Dateien
- [x] Integer, die Pointer tragen, pointerbreit machen **[Skript]**: `lp64_words.py` liest
      die LP64-Diagnosen per libclang, sucht die Deklaration, durch die der Pointer läuft
      (Cast, Ziel- oder Quellvariable, Parameter und Rückgabetyp in **allen** Deklarationen
      einer Funktion, Felder erzeugter `Obj…`-Structs) und ersetzt nur das Typ-Token `s32`/`u32`
      durch `BtIntPtr`/`BtUIntPtr` (`include/PR/ultratypes.h`: unter IDO `long`/`unsigned long`
      wie s32/u32, also N64 per Konstruktion gleich; nativ `intptr_t`, in
      `pc/native/include/PR/ultratypes.h`). Prototypen mit Pointer-Typ neben `s32`-Prototypen
      gelten als verträglich (gleiches Register, gleiche Größe). 2026-11-10: 8.818
      geänderte Zeilen in ~880 Dateien; `hazards64` 6.539 → 908; alle Dateien kompilieren LP64;
      `offsets.py check` make check OK, 0 Funktionen anders; `port.py gate --full` PASS.
      **Regel:** `int` nie in `long` umtypisieren, das ändert IDOs Code (gcskyDll); das Skript
      fasst nur `s32`/`u32` an
- [ ] Rest der LP64-Liste **[Agent, je Datei]**: `port.py worklist lp64 --file F` (1.041; vor
      `protos.py fix` 908, weil falsche Deklarationen 1.100 Mischungen vor dem Compiler verbargen);
      Gründe in `build/lp64_words_left.tsv`: Felder echter Structs und Globals (Layout von
      Daten, die aus der ROM kommen können), Array-Elemente, Speicherzugriffe
      `*(s32 *)(p + 0x3C)`, `int`-Deklarationen, Aufrufe über Funktionszeiger
- [ ] Aufrufe über Funktionszeiger mit anderer Signatur als die Funktion **[Skript, dann
      Agent]**: eine Tabelle `void (*)(s32)`, deren Funktion jetzt `BtIntPtr` nimmt, übergibt
      nativ 32 Bit und lässt die oberen Bits offen (arm64/x64-ABI). Direkt typisiert gibt es
      nur 13 Fälle (`-Wincompatible-function-pointer-types`, 2 mit `BtIntPtr`, beide gegen
      Pointer-Parameter, also verträglich). Der Rest läuft über `BtFnWord`-Tabellen und Casts
      und ist statisch nicht sichtbar: im ersten LP64-Build `-fsanitize=function` (prüft bei
      jedem indirekten Aufruf die Signatur) über den ganzen Korpus laufen lassen
- [x] Feste Offsets mit bekanntem Struct durch Felder ersetzen **[Skript]**:
      `offsets.py` (libclang, parst wie der N64-Build: MIPS, ohne `BT_NATIVE`) schreibt
      `*(T *)((u8 *)p + 0x14)` → `p->feld`, `&p->feld[i]`, `obj.feld` um, wenn an dem
      Offset ein Feld genau dieses Typs liegt (Arrays, verschachtelte und anonyme Structs).
      `offsets.py pad` teilt vorher Byte-Padding in Headern in typisierte Felder (nur
      Grundtypen, Größe und Ausrichtung unverändert, keine namentlich benutzten Arrays).
      `offsets.py verify` prüft alles in einem Docker-Klon: HEAD als Basis, Objekte pro
      Funktion vergleichen (`n64_objdiff.py`), abweichende Funktionen zurücknehmen und in
      `offsets_ido_keep.txt` eintragen, bis `make check` OK ist.
      Stand 2026-11-09: 545 Ersetzungen in 135 Dateien; 17 Funktionen (81 Stellen)
      braucht IDO in der Rohform. Frischer `make check` OK, SHA-1 `af479771…`;
      `port.py gate --full` PASS
- [x] Parametertypen aus Aufrufern und erzeugte Structs **[Skript]**: `offsets.py infer`
      leitet `void *argN` aus direkten Aufrufern ab (`build/offsets_types.tsv`),
      `offsets.py genstruct` baut für den Rest pro (Datei, argN) ein einzeiliges
      `typedef struct { … } Obj<datei>_<argN>;` aus allen Offsets/Breiten; `apply` schreibt
      dann `((Typ *)argN)->feld`. `place_decls.py` setzt jede Deklaration ohne
      Zeilenverschiebung vor die erste Benutzung (ans Ende einer `;`/`}`-Zeile, im selben
      `#if`-Zweig). Stand 2026-11-09: 2.102 Ersetzungen in 313 Dateien, 27 Funktionen
      in `offsets_ido_keep.txt`; `verify` und `make check` OK
      **Regel:** Zeilenzahl jeder Datei bleibt gleich (as1 plant nach `.loc`-Zeilen; eine
      neue Zeile oder eine Deklaration vor der ersten Zeile einer Funktion ändert den Code)
- [ ] Feld fehlt oder passt nicht **[Skript, dann Agent]**, 915 Stellen: 282 in
      Byte-Arrays, die der Code auch namentlich benutzt oder deren Ausrichtung nicht passt;
      175 hinter dem Ende des deklarierten Structs oder in Bitfeldern (Struct zu kurz
      deklariert); 165 Pointer-Feld mit anderem Pointer-Typ; Rest: Feld anderen Typs
      (Vorzeichen, `f32` als `s32` gelesen …). Nächstes Skript: Structs am Ende verlängern
      und Pointer-Felder auf den gelesenen Typ setzen, dann `apply` + `verify`
- [x] genstruct auch für lokale Variablen, benannte Parameter und Globals **[Skript]**:
      pro (Funktion, Variable) bzw. (Datei, `&D_…`) ein `Obj…`-Struct, auch mit
      Funktionszeiger-Feldern. 2026-11-10: weitere 3.981 Ersetzungen (6.083 im Log), offen
      8.756 → 4.774, 64-Bit-kritisch 1.366 → 173; 86 Funktionen in `offsets_ido_keep.txt`;
      `verify` make check OK. Fehler unterwegs: `((T *)(p + 0x17C))[i]` braucht `(&feld)[i]`;
      `revert` muss jede Definition einer Funktion zurücknehmen (`#ifdef BT_NATIVE`-Varianten
      stehen davor); `syntax_new.py` meldet nur clang-Fehler, die HEAD nicht hat
- [ ] Rest ohne Struct-Typ **[Agent, je Datei]**: `port.py worklist offsets` (4.774) und
      `offsets64` (173). Übrig sind Bases mit zwei Typen am selben Offset oder überlappenden
      Breiten, Zugriffe mit Laufindex, Ausdrücke als Basis (`*(void **)(p + 0x88)`), und die
      86 Funktionen, in denen IDO die Rohform braucht (dort `#ifdef BT_NATIVE`-Zweig oder
      Struct so wählen, dass IDO gleich bleibt)
- [ ] Erzeugte `Obj…`-Structs benennen und zusammenführen **[Agent, je Datei]**: gleiche
      Objekte in mehreren Dateien (z. B. Actor-Daten) zu einem Header-Struct machen
- [ ] 439 Stellen mit unvollständigem Struct (nur vorwärts deklariert): Definition
      aus den Zugriffen erzeugen
- [ ] Feste Größen statt `sizeof` (Freelist-Strides, 49× `heap_alloc(0x…)`) auf
      `sizeof` umstellen, sobald die Structs vollständig sind
- [ ] Actor-Struct und andere große Structs: alle Felder benannt, `_Static_assert`
      für das N64-Layout im IDO-Build
- [ ] Segment-Adressen und `0x80xxxxxx`-Konstanten über eine Segment-Tabelle
- [ ] Handles statt Pointer, wo 32-Bit-Werte in Assets oder Spielständen landen
- [ ] Heap: Allokator mit Host-Größen; Defragmentierung verschiebt Blöcke, also alle
      Pointer-Reparaturen prüfen
- [ ] Die Codex-`*_native.inc`-Ersatzmodule zusammenführen oder entfernen
- [ ] Build ohne wasm2c, direkt mit clang/MSVC für x64 und arm64; Trace = Referenz

## Phase 6 – Overlays statisch linken (M)

- [ ] Alle 52 Overlays (851 Sektionen) in das Programm linken
- [ ] Overlay-Laden wird zum Lookup, Syscall-Stubs und `_entrypoint` werden direkte Aufrufe
- [ ] Semantik beim Neuladen nachbilden: `.data` und `.bss` eines Overlays werden beim
      Laden zurückgesetzt (Snapshot beim Start, Kopie beim Laden)
- [ ] Code, der Overlay-Adressen vergleicht oder speichert, auf IDs umstellen

## Phase 7 – libultra ersetzen (M)

- [ ] Threads, Message-Queues, Timer, Interrupts: das heutige `host/os.c` ohne wasm
      übernehmen (kooperativ, ein Thread zur Zeit, virtueller Takt optional)
- [ ] PI/DMA → Archivzugriffe; SI → Controller über libultraship; EEPROM → Datei im
      Nutzerverzeichnis; VI → Präsentation; Rumble (`osMotor*`) → Gamepad-Rumble
- [x] Mehrere Controller (bis 4) für Mehrspieler (2026-11-12, SDL, ohne libultraship)

## Phase 8 – GPU-Grafik (L)

- [ ] libultraship-Fast3D einbinden (OpenGL, Metal, DirectX 11); `gbi.h` von
      libultraship mit Gfx-Wörtern in Pointer-Breite
- [ ] Microcodes: F3DEX2 (NoN, FIFO) und L3DEX2 (Linien) vollständig
- [ ] Framebuffer-Effekte: Render-to-Texture, CPU-Lesen und -Schreiben von Bildpuffern
      (Pause-Bild, Übergänge, `gczoombox`, Kamera-/Foto-Effekte), Z-Buffer-Lesen. Jede
      Stelle finden und mit Fast3D-Mitteln nachbauen
  - [ ] Pause-Bild im Spiel gegen Software prüfen
  - [ ] Übergänge im Spiel gegen Software prüfen
  - [ ] `gczoombox` im Spiel gegen Software prüfen
  - [ ] Kamera-/Foto-Effekte im Spiel gegen Software prüfen
  - [ ] Z-Buffer-Lesen im Spiel gegen Software prüfen
- [ ] Bildvergleich gegen den Software-RDP pro Frame mit Toleranz, für den gesamten Korpus
  - [x] Werkzeug `wasm/frame_compare.py`: jeder Retrace, Toleranz explizit,
        fehlende Frames/Abmessungen/Backend-Identität prüfen; ROM-freie Tests
- [x] Software-RDP als Debug-Option behalten (`BT_RENDERER=soft`, vorerst Standard)

OpenGL-Zwischenstand: `BT_RENDERER=gl` ist ein nativer macOS-Prototyp mit
GPU-Dreiecken, TMEM/Combiner/Blender und synchronem Gast-Readback bei `BT_SCALE=1`.
ROM-freie CPU-/GPU-Handoff-Tests bestehen; das ist keine Spieleffekt-Abnahme.
Metal und der Wechsel des Standards sind bis zur Bild-Orakel-Abnahme offen.
Abbruch nach zwei Ansätzen (2026-11-09): 8-s-Intro, Ansatz 1: 93/470 Frames
außerhalb Toleranz, maximal 74,332006%; Ansatz 2 (Combiner ohne veränderliches
globales GLSL-Array): 12/470, maximal 0,601627%. Erlaubt sind 0,5% Pixel pro Frame
mit RGB-Kanalabweichung >8/255. **Nicht abgenommen**, Toleranz nicht angehoben.
Belege: `build/gpu-intro-attempt{1,2}/summary.json`; Restarbeiten siehe PROGRESS.

## Phase 9 – Audio (M)

- [ ] n_audio-Befehle als C-HLE statt RSP-Interpreter (inkl. Pole-Filter-IIR, Reverb)
- [ ] PCM-Ausgabe bitgleich zum RSP-Interpreter (`BT_PCM`-Vergleich)
- [ ] Ausgabe über libultraship/SDL, einstellbare Latenz

## Phase 10 – SoH-Komfort (L)

- [ ] ImGui-Menü: Grafik, Audio, Steuerung, Verbesserungen, Cheats, Debug (Actor-Viewer)
- [ ] Tastenbelegung frei, Gamepad-Profile, Gyro optional (2026-11-12: Tastatur über `settings.ini`, kein Menü, keine Gamepad-Profile)
- [ ] Beliebige Auflösung, MSAA, Fenster/Vollbild, VSync (2026-11-12: 1x-4x intern, Vollbild, Filter im Menü; kein MSAA)
- [ ] Widescreen: Projektion plus HUD-Verankerung am Bildrand, Culling erweitern
- [x] 60 FPS per Frame-Interpolation (2026-11-13: `BT_INTERP`/Einstellung „Bildinterpolation“, Zwischenbilder aus der Displayliste mit gemischten Matrizen, Spielzustand unverändert; über 60 Hz hinaus offen. Daneben weiter experimentell 60 Spiel-Bilder/s über das Frame-Intervall, Physik ±7 %)
- [ ] Texture-Packs und Mods über zusätzliche `.o2r`-Archive
- [x] Spielstände im Nutzerverzeichnis, Import/Export echter EEPROM-Dumps (2026-11-12: Datei = rohes `.eep`)

## Phase 11 – Plattformen und Auslieferung (M)

- [ ] CMake-Projekt, Abhängigkeiten als Submodule (libultraship, Torch, SDL)
- [ ] Windows (MSVC und clang-cl), Linux (GCC/clang, AppImage), macOS (Universal Binary)
- [ ] CI baut alle drei Plattformen und führt Unit-Tests und Korpus-Traces aus
- [ ] Releases ohne ROM-Inhalte; Extraktions-Dialog beim ersten Start (2026-11-12: ROM-Auswahl-Dialog, Prüfsumme, Kopie im Nutzerordner; keine Extraktion)

## Phase 12 – Abnahme (L)

- [ ] 100-%-Durchlauf: Isle o' Hags, Mayahem Temple, Glitter Gulch Mine, Witchyworld,
      Jolly Roger's Lagoon, Terrydactyland, Grunty Industries, Hailfire Peaks,
      Cloud Cuckooland, Cauldron Keep, Endkampf und Abspann
- [ ] Alle Bosse, Minispiele, Verwandlungen (Mumbo und Humba Wumba), Solo-Charaktere
- [ ] Mehrspieler-Modi mit mehreren Controllern
- [ ] Speichern und Laden in allen Slots, Neustart des Spiels, Spielstand-Kompatibilität
- [ ] Mehrstündiger Lauf ohne Speicherleck oder Heap-Fehler (ASan-Build)
- [ ] Performance: stabile 60 FPS bei 4K auf Mittelklasse-Hardware
- [ ] Ein Mensch spielt durch; alles Gefundene kommt als Skript in den Korpus

---

## Was Agents gut können und was nicht

- **Gut:** Phase 1–3, 5 und 6. Jede Änderung ist mechanisch, und der Trace-Vergleich
  sagt sofort, ob sie stimmt. Ebenso die Asset-Konverter mit Unit-Tests, CI und die
  Plattform-Builds.
- **Mittel:** Phase 8 (Framebuffer-Effekte brauchen Augenmaß, aber Bildvergleiche helfen)
  und Phase 10 (Widescreen und Interpolation haben viele Sonderfälle).
- **Braucht Menschen:** den Testkorpus in Phase 0 (welche Szenen zählen), das Urteil
  „sieht richtig aus“ und den Durchlauf in Phase 12. Dazu Design-Entscheidungen wie
  Menüs und Standardeinstellungen.

Die Reihenfolge ist wichtig: Phase 0 zuerst. Ohne durchgespielte Referenz und Trace-
Vergleich wird jede weitere Phase zum Ratespiel.
