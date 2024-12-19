#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() {
    count=0;
    head=nullptr;  
    tail=nullptr;
}

int LinkedList::size() {
    return count;
}

void LinkedList::pop() {
    if (count == 0) {
        return;
    }
    Node* temp = head; 
    head = head->next;
    delete temp; 
    count--; 
    if (count == 0) {
        tail = nullptr;
    }
}

void LinkedList::push(int value) {
    Node* newNode = new Node(value);
    if(count==0 || head->data >= value) {
        newNode->next = head;
        head = newNode; 
    }
    else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    if(newNode->next == nullptr) {
        tail = newNode;
    }
    count++;
}

void LinkedList::print(){ 
    Node* current = head;
    while (current != 0) {
        cout << current->data <<" ";
        current = current->next;
    }
    cout<<endl;
}
//