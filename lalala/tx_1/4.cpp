// https://www.nowcoder.com/test/question/11ee0516a988421abf40b315a2b28d08?pid=30545524&tid=47169735
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>
#include <queue>
using namespace std;
#define dbg(x) cout << (#x) << " = " << (x) << endl;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int Q;
        cin >> Q;
        queue<int> q;
        while (Q--)
        {
            string op;
            cin >> op;
            if (op == "PUSH")
            {
                int x;
                cin >> x;
                q.push(x);
            }
            else if (op == "TOP")
            {
                if (q.empty())
                {
                    cout << -1 << endl;
                }
                else
                {
                    cout << q.front() << endl;
                }
            }
            else if (op == "POP")
            {
                if (q.empty())
                {
                    cout << -1 << endl;
                }
                else
                {
                    q.pop();
                }
            }
            else if (op == "SIZE")
            {
                cout << q.size() << endl;
            }
            else if (op == "CLEAR")
            {
                q = queue<int>();
            }
        }
    }
    return 0;
}