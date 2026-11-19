// GLSL 3.30 for the GPU renderer (rdp_gl.h). The fragment shader is rdp.c's pixel pipeline in
// integer math: TMEM texels come from the texture atlas (decoded by decode_texel), wrap/mirror/clamp,
// bilinear weights, LOD, combiner and alpha/coverage discards as in sample() and pixel(). Only the
// part of the blender that reads memory is left to fixed-function blending: the shader outputs the
// term without memory and, as the second (dual-source) color, the factor memory is multiplied by.
// color16 (scale 1): every write snaps to RGBA5551 like the N64 framebuffer, and blends that read memory
// (rmw) run here against the target itself, so they round like rdp.c; above 1x the targets keep 8 bits.
// shortcut: noise is a per-pixel hash and, above 1x, a first blender cycle that reads memory is skipped;
// both differ from the software LCG/pipeline, upgrade when a scene visibly depends on them.
static const char gpu_vertex_shader[] =
"#version 330\n"
"layout(location=0) in vec4 pos; layout(location=1) in vec4 shade; layout(location=2) in vec2 st;\n"
"layout(location=3) in uint mat;\n"
"noperspective out vec4 v_shade; smooth out vec2 v_stp; noperspective out vec2 v_stl; flat out uint v_mat;\n"
"void main(){ gl_Position=pos; v_shade=shade; v_stp=st; v_stl=st; v_mat=mat; }\n";

