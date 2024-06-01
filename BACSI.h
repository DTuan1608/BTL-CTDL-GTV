#ifndef BACSI_H
#define BACSI_H

#include <string>
#include "BENHNHAN.h"
#include "DICHVU.h"
#include "THUOC.h"
#include "BOSUNG.h"

using namespace std;

// Cấu trúc dữ liệu về bác sĩ
struct Bac_si {
    string Ho_tenBS;
    string Chuc_vu;
    string Ma_so;
    long Gia_kham;
};
struct NODEBS{
    Bac_si BS;
    int demBS;
    NODEBS* nextBS;
};
typedef NODEBS* DSBS;
typedef NODEBS* BSNODE;

// Khai báo nguyên mẫu hàm BS
void InitBS(DSBS& H);
void InsertBSS(DSBS &H, Bac_si K);
void InsertBS(DSBS &H);
void DeleteBS(DSBS &H, string hotenBS);
BSNODE FINDBS(DSBS &H, string MS);
void FixBS(DSBS& H, string MS);
void PrintBS(DSBS &H);

#endif
