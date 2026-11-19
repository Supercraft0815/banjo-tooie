# Fahrplan: vom heutigen Port zu SM64-/SoH-Qualität

Stand 2026-11-16. Dieses Dokument ergänzt `VARIANTE_A_CHECKLISTE.md`: dort stehen die Kästchen
und die Historie, hier stehen Arbeitspakete mit Schritten, Abnahme und Fallen, die ein Agent
ohne Rückfrage abarbeiten kann. Zahlen stammen aus `python3 pc/native/wasm/port.py status`
vom selben Tag.

Kennzeichen wie in der Checkliste: **[Skript]**, **[Agent]**, **[Mensch]**.
Aufwand: S = Tage, M = 1–2 Wochen, L = Wochen, XL = Monate (Agent-Zeit, grob).

## Arbeitsstand am 19. November 2026

Die Zahlen in der Vergleichstabelle und den Arbeitspaketen beschreiben den Ausgangsstand vom
16. November. Die Messergebnisse der einzelnen Änderungen stehen chronologisch in `PROGRESS.md`.

| Paket | Geprüfter Stand | Offene Abnahme |
|---|---|---|
| P0 | Arbeitsstand gesichert, bekanntes Fehlverhalten mit zehn Proben dokumentiert | abgeschlossen |
| Q1 | 14 Bildbögen mit Startpunkt, Pause und Ego-Sicht | Emulatorvergleich und Abzeichnung auf Nutzerwunsch zurückgestellt |
| Q2 | 56 akzeptierte Fälle mit 315.790 Retraces, darunter fünf Bossbegegnungen, 17 Mehrspielerfälle und alle zehn Humba-Verwandlungen | Mumbo, Solo-Spiel, weitere Bosse und Minispiele. Für die 162 unbesuchten Karten ist je ein Grund verzeichnet |
| Q3 | Acht Stunden mit Heapprüfung über 194 Karten, alle 46 Referenzen mit Host-Sanitizern bestanden | abgeschlossen |
| Q4 | Menschlicher 100-%-Durchlauf | auf Nutzerwunsch zurückgestellt |
| Q5 | Zonenbereinigung und drei Modellzugriffe wieder auf Originalcode, 229 Karten geprüft | weitere handportierte Teile |
| A1–A3 | Gast und Host getrennt, SDL3 auf dem Mac, 29 gemeinsame Software-Referenzen auf macOS, Linux und unter Wine | A2 zuletzt 8 ausgelassene Retraces in 75 s bei höchstens einem erlaubten. GPU-Bildvergleich auf Mesa und unter Wine offen |
| A4 | Universal-App, Windows-x64-ZIP und Linux-AppImages privat gebaut und mit echtem Intro gestartet | Pakete bleiben auf Nutzerwunsch lokal. Tag-Lauf, öffentliche Inhaltsfreigabe, macOS-Signatur und Notarisierung sind offen |
| A5–A7 | ImGui-Menü und vier Eingabeplätze, GPU-Zielgrößen und HUD bis 4K geprüft, Interpolations- und Scanout-Tests bestanden | A7-Messung am externen 4K/60-Hz-Display auf Nutzerwunsch zurückgestellt |
| A8 | C-Mixer als Standard, 24 Fälle gegen den Microcode, 83.772.256 identische PCM-Bytes in `new-game` | macOS-Abnahme abgeschlossen |
| A9–A11 | A9 in Erprobung. A11-Absturzberichte auf macOS, Linux und unter Wine geprüft | A9-Mod-Paket und A10-Wunschliste. Die Wunschliste ist auf Nutzerwunsch zurückgestellt |
| N1–N3 | 76 offene Datenmodule, N2 von 163 auf 150 ungültige Aufrufvarianten. N3 hat 1.060 LP64-Warnstellen, 207 verschiebbare Offsets und 45 feste Heapgrößen | Quelllisten, Fremdsymbolzugriffe und Compilerhilfen |
| N4–N6 | Der direkte native Build setzt N1–N3 voraus | Umstellung nach dem Spike, Entscheidung über Little-Endian nach N5 |

---

## 1. Ausgangsstand am 16. November 2026

| Merkmal | SM64-Port / Ship of Harkinian | Banjo-Tooie am 16. November | Paket |
|---|---|---|---|
| Spielcode | direkt für x64/arm64 kompiliert | C → wasm32 → wasm2c → nativ (32-Bit-Sandbox) | N4, N5 |
| Byte-Reihenfolge | Little-Endian, Assets beim Laden konvertiert | Big-Endian-Speicher über den Pass `bt-bigendian` | N6 |
| Compiler-Hilfen | keine | `bt-fixcalls` (Liste leer), `bt-stackslots`, `bt-datagroup`, `bt-safepoints`, `bitfields.py` | N2 |
| Daten | alles in C | 114 `.data`-Module und Rodata noch in asm (`data.py`), 348 Fremdsymbol-Zugriffe | N1 |
| 64-Bit-Tauglichkeit | ja | 1.041 Pointer/int-Mischungen, 208 kritische Offsets, 4.217 abweichende Deklarationen | N3 |
| Grafik | Fast3D (OpenGL, D3D11, Metal) | eigener GPU-Renderer, OpenGL 4.1 nur über CGL (macOS), höchstens 4x | A2, A6 |
| Audio | Mixer in C | RSP-Interpreter mit eingebettetem Microcode aus der ROM | A8 |
| Plattformen | Windows, Linux, macOS | nur macOS arm64, Homebrew-Pfade fest in `build.py` | A1, A3, A4 |
| Menü | ImGui, mit Gamepad bedienbar | F2-Menü, SDL-Software-Zeichner | A5 |
| Eingabe | frei belegbar, Profile, Gyro | Tastatur über `settings.ini`, vier Gamepads, Rumble | A5 |
| 60 FPS | Interpolation | vorhanden; über 60 Hz und krumme Raten offen | A7 |
| Breitbild | HUD am Rand verankert, Ultrawide | spieleigenes 16:9 | A6 |
| Mods | `.o2r`-Archive, Texturpakete | nichts | A9 |
| Abnahme | von vielen Menschen durchgespielt | Intro bis Spiral Mountain, Karten-Sweeps; kein Emulator-Vergleich | Q1–Q4 |
| CI und Releases | drei Plattformen | CI baut nur die N64-ROM | A4 |
| Versionsstand | – | 1.221 geänderte Dateien ohne Commit, letzter Commit 2026-11-09 | P0 |

Zwei Dinge sind getrennt zu betrachten:

