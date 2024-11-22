#include<iostream>
#include<array>
#include <cstring>

class DynamicArray {
    
private:
    int* arr;
    int s;
    int c;

public:

    DynamicArray(int capacity) {
        s = 0; // init size to 0 
        c = capacity; // init capacity
        arr = new int[capacity]; // init array
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        if (c > i) // capacity is greater than index being accessed
        {
            arr[i] = n;
        }
    }

    void pushback(int n) {
        if (s == c) // array is full
        {
            resize();
        }
        arr[s++] = n;
    }

    int popback() {
        if (s > 0) // check if array is empty
        {
            int n = arr[s-1]; 
            s--;
            return n;
        }
    }

    void resize() {
        c *= 2; // double capacity
        int* arr_ = new int[c]; // init new array
        memcpy(arr_, arr, s * sizeof(int)); // copy over old array
        delete [] arr;
        arr = arr_;
    }

    int getSize() {
        return s;
    }

    int getCapacity() {
        return c;
    }
};