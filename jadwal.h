#ifndef JADWAL_H_INCLUDED
#define JADWAL_H_INCLUDED

#include <iostream>
#include <string>
#define Nil NULL
#define infoJ(P) P->infoJ
#define nextJ(P) P->nextJ
#define prevJ(P) P->prevJ
#define FirstJ(L) L.FirstJ
#define LastJ(L) L.LastJ
using namespace std;


struct infotypeJ{
    int tanggal;
    string bulan;
    int tahun;
    };

typedef struct ElmJ *adrJ;

struct ElmJ{
    infotypeJ infoJ;
    adrJ    nextJ;
    adrJ    prevJ;
    };

struct ListJ{
    adrJ FirstJ;
    adrJ LastJ;
    };

void createlistJ(ListJ &L);
adrJ alokasiJ(infotypeJ X);

void insertfirstJ(ListJ &L, adrJ P);

void deletefirstJ(ListJ &L, adrJ &P);
void deleteafterJ(ListJ &L, adrJ &P);
void deletelastJ(ListJ &L, adrJ &P);
void dealokasiJ(adrJ P);

adrJ findElmJ(ListJ L, int X, string Y, int Z);

void printinfoJ(ListJ L);
#endif // JADWAL_H_INCLUDED
