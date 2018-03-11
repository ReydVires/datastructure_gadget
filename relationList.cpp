#include "relationList.h"
#include <iostream>
using namespace std;

void createList_r(List_r &L){
    first_r(L) = last_r(L) = nil;
}
address_r alokasi_r(address_p P,address_c C){
    address_r R = new elmList_r;
    parent(R) = P;
    child(R) = C;
    next_r(R) = nil;
    getComponent(P,C,R);
    return R;
}
void getComponent(address_p P, address_c C, address_r &R){
    if (info_c(C).substr(0,6) == "Camera" && info_p(P).camera == false){
        info_p(P).camera = true;
    }
    else if (info_c(C).substr(0,3) == "Ram" && info_p(P).ram == false){
        info_p(P).ram = true;
    }
    else if (info_c(C).substr(0,7) == "Battery" && info_p(P).battery == false){
        info_p(P).battery = true;
    }
    else if (info_c(C).substr(0,2) == "OS" && info_p(P).os == false){
        info_p(P).os = true;
    }
    else if (info_c(C).substr(0,3) == "CPU" && info_p(P).cpu == false){
        info_p(P).cpu = true;
    }
    else if (info_c(C).substr(0,5) == "Color" && info_p(P).color == false){
        info_p(P).color = true;
    }
    else
        R = nil;
}
void removeComponent(List_r &L, address_r R){
    if (info_c(child(R)).substr(0,6) == "Camera"){
        info_p(parent(R)).camera = false;
    }
    else if (info_c(child(R)).substr(0,3) == "Ram"){
        info_p(parent(R)).ram = false;
    }
    else if (info_c(child(R)).substr(0,7) == "Battery"){
        info_p(parent(R)).battery = false;
    }
    else if (info_c(child(R)).substr(0,2) == "OS"){
        info_p(parent(R)).os = false;
    }
    else if (info_c(child(R)).substr(0,3) == "CPU"){
        info_p(parent(R)).cpu = false;
    }
    else if (info_c(child(R)).substr(0,5) == "Color"){
        info_p(parent(R)).color = false;
    }
}
void editComponent(List_r &L, List_p Lp, List_c &Lc, string x){
    bool sameComponent = false;
    address_c C,B;
    address_r R,Q,Z,prec;
    address_p P;
    string strEdit;
    C = findElm_c(Lc,x);
    cout << "Edit Fitur\t: ";getline(cin,strEdit);
    if (strEdit.substr(0,6) != "Camera" && strEdit.substr(0,3) != "Ram" && strEdit.substr(0,7) != "Battery" && strEdit.substr(0,2) != "OS" && strEdit.substr(0,3) != "CPU" && strEdit.substr(0,5) != "Color"){
        cout << "Kode komponen salah!\n";
        return;
    }
    if (x.substr(0,6) == strEdit.substr(0,6) && strEdit.substr(0,6) == "Camera"){
        sameComponent = true;
    }
    else if (x.substr(0,3) == strEdit.substr(0,3) && strEdit.substr(0,3) == "Ram"){
        sameComponent = true;
    }
    else if (x.substr(0,7) == strEdit.substr(0,7) && strEdit.substr(0,7) == "Battery"){
        sameComponent = true;
    }
    else if (x.substr(0,2) == strEdit.substr(0,2) && strEdit.substr(0,2) == "OS"){
        sameComponent = true;
    }
    else if (x.substr(0,3) == strEdit.substr(0,3) && strEdit.substr(0,3) == "CPU"){
        sameComponent = true;
    }
    else if (x.substr(0,5) == strEdit.substr(0,5) && strEdit.substr(0,5) == "Color"){
        sameComponent = true;
    }
    R = first_r(L);
    if (sameComponent == true){
        B = alokasi_c(strEdit);
        insertLast_c(Lc,B);
        while (R != nil){
            if (info_c(C) == info_c(child(R))){
                removeComponent(L,R);
                P = parent(R);
                Z = alokasi_r(P,B);
                insertFirst_r(L,Z);
            }
            R = next_r(R);
        }
        cout << "Edit fitur berhasil diperbaharui\n";
        R = first_r(L);
        while (R != nil){
            if (x == info_c(child(R))){
                if (R == first_r(L)){
                    deleteFirst_r(L,Q);
                    R = first_r(L);
                }
                else if (R == last_r(L)){
                    deleteLast_r(L,Q);
                    R = last_r(L);
                }
                else {
                    prec = first_r(L);
                    while (next_r(prec) != R){
                        prec = next_r(prec);
                    }
                    deleteAfter_r(L,prec,Q);
                    R = prec;
                }
                dealokasi_r(Q);
            }
            else
                R = next_r(R);
        }
        deletebyValue_c(Lc,x);
    }
    else {
        Q = R;
        while (R != nil){
            if (info_c(C) == info_c(child(R))){
                if (strEdit.substr(0,6) == "Camera" && info_p(parent(R)).camera == true){
                    Q = nil;
                }
                else if (strEdit.substr(0,3) == "Ram" && info_p(parent(R)).ram == true){
                    Q = nil;
                }
                else if (strEdit.substr(0,7) == "Battery" && info_p(parent(R)).battery == true){
                    Q = nil;
                }
                else if (strEdit.substr(0,2) == "OS" && info_p(parent(R)).os == true){
                    Q = nil;
                }
                else if (strEdit.substr(0,3) == "CPU" && info_p(parent(R)).cpu == true){
                    Q = nil;
                }
                else if (strEdit.substr(0,5) == "Color" && info_p(parent(R)).color == true){
                    Q = nil;
                }
            }
            if (Q != nil)
                R = next_r(R);
            else
                R = nil;
        }
        if (Q == nil){
            cout << "Edit fitur gagal. Tidak semua fitur yang diedit dapat di perbaharui\n";
        }
        else {
            cout << "Edit fitur berhasil diperbaharui\n";
            B = alokasi_c(strEdit);
            insertLast_c(Lc,B);
            R = first_r(L);
            while (R != nil){
                if (info_c(C) == info_c(child(R))){
                    removeComponent(L,R);
                    P = parent(R);
                    Z = alokasi_r(P,B);
                    insertFirst_r(L,Z);
                }
                R = next_r(R);
            }
            deleteChild(L,Lc,x);
        }
    }
}
void dealokasi_r(address_r &R){
    delete R;
}
void insertFirst_r(List_r &L, address_r R){
    if (first_r(L) == nil)
        first_r(L) = last_r(L) = R;
    else {
        next_r(R) = first_r(L);
        first_r(L) = R;
    }
}
void insertLast_r(List_r &L, address_r R){
    if (first_r(L) == nil)
        insertFirst_r(L,R);
    else {
        next_r(last_r(L)) = R;
        last_r(L) = R;
    }
}
void displayInfo_Pr(List_r L, List_p Lp){
    address_r R;
    address_p P;
    int num = 1;
    bool stat = false;
    if (first_r(L) != nil){
        R = first_r(L);
        P = first_p(Lp);
        cout << "\t\tDISPLAY INFORMASI HANDPHONE\n";
        cout << " ===============================================\n";
        cout << "|NO.\t| HANDPHONE\t\t| IMEI\t\t|\n";
        cout << "|=======|=======================|===============|\n";
        while (P != nil){
            cout << "|" << num++ <<".\t|";
            if (info_p(P).name.size() + info_p(P).type.size() > 12)
                cout << " " << info_p(P).name << " " << info_p(P).type << "\t|";
            else
                cout << " " << info_p(P).name << " " << info_p(P).type << "\t\t|";
            if (info_p(P).imei.size() > 5)
                cout << " " << info_p(P).imei << "\t|";
            else
                cout << " " << info_p(P).imei << "\t\t|";
            cout << endl;
            //Fitur Area
            R = first_r(L);
            while (R != nil){
                if (info_p(P).imei == info_p(parent(R)).imei){
                    cout << "|\t|";
                    if (info_c(child(R)).size() >= 14)
                        cout << " " << info_c(child(R)) << "\t|\t\t|\n";
                    else
                        cout << " " << info_c(child(R)) << "\t\t|\t\t|\n";
                    stat = true;
                }
                R = next_r(R);
            }
            if (stat == false)
                cout << "|\t| -\t\t\t|\t\t|\n";
            else
                stat = false;
            P = next_p(P);
        }
        cout << " ===============================================\n";
    }
}
void deleteFirst_r(List_r &L, address_r &R){
    if (first_r(L) != nil){
        R = first_r(L);
        if (first_r(L) == last_r(L)){
            first_r(L) = last_r(L) = nil;
        }
        else {
            first_r(L) = next_r(R);
            next_r(R) = nil;
        }
    }
}
void deleteLast_r(List_r &L, address_r &R){
    address_r Q;
    if (first_r(L) != nil){
        R = last_r(L);
        if (first_r(L) == last_r(L))
            deleteFirst_r(L,R);
        else {
            Q = first_r(L);
            while (next_r(Q) != last_r(L)){
                Q = next_r(Q);
            }
            R = next_r(Q);
            last_r(L) = Q;
            next_r(last_r(L)) = nil;
        }
    }
}
void insertAfter_r(List_r &L, address_r prec, address_r R){
    if (first_r(L) == nil)
        insertFirst_r(L,R);
    else if (prec == last_r(L))
        insertLast_r(L,R);
    else {
        next_r(R) = next_r(prec);
        next_r(prec) = R;
    }
}
void deleteAfter_r(List_r &L, address_r prec, address_r &R){
    if (first_r(L) != nil){
        R = first_r(L);
        if (next_r(prec) == last_r(L))
            deleteLast_r(L,R);
        else if (prec == last_r(L))
            return;
        else {
            R = next_r(prec);
            next_r(prec) = next_r(R);
            next_r(R) = nil;
        }
    }
}
void displayInfo_Cr(List_r L, List_c Lc){
    address_r R;
    address_c C;
    int num = 1;
    bool stat = false;
    if (first_r(L) != nil){
        R = first_r(L);
        C = first_c(Lc);
        cout << "\tDISPLAY INFORMASI FITUR\n";
        cout << " ===============================\n";
        cout << "|NO.\t| FITUR\t\t\t|\n";
        cout << "|===============================|\n";
        while (C != nil){
            cout << "|"<< num++ << ".\t|";
            if (info_c(C).size() >= 14)
                cout << " " << info_c(C) << "\t|\n";
            else
                cout << " " << info_c(C) << "\t\t|\n";
            //Gadget Area
            R = first_r(L);
            while (R != nil){
                if (info_c(C) == info_c(child(R))){
                    cout << "|\t|";
                    if (info_p(parent(R)).name.size() + info_p(parent(R)).type.size() > 8)
                        cout << " " << info_p(parent(R)).name << " " << info_p(parent(R)).type << "\t|\n";
                    else
                        cout << " " << info_p(parent(R)).name << " " << info_p(parent(R)).type << "\t\t|\n";
                    stat = true;

                }
                R = next_r(R);
            }
            if (stat == false)
                cout << "|\t| -\t\t\t|\n";
            else
                stat = false;
            C = next_c(C);
        }
        cout << " ===============================\n";
    }
}
void displayRelation(List_r L){
    address_r R;
    int num = 1;
    if (first_r(L) != nil){
        R = first_r(L);
        cout << "\t\tDISPLAY RELATION\n";
        cout << " =======================================================\n";
        cout << "|NO.\t| HANDPHONE \t\t| FITUR\t\t\t|\n";
        cout << "|=======|=======================|=======================|\n";
        while (R != nil){
            cout << "|" << num++ <<".\t|";
            if (info_p(parent(R)).name.size() + info_p(parent(R)).type.size() > 8)
                cout << " " << info_p(parent(R)).name << " " << info_p(parent(R)).type << "\t|";
            else
                cout << " " << info_p(parent(R)).name << " " << info_p(parent(R)).type << "\t\t|";
            cout << " ";
            if (info_c(child(R)).size() > 14)
                cout << info_c(child(R)) << "\t|" << endl;
            else
                cout << info_c(child(R)) << "\t\t|" << endl;
            R = next_r(R);
        }
        cout << " =======================================================\n";
    }
}
void deleteParent(List_r &L, List_p &Lp, string x){
    address_r R,Q,prec;
    if (first_p(Lp) != nil){
       R = first_r(L);
        while (R != nil){
            if (x == info_p(parent(R)).imei){
                if (R == first_r(L)){
                    deleteFirst_r(L,Q);
                    R = first_r(L);
                }
                else if (R == last_r(L)){
                    deleteLast_r(L,Q);
                    R = last_r(L);
                }
                else {
                    prec = first_r(L);
                    while (next_r(prec) != R){
                        prec = next_r(prec);
                    }
                    deleteAfter_r(L,prec,Q);
                    R = prec;
                }
                dealokasi_r(Q);
            }
            else
                R = next_r(R);
        }
        deletebyValue_p(Lp,x);
    }
}
void deleteChild(List_r &L, List_c &Lc, string x){
    address_r R,Q,prec;
    if (first_c(Lc) != nil){
       R = first_r(L);
        while (R != nil){
            if (x == info_c(child(R))){
                if (R == first_r(L)){
                    deleteFirst_r(L,Q);
                    R = first_r(L);
                }
                else if (R == last_r(L)){
                    deleteLast_r(L,Q);
                    R = last_r(L);
                }
                else {
                    prec = first_r(L);
                    while (next_r(prec) != R){
                        prec = next_r(prec);
                    }
                    deleteAfter_r(L,prec,Q);
                    R = prec;
                }
                removeComponent(L,Q);
                dealokasi_r(Q);
            }
            else
                R = next_r(R);
        }
        deletebyValue_c(Lc,x);
    }
}
int countRelation(List_r L){
    int i = 0;
    address_r R = first_r(L);
    while (R != nil){
        i++;
        R = next_r(R);
    }
    return i;
}
void searchParent(List_r L, List_p Lp, string x){
    address_p P;
    address_r R;
    bool stat = false;
    if (first_p(Lp) != nil){
        P = findElm_p(Lp,x);
        if (P != nil && info_p(P).imei == x){
            cout << "Data ditemukan!\n";
            cout << "Handphone\t: " << info_p(P).name << " " << info_p(P).type << endl;
            cout << "Fitur\t\t: ";
            if (first_r(L) != nil){
                R = first_r(L);
                while (R != nil){
                    if (info_p(parent(R)).imei == x){
                        cout << info_c(child(R)) << " | ";
                        stat = true;
                    }
                    R = next_r(R);
                }
                if (stat == false)
                    cout << "Tidak ada fitur";
            }
            cout << endl;
        }
        else
            cout << "Data tidak ditemukan!\n";
    }
    else
        cout << "Tidak ada data dalam list HP\n";
}
void searchChild(List_r L, List_c Lc, string x){
    address_c C;
    address_r R;
    bool stat = false;
    if (first_c(Lc) != nil){
        C = findElm_c(Lc,x);
        if (C != nil && info_c(C) == x){
            cout << "Data " << info_c(C) << " ditemukan!\n";
            cout << "Handphone\t: ";
            if (first_r(L) != nil){
                R = first_r(L);
                while (R != nil){
                    if (info_c(child(R)) == x){
                        cout << info_p(parent(R)).name << " " << info_p(parent(R)).type << " | ";
                        stat = true;
                    }
                    R = next_r(R);
                }
                if (stat == false)
                    cout << "Tidak ada handphone";
            }
            cout << endl;
        }
        else
            cout << "Data " << x << " tidak ditemukan!\n";
    }
    else
        cout << "Tidak ada data dalam list fitur\n";
}
address_r findElm_r(List_r &L, string x, string y){
    address_r R;
    if (first_r(L)!= nil){
        R = first_r(L);
        while (R != nil && (info_p(parent(R)).imei != x || info_c(child(R)) != y)){
            R = next_r(R);
        }
        if (info_p(parent(R)).imei != x && info_c(child(R)) != y){
            R = nil;
        }
    }
    return R;
}
void deleteRelation(List_r &Lr, string x, string y){
    address_r R,Q,prec;
    if (first_r(Lr) != nil){
        R = findElm_r(Lr,x,y);
        if (info_p(parent(R)).imei == x && info_c(child(R)) == y){
                if (R == first_r(Lr))
                    deleteFirst_r(Lr,Q);
                else if (R == last_r(Lr))
                    deleteLast_r(Lr,Q);
                else {
                    prec = first_r(Lr);
                    while (next_r(prec) != R){
                        prec = next_r(prec);
                    }
                    deleteAfter_r(Lr,prec,Q);
                }
                removeComponent(Lr,Q);
                dealokasi_r(Q);
        }
    }
    else
        cout << "Tidak ada list relasi\n";
}
