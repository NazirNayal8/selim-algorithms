#include <iostream>
#include <stack>
using namespace std;
int main()
{
  int tc;
  cin >> tc;
  for (int k = 0; k < tc; k++)
  {
    stack<char> st;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
      char t = s[i];
      if (t == 'B')
      {
        if (st.empty())
        {
          st.push(t);
        }
        else
        {
          st.pop();
        }
      }
      else
      {
        st.push(t);
      }
    }
    cout << st.size() << endl;
  }
}
