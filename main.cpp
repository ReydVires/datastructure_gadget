#include <iostream>
#include <cstdlib>
#include "relationList.h"

using namespace std;

void menu(List_p &Lp, List_c &Lc, List_r &Lr){
    char pil_menu,pil_in,pil_rel,pil_del,pil_view,pil_src,pil_ed,pil_sort;
    string nama_hp, type_hp, imei_hp, fitur_hp;
    address_p P, prec_p;
    address_c C, prec_c;
    address_r R;
    do {
        cout << " =======================================\n";
        cout << "|NO.| MENU APLIKASI INFORMASI GADGET\t|\n";
        cout << "|===|===================================|\n";
        cout << "| 1.| Input Data\t\t\t|\n";
        cout << "| 2.| Pilih Fitur untuk Handphone\t|\n";
        cout << "| 3.| Hapus Data\t\t\t|\n";
        cout << "| 4.| Lihat Informasi\t\t\t|\n";
        cout << "| 5.| Cari Data\t\t\t\t|\n";
        cout << "| 6.| Edit\t\t\t\t|\n";
        cout << "| 7.| Sorting\t\t\t\t|\n";
        cout << "| 0.| Exit\t\t\t\t|\n";
        cout << " =======================================\n";
        cout << "| Pilih : ";cin >> pil_menu;
        if (pil_menu != '0') system("cls");
        switch (pil_menu){
            case '1': //menu input: DONE!
                do {
                    cout << " =======================================\n";
                    cout << "|NO.| MENU INPUT DATA\t\t\t|\n";
                    cout << "|===|===================================|\n";
                    cout << "|   | INPUT DATA HANDPHONE\t\t|\n";
                    cout << "| 1.| Insert First\t\t\t|\n";
                    cout << "| 2.| Insert Last\t\t\t|\n";
                    cout << "| 3.| Insert After\t\t\t|\n";
                    cout << "|   | INPUT DATA FITUR\t\t\t|\n";
                    cout << "| 4.| Insert First\t\t\t|\n";
                    cout << "| 5.| Insert Last\t\t\t|\n";
                    cout << "| 6.| Insert After\t\t\t|\n";
                    cout << "| 0.| Kembali\t\t\t\t|\n";
                    cout << " =======================================\n";
                    cout << "| Pilih : ";cin >> pil_in;
                    system("cls");
                    switch (pil_in){
                        case '1':
                            cout << " =======================================\n";
                            cout << "| MENU INPUT DATA HP\\INSERT FIRST\t|\n";
                            cout << " =======================================\n";
                            cout << "Nama Handphone\t: ";cin >> nama_hp;
                            cout << "Type Handphone\t: ";cin.ignore();getline(cin,type_hp);
                            cout << "Imei Handphone\t: ";cin >> imei_hp;
                            if (imeiCheck(Lp,imei_hp) == false){
                                P = alokasi_p(nama_hp,type_hp,imei_hp);
                                insertFirst_p(Lp,P);
                                cout << "Data berhasil ditambahkan\n";
                            }
                            else
                                cout << "Data gagal ditambahkan. Imei ada yang sama!\n";
                            system("pause");
                            break;
                        case '2':
                            cout << " =======================================\n";
                            cout << "| MENU INPUT DATA HP\\INSERT LAST\t|\n";
                            cout << " =======================================\n";
                            cout << "Nama Handphone\t: ";cin >> nama_hp;
                            cout << "Type Handphone\t: ";cin.ignore();getline(cin,type_hp);
                            cout << "Imei Handphone\t: ";cin >> imei_hp;
                            if (imeiCheck(Lp,imei_hp) == false){
                                P = alokasi_p(nama_hp,type_hp,imei_hp);
                                insertLast_p(Lp,P);
                                cout << "Data berhasil ditambahkan\n";
                            }
                            else
                                cout << "Data gagal ditambahkan. Imei ada yang sama!\n";
                            system("pause");
                            break;
                        case '3':
                            cout << " =======================================\n";
                            cout << "| MENU INPUT DATA HP\\INSERT AFTER\t|\n";
                            cout << " =======================================\n";
                            cout << "Input data setelah Handphone (IMEI) \t: ";cin >> imei_hp;
                            prec_p = findElm_p(Lp,imei_hp);
                            if (prec_p == nil)
                                cout << "Imei tidak ada!\n";
                            else {
                                cout << "Nama Handphone\t: ";cin >> nama_hp;
                                cout << "Type Handphone\t: ";cin.ignore();getline(cin,type_hp);
                                cout << "Imei Handphone\t: ";cin >> imei_hp;
                                if (imeiCheck(Lp,imei_hp) == false){
                                    P = alokasi_p(nama_hp,type_hp,imei_hp);
                                    insertAfter_p(Lp,prec_p,P);
                                    cout << "Data berhasil ditambahkan\n";
                                }
                                else
                                    cout << "Data gagal ditambahkan. Imei ada yang sama!\n";
                            }
                            system("pause");
                            break;
                        case '4':
                            cout << " =======================================\n";
                            cout << "| MENU INPUT DATA FITUR\\INSERT FIRST\t|\n";
                            cout << " =======================================\n";
                            cout << "Kode komponen HP : [Camera] [Ram] [Battery] [OS] [CPU] [Color]\n"
                            << "Tuliskan kode komponennya terlebih dahulu, tanpa [], lalu nilainya\n"
                            << "Contoh : OS iOS10, Ram 12GB, Color Black\n"
                            << "Input fitur : ";cin.ignore();getline(cin,fitur_hp);
                            if (fitur_hp.substr(0,6) == "Camera" || fitur_hp.substr(0,3) == "Ram" || fitur_hp.substr(0,7) == "Battery" || fitur_hp.substr(0,2) == "OS" || fitur_hp.substr(0,3) == "CPU" || fitur_hp.substr(0,5) == "Color"){
                                C = alokasi_c(fitur_hp);
                                insertFirst_c(Lc,C);
                                cout << "Data berhasil ditambahkan\n";
                            }
                            else
                                cout << "Data gagal ditambahkan. Kode komponen salah!\n";
                            system("pause");
                            break;
                        case '5':
                            cout << " =======================================\n";
                            cout << "| MENU INPUT DATA FITUR\\INSERT LAST\t|\n";
                            cout << " =======================================\n";
                            cout << "Kode komponen HP : [Camera] [Ram] [Battery] [OS] [CPU] [Color]\n"
                            << "Tuliskan kode komponennya terlebih dahulu, tanpa [], lalu nilainya\n"
                            << "Contoh : OS iOS10, Ram 12GB, Color Black\n"
                            << "Input fitur : ";cin.ignore();getline(cin,fitur_hp);
                            if (fitur_hp.substr(0,6) == "Camera" || fitur_hp.substr(0,3) == "Ram" || fitur_hp.substr(0,7) == "Battery" || fitur_hp.substr(0,2) == "OS" || fitur_hp.substr(0,3) == "CPU" || fitur_hp.substr(0,5) == "Color"){
                                C = alokasi_c(fitur_hp);
                                insertLast_c(Lc,C);
                                cout << "Data berhasil ditambahkan\n";
                            }
                            else
                                cout << "Data gagal ditambahkan. Kode komponen salah!\n";
                            system("pause");
                            break;
                        case '6':
                            cout << " =======================================\n";
                            cout << "| MENU INPUT DATA FITUR\\INSERT AFTER\t|\n";
                            cout << " =======================================\n";
                            cout << "Kode komponen HP : [Camera] [Ram] [Battery] [OS] [CPU] [Color]\n"
                            << "Tuliskan kode komponennya terlebih dahulu, tanpa [], lalu nilainya\n"
                            << "Contoh : OS iOS10, Ram 12GB, Color Black\n"
                            << "Input data setelah fitur : ";cin.ignore();getline(cin,fitur_hp);
                            prec_c = findElm_c(Lc,fitur_hp);
                            if (prec_c == nil)
                                cout << "Fitur tidak ada!\n";
                            else {
                                cout << "Input fitur : ";getline(cin,fitur_hp);
                                if (fitur_hp.substr(0,6) == "Camera" || fitur_hp.substr(0,3) == "Ram" || fitur_hp.substr(0,7) == "Battery" || fitur_hp.substr(0,2) == "OS" || fitur_hp.substr(0,3) == "CPU" || fitur_hp.substr(0,5) == "Color"){
                                    C = alokasi_c(fitur_hp);
                                    insertAfter_c(Lc,prec_c,C);
                                    cout << "Data berhasil ditambahkan\n";
                                }
                                else
                                    cout << "Data gagal ditambahkan. Kode komponen salah!\n";
                            }
                            system("pause");
                            break;
                        case '0':
                            break;
                    }
                    system("cls");
                } while(pil_in != '0');
                break;
            case '2': //menu relation: DONE!
                do {
                    cout << " =======================================\n";
                    cout << "|NO.| MENU PILIH FITUR\t\t\t|\n";
                    cout << "|===|===================================|\n";
                    cout << "| 1.| Insert First\t\t\t|\n";
                    cout << "| 2.| Insert Last\t\t\t|\n";
                    cout << "| 0.| Kembali\t\t\t\t|\n";
                    cout << " =======================================\n";
                    cout << "| Pilih : ";cin >> pil_rel;
                    system("cls");
                    switch(pil_rel){
                        case '1':
                            cout << " =======================================\n";
                            cout << "| MENU PILIH FITUR\\INSERT FIRST\t|\n";
                            cout << " =======================================\n";
                            cout << "Imei Handphone\t: ";cin >> imei_hp;
                            P = findElm_p(Lp,imei_hp);
                            if (P == nil)
                                cout << "Imei tidak ada!\n";
                            else {
                                cout << "Fitur dipilih\t: ";cin.ignore();getline(cin,fitur_hp);
                                C = findElm_c(Lc,fitur_hp);
                                if (C == nil)
                                    cout << "Fitur tidak ada!\n";
                                else {
                                    R = alokasi_r(P,C);
                                    if (R == nil)
                                        cout << "Data gagal ditambahkan. Komponen fitur dalam Handphone sudah ada!\n";
                                    else {
                                        insertFirst_r(Lr,R);
                                        cout << "Data berhasil ditambahkan\n";
                                    }
                                }
                            }
                            system("pause");
                            break;
                        case '2':
                            cout << " =======================================\n";
                            cout << "| MENU PILIH FITUR\\INSERT LAST\t|\n";
                            cout << " =======================================\n";
                            cout << "Imei Handphone\t: ";cin >> imei_hp;
                            P = findElm_p(Lp,imei_hp);
                            if (P == nil)
                                cout << "Imei tidak ada!\n";
                            else {
                                cout << "Fitur dipilih\t: ";cin.ignore();getline(cin,fitur_hp);
                                C = findElm_c(Lc,fitur_hp);
                                if (C == nil)
                                    cout << "Fitur tidak ada!\n";
                                else {
                                    R = alokasi_r(P,C);
                                    if (R == nil)
                                        cout << "Data gagal ditambahkan. Komponen fitur dalam Handphone sudah ada!\n";
                                    else {
                                        insertLast_r(Lr,R);
                                        cout << "Data berhasil ditambahkan\n";
                                    }
                                }
                            }
                            system("pause");
                            break;
                        case '0':
                            break;
                    }
                    system("cls");
                } while(pil_rel != '0');
                break;
            case '3': //menu delete: DONE!
                do {
                    cout << " =======================================\n";
                    cout << "|NO.| MENU HAPUS DATA\t\t\t|\n";
                    cout << "|===|===================================|\n";
                    cout << "| 1.| Hapus Handphone\t\t\t|\n";
                    cout << "| 2.| Hapus Fitur\t\t\t|\n";
                    cout << "| 3.| Hapus Fitur pada Handphone\t|\n";
                    cout << "| 0.| Kembali\t\t\t\t|\n";
                    cout << " =======================================\n";
                    cout << "| Pilih : ";cin >> pil_del;
                    system("cls");
                    switch(pil_del){
                        case '1':
                            cout << " =======================================\n";
                            cout << "| MENU HAPUS DATA\\HANDPHONE\t\t|\n";
                            cout << "|=======================================|\n";
                            if (first_p(Lp) != nil){
                                cout << "Imei Handphone\t: ";cin >> imei_hp;
                                P = findElm_p(Lp,imei_hp);
                                if (P == nil)
                                    cout << "Imei tidak ada\n";
                                else {
                                    deleteParent(Lr,Lp,imei_hp);
                                    cout << "Data handphone berhasil dihapus\n";
                                }
                            }
                            else
                                cout << "Tidak ada data di list handphone!\n";
                            system("pause");
                            break;
                        case '2':
                            cout << " =======================================\n";
                            cout << "| MENU HAPUS DATA\\FITUR\t\t\t|\n";
                            cout << "|=======================================|\n";
                            if (first_c(Lc) != nil){
                                cout << "Nama Fitur\t: ";cin.ignore();getline(cin,fitur_hp);
                                C = findElm_c(Lc,fitur_hp);
                                if (C == nil)
                                    cout << "Fitur tidak ada\n";
                                else {
                                    deleteChild(Lr,Lc,fitur_hp);
                                    cout << "Data fitur berhasil dihapus\n";
                                }
                            }
                            else
                                cout << "Tidak ada data di list fitur!\n";
                            system("pause");
                            break;
                        case '3':
                            cout << " =======================================\n";
                            cout << "| MENU HAPUS DATA\\RELASI\t\t|\n";
                            cout << "|=======================================|\n";
                            if (first_r(Lr) != nil){
                                cout << "Imei Handphone\t: ";cin >> imei_hp;
                                P = findElm_p(Lp,imei_hp);
                                if (P != nil){
                                    cout << "Nama Fitur\t: ";cin.ignore();getline(cin,fitur_hp);
                                    C = findElm_c(Lc,fitur_hp);
                                    if (C != nil){
                                        deleteRelation(Lr,imei_hp,fitur_hp);
                                        cout << "Data relasi berhasil dihapus\n";
                                    }
                                    else
                                        cout << "Fitur tidak ada\n";
                                }
                                else
                                    cout << "Imei tidak ada\n";
                            }
                            else
                                cout << "Tidak ada data di list relasi!\n";
                            system("pause");
                            break;
                        case '0':
                            break;
                    }
                    system("cls");
                } while(pil_del != '0');
                break;
            case '4': //menu display: DONE!
                do {
                    cout << " =======================================\n";
                    cout << "|NO.| MENU LIHAT INFORMASI\t\t|\n";
                    cout << "|===|===================================|\n";
                    cout << "| 1.| Handphone\t\t\t\t|\n";
                    cout << "| 2.| Fitur\t\t\t\t|\n";
                    cout << "| 3.| Handphone beserta fiturnya\t|\n";
                    cout << "| 4.| Fitur beserta handphone-nya\t|\n";
                    cout << "| 5.| List Relasi\t\t\t|\n";
                    cout << "| 0.| Kembali\t\t\t\t|\n";
                    cout << " =======================================\n";
                    cout << "| Pilih : ";cin >> pil_view;
                    system("cls");
                    switch(pil_view){
                        case '1':
                            if (first_p(Lp) != nil)
                                displayInfo_p(Lp);
                            else
                                cout << "List handphone kosong...\n";
                            system("pause");
                            break;
                        case '2':
                            if (first_c(Lc) != nil)
                                displayInfo_c(Lc);
                            else
                                cout << "List fitur kosong...\n";
                            system("pause");
                            break;
                        case '3':
                            if (first_r(Lr) != nil)
                                displayInfo_Pr(Lr,Lp);
                            else
                                cout << "List relasi atau list handphone kosong...\n";
                            system("pause");
                            break;
                        case '4':
                            if (first_c(Lc) != nil && first_r(Lr) != nil)
                                displayInfo_Cr(Lr,Lc);
                            else
                                cout << "List relasi atau list fitur kosong...\n";
                            system("pause");
                            break;
                        case '5':
                            if (first_p(Lp) != nil && first_r(Lr) != nil)
                                displayRelation(Lr);
                            else
                                cout << "List relasi kosong...\n";
                            system("pause");
                            break;
                        case '0':
                            break;
                    }
                    system("cls");
                } while(pil_view != '0');
                break;
            case '5': //menu search: DONE!
                do {
                    cout << " =======================================\n";
                    cout << "|NO.| MENU CARI DATA\t\t\t|\n";
                    cout << "|===|===================================|\n";
                    cout << "| 1.| Cari Handphone (IMEI)\t\t|\n";
                    cout << "| 2.| Cari Fitur\t\t\t|\n";
                    cout << "| 0.| Kembali\t\t\t\t|\n";
                    cout << " =======================================\n";
                    cout << "| Pilih : ";cin >> pil_src;
                    system("cls");
                    switch (pil_src){
                        case '1':
                            cout << " =======================================\n";
                            cout << "| MENU CARI DATA\\HANDPHONE\t\t|\n";
                            cout << " =======================================\n";
                            if (first_p(Lp) != nil){
                                cout << "Imei Handphone\t: ";cin >> imei_hp;
                                searchParent(Lr,Lp,imei_hp);
                            }
                            else
                                cout << "Tidak ada data di list handphone!\n";
                            system("pause");
                            break;
                        case '2':
                            cout << " =======================================\n";
                            cout << "| MENU CARI DATA\\FITUR\t\t\t|\n";
                            cout << " =======================================\n";
                            if (first_p(Lp) != nil){
                                cout << "Nama Fitur\t: ";cin.ignore();getline(cin,fitur_hp);
                                searchChild(Lr,Lc,fitur_hp);
                            }
                            else
                                cout << "Tidak ada data di list handphone!\n";
                            system("pause");
                            break;
                        case '0':
                            break;
                    }
                    system("cls");
                } while(pil_src != '0');
                break;
            case '6': //menu edit: DONE!
                do {
                    cout << " =======================================\n";
                    cout << "|NO.| MENU EDIT DATA\t\t\t|\n";
                    cout << "|===|===================================|\n";
                    cout << "| 1.| Nama Handphone\t\t\t|\n";
                    cout << "| 2.| Type Handphone\t\t\t|\n";
                    cout << "| 3.| Imei Handphone\t\t\t|\n";
                    cout << "| 4.| Edit Fitur \t\t\t|\n";
                    cout << "| 0.| Kembali\t\t\t\t|\n";
                    cout << " =======================================\n";
                    cout << "| Pilih : ";cin >> pil_ed;
                    system("cls");
                    switch (pil_ed){
                        case '1':
                            cout << " =======================================\n";
                            cout << "| MENU EDIT DATA\\NAMA HP\t\t|\n";
                            cout << " =======================================\n";
                            if (first_p(Lp) != nil){
                                cout << "Nama Brand HP yang diedit\t: ";cin >> nama_hp;
                                editInfo_p(Lp,pil_ed,nama_hp);
                            }
                            else
                                cout << "Tidak ada data di list handphone!\n";
                            system("pause");
                            break;
                        case '2':
                            cout << " =======================================\n";
                            cout << "| MENU EDIT DATA\\TIPE HP\t\t|\n";
                            cout << " =======================================\n";
                            if (first_p(Lp) != nil){
                                cout << "Type HP yang diedit\t: ";cin.ignore();getline(cin,type_hp);
                                editInfo_p(Lp,pil_ed,type_hp);
                            }
                            else
                                cout << "Tidak ada data di list handphone!\n";
                            system("pause");
                            break;
                        case '3':
                            cout << " =======================================\n";
                            cout << "| MENU EDIT DATA\\IMEI HP\t\t|\n";
                            cout << " =======================================\n";
                            if (first_p(Lp) != nil){
                                cout << "Imei HP\t: ";cin >> imei_hp;
                                editInfo_p(Lp,pil_ed,imei_hp);
                            }
                            else
                                cout << "Tidak ada data di list handphone!\n";
                            system("pause");
                            break;
                        case '4':
                            cout << " =======================================\n";
                            cout << "| MENU EDIT DATA\\FITUR\t\t|\n";
                            cout << " =======================================\n";
                            if (first_c(Lc) != nil){
                                cout << "Kode komponen HP : [Camera] [Ram] [Battery] [OS] [CPU] [Color]\n"
                                << "Tuliskan kode komponennya terlebih dahulu, tanpa [], lalu nilainya\n"
                                << "Contoh : OS iOS 10, Ram 12GB, Color Black\n";
                                cout << "Nama Fitur\t: ";cin.ignore();getline(cin,fitur_hp);
                                if (fitur_hp.substr(0,6) == "Camera" || fitur_hp.substr(0,3) == "Ram" || fitur_hp.substr(0,7) == "Battery" || fitur_hp.substr(0,2) == "OS" || fitur_hp.substr(0,3) == "CPU" || fitur_hp.substr(0,5) == "Color"){
                                    C = findElm_c(Lc,fitur_hp);
                                    if (C != nil){
                                        if (first_r(Lr) == nil)
                                            editInfo_c(Lc,fitur_hp);
                                        else
                                            editComponent(Lr,Lp,Lc,fitur_hp);
                                    }
                                    else
                                        cout << "Fitur tidak ada\n";
                                }
                                else
                                    cout << "Kode komponen salah!\n";
                            }
                            else
                                cout << "Tidak ada data di list fitur!\n";
                            system("pause");
                            break;
                        case '0':
                            break;
                    }
                    system("cls");
                } while(pil_ed != '0');
                break;
            case '7': //menu sort: DONE!
                do {
                    cout << " =======================================\n";
                    cout << "|NO.| MENU SORTING\t\t\t|\n";
                    cout << "|===|===================================|\n";
                    cout << "| 1.| Sort Ascending Handphone\t\t|\n";
                    cout << "| 2.| Sort Descending Handphone\t\t|\n";
                    cout << "| 3.| Sort Ascending Fitur\t\t|\n";
                    cout << "| 4.| Sort Descending Fitur\t\t|\n";
                    cout << "| 0.| Kembali\t\t\t\t|\n";
                    cout << " =======================================\n";
                    cout << "| Pilih : ";cin >> pil_sort;
                    switch (pil_sort) {
                        case '1':
                            if (countData_p(Lp) == 0)
                                cout << "Sorting gagal. Tidak ada data di list handphone!\n";
                            else if (countData_p(Lp) == 1)
                                cout << "Sorting gagal. Data di list handphone hanya 1!\n";
                            else {
                                sortingParent_A(Lp);
                                cout << "Sorting list handphone selesai\n";
                            }
                            system("pause");
                            system("cls");
                            break;
                        case '2':
                            if (countData_p(Lp) == 0)
                                cout << "Sorting gagal. Tidak ada data di list handphone!\n";
                            else if (countData_p(Lp) == 1)
                                cout << "Sorting gagal. Data di list handphone hanya 1!\n";
                            else {
                                sortingParent_D(Lp);
                                cout << "Sorting list handphone selesai\n";
                            }
                            system("pause");
                            system("cls");
                            break;
                        case '3':
                            if (countData_c(Lc) == 0)
                                cout << "Sorting gagal. Tidak ada data di list fitur!\n";
                            else if (countData_c(Lc) == 1)
                                cout << "Sorting gagal. Data di list fitur hanya 1!\n";
                            else {
                                sortingChild_A(Lc);
                                cout << "Sorting list fitur selesai\n";
                            }
                            system("pause");
                            system("cls");
                            break;
                        case '4':
                            if (countData_c(Lc) == 0)
                                cout << "Sorting gagal. Tidak ada data di list fitur!\n";
                            else if (countData_c(Lc) == 1)
                                cout << "Sorting gagal. Data di list fitur hanya 1!\n";
                            else {
                                sortingChild_D(Lc);
                                cout << "Sorting list fitur selesai\n";
                            }
                            system("pause");
                            system("cls");
                            break;
                        case '0':
                            break;
                    }
                    system("cls");
                } while(pil_sort != '0');
                break;
            case '0':
                cout << "Program ended.\n";
                break;
            default:
                cout << "Inputan salah\n";
                system("pause");
                system("cls");
                break;
        }
    } while(pil_menu != '0');
}

