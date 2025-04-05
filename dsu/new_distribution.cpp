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


int main() {

    int n=0;
    int m=0;
    scanf("%d %d", &n, &m);

    leader.resize(n + 1);
    levels.resize(n + 1);
    sizes.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        leader[i] = i;
        levels[i] = 1;
        sizes[i] = 1;
    }

    for(int i=0;i<m;i++){
        int k =0;
        scanf("%d", &k);// cin>>k;
        int previous;
        for(int l=0;l<k;l++){
            int x;
            // cin >> x;
            scanf("%d", &x);
            if (l > 0) {
                unite(x, previous);
            }
            previous = x;
        } 
    }
    for(int i=1;i<=n;i++){
        int leader_of_i = find(i);
        // cout << sizes[leader_of_i] << " ";
        printf("%d ", sizes[leader_of_i]);
    }
    // int x;
    // cin >> x;
}