#include "pianist_piano.h"
#include "pianist_piano.cpp"
#include <iostream>

using namespace std;

int main()
{
    list_pianist LD;
    adr_pianist A;
    createListPianist(LD);
    list_piano LP;
    adr_piano B;
    createListPiano(LP);

    infotypeD pianist;
    infotypePr piano;
    string pilihan;
    pilihan = pilihmenu();
    while (pilihan != "0")
    {
        if (pilihan == "1")
        {
            int n;
            string nama;
            cout << "Masukkan berapa banyak data yang akan dimasukkan : ";
            cin >> n;
            cout << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "Masukkan Data Ke " << i + 1 << endl;
                cout << "Masukkan Nama pianist : ";
                cin >> nama;
                A = createElemenPianist(nama);
                insertPt(LD, A);
                cout << endl;
            }
            cout << "Berhasil Menambahkan Data" << endl;
            printInfoPianist(LD);
            cout << endl;
        }
        else if (pilihan == "2")
        {
            string nama;
            int m;
            cout << "Masukkan berapa banyak data yang akan dimasukkan : ";
            cin >> m;
            cout << endl;
            for (int j = 0; j < m; j++)
            {
                cout << "Masukkan Data Ke " << j + 1 << endl;
                cout << "Masukkan Nama piano : ";
                cin >> nama;
                B = createElemenPiano(nama);
                insertPr(LP, B);
                cout << endl;
            }

            cout << "Berhasil Menambahkan Data" << endl;
            cout << endl;
            printInfoPiano(LP);
        }
        else if (pilihan == "3")
        {
            if (first(LD) != NULL)
            {
                string pianistDicari;
                cout << "Nama pianist yang ingin dicari : ";
                cin >> pianistDicari;
                adr_pianist x;
                x = cariPianist(LD, pianistDicari);
                if (x != NULL)
                {
                    cout << "Data pianist Ditemukan." << endl;
                    cout << "pianist atas nama " << info(x).nama_pianist << endl;
                }
                else
                {
                    cout << "Data tidak ditemukan." << endl;
                }
            }
            else
            {
                cout << "Belum ada pianist." << endl;
            }
        }
        else if (pilihan == "4")
        {
            printInfoPianist(LD);
            printInfoPiano(LP);
            string dr, pr;
            cout << "Masukkan Nama pianist: ";
            cin >> dr;
            cout << "Masukkan Nama piano: ";
            cin >> pr;
            adr_pianist D;
            adr_piano P;
            D = cariPianist(LD, dr);
            P = cariPiano(LP, pr);
            if (D != NULL && P != NULL)
            {
                createElemenRelasi(D, P);
                cout << "Relasi pianist " << dr << " dan piano " << pr << " berhasil dibuat" << endl;
                cout << endl;
            }
            else
            {
                cout << "Relasi gagal dibuat";
                cout << endl;
            }
        }
        else if (pilihan == "5")
        {
            string x;
            cout << "Masukkan nama piano: ";
            cin >> x;
            PrintDataPrPadaDr(LD, LP, x);
        }
        else if (pilihan == "6")
        {
            string dok;
            cout << "Masukan nama pianist yang ingin dihapus relasinya: ";
            cin >> dok;
            deletePt(LD, dok);
            cout << "Relasi berhasil dihapus" << endl;
        }
        else if (pilihan == "7")
        {
            string per, dr;
            adr_pianist D;
            adr_relasi R;
            cout << "Masukkan nama pianist dari piano yang akan dihapus datanya: ";
            cin >> dr;
            D = cariPianist(LD, dr);
            cout << "Masukkan nama piano yang akan dihapus datanya: ";
            cin >> per;
            R = findelmrelasi(D, per);
            deleteR(D, R);
            cout << "Data berhasil dihapus";
            cout << endl;
        }
        else if (pilihan == "8")
        {
            if (first(LD) != NULL)
            {
                printAllData(LD, LP);
            }
            else
            {
                cout << "data masih kosong" << endl;
            }
        }
        else if (pilihan == "9")
        {
            adr_pianist x;
            string per;
            cout << "Masukkan nama pianist yang ingin diketahui jumlah pianonya: ";
            cin >> per;
            int jum = 0;
            x = cariPianist(LD, per);
            jum = hitungPr(x);
            cout << "Pianist " << per << " memiliki jumlah piano " << jum;
            cout << endl;
        }
        else if (pilihan == "10")
        {
            NilaiMax(LD);
        }
        else if (pilihan == "11")
        {
            if (first(LD) != NULL)
            {
                printDataPianist(LD);
            }
            else
            {
                cout << "data masih kosong" << endl;
            }
        }
        else if (pilihan == "13")
        {
            break;
        }
        else
        {
            cout << "Pilihan Tidak Tersedia" << endl;
        }
        cout << "Kembali ke menu? (y/n): ";
        char kembali;
        cin >> kembali;
        if (kembali == 'y' || kembali == 'Y')
        {
            system("cls");
            pilihan = pilihmenu();
        }
        else
        {
            break;
            // pilihan = pilihmenu();
        }
    }
    cout << "Terima Kasih" << endl;
    cout << endl;
    return 0;
}
