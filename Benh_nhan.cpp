//Nguyễn Nhật Hoàng Anh
#include "BENHNHAN.h"

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void InitBN(DSBN &dsbn){
	dsbn = NULL;
}
int IsEmpty(DSBN dsbn){
	return(dsbn == NULL);
}
//In 1 phan tu
void PrintfBN(Benh_nhan benh_nhan){
	cout<<"Ho va ten:"<<benh_nhan.Ho_tenBN<<endl;
	cout<<"Tuoi:";
	cout<<benh_nhan.Tuoi<<endl;
	cout<<"Gioi tinh:";
	cout<<benh_nhan.Gioi_tinh<<endl;
	cout<<"Que quan: ";
	cout<<benh_nhan.Que<<endl;
	cout<<"So CCCD: "; 
	cout<<benh_nhan.CCCD<<endl;
	cout<<"BHYT:"<<(benh_nhan.Bao_hiem == 1 ? "Co" : "Khong") << endl;
	
}
//In DS
void Printf(DSBN dsbn){
	BNNODE R = dsbn;
	cout<<"\t"<<"***"<<"DANH SACH BENH NHAN"<<"***"<<endl;
	while(R != NULL){
		PrintfBN(R->BN);
		R = R->nextBN;
	}
	return;
}
//Tao ra 1 NODE moi bang cach nhap tu ban phim vao
Benh_nhan Create() {
    Benh_nhan A;
    cin.ignore();
    cout << "Ho va ten:";
    getline(cin, A.Ho_tenBN);
    cout << "Tuoi:";
    cin >> A.Tuoi;
    cout << "Gioi tinh:";
    cin >> A.Gioi_tinh;
    cin.ignore();
    cout << "Que quan: ";
    getline(cin, A.Que);
    cout << "So CCCD: "; 
    cin >> A.CCCD;
    cout << "SĐT:"; cin >> A.SDT;
    cout << "BHYT (1. Co, 0. Khong):" << endl;
    cin >> A.Bao_hiem;
    cout<<"Nhap ten dich vu"<<endl;
    string name;
    cin.ignore();
    getline(cin,name); 
    Dich_vu service;
    service = FindDV(A.DV,name);
    InsertDV(A.DV,service);
    return A;
}
//Nhap benh nhan tu vao DS 
void InsertBN(DSBN& dsbn){
	BNNODE P = new NODEBN;
    P->BN = Create();
    P->nextBN = dsbn;
    dsbn = P;
}
//Tim benh nhan voi so cccd cho truoc 
BNNODE FindBN(DSBN dsbn,string cccd){
	BNNODE R = dsbn;
	while( R != NULL){
		if(R->BN.CCCD == cccd) return R;
		R = R->nextBN;
	}
	cout <<"Khong tim thay BN"<<endl;
	return NULL;
}
//Tim BN o truoc benh nhan voi so cccd cho truoc 
BNNODE FindBNBefore(DSBN dsbn,string cccd){
	BNNODE R = dsbn;
	while( R != NULL){
		if(R->nextBN->BN.CCCD == cccd) return R;
		R = R->nextBN;
	}
	cout <<"Khong tim thay BN"<<endl;
	return NULL;
}
// Xoa 1 BN voi so cccd cho truoc 
void DeleteBN(DSBN& dsbn, string cccd){
	BNNODE P = FindBNBefore(dsbn,cccd);
	BNNODE Q = FindBN(dsbn,cccd);
	if(P == NULL)return;
	if(dsbn == Q)dsbn = dsbn->nextBN;
	P = P->nextBN;
	delete Q;
}
//Sua thong tin benh nhan 
void fixBN(DSBN& dsbn, string cccd) {
    BNNODE P = FindBN(dsbn, cccd);
    
    if (P != NULL) {
        cout << "Nhap thong tin moi cho benh nhan:" << endl;
        cout << "Ho va ten: ";
        getline(cin, P->BN.Ho_tenBN);
        cout << "Tuoi: ";
        cin >> P->BN.Tuoi;
        cout << "Gioi tinh: ";
        cin >> P->BN.Gioi_tinh;
        cin.ignore(); 
        cout << "Que: ";
        getline(cin, P->BN.Que);
        cout << "CCCD: ";
        cin >> P->BN.CCCD;
        cout << "BHYT (1. Co, 0. Khong): ";
        cin >> P->BN.Bao_hiem;
        cout << "Thong tin thay doi thanh cong!" << endl;
        cin.ignore();
    } else {
        return; 
    }
}
// sap xep BN 
void ArrangeBN(DSBN& dsbn) {
    if (dsbn == NULL) return; // Danh s ch r?ng, kh ng c?n s?p x?p
    
    int check;
    do{
        check = 0;
        BNNODE mid = dsbn;
        BNNODE last = NULL;
        BNNODE next = dsbn->nextBN;

        while (next != NULL) {
            if (mid->BN.Ho_tenBN > next->BN.Ho_tenBN) {
                if (last == NULL) { 
                    dsbn = next;
                }
				else {
                    last->nextBN = next;
                }
                mid->nextBN = next->nextBN;
                next->nextBN = mid;
                // Cap nhap gia tri 
				check = 0;
                mid = next;
                next = mid->nextBN;
            } 
			else {
                last = mid;
                mid = next;
                next = next->nextBN;
            }
        }
    } while (check);
}

long SumBN(DSBN S){
	return S->BN.DV->TongtienDV + S->BN.T->TongtienT;
}

void printfBN(DSBN S) {
    cout << "\n\tThong tin benh nhan:" << endl;
    if (S == NULL) {
        cout << "Danh sach benh nhan rong." << endl;
        return;
    }
    
    DSBN R = S;
    const int numRows = 3;
    const int numCols = 2;

    while (R != NULL) {
        string arr[numRows][numCols];
        arr[0][0] = "Ho ten: " + R->BN.Ho_tenBN;
        arr[0][1] = "Gioi tinh: " + R->BN.Gioi_tinh;
        arr[1][0] = "Tuoi: " + to_string(R->BN.Tuoi);
        arr[1][1] = "CCCD: " + R->BN.CCCD;
        arr[2][0] = "SDT: " + R->BN.SDT;
        arr[2][1] = "Que: " + R->BN.Que;

        for (int j = 0; j < numRows; j++) {
            for (int k = 0; k < numCols; k++) {
                cout << arr[j][k] << "\t";
            }
            cout << endl;
        }
        cout << "Bao hiem: " << R->BN.Bao_hiem << endl;
        cout << "\tDanh Sach Dich Vu\n";
        printfDV(R->BN.DV);
        printfT(R->BN.T);
        cout << "Tong vien phi: " << SumBN(S) << endl;
        if(R->BN.Bao_hiem == 1){
        	cout << "Phai tra: " << (SumBN(S)*20)/100;
		}else{
			cout << "Phai tra: " << SumBN(S);
		}
        R = R->nextBN;
    }
}