- **„So gut wie SoH“** ist, was der Spieler merkt: Plattformen, Menü, Grafikoptionen, Mods,
  Fehlerfreiheit. Das sind die Pakete **A** und **Q**. Sie liegen fast ganz in
  `pc/native/wasm/host/` und überleben jeden späteren Umbau des Spielcodes.
- **„So nativ wie SM64“** ist, wie der Spielcode gebaut wird: ohne wasm2c, 64 Bit, am Ende
  Little-Endian. Das sind die Pakete **N**. Der Spieler merkt davon nichts; es zählt für
  Debugging, Mods im Code und andere Compiler.

---

## 2. Entscheidungen (Empfehlung; der Nutzer bestätigt)

**E1 – Eigene Host-Schicht behalten, libultraship nicht einbinden.** Die Checkliste nennt
libultraship und Torch. Seitdem ist ein eigener GPU-Renderer entstanden, der das Bild-Orakel
besteht (Intro 0,056 % schlechtestes Bild), dazu Interpolation, Fenster, Eingabe, Einstellungen.
Fast3D erwartet Little-Endian-Displaylisten mit Zeigern in Host-Breite, verlangt also N4 und N6
vorher. Empfehlung: SM64-Port-Weg, kleine eigene Schicht aus SDL3, eigenem Renderer und Dear
ImGui. Folge für die Checkliste: Phase 4 („Torch-Factories“) und Phase 8 („Fast3D einbinden“)
werden durch A2, A6 und A9 ersetzt.

**E2 – Reihenfolge: P0, dann A und Q, parallel N1–N3; N4 erst danach.** A bringt dem Spieler
sofort etwas und ist unabhängig von N. N1–N3 sind Listenarbeit, die Agents nebenher erledigen.

**E3 – clang auf allen Plattformen.** Die LLVM-Pässe laufen nur mit clang. Windows baut mit
llvm-mingw oder clang aus MSYS2 (bringt pthreads mit), nicht mit MSVC. MSVC und GCC werden erst
nach N6 möglich.

**E4 – Little-Endian (N6) ist freiwillig und kommt zuletzt.** Es verlangt Konverter für jedes
Asset-Format. Entscheidung nach N5.

---

## 3. Regeln für jedes Paket

Diese Regeln stammen aus Fehlern der letzten Wochen. Wer eine bricht, erzeugt Arbeit für Tage.

1. **Start:** `python3 pc/native/wasm/port.py status`, Zahlen notieren.
2. **Orakel:** nach jeder Änderung `port.py gate`, vor jedem Commit `port.py gate --full`. Bei
   FAIL nennt die Ausgabe Retrace und Feld. Erst die Ursache klären. `--accept` nur nach einer
   gewollten Verhaltensänderung, vorher `build/reference` sichern, danach prüfen, dass jeder Fall
   seine `expected_map` erreicht.
3. **Das Gate vergleicht den Port mit sich selbst.** Es findet keine Fehler, die schon in der
   Referenz stecken (Beispiel: falsche Keyframe-Skala am 13.11.). Für Quelländerungen unter
   `src/` zusätzlich `python3 pc/native/wasm/ir_equiv.py` (Abweichungen müssen in
   `reference-ir/accepted.txt` begründet stehen).
4. **N64-Build bleibt byte-identisch:** nach Änderungen in `src/` oder `include/`
   `python3 pc/native/wasm/syntax_new.py`, dann `offsets.py check` (make check im Docker-Klon
   plus Vergleich je Funktion).
5. **Keine Zeile in einer `src/*.c`-Datei hinzufügen oder entfernen.** as1 plant nach
   Zeilennummern. Nativer Code kommt auf eine bestehende Zeile: `BT_NATIVE_ONLY(...)`,
   `BT_IDO_ONLY(...)`, `BT_PASS2`, `BT_PARAM_OR_VOID` (`include/bt_native.h`).
6. **Nur `s32`/`u32` umtypisieren, nie `int`.** `int` → `long` ändert IDOs Code.
7. **`lib/ultralib` ist ein Submodul und wird nicht angefasst.**
8. **Nie den Spielstand des Nutzers benutzen.** Läufe mit `BT_SAVE=<Kopie im Scratch>`, Programme
   mit absolutem Pfad starten, jeder Lauf in einem frischen Verzeichnis.
9. **Keine Probedateien unter `src/` anlegen, während ein Build läuft** (er nimmt sie mit).
10. **Diagnose-Ausgaben im Gast verändern das Verhalten** (Stack-Reste). Für Vergleiche
    `watch_lldb.py`, `play.py peek` oder `BT_TRACE` benutzen.
11. **Heap-Blockgrößen sind Verhalten.** Jede Änderung in `pc/native/memory.c` ist im Gate sichtbar.
12. **Zwei Ansätze, dann Abbruch:** Befund mit Zahlen nach `PROGRESS.md`, nächstes Paket.
13. **Ein Paket = ein Commit**, Nachricht mit Paketnummer und Zahlen vorher/nachher. Commits nur,
    wenn der Nutzer das für die Sitzung freigegeben hat.
14. **Zwei Agents schreiben nie dieselbe Datei.** Bahnen in Abschnitt 8.

---

## 4. P0 – Stand sichern (S, sofort)

### P0.1 Arbeitsstand committen **[Agent, Freigabe durch den Nutzer]**

1.221 geänderte und 57 neue Dateien liegen nur im Arbeitsverzeichnis.

1. `port.py gate --full` muss PASS melden. Der letzte volle Lauf liegt vor den Änderungen vom
   15./16.11. (freie Kamera, Fenster-Kontext).
2. `python3 pc/native/wasm/offsets.py check` (make check im Docker-Klon).
3. `git status --short | grep '^??'` durchsehen: nichts aus `build/`, keine ROM-Bytes, keine
   EEPROM-Dumps, keine Scratch-Skripte.
4. In Themen committen, jeweils `git add` nach Pfad: (a) `src/` + `include/` (Codemods),
   (b) `pc/native/wasm/*.py` + `fixcalls/`, (c) `pc/native/wasm/host/` + `guest/`,
   (d) `pc/native/*.c` + `include/` + `tests/`, (e) `tools/decomp_harness`, (f) Dokumente.
5. Abnahme: `git status --short` leer bis auf Ignoriertes; `git stash` wird nicht benutzt.
6. Nicht pushen ohne ausdrückliche Anweisung.

### P0.2 Bekannte offene Fehler als Liste **[Agent, S]**

