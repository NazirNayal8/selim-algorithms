#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "library.h"

using namespace std;

int main() { 
    int x=0;
    cin>>x;
    DSU ber(x);
    vector<pair<int,int>> free;
    for(int i=0;i<x;i++){
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
    for(int i=0;i<x;i++){
        int m=0;
        m=ber.find(i);
        l.insert(m);
    }
    
    for (auto x : l) {
        led.push_back(x);    
    }
    
    
}