static const char gpu_fragment_shader[] =
"#version 330\n"
"uniform usampler2D atlas; uniform usamplerBuffer mats; uniform vec2 scale; uniform uint frame; uniform bool color16,rmw;\n"
"uniform sampler2D modtex0,modtex1,modtex2,modtex3,modtex4,modtex5,modtex6,modtex7;\n"
"uniform sampler2D dst,silhouette; uniform bool soften;\n"
"noperspective in vec4 v_shade; smooth in vec2 v_stp; noperspective in vec2 v_stl; flat in uint v_mat;\n"
"layout(location=0,index=0) out vec4 o_color; layout(location=0,index=1) out vec4 o_factor;\n"
"int base;\n"
"ivec4 S_comb=ivec4(0),S_t0=ivec4(0),S_t1=ivec4(0),S_prim,S_shade,S_env; int S_noise,S_k4,S_k5,S_lod=0,S_plod,S_seam=0;\n"
"ivec4 unpack(uint c){return ivec4(int(c>>24),int((c>>16)&255u),int((c>>8)&255u),int(c&255u));}\n"
"ivec4 rgba16(uint v){ivec3 c=ivec3(int((v>>11)&31u),int((v>>6)&31u),int((v>>1)&31u));return ivec4((c<<3)|(c>>2),(v&1u)!=0u?255:0);}\n"
"ivec3 q5(ivec3 c){if(!color16)return c;c>>=3;return (c<<3)|(c>>2);}\n"
"ivec4 texel(int slot,int s,int t){uvec4 a=texelFetch(mats,base+4+slot*2),b=texelFetch(mats,base+5+slot*2);int w=int(a.y&65535u),h=int(a.y>>16);\n"
" if(w==0)return ivec4(0);if(b.w!=0u){ivec2 p=clamp(ivec2(s,t),ivec2(0),ivec2(w-1,h-1));vec4 c=slot==0?texelFetch(modtex0,p,0):slot==1?texelFetch(modtex1,p,0):slot==2?texelFetch(modtex2,p,0):slot==3?texelFetch(modtex3,p,0):slot==4?texelFetch(modtex4,p,0):slot==5?texelFetch(modtex5,p,0):slot==6?texelFetch(modtex6,p,0):texelFetch(modtex7,p,0);return ivec4(round(c*255.0));}return ivec4(texelFetch(atlas,ivec2(int(a.x&65535u)+clamp(s,-S_seam,w-1+S_seam),int(a.x>>16)+clamp(t,-S_seam,h-1+S_seam)),0));}\n"
"int wrapc(int c,int cm,int mask,int mx,int factor){if(factor>1){\n"
" if((cm&2)!=0||mask==0)c=clamp(c,0,max((mx+1)*factor-1,0));\n"
" if(mask==0)return c;int width=(1<<mask)*factor,period=(cm&1)!=0?2*width:width;\n"
" c=c<0?period-1-(~c)%period:c%period;return c<width?c:period-1-c;}\n"
" if((cm&2)!=0||mask==0)c=c<0?0:(c>mx?mx:c);\n"
" if(mask!=0){if((cm&1)!=0&&((c>>mask)&1)!=0)c=~c;c&=(1<<mask)-1;}return c;}\n"
"float shifted(float v,int sh){return sh==0?v:sh<11?v/float(1<<sh):v*float(1<<(16-sh));}\n"
"ivec4 sample_tile(int slot,vec2 st,bool filt){\n"
" uvec4 a=texelFetch(mats,base+4+slot*2),b=texelFetch(mats,base+5+slot*2);\n"
" int uls=int(a.z&65535u),ult=int(a.z>>16),lrs=int(a.w&65535u),lrt=int(a.w>>16);\n"
" int cms=int(b.x&3u),cmt=int((b.x>>2)&3u),masks=int((b.x>>4)&15u),maskt=int((b.x>>8)&15u);\n"
" int ms=(lrs-uls)>>2,mt=(lrt-ult)>>2;\n"
" float s=shifted(st.x,int((b.x>>12)&15u))-float(uls)*0.25,t=shifted(st.y,int((b.x>>16)&15u))-float(ult)*0.25;\n"
" int factor=max(int(b.z),1);s*=float(factor);t*=float(factor);\n"
// Original CI8 clear alternates FF and FE. The projected model writes black.
" if((b.y&2u)!=0u){bool inside=texelFetch(silhouette,ivec2(gl_FragCoord.xy),0).r>0.5;\n"
" return ivec4(inside?0:255-(int(floor(st.x))&1));}\n"
// Interpolation may undershoot an integer texel. Preserve genuine 1/32-texel steps.
" if(!filt){if(!soften||scale.y<2){float ns=round(s),nt=round(t),"
"es=min(4.0e-6*max(1.0,abs(s)),1.0/64.0),et=min(4.0e-6*max(1.0,abs(t)),1.0/64.0);"
"if(abs(s-ns)<=es)s=ns;if(abs(t-nt)<=et)t=nt;\n"
"  int s0=int(floor(s)),t0=int(floor(t)),sc=wrapc(s0,cms,masks,ms,factor),tc=wrapc(t0,cmt,maskt,mt,factor);return texel(slot,sc,tc);\n"
" }\n"
// soften: unfiltered texels (text, HUD) above 1x are interpolated with Catmull-Rom over alpha-weighted
// color, so 4x4 blocks become smooth, still sharp glyph edges; transparent texels add no color.
"  float u=s-0.5,v=t-0.5,iu=floor(u),iv=floor(v);vec2 f=vec2(u-iu,v-iv);\n"
"  vec2 w0=f*(-0.5+f*(1.0-0.5*f)),w1=1.0+f*f*(-2.5+1.5*f),w2=f*(0.5+f*(2.0-1.5*f)),w3=f*f*(-0.5+0.5*f);\n"
"  vec4 sum=vec4(0.0);for(int j=0;j<4;j++){int tt=wrapc(int(iv)-1+j,cmt,maskt,mt,factor);float wy=j==0?w0.y:j==1?w1.y:j==2?w2.y:w3.y;\n"
"   for(int i=0;i<4;i++){vec4 c=vec4(texel(slot,wrapc(int(iu)-1+i,cms,masks,ms,factor),tt));\n"
"    sum+=vec4(c.rgb*c.a,c.a)*(wy*(i==0?w0.x:i==1?w1.x:i==2?w2.x:w3.x));}}\n"
"  float al=clamp(sum.a,0.0,255.0);return al<0.5?ivec4(0):ivec4(clamp(round(sum.rgb/sum.a),0.0,255.0),round(al));}\n"
" float fs=floor(s),ft=floor(t);int s0=int(fs),t0=int(ft);\n"
" int sa=wrapc(s0,cms,masks,ms,factor),sb=wrapc(s0+1,cms,masks,ms,factor),ta=wrapc(t0,cmt,maskt,mt,factor),tb=wrapc(t0+1,cmt,maskt,mt,factor);\n"
" if((b.y&1u)!=0u){S_seam=1;if(s0==-1)sa=-1;if(s0==ms)sb=ms+1;if(t0==-1)ta=-1;if(t0==mt)tb=mt+1;}\n"  // gpu_seams border
" ivec4 c0=texel(slot,sa,ta),c1=texel(slot,sb,ta),c2=texel(slot,sa,tb),c3=texel(slot,sb,tb);S_seam=0;\n"
" int wx=int((s-fs)*256.0),wy=int((t-ft)*256.0);\n"
" ivec4 top=c0*256+(c1-c0)*wx,bot=c2*256+(c3-c2)*wx;return (top*256+(bot-top)*wy)>>16;}\n"
"ivec4 src(int id){switch(id){\n"
" case 0:return S_comb;case 1:return S_t0;case 2:return S_t1;case 3:return S_prim;case 4:return S_shade;\n"
" case 5:return S_env;case 6:return ivec4(256);case 8:return ivec4(S_noise);case 11:return ivec4(S_k4);\n"
" case 12:return ivec4(S_k5);case 13:return ivec4(S_comb.a);case 14:return ivec4(S_t0.a);case 15:return ivec4(S_t1.a);\n"
" case 16:return ivec4(S_prim.a);case 17:return ivec4(S_shade.a);case 18:return ivec4(S_env.a);\n"
" case 19:return ivec4(S_lod);case 20:return ivec4(S_plod);}return ivec4(0);}\n"
"ivec4 combine(uint c,uint a){\n"
" ivec3 ca=src(int(c>>24)).rgb,cb=src(int((c>>16)&255u)).rgb,cc=src(int((c>>8)&255u)).rgb,cd=src(int(c&255u)).rgb;\n"
" int aa=src(int(a>>24)).a,ab=src(int((a>>16)&255u)).a,ac=src(int((a>>8)&255u)).a,ad=src(int(a&255u)).a;\n"
" return ivec4(clamp((((ca-cb)*cc+0x80)>>8)+cd,ivec3(0),ivec3(255)),clamp((((aa-ab)*ac+0x80)>>8)+ad,0,255));}\n"
"ivec3 bld(int bl,int sh,ivec4 c,ivec3 mem,ivec4 fog,ivec4 bc,int sa){\n"
" int ps=(bl>>(12+sh))&3,as=(bl>>(8+sh))&3,ms=(bl>>(4+sh))&3,bs=(bl>>sh)&3;\n"
" ivec3 P=ps==0?c.rgb:ps==1?mem:ps==2?bc.rgb:fog.rgb,M=ms==0?c.rgb:ms==1?mem:ms==2?bc.rgb:fog.rgb;\n"
" int A=as==0?c.a:as==1?fog.a:as==2?sa:0,B=bs==0?255-A:bs==3?0:255;\n"
" return clamp((P*A+M*B)/255,ivec3(0),ivec3(255));}\n"
"void main(){\n"
" vec2 dpx=dFdx(v_stp),dpy=dFdy(v_stp),dlx=dFdx(v_stl),dly=dFdy(v_stl);\n"
" base=int(v_mat);\n"
" uvec4 h0=texelFetch(mats,base),h1=texelFetch(mats,base+1),h2=texelFetch(mats,base+2),h3=texelFetch(mats,base+3);\n"
"#ifdef BT_MATERIAL\n h0=BT_H0;h1.xy=BT_H1;\n#endif\n"
" uint omh=h0.x,oml=h0.y,flags=h1.z;int mode=int(flags&7u);ivec2 px=ivec2(gl_FragCoord.xy);\n"
" if(mode==4){uint f=h3.x,v=(int((float(px.x)+0.5)/scale.x)&1)!=0?(f&65535u):(f>>16);ivec4 c=rgba16(v);\n"
"  o_color=vec4(vec3(c.rgb)/255.0,float(v&1u));o_factor=vec4(0.0);return;}\n"
" S_prim=unpack(h2.x);S_env=unpack(h2.y);ivec4 fog=unpack(h2.z),blendc=unpack(h2.w);\n"
" S_plod=int(h1.w&255u);S_k4=int((h1.w>>8)&511u);S_k5=int((h1.w>>17)&511u);\n"
" S_shade=mode==0?ivec4(clamp(v_shade,0.0,255.0)):ivec4(0);\n"
" bool cyc2=(flags&128u)!=0u,use0=(flags&256u)!=0u,use1=(flags&512u)!=0u,filt=(flags&32u)!=0u;\n"
" if((flags&8u)!=0u){\n"
"  bool persp=(flags&16u)!=0u;vec2 st=(persp?v_stp:v_stl)/32.0,dx=(persp?dpx:dlx)/32.0,dy=(persp?dpy:dly)/32.0;\n"
"  int t0i=0,t1i=1,levels=int(h3.w),last=max(int(h3.z)-1,0);\n"
"  if((flags&64u)!=0u){float l=max(max(abs(dx.x),abs(dx.y)),max(abs(dy.x),abs(dy.y)));\n"
"   if(l>=1.0){int lv=int(log2(l));if(lv>=levels){lv=levels;S_lod=255;}else S_lod=clamp(int((l/float(1<<lv)-1.0)*256.0),0,255);\n"
"    t0i=lv;t1i=lv<levels?lv+1:lv;}}\n"
"  t0i=min(t0i,last);t1i=min(t1i,last);\n"
"  if(mode==3){ivec4 c=sample_tile(0,st,false);if((oml&1u)!=0u&&c.a==0)discard;\n"
"   o_color=vec4(vec3(q5(c.rgb))/255.0,1.0);o_factor=vec4(0.0);return;}\n"
"  if(use0||(use1&&!cyc2))S_t0=sample_tile(t0i,st,filt);\n"
"  if(use1)S_t1=cyc2?sample_tile(t1i,st,filt):S_t0;}\n"
" uint h=uint(px.x)*0x9E3779B1u^uint(px.y)*0x85EBCA77u^frame*0xC2B2AE3Du;h^=h>>15;h*=0x2C1B3C6Du;h^=h>>12;\n"
" S_noise=int(h>>24);\n"
" ivec4 c;if(cyc2){S_comb=combine(h0.z,h1.x);c=combine(h0.w,h1.y);}else c=combine(h0.w,h1.y);\n"
" if((oml&3u)==1u&&c.a<blendc.a)discard;\n"
" if((oml&0x2000u)!=0u&&(oml&0x4000u)==0u&&c.a<((oml&0x1000u)!=0u?128:8))discard;\n"
" int bl=int(oml>>16);\n"
" if(rmw){ivec3 mem=ivec3(round(texelFetch(dst,px,0).rgb*255.0)),r;int s1=cyc2?0:2;\n"
"  if(cyc2)c.rgb=bld(bl,2,c,mem,fog,blendc,S_shade.a);\n"
"  if((oml&0x4000u)!=0u)r=bld(bl,s1,c,mem,fog,blendc,S_shade.a);\n"
"  else{int ps=(bl>>(12+s1))&3;r=ps==0?c.rgb:ps==1?mem:ps==2?blendc.rgb:fog.rgb;}\n"
"  o_color=vec4(vec3(q5(r))/255.0,1.0);o_factor=vec4(0.0);return;}\n"
" if(cyc2){int ps=(bl>>14)&3,as=(bl>>10)&3,ms=(bl>>6)&3,bs=(bl>>2)&3;\n"
"  if(ps!=1&&ms!=1){ivec3 P=ps==0?c.rgb:ps==2?blendc.rgb:fog.rgb,M=ms==0?c.rgb:ms==2?blendc.rgb:fog.rgb;\n"
"   int A=as==0?c.a:as==1?fog.a:as==2?S_shade.a:0,B=bs==0?255-A:bs==3?0:255;\n"
"   c.rgb=clamp((P*A+M*B)/255,ivec3(0),ivec3(255));}}\n"
" int sh=cyc2?0:2,ps=(bl>>(12+sh))&3,as=(bl>>(8+sh))&3,ms=(bl>>(4+sh))&3,bs=(bl>>sh)&3;\n"
" ivec3 P=ps==0?c.rgb:ps==2?blendc.rgb:fog.rgb,M=ms==0?c.rgb:ms==2?blendc.rgb:fog.rgb;\n"
" vec3 rgb;float factor;\n"
" if((oml&0x4000u)!=0u){int A=as==0?c.a:as==1?fog.a:as==2?S_shade.a:0,B=bs==0?255-A:bs==3?0:255;\n"
"  if(ps!=1&&ms!=1){rgb=vec3(q5(clamp((P*A+M*B)/255,ivec3(0),ivec3(255))));factor=0.0;}\n"
"  else if(ps!=1){rgb=vec3(P*A)/255.0;factor=float(B)/255.0;}\n"
"  else if(ms!=1){rgb=vec3(M*B)/255.0;factor=float(A)/255.0;}\n"
"  else{rgb=vec3(0.0);factor=min(float(A+B)/255.0,1.0);}}\n"
" else if(ps==1){rgb=vec3(0.0);factor=1.0;}\n"
" else{rgb=vec3(q5(P));factor=0.0;}\n"
" o_color=vec4(rgb/255.0,1.0);o_factor=vec4(factor);}\n";

