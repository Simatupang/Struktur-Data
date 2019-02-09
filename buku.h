#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED

#include <iostream>
#include <string>
#define Nil NULL
#define infoB(P) P->infoB
#define nextB(P) P->nextB
#define prevB(P) P->prevB
#define FirstB(L) L.FirstB
#define LastB(L) L.LastB

using namespace std;

struct infotypeB{
    string nama;
    int jumlah;
    };

typedef struct ElmB *adrB;

struct ElmB{
    infotypeB infoB;
    adrB    nextB;
    adrB    prevB;
    };

struct ListB{
    adrB FirstB;
    adrB LastB;
    };

void createlistB(ListB &L);
adrB alokasiB(infotypeB X);

void insertfirstB(ListB &L, adrB P);

void deletefirstB(ListB &L, adrB &P);
void deleteafterB(ListB &L, adrB &P);
void deletelastB(ListB &L, adrB &P);
void dealokasiB(adrB P);

adrB findElmB(ListB L, string X);

void printinfoB(ListB L);
adrB findmin(ListB B);

#endif // BUKU_H_INCLUDED
