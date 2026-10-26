#include "common.h"

typedef struct {
    u32 unk0;
    u32 trackCount;
} AudioSeqHeader;

typedef struct {
    AudioSeqHeader *base;
    u32 validTracks;
    f32 qnpt;
    u32 lastTicks;
    u32 lastDeltaTicks;
    u32 deltaFlag;
    u8 *curLoc[32];
    u8 *curBUPtr[32];
    u8 curBULen[32];
    u8 lastStatus[32];
    u32 evtDeltaTicks[32];
} AudioSeq;

typedef struct {
    u32 validTracks;
    u32 lastTicks;
    u32 lastDeltaTicks;
    u8 *curLoc[32];
    u8 *curBUPtr[32];
    u8 curBULen[32];
    u8 lastStatus[32];
    u32 evtDeltaTicks[32];
} AudioSeqMarker;

void func_80024EE0(AudioSeq *seq, AudioSeqHeader *header) {
    u32 func_80025DE4(AudioSeq *, u32);
    u32 track;
    u32 offset;
    u32 mask;

    seq->base = header;
    seq->validTracks = 0;
    seq->lastDeltaTicks = 0;
    seq->lastTicks = 0;
    seq->deltaFlag = 1;
    for (track = 0; track < seq->base->trackCount; track++) {
        seq->lastStatus[track] = 0;
        seq->curBUPtr[track] = NULL;
        seq->curBULen[track] = 0;
        offset = ((u32 *)seq->base)[track + 2];
        if (offset != 0) {
            mask = 1 << track;
            seq->validTracks |= mask;
            seq->curLoc[track] = (u8 *)header + offset;
            seq->evtDeltaTicks[track] = func_80025DE4(seq, track);
        } else {
            seq->curLoc[track] = NULL;
        }
    }
    seq->qnpt = 1.0f / (f32)seq->base->unk0;
}

void func_80025084(AudioSeq *seq, ALEvent *evt, s32 arg2) {
    s32 func_80025224(AudioSeq *, u32, ALEvent *, s32);
    u32 func_80025DE4(AudioSeq *, u32);
    u32 i;
    u32 firstTime = -1U;
    u32 firstTrack;
    u32 lastTicks = seq->lastDeltaTicks;

    for (i = 0; i < seq->base->trackCount; i++) {
        if ((seq->validTracks >> i) & 1) {
            if (seq->deltaFlag) {
                seq->evtDeltaTicks[i] -= lastTicks;
            }
            if (seq->evtDeltaTicks[i] < firstTime) {
                firstTime = seq->evtDeltaTicks[i];
                firstTrack = i;
            }
        }
    }
    func_80025224(seq, firstTrack, evt, arg2);
    evt->msg.midi.ticks = firstTime;
    seq->lastTicks += firstTime;
    seq->lastDeltaTicks = firstTime;
    if (evt->type != 0x12) {
        seq->evtDeltaTicks[firstTrack] += func_80025DE4(seq, firstTrack);
    }
    seq->deltaFlag = 1;
}

