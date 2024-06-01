#include <iostream>
#include <string>

#include "BENHNHAN.h"
#include "BACSI.h"
#include "DICHVU.h"
#include "THUOC.h"
#include "BOSUNG.h"

using namespace std;

//sua xoa
void SuaxoaBN(DSBN &S){
    int check ;
    do{
	    string a;
	    cout << "Nhap cccd cua BN muon duoc sua: " ; cin >> a;
	    BNNODE p = NULL;
	    while(p == NULL){
		    cout << "Nhap lai cccd: " ; cin >> a;
		    p = FindBN(S,a);
	    }
	
	    int x;
	    cout << "0.Xoa\n1.Thong tin\n2.Dich vu\n3.Thuoc\n";
	    cin >> x; 
	    while(x < 0 || x > 3){
		    cout << "Nhap lai: "; cin >> x;
	    }
	    switch(x){
		    case 0: {
			    DeleteBN(S,a);
			    break;
		    }
		    case 1:{
			    fixBN(S,a);
			    break;
		    }
		    case 2:{
			    break;
		    }
		    case 3:{
			    int x;
			    while(x == 1){
			    int i;
			    cout << "Nhap ma thuoc: "; cin >> i;
			    NodeT r = NULL;
			    while(r == NULL){
				    cout << "Nhap lai ma: " ; cin >> i;
				    r = FindT(p->BN.T,i);
			    }
			    int y;
			    cout << "0.Xoa\n1.Sua\n"; cin >> y;
			    while(y != 0 && y != 1){
				    cout << "Nhap lai: "; cin >>y;
		    	}
			    switch(y){
			    	case 0:{
				    	DeleteT(p->BN.T,i);
				    	break;
			    	}
				    case 1:{
					    FixT(p->BN.T,i);
				    	break;
				    }
			    }
			    cout << "0.khong\n1.\nSua tiep\n"; cin >> x;
			    while(x != 0 && x != 1){
				    cout << "Nhap lai: "; cin >> x;
			    }
			    }
			    break;
		    }
        }
        cout << "\n\tThong tin benh nhan sau khi sua:" << endl;
        printfBN(S);
        cout << "Co tiep tuc sua nua khong:(1. Co , 2. Khong)"<<endl;
        cin >> check;
	} while (check);	
}
void Hienthi(){
    cout<<"\n\tChon cac chuc nang"<<endl;
    cout<<"1. Benh nhan"<<endl;
    cout<<"2. DSDV"<<endl;
    cout<<"3. DSBS"<<endl;
    cout<<"4. DS Thuoc"<<endl;
    return; 
}
void Hienthi1(){
    cout<<"\n\tChon cac thao tac"<<endl;
    cout<<"1. Nhap thong tin benh nhan"<<endl;
    cout<<"2. Sua thong tin benh nhan"<<endl;
    cout<<"3. Nhap thuoc cho benh nhan"<<endl;
    cout<<"4. In ra thong tin BN"<<endl;
    
}
void Hienthi2(){
    cout<<"\n\tChon cac thao tac"<<endl;
    cout<<"1. Xem DS dich vu"<<endl;
    cout<<"2. Nhap them dich vu "<<endl;
    return;
}
void Dapung(DSBN& dsbn,DSThuoc S,DSDV dsdv,DSBS dsbs){
    int x;
    do{
        Hienthi();
        cin>>x;
        switch(x){
            case 1:{
                int y;
                Hienthi1();
                cin>> y ; 
                switch(y){
                    case 1: InsertBN(dsbn);break;
                    case 2: SuaxoaBN(dsbn);break;
                    case 3:{
                        string cccd;
                        cout<<"Nhap ma cccd Benh nhan: ";
                        cin>>cccd;
                        NhapThuoc(dsbn,S,dsdv,FindBN(dsbn,cccd));
                        break;
                    }
                    case 4: printfBN(dsbn);break;
                }
                break;
            }
            case 2:{
                int y;
                Hienthi2();
                cin>> y;
                switch(y){
                    case 1:printfDV(dsdv);break;
                    case 2:NhapDichVu(dsdv);break;
                }
                break;
            }
            case 3:{
                ThaotaCBS(dsbs);
            }
            case 4:printfT(S);break;
        }
    } while(1);
}

void Hienthi3(){
    cout<<"\n\tChon cac thao tac"<<endl;
    cout<<"1. Xem DS bac si"<<endl;
    cout<<"2. Nhap them bac si(Private)"<<endl;
    return;
}

void ThaotaCBS(DSBS dsbs){
    Hienthi3();
    int Choice;
    cin >> Choice;
    switch(Choice){
        case 1: PrintBS(dsbs); break;
        case 2: InsertBS(dsbs); break;
        default: cout << "Nhap lai."; break;
    }
}