# Native C source port

The current playable port and its build instructions are in
[`wasm/README.md`](wasm/README.md). The notes below describe the earlier direct-host
prototype and its isolated core tests; they are retained for the N4/N5 migration.

## Earlier direct-host prototype

The default PC build compiles selected files from `src/` directly with the host
C compiler. It does not consume a MIPS ELF, invoke N64Recomp, or use
`RecompiledFuncs`. No ROM is needed for the core tests.

**This is the start of the source port, not a playable game.** The runnable target
is explicitly named `bt_native_core_test`. It exercises the actual decompiled
memory, vector, freelist and player-flag implementations with a native heap.
There is no game executable until the remaining dependencies are implemented.

The build also generates native aliases for all 4,232 manifest entrypoints. The
original `_entrypoint` syscall names resolve to ordinary C functions. A separate
link test checks pointer and floating-point arguments and callbacks across
translation units. `bt_native_level_test` exercises the real level-query overlay
with controlled flag/table data: the level ID is now explicitly forwarded in C,
rather than relying on the original MIPS argument register remaining intact.

`native_input.h` is the frontend boundary for controller samples. It accepts
libultra button masks and calibrated, normalized stick coordinates for four
controller slots. The original C button-history and player-key implementations
consume these samples directly. `bt_native_input_test` checks button mapping,
independent slots, press/release transitions, hold duration, stick values and
invalid samples. Real device polling, calibration and the game's full input
permission/state pipeline are still to be integrated; this is not an SDL frontend.

The scripted-player-state dispatcher (`src/overlays/bs/drone.c`) now forwards
the player pointer explicitly. Its native table uses host function pointers
instead of overlapping views at fixed 20-byte strides. `bt_native_drone_test`
checks all 15 state IDs, fallback behavior, pending-state activation, two players
and all four callback slots against expectations extracted from the original
assembly data. The test supplies controlled callback functions;
the state activation and getters now come from the real `badrone` component.
The state callbacks still require porting before this subsystem can run in the
game. Production table entries refer to the real game symbols, never the test
fixtures.

The `badrone` component uses a typed player field and a host-sized `BaDrone`
allocation, including full-width callback, callback-context and marker values.
All 35 component functions retain identical Original-IDO machine code. Native
tests exercise state activation/reset, state-selection returns, destination and
look-at vectors, horizontal travel duration, flags and callback pointer round
trips. Vector operations and player flags use the original C implementations;
external physics/state selectors are controlled test dependencies. The player
API wrappers now explicitly forward the previously implicit vector/flag arguments.
The remaining callback registrations, their callees and other modules that still
access the player/drone by numeric offsets are not yet integrated.

The two bubble states (`bs/drone/bubbled.c`, types 12 and 13) are compiled into
the native core with all nine functions. Their callback declarations are shared
with the native dispatch table. `bt_native_bubbled_test` exercises marker cleanup,
event routing, state changes, the clamped struggle value and animation-duration
updates across frame deltas. Timer decay, minimum and interpolation execute the
original scalar-math C; actor-message, animation, event and clock dependencies
are test observations until those subsystems are ported. The actor-message API
accepts a native marker pointer under `BT_NATIVE`; the IDO path retains its
original integer declaration to preserve register allocation in existing callers.

The animation controller (`core2/anctrl.c`, 43 functions) also compiles directly.
Its native flag accesses use byte masks, and the trailing animation payload is
aligned for host pointers instead of assuming a 28-byte header. Callback contexts
and returned poses have pointer-sized interfaces. The controller test checks
clock selection, flag independence, forward/reverse playback, wrapping, subrange
loops, stopping, start positions, smoothing and pointer round trips. The bubble
test now calls the actual `anctrl_setDuration`. The isolated controller test uses
a controlled backend; the separate pipeline test below links the real backend
and bone storage. The higher-level game asset cache is also compiled natively;
rendering remains pending.
The N64 controller keeps identical IDO machine code.

Bone-pose storage (`core2/1EB93C0.c`, 18 functions) now uses host-sized pointers
and allocations for its 109 transforms. Both ordinary allocations and the game's
allocation handles execute against the native heap. The bone-pose test checks
the first/last entries, identity initialization, copy, pointer repair after a
move, handle reuse and in-place blending. Quaternion interpolation executes the
original `1EB2EF0.c` implementation; the assembly Euler conversion, sine and
arccosine helpers have native C equivalents. These use host `libm`, so they are
not bit-identical to the original N64 lookup-table approximations. The shared
bone-storage functions retain identical IDO machine code. Actor callbacks and
model rendering still require porting before these poses can animate game models.

The animation backend (`core2/1E64F00.c`, 43 functions) now compiles directly and
links to the controller and bone storage. Host callback/context fields and the
pose-cache bounds use full-width pointers. Fixed offsets follow the host layout;
N64 cache operations retain their original overlapping linker-symbol views.
Previously implicit MIPS arguments and return values are explicit C data flow.
`bt_native_animation_test` exercises cache growth, eviction, zero-handle release,
slot reuse, both pose modes, controller-driven blends, hard switches and callback
context round trips using the real controller, backend, heap and pose functions.
Resource lookup, clocks and renderer calls remain controlled test boundaries.
Sampling now uses the real resource decoder below instead of a fixture function.
The backend preserves all 43 Original-IDO functions.

Animation resource processing (`core2/1EB9940.c`, 10 functions) compiles directly
and retains identical IDO code. `native_animation_decode` validates bounded
big-endian resource bytes and converts their 16-bit words to host order. It checks
channel/key counts, bone indices and key ordering, including repeated timestamps
present in shipped resources. Native C equivalents of the two assembly helpers
implement linear/cubic interpolation, loop boundaries, wrapped angles and writing
bone transforms. Tests cover malformed/truncated input, sampling branches, pose
queries and the controller/backend pipeline with encoded sample resources.

The optional archive check below has processed all 1,231 original animation
resources at nine times in both loop modes with sanitizers, checking finite pose
values and unit quaternions. This verifies decoding and sampling coverage; it does
not compare every result against N64 execution or prove visual/gameplay correctness.
Model/rendering consumers remain to be integrated.

The lower-level asset manager (`core2/1EAED30.c`, 28 functions) now compiles
directly with native pointer arrays and host-sized delayed-release records. Its
130-slot reference cache and two-frame release lists execute the game C code.
`native_assets_open` reads a bounded extracted `assets.bin` archive; ordinary
reads are synchronous and raw DEFLATE streams use zlib with their declared output
limit. Animation assets are validated and converted before entering this cache.
Other supported archive entries remain raw bytes until their consumers are ported.
Encrypted game databases (type 10) now pass through the original `gl/dbDll.c`
key construction and XOR loop, with a pure C CIC-6105 response in place of the
hardware exchange. The native loader decrypts before bounded decompression.
The response algorithm is shared with the legacy prototype, but the native build
does not link its recompiler runtime. Database contents remain serialized bytes;
their consumers and preload entrypoints need integration.

Tests cover cache capacity, repeated acquisition, reference-count overflow,
delayed releases including vector growth, shutdown, malformed compression, output
limits and caller buffer capacity. All 1,231 original animation assets have also
been loaded, sampled and released through this manager with sanitizers. All 28
manager functions retain identical Original-IDO code.

Database checks cover three known keys, XOR boundaries, synthetic encrypted
streams, zeroed allocation padding and caller-buffer limits. All 235 encrypted
databases from the original archive also decode through the native loader and
reference cache under sanitizers. This is loading coverage, not a verification
of their game consumers. All five `gl/dbDll.c` functions retain identical IDO
machine code, and both rebuilt ROM forms remain byte-identical to the originals.

The higher-level cache in `core2/1EAF950.c` now uses host-sized entries while
preserving the original sorted lookup, usage tracking, pin counts and eviction
code. Missing forwarded arguments/returns are explicit C values. The lower-level
manager retains allocation sizes so reloads use the decompressed buffer capacity.
Model auxiliary animation channels are bounds-checked and endian-converted before
the actual `core2/1EB52C0.c` registry receives them. Model headers, vertices and collision records
are decoded at archive load as described below; the remaining rendering sections
still require their own decoders.