Aus `PROGRESS.md` zusammentragen und je Punkt einen `play.py`-Nachweis versuchen: Lord Woo Fak
Fak (Karte 0xFC, `tr/angler.c` NULL-Licht), das grüne Rechteck nach einem Sprung (2026-11-07),
18 Karten mit stehendem Bild über Ausgang 1, Kickball ohne Banjo, Platzhalternamen
0xCA–0xCE in `maps.h`. Ergebnis: Abschnitt „Bekannte Fehler“ am Ende von `PROGRESS.md`,
je Punkt Karte, Spielstand, Eingabe, Bild.

---

## 5. Bahn Q – Richtigkeit und Abnahme

### Q1 Vergleich mit der echten Hardware bzw. einem Emulator **[Skript + Mensch, M]**

Ohne dieses Paket ist jede Referenz nur „der Port von gestern“.

1. **[Mensch]** ares installieren (kein Emulator auf dem Rechner gefunden).
2. **[Agent]** Bildbogen je Welt erzeugen: `save_editor.py` mit den Welt-Flags (Fall `worlds` in
   `corpus.py`), `play.py start --save <Kopie>`, je Welt `warp`, 10 s warten, `shot` am Startpunkt,
   einmal Pause-Menü, einmal Ego-Sicht. `montage` zu einem Blatt je Welt unter
   `build/acceptance/<welt>.png`.
3. **[Mensch]** denselben Spielstand in ares laden (`bt_eeprom.bin` ist ein rohes `.eep`), dieselben
   Stellen ansehen, Abweichungen als Liste (Karte, was ist anders).
4. **[Agent]** jede Abweichung als Fehler nach P0.2; Ursache zuerst in handportiertem Assembly
   suchen (`hasm`-Einträge in `baserom.us.yaml` gegen `pc/native/*.c`), dann im Renderer.

Abnahme: ein Blatt je Welt, vom Menschen abgezeichnet.

### Q2 Korpus je Welt, Boss, Minispiel, Verwandlung **[Agent, L]**

1. Je Szene ein Fall in `corpus.py`: Spielstand aus `save_editor.py`, Eingabe als `BT_PRESS`,
   `expected_map`, Dauer. Die Eingabe mit `play.py` Schritt für Schritt finden (`run N maske`,
   `shot`), dann als Skript festschreiben.
2. Reihenfolge: zehn Welten (Eingang und ein Innenraum), acht Bosse, Minispiele (Kickball,
   Ego-Schießspiele, Saucer of Peril, Rennen), Verwandlungen (Mumbo, Humba je Welt),
   Solo-Banjo und Solo-Kazooie, Mehrspieler-Menü und eine Partie je Modus.
3. Jeder neue Fall: zweimal laufen lassen (Wiederholbarkeit), Bildbogen ansehen, dann
   `gate --accept` nur für diesen Fall.
4. Danach `python3 pc/native/wasm/xsym_report.py` neu: der größere Korpus zeigt weitere
   Fremdsymbol-Zugriffe (Futter für N1).

Abnahme: `port.py gate --full` läuft alle Fälle; `corpus.py` meldet 0 unbesuchte benannte Karten
oder nennt sie mit Grund.

### Q3 Dauerlauf und Speicherfehler **[Skript, S]**

1. `python3 pc/native/wasm/soak.py` über Nacht mit `BT_HEAPCHECK=1`-Build.
2. Host mit `-fsanitize=address,undefined` bauen (`HOST_FLAGS`, eigener `BT_OUT`), Korpus einmal
   durchlaufen. Die Host-Objekte neu erzeugen: `build.py` baut sie nicht neu, wenn sich nur
   `HOST_FLAGS` ändern (`.o` löschen).

Abnahme: 8 Stunden ohne Absturz, ohne wachsenden Speicher (`ps -o rss` am Anfang und Ende).

### Q4 Durchspielen **[Mensch, L]**

Ein Mensch spielt 100 %. Jeder Fund wird ein Korpus-Fall (Q2), dann behoben. Das Paket endet
nie vor A1–A8, aber es beginnt, sobald P0 und Q1 stehen.

### Q5 Restliche native Ersatzteile **[Agent, M]**

27 `*_native.inc`-Dateien und 423 Wächter `#if defined(BT_NATIVE) && !defined(BT_ILP32)`.

1. Je Datei: läuft unter ILP32 schon das Original? Dann ist der native Zweig nur noch für das alte
   64-Bit-Ziel da und kann mit N4 weg.
2. Wo noch die native Fassung läuft: auf das Original umstellen. Fehlerklassen und Makros stehen in
   `PROGRESS.md`, Abschnitt 2026-11-14 (K&R-Durchreichung, IDO-Stacklayout, gemischte Grenzen).
3. Nach jeder Datei: Build, `sweep.py` über alle Karten (180 s), `unported|trap` als Fehler zählen.

Abnahme: native Logik in `src/` nur noch Plattform (Scheduler, DMA, Bildpuffer, `overlays.c`),
`gc/newoption` und die dokumentierten ABI-Stellen.

---

## 6. Bahn A – Produkt (alles in `pc/native/wasm/host/` und im Build)

### A1 Build von festen Pfaden lösen **[Agent, S]**

`build.py` nennt `/opt/homebrew/...` an sechs Stellen und linkt `-framework OpenGL`.

1. Werkzeuge suchen statt festschreiben: Umgebungsvariable (`BT_LLVM_BIN`, `BT_WABT`, `BT_SDL3`),
   sonst `shutil.which`, sonst die heutigen Homebrew-Pfade. Eine Funktion `tool(name)` oben in
   `build.py`.
2. Link-Zeile (heute Zeile 423) aus einer Tabelle je `sys.platform`: macOS `-framework OpenGL`,
   Linux `-lGL -ldl`, Windows `-lopengl32 -lws2_32`.
3. Den Build in zwei Stufen teilen, die getrennt aufrufbar sind:
   - `build.py guest` endet bei `build/ilp32/gen/*.c` (wasm2c-Ausgabe). Diese Dateien sind
     plattformunabhängiges C.
   - `build.py host` kompiliert `gen/*.c` und `host/*.c` und linkt.
   Grund: `opt` lädt den Pass als Plugin; unter Windows geht das mit den offiziellen LLVM-Paketen
   nach meinem Wissen nicht. Windows baut dann nur die Stufe `host` aus einem `gen/`-Verzeichnis,
   das auf Linux oder macOS entstanden ist. Zuerst prüfen, ob das stimmt; wenn das Plugin unter
   Windows lädt, entfällt die Übergabe.
4. `#embed` in `host/rsp.c` verlangt clang ≥ 19: Version am Anfang prüfen, klare Meldung.

