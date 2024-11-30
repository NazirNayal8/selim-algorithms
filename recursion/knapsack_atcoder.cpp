#include <iostream>
#include <vector>
using namespace std;
vector<long long>W;
vector<long long>v;
int n;
int w;
long long memory[101][100001];
// memory[left_n][right_n];
long long knapsack(int left_n, int left_w){
    // memory[left_n][left_w];
    if ( left_w<=0) {
        return 0;
    }
    if(left_n<0){
        return 0;
    }
    if (memory[left_n][left_w] != -1) {
        return memory[left_n][left_w];
    }
   if(left_w<W[left_n]){
    memory[left_n][left_w] = knapsack(left_n-1,left_w);
    return memory[left_n][left_w];
   }
   long long not_take=knapsack(left_n-1,left_w);
   long long take=v[left_n] + knapsack(left_n-1,left_w-W[left_n]);
   memory[left_n][left_w] = max(not_take,take);
   return memory[left_n][left_w];
}
int main() {
// fill the memory with -1
for(int i=0;i<101;i++){
    for(int j=0;j<100001;j++){
        memory[i][j]=-1;
    }
}
cin>>n;
cin>>w;
for(int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    W.push_back(x);
    v.push_back(y);
}
int left_w=w;
int left_n=n;
cout<<knapsack(left_n-1,left_w);
}