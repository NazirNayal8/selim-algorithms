#include "library.h"

using namespace std;


int find(DSU dsu, int x) {
    while (dsu.leader[x] != x) {
        dsu.leader[x] = dsu.leader[dsu.leader[x]];
        x = dsu.leader[x];
    }
    return x;
}

struct DSU {

    vector<int> leader;
    vector<int> levels;
    vector<int> sizes;
    int leaders;

    // constructor
    DSU(int n) {
        leader.resize(n + 1);
        levels.resize(n + 1);
        sizes.resize(n + 1);
        for (int i = 1; i <= n ; i++) {
            leader[i] = i;
            levels[i] = 1;
            sizes[i] = 1;
        }
    }

    int find(int x) {
        while (leader[x] != x) {
            leader[x] = leader[leader[x]];
            x = leader[x];
        }
        return x;
    }

    void unite(int x, int y) {
        int leader_x = find(x);
        int leader_y = find(y);

        if (leader_x == leader_y) {
            return;
        }

        if (levels[leader_x] > levels[leader_y]) {
            leader[leader_y] = leader_x;
            sizes[leader_x] += sizes[leader_y];
            leaders--;
        } else if (levels[leader_x] < levels[leader_y]) {
            leader[leader_x] = leader_y;
            sizes[leader_y] += sizes[leader_x];
            leaders--;
        } else {
            leader[leader_x] = leader_y;
            levels[leader_y]++;
            sizes[leader_y] += sizes[leader_x];
            leaders--;
        }
    }

};


struct Graph {
    int n;
    // adjacency list
    vector<vector<int>> adj;

    Graph(int n): n(n) {
        adj.resize(n + 1);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, vector<bool>& visited) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, visited);
            }
        }
    }
};


int main() {

    DSU d(10);

    d.unite(1, 2);
    d.unite(3, 4);

    int leader_of_2 = d.find(2);

    Graph g(10);

    g.add_edge(1, 2);
    g.add_edge(2, 3);

    vector<bool> visited(10, false);
    g.dfs(1, visited);

}