The cache test runs the real animation controller through cache lookup, archive
I/O, decompression, animation decoding and bone sampling. It also covers sorted
insertion/removal, capacity, pinning, reloads, frame-based deferred releases,
eviction and malformed model offsets. With the original archive it loads and
releases all 1,145 models, 1,231 animations and 235 databases under sanitizers.
The actor movement and event-execution functions in `1EAF950.c` still require
integration; compiling that translation unit does not validate those functions.
All 54 functions in its N64 object retain identical IDO instructions.
Game initialization/shutdown must still coordinate the higher-level cache with
archive lifetime; the integration test explicitly clears it before closing.

Spline evaluation (`core2/1EA1270.c` and `overlays/ml/spline.c`) now runs as
native C with compatible callback signatures, full-width coordinate pointers,
explicit forwarded arguments and floating-point return values. The native build
also includes the original angle/vector module `core2/1ECB0F0.c`. Hardware angle
helpers use host libm; they do not reproduce N64 lookup-table quantization.

Spline tests exercise two through six control points, both interpolation modes,
derivatives checked against finite differences, arc lengths, nearest points,
clock selection, forward/backward traversal, loop wrapping and orientation.
A stationary tangent previously produced infinity and an invalid integer
conversion under UBSan; native traversal now retains the current parameter when
the tangent magnitude is zero or nonfinite. Actor movement and event execution
still require integration with the native world.
All 32 functions in the two modified spline objects retain identical Original-IDO
instructions, and the full N64 ROM comparisons remain exact.

Path storage now uses a shared native context with full-width actor and target
pointers. The original `gl/spline/Dll.c` builds coordinate and sorted event
lists using native allocation handles, and releases these lists on cleanup.
`gl/spline/find.c` searches native paths by coordinate or adjacent point pair.
The latter search had an ASan-confirmed read past the last point; native search
now stops at the last complete pair. Event byte fields are extracted from native
words explicitly rather than relying on big-endian byte addresses.

The command table from asset `0xAFF` is copied to host byte order. Its original
two-pass offset scanner has native bounds and record-count checks; malformed or
truncated streams release their partial state. The lifetime test runs 40 build,
sample, search and cleanup cycles with controlled level-prop enumeration and
both synthetic and original archive command data. It also checks empty/repeated
cleanup, handle reuse, clock selection and actor-pointer retention. This is not
a real level transition: world-prop loading and the actual world/camera effects
invoked by scripts remain pending. Both modified overlay objects (five functions each)
retain identical IDO machine code.

The original path movement and `gl/spline/node.c` event dispatcher now operate
on host-order state words and full-width `Actor` fields. Native bitfield views
preserve the numeric N64 bit positions on little-endian hosts. Event traversal
uses bounded indices in both directions, and absent interpolation links stop
before the end of the list is read. Actor coordinates, target rotation, wait
state and dialog parameters no longer depend on N64 byte offsets.

The motion test runs the original curve traversal, event dispatcher, animation
controller and angle interpolation together. It covers forward/backward event
crossings, timed waits and conditions, path jumps, direction changes, animation
selection, missing links, speed/angle transitions and fixed/player/actor targets.
World lookups, dialogs and actor side effects are still
fixtures in this test; this is not a running level. All 56 functions in the two
modified N64 objects retain identical IDO instructions, with both ROM forms
byte-equal to the originals. The native suite currently has 32 tests.

The shared `core2/1EDED00.c` now provides the actual actor path-state allocator,
lookup, setup, updates and release. Its handle-based state survives pool growth;
tests create and release 64 actors, validate path flags and coordinates, and run
actor updates through the original movement and node dispatcher. Native
freelists align both their header and element stride for host pointers.

The same module's model-item lists retain full-width model/vector pointers and
callback addresses. A separate test exercises 32 actors, all eleven item types,
optional defrag callbacks, model rebinding, item searches, update suppression,
failed model creation and cleanup. Model loading/rendering and item-specific
effects remain fixtures; their actual overlay implementations still need
porting. The native library exposes their real unresolved dependencies rather
than supplying production no-op callbacks. All 37 actor-module functions and
11 freelist functions retain their Original-IDO instructions.

`gl/spline/funcs.c` now performs actual event-target lookup in the current path
and other registered paths. Missing targets stop before out-of-range reads;
the node dispatcher leaves the actor state unchanged when lookup fails. Tests
cover target precedence, empty/full lists, cross-path jumps, orientation decoding
and path assignment/registration after spawning. Spawning now calls the actual
factory lookup, constructor and actor allocator; metadata tables, grid initialization
and component implementations remain controlled test dependencies.
Both helper functions also retain their Original-IDO instructions.

The original `gl/spline/cs.c` interpreter now executes host-order command records
against the actual actor path state. Time/progress scheduling, waits, counters,
message conditions, animation control, path jumps, targets, actor registration,
cross-actor script assignment and interpolation are exercised through the real
interpreter. Every instruction is checked against its own script section before
operand reads; invalid actor/counter references and truncated records stop that
script. The original archive's 170 scripts and 1,702 command records pass this
boundary validation, without claiming that their world effects have run.

Earlier immediate-callback tests exposed stale actor/path-state pointers during
spawning; the native interpreter and enclosing updates reacquire them through the
marker. The integration test now follows the actual deferred queue: it verifies
that the script enqueues work, then forces both pools to grow before draining the
queue and checks the spawned actor's path state. Metadata selection, grid initialization, actor components,
dialogs, camera/player effects and target-world lookups remain fixtures. The six interpreter functions retain identical
Original-IDO instructions, and the full ROM comparison remains required.

The actor registry (`core2/1EDFED0.c`, 13 functions) now allocates host-sized
actors, resolves marker indices and iterates/removes actors using the original
vector implementation. Unordered removal updates the moved actor's marker while
preserving its other flags. Native marker lookup rejects removed or mismatched
markers. The registry test covers growth to 80 actors, relocation, iteration,
removal and cleanup over 40 cycles. The script integration test uses this actual
registry for actor lookup and forces growth by another 120 actors. Native
allocation refuses indices beyond the marker's 11-bit range; the capacity test
exercises all 2,048 entries, removal and reuse. Missing actor targets safely
retain the current orientation. World-grid loading and actor components still need integration.

The shared actor-property module (`core2/1EDC7B0.c`, 11 functions) also compiles
from the original C. Metadata queries combine the typed 16-bit flag halves rather
than reading N64 offsets from a pointer-sized host structure. Parent-marker
references retain their full pointer width; shadow dispatch resolves them through
the real registry and skips removed parents. Actor scale, one-shot flags and the
position/rotation forwarding use the canonical host fields. Tests cover both
31-bit metadata banks, flag independence, parent visibility/removal and argument
forwarding. Metadata selection, collision and actual shadow rendering remain
controlled dependencies. All 24 functions in the registry and property modules
retain their Original-IDO instructions.

The original actor constructor and spawn helpers (`core2/1EE1510.c`, 22
functions) now compile and execute natively. Actor metadata and marker callbacks
retain full-width function pointers; typed actor flag views preserve N64 numeric
bit positions on little-endian hosts. Float/short coordinate wrappers use actual
arrays and explicit return values instead of MIPS stack/register side effects.
Owner pointers are refreshed after actor-vector growth, failed marker creation
releases the two allocated buffers, and invalid factories stop before invocation.

The factory test covers constructor defaults and metadata flags, callback
selection, actor-vector growth through owner-relative spawning, prop overrides,
visibility copying, marker-generation checks for queued messages, cyclic/missing
world-node links and path-state assignment through the real path search and
sampler. The script integration test now invokes this same constructor. Deferred
payloads use a shared pointer-width callback interface with explicit adapters for
game signatures. Queue storage/execution now uses the original modules described
below. World-grid initialization, component setup and metadata-table selection
remain test boundaries; no production stubs are provided. All 22 functions retain identical Original-IDO instructions.

Deferred spawn storage and execution now run through `core2/1E7F4D0.c`,
`ch/bad/dieDll.c` and `ch/bad/diesetup.c`. The native context owns 22 host-sized
records with pointer-width arguments and a typed callback union for arities zero
through six. The original FIFO order, capacity limit and processing of callbacks
appended during a drain are preserved. Native draining rejects recursive entry
and invalid counts; cleanup during a callback stops the remaining work safely.

