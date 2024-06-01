//Hà Hữu An
#include <iostream>
#include <string>
#include "BENHNHAN.h"
#include "BACSI.h"
#include "DICHVU.h"
#include "THUOC.h"
#include "BOSUNG.h" 

using namespace std;

void InitT(DSThuoc &S){
    S = NULL;
}

int emptyT(DSThuoc S){
    return S == NULL;
}

NodeT makenodeT(THUOC T1){
    NodeT node = new NODET;
    node->T = T1;
    node->nextT = NULL;
    return node;
}

NodeT FindT(DSThuoc &S, int Ma_thuoc){
    NodeT p = S;
    while (p != NULL && p->T.Ma_thuoc != Ma_thuoc){
        p = p->nextT;
    }
    if(p == NULL){
        cout << "Khong co thuoc voi ma thuoc: " << Ma_thuoc << " trong danh sach" << endl;
        return NULL;
    } else {
        return p;
    }
}

void DeleteT(DSThuoc &S, int Ma_thuoc){
    if(emptyT(S)){
        cout << "Danh Sach Thuoc Rong" << endl;
        return;
    }
    NodeT P = FindT(S, Ma_thuoc);
    if(P == NULL) return;

    if(S == P){
        S = S->nextT;
        delete P;
    } else {
        NodeT R = S;
        while(R->nextT != P) R = R->nextT;
        R->nextT = P->nextT;
        delete P;
    }
    S->demT--;
}

void FixT(DSThuoc S, int Ma_thuoc){
    if(emptyT(S)){
        cout << "Danh Sach Thuoc Rong" << endl;
        return;
    }
    NodeT p = FindT(S, Ma_thuoc);
    if(p == NULL) return;
    
    long x;
    cout << "Nhap gia thay doi: ";
    cin >> x;
    p->T.Gia_thuoc = x;
    cout << "Da thay doi gia thuoc" << endl;
}

void ArrangeT(DSThuoc &S, THUOC T1){
    NodeT P = makenodeT(T1);
    if(emptyT(S)){
        S = P;
    } else {
        if(P->T.Ten_thuoc[0] <= 'A'){
            P->nextT = S;
            S = P;
        } else {
            NodeT R = S;
            while(R->nextT != NULL && R->nextT->T.Ten_thuoc[0] < P->T.Ten_thuoc[0]) 
                R = R->nextT;
                P->nextT = R->nextT;
                R->nextT = P;
        }
    }
    S->demT++;
}
void NhapThuoc(DSBN& dsbn,DSThuoc S,DSDV dsdv,BNNODE A){    
    int x;
    cout << "Co mua thuoc hay khong ? \n";
    cout << "0. Khong\n1. Co lay thuoc\n" ; cin >> x;
    while(x !=1 &&x != 0){
    	cout << "Nhap lai: "; cin >> x;
	}
	if(x==1 ){
	    NhapT(S);
    	A->BN.T = S;
	}else{
			A->BN.T = NULL;
		}
    return; 
}
void NhapT(DSThuoc &S){
    cout << "------------nhap thuoc-------------\n";
    int x = 1;
    while(x == 1){
        THUOC T1;
        cout << "Ten thuoc: "; cin >> T1.Ten_thuoc;
        cout << "Ma thuoc: "; cin >> T1.Ma_thuoc;
        cout << "Don gia: ";  cin >> T1.Gia_thuoc;
        cout << "So luong: "; cin >> T1.so_luong;
        ArrangeT(S, T1);
        cout << "----------------------\n" << "0.thoat\n" << "1.nhap tiep\n";
        cin >> x;
        if(x != 0 && x != 1){
            cout << "Nhap lai: "; cin >> x;
        }
    }
}

void printfT(DSThuoc S) {
    if(S == NULL)return;
    S->TongtienT = sumT(S);

    string arr[50][6];
    NodeT R = S;
    // Gán tiêu đề cho mảng
    arr[0][0] = "STT";
    arr[0][1] = "Ma";
    arr[0][2] = "Ten";
    arr[0][3] = "Gia";
    arr[0][4] = "So luong";
    arr[0][5] = "Thanh tien";

    // Gán giá trị cho mảng
    for (int i = 1; i <= S->demT; i++) {
        arr[i][0] = to_string(i);
        arr[i][1] = to_string(R->T.Ma_thuoc);
        arr[i][2] = R->T.Ten_thuoc;
        arr[i][3] = to_string(R->T.Gia_thuoc);
        arr[i][4] = to_string(R->T.so_luong);
        arr[i][5] = to_string(tonggiaT(R->T));
        R = R->nextT;
    }
    cout << "\tDanh Sach Thuoc" << endl;
    for (int j = 0; j <= S->demT; j++) {
        for (int k = 0; k < 6; k++) {
            cout << arr[j][k] << "\t";
        }
        cout << endl;
    }
    cout << "Tong tien: " << S->TongtienT << endl;
}

long tonggiaT(THUOC T){
    return T.Gia_thuoc*T.so_luong;
}

long sumT(DSThuoc S) {
    long total = 0;
    NodeT p = S;
    while (p != NULL) {
        total += p->T.Gia_thuoc * p->T.so_luong;
        p = p->nextT;
    }
    return total;
}