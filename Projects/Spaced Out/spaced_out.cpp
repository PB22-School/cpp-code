#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cout << "Number 1: ";
    cin >> a;
    cout << "Number 2: ";
    cin >> b;
    cout << "Number 3: ";
    cin >> c;

    int smallest = min(min(a,b),c);
    int greatest = max(max(a,b),c);
    int middle = (a+b+c)-(smallest+greatest);

    if(greatest-middle==middle-smallest) {
        cout << "Spaced Out" << endl;
    }
    else {
        cout << "NOT Spaced Out" << endl;
    }
}