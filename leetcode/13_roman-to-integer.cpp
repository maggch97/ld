#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> c2i = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int res = 0;
        for(int i=0;i<s.length();i++)
        {
            int value = c2i[s[i]];
            res += value;
            if(i+1<s.length()&&c2i[s[i]]<c2i[s[i+1]])
            {
                res-=2*value;
            }
        }
        return res;
    
    }
};

int main(){
    cout << Solution().romanToInt("IV");
}