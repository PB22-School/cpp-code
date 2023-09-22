#include <iostream>
#include <string>
using namespace std;

void printNames(string suffix,char letter, char endLetter) {
    while(letter < endLetter+1) {
        if(letter == 'Q' or letter == 'O') {
            cout << letter << 'u' << suffix <<  endl;
        }
        else {
            cout << letter + suffix << endl;
        }
        letter++;
    }
}

int main() {
    printNames("ack",'J','Q');
}