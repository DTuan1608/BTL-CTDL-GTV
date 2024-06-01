#ifndef BENHNHAN_H
#define BENHNHAN_H

#include <string>
#include "BACSI.h"
#include "DICHVU.h"
#include "THUOC.h"
#include "BOSUNG.h"

using namespace std;

struct Benh_nhan{
    string Ho_tenBN;
    long Tuoi;
    string Gioi_tinh;
    string Que;
    string CCCD;
    string SDT;
	int DK, MK, YK; // Ngày bệnh nhân đi khám
    DSDV DV;
    DSThuoc T;
    int Bao_hiem; 
};
struct NODEBN{
	Benh_nhan BN;
	NODEBN* nextBN;
};
typedef NODEBN* BNNODE;
typedef NODEBN* DSBN;

//Khai báo nguyên mẫu hàm BN
void InitBN(DSBN &dsbn);
int IsEmpty(DSBN dsbn);
void PrintfBN(Benh_nhan benh_nhan); //In 1 phần tử
void Printf(DSBN dsbn); //In danh sách
Benh_nhan Create();//Tạo 1NODE mới bằng cách nhập từ bàn phím vào
void InsertBN(DSBN& dsbn);
long SumBN(DSBN S);
BNNODE FindBN(DSBN dsbn,string cccd);
BNNODE FindBNBefore(DSBN dsbn,string cccd);
void DeleteBN(DSBN& dsbn, string cccd);
void fixBN(DSBN& dsbn, string cccd);
void ArrangeBN(DSBN& dsbn);
void printfBN(DSBN S);
#endif