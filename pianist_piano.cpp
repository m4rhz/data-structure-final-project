#include "pianist_piano.h"

string pilihmenu()
{
    string menu;
    cout << "===================================================" << endl;
    cout << "  TUGAS BESAR KELOMPOK 5 - DATA PIANIST DAN PIANO  " << endl;
    cout << "===================================================" << endl;
    cout << endl;
    cout << "1. Menambahkan data pianist" << endl;
    cout << "2. Menambahkan data piano " << endl;
    cout << "3. Mencari data pianist tertentu " << endl;
    cout << "4. Menambahkan relasi pianist dengan piano yang dimilikinya " << endl;
    cout << "5. Mencari data piano pada pianist tertentu " << endl;
    cout << "6. Menghapus data piano berserta relasinya " << endl;
    cout << "7. Menghapus data piano pada pianist tertentu " << endl;
    cout << "8. Menampilkan data seluruh pianist dengan piano yang dimilikinya " << endl;
    cout << "9. Menghitung banyaknya piano pada pianist tertentu " << endl;
    cout << "10. Menampilkan data pianist yang memainkan piano paling banyak " << endl;
    cout << "11. Menampilkan semua data pianist " << endl;
    cout << "12. Main Program " << endl;
    cout << "13. Keluar dari Program " << endl;
    cout << endl;
    cout << "Masukkan Pilihan Menu : ";
    cin >> menu;
    return menu;
}

void createListPianist(list_pianist &LD)
{
    first(LD) = NULL;
    last(LD) = NULL;
}

adr_pianist createElemenPianist(string namapianist)
{
    adr_pianist P = new elm_pianist;
    info(P).nama_pianist = namapianist;
    next(P) = NULL;
    frelasi(P) = NULL;
    return P;
}

void insertPt(list_pianist &LD, adr_pianist P)
{
    if (first(LD) == NULL)
    {
        first(LD) = P;
        last(LD) = P;
        next(P) = first(LD);
    }
    else
    {
        adr_pianist Q = first(LD);
        while (next(Q) != first(LD))
        {
            Q = next(Q);
        }
        next(P) = first(LD);
        next(Q) = P;
        last(LD) = P;
    }
}

void printInfoPianist(list_pianist LD)
{
    adr_pianist P = first(LD);
    if (first(LD) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        while (next(P) != first(LD))
        {
            cout << "Nama Pianist : " << info(P).nama_pianist << endl;
            cout << endl;
            P = next(P);
        }
        cout << "Nama Pianist : " << info(P).nama_pianist << endl;
        cout << endl;
    }
}

adr_pianist cariPianist(list_pianist LD, string D)
{
    adr_pianist P = first(LD);
    if (first(LD) == NULL)
    {
        cout << "list kosong" << endl;
        return NULL;
    }
    else
    {
        while (next(P) != first(LD))
        {
            if (info(P).nama_pianist == D)
            {
                return P;
            }
            P = next(P);
        }
        if (info(P).nama_pianist == D)
        {
            return P;
        }
        else
        {
            return NULL;
        }
    }
}

void deleteFirstDr(list_pianist &LD, adr_pianist &P)
{
    if (first(LD) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        adr_pianist Q = first(LD);
        while (next(Q) != first(LD))
        {
            Q = next(Q);
        }
        P = first(LD);
        first(LD) = next(first(LD));
        next(Q) = first(LD);
        next(P) = NULL;
        last(LD) = Q;
        frelasi(P) = NULL;
    }
}
void deleteLastDr(list_pianist &LD, adr_pianist &P)
{
    if (first(LD) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        adr_pianist Q = first(LD);
        adr_pianist R = first(LD);
        while (next(Q) != first(LD))
        {
            R = Q;
            Q = next(Q);
        }
        P = next(R);
        next(R) = first(LD);
        next(P) = NULL;
        last(LD) = R;
        frelasi(P) = NULL;
    }
}

void deleteAfterDr(list_pianist &LD, adr_pianist &P)
{
    if (first(LD) != NULL)
    {
        adr_pianist Q = first(LD);
        while (next(Q) != P)
        {
            Q = next(Q);
        }
        adr_pianist prec = Q;
        next(prec) = next(P);
        next(P) = NULL;
        frelasi(P) = NULL;
    }
}

void deletePt(list_pianist &LD, string nama)
{
    adr_pianist P = cariPianist(LD, nama);
    if (P != NULL)
    {
        if (P == first(LD))
        {
            deleteFirstDr(LD, P);
        }
        else if (P == last(LD))
        {
            deleteLastDr(LD, P);
        }
        else
        {
            deleteAfterDr(LD, P);
        }
    }
    else
    {
        cout << "tidak ada pianist" << endl;
    }
}

void createListPiano(list_piano &LP)
{
    first(LP) = NULL;
    last(LP) = NULL;
}

