#include <iostream>
#include <vector>
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