Tests cover all seven signatures, full-width payloads, enqueue-before-allocation,
capacity, append-during-drain, reentry, cleanup, reuse, initialization/update
ordering and the four original spawn argument wrappers. Factory/message and
script-spawn tests use this actual queue rather than a fixture dispatcher.
World initialization/update dependencies and bounce-actor effects remain
observations in the queue test; this is not a running world or frame loop. All
26 functions across the three modified modules retain their Original-IDO
instructions, and both rebuilt ROM forms remain byte-identical.

The marker integration uses a typed native world-prop record with a full-width
owner pointer and separate position/flag fields. Script target lookup now follows
its actual return type (`Actor *`) and caches that actor's marker. Looking at a
target reads the marker's current world prop, so moving its storage preserves the
lookup; a missing prop/cache skips only target recomputation and still completes
the ordinary rotation update. The test uses this actual pointer chain rather
than a pointer-to-short-array substitute. The marker pool and world-prop allocator are now part of the native core; loading the full world grid remains pending.

The complete marker module (`core2/1EC4CC0.c`, 51 functions) compiles directly.
Its 200 stable marker slots and 15-bit generation sequence keep their original
limits. Pool addressing, world-cell pointers, callbacks, group vectors and search
results use native widths; cube indices and model centers use typed host fields.
Cell movement reserves the destination prop before removal so allocation failure
keeps the old location. Group insertion avoids forming a pointer before the first
element. The existing actor-factory and deferred script-spawn tests now use the
real marker allocator, setters and cleanup rather than marker fixtures.

`bt_native_markers_test` covers pool exhaustion/reuse, generation wrapping,
initialization masks, coordinate/angle conversion, cell transitions, prop relocation,
marker exhaustion, scaled bounds/cache behavior, seven draw groups and nearest
prop searches with pointer-width filter contexts. Factory tests additionally check
that a queued message cannot reach a replacement actor in a reused marker slot.
The focused marker test now uses the real shared world pools and game asset cache,
with a generated asset fixture. Model centers and radii now use actual decoded
vertex headers. Grid initialization, drawing, sprite dimensions and memory-pressure
policy remain controlled boundaries. All 51 Original-IDO functions remain byte-identical.

The shared block allocator (`core2/1E8D2C0.c`, 18 functions) now keeps its original
free-block merging, append, relocation, ordered removal, compaction and shrinking
algorithms with a pointer-aligned native header. Empty pools can grow safely and
16-bit capacity overflow is rejected. Its test compares 12,000 mixed operations
against independent expected records and checks that allocated/free blocks cover
the entire pool without overlap.

World-prop storage (`core2/1EC2FD0.c`, 25 functions) now owns actual block pools
for scalar model records and pointer-sized dynamic props. The eight-byte world
cell still holds two start/count pairs. Sprite/model initialization, append,
removal, indexed access, marker-pointer repair, cell cleanup and lifecycle calls
execute the original C. Native model bitfields preserve their N64 numeric masks.
Freeing a cell repairs remaining markers if shrinking relocates the shared pool.

The world test exercises 180 markers across three cells, growth, cell movement,
ordered removal, freeing whole cells, model-prefix counts, node deletion and
initialization flags. Existing actor-factory and script-spawn tests use this
storage as well. The former world-storage fixture has been removed. Grid
lookup/enumeration and the static-model count table now use the actual grid
implementation below; test grid initialization and external world callbacks
remain controlled in those tests. All 43 functions in the allocator and world-prop
modules retain identical Original-IDO instructions. The cube integration below
now covers grid allocation and prop loading; rendering and the frame loop remain
unintegrated.

The grid module (`core2/1E96E60.c`, 30 functions) now uses a shared native state
with full-width cell/table pointers, the original eight-byte cell records and an
embedded fallback cell. Position/index conversions, bounds queries, neighbor
queries, marker-pointer repair and overlay forwarding execute the actual C.
The float-position cell wrapper explicitly returns its result. Stream arguments
forwarded to the cube loader preserve their pointer width.

The grid test checks every cell of a 4-by-5-by-6 grid, negative/exact-boundary
coordinates, clamping, invalid indices, empty grids and ordered neighbor results
before/after removing selected model/dynamic props. Interior and boundary queries
keep their distinct original traversal orders; the largest dynamic query returns
27 regular cells plus the fallback and a terminator. Actor/spawn/marker/world tests
now use the real grid lookup and pointer-repair functions. The grid tests supply
their metadata explicitly; the cube test below exercises the actual allocator
and loaders with controlled map geometry. Its optional archive pass now obtains
map metadata and bounds from the original map loader below. External render
callbacks remain to be integrated. All 30 Original-IDO functions retain
identical machine code.

The game stream overlay (`gs/maker.c`, all 26 entrypoints) now compiles directly
with native pointers and explicit constructor returns. Borrowed buffers, owned
growable output buffers and pinned asset streams retain their distinct lifetimes.
The scalar accessors preserve big-endian 16/32-bit file values, including exact
floating-point bit patterns; byte blocks remain unchanged. Read bounds, negative
lengths, growth overflow and exhausted cache pin counters are rejected. A sticky
`GsFile.failed` flag lets the consuming parsers stop on truncated input.

The stream test checks every tagged accessor against independently specified file
bytes, mismatched-tag lookahead, unaligned values, repeated buffer growth, failed
loads, borrowed/owned buffer cleanup and concurrent readers of the same cached
asset. It uses the actual game memory routines, archive loader and both cache
layers. The optional archive run reads all 235 original database assets through
`gsmaker_entrypoint_2` and checks their contents and cache release. The cube parser
is now integrated below, followed by the camera database, lighting parser and
world-section dispatcher.
All 26 stream functions and the 54 existing asset-cache functions retain identical
Original-IDO machine code; the complete ROM remains byte-equal.

The cube loader (`gc/cubeDll.c`, 12 functions), map-prop integration
(`gs/propsDll.c`, 7 functions) and prop queries (`gs/propmarker.c`, 4 functions)
now compile directly. Both cube formats decode 20-byte model and 12-byte sprite
records into native structures; sprite records expand to the native pointer-sized
layout. Unknown tags, truncation, invalid counts, serialized actor pointers and
model-prefix overflow stop the stream. Empty lists may omit their legacy data
tag, matching the original assets. Grid creation, cleanup, stable model partition,
actor collection, effect dispatch and prop queries use the actual C modules.
Actor collection allocates its list from the model count instead of overflowing
the original 500-pointer local array.

The cube test exercises both formats, native grid allocation, fallback sprites,
negative positions, model lookup/scale/flags, 600 collected actors, effect passes
and malformed input. The actor-factory test also reads a serialized map record
through the real stream/cube/prop code and creates an actor with the real factory,
registry and marker, checking position, rotation and scale. Spawn-queue and path
tests now call the real cube functions instead of their former cube fixtures.
The cube test now uses the actual grid collision callbacks. Actor metadata,
animation/deformation, effect creation and trigger updates remain test boundaries. An optional archive run loads the legacy cube
sections of nine original assets (27 model records, no sprite records); it does
not process their remaining world sections or prove complete maps playable.
All 23 Original-IDO functions in these three modules retain identical instructions,
and the complete compressed and decompressed ROMs remain byte-equal.

The camera database now compiles its 80 original functions directly:
`core2/1E7EE40.c`, `ca/dbmgrDll.c`, `ca/dbfunc.c` and `ca/dbio.c`. Its eight record
types retain their scalar layouts; the manager uses a native selected-record
pointer and typed count/handle/index fields. Accessors keep the shared original
C bodies with native pointer declarations. The existence-query wrapper now
explicitly forwards the camera ID. Insertion preserves records when handle
buffers move, includes the highest permitted ID when repairing indices and
rejects overflow of the eight-bit per-type index. The parser rejects unknown
tags, invalid IDs/types and truncated records, releasing partial databases.

