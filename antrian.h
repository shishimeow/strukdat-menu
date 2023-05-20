#ifndef ANTRIAN_H
#define ANTRIAN_H

#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    private:
        Node* front;
        Node* rear;
    public:
        Queue();
        void enqueue(int x);
        void dequeue();
        int peek();
        bool isEmpty();
        int last();
        int size();
};


#endif