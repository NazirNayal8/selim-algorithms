#include <iostream>
#include <stack>
using namespace std;
int main(){
int z=0;
string s;
cin>>s;
int t=s.length();
stack<char>st; 
for(int i=0;i<t;i++){
  if(!st.empty() and s[i]==st.top()){
    st.pop();
    z=z+1;
  }
  else{
    st.push(s[i]);
  }
}
if(z%2==0){
    cout<<"No"<<endl;
}
else{
    cout<<"Yes"<<endl;
}
}
