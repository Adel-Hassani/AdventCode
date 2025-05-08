#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
/*
*int main() {
    ifstream file("input2.txt");
    string line;
    int safe_count = 0;

    while (getline(file, line)) {
        vector<int> numbers;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            numbers.push_back(num);
        }

        if (numbers.size() < 2) {
            continue; // Reports must have at least two levels
        }

        bool is_safe = true;
        int direction = 0; // 1 for increasing, -1 for decreasing

        for (size_t i = 1; i < numbers.size(); ++i) {
            int prev = numbers[i-1];
            int curr = numbers[i];
            int diff = curr - prev;

            if (diff == 0) {
                is_safe = false;
                break;
            }

            int abs_diff = abs(diff);
            if (abs_diff < 1 || abs_diff > 3) {
                is_safe = false;
                break;
            }

            if (i == 1) {
                direction = (diff > 0) ? 1 : -1;
            } else {
                if ((diff > 0 && direction != 1) || (diff < 0 && direction != -1)) {
                    is_safe = false;
                    break;
                }
            }
        }

        if (is_safe) {
            ++safe_count;
        }
    }

    cout << safe_count << endl; //answer: 549

    return 0;
}
*/

bool is_safe(const vector<int>& nums) {
    if (nums.size() < 2) {
        return false; // A report must have at least two levels to be considered
    }

    int direction = 0; // 0: undetermined, 1: increasing, -1: decreasing
    for (size_t i = 1; i < nums.size(); ++i) {
        int prev = nums[i-1];
        int curr = nums[i];
        int diff = curr - prev;

        if (diff == 0) {
            return false; // Adjacent levels cannot be the same
        }

        int abs_diff = abs(diff);
        if (abs_diff < 1 || abs_diff > 3) {
            return false; // Difference out of allowed range
        }

        if (direction == 0) {
            direction = (diff > 0) ? 1 : -1;
        } else {
            if ((diff > 0 && direction != 1) || (diff < 0 && direction != -1)) {
                return false; // Direction change detected
            }
        }
    }

    return true;
}

int main() {
    ifstream file("input2.txt");
    string line;
    int safe_count = 0;

    while (getline(file, line)) {
        vector<int> original;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            original.push_back(num);
        }

        bool safe = false;

        // Check if the original report is safe
        if (is_safe(original)) {
            safe = true;
        } else {
            // Check all possible single removals
            for (size_t i = 0; i < original.size(); ++i) {
                vector<int> modified;
                for (size_t j = 0; j < original.size(); ++j) {
                    if (j != i) {
                        modified.push_back(original[j]);
                    }
                }
                if (modified.size() >= 2 && is_safe(modified)) {
                    safe = true;
                    break;
                }
            }
        }

        if (safe) {
            safe_count++;
        }
    }

    cout << safe_count << endl; //answer: 589

    return 0;
}