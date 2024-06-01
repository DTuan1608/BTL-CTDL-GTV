#include <iostream>
#include <string>

#include <string>
#include "BENHNHAN.h"
#include "BACSI.h"
#include "DICHVU.h"
#include "THUOC.h"
#include "BOSUNG.h"

using namespace std;

void InitDV(DSDV& dsdv){
    dsdv = NULL;
    dsdv->demDV = 0;
}
// Nhap thong tin dich vu
void NhapDichVu(DSDV& dsdv) {
    int x = 1;
    while(x==1){
        cin.ignore();
	    Dich_vu newService;
        cout << "Nhap ten dich vu: ";
        getline(cin,newService.Ten_DV);
        cout << "Nhap gia dich vu: ";
        cin >> newService.Gia_DV;
        InsertDV(dsdv, newService);
        cout << "0.khong , 1.nhap tiep: " ; cin >> x;
        while(x != 1 && x !=0){
    	    cout << "Nhap lai: " ; cin >> x;
	    }
    }
}
//Sap xep dich vu theo gia tang dan
void ArrangeDV(DSDV& dsdv) {
    DVNODE currentNode = dsdv;
    while (currentNode != NULL) {
        DVNODE nextNode = currentNode->nextDV;
        while (nextNode !=NULL) {
            if (currentNode->DV.Gia_DV > nextNode->DV.Gia_DV) {
                swap(currentNode->DV, nextNode->DV);
            }
            nextNode = nextNode->nextDV;
        }
        currentNode = currentNode->nextDV;
    }
}
// Them dich vu moi
void InsertDV(DSDV &dsdv, Dich_vu newService){
    int check;
    do{
        Dich_vu DV;
        NhapDichVu(dsdv);
        DVNODE newNode = new NODEDV;
        if(dsdv == NULL){
            newNode = NULL;
            dsdv = newNode;
        }
        else{
            newNode->DV = DV;
            newNode->nextDV = dsdv;
            dsdv = newNode;
        }
        ArrangeDV(dsdv);
        dsdv->demDV++;
        cout<<"Co nhap tiep khong:(1.Co , 0. Khong)"<<endl;
        cin>> check;
    }while(check);
    
}

// Xoa dich vu
void DeleteDV(DSDV& dsdv, string serviceName) {
    DVNODE prevNode = NULL;
    DVNODE currentNode = dsdv;
    while (currentNode != NULL) {
        if (currentNode->DV.Ten_DV == serviceName) {
            if (prevNode == NULL) {
                dsdv = currentNode->nextDV;
            } else {
                prevNode->nextDV = currentNode->nextDV;
            }
            delete currentNode;
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->nextDV;
    }
    dsdv->demDV--;
}

//Tim kiem dich vu
Dich_vu FindDV(DSDV dsdv, string serviceName) {
    DVNODE currentNode = dsdv;
    while (currentNode != NULL) {
        if (currentNode->DV.Ten_DV == serviceName) {
            return currentNode->DV;
        }
        currentNode = currentNode->nextDV;
    }
    DVNODE Q = NULL;
    return Q->DV;
}

//Sua thong tin dich vu
void FixDV(DSDV& dsdv, string serviceName, long newPrice) {
    DVNODE currentNode = dsdv;
    while (currentNode != NULL) {
        if (currentNode->DV.Ten_DV == serviceName) {
            currentNode->DV.Gia_DV = newPrice;
            return;
        }
        currentNode = currentNode->nextDV;
    }
    cout << "khong tim thay dich vu." << endl;
}

void printfDV(DSDV S) {
    S->TongtienDV = SumDV(S);
    int n = S->demDV+1;
    DSDV R = S;
    string arr[50][3];

    // Assigning headers to the array
    arr[0][0] = "STT";
    arr[0][1] = "Ten";
    arr[0][2] = "Thanh tien";

    // Assigning values to the array
    for (int i = 1; i < n; i++) {
        arr[i][0] = to_string(i);
        arr[i][1] = R->DV.Ten_DV;
        arr[i][2] = to_string(R->DV.Gia_DV);
        R = R->nextDV;
    }

    // Printing the array
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < 3; k++) {
            cout << arr[j][k] << "\t";
        }
        cout << endl;
    }
    cout << "Tong tien: " << S->TongtienDV << endl;
}
long SumDV(DSDV S){
	int a;
	DSDV p = S;
	while(p != NULL){
		a += p->DV.Gia_DV;
		p = p->nextDV;
	}
	return a;
}