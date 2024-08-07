#include <iostream>
#include <stack>
#include <queue>
#include <utility>

using namespace std;


const int n = 10;
const int m = 13;

vector<int> graph[n + 1];
vector<pair<int,int>> graph_weighted[n + 1];
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

int tree_distance(int start_node, int target_node) {

    vector<bool> visited(n + 1, false);
    queue<int> q;
    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1, -1);

    // parent[i] = j means that j is the parent of i

    q.push(start_node);
    visited[start_node] = true;
    dist[start_node] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // cout << node << " is visited" << endl;

        for (int i = 0; i < graph_weighted[node].size(); i++) {
            int neighbour = graph_weighted[node][i].first;
            int weight = graph_weighted[node][i].second;

            if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                dist[neighbour] = dist[node] + weight;
                parent[neighbour] = node;
            }
        }
    }
    
    int i = target_node;
    while (parent[i]!=-1) {
        cout<<parent[i] << endl;
        i=parent[i];
    }

    return dist[target_node];
}


int dijkstra_distance(int start_node, int target_node) {

    vector<bool> visited(n + 1, false);
    priority_queue<pair<int,int>> q;
    vector<int> dist(n + 1, -1);
    
    // parent[i] = j means that j is the parent of i

    q.push(make_pair(0, start_node));
    visited[start_node] = true;
    dist[start_node] = 0;

    while (!q.empty()) {
        pair<int,int> pair = q.top();
        int node = pair.second;
        dist[node] = -pair.first;
        q.pop();

        // cout << node << " is visited" << endl;

        for (int i = 0; i < graph_weighted[node].size(); i++) {
            int neighbour = graph_weighted[node][i].first;
            int weight = graph_weighted[node][i].second;

            if (dist[neighbour] == -1 || dist[neighbour] > dist[node] + weight) {
                dist[neighbour] = dist[node] + weight;
                q.push(make_pair(-dist[neighbour], neighbour));
            }
        }
    }
 }
    return dist[target_node];
}



void initialize_tree() {

    graph_weighted[1].push_back(make_pair(2, 4));
    graph_weighted[2].push_back(make_pair(1, 4));

    graph_weighted[2].push_back(make_pair(3, 1));
    graph_weighted[3].push_back(make_pair(2, 1));

    graph_weighted[2].push_back(make_pair(6, 2));
    graph_weighted[6].push_back(make_pair(2, 2));

    graph_weighted[2].push_back(make_pair(7, 2));
    graph_weighted[7].push_back(make_pair(2, 2));

    graph_weighted[3].push_back(make_pair(4, 2));
    graph_weighted[4].push_back(make_pair(3, 2));

    graph_weighted[3].push_back(make_pair(5, 3));
    graph_weighted[5].push_back(make_pair(3, 3));

    graph_weighted[7].push_back(make_pair(8, 4));
    graph_weighted[8].push_back(make_pair(7, 4));

    graph_weighted[7].push_back(make_pair(9, 3));
    graph_weighted[9].push_back(make_pair(7, 3));

}


void initialize_graph() {

    graph_weighted[1].push_back(make_pair(2, 4));
    graph_weighted[2].push_back(make_pair(1, 4));

    graph_weighted[2].push_back(make_pair(3, 1));
    graph_weighted[3].push_back(make_pair(2, 1));

    graph_weighted[2].push_back(make_pair(6, 2));
    graph_weighted[6].push_back(make_pair(2, 2));

    graph_weighted[2].push_back(make_pair(7, 2));
    graph_weighted[7].push_back(make_pair(2, 2));

    graph_weighted[3].push_back(make_pair(4, 2));
    graph_weighted[4].push_back(make_pair(3, 2));

    graph_weighted[3].push_back(make_pair(5, 3));
    graph_weighted[5].push_back(make_pair(3, 3));

    graph_weighted[7].push_back(make_pair(8, 4));
    graph_weighted[8].push_back(make_pair(7, 4));

    graph_weighted[7].push_back(make_pair(9, 3));
    graph_weighted[9].push_back(make_pair(7, 3));

    graph_weighted[6].push_back(make_pair(10, 1));
    graph_weighted[10].push_back(make_pair(6, 1));

    graph_weighted[9].push_back(make_pair(10, 4));
    graph_weighted[10].push_back(make_pair(9, 4));

    graph_weighted[5].push_back(make_pair(8, 2));
    graph_weighted[8].push_back(make_pair(5, 2));

    graph_weighted[3].push_back(make_pair(7, 1));
    graph_weighted[7].push_back(make_pair(3, 1));

    graph_weighted[4].push_back(make_pair(5, 2));
    graph_weighted[5].push_back(make_pair(4, 2));

}


int main() {

   initialize_tree();

    // testing the code
    // cout << "DFS:" << endl;
    // dfs(4);

    // cout << "DFS Recursive:" << endl;
    // dfs_rec(4);

    // cout << "BFS:" << endl;
    // bfs(4);

    int start_node = 8;
    int target_node = 5;
    
    cout << "Distance between " << start_node << " and " << target_node << " is " << tree_distance(start_node, target_node) << endl;
}