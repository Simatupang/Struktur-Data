#include "Fungsionalitas.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

void menu(ListR &R, ListB &B, ListJ &J){
    system("cls");
    int pilihan;
    cout<<"==========================================================="<<endl;
    cout<<"==                SELAMAT DATANG DI MENU UTAMA           =="<<endl;
    cout<<"==========================================================="<<endl;
    cout<<"== 1. Tambah Buku Baru                                   =="<<endl;
    cout<<"== 2. Tambah Jadwal Pinjaman Baru                        =="<<endl;
    cout<<"== 3. Tambah Relasi Baru                                 =="<<endl;
    cout<<"== 4. Hapus Buku                                         =="<<endl;
    cout<<"== 5. Tampilkan Semua Jadwal Pinjaman dengan Bukunya     =="<<endl;
    cout<<"== 6. Tampilkan Jadwal untuk Buku Tertentu               =="<<endl;
    cout<<"== 7. Tampilkan List Buku untuk Jadwal Tertentu          =="<<endl;
    cout<<"== 8. Tampilkan Buku dengan Jadwal Pinjam Paling Sedikit =="<<endl;
    cout<<"== 9. EXIT                                               =="<<endl;
    cout<<"==========================================================="<<endl;
    cout<<"silahkan pilih opsi: ";
    cin>>pilihan;
    switch (pilihan){
    case 1:
        system("cls");
        tambahbuku(B);
        getch();
        menu(R,B,J);
        break;

    case 2:
        system("cls");
        tambahjadwal(J);
        getch();
        menu(R,B,J);
        break;

    case 3:
        system("cls");
        tambahrelasi(R,B,J);
        getch();
        menu(R,B,J);
        break;

    case 4:
        system("cls");
        hapusbuku(R,B);
        getch();
        menu(R,B,J);
        break;

    case 5:
        system("cls");
        tampilkansemua(R);
        getch();
        menu(R,B,J);
        break;

    case 6:
        system("cls");
        tampiljadwalbukutertentu(R,B);
        getch();
        menu(R,B,J);
        break;

    case 7:
        system("cls");
        tampilbukujadwaltertentu(R,J);
        getch();
        menu(R,B,J);
        break;

    case 8:
        system("cls");
        tampilbukumin(B);
        getch();
        menu(R,B,J);
        break;

    case 9:
        break;

    default :
        menu(R,B,J);
    }
};

void tambahbuku(ListB &B){
    string judul;
    cout<<"====================================================================================="<<endl;
    cout<<"==                                  MENU TAMBAH BUKU                               =="<<endl;
    cout<<"====================================================================================="<<endl;
    cout<<"Silahkan masukan judul buku: ";
    cin>>judul;
    cout<<"====================================================================================="<<endl;
    if (findElmB(B,judul)== NULL){
        infotypeB Z;
        Z.nama = judul;
        Z.jumlah = 0;
        insertfirstB(B,alokasiB(Z));
        cout<<"Keterangan: Buku telah ditambah."<<endl;
    }
    else{
        cout<<"Keterangan: Buku telah tersedia"<<endl;;
    }
};

void tambahjadwal(ListJ &J){
    string bulan;
    int tanggal, tahun;
    cout<<"====================================================================================="<<endl;
    cout<<"==                              MENU TAMBAH JADWAL PINJAM                          =="<<endl;
    cout<<"====================================================================================="<<endl;
    cout<<"Silahkan masukkan tanggal peminjaman: ";
    cin>>tanggal;
    cout<<"====================================================================================="<<endl;
    cout<<"Silahkan masukkan bulan peminjaman: ";
    cin>>bulan;
    cout<<"====================================================================================="<<endl;
    cout<<"Silahkan masukkan tahun peminjaman: ";
    cin>>tahun;
    cout<<"====================================================================================="<<endl;
    if (findElmJ(J, tanggal, bulan, tahun)== NULL){
        infotypeJ P;
        P.tanggal = tanggal;
        P.bulan = bulan;
        P.tahun = tahun;
        insertfirstJ(J,alokasiJ(P));
        cout<<"Keterangan: Jadwal telah ditambah."<<endl;
    }
    else{
        cout<<"Keterangan: Jadwal telah tersedia."<<endl;
    }
};

void tambahrelasi(ListR &R, ListB B, ListJ J){
    string judul, bulan;
    int tanggal, tahun;
    cout<<"====================================================================================="<<endl;
    cout<<"==                              MENU TAMBAH JADWAL PINJAM                          =="<<endl;
    cout<<"====================================================================================="<<endl;
    cout<<"Masukkan judul buku: ";
    cin>>judul;
    cout<<"====================================================================================="<<endl;
    cout<<"Silahkan masukkan tanggal peminjaman: ";
    cin>>tanggal;
    cout<<"====================================================================================="<<endl;
    cout<<"Silahkan masukkan bulan peminjaman: ";
    cin>>bulan;
    cout<<"====================================================================================="<<endl;
    cout<<"Silahkan masukkan tahun peminjaman: ";
    cin>>tahun;
    cout<<"====================================================================================="<<endl;
    if (findElmB(B,judul) && findElmJ(J,tanggal,bulan,tahun)){
        infotypeR X;
        X.penunjukB = findElmB(B,judul);
        X.penunjukJ = findElmJ(J,tanggal,bulan,tahun);
        if (!findElmR(R,judul,tanggal,bulan,tahun)){
            insertfirstR(R,alokasiR(X));
            cout<<"Keterangan: Relasi telah ditambah"<<endl;
        }
        else{
            cout<<"Keterangan: Relasi telah tersedia sebelumnya. silahkan input data lain"<<endl;
        }

    }
    else{
        cout<<"Keterangan: Pencarian tidak tersedia / data yang anda input kosong"<<endl;
    }
};

