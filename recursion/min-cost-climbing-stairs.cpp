#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
using namespace std;

using namespace std;

// vector<int> memory = vector<int>(50, -1);

vector<int> memory(100002, -1);

int stair_mem(int n, vector<int>&cost) {
    // cost.size()
    if (n<0) {
        return 100000000;
    }

    if (n == 0) {
        return cost[n];
    }

    if (memory[n] != -1) {
        return memory[n];
    }

    int left_cost = stair_mem(n - 1, cost);
    int right_cost = stair_mem(n - 2, cost);
    memory[n] = cost[n] + min(left_cost, right_cost);
    
    return memory[n];
}

int solve(vector<int>& cost) {
    cost.push_back(0);
    return stair_mem(cost.size() - 1, cost);
}

int main() {
    vector<int> cost;
    cost.push_back(10);
    cost.push_back(15);
    cost.push_back(20);

    cout <<solve(cost)<<endl;

}