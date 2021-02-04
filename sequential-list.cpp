#include "sequential-list.h"
#include <iostream>
using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
    data_= new DataType(cap); //creates sequential list
    capacity_ = cap; //total possible # of elements in list
    size_ = 0; //initially no elements in list
}

SequentialList::~SequentialList()
{
    delete data_; //delete list
}

unsigned int SequentialList::size() const
{
    return size_; //current # of elements in list
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    if (size_ == 0) return true; //empty list has no elements
    else return false;
}

bool SequentialList::full() const
{
    if(size_ == capacity_) return true; //full list has total possible # of elements
    else return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if(index < 0||index >= size_) return data_[size_-1]; //if index invalid return last element
    else return data_[index];
}

unsigned int SequentialList::search(DataType val) const
{
    for (int i = 0; i < size_; i++) { //increments entire list
        if (data_[i] == val) return i; //if element found return index
    }
    return size_; //if element not found return total # of elements in list
}

void SequentialList::print() const
{
    for ( int i = 0; i < size_ ; i++) {
        cout << data_[i]; //prints each element in list
    }
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if (index > size_ || size_ == capacity_) return false; //return if invalid index or list is full

    if (index == 0) return insert_front(val); //function to insert index at front
    else if (index == size_) return insert_back(val); //function to insert index at back

    for (int i = size_-1; i >=index ; i--) { //increment backwards from back to index
        data_[i+1] = data_[i]; //move each element backwards by one
    }

    data_[index] = val; //insert new value at index
    size_++; //increase total # of elements
    return true;
}

bool SequentialList::insert_front(DataType val)
{
    if (size_ == capacity_) return false;

    for(int i = size_-1; i >= 0 ; i--) { //increment backwards from back to front
        data_[i+1] = data_[i];
    }

    data_[0] = val; //insert new value at front
    size_++;
    return true;
}

bool SequentialList::insert_back(DataType val)
{
    if (size_ == capacity_) return false;
    data_[size_] = val; //insert new value at end
    size_++;
    return true;
}

bool SequentialList::remove(unsigned int index)
{
    if (index < 0 || index > size_-1 || size_ == 0) return false; //return if invalid index or empty list

    if (index == 0) return remove_front(); //function to remove function at front
    else if (index == size_-1) return remove_back(); //function to remove function at back

    for (int i = index; i < size_-1; i++) { //increment forwards from front to index
        data_[i] = data_[i+1]; //move each element forwards by one
    }

    data_[size_-1] = NULL; //remove value at end
    size_--; //decrease total # of elements
    return true;
}

bool SequentialList::remove_front()
{
    if (size_ == 0) return false;

    for (int i = 0; i < size_-1; i++) { //increment forwards from front to back
        data_[i] = data_[i+1];
    }

    data_[size_-1] = NULL;
    size_--;
    return true;
}

bool SequentialList::remove_back()
{
    if (size_ == 0) return false;
    data_[size_-1] = NULL;
    size_--;
    return true;
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if (index < 0||index >= size_) return false; //return if invalid index
    data_[index] = val; //replace current element at index with new element
    return true;
}

