#include "common.h"

void func_80800000_chpotogoldgame(Actor *arg0) {
    s32 func_800D0A9C(u32, u32);
    s32 func_800D395C(void);
    s32 func_800DA298(s32);
    s32 func_80800434_chpotogoldgame(BtIntPtr, s32);
    void func_808011DC_chpotogoldgame(Actor *);
    void func_80801494_chpotogoldgame(Actor *, s32);
    void func_80801558_chpotogoldgame(Actor *);
    s32 func_80801A7C_chpotogoldgame(Actor *);

    func_808011DC_chpotogoldgame(arg0);
    arg0->unk64_20 = 0;
    if (func_800DA298(0x6B6) != 0) {
        func_80800434_chpotogoldgame((BtIntPtr)arg0, 0xF);
    } else if (func_800D0A9C(0x49, 1) != 0 || func_800D0A9C(0x17, 4) != 0 || func_800DA298(0x1DB) != 0 || func_800D395C() != 0) {
        ((f32 *)arg0->actorData)[0] = 2.0f;
        ((f32 *)arg0->actorData)[5] = 2.0f;
        ((f32 *)arg0->actorData)[4] = 2.0f;
        ((f32 *)arg0->actorData)[6] = 2.0f;
        ((f32 *)arg0->actorData)[1] = 2.0f;
        if (func_800D395C() != 0) {
            func_80800434_chpotogoldgame((BtIntPtr)arg0, 0xD);
        } else {
            func_80800434_chpotogoldgame((BtIntPtr)arg0, 4);
        }
    } else {
        ((f32 *)arg0->actorData)[0] = 0.0f;
        ((f32 *)arg0->actorData)[5] = 0.0f;
        ((f32 *)arg0->actorData)[4] = 0.0f;
        ((f32 *)arg0->actorData)[6] = 0.0f;
        ((f32 *)arg0->actorData)[1] = 0.0f;
    }
    func_80801A7C_chpotogoldgame(arg0);
    func_80801494_chpotogoldgame(arg0, 1);
    func_80801558_chpotogoldgame(arg0);
    arg0->actorData[7] = 0;
    _sueggmisc_entrypoint_3();
}

void func_80800124_chpotogoldgame(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    void func_800CE88C(s32, s32);
    s16 func_800CEA84(s32);
    s32 func_800D2498(u32, s32, u32);
    s32 func_800D395C(void);
    s32 func_800DA298(s32);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    void *func_80100094(Actor *, u32);
    void func_80108B04(Actor *, u32);
    s32 func_8010CB84(f32 *, s32);
    s32 func_80800434_chpotogoldgame(BtIntPtr, s32);
    void func_808011DC_chpotogoldgame(Actor *);
    void func_80801244_chpotogoldgame(Actor *);
    void func_808013BC_chpotogoldgame(Actor *, s32, s32, s32, s32, f32 *);
    void func_80801558_chpotogoldgame(Actor *);
    s32 func_80801A7C_chpotogoldgame(Actor *);
    s32 func_8080206C_chpotogoldgame(Actor *);
    struct GameState {
        u8 cells[5][4][5];
        u8 unk64;
        u8 unk65;
        u8 unk66;
    } *data;
    s32 i;
    s32 score;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
    case 1:
        func_80801A7C_chpotogoldgame(arg0);
        if (func_800DA298(0x9F6) && func_800DA298(0x9F7) &&
            func_800DA298(0x9F8) && func_800DA298(0x9F9)) {
            func_80800434_chpotogoldgame((BtIntPtr)arg0, 2);
        }
        break;
    case 2:
        if (func_80801A7C_chpotogoldgame(arg0)) {
            func_808013BC_chpotogoldgame(arg0, data->unk64, data->unk65, data->unk66, 0, NULL);
            if (++data->unk65 == 4) {
                data->unk65 = 0;
                if (++data->unk66 == 5) {
                    data->unk66 = 0;
                    if (++data->unk64 == 5) {
                        func_80800434_chpotogoldgame((BtIntPtr)arg0, 4);
                    }
                }
            }
        }
        break;
    case 4:
        if (arg0->unk64_20 && !_subaddiefind_entrypoint_2(0x1CD, 0)) {
            arg0->unk64_20 = 0;
            if (func_800F64A4(func_800F54E4(), 0x10220)) {
                func_80800434_chpotogoldgame((BtIntPtr)arg0, 12);
            } else {
                func_80800434_chpotogoldgame((BtIntPtr)arg0, 5);
            }
        }
        break;
    case 5:
        if (data->unk64 < 5) {
            func_808011DC_chpotogoldgame(arg0);
            for (i = 0; i < 4; i++) {
                func_808013BC_chpotogoldgame(arg0, data->unk64, i, data->unk66, 0, NULL);
            }
            if (++data->unk66 == 5) {
                data->unk66 = 0;
                data->unk64++;
            }
        }
        break;
    case 7:
        func_80801244_chpotogoldgame(arg0);
        score = func_8080206C_chpotogoldgame(arg0);
        func_800D2498(0xEB, score, 0);
        if (score == 100) {
            arg0->actorData[2] = (s32)(45.0f - (f32)func_800CEA84(0));
            if (func_800D395C()) {
                func_80800434_chpotogoldgame((BtIntPtr)arg0, 14);
            } else {
                func_80800434_chpotogoldgame((BtIntPtr)arg0, 8);
            }
            func_800CE88C(0, 0);
        }
        break;
    case 12:
        if (!func_8010CB84(arg0->position, 500) &&
            !func_800F64A4(func_800F54E4(), 0x10220)) {
            func_80108B04(arg0, 0);
            func_80800434_chpotogoldgame((BtIntPtr)arg0, 4);
        }
        break;
    }
    func_80801558_chpotogoldgame(arg0);
}

