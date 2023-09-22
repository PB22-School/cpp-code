#include <iostream>
#include <string>
using namespace std;

void count_letters(string str1, char char1) {
    int count = 0; 
    int index = 0;
    while (index < str1.length()) {
        if(str1[index]==char1) {
            count+=1;
        }
        index+=1;
    }
    cout << count << endl;
}

int main() {
    count_letters("Hello World!",'l');
}