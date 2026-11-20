#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func_80800144_scinfobar(uint8_t *, int32_t);
void scinfobar_entrypoint_3(void *, int32_t);
void scinfobar_entrypoint_24(intptr_t, void *, int32_t, int32_t);
static void *display;
static char text[24];
static int letters, icons, backdrop, style, asset, x = 42, y = 27;
static int32_t image;
static void require(int test) { if (!test) abort(); }
int32_t func_800CF6D0(void) { return 5; }
int16_t func_800CF6B0(void) { return 2; }
void fxdialog_entrypoint_0(void) {}
void fxdialog_entrypoint_1(int32_t left, int32_t top) { require(left == x && top == y); }
void fxdialog_entrypoint_2(float scale) { require(scale > 0 && scale < 1); }
void *fxdialog_entrypoint_3(intptr_t dl, float width, int32_t side, int32_t alpha) {
    require((void *)dl == display && width >= 0 && side == 0 && alpha == 255);
    ++backdrop; return display;
}
void fxdialog_entrypoint_4(void) { abort(); }
int32_t func_800E8C58(uint8_t handle) { abort(); }
int32_t func_8001211C(void) { return 0; }
void func_800B7F14(void *dl) { require(dl == display); }
void func_800B811C(void *dl) { require(dl == display); }
void func_800B8C50(void) {}
void func_800B8C8C(int32_t alpha) { require(alpha >= 0 && alpha <= 255); }
void func_800B8C98(int32_t font) { require(font == 1); }
void func_800B8CBC(int8_t r, int8_t g, int8_t b) {}
void func_800B8CE0(int32_t color) { require(color == 0xC26); }
void func_800B8DEC(void *dl, int32_t xx, int32_t yy, uint8_t ch) {
    require(dl == display && xx >= x && yy == y && letters < (int)sizeof(text) - 1);
    text[letters++] = ch;
}
void *func_800D674C(int32_t id) { asset = id; return &image; }
void func_800E24F8(int32_t r, int32_t g, int32_t b) {}
void func_800E253C(float scale) { require(scale > 0 && scale < 1); }
void func_800E257C(int32_t alpha) { require(alpha >= 0 && alpha <= 255); }
void func_800E30E0(intptr_t dl, void *im, int32_t mode, int32_t *pos) {
    require((void *)dl == display && im == &image && mode == 0 && pos[0] >= 4*x && pos[1] >= 4*y);
    require(asset == (style == 3 ? 0x9da : 0xb4d)); ++icons;
}
uint8_t func_800E8B74(uint32_t id) { abort(); }
void func_800E8C08(uint8_t handle) { abort(); }
void func_800E8D28(uint8_t handle, float scale) { abort(); }
void func_800E8D5C(uint8_t handle, void *data, int16_t slot) { abort(); }

int main(void) {
    const int16_t widths[] = {35,43,52,78,73,45,77,52,49};
    const char *const strings[] = {"24","3/24","","","24:00:0","24","3/24","","STOL"};
    const int counts[] = {0,0,3,5,0,0,0,3,0};
    uint8_t *hud = calloc(1, 0x34);
    display = malloc(sizeof(void *));
    require(hud && display);
    if (sizeof(void *) > 4) require((uintptr_t)hud > UINT32_MAX && (uintptr_t)display > UINT32_MAX);
    for (style=0; style<9; ++style) {
        int32_t current=style==8?999:42, total=3;
        int16_t measured;
        memset(hud,0,0x34); memset(text,0,sizeof(text));
        letters=icons=backdrop=0; hud[0]=0x64;
        memcpy(hud+0x20,&current,4); memcpy(hud+0x24,&total,4);
        scinfobar_entrypoint_3(hud,style);
        func_80800144_scinfobar(hud,0x65);
        memcpy(&measured,hud+8,2);
        float open=1.0f; memcpy(hud+0x14,&open,sizeof open);
        scinfobar_entrypoint_24((intptr_t)display,hud,x,y);
        if (backdrop!=1 || measured!=widths[style] || icons!=counts[style] || strcmp(text,strings[style])) {
            fprintf(stderr,"HUD style %d: width %d, icons %d, letters '%s', backdrop %d\n",style,measured,icons,text,backdrop);
            return 1;
        }
    }
    free(display);free(hud);
    return 0;
}
