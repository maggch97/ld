#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        // (())
        map<char, char> l2r = {{'[', ']'}, {'(', ')'}, {'{', '}'}};
        // cout << l2r['a']; // 0
        stack<char> stk; // 定义了一个栈
        // push 向栈顶增加一个元素
        // pop 从栈顶删除一个元素
        // top 取栈顶元素的值
        
        for (auto c : s)
        {
            if (c=='(' || c == '[' || c=='{')
            {
                // c 是左括号
                stk.push(c);
            }
            else
            {
                // c是右括号
                if (!stk.empty() && l2r[stk.top()] == c)
                {
                    // 栈顶元素和当前的 c 匹配
                    stk.pop();
                }else{
                    // 不匹配
                    return false;
                }
            }
        }
        if(stk.empty()){
            return true;
        }else{
            // 栈非空，一种情况是输入的全都是左括号 (((
            return false;
        }
        // vector<string> b = {"()", "{}", "[]"};
        // while (s != "")
        // {
        //     int originLength = s.length();
        //     for (auto x : b)
        //     {
        //         if (s.find(x) != -1)
        //         {
        //             s = s.substr(0, s.find(x)) + s.substr(s.find(x) + 2, s.size() - s.find(x) - 2);
        //         }
        //     }
        //     if (originLength == s.length())
        //     {
        //         return false;
        //     }
        // }
        // return true;
    }
};

int main()
{
    cout << Solution().isValid("()[]{}");
}