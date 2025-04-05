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
int findCircleNum(vector<vector<int> >& isConnected) {
    
    int n = isConnected.size();
    
    leader.resize(n + 1);
    levels.resize(n + 1);
    sizes.resize(n + 1);
    leaders=n;
    for (int i = 0; i < n; i++) {
        leader[i] = i;
        levels[i] = 1;
        sizes[i] = 1;
    }
    
    for(int i=0;i<n;i++){
        for(int z=0;z<n;z++){
            if(z==i){
                continue;
            }
            if (isConnected[i][z]==1){
                unite(i,z);
            }

        }
    }
    return leaders;
}


int main() {
    
    vector<vector<int> > isConnected = {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
    };

    cout << findCircleNum(isConnected) << endl;
    
}