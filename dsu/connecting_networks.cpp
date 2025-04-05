#include <iostream>
#include <vector>

using namespace std;
vector<int> leader;
vector<int> levels;
vector<int> sizes;
int leaders;

int find(int x){

    while(leader[x] != x)  {
        leader[x] = leader[leader[x]];
        x = leader[x];
    }
    return x;
}

void unite(int x, int y) {
    int leader_x = find(x);
    int leader_y = find(y);

    if (leader_x == leader_y){
        return;
    }

    if (levels[leader_x] > levels[leader_y]) {
        leader[leader_y] = leader_x; 
        sizes[leader_x] += sizes[leader_y];
        leaders--;
    }
    else if (levels[leader_x] < levels[leader_y]) {
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


int makeConnected(int n, vector<vector<int>>& connections) {
    leader.resize(n + 1);
    levels.resize(n + 1);
    sizes.resize(n + 1);
    leaders=n;  
    for (int i = 0; i < n; i++) {
        leader[i] = i;
        levels[i] = 1;
        sizes[i] = 1;
    }
    
    for (int t=0;t<connections.size();t++){
        unite(connections[t][0],connections[t][1]);
    }
    
    if(connections.size()>=n-1){
        return leaders-1;
    }
    else{
        return -1;
    }
}


int main() {

    int n = 6;
    vector<vector<int>> connections = {{0,1},{0,2},{0,3}};

    cout << makeConnected(n, connections) << endl;

}