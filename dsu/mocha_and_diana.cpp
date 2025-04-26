#include <iostream>
#include <vector>
#include "library.h"
using namespace std;
int main() {
    vector<pair<int,int> > q;
    int t,y,l,n;
    cin>>n;
    cin>>t;
    cin>>y;
    DSU mocha(t);
    DSU diana(y);
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
                l=l+1;
            }
        }
    }
    cout<<l<<endl;
    for (int i=0;i<q.size();i++){
        cout<<q[i].first<<" "<<q[i].second<<endl;
    }
}