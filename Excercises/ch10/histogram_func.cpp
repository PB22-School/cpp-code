#include <iostream>
#include <vector>
using namespace std;

vector<int> random_vector(int n, int upper_bound) {
    vector<int> vec(n);
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = rand() % upper_bound;
    }
    return vec;
}

vector<int> histogram(vector<int> vect, int high) {
    vector<int> histogramm(high);

    for(int i = 0; i < high; i++) {
        histogramm[vect[i]]++;
    }
    return histogramm;
}

int main() {
    vector<int> vect = histogram(random_vector(10,10),10);
    string c = "";
    for(int i = 0; i < vect.size(); i++) {
        cout << endl << "There are" << vect[i] << " " << i << "'s in the histogram\n"; 
    }
    cout << endl;
}