int main(){
    List_p Lp;
    List_c Lc;
    List_r Lr;
    createList_p(Lp);
    createList_c(Lc);
    createList_r(Lr);
    //=====
    //INISIAL INPUTAN
    //=====
    insertFirst_p(Lp,alokasi_p("Apple","iPhone 5s","92010"));
    insertLast_p(Lp,alokasi_p("Samsung","Galaxy J7","72014"));
    insertFirst_p(Lp,alokasi_p("Samsung","Galaxy S7","72015"));
    insertAfter_p(Lp,findElm_p(Lp,"92010"),alokasi_p("LG","V20","12014"));

    insertFirst_c(Lc,alokasi_c("Battery 3000mAh"));
    insertLast_c(Lc,alokasi_c("Color White"));
    insertLast_c(Lc,alokasi_c("Color Black"));
    insertFirst_c(Lc,alokasi_c("CPU 1,3GHz"));
    insertAfter_c(Lc,findElm_c(Lc,"Color White"),alokasi_c("Ram 4GB"));

    insertFirst_r(Lr,alokasi_r(findElm_p(Lp,"92010"),findElm_c(Lc,"CPU 1,3GHz")));
    insertLast_r(Lr,alokasi_r(findElm_p(Lp,"72015"),findElm_c(Lc,"Battery 3000mAh")));
    insertLast_r(Lr,alokasi_r(findElm_p(Lp,"72015"),findElm_c(Lc,"Color Black")));
    insertFirst_r(Lr,alokasi_r(findElm_p(Lp,"72015"),findElm_c(Lc,"Ram 4GB")));
    insertAfter_r(Lr,findElm_r(Lr,"72015","Battery 3000mAh"),alokasi_r(findElm_p(Lp,"72014"),findElm_c(Lc,"Battery 3000mAh")));
    insertFirst_r(Lr,alokasi_r(findElm_p(Lp,"72014"),findElm_c(Lc,"Color White")));
    insertFirst_r(Lr,alokasi_r(findElm_p(Lp,"12014"),findElm_c(Lc,"Ram 4GB")));
    insertAfter_r(Lr,findElm_r(Lr,"92010","CPU 1,3GHz"),alokasi_r(findElm_p(Lp,"12014"),findElm_c(Lc,"Color Black")));

    menu(Lp,Lc,Lr);

    cout << "\n\tBy Ahmad Arsyel A.H. & Ayumi Rahmadani H.\n";
    return 0;
}