s32 func_80800434_chpotogoldgame(BtIntPtr arg0, s32 arg1) {
    void _gcfrontend_entrypoint_9(s32 arg0);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    void func_800CE928(s32, BtIntPtr, BtIntPtr);
    s32 func_800D0A9C(u32, u32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(s16) func_800D211C(s32);
    s32 func_800DA298(s32);
    void func_800DA544(s32);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_800F7C0C(BtIntPtr, s32, f32);
    s32 func_800F7CF4(BtIntPtr, s32, void *);
    void func_800F8294(BtIntPtr, f32 *);
    void func_800FC6B0(u32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    void func_8080111C_chpotogoldgame(BtIntPtr);
    void func_8080117C_chpotogoldgame(BtIntPtr);
    void func_808011DC_chpotogoldgame(Actor *);
    void func_808013BC_chpotogoldgame(Actor *, s32, s32, s32, s32, f32 *);
    s32 func_8080206C_chpotogoldgame(Actor *);
    void func_80802124_chpotogoldgame(Actor *, s32, s32);
    void func_8080219C_chpotogoldgame(Actor *, s32, s32);
    void func_8080227C_chpotogoldgame(void *);
    extern Vec3f D_808024F0_chpotogoldgame;
    extern void _chpotogoldgame_entrypoint_0(s32, BtIntPtr);
    struct GameState {
        u8 cells[5][4][5];
        u8 unk64;
        u8 unk65;
        u8 unk66;
    } *data;
    s32 finalScore;
    Vec3f position;
    s32 i;
    s32 j;
    s32 k;
    s32 message;
    s32 initialMessage;
    s32 score;
    Actor *actor = (Actor *)arg0;

    data = func_80100094(actor, 0);
    switch (arg1) {
    case 2:
        func_800DA544(0x1DB);
        func_80108B04(actor, 0);
        data->unk65 = 0;
        data->unk66 = 0;
        data->unk64 = 0;
        func_80802124_chpotogoldgame(actor, 0, 0x10);
        break;
    case 5:
        if (func_800D211C(0x84) == 100) {
            initialMessage = 0x1425;
        } else if (func_800D0A9C(0x49, 1)) {
            initialMessage = 0x13D1;
        } else if (func_800D0A9C(0x17, 4)) {
            initialMessage = 0x13D0;
        } else if (func_800DA298(0x1E2)) {
            initialMessage = 0x13CF;
        } else {
            initialMessage = 0x13CD;
        }
        func_800F8294(func_800F54E4(), actor->position);
        func_8080219C_chpotogoldgame(actor, initialMessage, 0x4E);
        data->unk65 = 0;
        data->unk66 = 0;
        data->unk64 = 0;
        actor->unk64_20 = 0;
        break;
    case 6:
        func_8080219C_chpotogoldgame(actor, 0xCEC, 0xE);
        func_800CE8D8(0, 45.0f, 0x2D);
        func_800CE928(0, (BtIntPtr)_chpotogoldgame_entrypoint_0, (BtIntPtr)actor->unk0);
        _gcfrontend_entrypoint_9(0x71);
        break;
    case 7:
        position = D_808024F0_chpotogoldgame;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 4; j++) {
                for (k = 0; k < 5; k++) {
                    func_808013BC_chpotogoldgame(actor, i, j, k, 0, NULL);
                }
            }
        }
        func_808011DC_chpotogoldgame(actor);
        func_8080227C_chpotogoldgame(actor);
        func_800F7C0C(func_800F54E4(), 0x5F, -1.0f);
        func_800F7CF4(func_800F54E4(), 0x5E, &position);
        func_800CE88C(0, 1);
        func_800FDC28(0xC);
        func_800DA544(0x1E2);
        break;
    case 8:
        score = func_8080206C_chpotogoldgame(actor);
        if (func_800D211C(0x84) == 100) {
            if (score < 100) {
                func_800FC6B0(0x17);
                message = 0x141E;
            } else if ((s32)actor->actorData[2] < func_800D211C(0x89)) {
                func_800FC6B0(0x16);
                message = 0x1421;
            } else if (func_800D211C(0x89) == actor->actorData[2]) {
                func_800FC6B0(0x17);
                message = 0x1420;
            } else {
                func_800FC6B0(0x17);
                message = 0x141F;
            }
        } else if (func_800D0A9C(0x49, 1)) {
            if (func_800D211C(0x84) == score) {
                func_800FC6B0(0x17);
                message = 0x13D9;
            } else if (score < func_800D211C(0x84)) {
                func_800FC6B0(0x17);
                message = 0x13D7;
            } else if (score == 100) {
                func_800FC6B0(0x16);
                message = 0x1422;
            } else {
                func_800FC6B0(0x16);
                message = 0x13D8;
            }
        } else if (func_800D0A9C(0x17, 4)) {
            if (score < 90) {
                func_800FC6B0(0x17);
                message = 0x13D5;
            } else if (score == 100) {
                func_800FC6B0(0x16);
                message = 0x1423;
            } else {
                func_800FC6B0(0x16);
                message = 0x13D6;
            }
        } else if (score < 75) {
            func_800FC6B0(0x17);
            message = 0x13D2;
        } else if (score < 90) {
            func_800FC6B0(0x16);
            message = 0x13D3;
        } else if (score == 100) {
            func_800FC6B0(0x16);
            message = 0x1424;
        } else {
            func_800FC6B0(0x16);
            message = 0x13D4;
        }
        func_8080219C_chpotogoldgame(actor, message, 0xE);
        func_800F7C0C(func_800F54E4(), 0x5F, 0.0f);
        func_800FDC28(0);
        break;
    case 9:
        func_8080117C_chpotogoldgame(arg0);
        break;
    case 10:
        func_8080111C_chpotogoldgame(arg0);
        break;
    case 11:
        func_8080117C_chpotogoldgame(arg0);
        break;
    case 12:
        if (!func_800F64A4(func_800F54E4(), 0x10220)) {
            func_8080219C_chpotogoldgame(actor, 0x141D, 0xE);
        }
        break;
    case 4:
        func_8080227C_chpotogoldgame(actor);
        func_80108B04(actor, 1);
        break;
    case 13:
        func_800F8294(func_800F54E4(), actor->position);
        if (func_800D211C(0x84) == 100) {
            func_8080219C_chpotogoldgame(actor, 0x1439, 0xE);
        } else {
            func_8080219C_chpotogoldgame(actor, 0x1438, 0xE);
        }
        break;
    case 14:
        finalScore = func_8080206C_chpotogoldgame(actor);
        if (func_800D211C(0x84) == 100) {
            if (finalScore < 100) {
                func_800FC6B0(0x17);
                message = 0x143A;
            } else if ((s32)actor->actorData[2] < func_800D211C(0x89)) {
                func_800FC6B0(0x16);
                message = 0x143D;
            } else if (func_800D211C(0x89) == actor->actorData[2]) {
                func_800FC6B0(0x17);
                message = 0x143C;
            } else {
                func_800FC6B0(0x17);
                message = 0x143B;
            }
        } else if (func_800D211C(0x84) == finalScore) {
            func_800FC6B0(0x17);
            message = 0x1440;
        } else if (finalScore < func_800D211C(0x84)) {
            func_800FC6B0(0x17);
            message = 0x143F;
        } else if (finalScore == 100) {
            func_800FC6B0(0x16);
            message = 0x143E;
        } else {
            func_800FC6B0(0x16);
            message = 0x1441;
        }
        func_8080219C_chpotogoldgame(actor, message, 0xE);
        func_800FDC28(0);
        break;
    }
    func_80101FDC(actor, arg1); BT_NATIVE_ONLY(return 0;)
}

