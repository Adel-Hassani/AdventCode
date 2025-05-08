#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;
/*
*
int main() {
    ifstream file("input3.txt");
    string line;
    long long total = 0;

    while (getline(file, line)) {
        int n = line.size();
        for (int i = 0; i < n; ) {
            if (i + 3 < n && line[i] == 'm' && line[i+1] == 'u' && line[i+2] == 'l' && line[i+3] == '(') {
                int j = i + 4;
                int x = 0, y = 0;
                int digits = 0;
                bool valid = true;

                // Parse first number
                while (j < n && isdigit(line[j]) && digits < 3) {
                    x = x * 10 + (line[j] - '0');
                    j++;
                    digits++;
                }
                if (digits == 0 || j >= n || line[j] != ',') {
                    i++;
                    continue;
                }
                j++;
                digits = 0;

                // Parse second number
                while (j < n && isdigit(line[j]) && digits < 3) {
                    y = y * 10 + (line[j] - '0');
                    j++;
                    digits++;
                }
                if (digits == 0 || j >= n || line[j] != ')') {
                    i++;
                    continue;
                }

                // Valid instruction found
                total += x * y;
                i = j + 1; // Move past the closing ')'
            } else {
                i++;
            }
        }
    }

    cout << total << endl; //answer: 163931492

    return 0;
}
*/

int main() {
    ifstream file("input3.txt");
    string line;
    long long total = 0;
    bool enabled = true;

    while (getline(file, line)) {
        int n = line.size();
        int i = 0;
        while (i < n) {
            // Check for do()
            if (i + 3 < n && line[i] == 'd' && line[i+1] == 'o' && line[i+2] == '(' && line[i+3] == ')') {
                enabled = true;
                i += 4;
                continue;
            }
            // Check for don't()
            else if (i + 6 < n && line[i] == 'd' && line[i+1] == 'o' && line[i+2] == 'n' && line[i+3] == '\'' && line[i+4] == 't' && line[i+5] == '(' && line[i+6] == ')') {
                enabled = false;
                i += 7;
                continue;
            }
            // Check for mul(
            else if (i + 3 < n && line[i] == 'm' && line[i+1] == 'u' && line[i+2] == 'l' && line[i+3] == '(') {
                int j = i + 4;
                int x = 0, y = 0;
                int digits = 0;
                bool valid = true;

                // Parse X
                digits = 0;
                while (j < n && isdigit(line[j]) && digits < 3) {
                    x = x * 10 + (line[j] - '0');
                    j++;
                    digits++;
                }
                if (digits == 0 || j >= n || line[j] != ',') {
                    i += 4;
                    continue;
                }
                j++;
                digits = 0;

                // Parse Y
                while (j < n && isdigit(line[j]) && digits < 3) {
                    y = y * 10 + (line[j] - '0');
                    j++;
                    digits++;
                }
                if (digits == 0 || j >= n || line[j] != ')') {
                    i += 4;
                    continue;
                }

                // Add to total if enabled
                if (enabled) {
                    total += x * y;
                }
                i = j + 1; // Move past ')'
            } else {
                i++;
            }
        }
    }

    cout << total << endl; // answer: 76911921

    return 0;
}