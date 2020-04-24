#include <stdlib.h>
#include <iostream>
#include <string>
#include <array>

template <typename T>
class Vector {

    template<typename Value>
    friend std::ostream& operator << (std::ostream& os, Vector<Value>& vec);
    
    public:
        Vector(): ptr(new T[10]), logicalSize(0), allocatedSize(10) {}
        ~Vector() { delete[] ptr; }

        size_t size() { return logicalSize; }
        bool isEmpty() { return size() == 0; }

        T* begin() {
            return ptr;
        }
        T* end() const {
            return &(ptr[logicalSize]);
        }
        void push(T& item) {
            if (logicalSize == allocatedSize) grow();
            ptr[logicalSize++] = item;
        }
        void pop() {
            if (isEmpty()) {
                std::cout << "Nothing to pop!" << std::endl;
                return;
            }
            logicalSize--;
        }
        T& operator [] (int index) {
            if (index >= logicalSize) {
                throw "Index Out of Bounds!";
            }
            return ptr[index];
        }

    private:
        T* ptr; 
        size_t logicalSize;
        size_t allocatedSize; 

        void grow() {
            T* new_array = new T[(allocatedSize *= 2)];
            /* Copy everything over */
            for (size_t i = 0; i < logicalSize; i++) {
                new_array[i] = ptr[i];
            }
            delete[] ptr;
            ptr = new_array;
        }
};

/* Operator Overloading Down Here */
template <typename Value>
std::ostream& operator << (std::ostream& os, Vector<Value>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        os << vec.ptr[i];
    }
    return os;
}













