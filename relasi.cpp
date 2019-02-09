#include "relasi.h"
#include "buku.h"
#include "jadwal.h"

void createlistR(ListR &L){
    FirstR(L) = NULL;
    LastR(L) = NULL;
    };

adrR alokasiR(infotypeR X){
    adrR P = new ElmR;
    infoB(X.penunjukB).jumlah ++;
    infoR(P) = X;
    nextR(P) = NULL;
    prevR(P) = NULL;
    return P;
};

void insertfirstR(ListR &L, adrR P){
    if (FirstR(L) == NULL){
        FirstR(L) = P;
        LastR(L) = P;
    }
    else{
        nextR(P) = FirstR(L);
        prevR(FirstR(L)) = P;
        FirstR(L) = P;
    };
};

void deletefirstR(ListR &L, adrR &P){
    if (FirstR(L) != NULL){
        P = FirstR(L);
        FirstR(L) = nextR(FirstR(L));
        nextR(P) = NULL;
        prevR(FirstR(L)) = NULL;
        infoB(infoR(P).penunjukB).jumlah --;
    };
};

void deleteafterR(ListR &L, adrR &P){
    if (FirstR(L) != NULL){
        adrR Q = FirstR(L);
        while ( prevR(Q) != P){
            Q = nextR(Q);
        }
        nextR(P) = nextR(Q);
        prevR(nextR(Q)) = P;
        nextR(Q) = NULL;
        prevR(Q) = NULL;
        infoB(infoR(P).penunjukB).jumlah --;
    }
};

void deletelastR(ListR &L, adrR &P){
    if (FirstR(L) != NULL){
            P = LastR(L);
            LastR(L) = prevR(P);
            prevR(P) = NULL;
            nextR(LastR(L)) = NULL;
            infoB(infoR(P).penunjukB).jumlah --;
    }
};

void dealokasiR(adrR P){
    infoB(infoR(P).penunjukB).jumlah --;
    delete P;

};

adrR findElmR(ListR L,string nama, int tanggal, string bulan, int tahun){
    adrR P = FirstR(L);
    while (P != NULL){
        if ((infoJ(infoR(P).penunjukJ).tanggal == tanggal) && (infoJ(infoR(P).penunjukJ).bulan == bulan) && (infoJ(infoR(P).penunjukJ).tahun == tahun) && (infoB(infoR(P).penunjukB).nama == nama)){
            return P;
        }
        P = nextR(P);
    }
    return NULL;
};

void printinfosemuajadwaldenganbuku(ListR R, ListJ J){
    if (FirstJ(J) == NULL){
        cout<<" List Kosong"<<endl;
    }
    else{
        adrJ P = FirstJ(J);

        while (P != NULL){
            cout<<infoJ(P).tanggal<< " ";
            cout<<infoJ(P).bulan<< " ";
            cout<<infoJ(P).tahun<<endl;
            adrR Q = FirstR(R);
            while (Q != NULL){
                if (infoR(Q).penunjukJ == P){
                    cout<<infoB(infoR(Q).penunjukB).nama<<", ";
                }
                Q = nextR(Q);
            }
            cout<<endl;
            P = nextJ(P);
        }
    }
};

void printinfobukutertentu(ListR R, adrB nama){
    if (FirstR(R) == NULL){
        cout<<" List Kosong"<<endl;
    }
    else{
        adrR Q = FirstR(R);
        while (Q != NULL){
            if (infoR(Q).penunjukB == nama){
                cout<<infoB(infoR(Q).penunjukB).nama<< ": ";
                cout<<infoJ(infoR(Q).penunjukJ).tanggal<< " ";
                cout<<infoJ(infoR(Q).penunjukJ).bulan<< " ";
                cout<<infoJ(infoR(Q).penunjukJ).tahun<<endl;
        }
            Q = nextR(Q);
        }
    }
};

void printinfojadwaltertentu(ListR R, adrJ tanggal){
    if (FirstR(R) == NULL){
        cout<<" List Kosong"<<endl;
    }
    else{
        adrR Q = FirstR(R);
        while (Q != NULL){
            if (infoR(Q).penunjukJ == tanggal){
                cout<<infoJ(infoR(Q).penunjukJ).tanggal<<" ";
                cout<<infoJ(infoR(Q).penunjukJ).bulan<<" ";
                cout<<infoJ(infoR(Q).penunjukJ).tahun<<" : ";
                cout<<infoB(infoR(Q).penunjukB).nama<<endl;
        }
            Q = nextR(Q);
        }
    }
};