s32 func_80800A94_chpotogoldgame(Actor *arg0, s32 arg1, s32 arg2) {
    void _chappearfx_entrypoint_1(Actor *, u32, u32, f32);
    void _gcfrontend_entrypoint_10(void);
    void func_800C0850(void);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(s16) func_800D211C(s32);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F7B9C(BtIntPtr, s32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    void func_80108B04(Actor *, u32);
    s32 func_80800434_chpotogoldgame(BtIntPtr, s32);
    void func_808010A0_chpotogoldgame(void *);
    void func_8080111C_chpotogoldgame(BtIntPtr);
    s32 func_8080206C_chpotogoldgame();
    void func_8080219C_chpotogoldgame(Actor *arg0, s32 arg1, s32 arg2);
    void func_8080227C_chpotogoldgame(void *);
    Actor *child;
    s32 message;

    switch (arg1) {
    case 0x3D:
        if (!arg0->unk64_20) {
            child = func_80108528(0x1CD, arg0->position, 0, &arg0);
            child->unk74_7 = 0x32;
            arg0->unk64_20 = 1;
            if (arg2 == 0) {
                _chappearfx_entrypoint_1(child, 0x20, 0, 1.0f);
            }
            return 1;
        }
        return 0;
    case 0x30:
        switch (((s16 *)&arg2)[0]) {
        case 0x141F:
        case 0x1420:
        case 0x1421:
            if (((s16 *)&arg2)[1] != 0) {
                return func_800D211C(0x89);
            }
            return arg0->actorData[2];
        case 0x1422:
        case 0x1423:
        case 0x1424:
            return arg0->actorData[2];
        case 0x1425:
            return func_800D211C(0x89);
        case 0x13D2:
        case 0x13D3:
        case 0x13D4:
        case 0x13D5:
        case 0x13D6:
        case 0x13D9:
        case 0x141E:
            return func_8080206C_chpotogoldgame(arg0);
        case 0x13D7:
        case 0x13D8:
            if (((s16 *)&arg2)[1] != 0) {
                return func_800D211C(0x84);
            }
            return func_8080206C_chpotogoldgame(arg0);
        case 0x13CD:
        case 0x13CF:
            switch (((s16 *)&arg2)[1]) {
            case 1:
                return 0x2D;
            case 2:
                return 0x5A;
            default:
                return 0x4B;
            }
            return 0x4B;
        case 0x13D0:
            if (((s16 *)&arg2)[1] != 0) {
                return 0x2D;
            }
            return 0x5A;
        case 0x13D1:
            return func_800D211C(0x84);
        case 0x1438:
            if (((s16 *)&arg2)[1] != 0) {
                return func_800D211C(0x84);
            }
            return 0x2D;
        case 0x1439:
            if (((s16 *)&arg2)[1] != 0) {
                return func_800D211C(0x89);
            }
            return 0x2D;
        case 0x143A:
            return func_8080206C_chpotogoldgame(arg0);
        case 0x143D:
            if (((s16 *)&arg2)[1] != 0) {
                return func_800D211C(0x89);
            }
            return arg0->actorData[2];
        case 0x143C:
            return arg0->actorData[2];
        case 0x143B:
            if (((s16 *)&arg2)[1] != 0) {
                return func_800D211C(0x89);
            }
            return arg0->actorData[2];
        case 0x1440:
            return func_8080206C_chpotogoldgame(arg0);
        case 0x143F:
            if (((s16 *)&arg2)[1] != 0) {
                return func_800D211C(0x84);
            }
            return func_8080206C_chpotogoldgame(arg0);
        case 0x143E:
            return arg0->actorData[2];
        case 0x1441:
            if (((s16 *)&arg2)[1] != 0) {
                return func_800D211C(0x84);
            }
            return func_8080206C_chpotogoldgame(arg0);
        }
        return 1;
    case 0x2E:
        message = ((s16 *)&arg2)[0];
        if (message < 0x13DA) {
            goto lower_messages;
        }
        switch (message) {
        case 0x1425:
            goto message_1;
        case 0x1423:
            goto message_3;
        case 0x1424:
            goto message_4;
        case 0x141E:
        case 0x141F:
        case 0x1420:
        case 0x1421:
        case 0x1422:
            goto message_5;
        case 0x141D:
            goto message_6;
        case 0x1438:
        case 0x1439:
            goto message_7;
        case 0x143A:
        case 0x143B:
        case 0x143C:
        case 0x143D:
        case 0x143E:
        case 0x143F:
        case 0x1440:
        case 0x1441:
            goto message_8;
        case 0x1442:
            goto message_9;
        default:
            goto message_default;
        }
lower_messages:
        if (message < 0xCED) {
            goto small_messages;
        }
        switch (message) {
        case 0x13CD:
        case 0x13CF:
        case 0x13D0:
        case 0x13D1:
            goto message_1;
        case 0x13D3:
            goto message_2;
        case 0x13D6:
            goto message_3;
        case 0x13D4:
            goto message_4;
        case 0x13D2:
        case 0x13D5:
        case 0x13D7:
        case 0x13D8:
        case 0x13D9:
            goto message_5;
        default:
            goto message_default;
        }
small_messages:
        if (message != 0xCEC) {
            goto message_default;
        }
            func_80800434_chpotogoldgame((BtIntPtr)arg0, 7);
            return 1;
message_1:
            if (((s16 *)&arg2)[1] != 0) {
                func_80800434_chpotogoldgame((BtIntPtr)arg0, 6);
            } else {
                func_80800434_chpotogoldgame((BtIntPtr)arg0, 0xC);
            }
            return 1;
message_2:
            func_808010A0_chpotogoldgame(arg0);
            func_80800434_chpotogoldgame((BtIntPtr)arg0, 9);
            return 1;
message_3:
            func_808010A0_chpotogoldgame(arg0);
            func_80800434_chpotogoldgame((BtIntPtr)arg0, 0xA);
            return 1;
message_4:
            func_808010A0_chpotogoldgame(arg0);
            func_80800434_chpotogoldgame((BtIntPtr)arg0, 0xB);
            return 1;
message_5:
            func_808010A0_chpotogoldgame(arg0);
            func_80800434_chpotogoldgame((BtIntPtr)arg0, 5);
            return 1;
message_6:
            func_8080227C_chpotogoldgame(arg0);
            func_800F7B9C(func_800F54E4(), 0x93);
            return 1;
message_7:
            func_80800434_chpotogoldgame((BtIntPtr)arg0, 6);
            return 1;
message_8:
            func_808010A0_chpotogoldgame(arg0);
            func_8080219C_chpotogoldgame(arg0, 0x1442, 0x4E);
            return 1;
message_9:
            if (((s16 *)&arg2)[1] != 0) {
                func_80800434_chpotogoldgame((BtIntPtr)arg0, 6);
                return 1;
            }
            func_8080227C_chpotogoldgame(arg0);
            func_800C0850();
            _gcfrontend_entrypoint_10();
            return 1;
message_default:
        return 1;
    case 0xB:
        if (arg2 == 5 && (s32)arg0->unk70_10 == 0xB) {
            func_8080111C_chpotogoldgame((BtIntPtr)arg0);
        } else if (arg2 == 0) {
            func_80800434_chpotogoldgame((BtIntPtr)arg0, 4);
        } else if (arg2 == 3 || arg2 == 5) {
            func_80800434_chpotogoldgame((BtIntPtr)arg0, 5);
        } else {
            func_80800434_chpotogoldgame((BtIntPtr)arg0, 5);
        }
        return 4;
    case 0x95:
        if ((s32)arg0->unk70_10 == 4) {
            func_80108B04(arg0, 1);
            arg0->unk64_20 = 0;
        }
        return 1;
    }
    return 0;
}

/* extern */

void chpotogoldgame_entrypoint_0(s32 arg0, BtIntPtr arg1) {
    s32 func_800D395C();
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80800434_chpotogoldgame(BtIntPtr, s32);
    if (func_800D395C() != 0) {
        func_80800434_chpotogoldgame(func_80106790(arg1), 0xE);
        return;
    }
    func_80800434_chpotogoldgame(func_80106790(arg1), 8);
}

/* extern */

void func_808010A0_chpotogoldgame(void *arg0) {
    s32 func_800D2054(s32, s32, s32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(s16) func_800D211C(s32);
    s32 func_8080206C_chpotogoldgame();
    s32 sp1C;

    sp1C = func_8080206C_chpotogoldgame();
    if (func_800D211C(0x84) == 0x64) {
        func_800D2054(1, 0x89, (*(s32 *)((s8 *)(arg0) + (0x20))));
        return;
    }
    if (sp1C == 0x64) {
        func_800D2054(1, 0x89, (*(s32 *)((s8 *)(arg0) + (0x20))));
    }
    func_800D2054(0, 0x84, sp1C);
}

/* extern */

void func_8080111C_chpotogoldgame(BtIntPtr arg0) {
    void *_gccubesearch_entrypoint_1(s32 actor_id, f32 *position);
    void _gspropctrl_entrypoint_11(void *arg0, void *arg1);
    void func_800D1000(u32 arg0, u32 arg1, f32* arg2, u32 arg3, Unk80132ED0* arg4);
    void func_80802124_chpotogoldgame(Actor *, s32, s32);
    s32 pad[2];
    s32 sp24;

    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(0x1F6, arg0 + 4), &sp24);
    func_800D1000(0x49, 1, &sp24, 1, 0);
    func_80802124_chpotogoldgame(arg0, 3, 0x10);
}

/* extern */

void func_8080117C_chpotogoldgame(BtIntPtr arg0) {
    void *_gccubesearch_entrypoint_1(s32 actor_id, f32 *position);
    void _gspropctrl_entrypoint_11(void *arg0, void *arg1);
    void func_800D1000(u32 arg0, u32 arg1, f32* arg2, u32 arg3, Unk80132ED0* arg4);
    void func_80802124_chpotogoldgame(Actor *, s32, s32);
    s32 sp24[3];

    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(0x201, arg0 + 4), sp24);
    func_800D1000(0x17, 4, sp24, 1, 0);
    func_80802124_chpotogoldgame(arg0, 5, 0x10);
}

