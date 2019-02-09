#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include <iostream>
#include "buku.h"
#include "jadwal.h"

#define Nil NULL
#define infoR(P) P->infoR
#define nextR(P) P->nextR
#define prevR(P) P->prevR
#define FirstR(L) L.FirstR
#define LastR(L) L.LastR
using namespace std;

struct infotypeR{
    adrB penunjukB;
    adrJ penunjukJ;
    };

typedef struct ElmR *adrR;

struct ElmR{
    infotypeR infoR;
    adrR nextR;
    adrR prevR;
    };

struct ListR{
    adrR FirstR;
    adrR LastR;
    };

void createlistR(ListR &L);
adrR alokasiR(infotypeR X);

void insertfirstR(ListR &L, adrR P);

void deletefirstR(ListR &L, adrR &P);
void deleteafterR(ListR &L, adrR &P);
void deletelastR(ListR &L, adrR &P);
void dealokasiR(adrR P);

adrR findElmR(ListR L,string nama, int tanggal, string bulan, int tahun);

void printinfosemuajadwaldenganbuku(ListR R, ListJ J);
void printinfobukutertentu(ListR R, adrB nama);
void printinfojadwaltertentu(ListR R, adrJ tanggal);

#endif // RELASI_H_INCLUDED

