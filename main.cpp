//
//  main.cpp
//  DSA_3
//
//  Created by Aiman Moufid on 10/7/25.
//

#include <iostream>
#include <fstream>
using namespace std;

class Node {
public:
    string name;
    string place;
    int time;
    
    Node* next;
    Node(string n, string p, int t)
    {
        name = n;
        place = p;
        time = t;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    Node* iterate(int position) {
        if (position < 0) return nullptr;
        Node* current = head;
        int index = 0;
        while (current != nullptr && index < position) {
            current = current->next;
            index++;
        }
        return current; // nullptr if not found
    }
    // Insert at position
    void insertAt(int position, string name, string place, int time) {
        Node* newNode = new Node(name, place, time);
        if (position <= 0 || head == nullptr) { // Insert at beginning
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* prev = iterate(position - 1);
        if (prev == nullptr) { // Position too big, append at end
            append(name, place, time);
            delete newNode; // already appended, avoid memory leak
            return;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
    // Prepend (beginning)
    void prepend(string name, string place, int time) {
        insertAt(0, name, place, time);
    }
    // Append (end)
    void append(string name, string place, int time) {
        if (head == nullptr) {
            head = new Node( name,  place,  time);
            return;
        }
        Node* last = iterate(size() - 1);
        last->next = new Node(name,place,time);
    }
    // Find node by value
    Node* find(string findname) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->name == findname)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
    // Contains (true/false)
    bool contains(string value) {
        return find(value) != nullptr;
    }
    // Remove by value
    bool remove(int value) {                //unused
        if (head == nullptr) return false;
        // Special case: head
        if (head->time == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        // Find previous node of the target
        int index = 0;
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->time == value) {
                Node* target = current->next;
                current->next = target->next;
                delete target;
                return true;
            }
            current = current->next;
            index++;
        }
        return false; // Not found
    }
    // Remove from position
    bool removeAtPos(int value) {
        if(head == nullptr) return false;
        else
        {
            if(value==0)
            {
                Node* temp = head;
                cout << "Now answering: " << temp->name << endl <<"Status Was: " << temp->place << endl << endl;
                head = head->next;
                delete temp;
                return true;
            }
            else
            {
                
                Node* beans = iterate(value-1);
                if(beans != nullptr && beans->next != nullptr)
                {
                    
                    cout << "Now answering: " << beans->next->name << endl <<"Status Was: " << beans->next->place << endl << endl;
                    Node* target = beans->next;
                    beans->next = target->next;
                    delete target;
                    return true;
                }
                return false;
            }
        }
        
    }
    // Remove from position
    bool removeFirst() {
        return removeAtPos(0);
    }
    // Remove from position
    bool removeLast() {
        return removeAtPos(size()-1);
    }
    // Get size
    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    // Display
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name  << "  " << temp-> place << "  " << temp->time << endl;
            temp = temp->next;
        }
    }
};

class queues{
private:
    LinkedList list;
public:
    void enqueue(string n, string p, int t)
    {
        list.append(n, p, t);
    };
    void dequeue()
    {
        list.removeFirst();
    };
    Node* peek()
    {
        Node* Beans = list.iterate(0);
        return Beans;
    }
    void showall()
    {
        list.display();
    }
    int size()
    {
        return list.size();
    }
};

class stacks{
private:
    LinkedList list;
public:
    void push(string n, string p, int t)
    {
        list.append(n, p, t);
    };
    void pop()
    {
        list.removeLast();
    };
    Node* peek()
    {
        Node* Beans = list.iterate(list.size()-1);
        return Beans;
    }
    void showall()
    {
        list.display();
    }
    int size()
    {
        return list.size();
    }
};
    
    



int main()
{
    stacks stacklist;
    queues queuelist;
    ifstream file;
    file.open("Untitled.txt");
    if (!file)
    {
        cout <<"failed to open" << endl;
        return 1;
    }
    else
    {
        string n;
        string p;
        int t;
        while(file>>n>>p>>t)
        {
            if (p == "waiting")
            {
                queuelist.enqueue(n, p, t);
            }
            else
            {
                stacklist.push(n, p, t);
            }
        }
    }
    queuelist.showall();
    cout << endl;
    stacklist.showall();
    cout << endl;
    int totaltime=0;
    while(queuelist.size()>0 && stacklist.size()>0)
    {
        for(int i=0; i<3;i++)
        {
           
            if (queuelist.size()==0)
            {
               
                break;
            }
            else
            {
                cout <<"Current Time: " << totaltime << endl;
                Node* temp = queuelist.peek();
                totaltime+=temp->time;
                queuelist.dequeue();
            }
        }
        cout << "Current Time: " << totaltime << endl;
        Node* temp = stacklist.peek();
        totaltime+=temp->time;
        stacklist.pop();
    }
}
