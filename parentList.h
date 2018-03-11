#ifndef PARENTLIST_H_INCLUDED
#define PARENTLIST_H_INCLUDED
#include <iostream>
using namespace std;

#define nil NULL
#define first_p(L) L.first_p
#define last_p(L) L.last_p
#define next_p(P) P->next_p
#define info_p(P) P->info_p

typedef struct gadget infotype_p;
struct gadget {
    string name;
    string type;
    string imei;
    bool camera,ram,battery,os,cpu,color;
};
typedef struct elmList_p *address_p;
struct elmList_p {
    infotype_p info_p;
    address_p next_p;
};
struct List_p {
    address_p first_p;
    address_p last_p;
};
void createList_p(List_p &L);
address_p alokasi_p(string name, string type, string imei);
address_p findElm_p(List_p L, string x);
void dealokasi_p(address_p &P);
void insertFirst_p(List_p &L, address_p P);
void insertLast_p(List_p &L, address_p P);
void displayInfo_p(List_p L);
void deleteFirst_p(List_p &L, address_p &P);
void deleteLast_p(List_p &L, address_p &P);
void insertAfter_p(List_p &L, address_p prec, address_p P);
void deleteAfter_p(List_p &L, address_p prec, address_p &P);
void deletebyValue_p(List_p &L, string x);
int countData_p(List_p L);
void editInfo_p(List_p &L, char E, string x);
void sortingParent_A(List_p &L); //InsertionSort
void sortingParent_D(List_p &L);
bool imeiCheck(List_p Lp, string x);
#endif // PARENTLIST_H_INCLUDED
