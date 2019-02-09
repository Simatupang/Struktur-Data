#ifndef FUNGSIONALITAS_H_INCLUDED
#define FUNGSIONALITAS_H_INCLUDED
#include "relasi.h"

void menu(ListR &R, ListB &B, ListJ &J);
void tambahbuku(ListB &B);
void tambahjadwal(ListJ &J);
void tambahrelasi(ListR &R, ListB B, ListJ J);
void hapusbuku(ListR &R, ListB &B);
void tampilkansemua(ListR R);
void tampiljadwalbukutertentu(ListR R, ListB B);
void tampilbukujadwaltertentu(ListR R, ListJ J);
void tampilbukumin(ListB B);
#endif // FUNGSIONALITAS_H_INCLUDED

