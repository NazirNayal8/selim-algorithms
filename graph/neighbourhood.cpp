#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n=7, m=7;

    vector<int> adj_list[n+1];
    adj_list[1].push_back(2);
    adj_list[2].push_back(1);
    
    adj_list[2].push_back(3);
    adj_list[3].push_back(2);
    
    adj_list[2].push_back(4);
    adj_list[4].push_back(2);

    adj_list[4].push_back(5);
    adj_list[5].push_back(4);

    adj_list[3].push_back(6);
    adj_list[6].push_back(3);

    adj_list[6].push_back(7);
    adj_list[7].push_back(6);


    vector<int> money({-1, 7, 25, 15, 11, 8, 9, 3});
    

    // for(int i = 0 ; i < adj_list[3].size() ; ++i) {
    //     cout << adj_list[3][i] << " ";  
    // }
    // cout<<money[3];

  int x=0,r=0;
    for(int q=0,i=1;q<m;q++,i++){
        int y=0;
        for(int t=0;t<adj_list[i].size();t++){
           y=y+money[adj_list[i][t]];
        }
            if(x<y){
                x=y;
                r=i;
            }
         
   }
   cout<<x<<endl<<r;
}