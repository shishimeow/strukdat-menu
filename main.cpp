#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include "antrian.h"
#include "menu.h"

using namespace std;

int main()
{
    int choose;
    char order;
    Queue antrian;
    int cmd;
    int i = 1;
    awal:
    int nomor;
    int jumlah;
    string name;
    Makanan menu;
    Pesanan pesanan;
    int choice;
    
    cout << "================================================================\n";
    cout << "                 ~ S E L A M A T   D A T A N G ! ~                ";
    cout << "\n================================================================\n";
    cout << "1. Tampilkan Menu\n"
         << "2. Lihat Antrian\n"
         << "3. Exit";
    do{
        cout << "\n\nPilih Nomor : ";
        cin >> choose;
        switch(choose){
            case 1 : menu:
                     cout<<"\n==========================================================================\n";
                     cout<<"                           ~ M E N U  C A F E ~                               ";
                     cout<<"\n==========================================================================\n";
                     cout<<"                Makanan              |              Minuman              |";
                     cout<<"\n==========================================================================\n";
                     cout<<"1. Pancake, 10000                    |11. Cappucino, 25000               |\n";
                     cout<<"2. Slice Cake, 250000                |12. Macchiato, 20000               |\n";
                     cout<<"3. Waffle, 20000                     |13. Espresso, 30000                |\n";
                     cout<<"4. French Fries, 15000               |14. Americaon, 25000               |\n";
                     cout<<"5. Aglio Olio, 35000                 |15. Caramel Latte, 25000           |\n";
                     cout<<"6. Spagetthi, 30000                  |16. Vanilla Latte, 25000           |\n";
                     cout<<"7. Klapertaart, 20000                |                                   |\n";
                     cout<<"8. Cupcake, 10000                    |                                   |\n";
                     cout<<"9. Donuts, 8000                      |                                   |\n";
                     cout<<"10. Panna Cotta, 20000               |                                   |\n";                
                     cout<<"==========================================================================\n" << endl;

                    cout << "--------------------------------------------------------\n";
                    cout << "1. Pesan Menu\n"
                         << "2. Hapus Menu\n"
                         << "3. Tampilkan Invoice\n"
                         << "4. Kembali ke Menu Utama\n" << endl;
                    cout << "Pilihan Anda: ";
                    cin >> choice;
                    

                    switch(choice){
                        case 1: antrian.enqueue(i);
                                i++;
                                cout << "--------------------------------------------------------\n";
                                cout << "Nomor Antrian Anda : " << antrian.last() << endl;
                                cout << "Nama Pemesan       : ";
                                cin >> name;
                                pesanan.setNama(name);

                                second: 
                                cout << "Pilih Nomor Pesanan : ";
                                cin >> nomor;
                                cout << "Jumlah Pesanan Anda : ";
                                cin >> jumlah;
                                pesanan.tambahPesanan(nomor, jumlah);
                                cout << endl;

                                cout << "Ada tambahan pesanan? (Y/N)\n";
                                cin >> order;
                    
                                if (order == 'y' || order == 'Y'){
                                    goto second;
                                } else if (order == 'n' || order == 'N'){
                                    goto menu;
                                }                    
                                break;
                        case 2: cout << "--------------------------------------------------------\n";
                                pesanan.tampilkanPesanan();
                                third:
                                cout << "\nKode Menu yang Akan Dihapus : ";
                                cin >> nomor;
                                pesanan.hapusPesanan(nomor);
                                cout << "--------------------------------------------------------\n";
                                pesanan.tampilkanPesanan();
                                cout << "\nApakah ada menu lain yang ingin dihapus? (Y/N)\n";
                                cin >> order;

                                if (order == 'y' | order == 'Y'){
                                    goto third;
                                } else if (order == 'n' | order == 'N'){
                                    cout << "--------------------------------------------------------\n";
                                    goto menu;
                                }
                                break;
                        case 3: cout << "\n--------------------------------------------------------\n";
                                pesanan.tampilkanPesanan();
                                cout << "Total Pembayaran Anda: Rp" << pesanan.hitungTotalHarga() << endl;
                                cout << "\nKetik 'Y' untuk kembali ke Menu Utama\n";
                                cout << "Ketik 'B' untuk kembali ke Menu Sebelumnya\n";
                                cout << "Pilihan Anda: ";
                                cin >> order;

                                if (order == 'y' | order == 'Y'){
                                    goto awal;
                                } else if (order == 'b' | order == 'B'){
                                    goto menu;
                                }
                                break;
                        case 4: cout << endl;
                                goto awal;
                                break;
                    }

            case 2 :
                    cout << "Banyak Antrian Saat Ini: " << antrian.size()<< endl;
                    cout << "\n";
                    goto awal;
                    break;

            case 3 : 
                cout << "================================================================\n";
                cout << "                     ~ T H A N K  Y O U ! ~                       ";
                cout << "\n================================================================\n";
            exit(1);
            

        }
    } while (order=='y' || order=='Y');
    cout << "Thanks for order!";
    return 0;    
}