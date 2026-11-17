Generated with glad2 2.0.8 and its bundled Khronos specification:

```sh
python3 -m glad --quiet --reproducible --api gl:core=4.1 \
  --extensions GL_ARB_texture_barrier,GL_NV_texture_barrier --out-path build/glad-preview c
```

`src/gl.c` and `include/glad/gl.h` are copied here unchanged;
`include/KHR/khrplatform.h` is copied to `host/KHR/`.
SDL supplies procedure addresses; no glad platform loader is generated.
The generator is only needed to regenerate these files, not to build the port.
