#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int k=0 ; k < t ; k++) {
        int m=0;
        cin>>m;
        vector <int> ls (m);
        cout <<m<<endl;
        for(int i=0;i<m;i++){
            ls[i]=i+1;
            cout << i+1 << " ";       
        }
        cout << endl;    
        for(int i=0;i<m-1;i++){
            swap(ls[i],ls[i+1]);
            for(int n=0;n<ls.size();n++){
                cout<<ls[n]<<" ";
            }
            cout<<endl;
        }

    }
}