#include <iostream>
using namespace std;

void loop_forever(int n) {
    while (true) {
        cout << "n is now " << n << "." << endl;
        n = n + 1;
    }
}

void recurse_forever(int n) {
    cout << "n is now " << n << "." << endl;
    recurse_forever(n + 1);
}

int main() {
    loop_forever(1);
    //doesn't ever reach the next lines of code
    recurse_forever(1);
    //also doesn't ever reach the next lines of code
    cout << "This code is never ran." << endl;
    /*
    I'm pretty sure the call stack is all of the memory allocated to the code,
    and if you run out of memory pointers then you get a stack overflow error.
    It relates to these functions because these functions never stop running,
    however they do keep using memory, the larger a number gets the more bits
    it takes to store, and the recursive function probably does this faster
    because instead of making just one variable that is constantly being added
    too, it makes "infinite", which are all being added too constantly.
    */
}