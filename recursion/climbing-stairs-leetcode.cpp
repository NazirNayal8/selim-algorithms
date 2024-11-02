#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
using namespace std;

using namespace std;

// vector<int> memory = vector<int>(50, -1);

vector<int> memory(100002, -1);
int stair_mem(int n) {
    if ( n<0) {
        return 0;
    }
    if(n==0){
        return 1;
    }
    if (memory[n] != -1) {
        return memory[n];
    }

    memory[n] = stair_mem(n - 1) + stair_mem(n - 2);
    return memory[n];
}

int main() {
    int n;
    cin >> n;
cout <<stair_mem(n)<<endl;
    
}