s32 func_80025224(AudioSeq *arg0, u32 arg1, ALEvent *arg2, s32 arg3) {
    u32 func_80025BF0(AudioSeq *, u32);
    u32 func_80025DE4(AudioSeq *, u32);
    s32 offset;
    u8 status;
    u8 loopCount;
    u8 currentCount;
    u8 *ptr;
    u8 type;

    status = func_80025BF0(arg0, arg1);
    if (status == 0xFF) {
        type = func_80025BF0(arg0, arg1);
        if (type == 0x51) {
            arg2->type = 3;
            arg2->msg.tempo.status = status;
            arg2->msg.tempo.type = type;
            arg2->msg.tempo.byte1 = func_80025BF0(arg0, arg1);
            arg2->msg.tempo.byte2 = func_80025BF0(arg0, arg1);
            arg2->msg.tempo.byte3 = func_80025BF0(arg0, arg1);
            arg0->lastStatus[arg1] = 0;
        } else if (type == 0x2F) {
            s32 mask = 1 << arg1;
            arg0->validTracks ^= mask;
            if (arg0->validTracks != 0) {
                arg2->type = 0x12;
            } else {
                arg2->type = 4;
            }
        } else if (type == 0x2E) {
            status = func_80025BF0(arg0, arg1);
            arg2->msg.midi.duration = status << 8;
            status = func_80025BF0(arg0, arg1);
            arg2->msg.midi.duration += status;
            arg0->lastStatus[arg1] = 0;
            arg2->type = 0x13;
        } else if (type == 0x2D) {
            ptr = arg0->curLoc[arg1];
            loopCount = *ptr++;
            currentCount = *ptr;
            if (currentCount == 0 || arg3 == 0) {
                *ptr = loopCount;
                arg0->curLoc[arg1] = ptr + 5;
            } else {
                if (currentCount != 0xFF) {
                    *ptr = currentCount - 1;
                }
                ptr++;
                offset = *ptr++ << 24;
                offset += *ptr++ << 16;
                offset += *ptr++ << 8;
                offset += *ptr++;
                arg0->curLoc[arg1] = ptr - offset;
            }
            arg0->lastStatus[arg1] = 0;
            arg2->type = 0x14;
        }
    } else {
        arg2->type = 1;
        if (status & 0x80) {
            arg2->msg.midi.status = status & 0xF0;
            arg2->msg.midi.byte1 = arg1;
            arg2->msg.midi.byte2 = func_80025BF0(arg0, arg1);
            arg0->lastStatus[arg1] = arg2->msg.midi.status;
        } else {
            arg2->msg.midi.status = arg0->lastStatus[arg1];
            arg2->msg.midi.byte2 = status;
            arg2->msg.midi.byte1 = arg1;
        }
        if ((arg2->msg.midi.status & 0xF0) != 0xC0 &&
            (arg2->msg.midi.status & 0xF0) != 0xD0) {
            arg2->msg.tempo.byte1 = func_80025BF0(arg0, arg1);
            if ((arg2->msg.midi.status & 0xF0) == 0x90) {
                arg2->msg.midi.duration = func_80025DE4(arg0, arg1);
            }
        } else {
            arg2->msg.tempo.byte1 = 0;
        }
    }
    return 1;
}

s32 func_80025668(s32 *arg0) {
    return arg0[3];
}

void func_80025680(AudioSeq *seq, AudioSeqMarker *m) {
    u32 i;

    seq->validTracks = m->validTracks;
    seq->lastTicks = m->lastTicks;
    seq->lastDeltaTicks = m->lastDeltaTicks;

    for (i = 0; i < seq->base->trackCount; i++) {
        seq->curLoc[i] = m->curLoc[i];
        seq->curBUPtr[i] = m->curBUPtr[i];
        seq->curBULen[i] = m->curBULen[i];
        seq->lastStatus[i] = m->lastStatus[i];
        seq->evtDeltaTicks[i] = m->evtDeltaTicks[i];
    }
}

void func_80025750(AudioSeq *seq, AudioSeqMarker *m) {
    u32 i;

    m->validTracks = seq->validTracks;
    m->lastTicks = seq->lastTicks;
    m->lastDeltaTicks = seq->lastDeltaTicks;

    for (i = 0; i < seq->base->trackCount; i++) {
        m->curLoc[i] = seq->curLoc[i];
        m->curBUPtr[i] = seq->curBUPtr[i];
        m->curBULen[i] = seq->curBULen[i];
        m->lastStatus[i] = seq->lastStatus[i];
        m->evtDeltaTicks[i] = seq->evtDeltaTicks[i];
    }
}

void func_80025820(AudioSeq *seq, AudioSeqMarker *m, u32 ticks) {
    void func_80024EE0(AudioSeq *, AudioSeqHeader *);
    ALEvent evt;
    AudioSeq tempSeq;
    u32 i;

    func_80024EE0(&tempSeq, seq->base);

    do {
        m->validTracks = tempSeq.validTracks;
        m->lastTicks = tempSeq.lastTicks;
        m->lastDeltaTicks = tempSeq.lastDeltaTicks;

        for (i = 0; i < seq->base->trackCount; i++) {
            m->curLoc[i] = tempSeq.curLoc[i];
            m->curBUPtr[i] = tempSeq.curBUPtr[i];
            m->curBULen[i] = tempSeq.curBULen[i];
            m->lastStatus[i] = tempSeq.lastStatus[i];
            m->evtDeltaTicks[i] = tempSeq.evtDeltaTicks[i];
        }

        func_80025084(&tempSeq, &evt, 0);

        if (evt.type == AL_SEQ_END_EVT)
            break;

    } while (tempSeq.lastTicks < ticks);
}

