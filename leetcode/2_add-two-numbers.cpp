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

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *root = new ListNode();
        ListNode *current = root;
        int prev = 0; // 进位
        while (l1 != nullptr || l2 != nullptr || prev != 0)
        {
            int value = prev;
            if (l1 != nullptr)
            {
                value += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                value += l2->val;
                l2 = l2->next;
            }
            current->next = new ListNode;
            current = current->next;
            current->val = value % 10;
            prev = value / 10;
        }
        return root->next;
        // ListNode *root = new ListNode();
        // ListNode *current = root;
        // // nullptr == 0, 一般为了语义的清晰使用 nullptr
        // while (l1 != 0 || l2 != 0)
        // {
        //     int sum = 0;
        //     if (l1 != nullptr)
        //     {
        //         sum += l1 -> val;
        //         l1 = l1 -> next;
        //     }
        //     if(l2 != nullptr)
        //     {
        //         sum += l2 -> val;
        //         l2 = l2 -> next;
        //     }

        //     int value = sum;
        //     if(current->next!=nullptr){
        //         value += current->next->val;
        //     }

        //     if (value < 10) // 是不是应该判断 val + sum 而不是 sum
        //     {
        //         if(current -> next == nullptr)
        //         {
        //             current->next = new ListNode;
        //         }
        //         current = current -> next; // current = nullptr
        //         current -> val += sum;      // 非法访问了 val = 1, sum = 9
        //     }
        //     else
        //     {
        //          if(current -> next == nullptr)
        //         {
        //             current->next = new ListNode;
        //         }
        //         current = current -> next;
        //         current -> val += sum - 10;
        //         current->next = new ListNode;
        //         current -> next ->val = 1;
        //     }
        // }
        // auto head = root->next;
        // delete root;
        // return head;
    }
};
int main()
{
}