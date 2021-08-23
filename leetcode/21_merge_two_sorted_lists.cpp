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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *root = new ListNode();
        ListNode *current = root;
        while(l1!=nullptr || l2!=nullptr){
            if(l1==nullptr){
                current->next = new ListNode(l2->val);
                current = current->next;
                l2 = l2->next;
            }else if (l2==nullptr){
                current->next = new ListNode(l1->val);
                current = current->next;
                l1 = l1->next;
            }else if(l1->val <=l2->val){
                current->next = new ListNode(l1->val);
                current = current->next;
                l1 = l1->next;
            }else if(l2->val <= l1->val){
                current->next = new ListNode(l2->val);
                current = current->next;
                l2 = l2->next;
            }
        }
        return root->next;
    }
};
