#include <iostream>
#include <string>
using namespace std;

string backward_string(string str1) {
    string outString = "";
    for(int i = 0; i < str1.length()+1; i++) {
        outString+=str1[str1.length()-i];
    }
    return outString;
}   

int main() {
    cout << backward_string("Backwards Text") << endl;
}