// Deferred fragments of the 8-bit image (rdp.c mask_frag), one point each in draw order: rdp.c's depth
// test against N64 depth (mz, RDRAM bytes) in its integer math, then the byte. a: x | y << 16, z, zdz,
// value | ztest << 8 (1 test, 2 test without write) | decal << 10.
static const char gpu_maskfrag_vertex_shader[] =
"#version 330\n"
"layout(location=0) in uvec4 a;uniform ivec2 size;flat out uvec4 v;\n"
"void main(){vec2 p=(vec2(float(a.x&65535u),float(a.x>>16))+0.5)*2.0/vec2(size)-1.0;gl_Position=vec4(p,0.0,1.0);v=a;}\n";
static const char gpu_maskfrag_shader[] =
"#version 330\n"
"uniform usampler2D mz;flat in uvec4 v;out vec4 o_color;\n"
"const uint ZS[8]=uint[8](6u,5u,4u,3u,2u,1u,0u,0u),ZB[8]=uint[8](0u,0x20000u,0x30000u,0x38000u,0x3C000u,0x3E000u,0x3F000u,0x3F800u);\n"
"uint zc(uint z){uint e=z<0x20000u?0u:z<0x30000u?1u:z<0x38000u?2u:z<0x3C000u?3u:z<0x3E000u?4u:z<0x3F000u?5u:z<0x3F800u?6u:7u;\n"
" return (e<<11)|(((z-ZB[e])>>ZS[e])&0x7FFu);}\n"
"uint zd(uint c){uint e=(c>>11)&7u;return ZB[e]+((c&0x7FFu)<<ZS[e]);}\n"
"void main(){uint t=(v.w>>8)&3u;\n"
" if(t!=0u){uvec2 m=texelFetch(mz,ivec2(gl_FragCoord.xy),0).rg;uint oz=zd(((m.r<<8)|m.g)>>2),cz=zc(v.y),zq=zd(cz),tol=v.z+(1u<<ZS[cz>>11])*2u;\n"
"  bool pass=(v.w&1024u)!=0u?zq<=oz+tol&&zq+tol>=oz:zq<=oz;\n"
"  if(!pass||t==2u)discard;}\n"
" o_color=vec4(float(v.w&255u)/255.0);}\n";

