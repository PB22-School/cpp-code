#include <iostream>
using namespace std;

void print_multiples(int n, int upper)
{
    int i = 1;
    while (i <= upper) {
        cout << n * i << "\t";
        i = i + 1;
    }
    cout << endl;
}

void print_mult_table(int high)
{
    int i = 1;
    while (i <= high) {
        print_multiples(i, high);
        i = i + 1;
    }
}

int main() {
    print_mult_table(5);
    //The code works as expected
}