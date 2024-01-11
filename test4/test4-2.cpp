#include <iostream>
#include <vector>
using namespace std;

void solveNQueens(int row, int n, vector<int>& position, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, vector<vector<int>>& solutions) {
    if (row == n) {
        solutions.push_back(position);
        return;
    }

    for (int col = 0; col < n; col++) {
        int d1 = col - row + n - 1;
        int d2 = col + row;
        if (!cols[col] && !diag1[d1] && !diag2[d2]) {
            position[row] = col;
            cols[col] = diag1[d1] = diag2[d2] = true;

            solveNQueens(row + 1, n, position, cols, diag1, diag2, solutions);

            // 回溯
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
}

void printSolutions(const vector<vector<int>>& solutions) {
    for (const auto& solution : solutions) {
        for (int col : solution) {
            cout << col << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cout << "Input N: ";
    cin >> N;

    vector<int> position(N);
    vector<bool> cols(N, false), diag1(2 * N - 1, false), diag2(2 * N - 1, false);
    vector<vector<int>> solutions;

    solveNQueens(0, N, position, cols, diag1, diag2, solutions);

    cout << "Number of solutions: " << solutions.size() << endl;
    printSolutions(solutions);

    return 0;
}