The camera test verifies the default bytes of all eight types, all 36 public
field accessors, unrelated-field preservation, reverse-order insertion of 256
records, the highest ID, selection invalidation, repeated cleanup and full-width
player callback forwarding. Every truncated prefix of a complete test stream
is rejected. The optional archive run loads all 226 camera-first database assets,
containing 4,048 camera records, through the actual archive/cache/stream/parser
path. Initial camera pose and player callbacks are test boundaries; live camera
motion and rendering remain unintegrated. All 80 functions
retain identical Original-IDO instructions and the full ROM is byte-equal.

The lighting backend now compiles all 38 original core functions and seven
`gc/lightsDll.c` functions directly. Native records retain their 28-byte scalar
layout; vector pointers, callback predicates and returned state pointers use
host declarations. The allocation, flag queries, deferred removal, ambient and
directional colors, local-light ranges and nearest-light selection use the real
game vector and scalar-math implementations. Invalid or disabled lights are
excluded from nearest-light queries. The tagged parser rejects unknown tags,
missing required fields, truncation and coordinates that cannot safely convert
to integers, and frees a partial light database after failure.

The light section is shared through `src/core2/1EA1DA0_lights.inc`. The N64 parent
translation unit retains all its functions and their order; the native core
currently compiles this shared section directly. Its remaining transition and
timed-event sections are still compiled by the full-source audit and still fail.
Once those sections are ported, the native core must compile the parent `.c`
instead of the `.inc`. All 88 functions in the N64 parent, all seven light-overlay
functions and all six world-overlay functions retain identical Original-IDO
instructions. Both complete ROM forms remain byte-equal.

The world dispatcher (`gs/worldDll.c`) now passes camera, cube and lighting
sections to these actual C parsers, rejects unknown sections and releases its
asset stream on success or failure. The native world-loading caller stops if
the dispatcher reports failure. A synthetic archive tests the combined loading
path and its invalid/missing-asset cases. The light test also checks every
truncated prefix of its complete tagged stream, all 17 light categories,
full-width predicate callbacks, record reuse and deferred removal.

The optional cube archive test runs the shared dispatcher over 226 original
camera-first world assets: 15,973 model objects, 159 sprites, 4,048 camera entries
and 779 lights. This pass now loads the actual map models, derives grid bounds
from their vertex headers and uses the original cell sizes and boundary padding.
The lagoon map sections now also load through the real section manager.
The full world lifecycle and rendering remain unintegrated. The separate
collision integration test below now queries actual map geometry.
The nine older assets are tested only for their cube sections: their remaining
stream contains tag 3, which the existing world dispatcher does not handle.
These archive results demonstrate data loading, not playable maps.

The model-section accessors (`core2/1E8BFE0.c`, 17 functions), vertex-list
operations (14 functions from `core2/1E8A670.c`) and both `db/palette.c` functions
now compile directly. Model header offsets stay relative to the model allocation;
returned pointers and palette arguments have host width. The archive loader
validates the model version, header size, section offsets, vertex alignment,
vertex count, geometric bounds, zone-list size, auxiliary-channel extent and
collision records before changing any bytes. It converts header, vertex and
collision scalars to host order, preserving
the vertex color bytes and numeric count/flag bits. Other section payloads remain
in N64 byte order and require their own parsers before use.

The real vertex functions now provide bounds, center/radius, full-width vertex
ranges, independent copies and color/palette updates. The palette functions read
and write the serialized color order directly. Their test checks preservation of
positions, texture coordinates and alpha, the empty-list case, null optional
sections, malformed offsets/counts and every truncated prefix of a minimal
two-vertex resource. Invalid resources are rejected before mutation. The marker
test has removed its model-pointer and center/radius fixtures, and the cache test
checks copying a decoded model into a caller-owned buffer.

The optional model archive test loads all 1,145 original models and 739,955
vertices through the real game cache in both sanitizer and optimized builds.
These model bounds now feed the map-initialization port below; the isolated
world-grid tests still use controlled map bounds. Display lists, textures and
the renderer are not yet integrated. The vertex section
is shared as `1E8A670_vertices.inc` until its parent's collision routines are
ported; the full-source audit still compiles and rejects that remaining code.
All 22 functions in the N64 parent, all 17 model accessors, both palette functions
and all 51 marker functions retain identical Original-IDO instructions. The
complete compressed and decompressed ROMs remain byte-equal.

The map loader (`gc/mapDll.c`, 12 functions) now uses typed native layers and
configuration records. Its 228 original map records retain both model IDs,
signed grid padding and clone flags; the cell-size table includes its original
default. The N64, ILP32, and LP64 builds use the same tables in
`src/overlays/gc/mapDll_data.inc`. Native map tests read them without a ROM or extraction.
Loading pins both model layers, initializes zone state and the vector table,
combines bounds and passes native pointers to lighting, instance and texture
interfaces. Failure releases partially loaded map resources; texture preloading
keeps prior textures intact if a later layer fails. Repeated cleanup is safe.

The bounds functions remain shared through `1E97EF0_bounds.inc`, including the
N64 negative-boundary division rule and signed map padding. The native build now
compiles their full 50-function parent, `core2/1E97EF0.c`, rather than a bounds-only
slice. The world archive test has removed its substitute cell-size and grid-bounds
functions and calls these real C implementations.
All 226 current-format world assets load using their actual map geometry and
retain the object/camera/light counts above in both build configurations.

The eight vector-table functions (`core2/1EB57A0.c`) preserve full-width pointers
and explicitly forward vector arguments. The seven `gl/zone.c` functions and six
`db/zone.c` functions now operate on native pointers; zone queries decode their
serialized short bounds and explicitly return containment results. The map test
checks both layers, primary/combined bounds, exact negative cell boundaries,
configuration switches, resource pinning, texture rollback, missing models,
vertex cloning, zone containment/selection, vector operations and cleanup.
Lighting/texture/instance backends remain controlled test dependencies.
The lagoon maps now load their individual sections as described below. These
checks do not establish a complete world lifecycle or playable map.

The 12 map-overlay, eight vector-table, 13 zone and all 50 map-core Original-IDO
functions retain identical instructions, and both complete ROM forms remain
byte-equal. Both the sanitizer build and the optimized Release build pass all 32 tests on
the development host. Native builds use the host `stdio.h` declaration of
`sprintf`, avoiding a collision between the N64 prototype and macOS fortified
stdio macros during optimization. The adapter lives in `pc/native/include/PR/os_libc.h`;
the libultra submodule and N64 header path remain unchanged.

## Build and test

From the repository root, with CMake, Python 3.11+, zlib development files and Clang or GCC:

```sh
cmake -S pc -B build/native -DCMAKE_BUILD_TYPE=Debug -DBT_NATIVE_SANITIZERS=ON
cmake --build build/native --parallel
ctest --test-dir build/native --output-on-failure
```

The map section manager (`gc/mapsects.c`, all 42 functions) and all three lagoon
initializers/callbacks compile directly for the host. Native section records keep
full-width model, texture, instance and callback pointers. The checked-in section
tables reproduce the 13 original records, neighbor links and culling points;
`generate_map_sections_data.py` reproduces them from the owning assembly data.
Loading and cleanup track each section's own cache pins, including models shared
with the base map or another section. The asynchronous path acquires a section's
pin even if another owner has already loaded that model. The map loader reports
section-load failure and releases partial resources.

The section test covers bounds, neighboring/hidden sections, selection, height
queries, busy/ready transitions, callback pointers, both model layers, shared
pins, delayed loads, missing resources, repeated cleanup, draw arguments and
line/sweep/sphere routing. The optional archive pass loads, updates and releases
all 13 actual lagoon sections, including their original culling callbacks.
Camera/player inputs, asynchronous scheduling, renderer, instance and geometric
collision implementations are still test boundaries. All 19 functions in the
original geometry helper module `core2/1EC9740.c` now compile too; the tests use
its real box/sphere checks and verify projection/normalization pointer fixes.