void func_8002597C(AudioSeq *seq, AudioSeqMarker *markers, u32 count, u32 first) {
    void func_80024EE0(AudioSeq *, AudioSeqHeader *);
    ALEvent evt;
    AudioSeq tempSeq;
    u32 i;
    s32 remaining;
    AudioSeqMarker marker;

    func_80024EE0(&tempSeq, seq->base);
    for (remaining = 0; remaining < count; remaining++) {
        markers[remaining].lastTicks = 0;
    }
    do {
        marker.validTracks = tempSeq.validTracks;
        marker.lastTicks = tempSeq.lastTicks;
        marker.lastDeltaTicks = tempSeq.lastDeltaTicks;
        for (i = 0; i < seq->base->trackCount; i++) {
            marker.curLoc[i] = tempSeq.curLoc[i];
            marker.curBUPtr[i] = tempSeq.curBUPtr[i];
            marker.curBULen[i] = tempSeq.curBULen[i];
            marker.lastStatus[i] = tempSeq.lastStatus[i];
            marker.evtDeltaTicks[i] = tempSeq.evtDeltaTicks[i];
        }
        func_80025084(&tempSeq, &evt, 0);
        if (evt.type == 0x13) {
            if (((s32)evt.msg.midi.duration >> 8) >= first &&
                ((s32)evt.msg.midi.duration >> 8) < first + count) {
                if (markers[((s32)evt.msg.midi.duration >> 8) - first].lastTicks == 0) {
                markers[((s32)evt.msg.midi.duration >> 8) - first] = marker;
                if (--remaining <= 0) {
                    return;
                }
            }
        }
        }
    } while (evt.type != AL_SEQ_END_EVT);
}

u32 func_80025BF0(AudioSeq *arg0, u32 arg1) {
    struct Stream {
        s32 header[6];
        u8 *input[32];
        u8 *repeat[32];
        u8 count[32];
    };
    volatile u8 spF, spE, spD, spC, spB;
    volatile int sp4;

    if (*(volatile u8 *)((u32)arg0 + (u32)arg1 + 0x118)) {
        spF = **(u8 *volatile *)((u32)arg0 + ((u32)arg1 << 2) + 0x98);
        ((volatile struct Stream *)arg0)->repeat[(u32)arg1] = ((volatile struct Stream *)arg0)->repeat[arg1] + 1;
        ((volatile struct Stream *)arg0)->count[(u32)arg1] = ((volatile struct Stream *)arg0)->count[arg1] - 1;
    } else {
        spF = **(u8 *volatile *)((u32)arg0 + ((u32)arg1 << 2) + 0x18);
        ((volatile struct Stream *)arg0)->input[(u32)arg1] = ((volatile struct Stream *)arg0)->input[arg1] + 1;
        if (spF == 0xFE) {
            spB = **(u8 *volatile *)((u32)arg0 + ((u32)arg1 << 2) + 0x18);
            ((volatile struct Stream *)arg0)->input[(u32)arg1] = ((volatile struct Stream *)arg0)->input[arg1] + 1;
            if (spB != 0xFE) {
                spD = spB;
                spE = **(u8 *volatile *)((u32)arg0 + ((u32)arg1 << 2) + 0x18);
                ((volatile struct Stream *)arg0)->input[(u32)arg1] = ((volatile struct Stream *)arg0)->input[arg1] + 1;
                spC = **(u8 *volatile *)((u32)arg0 + ((u32)arg1 << 2) + 0x18);
                ((volatile struct Stream *)arg0)->input[(u32)arg1] = ((volatile struct Stream *)arg0)->input[arg1] + 1;
                sp4 = spD;
                sp4 <<= 8;
                sp4 += spE;
                ((volatile struct Stream *)arg0)->repeat[(u32)arg1] = ((volatile struct Stream *)arg0)->input[arg1] - sp4 - 4;
                ((volatile struct Stream *)arg0)->count[(u32)arg1] = spC;
                spF = **(u8 *volatile *)((u32)arg0 + ((u32)arg1 << 2) + 0x98);
                ((volatile struct Stream *)arg0)->repeat[(u32)arg1] = ((volatile struct Stream *)arg0)->repeat[arg1] + 1;
                ((volatile struct Stream *)arg0)->count[(u32)arg1] = ((volatile struct Stream *)arg0)->count[arg1] - 1;
            }
        }
    }
    return spF;
}

u32 func_80025DE4(AudioSeq *seq, u32 track) {
    u32 func_80025BF0(AudioSeq *, u32);
    u32 value;
    u32 c;

    value = func_80025BF0(seq, track);
    if (value & 0x80) {
        value &= 0x7F;
        do {
            c = func_80025BF0(seq, track);
            value = (value << 7) + (c & 0x7F);
        } while (c & 0x80);
    }
    return value;
}
