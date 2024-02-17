#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    for (int z = 0; z < t; z++)
    {
        int l;
        int move = 0;
        int n;
        cin >> n;
        string b;
        cin >> b;
        stack<char> st;
        l = b.length();
        for (int i = 0; i < l; i++)
        {
            if (st.empty() and b[i] == ')')
            {
                move = move + 1;
            }
            else if (st.empty() and b[i] == '(')
            {
                st.push(b[i]);
            }
            else if (st.top() == '(' and b[i] == ')')
            {
                st.pop();
            }
            else if (st.top() == '(' and b[i] == '(')
            {
                st.push(b[i]);
            }
        }
        cout << move << endl;
    }
}