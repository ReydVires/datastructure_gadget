#include "childList.h"
#include <iostream>
using namespace std;

void createList_c(List_c &L){
    first_c(L) = last_c(L) = nil;
}
address_c alokasi_c(infotype_c x){
    address_c P = new elmList_c;
    info_c(P) = x;
    next_c(P) = nil;
    return P;
}
address_c findElm_c(List_c L, infotype_c x){
    address_c P = first_c(L);
    while (P != nil && info_c(P) != x){
        P = next_c(P);
    }
    return P;
}
void dealokasi_c(address_c &P){
    delete P;
}
void insertFirst_c(List_c &L, address_c P){
    if (first_c(L) == nil)
        first_c(L) = last_c(L) = P;
    else {
        next_c(P) = first_c(L);
        first_c(L) = P;
    }
}
void insertLast_c(List_c &L, address_c P){
    if (first_c(L) == nil)
        insertFirst_c(L,P);
    else {
        next_c(last_c(L)) = P;
        last_c(L) = P;
    }
}
void displayInfo_c(List_c L){
    int num = 1;
    if (first_c(L) != nil){
        address_c P = first_c(L);
        cout << "\tDISPLAY DATA FITUR\n";
        cout << " ===============================\n";
        cout << "|NO.\t| FITUR\t\t\t|\n";
        cout << "|===============================|\n";
        while (P != nil){
            cout << "|"<< num++ << ".\t|";
            if (info_c(P).size() >= 14)
                cout << " " << info_c(P) << "\t|\n";
            else
                cout << " " << info_c(P) << "\t\t|\n";
            P = next_c(P);
        }
        cout << " ===============================\n";
    }
}
void deleteFirst_c(List_c &L, address_c &P){
    if (first_c(L) != nil){
        P = first_c(L);
        if (first_c(L) == last_c(L)){
            first_c(L) = last_c(L) = nil;
        }
        else {
            first_c(L) = next_c(first_c(L));
            next_c(P) = nil;
        }
    }
}
void deleteLast_c(List_c &L, address_c &P){
    address_c Q;
    if (first_c(L) != nil){
        P = last_c(L);
        if (first_c(L) == last_c(L))
            deleteFirst_c(L,P);
        else {
            Q = first_c(L);
            while (next_c(Q) != last_c(L)){
                Q = next_c(Q);
            }
            P = next_c(Q);
            last_c(L) = Q;
            next_c(last_c(L)) = nil;
        }
    }
}
void insertAfter_c(List_c &L, address_c prec, address_c P){
    if (first_c(L) == nil)
        insertFirst_c(L,P);
    else if (prec == last_c(L))
        insertLast_c(L,P);
    else {
        next_c(P) = next_c(prec);
        next_c(prec) = P;
    }
}
void deleteAfter_c(List_c &L, address_c prec, address_c &P){
    if (first_c(L) != nil){
        P = first_c(L);
        if (next_c(prec) == last_c(L))
            deleteLast_c(L,P);
        else if (prec == last_c(L))
            return;
        else {
            P = next_c(prec);
            next_c(prec) = next_c(P);
            next_c(P) = nil;
        }
    }
}
int countData_c(List_c L){
    int count = 0;
    address_c P;
    if (first_c(L) != nil){
        P = first_c(L);
        while (P != nil){
            count++;
            P = next_c(P);
        }
    }
    return count;
}
void deletebyValue_c(List_c &L, infotype_c x){
    address_c P,prec;
    if (first_c(L) != nil){
        P = findElm_c(L,x);
        if (P == first_c(L))
            deleteFirst_c(L,P);
        else if (P == last_c(L))
            deleteLast_c(L,P);
        else {
            prec = first_c(L);
            while (next_c(prec) != P){
                prec = next_c(prec);
            }
            deleteAfter_c(L,prec,P);
        }
        dealokasi_c(P);
    }
}
void editInfo_c(List_c &L, string x){
    string temp;
    address_c C = first_c(L);
    if (first_c(L) == nil)
        cout << "Tidak ada list feature\n";
    else {
        while (C != nil){
            if (info_c(C) == x){
                cout << "Edit fitur\t: ";
                getline(cin,temp);
                if (temp.substr(0,6) == "Camera" || temp.substr(0,3) == "Ram" || temp.substr(0,7) == "Battery" || temp.substr(0,2) == "OS" || temp.substr(0,3) == "CPU" || temp.substr(0,5) == "Color"){
                    info_c(C) = temp;
                    cout << "Edit fitur berhasil diperbaharui\n";
                }
                else
                    cout << "Kode komponen salah!\n";
                C = last_c(L);
            }
            C = next_c(C);
        }
    }
}
void sortingChild_A(List_c &L){
    address_c P,Q,R,S,T,Z;
    Q = next_c(first_c(L));
    if (first_c(L) != nil && next_c(first_c(L)) != nil){
        //====
        while (Q != nil){
            P = first_c(L);
            while (P != Q){
                if (info_c(P)[0] > info_c(Q)[0]){
                    if (P == first_c(L) && Q == last_c(L)){
                        if (next_c(P) == Q){
                            next_c(Q) = first_c(L);
                            next_c(P) = nil;
                        }
                        else {
                            R = first_c(L);
                            while (next_c(R) != Q){
                                R = next_c(R);
                            }
                            next_c(Q) = next_c(P);
                            next_c(R) = P;
                            next_c(P) = nil;
                        }
                        first_c(L) = Q;
                        last_c(L) = P;
                    }
                    else if (P == first_c(L) && Q != last_c(L)){
                        if (next_c(P) == Q){
                            next_c(P) = next_c(Q);
                            next_c(Q) = P;
                        }
                        else {
                            R = first_c(L);
                            while (next_c(R) != Q){
                                R = next_c(R);
                            }
                            first_c(L) = next_c(P);
                            next_c(P) = next_c(Q);
                            next_c(R) = P;
                            next_c(Q) = first_c(L);
                        }
                        first_c(L) = Q;
                    }
                    else if (P != first_c(L) && Q == last_c(L)){
                        R = first_c(L);
                        while (next_c(R) != P){
                            R = next_c(R);
                        }
                        S = first_c(L);
                            while (next_c(S) != Q){
                                S = next_c(S);
                        }
                        if (next_c(P) == Q){
                            next_c(Q) = P;
                            next_c(R) = Q;
                        }
                        else {
                            next_c(Q) = next_c(P);
                            next_c(S) = P;
                            next_c(R) = Q;
                        }
                        next_c(P) = nil;
                        last_c(L) = P;
                    }
                    else {
                        R = first_c(L);
                        while (next_c(R) != P){
                            R = next_c(R);
                        }
                        Z = first_c(L);
                        while (Z != next_c(Q)){
                            Z = next_c(Z);
                        }
                        S = first_c(L);
                            while (next_c(S) != Q){
                                S = next_c(S);
                        }
                        if (next_c(P) == Q){
                            next_c(Q) = P;
                            next_c(P) = Z;
                            next_c(R) = Q;
                        }
                        else {
                            next_c(Q) = next_c(P);
                            next_c(R) = Q;
                            next_c(S) = P;
                            next_c(P) = Z;
                        }
                    }
                    T = Q;
                    Q = P;
                    P = T;
                }
                P = next_c(P);
            }
            Q = next_c(Q);
        }
        //====
    }
    else
        cout << "Tidak bisa di sorting\n";
}
void sortingChild_D(List_c &L){
    address_c P,Q,R,S,T,Z;
    Q = next_c(first_c(L));
    if (first_c(L) != nil && next_c(first_c(L)) != nil){
        //====
        while (Q != nil){
            P = first_c(L);
            while (P != Q){
                if (info_c(P)[0] < info_c(Q)[0]){
                    if (P == first_c(L) && Q == last_c(L)){
                        if (next_c(P) == Q){
                            next_c(Q) = first_c(L);
                            next_c(P) = nil;
                        }
                        else {
                            R = first_c(L);
                            while (next_c(R) != Q){
                                R = next_c(R);
                            }
                            next_c(Q) = next_c(P);
                            next_c(R) = P;
                            next_c(P) = nil;
                        }
                        first_c(L) = Q;
                        last_c(L) = P;
                    }
                    else if (P == first_c(L) && Q != last_c(L)){
                        if (next_c(P) == Q){
                            next_c(P) = next_c(Q);
                            next_c(Q) = P;
                        }
                        else {
                            R = first_c(L);
                            while (next_c(R) != Q){
                                R = next_c(R);
                            }
                            first_c(L) = next_c(P);
                            next_c(P) = next_c(Q);
                            next_c(R) = P;
                            next_c(Q) = first_c(L);
                        }
                        first_c(L) = Q;
                    }
                    else if (P != first_c(L) && Q == last_c(L)){
                        R = first_c(L);
                        while (next_c(R) != P){
                            R = next_c(R);
                        }
                        S = first_c(L);
                        while (next_c(S) != Q){
                            S = next_c(S);
                        }
                        if (next_c(P) == Q){
                            next_c(Q) = P;
                            next_c(R) = Q;
                        }
                        else {
                            next_c(Q) = next_c(P);
                            next_c(S) = P;
                            next_c(R) = Q;
                        }
                        next_c(P) = nil;
                        last_c(L) = P;
                    }
                    else {
                        R = first_c(L);
                        while (next_c(R) != P){
                            R = next_c(R);
                        }
                        Z = first_c(L);
                        while (Z != next_c(Q)){
                            Z = next_c(Z);
                        }
                        S = first_c(L);
                        while (next_c(S) != Q){
                            S = next_c(S);
                        }
                        if (next_c(P) == Q){
                            next_c(Q) = P;
                            next_c(P) = Z;
                            next_c(R) = Q;
                        }
                        else {
                            next_c(Q) = next_c(P);
                            next_c(R) = Q;
                            next_c(S) = P;
                            next_c(P) = Z;
                        }
                    }
                    T = Q;
                    Q = P;
                    P = T;
                }
                P = next_c(P);
            }
            Q = next_c(Q);
        }
        //====
    }
    else
        cout << "Tidak bisa di sorting\n";
}
