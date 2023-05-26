#include <iostream>
#include <string>
#include <Windows.h>
#include "lagu.h"

using namespace std;

    QueueLagu::QueueLagu() : front(nullptr), rear(nullptr) {
        addSong();
    }

    bool QueueLagu::isEmpty() const {
        return front == nullptr;
    }

    void QueueLagu::enqueue(const string& judul, const string& artis, const string& path) {
        Lagu lagu;
        lagu.judul = judul;
        lagu.artis = artis;
        lagu.path = path;

        Node* newNode = new Node;
        newNode->lagu = lagu;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void QueueLagu::dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong. Tidak ada lagu yang bisa dihapus." << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void QueueLagu::playSong() {
    if (isEmpty()) {
        cout << "Antrian kosong. Tidak ada lagu yang bisa diputar." << endl;
    } else {
        int choice;
        cout << "\x1b[38;5;228m";
        cout << "\n";
        cout << "      |" << endl;
        cout << "      | Daftar Lagu:\n";

        int index = 1;
        Node* current = front;
        while (current != nullptr) {
            cout << "      | " << index << ". " << current->lagu.judul << " - " << current->lagu.artis << endl;
            current = current->next;
            index++;
        }
        cout << "      //-----------------------------------------------------------------------------------------------------------------------\\\\";
        cout << "\n";
        cout << "      | Pilih lagu yang ingin diputar (masukkan nomor): ";
        cin >> choice;

        if (choice >= 1 && choice <= index) {
            current = front;
            for (int i = 1; i < choice; i++) {
                current = current->next;
            }
            Lagu lagu = current->lagu;
            string file = lagu.path;

            wstring wideFileName(file.begin(), file.end());

            PlaySoundW(wideFileName.c_str(), NULL, SND_FILENAME | SND_ASYNC);

            cout << "      | Memutar lagu: " << lagu.judul << " - " << lagu.artis << endl;
            cout << "      //-----------------------------------------------------------------------------------------------------------------------\\\\";
        } else {
            cout << "      | Pilihan lagu tidak valid." << endl;
        }
        cout << "\x1B[0m";
    }
    }

    void QueueLagu::beginSong(){
            string file = "lagu1.wav";

            wstring wideFileName(file.begin(), file.end());

            PlaySoundW(wideFileName.c_str(), NULL, SND_FILENAME | SND_ASYNC);
    }



    void QueueLagu::addSong(){
        enqueue("Testing", "Gaada", "lagu1.wav");
        enqueue("Weebs", "Siapa hayo", "blends.wav");
    }
