#include "jadwal.h"

void createlistJ(ListJ &L){
    FirstJ(L) = NULL;
    LastJ(L) = NULL;
    };

adrJ alokasiJ(infotypeJ X){
    adrJ P = new ElmJ;
    infoJ(P) = X;
    nextJ(P) = NULL;
    prevJ(P) = NULL;
    return P;
};

void insertfirstJ(ListJ &L, adrJ P){
    if (FirstJ(L) == NULL){
        FirstJ(L) = P;
        LastJ(L) = P;
    }
    else{
        nextJ(P) = FirstJ(L);
        prevJ(FirstJ(L)) = P;
        FirstJ(L) = P;
    };
};

void deletefirstJ(ListJ &L, adrJ &P){
    if (FirstJ(L) != NULL){
        P = FirstJ(L);
        FirstJ(L) = nextJ(FirstJ(L));
        nextJ(P) = NULL;
        prevJ(FirstJ(L)) = NULL;
    };
};

void deleteafterJ(ListJ &L, adrJ &P){
    if (FirstJ(L) != NULL){
        adrJ Q = FirstJ(L);
        while ( prevJ(Q) != P){
            Q = nextJ(Q);
        }
        nextJ(P) = nextJ(Q);
        prevJ(nextJ(Q)) = P;
        nextJ(Q) = NULL;
        prevJ(Q) = NULL;
    }
};

void deletelastJ(ListJ &L, adrJ &P){
    if (FirstJ(L) != NULL){
            P = LastJ(L);
            LastJ(L) = prevJ(P);
            prevJ(P) = NULL;
            nextJ(LastJ(L)) = NULL;
    }
};

void dealokasiJ(adrJ P){
    delete P;
};

adrJ findElmJ(ListJ L, int X, string Y, int Z){
    adrJ P = FirstJ(L);
    while (P != NULL){
        if ((infoJ(P).tanggal == X) && (infoJ(P).bulan == Y) && (infoJ(P).tahun == Z)){
            return P;
        }
        P = nextJ(P);
    }
    return NULL;
};

void printinfoJ(ListJ L){
    if (FirstJ(L) == NULL){
        cout<<" List Kosong"<<endl;
    }
    else{
        adrJ P = FirstJ(L);
        while (P != NULL){
            cout<<infoJ(P).tanggal<<" ";
            cout<<infoJ(P).bulan<<" ";
            cout<<infoJ(P).tahun<<endl;
            P = nextJ(P);
        }
    };
};
