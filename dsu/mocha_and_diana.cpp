#include <iostream>
#include <vector>
// #include "library.h"
using namespace std;


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


int main() {
    vector<pair<int,int> > q;
    int t,y,l=0,n;
    cin>>n;
    cin>>t;
    cin>>y;
    DSU mocha(n);
    DSU diana(n);
    for(int i=1;i<=t;i++){
        int k,w;
        cin>>k;
        cin>>w;
        mocha.unite(k,w);
    }
    for(int i=1;i<=y;i++){
        int k,w;
        cin>>k;
        cin>>w;
        diana.unite(k,w);
    }
    for(int i=1;i<n;i++){
        for(int x=i+1;x<=n;x++){
            if(mocha.find(x)!=mocha.find(i) and diana.find(x)!=diana.find(i)){
                q.push_back(make_pair(x,i));
                mocha.unite(x,i);
                diana.unite(x,i);
                l=l+1;
            }
        }
    }
    cout<<l<<endl;
    for (int i=0;i<q.size();i++){
        cout<<q[i].first<<" "<<q[i].second<<endl;
    }
}