/* extern */

void func_808011DC_chpotogoldgame(Actor *arg0) {
    void _subaddielink_entrypoint_0(void *arg0);
    void *func_80100094(Actor *, u32);
    s32 var_s1;
    u8 *temp_v0;
    u8 *var_s0;
    u8 *var_s2;

    temp_v0 = func_80100094(arg0, 1);
    var_s1 = 0;
    do {
        temp_v0[var_s1 + 0x14] = 0;
        _subaddielink_entrypoint_0(temp_v0 + var_s1 + 0xC);
        var_s1 += 0x18;
    } while (var_s1 != 0xF0);
}

void func_80801244_chpotogoldgame(Actor *arg0)
{
  s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
  void _subaddielink_entrypoint_1(u8 *arg0, u8 *arg1);
  Actor *_subaddielink_entrypoint_4(u8 *);
  void func_800EE7F8(f32 *, f32 *);
  void *func_80100094(Actor *, u32);
  void func_808013BC_chpotogoldgame(Actor *, s32, s32, s32, s32, f32 *);
  s32 func_808016E8_chpotogoldgame(f32 *, s32 *, s32 *, s32 *);
  s32 i;
  s32 count;
  struct Entry
  {
    f32 position[3];
    u8 link[8];
    u8 active;
    u8 pad[3];
  };
  u8 *actors[10];
  struct Entry *data;
  s32 x;
  s32 y;
  s32 z;
  s32 j;
  data = func_80100094(arg0, 1);
  i = 0;
  if (data->active != 0)
  {
    do
    {
      if ((_subaddielink_entrypoint_4(data[i].link) == NULL) && func_808016E8_chpotogoldgame(data[i].position, &x, &y, &z))
      {
        func_808013BC_chpotogoldgame(arg0, y, x, z, 1, data[i].position);
      }
      i++;
    }
    while ((i < 10) && (data[i].active != 0));
  }
  count = _subaddiefind_entrypoint_4(0x15F, actors, 10);
  for (j = 0; j < count; j++)
  {
    func_800EE7F8(data[j].position, ((Actor *) actors[j])->position);
    if (j)
    {
    }
    _subaddielink_entrypoint_1(data[j].link, ((Actor *) actors[j])->unk0);
    data[j].active = 1;
  }

  for (; j < 10; j++)
  {
    data[j].active = 0;
  }

}