// A load from the 8-bit image: its texels into the atlas as decode_texel makes them (I8, or IA8 with ia).
static const char gpu_shadow_vertex_shader[] =
"#version 330\nlayout(location=0) in vec4 v; uniform vec2 viewport; noperspective out float z;flat out float dz;\n"
"void main(){gl_Position=vec4(v.xy*2.0/viewport-1.0,0.0,1.0);z=v.z;dz=v.w;}\n";
static const char gpu_shadow_fragment_shader[] =
"#version 330\nuniform sampler2D scene;noperspective in float z;flat in float dz;out float mask;\n"
"const uint shifts[8]=uint[8](6u,5u,4u,3u,2u,1u,0u,0u);\n"
"const uint bases[8]=uint[8](0u,0x20000u,0x30000u,0x38000u,0x3C000u,0x3E000u,0x3F000u,0x3F800u);\n"
"uint expz(uint a){return a<0x20000u?0u:a<0x30000u?1u:a<0x38000u?2u:a<0x3c000u?3u:a<0x3e000u?4u:a<0x3f000u?5u:a<0x3f800u?6u:7u;}\n"
"uint quant(uint a,uint e){return bases[e]+(((a-bases[e])>>shifts[e])<<shifts[e]);}\n"
"void main(){uint v=uint(clamp(z,0.,262143.)); uint d=uint(clamp(texelFetch(scene,ivec2(gl_FragCoord.xy),0).r*262144.,0.,262143.));\n"
"uint e=expz(v),q=quant(v,e),o=quant(d,expz(d)),tol=uint(dz)+(2u<<shifts[e]);if(q>o+tol||o>q+tol)discard;mask=1.;}\n";

