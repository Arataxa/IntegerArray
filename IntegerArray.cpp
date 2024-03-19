#include "IntegerArray.h"
#include <algorithm>

IntegerArray::IntegerArray(size_t size) : size(size), data(new int[size]) {}

IntegerArray::IntegerArray(const IntegerArray& other) : size(other.size), data(new int[other.size]) {
    std::copy(other.data, other.data + other.size, data);
}

IntegerArray::~IntegerArray() {
    delete[] data;
}

int& IntegerArray::operator[](size_t index) {
    if (index >= size) throw bad_range();
    return data[index];
}

void IntegerArray::Resize(size_t newSize) {
    if (newSize < 0) throw bad_length();
    int* newData = new int[newSize];
    std::copy(data, data + std::min(size, newSize), newData);
    delete[] data;
    data = newData;
    size = newSize;
}

void IntegerArray::InsertAt(size_t index, int value) {
    if (index > size) throw bad_range(); 
    Resize(size + 1);
    std::move_backward(data + index, data + size - 1, data + size);
    data[index] = value;
}

void IntegerArray::RemoveAt(size_t index) {
    if (index >= size) throw bad_range();
    std::move(data + index + 1, data + size, data + index);
    Resize(size - 1);
}

size_t IntegerArray::GetSize() const {
    return size;
}

void IntegerArray::InsertAtBeginning(int value) {
    InsertAt(0, value);
}

void IntegerArray::InsertAtEnd(int value) {
    InsertAt(size, value); 
}

int IntegerArray::Find(int value) const {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == value) return static_cast<int>(i);
    }
    return -1;
}