void func_808013BC_chpotogoldgame(Actor *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 *arg5) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800FC660(u32);
    void *func_80100094(Actor *, u32);
    void func_80801870_chpotogoldgame(s32, s32, s32, s32);
    extern s32 D_808024FC_chpotogoldgame[17];
    u8 (*data)[4][5];

    data = func_80100094(arg0, 0);
    if (arg4 != 0 && data[arg1][arg2][arg3] == 0) {
        if (arg5 != NULL) {
            func_800BBCB8(arg5, arg5, 1.0f, 0x1E, D_808024FC_chpotogoldgame);
        }
        func_800FC660(0xE);
    }
    data[arg1][arg2][arg3] = arg4;
    func_80801870_chpotogoldgame(arg2, arg1, arg3, arg4);
}

/* extern */

void func_80801494_chpotogoldgame(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80801870_chpotogoldgame(s32, s32, s32, s32);
    s32 var_s0;
    s32 var_s3;
    s32 var_s4;
    s8 *var_fp;
    s8 *var_s1;
    s8 *var_s6;
    s8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    var_s4 = 0;
    var_fp = temp_v0;
    do {
        var_s3 = 0;
        var_s6 = var_fp;
loop_2:
        var_s0 = 0;
        var_s1 = var_s6;
loop_3:
        *var_s1 = arg1;
        func_80801870_chpotogoldgame(var_s3, var_s4, var_s0, arg1);
        var_s0 += 1;
        var_s1 += 1;
        if (var_s0 != 5) {
            goto loop_3;
        }
        var_s3 += 1;
        var_s6 += 5;
        if (var_s3 != 4) {
            goto loop_2;
        }
        var_s4 += 1;
        var_fp += 0x14;
    } while (var_s4 != 5);
}
struct Color { s32 values[3]; };
void func_80801558_chpotogoldgame(Actor *arg0) {
    void func_800BF48C(s32, s32, s32);
    void func_800C8C90(BtIntPtr);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    int func_800F3214(void *, void *, void *, f32);
    s32 func_8080206C_chpotogoldgame();

    struct GameData { f32 values[8]; };
    extern struct Color D_80802540_chpotogoldgame;
    extern struct Color D_8080254C_chpotogoldgame;
    struct Color color;
    struct Color start = D_80802540_chpotogoldgame;
    struct Color end = D_8080254C_chpotogoldgame;
    f32 ratio;

    ratio = func_800F10B4((f32)func_8080206C_chpotogoldgame(), 100.0f, 0.0f, 0.0f, 0.5f);
    ratio += func_800F10B4(((struct GameData *)arg0->actorData)->values[5], 0.0f, 2.0f, 0.0f, 0.1f);
    ratio += func_800F10B4(((struct GameData *)arg0->actorData)->values[6], 0.0f, 2.0f, 0.0f, 0.1f);
    ratio += func_800F10B4(((struct GameData *)arg0->actorData)->values[0], 0.0f, 2.0f, 0.0f, 0.1f);
    ratio += func_800F10B4(((struct GameData *)arg0->actorData)->values[4], 0.0f, 2.0f, 0.0f, 0.1f);
    ratio += func_800F10B4(((struct GameData *)arg0->actorData)->values[1], 0.0f, 2.0f, 0.0f, 0.1f);
    func_800F3214(&color, &start, &end, ratio);
    func_800BF48C(color.values[0], color.values[1], color.values[2]);
    func_800C8C90((BtIntPtr)&color);
}
struct Bounds { f32 values[8]; };
s32 func_808016E8_chpotogoldgame(f32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    f32 func_800136E4(f32);
    f32 func_800F13C4(f32, f32);
    s32 func_800F1EA4(f32 *, f32 *);

    extern struct Bounds D_80802558_chpotogoldgame;
    f32 angle;
    struct Bounds bounds = D_80802558_chpotogoldgame;
    for (*arg1 = 0; *arg1 < 4; (*arg1)++) {
        if (bounds.values[*arg1 * 2] < arg0[1]) {
            return 0;
        }
        if (bounds.values[*arg1 * 2 + 1] < arg0[1]) {
            break;
        }
    }
    if (*arg1 >= 4) {
        return 0;
    }
    func_800F1EA4(arg0, &angle);
    angle = func_800136E4(angle - 7.0f);
    *arg2 = (s32)(angle / 72.0f);
    angle = func_800F13C4(angle, 72.0f);
    if (angle > 58.0f) {
        return 0;
    }
    *arg3 = (s32)(angle / 12.0f);
    if (func_800F13C4(angle, 12.0f) > 10.0f) {
        return 0;
    }
    return 1;
}

