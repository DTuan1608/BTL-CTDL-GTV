#ifndef DICHVU_H
#define DICHVU_H

#include <string>
#include "BENHNHAN.h"
#include "BACSI.h"
#include "THUOC.h"
#include "BOSUNG.h"

using namespace std;

struct Dich_vu {
    string Ten_DV;
    long Gia_DV;
};
struct NODEDV {
    Dich_vu DV;
    long TongtienDV;
    int demDV;
    NODEDV* nextDV;
};

typedef NODEDV* DVNODE;
typedef NODEDV* DSDV;

//Khai báo nguyên mẫu hàm dịch vụ
void InsertDV(DSDV &dsdv, Dich_vu DV);
void InitDV(DSDV& dsdv);
void DeleteDV(DSDV& dsdv, string serviceName);
Dich_vu FindDV(DSDV dsdv, string serviceName);
void ArrangeDV(DSDV& dsdv);
void FixDV(DSDV& dsdv, string serviceName, long newPrice);
long SumDV(DSDV S);
void NhapDichVu(DSDV& dsdv);
void printfDV(DSDV S);

#endif 