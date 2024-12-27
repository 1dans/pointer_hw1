#include <iostream>
using namespace std;


void fillArray(int* ptr, int size) {
    for (int i = 0; i < size; ++i) {
        *(ptr+i) = 1 + rand() % 10;
    }
}
/* void copyArray(int *ptr, int*p, int size) { // #1
    for (int i = 0; i < size; ++i) {
        *(p + i) = *(ptr + i);
    }
}*/

/* void reverseArray(int* ptr, int size) { // #2
    for (int i = size-1; i >= 0; --i) {
        cout << *(ptr + i) << ' ';
    }
}*/

void reverseCopyArray(int* ptr, int*p, int size) { // #3 
    int reverse_i = size-1;
    for (int i = 0; i < size; ++i) {
        *(p+i) = *(ptr + reverse_i);
        --reverse_i;
    }
}
void displayArray(int* ptr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(ptr+i) << ' ';
    }
}

void del(int* ptr) {
    delete[] ptr;
}
 
int main()
{
    srand(time(nullptr));

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int* ptr = new int[size];
    int* p = new int[size]; // #1 & #3
    fillArray(ptr, size);
    displayArray(ptr, size);
    cout << endl;
    reverseCopyArray(ptr, p, size);
    // reverseArray(ptr, size); #2
    //copyArray(ptr, p, size); #1
    
    displayArray(p, size); // #1 & #3
    del(ptr);
    del(p); // #1 & #3

    //#2
}
