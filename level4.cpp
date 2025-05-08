#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*
*
int main() {
    vector<string> grid;
    string line;
    ifstream file("input4.txt");

    // Read and sanitize input
    while (getline(file, line)) {
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());
        if (!line.empty()) {
            grid.push_back(line);
        }
    }

    if (grid.empty()) {
        cout << 0 << endl;
        return 0;
    }

    // Validate grid dimensions
    size_t cols = grid[0].size();
    for (const auto& row : grid) {
        if (row.size() != cols) {
            cerr << "Error: Grid rows have inconsistent lengths." << endl;
            return 1;
        }
    }

    int count = 0;
    const vector<pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            for (const auto& [dx, dy] : directions) {
                int x_end = i + 3 * dx;
                int y_end = j + 3 * dy;
                if (x_end >= 0 && x_end < grid.size() && y_end >= 0 && y_end < grid[i].size()) {
                    char c0 = grid[i][j];
                    char c1 = grid[i + dx][j + dy];
                    char c2 = grid[i + 2 * dx][j + 2 * dy];
                    char c3 = grid[i + 3 * dx][j + 3 * dy];
                    if ((c0 == 'X' && c1 == 'M' && c2 == 'A' && c3 == 'S') ||
                        (c0 == 'S' && c1 == 'A' && c2 == 'M' && c3 == 'X')) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count/2 << endl; //answer 2545
    return 0;
}
*/

int main() {
    vector<string> grid;
    string line;
    ifstream file("input4.txt");

    // Read and sanitize input lines
    while (getline(file, line)) {
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());
        if (!line.empty()) {
            grid.push_back(line);
        }
    }

    if (grid.empty()) {
        cout << 0 << endl;
        return 0;
    }

    // Validate grid dimensions
    size_t cols = grid[0].size();
    for (const auto& row : grid) {
        if (row.size() != cols) {
            cerr << "Error: Inconsistent row lengths." << endl;
            return 1;
        }
    }

    int count = 0;
    int rows = grid.size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] != 'A') {
                continue;
            }

            // Check diagonal 1 (top-left to bottom-right)
            bool diag1_valid = false;
            if (i-1 >= 0 && j-1 >= 0 && i+1 < rows && j+1 < cols) {
                string diag;
                diag += grid[i-1][j-1];
                diag += grid[i][j];
                diag += grid[i+1][j+1];
                if (diag == "MAS" || diag == "SAM") {
                    diag1_valid = true;
                }
            }

            // Check diagonal 2 (top-right to bottom-left)
            bool diag2_valid = false;
            if (i-1 >= 0 && j+1 < cols && i+1 < rows && j-1 >= 0) {
                string diag;
                diag += grid[i-1][j+1];
                diag += grid[i][j];
                diag += grid[i+1][j-1];
                if (diag == "MAS" || diag == "SAM") {
                    diag2_valid = true;
                }
            }

            if (diag1_valid && diag2_valid) {
                count++;
            }
        }
    }

    cout << count << endl; //asnwer: 1886

    return 0;
}