adr_piano createElemenPiano(string namapiano)
{
    adr_piano P = new elm_piano;
    info(P).nama_piano = namapiano;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertPr(list_piano &LP, adr_piano P)
{
    if (first(LP) == NULL)
    {
        first(LP) = P;
        last(LP) = P;
    }
    else
    {
        next(last(LP)) = P;
        prev(P) = last(LP);
        last(LP) = P;
    }
}

adr_piano cariPiano(list_piano LP, string x)
{
    adr_piano P = first(LP);

    while (P != NULL)
    {
        if (info(P).nama_piano == x)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void PrintDataPrPadaDr(list_pianist LD, list_piano LP, string nama)
{
    adr_piano p = cariPiano(LP, nama);
    if (p != NULL)
    {
        adr_pianist d;
        d = first(LD);
        while (next(d) != first(LD))
        {
            adr_relasi r = frelasi(d);
            if (r != NULL)
            {
                while (r != NULL)
                {
                    if (piano(r) == p)
                    {
                        cout << "piano " << nama << " sedang dimainkan oleh pianist " << info(d).nama_pianist;
                        cout << endl;
                    }
                    r = next(r);
                }
            }
            d = next(d);
        }
        p = next(p);
    }
}

void printInfoPiano(list_piano L)
{
    adr_piano P = first(L);
    cout << "List Piano yang akan dimainkan Pianist: " << endl;
    if (first(L) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        while (next(P) != NULL)
        {
            cout << "Nama piano : " << info(P).nama_piano << endl;
            cout << endl;
            P = next(P);
        }
        cout << "Nama piano : " << info(P).nama_piano << endl;
        cout << endl;
    }
}

void createElemenRelasi(adr_pianist D, adr_piano P)
{
    adr_relasi r, p;

    p = frelasi(D);

    r = new elm_relasi;

    if (p == NULL)
    {
        piano(r) = P;
        next(r) = NULL;
        prev(r) = NULL;
        frelasi(D) = r;
    }
    else
    {
        while (next(p) != NULL)
        {
            p = next(p);
        }
        piano(r) = P;
        prev(r) = p;
        next(p) = r;
        next(r) = NULL;
    }
}

adr_relasi findelmrelasi(adr_pianist pianist, string piano)
{
    adr_relasi P = frelasi(pianist);
    while (P != NULL)
    {
        if (info(piano(P)).nama_piano == piano)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void deleteFirstR(adr_pianist &D, adr_relasi &R)
{
    if (frelasi(D) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        R = frelasi(D);
        frelasi(D) = next(R);
        next(R) = NULL;
        prev(frelasi(D)) = NULL;
    }
}

void deleteLastR(adr_pianist D, adr_relasi &R)
{
    if (frelasi(D) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        adr_relasi Q = frelasi(D);
        adr_relasi P = frelasi(D);
        while (next(Q) != NULL)
        {
            P = Q;
            Q = next(Q);
        }
        R = Q;
        next(P) = NULL;
        prev(R) = NULL;
    }
}

void deleteAfterR(adr_pianist D, adr_relasi &R)
{
    adr_relasi prec = prev(R);
    if ((frelasi(D) != NULL) && (prec != NULL))
    {
        R = next(prec);
        next(prec) = next(R);
        prev(next(R)) = prec;
        next(R) = NULL;
        prev(R) = NULL;
    }
}

void delete1R(adr_pianist &D, adr_relasi &R)
{
    if (frelasi(D) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        R = frelasi(D);
        frelasi(D) = NULL;
        next(R) = NULL;
        prev(R) = NULL;
    }
}

void deleteR(adr_pianist &D, adr_relasi &R)
{
    adr_relasi x = frelasi(D);
    adr_relasi r = frelasi(D);
    adr_relasi lastr;
    while (next(r) != NULL)
    {
        r = next(r);
    }
    lastr = r;

    if (R == NULL)
    {
        cout << "tidak ada piano" << endl;
    }
    else if (R == x)
    {
        deleteFirstR(D, R);
    }
    else if (next(x) == NULL)
    {
        delete1R(D, R);
    }
    else if (R == lastr)
    {
        deleteLastR(D, R);
    }
    else
    {
        deleteAfterR(D, R);
    }
}

void printDataPianist(list_pianist LD)
{
    {
        adr_pianist d = first(LD);
        if (first(LD) == NULL)
        {
            cout << "List Kosong" << endl;
        }
        else
        {
            int i = 1;
            while (next(d) != first(LD))
            {
                cout << "Nama pianist " << i << ": " << info(d).nama_pianist << endl;
                adr_relasi r = frelasi(d);
                d = next(d);
                i++;
            }
            cout << "Nama pianist " << i << ": " << info(d).nama_pianist << endl;
            adr_relasi r = frelasi(d);
            cout << endl;
        }
    }
}

void printAllData(list_pianist LD, list_piano LP)
{
    {
        adr_pianist d = first(LD);
        if (first(LD) == NULL)
        {
            cout << "List Kosong" << endl;
        }
        else
        {
            while (next(d) != first(LD))
            {
                cout << "Pianist " << info(d).nama_pianist << " memainkan piano : " << endl;
                adr_relasi r = frelasi(d);
                while (r != NULL)
                {
                    cout << info(piano(r)).nama_piano << endl;
                    r = next(r);
                }
                d = next(d);
                cout << endl;
            }
            cout << "Pianist " << info(d).nama_pianist << " memainkan piano : " << endl;
            adr_relasi r = frelasi(d);
            while (r != NULL)
            {
                cout << info(piano(r)).nama_piano << endl;
                r = next(r);
            }
        }
    }
}

int hitungPr(adr_pianist d)
{
    int count = 0;
    adr_relasi P = frelasi(d);
    while (P != NULL)
    {
        count++;
        P = next(P);
    }
    return count;
}

void NilaiMax(list_pianist LD)
{
    int maks = 0;
    int x;
    adr_pianist d = first(LD);
    adr_pianist nama_pianist = NULL;
    while (next(d) != first(LD))
    {
        x = hitungPr(d);
        if (x > maks)
        {
            maks = x;
            nama_pianist = d;
        }
        d = next(d);
    }
    cout << "Pianist yang paling banyak memainkan piano adalah " << info(nama_pianist).nama_pianist << " dengan jumlah piano " << maks;
    cout << endl;
};