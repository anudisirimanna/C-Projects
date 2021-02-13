#include "doubly-linked-list.h"
#include <iostream>
#include <new>
using namespace std;

DoublyLinkedList::Node::Node(DataType data):
        value(data), next(NULL), prev(NULL)
{

}
DoublyLinkedList::DoublyLinkedList()
        :head_(NULL), tail_(NULL), size_(0)
{

}
/*DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& list)
:size_(list.size_)
{

}*/
DoublyLinkedList::~DoublyLinkedList()
{
    Node* temp = NULL;
    while (head_ != NULL) {
        temp = head_;
        head_ = head_->next;
        delete temp;
    }
    head_ = NULL;
}
bool DoublyLinkedList::empty() const {
    if (size_ == 0) return true;
    else return false;
}
unsigned int DoublyLinkedList::size() const
{
    return size_;
}
void DoublyLinkedList::print() const
{
    Node* temp = head_;
    while (temp != NULL) {
        cout << temp->value << endl;
        temp = temp->next;
    }
}
bool DoublyLinkedList::insert_front(DataType value)
{
    if (size_ == CAPACITY) return false;

    Node* newNode = new Node(value);
    if (size_ == 0) {
        head_ = newNode;
        tail_ = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
        size_++;
        return true;
    }

    Node* oldHead = head_;
    newNode->next = oldHead;
    head_ = newNode;
    newNode->next->prev = newNode;
    size_++;
    return true;
}
bool DoublyLinkedList::remove_front()
{
    if(size_ == 0) return false;

    if(size_ == 1) {
        Node* temp = head_;
        delete temp;
        head_ = NULL;
        tail_ = NULL;
        size_--;
        return true;
    }

    Node* oldHead = head_;
    Node* temp = oldHead->next;
    temp->prev = NULL;
    delete oldHead;
    head_ = temp;
    size_--;
    return true;
}
bool DoublyLinkedList::insert_back(DataType value)
{
    if (size_ == CAPACITY) return false;

    Node* newNode = new Node(value);
    if (size_ == 0) {
        head_ = newNode;
        tail_ = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
        size_++;
        return true;
    }

    Node* oldTail = tail_;
    oldTail->next = newNode;
    newNode->prev = oldTail;
    newNode->next = NULL;
    tail_ = newNode;
    size_++;
    return true;
}

bool DoublyLinkedList::remove_back()
{
    if (size_ == 0) return false;

    if (size_ == 1) {
        Node* temp = head_;
        delete temp;
        head_ = NULL;
        tail_ = NULL;
        size_--;
        return true;
    }

    Node* oldTail = tail_;
    Node* temp = oldTail->prev;
    temp->next = NULL;
    delete oldTail;
    tail_ = temp;
    size_--;
    return true;
}
bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    if (size_ == CAPACITY) return false;
    if (index < 0 || index > size_) return false;

    if (index == 0) return insert_front(value);
    if (index == size_) return insert_back(value);

    Node* newNode = new Node(value);
    Node* prev = getNode(index-1);
    Node* next = getNode(index);
    prev->next = newNode;
    newNode->prev = prev;
    newNode->next = next;
    next->prev = newNode;
    size_++;
    return true;
}
bool DoublyLinkedList::remove(unsigned int index)
{
    if (index >= size_) return false;
    if (head_==NULL && head_->next==NULL) return false;

    if (index == 0) return remove_front();
    if (index == size_-1) return remove_back();

    Node* remove = new Node(index);
    Node* prev = getNode(index-1);
    Node* next = getNode(index+1);
    prev->next = next;
    next->prev = prev;
    remove->next = NULL;
    remove->prev = NULL;
    delete remove;
    size_--;
    return true;
}
unsigned int DoublyLinkedList::search(DataType value) const
{
    Node* temp = head_;
    for (int i = 0; i < size_; i++) {
        if (temp->value == value) return i;
        temp = temp->next;
    }
    return size_;
}
DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    if (index < 0 || index >= size_) return tail_->value;
    Node* temp = getNode(index);
    return temp->value;
}
bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    if (index < 0 || index >= size_) return false;
    if (size_ == 0) return false;
    Node* temp = getNode(index);
    temp->value = value;
    return true;
}
DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    Node* temp = head_;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}
bool DoublyLinkedList::full() const
{
    if (size_ == CAPACITY) return true;
    else return false;
}