The collision dispatcher (`core2/1EA0210.c`, ten functions) retains the original
query loops with a native table of eight typed callback sets. Registration
rejects overflow, and reset clears the last hit's model pointer. Tests exercise
all hit/miss combinations for line, swept sphere and sphere queries, original
registration order, the last successful query's model, null callbacks, reset,
capacity and height queries. The world-grid test registers the actual world-object
queries in this real dispatcher instead of replacing registration or queries.
The geometry integration test below uses the actual collision routines. All 101
Original-IDO functions in the eight
files changed for these section/dispatcher integrations retain identical
instructions; both complete ROM forms remain byte-equal. The native suite passes
53 tests in Debug with AddressSanitizer/UndefinedBehaviorSanitizer and in Release.

The full map runtime (`core2/1E97EF0.c`) now connects map loading, section updates,
collision dispatch, draw parameters, vertex-buffer swaps, instance visibility,
lighting and cleanup through native interfaces. Its pointer-returning getters
use host pointers, and its height wrappers explicitly return the result that N64
callers consumed from the floating-point return register. The map registration
entrypoint reports load/registration failures and releases a newly loaded map if
the callback table is full. It preserves the original query order and collision
owner assignment, including the repeated section query in the two-layer line
path. Native allocations do not move, so heap-relocation-only work is unnecessary.

The expanded map/section test exercises the real runtime and dispatcher together:
primary/secondary hits and misses, section fallbacks, filtering, height searches,
extended rays, both vertex buffers, draw switches/colors, instance visibility,
lighting selection, full-width getters and failure cleanup. The instance visibility
value is passed explicitly instead of relying on the MIPS argument register. Actor
factory/path tests now use the actual zone getter; the factory also reads the real
map lighting mode. The optional lagoon archive test loads, updates and unloads all
three maps through this runtime. Renderer, light/instance backends and geometric
collision calculations remain controlled test dependencies. This is still not a
complete game loop or visible map. All 50 map-runtime and 22 actor-factory functions
retain identical Original-IDO instructions; the complete ROMs remain byte-equal.

The geometric collision module (`core2/1E83B90.c`, all 28 functions) now compiles
with its original line, sphere, swept-sphere, triangle collection and edge tests.
Native changes preserve pointer-sized hit values, scratch lists and processed
triangle records. The swept-query block cache allocates and advances records by
host layout, preserving its original 15/50-record blocks and timed reclamation.
Collision model decoding validates cell dimensions/strides, triangle spans and
vertex indices before mutation, rejects collision overlap with other declared
sections, and converts the grid, triangle indices and flag words to host order.

All 28 original C matrix functions in `core1/mlmtx.c` are also compiled. Portable
implementations of the required assembly identity, translation and scaling helpers
use the same matrix stack. Rotation retains the C routines and the cached cosine
interface, using host libm as the other native angle helpers do; N64 lookup-table
quantization is not reproduced.

`bt_native_collision_geometry_test` tests the actual geometry, not hit callbacks:
nearest/front/back hits, flag filtering, sphere face/edge/vertex paths, swept
queries, repeated cache growth/reclamation, transformed models, triangle output,
grid clamping and the 100-cell query limit. It checks malformed/truncated resources
and callback-independent matrix round trips. Its optional archive pass validates
all 546 collision meshes containing 653,004 triangles and hits all 1,618 sampled
rays constructed through triangle faces. It also loads and queries all 228 map
configurations through the real map runtime, collision dispatcher and geometric
routines; 201 center rays hit geometry in the current archive. Other center rays
may cross empty space. Those queries also exercise sphere/sweep calls and map
cleanup under sanitizers. This is geometry integration, not player movement or
complete gameplay. Rendering, instances and camera/player input remain controlled
dependencies in that test. Both full ROM forms remain byte-equal, and the 28
collision functions retain identical Original-IDO instructions.

The world-object collision path now compiles all eight functions in
`core2/1EA6B20.c`, the three collision-context functions in `core2/1EA5130.c`,
all six `su/baddie/customhits.c` functions and both original `gs/proplookup.c`
lookup tables. The five-function cell-query/callback section is shared through
`1EC3810_collision.inc`; its parent's world lifecycle, render and attachment
functions still need integration and remain in the failing full-source target.

World queries retain their original cell iteration order, lower-Y extension,
fallback-cell query and last-hit result. Cell queries use actual decoded model
geometry with native static-prop transforms, actor transforms, custom callbacks,
collision filters and cache operations. The line path intentionally retains the
original custom-callback ordering, which differs from sphere/sweep handling of
disabled actors. Marker custom-table getters and all query results now use full
host pointers. Hit notifications retain the packed static-prop word for a static
sweep and a marker pointer for an actor ray.

Nearest-marker sampling and multi-sphere queries preserve broad-phase filtering,
callback rejection, query/result nibbles and tie order. The original 32-marker
result buffer is replaced by the existing vector container, retaining every hit
without overwriting adjacent state. Zero/nonfinite sweep radii are rejected;
empty multi-sphere queries clear previous results. Native custom-hit callbacks
also preserve generation/frame caching and pass skeleton-query pointers at full
width. The skeleton and actor animation/deformation backends are now integrated as described below.

`native_world_collision` tests static models and actor geometry through the real
world grid, model cache and triangle queries; it also checks callback selection,
disabled/filter paths, exact 3D cell/fallback order, marker sampling, 80 simultaneous hits,
result indices, custom-hit caching and setter/getter pointer identity. Animation,
actor deformation, skeleton geometry and attachment recording are explicit test
boundaries, not production fallback implementations. All 101 Original-IDO
functions across the six changed owning modules remain byte-identical, and the
complete compressed and decompressed ROM comparisons pass. The optional original
archive runs still query all 546 collision meshes / 228 configured maps and load
226 world assets. A separate original-prop pass loads all 37 populated static
lookup entries and hits all 60 sampled rays across their 20 collision meshes
through actual cell queries, also exercising sphere/sweep paths. This is further
game-code integration, not a playable build.

The complete actor model module (`core2/1EDCA30.c`, 32 functions), vertex/cache
module (`core2/1ED9D70.c`, 21 functions) and `gl/packvtx.c` now compile natively.
Model selection, bounds/radii, marker centers, both vertex buffers, palette
application, resource activation/release and automatic custom-hit getter
installation use native pointers. Previously implicit MIPS register returns and
arguments are explicit. Actor resource halves have named native fields while
preserving their numeric flag words; skeleton handles preserve marker generation
bits. Actor-item vertex forwarding now retains both full-width buffer pointers.

The vertex cache uses the existing freelist allocator for native records and
retains the original two-update deferred release, shared packed-color entries,
copy-on-write palette updates and scratch-buffer expiry. Packed-entry handles and
reference counts no longer truncate to eight bits. Defragmentation-only work is
unnecessary with the native nonmoving heap. The packed-vertex palette reader now
has space for all four color components it writes; the original three-element
local would overflow. The unused tenth packed byte is initialized in native code.

`native_actor_model` checks all these paths, 400 shared-cache users, model changes,
full-width model messages, resource ownership and cleanup. The world-object
collision test now uses the actual actor model/bounds/vertex accessors and custom
hit bounds rather than its old actor-model fixtures. Animation/effect resources,
actor event consumers, attachment recording and skeleton narrow-phase geometry
remain explicit test dependencies. This does not establish a working renderer or
animated gameplay. The optional model archive pass activates all 1,145 original
models (739,955 vertices), checks and swaps both copied vertex buffers and releases
them through the actual actor lifecycle in both sanitizer and Release builds.
All 55 Original-IDO functions in the three newly ported modules retain identical
instructions; both complete ROM forms remain byte-equal. The full-source target
still includes every unported module and still fails.

`1EDA900.c` now provides the native actor event dispatcher and its context.
Actor metadata callbacks accept full-width payloads and return values. Direct,
type-filtered, radius-filtered and world-cell broadcasts use the actual actor
registry and marker grid. The fallback-cell query now uses its callback result;
the original C tested a stale/uninitialized local there. Native callbacks stay
linked, so the N64 overlay residency/unload operations do not apply. Deferred
actor messages and model load/unload notifications now traverse this dispatcher
in their integration tests, with observed callback consumers.

