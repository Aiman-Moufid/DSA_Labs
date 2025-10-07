
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the end
    void displayAll()
    {
        Node* temp = head;
        cout << endl;
        while(temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    // Insert at the end
    void append(int val)
    {
        Node* newnode = new Node(val);
        if (head == nullptr)
        {
            head = newnode;
            newnode->prev = nullptr;
            newnode->next = nullptr;
        }
        else
        {
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = nullptr;
            
        }
        
    }

    // Insert at the front
    void prepend(int val)
    {
        Node* newnode = new Node(val);
        if (head == nullptr)
        {
            head = newnode;
            newnode->prev = nullptr;
            newnode->next = nullptr;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
            newnode->prev = nullptr;
        }
    }

    // Insert between first and last, at possition pos
    void insert(int val, int pos) {

    }

    // Remove from position pos
    void removeFromPos(int pos) {

    }

    // Find value val and remove it
    void removeValue(int pos) {

    }

    // Find and return the node with given value
    Node* search(int value) {

    }

    // Free all memory
    ~DoublyLinkedList() {

    }
};
