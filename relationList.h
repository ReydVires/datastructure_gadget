#ifndef RELATIONLIST_H_INCLUDED
#define RELATIONLIST_H_INCLUDED
#include <iostream>
#include "parentList.h"
#include "childList.h"
using namespace std;

#define nil NULL
#define first_r(L) L.first_r
#define last_r(L) L.last_r
#define next_r(R) R->next_r
#define parent(R) R->parent
#define child(R) R->child

typedef struct elmList_r *address_r;
struct elmList_r {
    address_r next_r;
    address_c child;
    address_p parent;
};
struct List_r {
    address_r first_r;
    address_r last_r;
};
void createList_r(List_r &L);
address_r alokasi_r(address_p P, address_c C);
void getComponent(address_p P, address_c C, address_r &R);
void dealokasi_r(address_r &R);
address_r findElm_r(List_r &L, string x, string y);
void insertFirst_r(List_r &L, address_r R);
void insertLast_r(List_r &L, address_r R);
void displayInfo_Pr(List_r L, List_p Lp);
void displayInfo_Cr(List_r L, List_c Lc);
void displayRelation(List_r L);
void deleteFirst_r(List_r &L, address_r &R);
void deleteLast_r(List_r &L, address_r &R);
void insertAfter_r(List_r &L, address_r prec, address_r R);
void deleteAfter_r(List_r &L, address_r prec, address_r &R);
void deleteParent(List_r &L, List_p &Lp, string x);
void deleteChild(List_r &L, List_c &Lc, string x);
void deleteRelation(List_r &Lr, string x, string y);
void removeComponent(List_r &L, address_r R);
int countRelation(List_r L);
void searchParent(List_r L, List_p Lp, string x);
void searchChild(List_r L, List_c Lc, string x);
void editComponent(List_r &L, List_p Lp, List_c &Lc, string x);

#endif // RELATIONLIST_H_INCLUDED