`1ED8C80.c` now supplies the native actor lifecycle: subsystem initialization,
regular/alternate frame callbacks, one-time initialization and activation events,
range checks, marker transforms, resource updates, delayed removal, linked-actor
removal, model-cache eviction and teardown. Actor buffer slots retain the numeric
N64 handle words while holding full-width host allocations. Allocation sizes are
tracked by the existing native handle allocator; resized actor buffers preserve
the old contents and zero newly allocated bytes. Invalid slots and overflowing
sizes are rejected. Heap-compaction-only passes do not relocate native objects.
The metadata getter remains a separately compiled shared include in the native
core, allowing tests to isolate lifecycle dependencies.

`native_actor_lifecycle` integrates the real actor constructor, registry, event
dispatcher, animation controller, model/vertex cache, item ownership, path-state
allocation and native heap. It checks callback order, regular/alternate/disabled
actors, both observer-position sources, radius boundaries, buffer resizing,
model-item updates, delayed linked removal, ten-actor eviction batches and
idempotent destruction callbacks. Animation containers and skeleton resources
now use the actual implementations described below. Player/camera providers,
effects and visible render-output consumers remain observed test boundaries.
`native_actor_events` also checks full-width values, missing handlers, strict
radius boundaries, fallback-only delivery and actor-registry mutation. All 40
Original-IDO functions across these two owning modules keep identical instructions,
and both complete ROM forms remain byte-equal. These tests do not establish a
linked playable game, a renderer, audio output or save/load support.

The actor animation layer now includes `1EDDA60.c` and `1EDB4D0.c`.
Controller handles use the actor's named native field and the existing freelist,
including pool growth and resource release. Animation tables and dynamically
supplied event contexts carry full-width pointers. Playback selection, unchanged
animation handling, random start/direction flags, timer queries, transition
settings and speed-dependent durations execute natively. The missing argument
forwarding in the original MIPS call is explicit in the native branch; the
transition setter preserves the IEEE-754 bit-pattern convention of existing
integer callers. Pose and vertex pointers also reach the deformation/rendering
boundary without integer truncation.

The actor-lifecycle integration test now uses these actual controller ownership
and state-selection modules instead of its former controller fixtures. It checks
96 simultaneous controllers across pool growth/reuse, preservation of adjacent
expression handles, normal and event-provided animation tables, state changes,
flags, frame timing and both vertex buffers passed to deformation. Animation
resources are sampled through the real animation backend. Skeleton matrix
construction, expression-model setup and vertex deformation now execute the real
native implementations described below. This
does not yet provide visible animated rendering. The
optional original-archive pass selects all 1,230 nonzero animation IDs and samples
4,920 finite poses through the actual actor state/controller/animation pipeline,
skeleton construction and vertex deformation in both sanitizer and Release builds.
The model with the most bones among the skinned assets is used for this stress
check; applying unrelated animations to it is not visual animation validation. ID zero retains its game meaning of no
animation. All 37 Original-IDO functions in these two modules keep identical
instructions; both complete ROM forms remain byte-equal.

`db/anim.c` now deforms native vertex lists from the model's bone/vertex
bindings, including duplicated vertices, position-group separators and separate
normal output. The model loader validates record sizes, signed counts, matrix
indices, vertex references, normal capacity and section boundaries before changing
any bytes. Binding scalar fields become host-endian; packed normal bytes retain
their serialized representation. The original matrix accessor is shared through
`1E875C0_matrix.inc`, now included by the complete native skeleton module.

`skinning.c` implements the two handwritten MIPS transformation routines as native
C. It preserves the arithmetic order, nearest-even position rounding and low-word
storage behavior, including deterministic handling of out-of-range conversions.
Floating-point contraction is disabled for these routines. This is native math,
without an emulated MIPS CPU. `native_skinning` checks nonuniform scaling,
translation, normals, untouched vertex attributes, rounding ties, alternate host
rounding mode, malformed input and validation without partial mutation. Its
original-archive pass exercises 106 binding sections, 1,665 groups and 46,975
vertex references, with both position and normal paths. The actor-animation test
now calls actual skeleton construction and deformation for both copied vertex
buffers. Visible rendering remains integration work. All
26 Original-IDO functions in the two touched owning modules retain identical
instructions, and both complete ROM forms remain byte-equal.

The complete `1E875C0.c` skeleton module now uses native pointer-safe matrix
containers, heap/handle ownership, bone lookup/copy, pivot queries and both
rotation-only hierarchy modes. `skeleton.c` implements the handwritten quaternion,
component-scale and pivot-translation pipeline, plus fixed-point matrix packing;
no emulated CPU is involved. Model loading validates and decodes every skeleton's
finite values, pose indices, parent ordering and bounds before mutating input.
The existing `1EBA250.c` expression module applies weighted rotation, scale and
translation corrections, with native allocation and mask-bound checks. Its two
handwritten quaternion dependencies are implemented in native C. Host angle
helpers still use libm rather than the N64 trigonometric lookup table.

`native_skeleton` checks branched hierarchies, nonuniform scales, pivots,
rotation-only modes, matrix ownership, expression masks (including bit 31),
positive/negative blend weights and fixed-point word packing. An original-archive
pass reconstructs bind-pose matrices for all 445 skeletons / 7,533 bones. The
actor integration fixture now derives vertex positions from its actual animation
channel instead of a supplied matrix, and allocates/resets/frees real expression
models. The shared render-state provider now uses the actual implementation
described below. All 24
Original-IDO skeleton functions and 15 expression functions retain identical
instructions; both full ROM forms remain byte-equal. This remains an integrated
core test suite, not a bootable or playable game.

The shared render state from `1EB5E70.c` is now integrated with native pointers
for poses, bone matrices, vertex/color/normal buffers, display lists and callbacks.
Its original reset behavior, switch table, resource initialization/destruction,
transform overrides and color modes are preserved. Geometry dispatch mode stores
the index of the original table and selects its behavior in the native geometry
consumer described below.
The actor lifecycle test now uses these actual state setters and resource owners.

The complete `1E8CC00.c` light-list and `1EE7960.c` model-lighting modules are
compiled natively. They select the closest affecting world lights, attenuate by
range, combine ambient/directional contributions and update vertex RGB while
preserving positions and alpha. Native list capacities are enforced. Coincident
point lights have a zero direction instead of generating NaNs, and zero total
light distance avoids division by zero. Floating-point contraction is disabled
for these modules to preserve the original intermediate rounding before integer
color conversion. `native_render_state` tests full-width pointer/callback values,
reset semantics, sorted light eviction, capacity edges, actual world-light-to-
vertex-color processing, bone-oriented normals and unchanged vertex attributes.
All 88 Original-IDO functions in the renderer owner, 14 light-list functions and
10 model-lighting functions retain identical instructions, and both full ROM
forms remain byte-equal. These checks do not establish a playable game.

The native graphics ABI now fixes two LP64 layout errors in the SDK types:
`Gfx` is an 8-byte word packet and `Mtx` a 64-byte fixed-point packet, rather
than the 16/128-byte host layouts produced by the original `long` and bitfield
unions. This is a native-only header adapter; `lib/ultralib` is unchanged.
`guMtxF2L` / `guMtxL2F` now have native C implementations, and the actual
`mlMtxApply` path emits these matrices. Tests verify packet opcodes, byte strides,
buffer canaries, general projection entries, signed fractions, truncation and
invalid conversions. Graphics pointers use the native address registration below;
narrowing a host pointer into a packet is not allowed.

Model loading now validates and converts display-list words and reachable geometry
command scalars. It checks all 25 command layouts, forward branches, shared child
nodes, record overlap, finite coordinates, signed display-list and bone indices,
selector tables and bounded variable-length arrays before changing any input.
The graph is processed iteratively, so long command chains do not consume the C
call stack. An independent inventory of the original archive found 50,236
reachable commands across its 1,145 models; every original model passes the
native loader. Geometry decoding and display-list decoding retain their original
byte strides, and segmented graphics addresses remain numeric packet values.
This supplies the validated input for native geometry execution; visible
rendering remains incomplete.

