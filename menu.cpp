#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "menu.h"

Makanan::Makanan(){
    tambahMakananDefault();
}

void Makanan::tambahMakanan(int kode, const string &nama, int harga){
    daftarMakanan[kode] = make_pair(nama, harga);
}

void Makanan::hapusMakanan(int kode){
    daftarMakanan.erase(kode);
}

void Makanan::tampilkanMakanan(){
    cout << "Daftar Makanan:" << endl;
    for (const auto &makanan : daftarMakanan){
        int kode = makanan.first;
        string nama = makanan.second.first;
        int harga = makanan.second.second;
        cout << "Nama: " << nama << ", Harga: Rp" << harga << endl;
    }
}

int Makanan::getKodeMakanan(const string& nama){
    for (const auto& makanan : daftarMakanan) {
        if (makanan.second.first == nama) {
            return makanan.first;
        }
    }
    return -1;  // Kode -1 menandakan makanan tidak ditemukan
}

int Makanan::getHargaMakanan(int kode){
    auto it = daftarMakanan.find(kode);
    if (it != daftarMakanan.end()){
        it->second.second;
        return it->second.second;
    }
    return -1; // Jika kode makanan tidak ditemukan, kembalikan harga 0.0
}

string Makanan::getNamaMakanan(int kode){
    auto it = daftarMakanan.find(kode);
    if (it != daftarMakanan.end()){
        return it->second.first;
    }
    return ""; // Jika kode makanan tidak ditemukan, kembalikan string kosong
}

void Makanan::tambahMakananDefault(){
    tambahMakanan(1, "Pancake", 10000.0);
    tambahMakanan(2, "Slice Cake", 25000.0);
    tambahMakanan(3, "Waffle", 20000.0);
    tambahMakanan(4, "French Fries", 15000.0);
    tambahMakanan(5, "Aglio Olio", 35000.0);
    tambahMakanan(6, "Spagetthi", 30000.0);
    tambahMakanan(7, "Klapertaart", 20000.0);
    tambahMakanan(8, "Cupcake", 10000.0);
    tambahMakanan(9, "Donuts", 8000.0);
    tambahMakanan(10, "Panna Cotta", 20000.0);
    tambahMakanan(11, "Cappucino", 25000.0);
    tambahMakanan(12, "Machiato", 20000.0);
    tambahMakanan(13, "Espresso", 30000.0);
    tambahMakanan(14, "Americano", 22000.0);
    tambahMakanan(15, "Caramel Latte", 25000.0);
    tambahMakanan(16, "Vanilla Latte", 25000.0);
}



Pesanan::Pesanan(){
    Makanan listMakanan;
}

void Pesanan::setNama(string nm){
    nama = nm;
}

void Pesanan::tambahPesanan(int kodeMakanan, int kuantitas){
    // Cek apakah makanan sudah ada dalam pesanan
    if (daftarPesanan.find(kodeMakanan) != daftarPesanan.end()){
        daftarPesanan[kodeMakanan] += kuantitas; // Tambahkan kuantitas jika sudah ada
    }
    else{
        daftarPesanan[kodeMakanan] = kuantitas; // Tambahkan makanan baru dengan kuantitas
    }
}

void Pesanan::hapusPesanan(int kodeMakanan) {
    auto it = daftarPesanan.find(kodeMakanan);
    string namaMakanan = listMakanan.getNamaMakanan(kodeMakanan);
    if (it != daftarPesanan.end()) {
        daftarPesanan.erase(it);
        cout << "Pesanan " << namaMakanan << " telah dihapus." << endl;
    } else {
        cout << "Pesanan " << namaMakanan << " tidak ditemukan." << endl;
    }
}

int Pesanan::hitungTotalHarga(){
    int totalHarga = 0;
    for (auto &pesanan : daftarPesanan){
        int kodeMakanan = pesanan.first;
        int kuantitas = pesanan.second;
        int hargaMakanan = listMakanan.getHargaMakanan(kodeMakanan);
        totalHarga += (hargaMakanan * kuantitas);
    }
    return totalHarga;
}

void Pesanan::tampilkanPesanan() {
    cout << "Pesanan untuk " << nama << endl;
    cout << "Daftar Pesanan:" << endl;
    for (const auto& pesanan : daftarPesanan) {
        int kodeMakanan = pesanan.first;
        int kuantitas = pesanan.second;
        string namaMakanan = listMakanan.getNamaMakanan(kodeMakanan);
        int hargaMakanan = listMakanan.getHargaMakanan(kodeMakanan);
        int kode = listMakanan.getKodeMakanan(namaMakanan);

        cout << "Kode Menu: " << kode << ", Nama: " << namaMakanan << ", Kuantitas: " << kuantitas
             << ", Harga: Rp" << (hargaMakanan * kuantitas) << endl;
    }
}

