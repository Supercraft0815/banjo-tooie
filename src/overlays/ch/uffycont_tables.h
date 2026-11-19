typedef struct {
    s16 map;
    s16 currentFlag;
    s16 visitFlag;
    s16 prerequisite;
    s16 icon;
} ChuffyStation;

/* Scans may read the map and currentFlag fields at the terminator. The
 * next halfword is also the first audio command in the original layout. */
typedef union {
    struct {
        ChuffyStation stations[7];
        s16 terminator;
        s16 audio[8];
    } data;
    ChuffyStation scan[8];
} ChuffyStations;

extern ChuffyStations D_80800B20_chchuffycont;

BT_IDO_ONLY(extern s16 D_80800B66_chchuffycont;)
#define CHUFFY_STATION_END BT_DATA_FIELD(&D_80800B20_chchuffycont.scan[7], (ChuffyStation *)&D_80800B66_chchuffycont)