Native graphics memory now assigns bounded 32-bit references to registered host
buffers while retaining full-width host pointers. The native SDK adapters for
matrix, display-list, vertex, viewport, segment, light, look-at and image commands
distinguish numeric addresses from pointers. `osVirtualToPhysical` and the K0/K1
conversion macros use this registration. Unregistered host pointers fail loudly;
integer addresses are never treated as host pointers. Registration preserves
existing references, reuses contained ranges and rejects overlapping expansion.
Consumers resolve references with an explicit byte count; a segmented reference
cannot escape its registered allocation into the next one. Reset/disposal clears
all segments. Buffers and their registration must live through consumption of
the graphics batch, and the currently bound batch is single-threaded.

`native_graphics_memory` checks mapping growth, overlap, allocation boundaries,
address-space exhaustion, segment offsets, binding lifetime, SDK packet contents,
single evaluation of pointer/cursor expressions, and the actual `mlMtxApply` to
packet-reference to `guMtxL2F` path. The original-archive pass registers all 1,145
models' vertex and display-list buffers and resolves 82,386 original vertex-load
packets / 723,004 vertex references within their vertex buffers. This is the
address bridge used by native geometry execution; display-list consumption
and visible output are still outstanding. Static `gs*` pointer initializers and
other SDK pointer macros still require their owning native consumers to be ported.

The geometry section of `1EB5E70.c` now has a native consumer for all 25 command
types and all three original dispatch modes. It executes billboard/bone matrix
branches, ordered planes, selectors, LOD, boxes, spheres, attachment points,
zones, render modes and the repeated display-list/matrix sequences. Entries that
the original tables deliberately ignore retain that behavior. Emitted packets
reference the registered native display lists and 64-byte matrices. The original
four-plane culling functions are compiled directly, including the geometry
consumer's reflection retry. The model mode packets are native C constants from
the original three 24-packet tables. The zone-state setter now preserves its host
pointer instead of storing it in a 32-bit integer.

`1EE8860.c` now computes the original per-vertex projected texture coordinates in
native C, including signed packed normals, bone-relative camera axes, the 992
coordinate scale and truncation into the vertex's 16-bit coordinates. Geometry
commands call this implementation and the actual model-lighting callback. The
handwritten affine matrix-product/push operation also has a native C implementation.
These paths disable floating-point contraction to retain intermediate rounding.

`native_geometry` verifies packet order for every opcode/mode combination,
conditional branches, actual attachment and zone updates, bone matrices,
reflection culling, actual vertex lighting/texture edits, output capacities,
command-budget exhaustion and restoration of the CPU matrix stack on failure.
The caller supplies a command budget and bounded output buffers; nested geometry
calls have a 1,024-level limit and use the original 31-entry CPU matrix stack.
A failed draw has partial packets and potentially partial vertex edits and must
not be submitted. Input must have passed the model loader's validation, and the
original per-model callback setup must run before dispatch.

The archive pass executes all 1,145 original models in three modes (3,435 passes),
producing 81,867 graphics packets and 14,619 matrices with valid native references.
It uses native cameras positioned from each model's bounds, bind-pose matrices
and expanded selector masks;
it does not establish the appearance of an animated scene. All 88 renderer-owner,
49 camera-owner and 3 texture-projection Original-IDO functions retain identical
instructions, and the full ROM remains byte-equal. The complete model draw entry,
player viewport/reflection orchestration, GPU display-list consumption and visible renderer
still need integration before this is a playable game.

All 49 functions in `1EA3AA0.c` now compile as the native camera module. Typed
camera pointers and explicit argument/return forwarding replace assumptions
about MIPS registers. Position, quaternion orientation, four culling planes,
five world rays and perspective matrices use the original calculations. The
camera test covers state, ownership, 80 orientations, inverse matrices, culling
boundaries, clipping, fixed-point packing and invalid projection parameters.
The archive geometry pass uses these actual cameras in both configurations.

The shared float-to-short vector conversion now explicitly truncates to a MIPS
32-bit word before retaining its low 16 bits. This avoids undefined host casts
for large coordinates encountered during archive rendering. All 49 camera and
66 vector Original-IDO functions retain identical instructions, with full ROM
byte equality. UndefinedBehaviorSanitizer recovery is disabled so diagnostics
fail the test rather than being hidden behind a successful exit status.

`1EBCFC0.c` now compiles all 53 camera-manager functions with native pointer
signatures and explicit matrix/scalar return values. Camera selection and
snapshot/restore call the actual camera module. The perspective and orthographic
frame builders use the original matrix order, widescreen bounds, perspective
normalization and single half-scale retry. Their native graphics context carries
output ends and the registered-address map. Invalid camera parameters, missing
matrix registration or insufficient capacity fail without emitting packets or
changing output cursors. The identity/orthographic SDK helpers use native fixed
matrices; no emulator is involved.

`native_camera_frame` checks selection, snapshot ownership, movement, typed
forwarding, relative angles, bounds calculations, viewport matrix packets,
segment-8 restoration, widescreen combinations, 40 camera orientations,
projection range fallback and untouched buffers/CPU stack on failure. Every
archive model/mode pass now starts with these actual perspective/identity packets
before its geometry commands. The module's 53 Original-IDO functions retain
identical instructions and full ROM equality. Its screen/world conversion
wrappers still depend on the real, unported player/viewport owner; the test does
not replace it with a stub. Reflection-aware culling is integrated below.
A visible scene remains outstanding.

The model loader now validates and decodes texture-block metadata alongside the
other model sections. Texture and palette bytes keep their original N64 byte
order. Inline blocks retain their data; external blocks use the real `db/tex.c`
consumer to load the referenced compressed assets at ID base `0x1EF6`, check the
aggregate size, concatenate their payloads and replace IDs with native block
offsets. The resulting owned block has inline metadata and is released through
the original texture-free entry point. Invalid references and partial expansion
fail without modifying the source block.

Map and map-section loading now call this actual implementation. The previous
texture allocation/free test doubles are gone. Inline textures correctly need
no separately owned block, and failed external loads retain the previous map
textures. The fixtures contain actual compressed texture payloads and verify
bytes, rollback and cleanup. All 13 original lagoon sections also load, update
and release through this path in Debug and Release; their remaining lighting,
instance, camera and draw dependencies still have explicit test boundaries.

`native_textures` checks malformed metadata without partial conversion, empty
blocks, original zero-height metadata, expansion failure and segmented image
references. The original archive passes all 1,145 texture blocks: 909 inline and
236 external, 11,615 descriptors, 6,620 referenced texture loads / 12,777,344
concatenated bytes, and 127,101 segment-2 image references resolving within the
correct pixel buffers. All 56 Original-IDO functions in the texture/map/section
owners retain identical instructions and the full ROM remains byte-equal.
These are native resource and graphics-address checks; visible texture sampling
and the complete model draw entry are still outstanding.

The remaining three model-lighting callbacks now compile directly from their C
owners: `1EE8100.c` selects nearby point lights and multiplies base vertex colors,
`1EE8B70.c` selects additive lights by score and restores base colors when they
leave, and `tr/angler.c` retains the boss's forced-light selection. Native lists
preserve stable tie ordering, original fixed-point attenuation, color clamping,
vertex skip flags and alpha. Their capacities are bounded to the original nine
and five entries. An unavailable forced light is checked before dereferencing it.
Selection uses the actual world-light storage and forward/inverse model matrices;
these implementations contain no test replacement for those dependencies.

`native_point_lighting` checks near/far attenuation, both selection orders,
capacity limits, negative requested counts, transforms, repeated additive passes,
color restoration, forced-light duplicates and unavailable lights. The optional
archive run exercises all three callbacks on 1,145 original models / 739,955
vertices, verifies matching ordinary/Angler selection with no forced light,
additive idempotence, full vertex restoration and balanced matrix stacks. Debug
with fatal UndefinedBehaviorSanitizer and Release both pass. The callbacks' 12
Original-IDO functions remain instruction-identical.

The original `1E2B7B0.c` LookAt wrapper now forwards a host-width `LookAt *` to
the actual `1ECBCC0.c` matrix routine. Its reflection directions, fixed matrices,
translation and registered graphics references pass 40 view directions in
`native_graphics_memory`. The wrapper and its 32-function matrix owner remain
instruction-identical under Original-IDO. Native floating-point contraction is
disabled for these routines.

