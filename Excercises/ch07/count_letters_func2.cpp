#include <iostream>
#include <string>
using namespace std;

void count_letters(string str1, char char1) {
    int count = 0;
    int index = 0;
    while(str1.find(char1,index)!=-1) {
        index = str1.find(char1,index)+1;
        count += 1;
    }
    cout << count << endl;
}

int main() {
    count_letters("Hello World",'d');
}