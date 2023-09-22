#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string string_to_upper(string input) {
    string output = "";
    for(int i = 0; i < input.length(); i++) {
        output += toupper(input[i]);
    }
    return output;
}

string string_to_lower(string input) {
    string output = "";
    for(int i = 0; i < input.length(); i++) {
        output += tolower(input[i]);
    }
    return output;
}

int main() {
    cout << string_to_lower("HellO WOrLd!") << endl;
}