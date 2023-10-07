#ifndef PIANIST_PIANO_H_INCLUDED
#define PIANIST_PIANO_H_INCLUDED

#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(R) R->prev
#define first(L) (L).first
#define last(L) (L).last
#define frelasi(p) (p)->frelasi
#define piano(p) (p)->piano
#define pianist(P) (P)->pianist

typedef struct elm_relasi *adr_relasi;

struct pianist
{
    string nama_pianist;
};

typedef struct elm_pianist *adr_pianist;
typedef pianist infotypeD;

struct elm_pianist
{
    infotypeD info;
    adr_pianist next;
    adr_pianist prev;
    adr_relasi frelasi;
};

struct list_pianist
{
    adr_pianist first;
    adr_pianist last;
};

struct piano
{
    string nama_piano;
};

typedef struct elm_piano *adr_piano;
typedef piano infotypePr;

struct elm_piano
{
    adr_piano next;
    infotypePr info;
    adr_piano prev;
    adr_relasi frelasi;
};

struct list_piano
{
    adr_piano first;
    adr_piano last;
};

struct elm_relasi
{
    adr_piano piano;
    adr_relasi prev;
    adr_relasi next;
};

string pilihmenu();
void createListPianist(list_pianist &LD);
adr_pianist createElemenPianist(string namapianist);
void insertPt(list_pianist &LD, adr_pianist P);
void printInfoPianist(list_pianist LD);
adr_pianist cariPianist(list_pianist LD, string D);
void deleteFirstDr(list_pianist &LD, adr_piano &P);
void deleteLastDr(list_pianist &LD, adr_piano &P);
void deleteAfterDr(list_pianist &LD, adr_piano &P);
void deletePt(list_pianist &LD, string nama);
void createListPiano(list_piano &LP);
adr_piano createElemenPiano(string namapiano);
void insertPr(list_piano &LP, adr_piano P);
void printInfoPiano(list_piano L);
adr_piano cariPiano(list_piano LP, string x);
void PrintDataPrPadaDr(list_pianist LD, list_piano LP, string nama);
void createElemenRelasi(adr_pianist D, adr_piano P);
adr_relasi findelmrelasi(adr_pianist, string pianist);
void deleteFirstR(adr_pianist &D, adr_relasi &R);
void deleteLastR(adr_pianist D, adr_relasi &R);
void deleteAfterR(adr_pianist D, adr_relasi &R);
void delete1R(adr_pianist &D, adr_relasi &R);
void deleteR(adr_pianist &D, adr_relasi &R);
void printDataPianist(list_pianist LD);
void printAllData(list_pianist LD, list_piano LP);
int hitungPr(adr_pianist d);
void NilaiMax(list_pianist LD);

#endif // PIANIST_PIANO_H_INCLUDEDS
