#ifndef SU_BADDIEDIALOG_DESCRIPTOR_H
#define SU_BADDIEDIALOG_DESCRIPTOR_H

#include "common.h"

typedef struct {
	/* 0x00 */ u16 unk0;
	/* 0x02 */ u16 unk2;
	/* 0x04 */ u16 unk4;
	/* 0x06 */ u16 unk6;
	/* 0x08 */ u32 unk8;
	/* 0x0C */ u16 unkC;
	/* 0x0E */ u16 unkE;
	/* 0x10 */ s16 unk10;
	/* 0x12 */ u16 unk12;
	/* 0x14 */ u16 unk14;
	/* 0x16 */ u8 unk16;
	/* 0x17 */ u8 unk17;
	/* 0x18 */ u8 unk18;
}subaddiedialog_UnkStruct0;

typedef struct {
	/* 0x00 */ u32 TransformationType;
	/* 0x04 */ s16 unk4;
	/* 0x06 */ u8 unk6;
	/* 0x07 */ u8 unk7;
}subaddiedialog_UnkStruct1;

typedef struct {
	/* 0x00 */ u16 DialogFlag;//Dialog Flag
	/* 0x02 */ u16 unk2;
	/* 0x04 */ u16 unk4;
	/* 0x06 */ s16 unk6;
	/* 0x08 */ u16 unk8;
	/* 0x0A */ u16 unkA;
	/* 0x0C */ u8 unkC;
	/* 0x0D */ u8 unkD;
	/* 0x0E */ u8 unkE;

}subaddiedialog_UnkStruct2;

#endif
