#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> strVec(10);
    for(int i = 0; i < 10; i++) {
        cout << "Insert Number : ";
        cin >> strVec[i];
    }
    int biggest = 0;
    for(int i = 0; i < 10; i++) {
        if(strVec[i] > biggest) {
            biggest = strVec[i];
        }
    }
    cout << &biggest << endl;
}