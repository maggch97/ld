#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// x = 1095
// x % 10 = 5
// x / 10 = 109

// x % 10 = 9
// x / 10 = 10

// rev = 0
// x = 1095
// pop = 5
// rev = rev*10+5 = 5
// x = 109

// x = 109
// pop = 9
// rev = 5*10+9 = 59
// rev = 59*10+0 = 590
// rev = 590*10+1 = 5901


class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            // INT_MAX 结尾是 7
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};