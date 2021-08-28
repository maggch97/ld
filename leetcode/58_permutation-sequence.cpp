#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int i= s.find_last_not_of(' ');
        cout << i << endl;
        string temp = s.substr(0,i+1);
        int j= temp.find_last_of(' ');
        cout << j << endl;
        return i-j;
    }
};

int main()
{
    cout << Solution().lengthOfLastWord("    Hello World    ");
}