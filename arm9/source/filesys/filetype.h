#pragma once

#include "common.h"

#define IMG_FAT     (1ULL<<0)
#define IMG_NAND    (1ULL<<1)
#define GAME_CIA    (1ULL<<2)
#define GAME_NCSD   (1ULL<<3)
#define GAME_NCCH   (1ULL<<4)
#define GAME_TMD    (1ULL<<5)
#define GAME_CDNTMD (1ULL<<6)
#define GAME_TWLTMD (1ULL<<7)
#define GAME_CMD    (1ULL<<8)
#define GAME_EXEFS  (1ULL<<9)
#define GAME_ROMFS  (1ULL<<10)
#define GAME_BOSS   (1ULL<<11)
#define GAME_NUSCDN (1ULL<<12)
#define GAME_TICKET (1ULL<<13)
#define GAME_TIE    (1ULL<<14)
#define GAME_SMDH   (1ULL<<15)
#define GAME_3DSX   (1ULL<<16)
#define GAME_NDS    (1ULL<<17)
#define GAME_GBA    (1ULL<<18)
#define GAME_TAD    (1ULL<<19)
#define SYS_FIRM    (1ULL<<20)
#define SYS_DIFF    (1ULL<<21)
#define SYS_DISA    (1ULL<<22)
#define SYS_AGBSAVE (1ULL<<23)
#define SYS_TICKDB  (1ULL<<24)
#define BIN_NCCHNFO (1ULL<<25)
#define BIN_TIKDB   (1ULL<<26)
#define BIN_KEYDB   (1ULL<<27)
#define BIN_LEGKEY  (1ULL<<28)
#define TXT_SCRIPT  (1ULL<<29)
#define TXT_GENERIC (1ULL<<30)
#define GFX_PNG     (1ULL<<31)
#define FONT_PBM    (1ULL<<32)
#define NOIMG_NAND  (1ULL<<33)
#define HDR_NAND    (1ULL<<34)
#define TYPE_BASE   0xFFFFFFFFFFULL // 40 bit reserved for base types

// #define FLAG_FIRM   (1ULL<<58) // <--- for CXIs containing FIRMs
// #define FLAG_GBAVC  (1ULL<<59) // <--- for GBAVC CXIs
#define FLAG_DSIW   (1ULL<<60)
#define FLAG_ENC    (1ULL<<61)
#define FLAG_CTR    (1ULL<<62)
#define FLAG_CXI    (1ULL<<63)

#define FTYPE_MOUNTABLE(tp)     (tp&(IMG_FAT|IMG_NAND|GAME_CIA|GAME_NCSD|GAME_NCCH|GAME_EXEFS|GAME_ROMFS|GAME_NDS|GAME_TAD|SYS_FIRM|SYS_DIFF|SYS_DISA|SYS_TICKDB|BIN_KEYDB))
#define FTYPE_VERIFICABLE(tp)   (tp&(IMG_NAND|GAME_CIA|GAME_NCSD|GAME_NCCH|GAME_TMD|GAME_CDNTMD|GAME_TWLTMD|GAME_TIE|GAME_TAD|GAME_TICKET|GAME_BOSS|SYS_FIRM))
#define FTYPE_DECRYPTABLE(tp)   (tp&(GAME_CIA|GAME_NCSD|GAME_NCCH|GAME_BOSS|GAME_NUSCDN|SYS_FIRM|BIN_KEYDB))
#define FTYPE_ENCRYPTABLE(tp)   (tp&(GAME_CIA|GAME_NCSD|GAME_NCCH|GAME_BOSS|BIN_KEYDB))
#define FTYPE_CIABUILD(tp)      ((tp&(GAME_NCSD|GAME_NCCH|GAME_TMD|GAME_CDNTMD|GAME_TWLTMD|GAME_TIE|GAME_TAD)) || ((tp&GAME_NDS)&&(tp&(FLAG_DSIW))))
#define FTYPE_CIABUILD_L(tp)    (tp&(GAME_TMD|GAME_CDNTMD|GAME_TIE|GAME_TAD))
#define FTYPE_CIAINSTALL(tp)    ((tp&(GAME_NCSD|GAME_NCCH|GAME_CIA|GAME_CDNTMD|GAME_TWLTMD)) || ((tp&GAME_NDS)&&(tp&(FLAG_DSIW))))
#define FTYPE_TIKINSTALL(tp)    (tp&(GAME_TICKET))
#define FTYPE_TIKDUMP(tp)       (tp&(GAME_TIE))
#define FTYPE_CXIDUMP(tp)       (tp&(GAME_TMD))
#define FTYPE_UNINSTALL(tp)     (tp&(GAME_TIE))
#define FTYPE_TIKBUILD(tp)      (tp&(GAME_TICKET|SYS_TICKDB|BIN_TIKDB))
#define FTYPE_KEYBUILD(tp)      (tp&(BIN_KEYDB|BIN_LEGKEY))
#define FTYPE_TITLEINFO(tp)     (tp&(GAME_TIE|GAME_TICKET|GAME_SMDH|GAME_NCCH|GAME_NCSD|GAME_CIA|GAME_TMD|GAME_CDNTMD|GAME_TWLTMD|GAME_NDS|GAME_GBA|GAME_TAD|GAME_3DSX))
#define FTYPE_RENAMABLE(tp)     (tp&(GAME_NCCH|GAME_NCSD|GAME_CIA|GAME_NDS|GAME_GBA))
#define FTYPE_TRIMABLE(tp)      (tp&(IMG_NAND|GAME_NCCH|GAME_NCSD|GAME_NDS|GAME_GBA|SYS_FIRM))
#define FTYPE_TRANSFERABLE(tp)  ((u64) (tp&(IMG_FAT|FLAG_CTR)) == (u64) (IMG_FAT|FLAG_CTR))
#define FTYPE_NCSDFIXABLE(tp)   (tp&(HDR_NAND|NOIMG_NAND))
#define FTYPE_HASCODE(tp)       (((u64) (tp&(GAME_NCCH|FLAG_CXI)) == (u64) (GAME_NCCH|FLAG_CXI))|(tp&GAME_NCSD))
#define FTYPE_ISDISADIFF(tp)    (tp&(SYS_DIFF|SYS_DISA))
#define FTYPE_RESTORABLE(tp)    (tp&(IMG_NAND))
#define FTYPE_EBACKUP(tp)       (tp&(IMG_NAND))
// #define FTYPE_XORPAD(tp)        (tp&(BIN_NCCHNFO)) // deprecated
#define FTYPE_XORPAD(tp)        0
#define FTYPE_KEYINIT(tp)       (tp&(BIN_KEYDB))
#define FTYPE_KEYINSTALL(tp)    (tp&(BIN_KEYDB))
#define FTYPE_SCRIPT(tp)        (tp&(TXT_SCRIPT))
#define FTYPE_FONT(tp)          (tp&(FONT_PBM))
#define FTYPE_GFX(tp)           (tp&(GFX_PNG))
#define FTYPE_SETABLE(tp)       (tp&(FONT_PBM))
#define FTYPE_BOOTABLE(tp)      (tp&(SYS_FIRM))
#define FTYPE_INSTALLABLE(tp)   (tp&(SYS_FIRM))
#define FTYPE_AGBSAVE(tp)       (tp&(SYS_AGBSAVE))

u64 IdentifyFileType(const char* path);