Abnahme: `python3 pc/native/wasm/build.py` auf dem Mac wie bisher; `port.py gate` PASS;
`build.py host` allein aus vorhandenem `gen/` erzeugt ein lauffähiges Programm.

### A2 OpenGL ohne CGL **[Agent, M]** (vor A3)

CGL steht in `rdp_gl.h` (15 Stellen), `video.c` (3), `rdp.h` (1).

1. GL-Lader: glad 2 für OpenGL 4.1 core plus `GL_ARB_texture_barrier` und `GL_NV_texture_barrier`
   erzeugen, als `host/glad/` einchecken (zwei Dateien). Auch auf macOS benutzen, damit es einen
   Weg gibt. Laden mit `gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress)`.
2. Kontexte über SDL: Fensterkontext in `bt_video_window` mit `SDL_GL_CreateContext`. Die
   Renderer-Kontexte (Spielthread, Completion-Thread; heute `rdp_gpu_share`) auf dem Hauptthread
   vor dem Spielstart anlegen, mit `SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1)`, und
   im besitzenden Thread mit `SDL_GL_MakeCurrent` aktivieren. Ohne Fenster (Tests, `BT_VCLOCK`)
   ein Fenster mit `SDL_WINDOW_HIDDEN | SDL_WINDOW_OPENGL`.
3. Barriere im exakten Modus (1x): `glTextureBarrier` wenn 4.5 oder ARB vorhanden, sonst
   `glTextureBarrierNV`, sonst fällt 1x auf den Software-Renderer zurück (Meldung einmal).
4. Alle `#include <OpenGL/...>` durch `glad/gl.h` ersetzen.

Abnahme auf dem Mac, alle drei müssen unverändert sein: `python3 pc/native/wasm/tests/render_test.py`
(mit `gpu_render_test`: 65.536 gleiche Bytes), `frame_compare.py replay` für `intro` (PASS,
schlechtestes Bild 0,056 %), Messung aus `PROGRESS.md` 2026-11-16 wiederholen (höchstens 1
übersprungene Retrace in 75 s).

Fallen: Ein GL-Kontext ist nur in einem Thread aktuell. Kein `glFlush` mitten im Bild (hat die
GPU-Zeit verdoppelt). `build.py` baut Host-Objekte nicht neu, wenn nur Flags sich ändern.

### A3 Linux und Windows **[Agent, M]** (nach A1, A2)

1. Linux zuerst (ein Container genügt): `build.py` ganz, Tests, `port.py gate` mit Software-Renderer
   headless. Der Trace muss mit den macOS-Referenzen übereinstimmen (`--cross-build`); wenn nicht,
   ist die Ursache fast sicher Gleitkomma im Host (`gsp.c`) oder eine libm-Funktion im Gast
   (`guest/libc.c` darf keine Host-libm benutzen, deren Ergebnisse sich je Plattform unterscheiden).
2. POSIX-Stellen im Host kapseln, eine Datei `host/plat.h`: `nanosleep`, `unistd.h`, Signale im
   Fault-Handler, FIFO in `control.c`. `control.c`, `trace.c` und `sips`-Aufrufe sind
   Entwicklerwerkzeuge und dürfen unter Windows fehlen (`#ifndef _WIN32`).
3. Windows mit llvm-mingw (E3): Stufe `host` aus A1. wasm2c-Laufzeit: Guard-Pages über
   `VirtualAlloc` (in `wasm-rt-impl.c` vorhanden); der eigene Schutz der unteren 2 GB braucht ein
   Gegenstück mit `VirtualProtect`.
4. Dateidialog, Nutzerordner und Gamepads laufen schon über SDL3; nur prüfen.
5. GPU-Renderer je Plattform mit `gpu_render_test` und dem Intro-Orakel abnehmen. In CI ohne GPU:
   Mesa llvmpipe.

Abnahme: auf beiden Systemen startet das Spiel aus einer ROM, Intro bis Dateiauswahl mit Ton,
`port.py gate` PASS gegen dieselben Referenzen.

### A4 CI und Releases **[Agent, M]** (nach A3)

1. Neuer Workflow `.github/workflows/pc.yml`, Matrix macOS arm64, macOS x64, Linux x64, Windows
   x64. ROM wie im bestehenden `ci.yml` aus dem privaten Abhängigkeits-Repo.
2. Schritte: `build.py guest` einmal (Linux), `gen/` als Artefakt innerhalb des Laufs,
   `build.py host` je Plattform, ROM-freie Tests überall, `port.py gate` auf Linux.
3. Pakete: macOS `.app` (Universal per `lipo`, SDL3 statisch), Windows `.zip` mit `SDL3.dll`, Linux
   AppImage.
4. **Inhalt prüfen, bevor etwas öffentlich wird [Mensch entscheidet]:** Das Programm enthält den
   kompilierten Spielcode, die `.data` aus der ROM (`data.py`) und das Audio-Microcode
   (`#embed` in `rsp.c`). Ein Skript listet, was davon Bild-, Ton- oder Textdaten sind
   (`data_inventory.py` erweitern: Labels über 1 KiB mit Textur- oder Displaylisten-Typ).
   Das Microcode fällt mit A8 weg. `gen/`-Artefakte nie öffentlich ablegen.
5. Signieren und Notarisieren auf macOS braucht das Entwicklerkonto des Nutzers: **[Mensch]**.

Abnahme: ein Tag erzeugt drei Pakete, jedes startet auf einem sauberen System mit einer ROM.

### A5 Menü und Eingabe mit Dear ImGui **[Agent, M]** (nach A2)

1. Dear ImGui als Quellkopie nach `pc/native/third_party/imgui` mit den Backends
   `imgui_impl_sdl3` und `imgui_impl_opengl3`. ImGui ist C++: eine einzige Datei
   `host/menu.cpp` mit `extern "C"`-Funktionen `bt_menu_event`, `bt_menu_draw`; der Rest bleibt C.
2. `settings.c` behält Tabelle, `settings.ini` und `bt_setting()`/`bt_setting_set()`. Nur
   `bt_settings_draw` und `bt_settings_event` gehen an `menu.cpp`. So bleibt jeder Aufrufer gleich.
3. Menüs: Grafik (Renderer, Auflösung, Breitbild, Filter, Interpolation, Textglättung, VSync),
   Audio (Lautstärke, Latenz), Steuerung, Verbesserungen (A10), Debug (FPS, Karten-Warp über den
   vorhandenen `BT_WARP`-Weg, Render-Statistik).
4. Steuerung: je Port eine Belegung, Taste oder Gamepad-Knopf pro N64-Knopf durch „drücken zum
   Belegen“, Totzone und Empfindlichkeit des Sticks, Speicherung in den vorhandenen
   `key.X=`-Zeilen plus neuen `pad<N>.X=`-Zeilen (`bt_input_bind`).
