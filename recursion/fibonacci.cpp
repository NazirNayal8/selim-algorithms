#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> memory(1000, -1);
// memoization
int fib_mem(int n) {
    if (n == 1 or n == 2) {
        return 1;
    }
    if (memory[n] != -1) {
        return memory[n];
    }

    memory[n] = fib_mem(n - 1) + fib_mem(n - 2);
    return memory[n];
}

int fib(int n) {
    if (n == 1 or n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}


int main() {

// recursive
int n = 25;

auto start0 = chrono::high_resolution_clock::now();

cout << fib(n) << endl;

auto stop0 = chrono::high_resolution_clock::now();


auto duration0 = chrono::duration_cast<chrono::microseconds>(stop0 - start0);

cout << "Duration for Recursive is " << duration0.count() << endl;


auto start = chrono::high_resolution_clock::now();

cout << fib_mem(n) << endl;

auto stop = chrono::high_resolution_clock::now();

auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

cout << "Duration for Recursive with Memory is " << duration.count() << endl; 

auto start2 = chrono::high_resolution_clock::now();

int answer;
int previous=1;
int current=1;
// iterative
for(int i = 3 ; i <= n ; ++i) {
answer = previous+current;
previous=current;
current=answer;
}

cout << answer << endl;
auto stop2 = chrono::high_resolution_clock::now();

auto duration2 = chrono::duration_cast<chrono::microseconds>(stop2 - start2);

cout << "Duration for Iterative is " << duration2.count() << endl; 


}