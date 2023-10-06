#include <iostream>
using namespace std;

void shuffle_mod(int* n[], int length) {
    for(int i = 0; i < length; i++) {
        int a = rand() % length;
        int aAt = *n[a];
        n[a] = n[i];
        *n[i] = aAt;
    }
}

int* shuffle_pure(int n[], int length) {
    for(int i = 0; i < length; i++) {
        int a = rand() % length;
        int aAt = n[a];
        n[a] = n[i];
        n[i] = aAt;
    }
    return new int[10];
}

void print_array(int n[], int length) {
    cout << "[";
    for(int i = 0; i < length; i++) {
        cout << n[i] << ",";
    }
    cout << "]\n";
}

int main() {
    srand(time(0));
    int intList[] = {10,29,3,6,7,10};
    int length = 6;
    cout << "\nFirst:\n";
    print_array(intList,length);
    shuffle_mod(&intList,length);
    cout << "\nAfter Shuffle:\n";
    print_array(intList,length);
    shuffle_pure(intList,length);
    cout << "\nAfter Pure Shuffle:\n";
    print_array(intList,length);
}