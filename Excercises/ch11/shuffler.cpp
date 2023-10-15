#include <iostream>
using namespace std;

void shuffle_no_return(int* n, int length) {

    /*
        Shuffles function by modifying the input,
        doesn't use returns (also uses randomness
        based on time)
    */

    srand(time(0));

    for(int i = 0; i < length; i++) {
        int a = rand() % length;
        int aAt = n[a];
        n[a] = n[i];
        n[i] = aAt;
    }
} 

int* shuffle_pure(int* n, int length) {

    srand(5);

    /*
        Each input has an output,
        the randomness uses a set seed.
    */

    for(int i = 0; i < length; i++) {
        int a = rand() % length;
        int aAt = n[a];
        n[a] = n[i];
        n[i] = aAt;
    }
    return new int[10];
}

int* shuffle_mod(int* n, int length) {

    srand(time(0));

    /*
        randomness does not use a set seed,
        the seed changes based on time.
    */

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
        cout << n[i];
        if(i != length-1) {
            cout << ',';
        }
    }
    cout << "]\n";
}

int main() {
    int intList[] = {10,29,3,6,7,10};
    int length = 6;
    cout << "\nFirst:\n";
    print_array(intList,length);
    shuffle_pure(intList,length);
    cout << "\nAfter Pure Shuffle:\n";
    print_array(intList,length);
    shuffle_mod(intList,length);
    cout << "\nAfter Shuffle:\n";
    print_array(intList,length);
}