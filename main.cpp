#include <unistd.h>
#include "antrian.h"
#include "menu.h"
#include "lagu.h"
#include "tampilan.h"

using namespace std;

int main()
{
    int choose;
    char order;
    Queue antrian;
    QueueLagu lagu;
    int cmd;
    int i = 1;

    lagu.beginSong();
    awal:
    int nomor;
    int jumlah;
    string name;
    Makanan menu;
    Pesanan pesanan;
    int choice;
    
    menuUtama();
    cout << "\x1b[38;5;228m";
    do{
        cout << "\n\n      ~ Pilih Nomor : ";
        cin >> choose;
        switch(choose){
            case 1 : system("cls"); 
                    menu:
                    menuList();
                    opsiMenu();
                    cout << "\x1b[38;5;228m";
                    cout << "\n\n\n      ~ Pilihan Anda: ";
                    cin >> choice;
                    

                    switch(choice){
                        case 1: antrian.enqueue(i);
                                i++;
                                cout << "       --------------------------------------------------------\n";
                                cout << "       Nomor Antrian Anda : " << antrian.last() << endl;
                                cout << "       Nama Pemesan       : ";
                                cin >> name;
                                pesanan.setNama(name);

                                second: 
                                cout << "       Pilih Nomor Pesanan : ";
                                cin >> nomor;
                                cout << "       Jumlah Pesanan Anda : ";
                                cin >> jumlah;
                                pesanan.tambahPesanan(nomor, jumlah);
                                cout << endl;

                                cout << "       Ada tambahan pesanan? (Y/N)\n";
                                cout <<"       ~ Pilihan Anda: ";
                                cin >> order;
                    
                                if (order == 'y' || order == 'Y'){
                                    cout << "\n       --------------------------------------------------------\n";
                                    goto second;
                                } else if (order == 'n' || order == 'N'){
                                    system("cls");
                                    goto menu;
                                } system("cls"); 
                                thankYou();
                                Sleep(3000);                  
                                break;

                        case 2: system("cls");
                                banner();
                                cout << "\x1b[38;5;228m";
                                cout << "\n\n";
                                pesanan.tampilkanPesanan();
                                third:
                                cout << "\n       Kode Menu yang Akan Dihapus : ";
                                cin >> nomor;
                                pesanan.hapusPesanan(nomor);
                                cout << "       --------------------------------------------------------\n";
                                pesanan.tampilkanPesanan();
                    
                                cout << "\n       Apakah ada menu lain yang ingin dihapus? (Y/N)\n";
                                cout << "        ~ Pilihan Anda: ";
                                cin >> order;

                                if (order == 'y' | order == 'Y'){
                                    goto third;
                                } else if (order == 'n' | order == 'N'){
                                    system("cls");
                                    goto menu;
                                } system("cls"); 
                                thankYou();
                                Sleep(3000);
                                break;

                        case 3: system("cls");
                                banner();
                                cout << "\x1b[38;5;228m";
                                cout << "\n\n";
                                pesanan.tampilkanPesanan();
                                cout << "       Total Pembayaran Anda: Rp" << pesanan.hitungTotalHarga() << endl;
                                cout << "\n       Ketik 'Y' untuk kembali ke Menu Utama\n";
                                cout << "       Ketik 'B' untuk kembali ke Rincian Menu\n";
                                cout << "       ~ Pilihan Anda: ";
                                cin >> order;

                                if (order == 'y' | order == 'Y'){
                                    system("cls");
                                    goto awal;
                                } else if (order == 'b' | order == 'B'){
                                    system("cls");
                                    goto menu;
                                } system("cls"); 
                                thankYou();
                                Sleep(3000);
                                break;

                        case 4: system("cls");
                                cout << endl;
                                goto awal;
                                break;

                        default: error2:
                                cout << "\x1b[38;5;228m";
                                error();
                                cout << "\n       Ketik 'Y' untuk kembali ke Menu Utama\n";
                                cout << "       Ketik 'B' untuk kembali ke Rincian Menu\n";
                                cout << "       ~ Pilihan Anda: ";
                                cin >> order;

                                if (order == 'y' | order == 'Y'){
                                    system("cls");
                                    goto awal;
                                } else if (order == 'b' | order == 'B'){
                                    system("cls");
                                    goto menu;
                                } system("cls"); 
                                thankYou();
                                Sleep(3000);
                                break;
                        cout << "\x1B[0m";             
                    }

            case 2 : system("cls");
                    banner();
                    cout << "\x1b[38;5;228m";
                    cout << "\n       Banyak Antrian Saat Ini: " << antrian.size()<< endl;
                    cout << "\n";

                    option:
                    cout << "       Kembali ke Menu Utama? (Y/N)\n";
                    cout <<"       ~ Pilihan Anda: ";
                    cin >> order;

                    if (order == 'y' || order == 'Y'){
                        system("cls");
                        goto awal;
                    } else if (order == 'n' || order == 'N'){
                        cout << "\n       --------------------------------------------------------\n";
                        goto option;
                    } system("cls"); 
                    thankYou();
                    Sleep(3000);
                    break;

            case 3 : lagu:
                     system("cls");
                     banner();
                     lagu.playSong();

                    cout << "\x1b[38;5;228m";
                    cout << "\n\n";
                    cout << "        Kembali ke Menu Utama? (Y/N)\n";
                    cout << "      ~ Pilihan Anda: ";
                    cin >> order;
                    
                    if (order == 'y' || order == 'Y'){
                        system("cls");
                        goto awal;
                    } else if (order == 'n' || order == 'N'){
                        goto lagu;
                        break;
                    } system("cls"); 
                    thankYou();
                    Sleep(3000);
                    break;

            case 4 : system("cls");
                thankYou();
                Sleep(3000);
                exit(1);

            default: system("cls");
                    error();
                     
                    opti:
                    cout << "\x1b[38;5;228m";
                    cout << "\n";
                    cout << "      Kembali ke Menu Utama? (Y/N)\n";
                    cout <<"      ~ Pilihan Anda: ";
                    cin >> order;
                    cin >> order;
                    
                    if (order == 'y' || order == 'Y'){
                        system("cls");
                        goto awal;
                    } else if (order == 'n' || order == 'N'){
                        cout << "\n      --------------------------------------------------------\n";
                        goto opti;
                    } system("cls"); 
                    thankYou();
                    Sleep(3000);
                    break;
            cout << "\x1B[0m";
        }
    } while (order=='y' || order=='Y');
    system("cls"); 
    thankYou();
    Sleep(3000);
    return 0;    
}