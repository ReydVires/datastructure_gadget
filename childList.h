#ifndef CHILDLIST_H_INCLUDED
#define CHILDLIST_H_INCLUDED
#include <iostream>
using namespace std;

#define nil NULL
#define first_c(L) L.first_c
#define last_c(L) L.last_c
#define next_c(P) P->next_c
#define info_c(P) P->info_c

typedef string infotype_c;
typedef struct elmList_c *address_c;
struct elmList_c {
    infotype_c info_c;
    address_c next_c;
};
struct List_c {
    address_c first_c;
    address_c last_c;
};
void createList_c(List_c &L);
address_c alokasi_c(infotype_c x);
address_c findElm_c(List_c L, infotype_c x);
void dealokasi_c(address_c &P);
void insertFirst_c(List_c &L, address_c P);
void insertLast_c(List_c &L, address_c P);
void displayInfo_c(List_c L);
void deleteFirst_c(List_c &L, address_c &P);
void deleteLast_c(List_c &L, address_c &P);
void insertAfter_c(List_c &L, address_c prec, address_c P);
void deleteAfter_c(List_c &L, address_c prec, address_c &P);
void deletebyValue_c(List_c &L, infotype_c x);
int countData_c(List_c L);
void editInfo_c(List_c &L, string x);
void sortingChild_A(List_c &L); //InsertionSort
void sortingChild_D(List_c &L);

#endif // CHILDLIST_H_INCLUDED
