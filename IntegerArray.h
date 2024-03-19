#include <exception>
#include <iostream>

class bad_range : public std::exception {
public:
    const char* what() const noexcept override {
        return "Index out of bounds";
    }
};

class bad_length : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid array length";
    }
};

class IntegerArray {
private:
    int* data;
    size_t size;
public:
    IntegerArray(size_t size); 
    IntegerArray(const IntegerArray& other);
    ~IntegerArray(); 


    int& operator[](size_t index); 
    void Resize(size_t newSize); 
    void InsertAt(size_t index, int value);
    void RemoveAt(size_t index);
    size_t GetSize() const;

    void InsertAtBeginning(int value);
    void InsertAtEnd(int value);
    int Find(int value) const;
};
