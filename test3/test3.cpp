#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

struct Position {
    int x, y;
};

int pick_apple(vector<vector<int>>& orchard, int startX, int startY, int M, int N) {
    stack<Position> stack;
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    stack.push({startX, startY});
    int count = 0;

    while (!stack.empty()) {
        Position current = stack.top();
        stack.pop();

        int x = current.x;
        int y = current.y;

        if (x < 0 || x >= M || y < 0 || y >= N || orchard[x][y] == -1 || visited[x][y]) {
            continue;
        }
        visited[x][y] = true;
        if (orchard[x][y] == 1) {
            count++;
            orchard[x][y] = 0;
        }
        if (x + 1 < M && !visited[x + 1][y]) stack.push({x + 1, y});
        if (x - 1 >= 0 && !visited[x - 1][y]) stack.push({x - 1, y});
        if (y + 1 < N && !visited[x][y + 1]) stack.push({x, y + 1});
        if (y - 1 >= 0 && !visited[x][y - 1]) stack.push({x, y - 1});
    }
    return count;
}

int main() {
    int M, N;
    char ignore;//读符号
    cin >> M >> ignore >> N;

    vector<vector<int>> orchard(M, vector<int>(N, 1)); // 初始化果园，1代表苹果树

    string line;
    getline(cin, line); // 读取第1行的回车
    getline(cin, line); // 读取第二行

    stringstream ss(line);
    int x, y;
    while (ss >> ignore >> x >> ignore >> y >> ignore) {
        orchard[x][y] = -1; // 标记梨树位置
    }

    int apple_count = pick_apple(orchard, 6, 6, M, N);
    cout << apple_count << endl;

    return 0;
}