5. Bedienung mit dem Gamepad (`ImGuiConfigFlags_NavEnableGamepad`); das Spiel bekommt keine
   Eingaben, solange das Menü offen ist (heute `bt_menu_open`).
6. Gyro für die Ego-Sicht über `SDL_SetGamepadSensorEnabled`: erst nach Rückfrage, eigener Punkt.

Abnahme: `tests/keyboard.c` grün; jede Einstellung im Menü ändert denselben Wert wie vorher die
`settings.ini`-Zeile; Menü vollständig mit Gamepad bedienbar; Fensterfoto je Menüseite.
Unter `BT_HEADLESS` wird ImGui nicht initialisiert (Traces dürfen nicht davon abhängen).

### A6 Auflösung, Kantenglättung, Breitbild **[Agent, M]** (nach A2)

1. `RDP_MAX_SCALE 4` (`rdp.h`) gilt für statische Puffer in `video.c` und `rdp.c`. Für den
   GPU-Renderer die Zielgröße aus der Fensterhöhe ableiten (Faktor als Bruch, Ziele dynamisch
   anlegen); der Software-Renderer bleibt bei 1x–4x.
2. MSAA 2x/4x/8x als Multisample-Ziel, Auflösen beim `gpu_publish`. Bei 1x (exakter Modus) aus.
   Abnahme über das Orakel mit Toleranz: Kanten dürfen abweichen, Flächen nicht.
3. Breitbild prüfen, bevor etwas gebaut wird: `play.py`-Bild in 16:9 mit HUD. Ist das HUD
   gestreckt, dann 2D-Zeichnungen (Texrects und Dreiecke unter orthografischer Projektion) im
   4:3-Maß lassen und nach x-Lage verankern: linkes Drittel an den linken Rand, rechtes an den
   rechten, Mitte mittig. Ausnahmen (Vollbild-Überblendungen, Pause-Hintergrund) erkennt man an
   voller Breite; die werden gestreckt.
4. Ultrawide (21:9) nur, wenn 3. funktioniert: Projektion in `src/core2/1EBCFC0.c:func_800E44FC`
   unter `BT_NATIVE` um das Seitenverhältnis erweitern, Culling der Karten-Sektionen mitziehen.
5. Offene Renderer-Lücken aus `PROGRESS.md` 2026-11-14 abarbeiten, je Punkt ein Bildvergleich:
   Spielerschatten (CI8-Bild) bei 4x blockig, Pause-Hintergrund in N64-Auflösung, Nähte bei
   Texrect-Streifen, Rauschen, Tiefen-Import von CPU-Schreibzugriffen.
6. Jede Stelle, an der das Spiel Bildpuffer liest oder schreibt, einzeln im Bild abnehmen
   (Checkliste Phase 8): Pause-Bild, Übergänge, `gczoombox`, Foto-Effekte, Z-Lesen.

Abnahme: 1440p und 4K im Fenster und im Vollbild, HUD unverzerrt, `frame_compare.py replay` bei 1x
unverändert PASS.

### A7 Bildtakt und Leistung **[Agent, M]** (nach A2)

1. Messen, was fehlt: externes 4K-Display mit 60 Hz, Vollbild, `BT_RENDER_STATS=1`
   (`presents repeated`, `retraces skipped`).
2. Resolves je Task (Farbe und Tiefe ins RDRAM) nur noch, wenn jemand liest. Die Leser sind
   bekannt (`PROGRESS.md` 2026-11-14: Texturladen aus einem Bildpuffer, `func_8001A0C0`,
   Sichtproben in `core2/1EC1AD0.c`, Pausen-Kopie `func_800C0BC0`, Bildschirmfotos). Erst zählen,
   wie oft je Sekunde jeder Leser vorkommt, dann entscheiden.
3. Shader je Combiner-Konfiguration spezialisieren (Programm-Cache nach Othermode- und
   Combiner-Schlüssel), asynchron übersetzen, bis dahin der allgemeine Shader.
4. Anzeigeraten, die kein Vielfaches von 59,94 Hz sind (75, 144, 165 Hz, VRR): Zwischenbilder für
   beliebiges t statt höchstens drei feste; die Zuordnung der Matrizen existiert (`gsp.c`).
5. Auf den Fence der Bildkopie warten, bevor das Fenster sie zeigt (Kommentar bei `gpu_publish`).

Abnahme: 4K, Interpolation an, Spiral Mountain und eine volle Welt (Witchyworld), 5 Minuten: keine
übersprungene Retrace nach der ersten Sekunde auf dem Rechner des Nutzers. Gate unverändert.

### A8 Audio-Mixer in C **[Agent, M]**

Das Spiel benutzt 15 Befehle: `aSegment`, `aClearBuffer`, `aSetBuffer`, `aLoadBuffer`,
`aSaveBuffer`, `aDMEMMove`, `aMix`, `aInterleave`, `aSetVolume`, `aEnvMixer`, `aResample`,
`aADPCMdec`, `aLoadADPCM`, `aSetLoop`, `aPoleFilter` (Erzeuger: `src/core1/1E43D60.c` und
`lib/ultralib/src/audio/`). Der RSP-Interpreter ist das Orakel.

1. `host/mixer.c` mit `bt_mixer_audio(u32 task)`: Befehlsliste lesen, 4 KiB DMEM nachbilden.
   Die Opcode-Nummern aus der Sprungtabelle des Microcodes und aus den `aXxx`-Makros der
   Spiel-Header nehmen, nicht aus dem Standard-`abi.h` raten (n_audio weicht ab).
2. Vergleichsmodus `BT_AUDIO_CHECK=1`: jede Task läuft durch beide; verglichen werden der DMEM
   nach der Task und jeder `aSaveBuffer`-Bereich im RDRAM. Erste Abweichung mit Befehlsnummer und
   Offset ausgeben, Abbruch.
3. Reihenfolge der Befehle: Puffer und Kopien, `aMix`, `aInterleave`, `aADPCMdec`, `aResample`,
   `aEnvMixer`, zuletzt `aPoleFilter` (sein IIR-Modus fehlt in bekannten HLEs und muss aus dem
   Microcode abgeleitet werden: die Disassemblierung von `assets/core1/n_aspMain.textbin.bin`
   lesen, der Interpreter zeigt Zwischenwerte).
4. Rundung und Sättigung genau wie die Vektoreinheit (48-Bit-Akkumulator, `VMULF`-Rundung,
   Clamp auf s16). Vorlage für den Aufbau ist `mixer.c` des SM64-Ports; Code nicht übernehmen,
   sondern gegen das Orakel schreiben.
