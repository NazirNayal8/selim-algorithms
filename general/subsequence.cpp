#include <iostream>
#include <vector>
using namespace std;
bool isSubsequence(string s, string t) {
        int x=0;
        for(int i=0;i<t.length();i++){
            if(s[x]==t[i]){
                x=x+1;
            }
        }
        if(x==s.length()){
            return true;
        }
        else{
            return false;
        }
}
int main() {
    cout << isSubsequence("axc", "ahbgdc") << endl;
}