#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
class Graph {
public:
    Graph(int num_vertices) : adjacency_list(num_vertices + 1), beauty(num_vertices + 1), max_beauty(num_vertices + 1), in_deg(num_vertices + 1, 0) {}

    void add_edge(int from, int to) {
        adjacency_list[from].emplace_back(to);
        ++in_deg[to];
    }

    void set_beauty(int vertex, long long value) {
        beauty[vertex] = value;
        max_beauty[vertex] = value;
    }

    long long compute_max_beauty() {
        deque<int> zero_in_deg_vertices;

        for (size_t i = 1; i < in_deg.size(); ++i) {
            if (in_deg[i] == 0) {
                zero_in_deg_vertices.push_back(i);
            }
        }

        while (!zero_in_deg_vertices.empty()) {
            int current = zero_in_deg_vertices.front();
            zero_in_deg_vertices.pop_front();

            for (int next : adjacency_list[current]) {
                max_beauty[next] = max(max_beauty[next], beauty[next] + max_beauty[current]);

                if (--in_deg[next] == 0) {
                    zero_in_deg_vertices.push_back(next);
                }
            }
        }

        return max_beauty[1];
    }

private:
    vector<std::vector<int>> adjacency_list;
    vector<long long> beauty, max_beauty;
    vector<int> in_deg;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Graph g(n);

    for (int i = 1; i <= n; ++i) {
        long long beauty_value;
        cin >> beauty_value;
        g.set_beauty(i, beauty_value);
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g.add_edge(v, u);
    }

    cout << g.compute_max_beauty() << std::endl;

    return 0;
}