static const char gpu_maskcopy_shader[] =
"#version 330\n"
"uniform sampler2D image;uniform ivec2 off;uniform bool ia;out uvec4 o_value;\n"
"void main(){uint v=uint(round(texelFetch(image,ivec2(gl_FragCoord.xy)+off,0).r*255.0));\n"
" if(ia){uint i=(v>>4)*17u;o_value=uvec4(i,i,i,(v&15u)*17u);}else o_value=uvec4(v);}\n";

// Full-screen passes: a triangle over the viewport, no vertex data.
static const char gpu_fullscreen_shader[] =
"#version 330\n"
"void main(){vec2 p=vec2((gl_VertexID<<1)&2,gl_VertexID&2);gl_Position=vec4(p*2.0-1.0,0.0,1.0);}\n";

// CPU writes: pixels whose RDRAM value differs from the last resolve replace their subpixels.
static const char gpu_import_shader[] =
"#version 330\n"
"uniform usampler2D image,shadow;uniform vec2 scale;uniform int every;uniform bool isDepth;\n"
"layout(location=0,index=0) out vec4 o_color;layout(location=0,index=1) out vec4 o_factor;\n"
"void main(){ivec2 p=ivec2(gl_FragCoord.xy/scale);uvec2 a=texelFetch(image,p,0).rg,b=texelFetch(shadow,p,0).rg;\n"
" if(every==0&&a==b)discard;uint v=(a.r<<8)|a.g;gl_FragDepth=0.0;\n"
" if(isDepth){const uint shifts[8]=uint[8](6u,5u,4u,3u,2u,1u,0u,0u);\n"
" const uint bases[8]=uint[8](0u,0x20000u,0x30000u,0x38000u,0x3C000u,0x3E000u,0x3F000u,0x3F800u);\n"
" uint code=v>>2,e=code>>11,z=bases[e]+(((code&2047u)+1u)<<shifts[e])-1u;\n"
" gl_FragDepth=(float(z)+0.5)/262144.0;return;}ivec3 c=ivec3(int((v>>11)&31u),int((v>>6)&31u),int((v>>1)&31u));\n"
" o_color=vec4(vec3((c<<3)|(c>>2))/255.0,float(v&1u));o_factor=vec4(0.0);}\n";

