#include "parentList.h"
#include <iostream>
using namespace std;

void createList_p(List_p &L){
    first_p(L) = last_p(L) = nil;
}
address_p alokasi_p(string name, string type, string imei){
    address_p P = new elmList_p;
    info_p(P).name = name;
    info_p(P).type = type;
    info_p(P).imei = imei;
    info_p(P).camera = info_p(P).ram = info_p(P).battery = info_p(P).os = info_p(P).cpu = info_p(P).color = false;
    next_p(P) = nil;
    return P;
}
address_p findElm_p(List_p L, string x){
    address_p P = first_p(L);
    while (P != nil && info_p(P).imei != x){
        P = next_p(P);
    }
    return P;
}
void dealokasi_p(address_p &P){
    delete P;
}
void insertFirst_p(List_p &L, address_p P){
    if (first_p(L) == nil)
        first_p(L) = last_p(L) = P;
    else {
        next_p(P) = first_p(L);
        first_p(L) = P;
    }
}
void insertLast_p(List_p &L, address_p P){
    if (first_p(L) == nil)
        insertFirst_p(L,P);
    else {
        next_p(last_p(L)) = P;
        last_p(L) = P;
    }
}
void displayInfo_p(List_p L){
    address_p P;
    int num = 1;
    if (first_p(L) != nil){
        P = first_p(L);
        cout << "\t\tDISPLAY DATA HANDPHONE\n";
        cout << " ===============================================================\n";
        cout << "|NO.\t| NAMA BRAND\t| TYPE HANDPHONE\t| IMEI\t\t|\n";
        cout << "|=======|===============|=======================|===============|\n";
        while (P != nil){
            cout << "|" << num++ <<".\t|";
            if (info_p(P).name.size() > 5)
                cout << " " << info_p(P).name << "\t|";
            else
                cout << " " << info_p(P).name << "\t\t|";
            if (info_p(P).type.size() > 5)
                cout << " " << info_p(P).type << "\t\t|";
            else
                cout << " " << info_p(P).type << "\t\t\t|";
            if (info_p(P).imei.size() > 5)
                cout << " " << info_p(P).imei << "\t|" << endl;
            else
                cout << " " << info_p(P).imei << "\t\t|" << endl;
            P = next_p(P);
        }
        cout << " ===============================================================\n";
    }
}
void deleteFirst_p(List_p &L, address_p &P){
    if (first_p(L) != nil){
        P = first_p(L);
        if (first_p(L) == last_p(L)){
            first_p(L) = last_p(L) = nil;
        }
        else {
            first_p(L) = next_p(first_p(L));
            next_p(P) = nil;
        }
    }
}
void deleteLast_p(List_p &L, address_p &P){
    address_p Q;
    if (first_p(L) != nil){
        P = last_p(L);
        if (first_p(L) == last_p(L))
            deleteFirst_p(L,P);
        else {
            Q = first_p(L);
            while (next_p(Q) != last_p(L)){
                Q = next_p(Q);
            }
            P = next_p(Q);
            last_p(L) = Q;
            next_p(last_p(L)) = nil;
        }
    }
}
void insertAfter_p(List_p &L, address_p prec, address_p P){
    if (first_p(L) == nil)
        insertFirst_p(L,P);
    else if (prec == last_p(L))
        insertLast_p(L,P);
    else {
        next_p(P) = next_p(prec);
        next_p(prec) = P;
    }
}
void deleteAfter_p(List_p &L, address_p prec, address_p &P){
    if (first_p(L) != nil){
        P = first_p(L);
        if (next_p(prec) == last_p(L))
            deleteLast_p(L,P);
        else if (prec == last_p(L))
            return;
        else {
            P = next_p(prec);
            next_p(prec) = next_p(P);
            next_p(P) = nil;
        }
    }
}
void deletebyValue_p(List_p &L, string x){
    address_p prec,P;
    if (first_p(L) !=  nil){
        P = findElm_p(L,x);
        if (P == first_p(L))
            deleteFirst_p(L,P);
        else if (P == last_p(L))
            deleteLast_p(L,P);
        else {
            prec = first_p(L);
            while (next_p(prec) != P){
                prec = next_p(prec);
            }
            deleteAfter_p(L,prec,P);
        }
        dealokasi_p(P);
    }
}
int countData_p(List_p L){
    int count = 0;
    address_p P;
    if (first_p(L) != nil){
        P = first_p(L);
        while (P != nil){
            count++;
            P = next_p(P);
        }
    }
    return count;
}
void editInfo_p(List_p &L, char E, string x){
    bool edited = false;
    string temp;
    address_p P = first_p(L);
    if (P == nil)
        cout << "Tidak ada list Hp\n";
    else {
        while (P != nil){
            if (E == '1'){
                if (info_p(P).name == x){
                    if (edited == false){
                        cout << "Diubah\t: ";
                        cin.ignore();getline(cin,temp);
                        info_p(P).name = temp;
                        cout << "Edit nama handphone berhasil\n";
                        edited = true;
                    }
                    else
                        info_p(P).name = temp;
                }
            }
            else if (E == '2'){
                if (info_p(P).type == x){
                    cout << "Diubah\t: ";
                    getline(cin,info_p(P).type);
                    cout << "Edit tipe handphone berhasil\n";
                    P = last_p(L);
                }
            }
            else if (E == '3'){
                if (info_p(P).imei == x){
                    cout << "Diubah\t: ";cin >> temp;
                    if (temp == info_p(P).imei)
                        cout << "Data imei yang diinputkan masih sama\n";
                    else {
                        if (imeiCheck(L,temp) == false && temp != info_p(P).imei){
                            info_p(P).imei = temp;
                            cout << "Edit imei handphone berhasil\n";
                        }
                        else
                            cout << "Edit imei handphone gagal. Imei ada yang sama!\n";
                    }
                    P = last_p(L);
                }
            }
            P = next_p(P);
        }
    }
}
void sortingParent_A(List_p &L){
    address_p P,Q,R,S,T,Z;
    Q = next_p(first_p(L));
    if (first_p(L) != nil && next_p(first_p(L)) != nil){
        //====
        while (Q != nil){
            P = first_p(L);
            while (P != Q){
                if (info_p(P).name[0] > info_p(Q).name[0]){
                    if (P == first_p(L) && Q == last_p(L)){
                        if (next_p(P) == Q){
                            next_p(Q) = first_p(L);
                            next_p(P) = nil;
                        }
                        else {
                            R = first_p(L);
                            while (next_p(R) != Q){
                                R = next_p(R);
                            }
                            next_p(Q) = next_p(P);
                            next_p(R) = P;
                            next_p(P) = nil;
                        }
                        first_p(L) = Q;
                        last_p(L) = P;
                    }
                    else if (P == first_p(L) && Q != last_p(L)){
                        if (next_p(P) == Q){
                            next_p(P) = next_p(Q);
                            next_p(Q) = P;
                        }
                        else {
                            R = first_p(L);
                            while (next_p(R) != Q){
                                R = next_p(R);
                            }
                            first_p(L) = next_p(P);
                            next_p(P) = next_p(Q);
                            next_p(R) = P;
                            next_p(Q) = first_p(L);
                        }
                        first_p(L) = Q;
                    }
                    else if (P != first_p(L) && Q == last_p(L)){
                        R = first_p(L);
                        while (next_p(R) != P){
                            R = next_p(R);
                        }
                        S = first_p(L);
                            while (next_p(S) != Q){
                                S = next_p(S);
                        }
                        if (next_p(P) == Q){
                            next_p(Q) = P;
                            next_p(R) = Q;
                        }
                        else {
                            next_p(Q) = next_p(P);
                            next_p(S) = P;
                            next_p(R) = Q;
                        }
                        next_p(P) = nil;
                        last_p(L) = P;
                    }
                    else {
                        R = first_p(L);
                        while (next_p(R) != P){
                            R = next_p(R);
                        }
                        Z = first_p(L);
                        while (Z != next_p(Q)){
                            Z = next_p(Z);
                        }
                        S = first_p(L);
                            while (next_p(S) != Q){
                                S = next_p(S);
                        }
                        if (next_p(P) == Q){
                            next_p(Q) = P;
                            next_p(P) = Z;
                            next_p(R) = Q;
                        }
                        else {
                            next_p(Q) = next_p(P);
                            next_p(R) = Q;
                            next_p(S) = P;
                            next_p(P) = Z;
                        }
                    }
                    T = Q;
                    Q = P;
                    P = T;
                }
                P = next_p(P);
            }
            Q = next_p(Q);
        }
        //====
    }
    else
        cout << "Tidak bisa di sorting\n";
}
void sortingParent_D(List_p &L){
    address_p P,Q,R,S,T,Z;
    Q = next_p(first_p(L));
    if (first_p(L) != nil && next_p(first_p(L)) != nil){
        //====
        while (Q != nil){
            P = first_p(L);
            while (P != Q){
                if (info_p(P).name[0] < info_p(Q).name[0]){
                    if (P == first_p(L) && Q == last_p(L)){
                        if (next_p(P) == Q){
                            next_p(Q) = first_p(L);
                            next_p(P) = nil;
                        }
                        else {
                            R = first_p(L);
                            while (next_p(R) != Q){
                                R = next_p(R);
                            }
                            next_p(Q) = next_p(P);
                            next_p(R) = P;
                            next_p(P) = nil;
                        }
                        first_p(L) = Q;
                        last_p(L) = P;
                    }
                    else if (P == first_p(L) && Q != last_p(L)){
                        if (next_p(P) == Q){
                            next_p(P) = next_p(Q);
                            next_p(Q) = P;
                        }
                        else {
                            R = first_p(L);
                            while (next_p(R) != Q){
                                R = next_p(R);
                            }
                            first_p(L) = next_p(P);
                            next_p(P) = next_p(Q);
                            next_p(R) = P;
                            next_p(Q) = first_p(L);
                        }
                        first_p(L) = Q;
                    }
                    else if (P != first_p(L) && Q == last_p(L)){
                        R = first_p(L);
                        while (next_p(R) != P){
                            R = next_p(R);
                        }
                        S = first_p(L);
                            while (next_p(S) != Q){
                                S = next_p(S);
                        }
                        if (next_p(P) == Q){
                            next_p(Q) = P;
                            next_p(R) = Q;
                        }
                        else {
                            next_p(Q) = next_p(P);
                            next_p(S) = P;
                            next_p(R) = Q;
                        }
                        next_p(P) = nil;
                        last_p(L) = P;
                    }
                    else {
                        R = first_p(L);
                        while (next_p(R) != P){
                            R = next_p(R);
                        }
                        Z = first_p(L);
                        while (Z != next_p(Q)){
                            Z = next_p(Z);
                        }
                        S = first_p(L);
                            while (next_p(S) != Q){
                                S = next_p(S);
                        }
                        if (next_p(P) == Q){
                            next_p(Q) = P;
                            next_p(P) = Z;
                            next_p(R) = Q;
                        }
                        else {
                            next_p(Q) = next_p(P);
                            next_p(R) = Q;
                            next_p(S) = P;
                            next_p(P) = Z;
                        }
                    }
                    T = Q;
                    Q = P;
                    P = T;
                }
                P = next_p(P);
            }
            Q = next_p(Q);
        }
        //====
    }
    else
        cout << "Tidak bisa di sorting\n";
}
bool imeiCheck(List_p Lp, string x){
    address_p P;
    bool stat;
    P = findElm_p(Lp,x);
    if (P == nil)
        stat = false;
    else
        stat = true;
    return stat;
}
