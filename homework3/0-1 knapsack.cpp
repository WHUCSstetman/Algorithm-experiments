#include <iostream>
#include <fstream>

using namespace std;

int judge(int** a, int n, int w) {
    int** dp = new int*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        dp[i] = new int[w + 1];
    }

    for (int i = 0; i < w + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) {
                dp[j][i] = 0;
            }
        }
    }
    for (int i = 1; i < w + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (i < a[j - 1][1]) {
                dp[j][i] = dp[j - 1][i];
            } else {
                dp[j][i] = max(dp[j - 1][i], dp[j - 1][i - a[j - 1][1]] + a[j - 1][0]);
            }
        }
    }
    return dp[n][w];
}

int main() {
    ifstream inputFile("/Users/dragon_rider/CLionProjects/untitled6/data/ks_300_0.txt");
    int n, w;
    inputFile >> n >> w;

    int** items = new int*[n];
    for (int i = 0; i < n; ++i) {
        items[i] = new int[2];
        inputFile >> items[i][0] >> items[i][1];
    }

    inputFile.close();

    cout << judge(items, n, w);

    for (int i = 0; i < n; ++i) {
        delete[] items[i];
    }
    delete[] items;

    return 0;
}
