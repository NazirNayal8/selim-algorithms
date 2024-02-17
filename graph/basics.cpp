#include <iostream>
#include <vector>
using namespace std;

int n = 7;
int m = 7;


int main() {

    // Adjacency Matrix
    int adj_matrix[n][n] = {
        {0, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    // vector<vector<int>> adj_matrix_v(n, vector<int>(n, 0));
    // adj_matrix_v[0][1] = 1;
    // adj_matrix_v[1][0] = 1;
    // adj_matrix_v[1][2] = 1;
    // adj_matrix_v[1][4] = 1;
    // adj_matrix_v[2][1] = 1;
    // adj_matrix_v[2][3] = 1;
    // adj_matrix_v[3][2] = 1;
    // adj_matrix_v[3][4] = 1;
    // adj_matrix_v[4][1] = 1;
    // adj_matrix_v[4][3] = 1;
    // adj_matrix_v[4][5] = 1;
    // adj_matrix_v[4][6] = 1;
    // adj_matrix_v[5][4] = 1;
    // adj_matrix_v[6][4] = 1;


    // vector<int> v(n);
    // v.push_back(1) // of size n + 1 , it's dynamic
    // int a[n]; // size of the array is static

    // for(int i = 0; i < n; i++) {
    //     cout  << v[i] << " " << a[i] << endl;
    // }

    /*
    int a = 3;
    int a[3];
    cout << a[3] << endl;
    vector<int> v(3);
    v.push_back(5)
    */

    // is there an edge between 0 and 1?
    cout << adj_matrix[0][1] << endl;


    // Adjacency List using vectors
    vector<int> adj_list[n];
    /*
    [
        []
        []
        []
        []
        []
        []
        []
    ]   
    */
    
    adj_list[0].push_back(1);
    adj_list[1].push_back(0);
    adj_list[1].push_back(2);
    adj_list[1].push_back(4);
    adj_list[2].push_back(1);
    adj_list[2].push_back(3);
    adj_list[3].push_back(2);
    adj_list[3].push_back(4);
    adj_list[4].push_back(1);
    adj_list[4].push_back(3);
    adj_list[4].push_back(5);
    adj_list[4].push_back(6);
    adj_list[5].push_back(4);
    adj_list[6].push_back(4);

    for(int i = 0; i < n; i++) {
        cout << "Node " << i+1 << " is connected to: ";
        for(int j = 0; j < adj_list[i].size(); j++) {
            cout << adj_list[i][j]+1 << " ";
        }
        cout << endl;
    }

// input example:
// first row has two numbers: number of nodes (n) and number of edges (m)
// next m lines you will have in each line two numbers x,y which means there is an edge between x and y
// 7 7
// 1 2
// 2 3
// 2 5
// 3 4
// 4 5
// 5 6
// 5 7
    
    int n,m;
    cin >> n >> m;
    vector<int> adj_list[n];
    for(int i = 0; i < m ; i++){
        int x,y;
        cin >> x >> y;
        adj_list[x-1].push_back(y-1);
        adj_list[y-1].push_back(x-1);
    }

}