void func_80801870_chpotogoldgame(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    void *func_800BEA88(s32 i);
#ifdef BT_NATIVE
    void chpotogoldgame_entrypoint_1(u8, s16 *, Vtx *, s32, s32);
#else
    extern s32 _chpotogoldgame_entrypoint_1;
#endif
    arg1 = ((arg3 & 1) << 4) | arg1;
    _glid_entrypoint_0(func_800BEA88(0), ((arg0 * 5) - arg2) + 5, &_chpotogoldgame_entrypoint_1, arg1);
}

/* extern */

void chpotogoldgame_entrypoint_1(u8 arg0, s16 *arg1, Vtx *arg2, s32 arg3, s32 arg4) { s32 func_80801998_chpotogoldgame(s16 *); s16 *var_s1; Vtx *temp_s6; Vtx *var_s0; s32 flag; var_s0 = arg2; var_s1 = arg1;
    flag = arg4 & 0x10;
    arg4 &= 0xF;
    temp_s6 = arg2 + arg3;
    if (arg2 < temp_s6) {
        do {
            if (func_80801998_chpotogoldgame(var_s1) == arg4) {
                if (flag) {
                    var_s0->v.cn[0] = 0x64;
                    var_s0->v.cn[1] = 0x64;
                    var_s0->v.cn[2] = 0x64;
                } else {
                    var_s0->v.cn[0] = 0xFF;
                    var_s0->v.cn[1] = 0xFF;
                    var_s0->v.cn[2] = 0xFF;
                }
            }
            var_s0++;
            var_s1 += 8;
        } while (var_s0 < temp_s6);
    }
}

