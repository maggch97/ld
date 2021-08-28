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
    vector<int> plusOne(vector<int> digits)
    {
        int last = digits.size()-1;
        pair <int,int> in9;
        in9.first=9;
        in9.second=0;
        if(digits[last]==9)
        {
            // digits = {9}
             while(last>=0 && digits[last]==9) // {}[-1]
             {
                 in9.second++;
                 digits.pop_back(); // {}
                 last = digits.size()-1; // last = -1
             }
            if(digits.size()==0)
            {
                digits.push_back(0);
            }
            
            last = digits.size()-1;
            cout << last << endl;
            digits.back()++;    // int &
            // digits {0, 1, 2}
            //                  .   
            // [digits.begin(), digits.end() )
            digits.insert(digits.end(),in9.second,0);
        }
        else
        {
            digits[last]++;
        }
        
        return digits;
    }
};

int main()
{
    Solution s;
    cout << s.plusOne({9})[0] <<endl;
}