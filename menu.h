#ifndef MENU_H
#define MENU_H

#include <string>
#include <map>
using namespace std;

class Makanan{
    private:
        map<int, pair<string, double>> daftarMakanan;

    public:
        Makanan();
        void tambahMakanan(int kode, const string &nama, int harga);
        void hapusMakanan(int kode);
        void tampilkanMakanan();
        int getKodeMakanan(const string& nama);
        int getHargaMakanan(int kode);
        string getNamaMakanan(int kode);
        void tambahMakananDefault();
};

class Pesanan{
    private:
        string nama;
        map<int, int> daftarPesanan;
        Makanan listMakanan;

    public:
        Pesanan();
        void setNama(string nm);
        void tambahPesanan(int kodeMakanan, int kuantitas);
        void hapusPesanan(int kodeMakanan);
        int hitungTotalHarga();
        void tampilkanPesanan();
};

#endif