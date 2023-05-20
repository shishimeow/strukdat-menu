#include <iostream>
#include <stdlib.h>
#include "antrian.h"

Queue::Queue() {
    front = NULL;
    rear = NULL;
}

void Queue::enqueue(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;
    if(front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void Queue::dequeue() {
    Node* temp = front;
    if(front == NULL) {
        return;
    }
    if(front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    delete temp;
}
        
int Queue::peek() {
    if(front == NULL) {
        return -1;
    }
    return front->data;
}
        
bool Queue::isEmpty() {
    return (front == NULL); 
}
        
int Queue::last() {
    if (rear == NULL) {
    return 0;  // antrian kosong
    }
    return rear->data;
}
        
int Queue::size() {
    int count = 0;
    Node* temp = front;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}