s32 func_80801998_chpotogoldgame(s16 *arg0) {
    void func_800EE88C(f32 dst[3], s16 src[3]);
    s32 func_800F1EA4(f32[3], f32 *);
    f32 sp24;
    f32 sp18[3];

    func_800EE88C(sp18, arg0);
    func_800F1EA4(sp18, &sp24);
    return (s32) (sp24 / 72.0f);
}

void chpotogoldgame_entrypoint_2(s32 arg0, Unk80132ED0 *arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_800DA298(s32);
    void func_800DA544(s32);
    void func_800FC6B0(u32);
    s32 flag;

    switch (func_80106790(arg1)->unk6C_9) {
    case 0x15A:
        flag = 0x9F6;
        break;
    case 0x15B:
        flag = 0x9F7;
        break;
    case 0x15C:
        flag = 0x9F8;
        break;
    case 0x15D:
        flag = 0x9F9;
        break;
    default:
        return;
    }
    if (!func_800DA298(flag)) {
        func_800FC6B0(0xE);
        func_800DA544(flag);
    }
}

s32 func_80801A7C_chpotogoldgame(Actor *arg0) {
    s32 sp24;
    BtIntPtr marker;
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    void *func_800BEA88(s32 i);
    int func_800D91EC(f32 *, f32);
    s32 func_800DA298(s32);
#ifdef BT_NATIVE
    void chpotogoldgame_entrypoint_3(s32 arg0, s32 arg1, Vtx *arg2, s32 arg3, BtIntPtr arg4);
#else
    extern s32 _chpotogoldgame_entrypoint_3;
#endif
    s32 *volatile sp1C;
    BtIntPtr temp_v0;

    sp24 = 1;
    if ((func_800DA298(0x9F6) != 0) || (func_800DA298(0x1DB) != 0)) {
        sp24 = func_800D91EC((f32 *)&arg0->actorData[0], 2.0f) & 1;
    }
    if ((func_800DA298(0x9F7) != 0) || (func_800DA298(0x1DB) != 0)) {
        sp24 &= func_800D91EC((f32 *)&arg0->actorData[5], 2.0f);
    }
    if ((func_800DA298(0x9F8) != 0) || (func_800DA298(0x1DB) != 0)) {
        sp24 &= func_800D91EC((f32 *)&arg0->actorData[4], 2.0f);
    }
    if ((func_800DA298(0x9F9) != 0) || (func_800DA298(0x1DB) != 0)) {
        sp24 &= func_800D91EC((f32 *)&arg0->actorData[6], 2.0f);
    }
    if ((func_800DA298(0x9F6) != 0) && (func_800DA298(0x9F7) != 0) && (func_800DA298(0x9F8) != 0) && (func_800DA298(0x9F9) != 0)) {
        sp24 &= func_800D91EC((f32 *)&arg0->actorData[1], 2.0f);
    }
    temp_v0 = func_800BEA88(0);
    marker = arg0->unk0;
    sp1C = &_chpotogoldgame_entrypoint_3;
    _glid_entrypoint_0(temp_v0, 0x18, &_chpotogoldgame_entrypoint_3, marker);
    _glid_entrypoint_0(func_800BEA88(0), 0x15, sp1C, arg0->unk0);
    _glid_entrypoint_0(func_800BEA88(0), 0x17, sp1C, arg0->unk0);
    _glid_entrypoint_0(func_800BEA88(0), 0x16, sp1C, arg0->unk0);
    _glid_entrypoint_0(func_800BEA88(0), 0x19, sp1C, arg0->unk0);
    return sp24;
}