// N64-resolution depth as RDRAM bytes (the game reads Z memory with the CPU): subpixel depths are
// compressed like the RDP stores them, averaged and compressed again like rdp.c's resolve.
static const char gpu_zresolve_shader[] =
"#version 330\n"
"uniform sampler2D depth;uniform ivec2 scale;out uvec4 o_value;\n"
"const int ZS[8]=int[8](6,5,4,3,2,1,0,0),ZB[8]=int[8](0,0x20000,0x30000,0x38000,0x3C000,0x3E000,0x3F000,0x3F800);\n"
"int zc(int z){int e=z<0x20000?0:z<0x30000?1:z<0x38000?2:z<0x3C000?3:z<0x3E000?4:z<0x3F000?5:z<0x3F800?6:7;\n"
" return (e<<11)|(((z-ZB[e])>>ZS[e])&0x7FF);}\n"
"int zd(int c){int e=(c>>11)&7;return ZB[e]+((c&0x7FF)<<ZS[e]);}\n"
"void main(){ivec2 cell=ivec2(gl_FragCoord.xy), sz=textureSize(depth,0), p=(2*cell*sz+scale-1)/(2*scale);ivec2 span=(2*(cell+1)*sz+scale-1)/(2*scale)-p;int n=span.x*span.y,avg=0,rem=0;\n"
" for(int y=0;y<span.y;y++){int row=0;for(int x=0;x<span.x;x++)\n"
"  row+=zd(zc(clamp(int(texelFetch(depth,p+ivec2(x,y),0).r*262144.0),0,0x3FFFF)));rem+=row%n;avg+=row/n+rem/n;rem%=n;}\n"
" uint v=uint(zc(avg))<<2;o_value=uvec4(v>>8,v&255u,0u,0u);}\n";

// N64-resolution image as RDRAM bytes: subpixels averaged in 5-bit units like rdp.c's resolve.
static const char gpu_resolve_shader[] =
"#version 330\n"
"uniform sampler2D color;uniform ivec2 scale;out uvec4 o_value;\n"
"void main(){ivec2 cell=ivec2(gl_FragCoord.xy), sz=textureSize(color,0), p=(2*cell*sz+scale-1)/(2*scale);ivec2 span=(2*(cell+1)*sz+scale-1)/(2*scale)-p;ivec3 sum=ivec3(0);int alpha=0;\n"
" for(int y=0;y<span.y;y++)for(int x=0;x<span.x;x++){vec4 c=texelFetch(color,p+ivec2(x,y),0);\n"
"  sum+=ivec3(round(c.rgb*255.0))>>3;alpha+=c.a>=0.5?1:0;}\n"
" int n=span.x*span.y;ivec3 q=sum/n;\n"
" uint v=(uint(q.r)<<11)|(uint(q.g)<<6)|(uint(q.b)<<1)|(alpha*2>=n?1u:0u);o_value=uvec4(v>>8,v&255u,0u,0u);}\n";
