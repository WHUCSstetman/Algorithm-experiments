#include <iostream>
#include <vector>
using namespace std;

void finding_exchange(int final, int n, int** R, int step, double num, double& max, vector<int>& exchange_way, vector<vector<int>>& bestways, vector<bool>& visited) {
    if (step == final) {
        if (num > max) {
            max = num;
            bestways.clear();
            bestways.push_back(exchange_way);
        } else if (num == max) {
            bestways.push_back(exchange_way);
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            exchange_way.push_back(i);
            finding_exchange(final, n, R, i, num * R[step][i], max, exchange_way, bestways, visited);
            exchange_way.pop_back();  // 回溯
            visited[i] = false;
        }
    }
}

void find_best_exchange(int** R, int n, int a, int b) {
    vector<int> exchange_way;
    vector<vector<int>> bestways;
    double max = 0;
    vector<bool> visited(n, false);

    exchange_way.push_back(a);
    visited[a] = true;
    finding_exchange(b, n, R, a, 1.0, max, exchange_way, bestways, visited);

    cout << "Max exchange amount: " << max << endl;
    cout << "Best exchange methods: " << endl;
    for (const auto& p : bestways) {
        for (int v : p) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    // ... 初始化 R，n，a，b 等
    // find_best_exchange(R, n, a, b);
    return 0;
}
