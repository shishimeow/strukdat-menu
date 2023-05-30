#ifndef LAGU_H
#define LAGU_H

// void playSound();

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

struct Lagu {
    string judul;
    string artis;
    string path;
};

class QueueLagu {
private:
    struct Node {
        Lagu lagu;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    QueueLagu();
    bool isEmpty() const;
    void enqueue(const string& judul, const string& artis, const string& path);
    void dequeue();
    void playSong();
    void addSong();
    void beginSong();
};

#endif