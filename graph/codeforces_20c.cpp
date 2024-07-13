#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<bool> visited(MAX_N, false);
priority_queue<pair<int,int>> q;
vector<int> dist(MAX_N, -1);
vector<int> parent(MAX_N, -1);
vector<pair<int,int>> graph_weighted[MAX_N];
    

void dijkstra_distance(int start_node, int target_node, int n, vector<pair<int,int>> graph_weighted[]) {

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
                 parent[neighbour] = node;
            }
        }
    }
    int i = n;
    vector<int> path;
    while (parent[i]!=-1) {
        path.push_back(i);
        i=parent[i];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    if (dist[n] == -1) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
    }
}
    
int main() 
{
    int n,m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; ++i) {
        int y=0, v=0,z=0;
        cin >> y >> v >> z;
        graph_weighted[y].push_back(make_pair(v, z));
        graph_weighted[v].push_back(make_pair(y, z));
    }
    
    dijkstra_distance(1,n,n,graph_weighted);
}


