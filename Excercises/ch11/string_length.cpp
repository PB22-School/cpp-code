#include <iostream>
using namespace std;

int str_len(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int main() {
    char str[] = {'a','b','c','d','\0'};
    cout << str_len(str) << endl;
}