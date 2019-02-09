#include "buku.h"

void createlistB(ListB &L){
    FirstB(L) = NULL;
    LastB(L) = NULL;
    };

adrB alokasiB(infotypeB X){
    adrB P = new ElmB;
    X.jumlah = 0;
    infoB(P) = X;
    nextB(P) = NULL;
    prevB(P) = NULL;
    return P;
};

void insertfirstB(ListB &L, adrB P){
    if (FirstB(L) == NULL){
        FirstB(L) = P;
        LastB(L) = P;
    }
    else{
        nextB(P) = FirstB(L);
        prevB(FirstB(L)) = P;
        FirstB(L) = P;
    };
};

void deletefirstB(ListB &L, adrB &P){
    if (FirstB(L) != NULL){
            P = FirstB(L);
            FirstB(L) = nextB(FirstB(L));
            nextB(P) = NULL;
            prevB(FirstB(L)) = NULL;
    }
};

void deleteafterB(ListB &L, adrB &P){
    if (FirstB(L) != NULL){
        adrB Q = FirstB(L);
        while ( prevB(Q) != P){
            Q = nextB(Q);
        }
        nextB(P) = nextB(Q);
        prevB(nextB(Q)) = P;
        nextB(Q) = NULL;
        prevB(Q) = NULL;
    }
};

void deletelastB(ListB &L, adrB &P){
    if (FirstB(L) != NULL){
            P = LastB(L);
            LastB(L) = prevB(P);
            prevB(P) = NULL;
            nextB(LastB(L)) = NULL;
    }
};

void dealokasiB(adrB P){
    delete P;
};

adrB findElmB(ListB L, string X){
    adrB P = FirstB(L);
    while (P != NULL){
        if (infoB(P).nama == X){
            return P;
        }
        P = nextB(P);
    }
    return NULL;
};

void printinfoB(ListB L){
    if (FirstB(L) == NULL){
        cout<<" List Kosong"<<endl;
    }
    else{
        adrB P = new ElmB;
        P = FirstB(L);
        while (P != NULL){
            cout<<infoB(P).nama<<endl;
            P = nextB(P);
        }
    };
};

adrB findmin(ListB B){
    adrB Q = NULL;
    int minim = 9999;
    adrB P = FirstB(B);
    while (P != NULL){
        if (minim > infoB(P).jumlah){
            minim = infoB(P).jumlah;
            Q = P;
        }
        else if (minim == infoB(P).jumlah){
            Q = NULL;
        }
        P = nextB(P);
    }
    return Q;
};
