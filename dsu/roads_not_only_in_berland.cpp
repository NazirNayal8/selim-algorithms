#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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
    int x=0;
    cin>>x;
    DSU ber(x);
    vector<pair<int,int>> free;
    for(int i=0;i<x - 1;i++){
        int k,l;
        cin>>k;
        cin>>l;
        if(ber.find(k)==ber.find(l)){
            free.push_back({k,l});
        }
        else{
            ber.unite(k,l);
        } 
    }
    set<int> l;
    vector<int> led;
    for(int i=1;i<=x;i++){
        int m=0;
        m=ber.find(i);
        l.insert(m);
    }
    for (auto x : l) {
        led.push_back(x);    
    }
    cout<<free.size()<<endl;
    for(int i=0;i<free.size();i++){
        cout<<free[i].first <<" "<<free[i].second<<" "<<led[i]<<" "<<led[i+1]<<endl;
    }
}
