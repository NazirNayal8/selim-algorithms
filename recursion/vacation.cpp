#include <iostream>
#include <vector>
using namespace std;

vector<int> values[3];
int n;
/*
degree
3 6 9
4 2 10
2 2 7
*/
int memory[100002][3];

int happiness(int day, int last_choice){

    if(day==n){
        return 0;
    }
    if(memory[day][last_choice] != -1){
        return memory[day][last_choice];
    }
    
    int d1 = (last_choice + 1) % 3; // 0
    int d2 = (last_choice + 2) % 3; // 1
    memory[day][last_choice] =  max(happiness(day + 1, d1) + values[d1][day], happiness(day + 1, d2) + values[d2][day]);
    return memory[day][last_choice];
}
int main() {

    memset(memory, -1, sizeof(memory));

     cin >> n;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        values[0].push_back(a);
        values[1].push_back(b);
        values[2].push_back(c);
    }
    cout << max(happiness(0,0), max(happiness(0,1), happiness(0,2))) << endl;

    // int arr[] = {1,2,3,4,5,6,7};
    // int *p[] = {arr+4,arr+2,arr}; // arr[2]
    // (*p)++;
    // printf("%d",**p);



}