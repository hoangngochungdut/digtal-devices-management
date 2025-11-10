#ifndef LINKLIST_H
#define LINKLIST_H

template <typename T>
class Node{
public:
    T data;
    Node* next;
    
    Node(T value): data(value), next(nullptr) {} 
};

template <typename T>
class LinkList{
private:
    Node<T>* head;
public: 
    Node<T>* getHead() const {return head;}
    void clear() {
        Node<T>* curr = getHead();
        while (curr) {
        Node<T>* temp = curr;
        curr = curr->next;
        delete temp; 
        }
        head = nullptr;
    }

    LinkList() : head(nullptr) {}
    ~LinkList() {clear();}
    
    bool isEmpty() {return head == nullptr;}

    void add(T item) {
        Node<T>* newNode = new Node<T>(item);
        if (!getHead()) {
        head = newNode; 
        return;
        } 
        Node<T>* temp = getHead();
        while(temp->next) temp = temp->next;
        temp->next = newNode;    
    }

    void display() {
        int count = 0;
        Node<T>* curr = getHead();
        while(curr) {
            cout << ++count << ". ";
            (curr->data).show();
            curr = curr->next;
        }
    }

};
#endif