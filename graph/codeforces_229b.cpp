#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cstring>

using namespace std;

int main() {

    map<string,int> m;
    m["selim"] = 7;
    m["nazir"] = 8;

    cout << m["selim"] << endl; // O(logn)

    if (m.find("selim") != m.end()) {
        cout << m["selim"] << endl;
    }

    // the unordered_map is a map that works approximately in O(1) time
    // hash table - hash map


    // log(2) = 1
    // log(4) = 2
    // log(8) = 3
    // log(16) = 4
    // log(32) = 5
    // log(64) = 6
    // log(128) = 7
    // log(256) = 8
    // log(512) = 9
    // log(1024) = 10
    // log(2048) = 11
    // log(4096) = 12
    // log(8192) = 13
    // log(16384) = 14
    // log(32768) = 15
    // log(65536) = 16
    // log(131072) = 17


    // log3(3) = 1
    // log3(9) = 2
    
    // vector<int> v(1001);

    // cout << v[1000] << endl;  // O(1)

    // map<int,int> m2;
    // m2[1000] = 8;

for(int i = n - 1 ; i >= 0 ; i--) {
    cout << i << endl;
}

    return 0;
}

