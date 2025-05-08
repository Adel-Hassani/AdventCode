#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <unordered_map>

using namespace std;
// uncomment the following code to test the first approach
/*
*
int main() {
    vector<int> left, right;
    ifstream file("input.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        int a, b;
        ss >> a >> b;
        left.push_back(a);
        right.push_back(b);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    long long total = 0;
    for (size_t i = 0; i < left.size(); ++i) {
        total += abs(left[i] - right[i]);
    }

    cout << total << endl;

    return 0; //answer: 1590491
}
*/

int main() {
    vector<int> left, right;
    ifstream file("input.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        int a, b;
        ss >> a >> b;
        left.push_back(a);
        right.push_back(b);
    }

    unordered_map<int, int> right_counts;
    for (int num : right) {
        right_counts[num]++;
    }

    long long total = 0;
    for (int num : left) {
        total += num * right_counts[num];
    }

    cout << total << endl; //answer: 22588371

    return 0;
}