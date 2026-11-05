#!/bin/sh
# Configures the direct C source port. --legacy-recomp selects the earlier prototype.
set -e
cd "$(dirname "$0")"

if [ "$#" -eq 0 ]; then
    cmake -S . -B ../build/native -DBT_LEGACY_RECOMP=OFF -DCMAKE_BUILD_TYPE=Debug
    echo "Build: cmake --build ../build/native"
    echo "Test: ctest --test-dir ../build/native --output-on-failure"
    exit 0
fi
if [ "$#" -ne 1 ] || [ "$1" != "--legacy-recomp" ]; then
    echo "Usage: $0 [--legacy-recomp]" >&2
    exit 2
fi

fetch() { # dir url commit
    if [ ! -e "lib/$1/CMakeLists.txt" ]; then
        git clone "$2" "lib/$1"
        git -C "lib/$1" checkout "$3"
        git -C "lib/$1" submodule update --init --recursive --depth 1
    fi
}

fetch N64ModernRuntime https://github.com/N64Recomp/N64ModernRuntime ca568b6ad79b9029d14077f0c3ffa757727c5559
fetch RecompFrontend https://github.com/N64Recomp/RecompFrontend d0d90ba49f46f4896aaeda362056c21b1e342561
fetch rt64 https://github.com/rt64/rt64 6f1c2d99a4ea571c139f449c326fd176ba8f3496

# rt64 runs its shader compiler through the shell, which breaks on paths with spaces.
sed -i.orig -E 's/(^|[^v] )"(DYLD_LIBRARY_PATH|LD_LIBRARY_PATH)=/\1${CMAKE_COMMAND} -E env "\2=/' lib/rt64/CMakeLists.txt

patch -N -p1 -d lib/N64ModernRuntime < runtime-patches/threadqueue.patch || true

TOOLS=lib/N64ModernRuntime/N64Recomp/build
cmake -S lib/N64ModernRuntime/N64Recomp -B "$TOOLS" -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build "$TOOLS" --target N64Recomp RSPRecomp

python3 tools/gen_overlay_list.py
python3 tools/fix_elf.py
"$TOOLS/N64Recomp" tooie.us.toml
mkdir -p rsp
"$TOOLS/RSPRecomp" n_aspMain.us.toml

cmake -S . -B build-cmake -G Ninja -DBT_LEGACY_RECOMP=ON -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
echo "Now run: cmake --build build-cmake --target BanjoTooieRecompiled"
