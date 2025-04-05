#include <iostream>
#include <vector>
using namespace std;

// 2 4 8 9 4 5 2 1 9 2 **
// 0 1 2 3 4 5 6 7 8 9 10

int maxProfit(vector<int>& prices) {
 int maxp=0;
 int lowest=prices[0]; 
 // when i = prices.size() finishes, i+1 is outside
 // when i = prices.size() - 2, i+1=prices.size() - 1
 for(int i = 0 ; i < prices.size() - 1; i++) {
  if(prices[i+1]>lowest){
    if (prices[i+1]-lowest>maxp){
     maxp=prices[i+1]-lowest;
    }
  }
  else if(prices[i+1]<lowest){
    lowest=prices[i+1];
  }
 }
  return maxp;  
}

int main() {
    
  vector<int> prices;
  prices.push_back(7);
  prices.push_back(6);
  prices.push_back(4);
  prices.push_back(3);
  prices.push_back(1);

  cout << maxProfit(prices) << endl;

}