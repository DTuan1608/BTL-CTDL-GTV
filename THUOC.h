#ifndef THUOC_H
#define THUOC_H

#include <string>
#include "BENHNHAN.h"
#include "BACSI.h"
#include "DICHVU.h"
#include "BOSUNG.h"

using namespace std;

typedef struct THUOC{
    string Ten_thuoc;
    int Ma_thuoc;
    long Gia_thuoc;
    int so_luong;
} THUOC;

struct NODET{
    THUOC T;
    long TongtienT;
    int demT;
    NODET *nextT;
};
typedef NODET* NodeT;
typedef NODET* DSThuoc;

//Khai báo nguyên mẫu hàm Thuoc
void InitT(DSThuoc &T);
int emptyT(DSThuoc T);
NodeT makenodeT(THUOC T1);
NodeT FindT(DSThuoc &T, int Ma_thuoc);
void DeleteT(DSThuoc &T, int Ma_thuoc);
void FixT(DSThuoc T, int Ma_thuoc);
void ArrangeT(DSThuoc &T, THUOC T1);
void NhapThuoc(DSBN& dsbn, DSThuoc T,DSDV dsdv, BNNODE A);
long tonggiaT(THUOC);
void NhapT(DSThuoc &T);
void printfT(DSThuoc S);
long sumT(DSThuoc S);

#endif 