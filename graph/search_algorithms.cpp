#include <iostream>
#include <stack>
#include <queue>

using namespace std;


const int n = 9;
const int m = 8;

vector<int> graph[n + 1];
vector<int> visited(n + 1, false);


void dfs_rec(int x) {
    
    visited[x] = true;
    cout << x << " is visited" << endl;
    for (int i = 0 ; i < graph[x].size(); i++) {
        int neighbour = graph[x][i];
        if (!visited[neighbour]) {
            dfs_rec(neighbour);
        }
    }
}


void dfs(int start) {

    // [false, True, True, True, false, false, false, false, false]
    vector<bool> visited(n + 1, false);
    stack<int> st;

    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        cout << node << " is visited" << endl;

        for (int i = 0; i < graph[node].size(); i++) {
            int neighbour = graph[node][i];
            if (!visited[neighbour]) {
                st.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }

}


void bfs(int start) {

    // [false, True, True, True, false, false, false, false, false]
    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " is visited" << endl;

        for (int i = 0; i < graph[node].size(); i++) {
            int neighbour = graph[node][i];
            if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }

}


int main() {

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    graph[2].push_back(6);
    graph[6].push_back(2);

    graph[2].push_back(7);
    graph[7].push_back(2);

    graph[3].push_back(4);
    graph[4].push_back(3);

    graph[3].push_back(5);
    graph[5].push_back(3);

    graph[7].push_back(8);
    graph[8].push_back(7);

    graph[7].push_back(9);
    graph[9].push_back(7);

    // testing the code
    cout << "DFS:" << endl;
    dfs(4);

    cout << "DFS Recursive:" << endl;
    dfs_rec(4);

    cout << "BFS:" << endl;
    bfs(4);

}