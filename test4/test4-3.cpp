#include <iostream>
#include <vector>
using namespace std;

void finding_way(int final, int n, int** A, int step, int length, int& shortest, vector<int>& way, vector<vector<int>>& shortestways) {
    way.push_back(step);  // 添加当前节点到路径

    if (step == final) {  // 到达目标节点
        if (length == shortest) {
            shortestways.push_back(way);
        }
        else if (length < shortest) {
            shortest = length;
            shortestways.clear();
            shortestways.push_back(way);
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (A[step][i] != 0 && find(way.begin(), way.end(), i) == way.end()) {  // 检查是否已经访问过
                if (length + A[step][i] < shortest) {  // 剪枝条件
                    finding_way(final, n, A, i, length + A[step][i], shortest, way, shortestways);
                }
            }
        }
    }

    way.pop_back();  // 回溯，从路径中移除当前节点
}

void get_shortest(int** A, int n, int s, int t) {
    vector<int> way;
    vector<vector<int>> shortestways;
    int shortest = INT_MAX;

    finding_way(t, n, A, s, 0, shortest, way, shortestways);

    cout << "Shortest path length: " << shortest << endl;
    cout << "Shortest paths: " << endl;
    for (const auto& p : shortestways) {
        for (int v : p) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    int s = 0;
    int t = 3;

    int** A = new int*[n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }

    // 构建邻接矩阵
    A[0][1] = 10;
    A[0][2] = 3;
    A[1][3] = 1;
    A[2][1] = 1;
    A[2][3] = 5;

    // 运行程序
    get_shortest(A, n, s, t);

    // 释放内存
    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