5. Befehl 7 (MP3-Überlagerung) wird nicht unterstützt. Zuerst über den ganzen Korpus zählen, ob er
   vorkommt (Q2); nur dann portieren.
6. Wenn alle Fälle bitgleich sind: Mixer wird Standard, `BT_AUDIO=rsp` bleibt als Debug-Option im
   Entwickler-Build. Im Release-Build fällt `rsp.c` mit dem `#embed` weg.
7. Latenz einstellbar: `LATENCY_BYTES` in `ai.c` als Einstellung (A5).

Abnahme: `BT_AUDIO_CHECK=1` über `gate --full` ohne Abweichung; `BT_PCM`-Datei von `new-game` mit
Mixer und mit Interpreter byte-gleich.

### A9 Mods: Texturpakete und Asset-Ersatz **[Agent, M]** (nach A2)

1. **Texturen.** Der Atlas-Cache hat schon einen Schlüssel je Kachel (TMEM-Inhalt, Deskriptor,
   TLUT). Daraus ein stabiler 64-Bit-Hash über die dekodierten Texel plus Format und Größe.
   - `BT_TEX_DUMP=ordner` schreibt jede neue Kachel als `<hash>_<b>x<h>.png`.
   - Beim Start `mods/<paket>/textures/*.png` indizieren; trifft ein Hash, kommt das Ersatzbild in
     eine eigene Textur in voller Auflösung statt in den Atlas. Der Shader tastet es über normierte
     Koordinaten ab. PNG lesen mit `stb_image.h` (eine Datei, `third_party/`).
   - Nur GPU-Renderer, nur ab 2x; 1x bleibt exakt.
   - Kompatibilität mit vorhandenen Emulator-Paketen (Rice-CRC im Dateinamen) ist ein eigener
     Schritt danach: CRC beim Laden über die Quellbytes im RDRAM berechnen, zweiter Index.
2. **Assets.** Alle Asset-Zugriffe laufen über die ID (`native_asset_load`,
   `native_asset_read_into` in `pc/native/assets.c`). Vor dem Lesen aus der ROM
   `mods/<paket>/assets/<id hex>.bin` prüfen (unkomprimiert, Größe an den Aufrufer melden).
   `BT_ASSET_DUMP=ordner` schreibt jedes geladene Asset einmal.
3. Reihenfolge der Pakete im Menü (A5), Standard: keine.

Abnahme: ein Testpaket ersetzt eine HUD-Textur und ein Modell-Asset; Fensterfoto vorher/nachher;
ohne `mods/` ist `gate --full` unverändert PASS.

### A10 Verbesserungen und Cheats **[Agent, S je Punkt; Liste vom Nutzer]**

Muster wie die freie Kamera (`PROGRESS.md` 2026-11-15): Einstellung in `settings.c`, Host-Import,
im Spiel eine Zeile unter `BT_NATIVE_ONLY`, aus = unverändertes Spiel. Kandidaten: schnellerer
Text, Intro und Logos überspringen (im Spiel vorhanden, nur als Option anbieten), Cheats des
Spiels als Schalter (die Flags der Code-Kammer setzen), Karten-Warp, unendlich Eier/Luft/Leben
für Tests. Jeder Punkt: Gate mit Option aus PASS, mit Option an ein `play.py`-Nachweis.

### A11 Absturzbericht **[Agent, S]**

Der Fault-Handler gibt heute den PC auf stderr aus. Für Releases: Datei `crash.txt` im
Nutzerordner (Version, Karte, Gast-Rücksprungkette über `game.map`-Auszug, letzte 200 Zeilen
Log) und `SDL_ShowSimpleMessageBox` mit dem Pfad.

---

## 7. Bahn N – nativer Spielcode

Alle Pakete N1–N3 arbeiten am heutigen ILP32-Build, der dabei spielbar bleibt. Erst N4 baut
anders.

### N1 Alle Daten in C **[Skript, dann Agent je Modul, L]**

Ziel: der native Build braucht `data.py` nicht mehr.

1. `python3 pc/native/wasm/port.py worklist data` (114 Module). Je Modul nennt die Liste den
   Grund. Häufige Gründe und ihr Rezept:
   - Label beginnt mitten in einem Array-Element → beide Labels zu einem C-Objekt, Zugriffe auf
     Felder umschreiben.
   - Skalar-Label vor einem größeren Objekt → Struct anlegen, zeilenneutral.
   - `u32`-Felder, die Funktionszeiger halten → `BtFnWord`.
   - Byte-Blob mit Zeigerarithmetik (`D - 8`, `== D`) → Array mit Index.
   - Block-lokale Typen → auf Dateiebene heben, an die Leerzeile vor der Funktion gehängt.
   - C-Datei mit eigenem `.data` (as1-Hebeltabellen wie `D_lever`) → bleibt bis zuletzt; die Tabelle
     kommt zuerst, die angehängten Daten dahinter müssen im yaml als eigener Abschnitt stehen.
2. Je Modul: ändern, `data_to_c.py apply`, `data_to_c.py verify` (Docker-Klon, `.data` und
   Relocations je Objekt), `port.py gate`. Wörter, die zufällig wie Adressen aussehen, gehören in
   `stub_constants.txt` (`data_to_c.py constants`).
3. `port.py worklist xsym` (348 Zugriffe, 86 Dateien, Gruppen in
   `build/ilp32-xsym/xsym_groups.tsv`): je Gruppe erst die Daten als ein C-Objekt, dann die
   Zugriffe. Nach Q2 den Bericht neu erzeugen.
4. Rodata-Branch `claude/awesome-lovelace-b12e6f`: 41 Pfade fügen sich sauber, 11 Konflikte,
   6 neue Dateisplits (Vorschau in `build/ilp32/phase01-validation/rodata-preview/`). Je
   Konfliktdatei die heutigen Funktionskörper behalten und nur die Rodata-Aufteilung übernehmen;
   danach `make check`.
5. Schalter `BT_NO_ASMDATA=1` in `build.py` (neu): `data.py` liefert nur noch `hasm`-Daten; der
   Build bricht bei jedem Label ab, das noch aus asm käme. Die Fehlerliste ist die Restliste.

Abnahme: `port.py status` zeigt `data 0`, `xsym 0`; `BT_NO_ASMDATA=1`-Build besteht
`gate --full`; `make check` OK.

### N2 Ohne Compiler-Hilfen **[Skript, dann Agent, M]**

