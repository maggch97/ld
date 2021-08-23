#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define dbg(x) cout << (#x) << " = " << (x) << endl


// x: 0 0 0 0  0 0 1 1
//          16 8 4 2 1
// x << 4
// x: 0 0 1 1 0 0 0 0
class Solution {
public:
    // stoi : string to int
    // stoll: string to long long
    // stoull: string to unsigned long long

    int reverse(int x) {
        string input = to_string(x);
        bool neg = (input[0]=='-');
        if(neg){
            std::reverse(input.begin()+1,input.end());
        }else{
            std::reverse(input.begin(),input.end());
        }
        long long y = stoll(input);
        if (y>= -(1LL << 31) && y<= (1LL<<31)-1)
        {
            return y;
        }
        else
        {
            return 0;
        }
    }
};

int main(){
    Solution s;
    cout << s.reverse(1534236469);
}