void chpotogoldgame_entrypoint_3(s32 arg0, s32 arg1, Vtx *arg2, s32 arg3, BtIntPtr arg4) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 pad;
    u8 *actor;
    u8 color;
    Vtx *end;

    actor = (u8 *)func_80106790(arg4);
    switch (arg0) {
    case 21:
        color = (u8)(u32)func_800F10B4(*(f32 *)(actor + 0x2C), 0.0f, 2.0f, 100.0f, 255.0f);
        break;
    case 22:
        color = (u8)(u32)func_800F10B4(*(f32 *)(actor + 0x30), 0.0f, 2.0f, 100.0f, 255.0f);
        break;
    case 23:
        color = (u8)(u32)func_800F10B4(*(f32 *)(actor + 0x28), 0.0f, 2.0f, 100.0f, 255.0f);
        break;
    case 24:
        color = (u8)(u32)func_800F10B4(*(f32 *)(actor + 0x18), 0.0f, 2.0f, 100.0f, 255.0f);
        break;
    case 25:
        color = (u8)(u32)func_800F10B4(*(f32 *)(actor + 0x1C), 0.0f, 2.0f, 100.0f, 255.0f);
        break;
    }
    for (end = arg2 + arg3; arg2 < end; arg2++) {
        arg2->v.cn[0] = color;
        arg2->v.cn[1] = color;
        arg2->v.cn[2] = color;
    }
}

/* extern */

s32 func_8080206C_chpotogoldgame(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 i;
    s32 j;
    s32 k;
    s32 count = 0;
    u8 (*data)[4][5];

    data = func_80100094(arg0, 0);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 5; k++) {
                if (data[i][j][k] != 0) {
                    count++;
                }
            }
        }
    }
    return count;
}

void func_80802124_chpotogoldgame(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_2(BtIntPtr arg0, s32 arg1, s32 arg2);
    s32 _capod_entrypoint_6(BtIntPtr arg0, s32 arg1, s32 arg2);

    switch (arg0->actorData[7]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x29, 0x10);
        case 1:
            arg0->actorData[7] = 2;
        case 2:
            _capod_entrypoint_6(arg0->unk0, arg1, arg2);
            break;
    }
}

void func_8080219C_chpotogoldgame(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_2(BtIntPtr arg0, s32 arg1, s32 arg2);
    void _capod_entrypoint_7(s32, s32);
    void _capod_entrypoint_8(s32 arg0);
    void _gcdialogcamera_entrypoint_6(Unk80132ED0 *);
    void _gcdialogcamera_entrypoint_8(void);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    BtUIntPtr func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    f32 func_800F5F24(BtUIntPtr);
    f32 sp3C[3];
    f32 sp30[3];

    switch (arg0->actorData[7]) {
        case 1:
            break;
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x29, 0x10);
        default:
            _capod_entrypoint_8(1);
            arg0->actorData[7] = 1;
            _gcdialogcamera_entrypoint_6(arg0->unk0);
            _gcdialogcamera_entrypoint_8();
            _capod_entrypoint_7(5, 1);
            break;
    }
    func_800F5A00(func_800F54E4(), sp3C);
    func_800EEB9C(sp30, func_800F5F24(func_800F54E4()), 300.0f);
    func_800EF04C(sp3C, sp30);
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, sp3C, 0x22);
}

/* extern */

void func_8080227C_chpotogoldgame(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x34))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x34))) = 0;
    }
}

OSThread *chpotogoldgame_entrypoint_4(void)
{
    extern ActorData D_80802578_chpotogoldgame[];

    return (OSThread *) D_80802578_chpotogoldgame;
}
/* data_to_c.py: from asm/data/overlays/ch/potogoldgame.data.s */
void func_80105834(Actor*);
void func_8010A730();
void func_80108ED0();
void func_80107C2C();
Vec3f D_808024F0_chpotogoldgame BT_DATA(4, overlays_ch_potogoldgame, 0x0) = { { 0.0f, 1075.0f, -2700.0f } };
s32 D_808024FC_chpotogoldgame[17] BT_DATA(4, overlays_ch_potogoldgame, 0xC) = { 1903074, 1834408, -52428755, 13107500, 917514, 2621474, 2490444, 1638425, 1376281, 15073323, 16777600, 3080294, 6029393, 1638420, 1966272, 3276750, -6553600 };
struct Color D_80802540_chpotogoldgame BT_DATA(4, overlays_ch_potogoldgame, 0x50) = { { 80, 80, 80 } };
struct Color D_8080254C_chpotogoldgame BT_DATA(4, overlays_ch_potogoldgame, 0x5C) = { { 220, 220, 220 } };
struct Bounds D_80802558_chpotogoldgame BT_DATA(4, overlays_ch_potogoldgame, 0x68) = { { 1825.0f, 1570.0f, 1475.0f, 1125.0f, 1025.0f, 650.0f, 575.0f, 250.0f } };
ActorData D_80802578_chpotogoldgame [1] BT_DATA(4, overlays_ch_potogoldgame, 0x88) = { { 355, 1029, 0, 1, 0, (void (*)(struct Actor *))func_80800124_chpotogoldgame, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 0, 0, (BtIntPtr)func_80108ED0, 103, 240, (void (*)(struct Actor *))func_80800000_chpotogoldgame, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9216, (void (*)(struct Actor *, long, long))func_80800A94_chpotogoldgame, 0 } };