Jede Hilfe bekommt einen Ausschalter und wird einzeln abgebaut. Passkette heute (`build.py`
Zeile 366): `mem2reg, bt-fixcalls, bt-bigendian, bt-datagroup, bt-stackslots, internalize,
bt-safepoints, default<O2>, bt-fixcalls`.

1. **[Skript]** `BT_PASS_OFF=name[,name]` in `build.py` (neu) lässt Pässe weg; zusammen mit
   `BT_OUT=build/ilp32-<name>` entsteht ein eigener Baum.
2. `bt-fixcalls`: `widened.txt` ist leer. Build ohne den Pass; was wasm-ld als
   Signaturkonflikt meldet oder im Sweep abstürzt, ist die Restliste. Dazu
   `port.py worklist protos` (4.217; Reihenfolge float 421, arity 362, ret, size). Wo IDO mit der
   echten Signatur anderen Code erzeugt (`protos_ido_keep.txt`), bleibt die alte Deklaration unter
   `BT_IDO_ONLY` und die richtige unter `BT_NATIVE_ONLY` auf derselben Zeile.
3. `bt-stackslots`: den Pass seine Fundstellen ausgeben lassen (wie `widened.txt`), je Stelle die
   Locals nativ zu einem Array machen (Muster: `su/spline.c`, `f32 points[4][3]`). Dazu der
   Fall, den der Pass nicht sieht (Callee liest Nachbar-Locals): Scan nach Gruppen gleichartiger
   lokaler Arrays, von denen nur eines weitergegeben wird.
4. `bitfields.py`: Codemod, der in jeder Struct-Definition mit Bitfeldern die gespiegelte
   Reihenfolge unter `#ifdef BT_NATIVE` daneben schreibt (in Headern dürfen Zeilen dazukommen; bei
   Structs in `.c`-Dateien auf dieselbe Zeile). Prüfung: IR des Builds mit Codemod gleich dem IR
   mit `bitfields.py` (`ir_equiv.py`).
5. `bt-datagroup`: fällt weg, sobald `xsym 0` (N1).
6. `bt-safepoints`: Die virtuelle Uhr erkennt Warteschleifen schon (100.000 Latches ohne
   OS-Aufruf). Diese Stellen mit Funktionsnamen protokollieren, über den ganzen Korpus sammeln, an
   jeder ein `BT_NATIVE_ONLY(bt_yield();)` einsetzen (Beispiel `func_800C2AB8`), dann den Pass
   abschalten und den Korpus mit echter Uhr laufen lassen (Hänger = fehlende Stelle).
7. Zum Schluss `-Wall` mit den Warnungen, die echte Fehler zeigen
   (`-Wreturn-type -Wimplicit-function-declaration -Wincompatible-pointer-types -Wuninitialized`)
   als Fehler im nativen Build.

Abnahme: `BT_PASS_OFF=fixcalls,stackslots,datagroup,safepoints` und ohne `bitfields.py`:
`gate --full` PASS, Sweep über alle Karten 0 Abstürze, `make check` OK. Übrig bleibt allein
`bt-bigendian`.

### N3 64-Bit-saubere Quellen **[Skript, dann Agent je Datei, L]**

1. `port.py worklist lp64` (1.041 in 261 Dateien; Gründe in `build/lp64_words_left.tsv`).
   Erst `lp64_words.py` erneut bis zum Stillstand, dann je Datei von Hand: Felder echter Structs,
   Globals, Array-Elemente, `*(s32 *)(p + 0x3C)`.
2. `port.py worklist offsets64` (208 in 37 Dateien), dann `offsets` (4.774): `offsets.py scan`,
   `genstruct`, `apply`, `verify`. Vorher das nächste Skript aus der Checkliste bauen: Structs am
   Ende verlängern, Pointer-Felder auf den gelesenen Typ setzen (915 Stellen).
3. Erzeugte `Obj…`-Structs zusammenführen: gleiche Layouts in mehreren Dateien werden ein
   Header-Struct (Skript: Layouts hashen, Kandidaten listen; Agent benennt).
4. Größen: 49 `heap_alloc(0x…)` und feste Schrittweiten auf `sizeof`, sobald das Struct vollständig
   ist. Unter IDO muss derselbe Wert herauskommen (`offsets.py check`).
5. Layout-Zusicherungen für die großen Structs (Actor, Marker, Player): im N64-Zweig
   `typedef char bt_assert_<name>[(sizeof(T) == 0x…) ? 1 : -1];` in den Headern.
6. Abnahme laufend: `python3 pc/native/wasm/hazards64.py` (3 s) muss fallen; nach jedem Block
   `gate` und `offsets.py check`.

Abnahme: `lp64 0`, `offsets64 0`, `hazards64.py` meldet 0 in Spieldateien.

### N4 Erster Build ohne wasm2c **[Agent, XL; beginnt mit einem Spike]**

Voraussetzung: N1, N2 (bis auf `bt-bigendian`), N3.

**Entwurf (im Spike zu bestätigen):** Der Spielcode wird mit derselben Passkette direkt für
arm64/x64 übersetzt; der Speicher bleibt Big-Endian. Zeiger sind 64 Bit. Überall, wo das Spiel
Zeiger in 32-Bit-Felder schreibt (Displaylisten-Wörter, Vertex- und Matrixadressen, `OSTask`,
Felder in Asset-Daten), steht stattdessen der 32-Bit-Abstand zu einer Basis `bt_base`. Das geht,
wenn der gesamte Spielspeicher in einem Bereich unter 4 GB liegt: statische Daten des Programms,
die Heap-Arena als statisches Array, Thread-Stacks als statische Arrays
(`pthread_attr_setstack`, mindestens 1 MB). Die Host-Schicht rechnet weiter mit 32-Bit-Adressen
(`G(addr)` = `bt_base + addr`) und bleibt fast unverändert. Der andere Weg (SoH: Displaylisten mit
Zeigerbreite, Assets beim Laden umbauen) verlangt Konverter für jedes Format vor dem ersten
Bild und ist deshalb nicht der Einstieg.

1. **Spike (M):** Nur Boot bis zum ersten Intro-Bild. `build.py --target=native` (neu): gleiche
   Quellen, `--target=<host>`, Pässe, `llc`, Link mit `host/`. Makros `BT_P32(p)` (Zeiger → Abstand)
   und `BT_PTR(T, off)` in `bt_native.h`. Ergebnis ist eine Liste der Stellen, an denen es
   bricht, und eine Aussage, ob der Entwurf trägt. Wenn nicht: Abbruch mit Befund, nicht weiterbauen.
