FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential git ca-certificates wget python3 python3-pip \
    gcc-mips-linux-gnu binutils-mips-linux-gnu libfmt-dev zlib1g-dev \
    && rm -rf /var/lib/apt/lists/*
RUN python3 -m pip install --no-cache-dir \
    spimdisasm==1.35.0 'mapfile-parser>=2.4,<3' toml pyyaml \
    colorama pylibyaml n64img intervaltree ansiwrap watchdog python-Levenshtein \
    tqdm pygfxd cxxfilt
WORKDIR /work
