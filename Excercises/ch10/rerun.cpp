#include <iostream>
#include <vector>
using namespace std;

vector<int> random_vector(int n, int upper_bound)
{
    vector<int> vec(n);

    for (int i = 0; i < vec.size(); i++) {
        vec[i] = rand() % upper_bound;
    }

    return vec;
}

int how_many(const vector<int>& vec, int value)
{
    int count = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == value) count++;
    }
    return count;
}

int main() {
    int num_values = 50; //changing this variable changes the number of values in the vector.
    int upper_bound = 10;
    vector<int> vector = random_vector(num_values, upper_bound);
    cout << "value\thow_many" << endl;
    for (int i = 0; i < upper_bound; i++) {
        cout << i << '\t' << how_many(vector, i) << endl;
    }
}