The eight original segment-3 render-mode banks are now native C graphics tables,
with their unused zero padding omitted. Depth mode, opaque/translucent selection,
the original default custom banks, custom overrides and their persistence across
render-state resets are preserved. `native_model_modes` compares all 539 packets
from these banks, texture-mode lists and restoration list against the original
checked-in data. Its archive run resolves 222,400 mode references across the eight
banks and all 1,145 models. These checks pass in Debug and Release, and the full
Original-IDO ROM remains byte-equal. The complete model draw entry, fog/reflection
pass integration and visible rendering still remain to be implemented.

The full `1EAC200.c` fog owner now compiles with typed configuration/state and
host-width world-cell/cache pointers. It retains both original map presets,
view-dependent slot selection, perspective fog factors, signed factor clamps,
MIPS invalid-conversion results, and once-per-reset fog-color packets. Its
height-layer cache uses the real world grid and static-prop pools, preserves
16-bit accumulation, supports repeated rebuilding/cleanup, and rejects grid
dimensions that would address outside the cell allocation.

`native_fog` checks exact factor/color packets, both slots, clipping and invalid
conversion cases, map selection, caching, cleanup, and real prop insertion/removal.
The cube/world archive tests also build and verify the layer cache on all 226
current and nine legacy world files. Debug with fatal UndefinedBehaviorSanitizer
and Release both pass, as do all 52 tests. World-grid defragmentation now calls
the actual fog-cache routine. The two genuinely empty original prop lifecycle
hooks are shared through `1EC3810_prop_hooks.inc`; their previous test copies
have been removed. All ten fog-owner and 31 world-owner Original-IDO functions
remain instruction-identical, and both full ROM comparisons pass.

The map/view helpers are shared with the original wrappers. The full current-view
wrapper still references the real, unported player/camera-manager queries; the
fog tests select its visibility input at the helper boundary instead of supplying
replacement game queries. This does not yet prove frame integration or visible
fog. Packet callers must provide room for one command, as in the original API.

The eight-function reflection owner (`1E95F80.c`) now compiles with host-width
buffers and a typed graphics context. Its three original map configurations
produce the original floating/fixed reflection matrices. The original water
height accessors and face-culling packet helpers are shared from their owners
through C includes; segment-7 front/back lists retain the original packet words.
The five camera-manager culling wrappers now link and execute the real reflection
transform and activation checks.

The begin-pass path registers both 3,000-packet buffers, mirror matrix and
projection-restoration lists, reserves a terminator slot, and switches the camera
to segment-8 projection restoration. It rejects nested recording and missing
graphics mappings. Cleanup during recording restores the original graphics and
matrix cursors. Storage must remain alive until submitted graphics have finished.
The end-pass body retains the original mirrored/normal replay order, face culling,
surface bounds and original model-draw call. That call is still an unresolved
native integration dependency: `func_800BC948` is not exercised or claimed to be
linked until `func_800DE498` is implemented. No substitute draw function is used.

`native_reflection` checks reflection/involution, water-height behavior, 375
camera query positions, float/short boxes, points, spheres, buffer switching,
failure/cleanup and registered culling/matrix packets. Its original-archive run
confirms that all 356 vertices of the three reflection-surface models lie on
their configured planes and remain fixed by reflection. Debug with fatal
UndefinedBehaviorSanitizer and Release pass all 53 tests. All 42 Original-IDO
functions in the three touched owners retain identical instructions; both full
ROM comparisons pass. Full reflection-pass execution and visible rendering remain
pending the native model-draw integration.

To also check the animations from your locally extracted ROM asset archive:

```sh
python3 pc/native/tests/animation_archive.py assets/assets.bin \
    build/native/native/bt_native_animation_resource_test
```

This check extracts resources to a temporary directory and removes them afterward.
The ordinary CTest suite does not require a ROM or include game assets.

To exercise native archive I/O, decompression and the game's reference cache
against the same animation assets:

```sh
build/native/native/bt_native_assets_test assets/assets.bin
build/native/native/bt_native_database_test assets/assets.bin
build/native/native/bt_native_asset_cache_test assets/assets.bin
build/native/native/bt_native_path_test assets/assets.bin
build/native/native/bt_native_path_motion_test assets/assets.bin
build/native/native/bt_native_actor_factory_test assets/assets.bin
build/native/native/bt_native_gsfile_test assets/assets.bin
build/native/native/bt_native_cube_test assets/assets.bin
build/native/native/bt_native_camera_db_test assets/assets.bin
build/native/native/bt_native_model_test assets/assets.bin
build/native/native/bt_native_map_sections_test assets/assets.bin --archive
build/native/native/bt_native_collision_geometry_test assets/assets.bin
build/native/native/bt_native_world_collision_test assets/assets.bin --archive
build/native/native/bt_native_actor_model_test assets/assets.bin --archive
build/native/native/bt_native_actor_lifecycle_test assets/assets.bin --archive
build/native/native/bt_native_skinning_test assets/assets.bin
build/native/native/bt_native_skeleton_test assets/assets.bin
build/native/native/bt_native_graphics_memory_test assets/assets.bin
build/native/native/bt_native_geometry_test assets/assets.bin
build/native/native/bt_native_textures_test assets/assets.bin
build/native/native/bt_native_point_lighting_test assets/assets.bin
build/native/native/bt_native_model_modes_test assets/assets.bin
build/native/native/bt_native_reflection_test assets/assets.bin
```

`pc/setup.sh` configures this same source build. The earlier recompilation
prototype remains accessible explicitly through `pc/setup.sh --legacy-recomp`.

To compile every game C translation unit and expose outstanding porting errors:

```sh
cmake --build build/native --target bt_native_all_sources --parallel
```

That target currently fails. It is excluded from the default core-test build;
it never filters out failing source files or substitutes stubs. Compiling an
object alone does not prove that its declarations, data layouts or behavior are
correct on the host. The latest full-source syntax audit (2026-11-05) accepts
352 of 1,114 translation units with the native compiler's strict pointer and
declaration checks. The other 762 still fail; this count is neither linked-game
coverage nor a gameplay completion percentage.

## Porting boundaries

- `BT_NATIVE` selects host `uintptr_t` and fixed-width N64 scalar types. Turning
  `s32` into a pointer-sized integer globally would corrupt game data and is not
  a valid fix for pointer truncation.
- The platform heap implements native allocations and indexed handles. Host
  allocations do not require the N64 heap's moving defragmenter.
- The original C memory routines are compiled directly, including their existing
  alignment and length preconditions. The aligned routines must receive lengths
  divisible by their word size.
- The vector insertion fix refreshes a handle-backed pointer after a possible
  reallocation only in the native build. The IDO path retains its original code.
- ROM byte order, serialized pointers, bitfields and offsets must be handled
  where resources are decoded. Host structures cannot be populated by copying
  the original ROM bytes into them.

## Remaining integration work

1. Correct cross-module function declarations and pointer-valued fields in the
   game sources. The compiler rejects missing declarations and pointer/integer
   conversions. Address-based variable names do not imply a valid host address.
   The input/key header-guard collision and the missing return of
   `bakey_func_80091940` have been corrected. Other apparent C procedures may also
   rely on preserved MIPS argument or return registers and need explicit data flow.
2. Replace assembler-defined globals with typed native definitions and convert
   ROM data into those structures; implement the remaining assembler helpers.
3. Finish native overlay tables and lifecycle handling. Direct syscall-name to
   C-function binding is implemented, but incompatible declarations and references
   that treat code addresses as data still require correction.
4. Implement the game's OS/thread/message/timing, input and save interfaces, then
   connect the game entrypoint. Hardware-register accesses and boot/security code
   require explicit platform decisions.
5. Connect display-list rendering and audio to the native game and decoded
   resources, and verify gameplay, transitions and saves.

The N64 matching build remains independently checked with Original-IDO,
`make complete`, and full byte comparisons of both ROM forms. Passing the native
core tests does not establish full-game correctness or completion of this list.
Header changes require recompiling their consumers: the current N64 Makefile does
not track all C header dependencies. The input changes were verified by forcing
all game C sources to rebuild with Make's `-W` option before `make complete`.