void hapusbuku(ListR &R, ListB &B){
    string X;
    cout<<"====================================================================================="<<endl;
    cout<<"==                              MENU HAPUS BUKU                                    =="<<endl;
    cout<<"====================================================================================="<<endl;
    cout<<endl;
    cout<<"masukkan judul buku yang ingin dihapus: ";
    cin>>X;
    cout<<"====================================================================================="<<endl;
    adrB P = findElmB(B,X);
    if (P != NULL){
        adrR Q = FirstR(R);
        while(Q != NULL){
            if(infoR(Q).penunjukB == P){
                if (Q == FirstR(R)){
                    deletefirstR(R,Q);
                }
                else if(Q == LastR(R)){
                    deletelastR(R,Q);
                }
                else{
                    deleteafterR(R,Q);
                }
            }
            Q = nextR(Q);
        }
        if (P == FirstB(B)){
            deletefirstB(B,P);
        }
        else if(P == LastB(B)){
            deletelastB(B,P);
        }
        else{
            deleteafterB(B,P);
        }
        cout<<"Keterangan: buku telah dihapus"<<endl;
    }
    else{
        cout<<"Keterangan: buku tidak ditemukan"<<endl;
    }
};

void tampilkansemua(ListR R){
    adrR X = FirstR(R);
    cout<<"====================================================================================="<<endl;
    cout<<"==                             DAFTAR BUKU PINJAMAN                                =="<<endl;
    cout<<"====================================================================================="<<endl;
    if(X != NULL){
        while(X != NULL){
            cout<<"       "<<endl;
            cout<<infoB(infoR(X).penunjukB).nama<<": ";
            cout<<infoJ(infoR(X).penunjukJ).tanggal<<" ";
            cout<<infoJ(infoR(X).penunjukJ).bulan<<" ";
            cout<<infoJ(infoR(X).penunjukJ).tahun<<"."<<endl;
            X = nextR(X);
        }
    }
    else{
        cout<<"Keterangan: Data Kosong"<<endl;
    }
};

void tampiljadwalbukutertentu(ListR R, ListB B){
    string judul;
    cout<<"====================================================================================="<<endl;
    cout<<"==                             DAFTAR BUKU PINJAMAN                                =="<<endl;
    cout<<"====================================================================================="<<endl;
    cout<<"Silahkan masukkan judul buku: ";
    cin>>judul;
    cout<<"====================================================================================="<<endl;
    adrB X = findElmB(B, judul);
    adrR P = FirstR(R);
    if (X == NULL){
        cout<<"Keterangan: buku tak tersedia"<<endl;
    }
    else{
        if(P != NULL){
            while (P != NULL) {
                if (infoB(infoR(P).penunjukB).nama == infoB(X).nama){
                    cout<<"                ";
                    cout<<infoB(X).nama<<": ";
                    cout<<infoJ(infoR(P).penunjukJ).tanggal<<" ";
                    cout<<infoJ(infoR(P).penunjukJ).bulan<<" ";
                    cout<<infoJ(infoR(P).penunjukJ).tahun<<"."<<endl;
                }
                P = nextR(P);
            }
        }
        else{
            cout<<"Keterangan: buku belum dipinjam"<<endl;
        }
    }
};

void tampilbukujadwaltertentu(ListR R, ListJ J){
    string bulan;
    int tanggal, tahun;
    cout<<"====================================================================================="<<endl;
    cout<<"==                             DAFTAR BUKU PINJAMAN                                =="<<endl;
    cout<<"====================================================================================="<<endl;
    cout<<"Silahkan masukkan tanggal peminjaman: ";
    cin>>tanggal;
    cout<<"====================================================================================="<<endl;
    cout<<"Silahkan masukkan bulan peminjaman: ";
    cin>>bulan;
    cout<<"====================================================================================="<<endl;
    cout<<"Silahkan masukkan tahun peminjaman: ";
    cin>>tahun;
    cout<<"====================================================================================="<<endl;
    adrJ X = findElmJ(J, tanggal, bulan, tahun);
    if(X != NULL){
        adrR P = FirstR(R);
        if(P != NULL){
            while (P != NULL) {
                if (infoR(P).penunjukJ == X){
                    cout<<"                      ";
                    cout<<infoJ(X).tanggal<<" ";
                    cout<<infoJ(X).bulan<<" ";
                    cout<<infoJ(X).tahun<<": ";
                    cout<<infoB(infoR(P).penunjukB).nama<<"."<<endl;
                }
                P = nextR(P);
            }
        }
        else{
            cout<<"Keterangan: Tak ada buku yang dipinjam pinjam di tanggal ini"<<endl;
        }
    }
    else{
        cout<<"Keterangan: Tanggal tak tersedia"<<endl;
    }
};

void tampilbukumin(ListB B){
    adrB X = findmin(B);
    cout<<"====================================================================================="<<endl;
    cout<<"==                             DAFTAR BUKU PINJAMAN                                =="<<endl;
    cout<<"====================================================================================="<<endl;
    if(X != NULL){
        cout<<"Buku dengan pinjaman paling sedikit: "<<infoB(X).nama<<endl;
    }
    else if(X == NULL){
        cout<<"Keeterangan: Tak ada pinjaman buku ter-sedikit"<<endl;
    }
};
