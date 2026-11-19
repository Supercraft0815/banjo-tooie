#include "overlays/ba/data.h"
BT_NATIVE_ONLY(u8 func_800F8B88(void);)
s32 func_80800000_badata(PlayerState *self) {
    s32 sp1C  = bs_getCurrentState(self);
    switch(func_800A3274(self)) {
        case TRANSFORM_2_SNOWBALL:
            return 2;

        case TRANSFORM_6_BEE:
            if(func_8009CA70(self, sp1C, 0x4000)) {
                return 0x1E;
            }
            return 0xB;

        case TRANSFORM_7_WASHINGMACHINE:
            return 0;

        case TRANSFORM_8_STONY:
            return 0xE;

        case TRANSFORM_A_BANJO:
            if(func_8009E71C(self, 0x12)) {
                return 0xA;
            } else if (func_8009E71C(self, 0x13)) {
                return 0x1F;
            } else if (func_8009E71C(self, 0x14)) {
                return 0x20;
            } else if (func_8009CA70(self, sp1C, 0x400)) {
                return 0x1C;
            } else if (player_inWater(self)) {
                if (func_800F8B88() == 3) {
                    return 0x21;
                } else {
                    switch (func_800F40EC(self)) {
                        case 2:
                            return 0x5;
                        default:
                        case 1:
                            return 0x4;
                    }
                }
            } else {
                return 0xF;
            }
        case TRANSFORM_B_KAZOOIE:
            if (func_8009CA70(self, sp1C, 0x200)) {
                return 0x22;
            } else if (func_8009CBDC(self, sp1C) == 0x9) {
                return 0x3;
            } else if (bastatetimer_get(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0.0f) {
                return 0x1;
            } else if (func_800F8B88() == 3) {
                return 0x1A;
            } else if (player_inWater(self)) {
                return 0x1B;
            } else {
                return 0x10;
            }
            break;

        case TRANSFORM_D_MUMBO:
            if (player_inWater(self)) {
                return 0x12;
            } else {
                return 0x11;
            }
            break;

        case TRANSFORM_E_GOLDENGOLIATH:
            return 0x13;

        case TRANSFORM_F_DETONATOR:
            return 0x14;
        
        case TRANSFORM_10_VAN:
            return 0x15;

        case TRANSFORM_C_SUB:
            return 0x16;

        case TRANSFORM_11_CLOCKWORK:
            return 0x17;

        case TRANSFORM_12_TREXSMALL:
            return 0x18;

        case TRANSFORM_13_TREXLARGE:
            return 0x19;

        case TRANSFORM_9_FIRSTPERSON:
            return 0x1D;
            
        case TRANSFORM_1_BK:
        default:
            if (func_8009CBDC(self, sp1C) == 2) {
                return 0x23;
            } else if (func_8009CBDC(self, sp1C) == 0xA) {
                return 0xC;
            } else if (func_8009CBDC(self, sp1C) == 0x9) {
                return 0x7;
            } else if (func_8009CA70(self, sp1C, 0x40)) {
                return 0x8;
            } else if (func_8009CA70(self, sp1C, 0x400)) {
                return 0x1C;
            } else if (bastatetimer_get(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0.0f) {
                return 0x9;
            } else if (func_8009EA4C() == 5) {
                return 0x5;
            } else if (func_800F3ED0(self) == 3) {
                return 0xD;
            } else if (player_inWater(self)) {
                switch (func_800F40EC(self)) {
                    case 2:
                        return 0x5;
                    default:
                    case 1:
                        return 0x4;
                }
            } else {
                return 0x6;
            }
            break;
    }
}

s32 func_80800388_badata(PlayerState *self) {
    s32 sp1C;
    f32 sp18;

    sp1C = func_8009EA4C();
    switch (func_800A3274(self)) {
        case TRANSFORM_2_SNOWBALL:
            return 2;
        
        case TRANSFORM_6_BEE:
            if (sp1C == 4) {
                return 0x1E;
            }         
            return 0xB;
        
        case TRANSFORM_7_WASHINGMACHINE:
            return 0;
        
        case TRANSFORM_8_STONY:
            return 0xE;

        case TRANSFORM_A_BANJO:
            if (player_inWater(self)) {
                if (func_800F8B88() == 3) {
                    return 0x21;
                }

                sp18 = func_8009C150(self);
                if(func_800964DC(self) - 80.0f < sp18) {
                    return 0x4;
                }
                
                return 0x5;
            }
            
            switch(sp1C) {
                case 0x3:
                    return 0xA;
                case 0x6:
                    return 0x1F;
                case 0x7:
                    return 0x20;
            }
            return 0xF;

        case TRANSFORM_B_KAZOOIE:
            if (sp1C == 4) {
                return 0x3;
            }

            if (bastatetimer_get(self, BA_STATE_TIMER_ID_3_TURBO_TALON) != 0.0f) {
                return 0x10;
            }

            if (bastatetimer_get(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0.0f) {
                return 0x1;
            }

            if (func_800F8B88() == 3) {
                return 0x1A;
            }

            if (player_inWater(self)) {
                return 0x1B;
            }

            return 0x10;

        case TRANSFORM_D_MUMBO:
            if (player_inWater(self)) {
                return 0x12;
            }
            return 0x11;
        
        case TRANSFORM_E_GOLDENGOLIATH:
            return 0x13;

        case TRANSFORM_F_DETONATOR:
            return 0x14;

        case TRANSFORM_10_VAN:
            return 0x15;

        case TRANSFORM_C_SUB:
            return 0x16;

        case TRANSFORM_11_CLOCKWORK:
            return 0x17;

        case TRANSFORM_12_TREXSMALL:
            return 0x18;
        
        case TRANSFORM_13_TREXLARGE:
            return 0x19;


        case TRANSFORM_9_FIRSTPERSON:
            return 0x1D;

        case TRANSFORM_1_BK:
        default:
            if (player_inWater(self)) {
                sp18 = func_8009C150(self);
                if (func_800964DC(self) - 95.0f < sp18) {
                    return 4;
                }
                return 5;
            }
            if (sp1C == 4) {
                return 0x7;
            }
            if (sp1C == 5) {
                return 0x5;
            }
            if (sp1C == 2) {
                return 0x8;
            }

            if(bastatetimer_get(self, BA_STATE_TIMER_ID_3_TURBO_TALON) != 0.0f) {
                return 0x8;
            }

            if(bastatetimer_get(self, BA_STATE_TIMER_ID_2_LONGLEG) != 0.0f) {
                return 0x9;
            }
            return 0x6;
    }
}

void func_808006AC_badata(PlayerState *self , BaData_1 *arg1, s32 *arg2, f32 *arg3) {
    s32 tmp_v0 = func_80800000_badata(self);
    *arg2 = arg1[tmp_v0].unk2;
    *arg3 = arg1[tmp_v0].unk4;
}


void badata_entrypoint_0(PlayerState *self, AssetId *assetId, f32 *arg2) {
    func_808006AC_badata(self, D_80801EF8_badata, assetId, arg2);
}

void badata_entrypoint_1(PlayerState *self, AssetId *assetId, f32 *arg2) {
    func_808006AC_badata(self, D_80801A78_badata, assetId, arg2);
}

void badata_entrypoint_2(PlayerState *self, AssetId *assetId, f32 *arg2) {
    func_808006AC_badata(self, D_80801B98_badata, assetId, arg2);
}

void badata_entrypoint_3(PlayerState *self, AssetId *assetId, f32 *arg2) {
    func_808006AC_badata(self, D_80801DD8_badata, assetId, arg2);
}

void badata_entrypoint_4(PlayerState *self, AssetId *assetId, f32 *arg2) {
    func_808006AC_badata(self, D_80802018_badata, assetId, arg2);
}

void badata_entrypoint_5(PlayerState *self, AssetId *assetId, f32 *arg2) {
    func_808006AC_badata(self, D_80801CB8_badata, assetId, arg2);
}


void badata_entrypoint_6(PlayerState *self, s32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    s32 tmp_v0 = func_80800000_badata(self);
    BaData_3 *tmp_v1 = &D_80801718_badata[tmp_v0];
    *arg1  = tmp_v1->unk2;
    *arg2  = tmp_v1->unk4;
    *arg3  = tmp_v1->unk8;
    *arg4  = tmp_v1->unkC;
}

void badata_entrypoint_7(PlayerState * self, AssetId *assetId, f32 *arg2) {
    func_808006AC_badata(self, D_80801958_badata, assetId, arg2);
}

void badata_entrypoint_8(PlayerState *self, s32 *arg1, f32 *arg2, f32 *arg3) {
    s32 tmp_v0 = func_80800000_badata(self);
    BaData_4 *tmp_v1 = &D_80802648_badata[tmp_v0];
    *arg1  = tmp_v1->unk0;
    *arg2  = tmp_v1->unk4;
    *arg3  = tmp_v1->unk8;
}

void badata_entrypoint_9(PlayerState *self, AssetId *assetId, f32 *arg2){
    func_808006AC_badata(self, D_80802138_badata, assetId, arg2);
}

void badata_entrypoint_10(PlayerState *self, AssetId *assetId, f32 *arg2){
    func_808006AC_badata(self, D_80802378_badata, assetId, arg2);
}

void badata_entrypoint_11(PlayerState *self, AssetId *assetId, f32 *arg2){
    func_808006AC_badata(self, D_80802258_badata, assetId, arg2);
}

void badata_entrypoint_12(PlayerState *self, s32 *arg1, f32 *arg2) {
    s32 tmp_v0 = func_80800000_badata(self);
    BaData_4 *tmp_v1 = &D_80802498_badata[tmp_v0];
    *arg1  = tmp_v1->unk2;
    *arg2  = tmp_v1->unk8;
}

void badata_entrypoint_13(PlayerState *self, s32 *arg1, f32 *arg2) {
    s32 tmp_v0 = func_80800000_badata(self);
    BaData_4 *tmp_v1 = &D_80802498_badata[tmp_v0];
    *arg1  = tmp_v1->unk0;
    *arg2  = tmp_v1->unk4;
}

s32 badata_entrypoint_14(PlayerState *self) {
    return D_80801640_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_15(PlayerState *self) {
    return D_80801664_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_16() {
    return 11;
}

s32 func_80800AA4_badata(PlayerState *self, BaData_5 *arg1, s32 index, s32 *arg3, f32 *arg4, s32 *arg5) {
    s32 max;
    s32 valid;
    s32 tmp_v0;

    valid = 1;
    tmp_v0 = func_80800000_badata(self);
    max = arg1[tmp_v0].count;
    if(index >= max) {
        index = 0;
        valid = 0;
    }
    *arg3 = arg1[tmp_v0].unk0[index].unk0;
    *arg4 = arg1[tmp_v0].unk0[index].unk4 + arg1[tmp_v0].unk8;
    *arg5 = arg1[tmp_v0].unk0[index].unk2;
    return valid;
}


BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) badata_entrypoint_17(PlayerState *self, s32 index, s32 *arg2, f32 *arg3, s32 *arg4) {
    BT_NATIVE_ONLY(return) func_80800AA4_badata(self, D_808010C8_badata, index, arg2, arg3, arg4);
}

f32 badata_entrypoint_18(PlayerState *self) {
    return D_808010C8_badata[func_80800000_badata(self)].unk8;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) badata_entrypoint_19(PlayerState *self, s32 index, s32 *arg2, f32 *arg3, s32 *arg4) {
    BT_NATIVE_ONLY(return) func_80800AA4_badata(self, D_80801298_badata, index, arg2, arg3, arg4);
}

s32 badata_entrypoint_20(PlayerState *self) {
    if (0.5f < func_800DC0C0()) {
        return D_80801568_badata[func_80800000_badata(self)].unk2;
    } else {
        return D_80801568_badata[func_80800000_badata(self)].unk4;
    }
}

s32 badata_entrypoint_21(PlayerState *self) {
    return D_80801A78_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_22(PlayerState *self) {
    return D_80801718_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_23(PlayerState *self) {
    return D_80802018_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_24(PlayerState *self) {
    return D_808014D8_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_25(PlayerState *self) {
    return D_80801520_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_26(PlayerState *self) {
    return D_80801568_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_27(PlayerState *self) {
    func_80800000_badata(self);
    return D_80801448_badata[func_80800000_badata(self)];
}

BtIntPtr badata_entrypoint_28(PlayerState *self) {
    return D_80801688_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_29(PlayerState *self) {
    return D_80802138_badata[func_80800000_badata(self)].unk0;
}


s32 badata_entrypoint_30(PlayerState *self, s32 arg1) {
    switch (arg1) {
        case 1:
            return 0x73;

        case 2:
            return 0x74;

        case 3:
            return 0x75;

        case 4:
            return 0x74;
    }
    return 0;
}

s32 badata_entrypoint_31(PlayerState *self) {
    return D_80802378_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_32(PlayerState *self) {
    return D_80802258_badata[func_80800000_badata(self)].unk0;
}

s32 badata_entrypoint_33(PlayerState *self) {
    switch (func_8009EA64()) {
        case 0x305:
            return 0x12A;

        case 0x171:
            return 0x7C;
        
        case 0x2A2:
            return 0x12B;
        
        case 0x38A:
            return 0xB7;
    }
    return 0xB7;
}

s32 badata_entrypoint_34(PlayerState *self) {
    return D_80801490_badata[func_80800000_badata(self)];
}

s32 badata_entrypoint_35(PlayerState *self) {
    return D_80801490_badata[func_80800388_badata(self)];
}
/* data_to_c.py: from asm/data/overlays/ba/data.data.s */
extern u8 D_80801060_badata[];
extern u8 D_80801080_badata[];
extern u8 D_808010A0_badata[];
extern u8 D_808010B0_badata[];
extern u8 D_80801278_badata[];
extern u8 D_80801280_badata[];
extern u8 D_80801288_badata[];
void _bswalk_entrypoint_22();
void _bsfirstp_entrypoint_25();
u8 D_80801060_badata[32] BT_DATA(4, overlays_ba_data, 0x0) = { 0x05, 0x78, 0x55, 0xF0, 0x3F, 0x80, 0x00, 0x00, 0x05, 0x79, 0x55, 0xF0, 0x3F, 0x80, 0x00, 0x00, 0x05, 0x7A, 0x55, 0xF0, 0x3F, 0x80, 0x00, 0x00, 0x05, 0x7B, 0x55, 0xF0, 0x3F, 0x80, 0x00, 0x00 };
u8 D_80801080_badata[32] BT_DATA(4, overlays_ba_data, 0x20) = { 0x45, 0x93, 0x55, 0xF0, 0x3F, 0x80, 0x00, 0x00, 0x45, 0x94, 0x55, 0xF0, 0x3F, 0x80, 0x00, 0x00, 0x45, 0x95, 0x55, 0xF0, 0x3F, 0x80, 0x00, 0x00, 0x45, 0x96, 0x55, 0xF0, 0x3F, 0x80, 0x00, 0x00 };
u8 D_808010A0_badata[16] BT_DATA(4, overlays_ba_data, 0x40) = { 0x05, 0x0F, 0x55, 0xF0, 0x3F, 0x80, 0x00, 0x00, 0x05, 0x10, 0x55, 0xF0, 0x3F, 0x80, 0x00, 0x00 };
u8 D_808010B0_badata[24] BT_DATA(4, overlays_ba_data, 0x50) = { 0x05, 0x67, 0x55, 0xF0, 0x3F, 0x99, 0x99, 0x9A, 0x05, 0x67, 0x55, 0xF0, 0x3F, 0xA0, 0x00, 0x00, 0x05, 0x67, 0x55, 0xF0, 0x3F, 0xA6, 0x66, 0x66 };
BaData_5 D_808010C8_badata [36] BT_DATA(4, overlays_ba_data, 0x68) = { { (BaData_1 *)D_80801060_badata, 4, 0.81f }, { (BaData_1 *)D_80801080_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.81f }, { (BaData_1 *)D_80801080_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.81f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.81f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801080_badata, 4, 0.0f }, { (BaData_1 *)D_808010A0_badata, 2, 0.0f }, { (BaData_1 *)D_808010A0_badata, 2, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.81f }, { (BaData_1 *)D_80801060_badata, 4, 0.81f }, { (BaData_1 *)D_80801060_badata, 4, 0.81f }, { (BaData_1 *)D_80801080_badata, 4, 0.4f }, { (BaData_1 *)D_808010B0_badata, 3, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801080_badata, 4, 0.0f }, { (BaData_1 *)D_80801080_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.8f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f }, { (BaData_1 *)D_80801080_badata, 4, 0.0f }, { (BaData_1 *)D_80801060_badata, 4, 0.0f } };
u8 D_80801278_badata[8] BT_DATA(4, overlays_ba_data, 0x218) = { 0x04, 0x3D, 0x55, 0xF0, 0x3F, 0x80, 0x00, 0x00 };
u8 D_80801280_badata[8] BT_DATA(4, overlays_ba_data, 0x220) = { 0x44, 0x3E, 0x6D, 0x60, 0x3F, 0x80, 0x00, 0x00 };
u8 D_80801288_badata[16] BT_DATA(4, overlays_ba_data, 0x228) = { 0x05, 0x11, 0x55, 0xF0, 0x3F, 0x80, 0x00, 0x00, 0x04, 0xD8, 0x55, 0xF0, 0x3F, 0xAC, 0xCC, 0xCD };
BaData_5 D_80801298_badata [36] BT_DATA(4, overlays_ba_data, 0x238) = { { (BaData_1 *)D_80801278_badata, 1, 0.81f }, { (BaData_1 *)D_80801280_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.81f }, { (BaData_1 *)D_80801280_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.81f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.81f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801280_badata, 1, 0.0f }, { (BaData_1 *)D_80801288_badata, 1, 0.0f }, { (BaData_1 *)D_80801288_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.81f }, { (BaData_1 *)D_80801278_badata, 1, 0.81f }, { (BaData_1 *)D_80801278_badata, 1, 0.81f }, { (BaData_1 *)D_80801278_badata, 1, 0.81f }, { (BaData_1 *)D_80801280_badata, 1, 0.4f }, { (BaData_1 *)D_808010B0_badata, 3, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801280_badata, 1, 0.0f }, { (BaData_1 *)D_80801280_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.81f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f }, { (BaData_1 *)D_80801280_badata, 1, 0.0f }, { (BaData_1 *)D_80801278_badata, 1, 0.0f } };
s16 D_80801448_badata [36] BT_DATA(4, overlays_ba_data, 0x3E8) = { 142, 86, 388, 371, 86, 191, 86, 24, 86, 86, 126, 163, 86, 86, 176, 86, 314, 236, 236, -1, 266, 280, 131, -1, 321, 333, 360, 314, 86, -1, 192, 86, 86, 191, 314, 86 };
s16 D_80801490_badata [36] BT_DATA(4, overlays_ba_data, 0x430) = { 50, 72, 381, 354, 45, 43, 1, 36, 21, 38, 357, 133, 79, 27, 179, 1, 187, 229, 240, 249, 268, 282, 305, 310, 325, 337, 340, 349, 58, 204, 140, 364, 367, 43, 190, 1 };
s16 D_808014D8_badata [36] BT_DATA(4, overlays_ba_data, 0x478) = { 54, 72, 384, 223, 47, 47, 47, 47, 113, 47, 358, 136, 47, 47, 173, 47, 223, 233, 233, 249, 262, 276, 305, 307, 318, 330, 340, 223, 58, 204, 136, 47, 47, 47, 223, 47 };
s16 D_80801520_badata [36] BT_DATA(4, overlays_ba_data, 0x4C0) = { 53, 74, 383, 189, 5, 5, 5, 5, 8, 5, 361, 135, 5, 5, 174, 5, 189, 232, 232, 249, 263, 277, 305, 308, 319, 331, 340, 189, 58, 204, 135, 5, 5, 5, 189, 5 };
BaData_2 D_80801568_badata [36] BT_DATA(4, overlays_ba_data, 0x508) = { { 62, 67, 67 }, { 256, 257, 257 }, { 385, 386, 386 }, { 377, 257, 257 }, { 14, 258, 65 }, { 127, 258, 65 }, { 14, 258, 65 }, { 145, 258, 65 }, { 123, 258, 65 }, { 14, 258, 65 }, { 125, 258, 258 }, { 137, 138, 138 }, { 14, 258, 65 }, { 14, 258, 65 }, { 175, 171, 171 }, { 14, 259, 259 }, { 256, 257, 257 }, { 234, 235, 235 }, { 234, 235, 235 }, { 14, 258, 65 }, { 265, 260, 260 }, { 279, 274, 274 }, { 301, 302, 302 }, { 301, 302, 302 }, { 320, 316, 316 }, { 332, 328, 328 }, { 346, 302, 302 }, { 256, 257, 257 }, { 14, 258, 65 }, { 204, 204, 204 }, { 396, 138, 138 }, { 14, 258, 65 }, { 14, 258, 65 }, { 127, 258, 65 }, { 347, 257, 257 }, { 14, 258, 65 } };
u8 D_80801640_badata [36] BT_DATA(4, overlays_ba_data, 0x5E0) = { 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0 };
u8 D_80801664_badata [36] BT_DATA(4, overlays_ba_data, 0x604) = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 };
BtIntPtr D_80801688_badata [36] BT_DATA(4, overlays_ba_data, 0x628) = { 0, 0, 0, 0, 0, 0, (BtIntPtr)_bswalk_entrypoint_22, 0, 0, 0, 0, 0, 0, 0, 0, (BtIntPtr)_bswalk_entrypoint_22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (BtIntPtr)_bsfirstp_entrypoint_25, 0, 0, 0, 0, 0, (BtIntPtr)_bswalk_entrypoint_22 };
BaData_3 D_80801718_badata [36] BT_DATA(4, overlays_ba_data, 0x6B8) = { { 93, 853, 1.0f, 0.5f, 0.5f }, { 147, 316, 0.43f, 0.0f, 1.0f }, { 387, 95, 0.3f, 0.0f, 1.0f }, { 147, 316, 0.43f, 0.0f, 1.0f }, { 152, 104, 0.35f, 0.0f, 1.0f }, { 152, 104, 0.35f, 0.0f, 1.0f }, { 152, 104, 0.35f, 0.0f, 1.0f }, { 152, 104, 0.35f, 0.0f, 1.0f }, { 152, 104, 0.35f, 0.0f, 1.0f }, { 155, 104, 0.35f, 0.0f, 1.0f }, { 152, 104, 0.35f, 0.0f, 1.0f }, { 157, 482, 1.0f, 0.34f, 0.34f }, { 152, 104, 0.35f, 0.0f, 1.0f }, { 152, 104, 0.35f, 0.0f, 1.0f }, { 172, 290, 1.0f, 0.63f, 0.63f }, { 152, 104, 0.35f, 0.0f, 1.0f }, { 147, 316, 0.43f, 0.0f, 1.0f }, { 245, 187, 1.0f, 0.57f, 0.57f }, { 243, 187, 1.0f, 0.57f, 0.57f }, { 254, 495, 1.0f, 0.5f, 0.5f }, { 261, 229, 1.0f, 0.5f, 0.5f }, { 275, 237, 1.0f, 0.35f, 0.35f }, { 304, 303, 0.5f, 0.5f, 0.5f }, { 147, 316, 0.43f, 0.0f, 1.0f }, { 317, 465, 1.0f, 0.71f, 0.71f }, { 329, 465, 1.0f, 0.71f, 0.71f }, { 147, 316, 0.43f, 0.0f, 1.0f }, { 147, 316, 0.43f, 0.0f, 1.0f }, { 152, 104, 0.35f, 0.0f, 1.0f }, { 206, 104, 0.35f, 0.0f, 1.0f }, { 157, 482, 1.0f, 0.34f, 0.34f }, { 152, 104, 0.35f, 0.0f, 1.0f }, { 152, 104, 0.35f, 0.0f, 1.0f }, { 152, 104, 0.35f, 0.0f, 1.0f }, { 147, 316, 0.43f, 0.0f, 1.0f }, { 152, 104, 0.35f, 0.0f, 1.0f } };
BaData_1 D_80801958_badata [36] BT_DATA(4, overlays_ba_data, 0x8F8) = { { 93, 854, 0.38f }, { 92, 640, 0.38f }, { 387, 94, 0.38f }, { 378, 170, 0.38f }, { 150, 87, 1.2f }, { 151, 112, 2.0f }, { 152, 41, 0.38f }, { 153, 56, 0.38f }, { 154, 38, 0.38f }, { 155, 65, 0.38f }, { 110, 649, 1.0f }, { 157, 478, 3.0f }, { 152, 178, 0.38f }, { 164, 35, 0.38f }, { 172, 99, 0.38f }, { 152, 41, 0.38f }, { 147, 164, 0.38f }, { 245, 188, 0.38f }, { 243, 181, 0.38f }, { 254, 494, 6.5f }, { 261, 229, 0.38f }, { 275, 236, 0.38f }, { 304, 302, 0.38f }, { 312, 236, 0.38f }, { 317, 466, 8.5f }, { 329, 466, 8.5f }, { 342, 306, 0.38f }, { 102, 313, 0.38f }, { 64, 115, 0.38f }, { 206, 782, 0.38f }, { 157, 476, 0.38f }, { 152, 41, 0.38f }, { 152, 41, 0.38f }, { 151, 112, 2.0f }, { 398, 317, 0.8f }, { 152, 41, 0.38f } };
BaData_1 D_80801A78_badata [36] BT_DATA(4, overlays_ba_data, 0xA18) = { { 93, 857, 0.4f }, { 92, 640, 0.8f }, { 387, 95, 0.6f }, { 378, 170, 0.62f }, { 150, 57, 0.8f }, { 151, 113, 0.75f }, { 152, 3, 0.43f }, { 153, 56, 0.62f }, { 154, 21, 0.53f }, { 155, 66, 0.8f }, { 110, 324, 0.9f }, { 157, 477, 0.38f }, { 152, 3, 0.43f }, { 164, 17, 0.53f }, { 172, 98, 0.4f }, { 152, 3, 0.43f }, { 147, 167, 0.43f }, { 245, 179, 0.43f }, { 243, 156, 0.75f }, { 254, 485, 0.8f }, { 261, 226, 0.5f }, { 275, 236, 0.5f }, { 304, 303, 0.5f }, { 312, 166, 0.5f }, { 317, 462, 0.6f }, { 329, 462, 0.6f }, { 342, 306, 0.5f }, { 102, 313, 0.7f }, { 64, 115, 0.5f }, { 206, 782, 0.5f }, { 157, 476, 0.38f }, { 94, 326, 0.7f }, { 96, 632, 0.5f }, { 151, 113, 0.75f }, { 398, 317, 0.8f }, { 152, 3, 0.43f } };
BaData_1 D_80801B98_badata [36] BT_DATA(4, overlays_ba_data, 0xB38) = { { 93, 854, 3.9f }, { 92, 640, 0.8f }, { 387, 94, 1.2f }, { 378, 170, 0.62f }, { 150, 87, 1.2f }, { 151, 112, 2.0f }, { 152, 4, 4.5f }, { 153, 56, 0.62f }, { 154, 38, 1.2f }, { 155, 65, 1.0f }, { 110, 649, 1.0f }, { 157, 478, 3.0f }, { 152, 178, 2.64f }, { 164, 35, 1.0f }, { 172, 99, 1.0f }, { 152, 4, 4.5f }, { 147, 164, 6.5f }, { 245, 181, 5.5f }, { 243, 181, 5.5f }, { 254, 494, 6.5f }, { 261, 229, 6.5f }, { 275, 236, 1.0f }, { 304, 302, 6.0f }, { 312, 166, 0.5f }, { 317, 466, 8.5f }, { 329, 466, 8.5f }, { 342, 306, 0.5f }, { 102, 313, 0.7f }, { 64, 115, 0.5f }, { 206, 782, 0.5f }, { 157, 476, 0.38f }, { 94, 659, 2.7f }, { 96, 631, 2.0f }, { 151, 112, 2.0f }, { 398, 317, 0.8f }, { 152, 4, 4.5f } };
BaData_1 D_80801CB8_badata [36] BT_DATA(4, overlays_ba_data, 0xC58) = { { 93, 854, 3.9f }, { 92, 640, 0.8f }, { 387, 94, 1.2f }, { 378, 170, 0.62f }, { 150, 87, 1.2f }, { 151, 112, 2.0f }, { 152, 4, 4.5f }, { 153, 56, 0.62f }, { 154, 38, 1.2f }, { 155, 65, 1.0f }, { 110, 649, 1.0f }, { 157, 478, 3.0f }, { 152, 178, 2.64f }, { 164, 35, 1.0f }, { 172, 99, 1.0f }, { 152, 4, 4.5f }, { 147, 164, 6.5f }, { 245, 181, 5.5f }, { 243, 181, 5.5f }, { 254, 494, 4.5f }, { 261, 229, 6.5f }, { 275, 236, 1.0f }, { 304, 302, 6.0f }, { 312, 166, 0.5f }, { 317, 466, 8.5f }, { 329, 466, 8.5f }, { 342, 306, 0.5f }, { 102, 313, 0.7f }, { 64, 115, 0.5f }, { 205, 781, 0.5f }, { 157, 476, 0.38f }, { 94, 659, 2.7f }, { 96, 631, 2.0f }, { 151, 112, 2.0f }, { 398, 317, 0.8f }, { 152, 4, 4.5f } };
BaData_1 D_80801DD8_badata [36] BT_DATA(4, overlays_ba_data, 0xD78) = { { 93, 854, 3.9f }, { 92, 640, 0.8f }, { 387, 94, 1.2f }, { 378, 170, 0.62f }, { 150, 87, 1.2f }, { 151, 112, 2.0f }, { 152, 111, 5.5f }, { 153, 56, 0.62f }, { 154, 38, 1.2f }, { 155, 65, 1.0f }, { 110, 649, 1.0f }, { 157, 478, 3.0f }, { 152, 178, 2.64f }, { 164, 35, 1.0f }, { 172, 99, 6.1f }, { 152, 111, 5.5f }, { 147, 164, 6.5f }, { 245, 181, 6.03f }, { 243, 157, 2.8f }, { 254, 494, 6.5f }, { 261, 229, 6.5f }, { 275, 236, 1.0f }, { 304, 302, 6.0f }, { 312, 164, 6.5f }, { 317, 466, 8.5f }, { 329, 466, 8.5f }, { 342, 306, 0.5f }, { 102, 313, 0.7f }, { 64, 115, 0.5f }, { 205, 781, 0.5f }, { 157, 476, 0.38f }, { 94, 659, 2.7f }, { 96, 631, 2.0f }, { 151, 112, 2.0f }, { 398, 317, 0.8f }, { 152, 111, 5.5f } };
BaData_1 D_80801EF8_badata [36] BT_DATA(4, overlays_ba_data, 0xE98) = { { 93, 854, 3.9f }, { 92, 640, 0.8f }, { 387, 95, 0.6f }, { 378, 170, 0.62f }, { 150, 185, 0.7f }, { 151, 185, 0.7f }, { 152, 185, 0.7f }, { 153, 185, 0.7f }, { 154, 21, 0.53f }, { 155, 66, 0.8f }, { 110, 185, 0.7f }, { 157, 478, 3.0f }, { 152, 3, 0.43f }, { 164, 17, 0.53f }, { 172, 99, 0.6f }, { 152, 185, 0.7f }, { 147, 167, 0.43f }, { 245, 179, 0.43f }, { 243, 156, 0.75f }, { 254, 485, 0.43f }, { 261, 226, 0.5f }, { 275, 236, 0.5f }, { 304, 303, 0.5f }, { 312, 164, 6.5f }, { 317, 466, 8.5f }, { 329, 466, 8.5f }, { 342, 306, 0.5f }, { 102, 313, 0.7f }, { 64, 115, 0.5f }, { 206, 782, 0.5f }, { 157, 476, 0.38f }, { 94, 185, 0.7f }, { 96, 185, 0.7f }, { 151, 185, 0.7f }, { 398, 317, 0.8f }, { 152, 185, 0.7f } };
BaData_1 D_80802018_badata [36] BT_DATA(4, overlays_ba_data, 0xFB8) = { { 93, 854, 3.9f }, { 147, 316, 0.43f }, { 387, 95, 0.6f }, { 147, 316, 0.43f }, { 152, 104, 0.35f }, { 151, 113, 0.75f }, { 152, 104, 0.35f }, { 152, 104, 0.35f }, { 152, 104, 0.35f }, { 152, 104, 0.35f }, { 152, 104, 0.35f }, { 157, 478, 3.0f }, { 152, 104, 0.35f }, { 152, 104, 0.35f }, { 172, 99, 0.6f }, { 152, 104, 0.35f }, { 147, 316, 0.43f }, { 245, 188, 0.25f }, { 245, 188, 0.25f }, { 254, 485, 0.43f }, { 261, 226, 0.5f }, { 275, 236, 0.5f }, { 304, 303, 0.5f }, { 312, 164, 6.5f }, { 317, 466, 8.5f }, { 329, 466, 8.5f }, { 342, 306, 0.5f }, { 147, 316, 0.43f }, { 64, 115, 0.5f }, { 206, 782, 0.5f }, { 157, 476, 0.38f }, { 152, 104, 0.35f }, { 152, 104, 0.35f }, { 151, 113, 0.75f }, { 147, 316, 0.43f }, { 152, 104, 0.35f } };
BaData_1 D_80802138_badata [36] BT_DATA(4, overlays_ba_data, 0x10D8) = { { 146, 854, 3.9f }, { 78, 329, 1.0f }, { 389, 94, 1.2f }, { 376, 0, 0.0f }, { 119, 87, 1.2f }, { 120, 112, 2.0f }, { 115, 80, 11.4f }, { 118, 0, 0.0f }, { 121, 0, 0.0f }, { 98, 65, 1.0f }, { 128, 649, 1.0f }, { 107, 478, 3.0f }, { 158, 0, 0.0f }, { 115, 80, 11.4f }, { 177, 99, 6.1f }, { 115, 111, 5.5f }, { 143, 16, 9.6f }, { 246, 181, 6.03f }, { 242, 157, 2.8f }, { 112, 494, 6.5f }, { 267, 229, 6.5f }, { 281, 236, 1.0f }, { 303, 302, 6.0f }, { 311, 164, 6.5f }, { 322, 466, 8.5f }, { 334, 466, 8.5f }, { 341, 306, 0.5f }, { 101, 313, 0.7f }, { 160, 114, 1.2f }, { 208, 0, 1.0f }, { 141, 476, 0.38f }, { 95, 659, 2.7f }, { 97, 631, 2.0f }, { 120, 112, 2.0f }, { 397, 0, 0.0f }, { 399, 85, 4.5f } };
BaData_1 D_80802258_badata [36] BT_DATA(4, overlays_ba_data, 0x11F8) = { { 146, 854, 3.9f }, { 78, 329, 1.0f }, { 389, 94, 1.2f }, { 376, 0, 0.0f }, { 119, 87, 1.2f }, { 120, 112, 2.0f }, { 116, 111, 5.5f }, { 118, 0, 0.0f }, { 121, 0, 0.0f }, { 98, 65, 1.0f }, { 128, 649, 1.0f }, { 107, 478, 3.0f }, { 158, 0, 0.0f }, { 116, 111, 5.5f }, { 177, 99, 6.1f }, { 116, 111, 5.5f }, { 143, 164, 6.5f }, { 246, 181, 6.03f }, { 242, 157, 2.8f }, { 112, 494, 6.5f }, { 267, 229, 6.5f }, { 281, 236, 1.0f }, { 303, 302, 6.0f }, { 311, 164, 6.5f }, { 322, 466, 8.5f }, { 334, 466, 8.5f }, { 341, 306, 0.5f }, { 101, 313, 0.7f }, { 160, 114, 1.2f }, { 207, 0, 1.0f }, { 141, 476, 0.38f }, { 95, 659, 2.7f }, { 97, 631, 2.0f }, { 120, 112, 2.0f }, { 397, 0, 0.0f }, { 399, 85, 4.5f } };
BaData_1 D_80802378_badata [36] BT_DATA(4, overlays_ba_data, 0x1318) = { { 146, 854, 3.9f }, { 78, 329, 1.0f }, { 389, 94, 1.2f }, { 376, 0, 0.0f }, { 119, 87, 1.2f }, { 120, 112, 2.0f }, { 117, 80, 11.4f }, { 118, 0, 0.0f }, { 121, 0, 0.0f }, { 98, 65, 1.0f }, { 128, 649, 1.0f }, { 107, 478, 3.0f }, { 158, 0, 0.0f }, { 116, 111, 5.5f }, { 177, 99, 6.1f }, { 117, 111, 5.5f }, { 143, 16, 9.6f }, { 246, 181, 6.03f }, { 242, 157, 2.8f }, { 112, 494, 6.5f }, { 267, 229, 6.5f }, { 281, 236, 1.0f }, { 303, 302, 6.0f }, { 311, 164, 6.5f }, { 322, 466, 8.5f }, { 334, 466, 8.5f }, { 341, 306, 0.5f }, { 101, 313, 0.7f }, { 160, 114, 1.2f }, { 208, 0, 1.0f }, { 141, 476, 0.38f }, { 95, 659, 2.7f }, { 97, 631, 2.0f }, { 120, 112, 2.0f }, { 397, 0, 0.0f }, { 399, 85, 4.5f } };
BaData_4 D_80802498_badata [36] BT_DATA(4, overlays_ba_data, 0x1438) = { { 857, 857, 1.0f, 1.0f }, { 656, 657, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 99, 99, 6.1f, 6.1f }, { 90, 89, 0.2f, 0.2f }, { 656, 657, 0.2f, 0.2f }, { 186, 186, 0.5f, 0.5f }, { 186, 186, 0.5f, 0.5f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 238, 238, 1.0f, 1.0f }, { 90, 89, 0.2f, 0.2f }, { 656, 657, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 656, 657, 0.2f, 0.2f }, { 656, 657, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f }, { 90, 89, 0.2f, 0.2f } };
BaData_4 D_80802648_badata [36] BT_DATA(4, overlays_ba_data, 0x15E8) = { { 857, 0, 0.0f, 1.0f }, { 640, 0, 0.0f, 1.0f }, { 94, 0, 0.0f, 0.99f }, { 170, 0, 0.0f, 1.0f }, { 57, 0, 0.0f, 1.0f }, { 113, 0, 0.0f, 1.0f }, { 8, 0, 0.3f, 0.66f }, { 56, 0, 0.0f, 1.0f }, { 21, 0, 0.2f, 0.82f }, { 66, 0, 0.0f, 1.0f }, { 649, 0, 0.0f, 1.0f }, { 476, 0, 0.0f, 1.0f }, { 3, 0, 0.0f, 1.0f }, { 17, 0, 0.0f, 1.0f }, { 99, 0, 0.0f, 1.0f }, { 8, 0, 0.3f, 0.66f }, { 169, 0, 0.3f, 0.7f }, { 179, 0, 0.0f, 1.0f }, { 156, 0, 0.0f, 1.0f }, { 485, 0, 0.0f, 1.0f }, { 226, 0, 0.0f, 1.0f }, { 236, 0, 0.0f, 1.0f }, { 303, 0, 0.0f, 1.0f }, { 166, 0, 0.0f, 1.0f }, { 462, 0, 0.0f, 1.0f }, { 462, 0, 0.0f, 1.0f }, { 306, 0, 0.0f, 1.0f }, { 313, 0, 0.0f, 1.0f }, { 115, 0, 0.0f, 1.0f }, { 782, 0, 0.0f, 1.0f }, { 476, 0, 0.0f, 1.0f }, { 104, 0, 0.0f, 1.0f }, { 104, 0, 0.0f, 1.0f }, { 113, 0, 0.0f, 1.0f }, { 170, 0, 0.0f, 1.0f }, { 8, 0, 0.3f, 0.66f } };
