#include <iostream>
#include <vector>
using namespace std;
void read_vector(vector<int> &v, int n) {
  for(int i = 0 ; i < n ; ++i) {
    int x;
    cin >> x;
    v.push_back(x-1);
  }
}
int main() {
vector<int> p;
int n=0;
cin>>n;
read_vector(p,n);
int answer = 0;
 for(int x = 0 ; x < n ; x++) {
     int y = x;
     int count = 0;
     while (y != -2) {
         y = p[y];
         count=count+1;
     }
     answer = max(answer, count);
 }
 cout<<answer<<endl;
}