2. **[Skript]** Stellen finden, die Zeiger in 32-Bit-Speicher legen: im nativen Build ein Pass, der
   jede 8-Byte-Zeigerspeicherung in einen Asset-Puffer oder Displaylisten-Puffer meldet
   (Bereichsprüfung wie `bt-xsym`). Die Liste ist die Arbeitsliste für `BT_P32`.
3. Indirekte Aufrufe mit falscher Signatur: Build mit `-fsanitize=function`, Korpus laufen lassen,
   Fundstellen beheben.
4. Heap: `pc/native/memory.c` mit Host-Größen für Köpfe; die Defragmentierung verschiebt Blöcke,
   jede Zeigerreparatur prüfen (`BT_HEAPCHECK`).
5. Overlays sind schon statisch gelinkt (`src/core2/overlays.c`, nativer Zweig). Prüfen: `.data`
   und `.bss` eines Overlays werden beim erneuten Laden zurückgesetzt (Test: Karte betreten,
   verlassen, wieder betreten, Overlay-Variablen per `peek`). Fehlt das: Schnappschuss beim Start,
   Kopie beim Laden.
6. Kopierschutz-Stellen (IPL3-Wörter in Thread-Rahmen, XOR mit Codebytes von `func_800D1A04`)
   hängen am N64-Stacklayout: unter `BT_NATIVE` die erwarteten Werte direkt liefern.
7. Vergleich mit dem wasm2c-Build: `trace_tools.py --cross-build`. Die virtuelle Uhr zählt
   Schleifen-Latches und kann zwischen beiden Builds abweichen; dann je Spielbild statt je Retrace
   vergleichen (Kartenfolge, Spielerposition, Flags an Bildwechseln).
8. ASan und UBSan laufen jetzt auf dem Spielcode selbst: Korpus einmal mit beiden.

Abnahme: nativer Build spielt den ganzen Korpus, Bildvergleich gegen den wasm2c-Build im Rahmen
des Orakels, 8-Stunden-Dauerlauf unter ASan sauber.

### N5 Umstellen und aufräumen **[Agent, M; Löschen nur mit Freigabe]**

1. Nativer Build wird Standard in `build.py`, CI (A4) baut ihn; der wasm2c-Weg bleibt ein
   Vierteljahr als Referenz.
2. Danach entfernen: der alte 64-Bit-Versuch (`pc/native/link_game.py`, `platform/ultra_*.c`,
   `CMakeLists.txt`), der Recomp-Prototyp (`pc/RecompiledFuncs`, `pc/build-cmake`, `pc/patches`,
   `pc/runtime-patches`), `*_native.inc`, die LP64-only-Zweige. Vor jedem Löschen prüfen, dass
   nichts im Build darauf zeigt; Liste dem Nutzer vorlegen.

### N6 Little-Endian **[freiwillig, XL; Entscheidung E4]**

Erst ab hier gehen MSVC und GCC, und erst hier sind Assets native Structs.

1. **[Skript]** Pass `bt-ealias` im Big-Endian-Build: merkt je Byte, mit welcher Breite es zuletzt
   geschrieben wurde und ob es aus der ROM kam (PI-Lesen, `native_asset_load`); meldet jedes Laden
   mit anderer Breite oder anderem Versatz und jedes Laden breiter als ein Byte aus ROM-Bytes.
   Die erste Gruppe ist Byte/Wort-Aliasing im Code, die zweite ist die vollständige Liste der
   Stellen, die Asset-Formate lesen.
2. Aus der zweiten Liste den Katalog der Asset-Typen (Checkliste Phase 4), je Typ ein Konverter
   beim Laden mit Test gegen echte ROM-Daten. Vorhandene Module (`model.c`, `geometry_data.c`,
   `animation_resource.c`, `textures.c`) sind der Ausgangspunkt.
3. Displaylisten aus Assets beim Laden in Host-Reihenfolge; `gsp.c` liest dann nativ.
4. EEPROM beim Laden und Speichern konvertieren, damit `.eep`-Dateien echter Konsolen passen.
5. `bt-bigendian` aus, Gate über den ganzen Korpus.

---

## 8. Reihenfolge und Bahnen

Zwei Agents arbeiten nie in derselben Bahn zugleich, außer die Pakete nennen verschiedene Dateien.

| Bahn | Dateien | Pakete in Reihenfolge |
|---|---|---|
| H (Host) | `pc/native/wasm/host/`, `third_party/` | A2 → A5, A6, A7 (nacheinander: alle fassen `video.c`/`rdp_gl.h` an) → A9 |
| U (Audio) | `host/mixer.c`, `ai.c`, `rsp.c` | A8 (parallel zu H) |
| B (Build) | `build.py`, `.github/` | A1 → A3 → A4 |
| S (Quellen) | `src/`, `include/`, Codemod-Skripte | Q5 → N1 → N2 → N3 (eine Datei je Agent, Validierung in der Bahn wie bei `decomp-agent port-calls`) |
| K (Korpus) | `corpus.py`, `build/acceptance/` | P0.2 → Q1 → Q2 → Q3 |
| Mensch | – | E1–E4, Q1 Schritt 1 und 3, Q4, A4 Schritt 4 und 5, A10 Liste |

Meilensteine:

1. **M-A „öffentlich zeigbar“:** P0, A1–A5, Q1, Q3. Drei Plattformen, Menü, geprüfte Bilder.
2. **M-B „SoH-Komfort“:** A6–A11, Q2, Q4 begonnen.
3. **M-C „nativ“:** N1–N5.
4. **M-D „wie SM64“:** N6.

Für die mechanischen Listen (N1 Schritt 1–3, N2 Schritt 2, N3) lohnt der vorhandene Harness
(`decomp-agent port-calls`-Muster: ein Worker je Datei, die Bahn validiert seriell mit Build,
`make check`, Gate und `ir_equiv.py`). Für H, U, B ein Agent je Paket.

---

## 9. Nicht geprüft beim Schreiben dieses Fahrplans

- Ob `opt` unter Windows Pass-Plugins lädt (A1 Schritt 3).
- Ob das HUD im 16:9-Modus gestreckt ist (A6 Schritt 3).
- Ob der Entwurf mit 32-Bit-Abständen (N4) trägt; deshalb beginnt N4 mit dem Spike.
- Ob Befehl 7 des Audio-Microcodes im Spiel je vorkommt (A8 Schritt 5).
- Was genau an Bild- und Tondaten in `.data` und damit im Programm liegt (A4 Schritt 4).
- `port.py gate --full` ist seit den Änderungen vom 15./16.11. nicht gelaufen (P0.1 Schritt 1).
