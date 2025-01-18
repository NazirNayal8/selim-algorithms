#include <iostream>
using namespace std;
int memory[2501][2501]; // 2D array, a 2D matrix 
// cout << memory[x][y] << endl;
int longest (int x, vector<int>& nums,int y){
    if (x==nums.size()){
        return 0;
    }
    if (memory[x][y] != -1) {
        return memory[x][y];
    }
    if (nums[x]<=nums[y]){
        memory[x][y] = longest(x+1, nums, y);
        return memory[x][y];
    }
    if (nums[x]>nums[y]){
       int take = 1 + longest(x+1,nums, x);
       int not_take = longest(x+1, nums, y);
        memory[x][y] =max(take,not_take);
        return memory[x][y];
    }
}
// 2, 10, 3, 7, 101, 18
int lengthOfLIS(vector<int>& nums) {
    return longest(0,nums,-1);   
}
int main(){
    for (int i=0; i< 2500; ++i){
        for (int j=0; j<2500; ++j){
            memory[i][j] = -1;
        }
    }
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(10);
    nums.push_back(9);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(101);
    nums.push_back(18);
    cout <<longest(1, nums, 0) << endl;
    return 0;
}
//https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=problem-list-v2&envId=50wroh7h