#include <iostream>
using namespace std;

bool isWorkingAge(int age) {
    return age > 16 && age < 65;
}

int main() {
    for(int i = 2; i < 12; i++) {
        cout << "Is " << i*6 << " a working age?\t" << isWorkingAge(i*6) << endl;
    }
    return 0;
}