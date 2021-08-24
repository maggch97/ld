
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
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
    // pre 是未反转前cur节点的前置节点
    ListNode* dfs(ListNode *pre, ListNode *cur){
        dfs(cur, cur->next);
        cur->next = pre;
    }
    ListNode *reverseList(ListNode *head)
    {
        if(head == nullptr){
            return head;
        }
        dfs(nullptr,head);
        return head;

        ListNode *root = new ListNode();
        root->next = head;
        ListNode *p1 = root->next;
        ListNode *p2 = root->next->next;
        while(p2!=nullptr){
            ListNode *nxt = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = nxt;
        }
        head->next = nullptr;
        return p1;
        // ListNode *current = head;
        
        // stack <int> value;
        // if (head == nullptr)
        // {
        //     return head;
        // }
        // do{
        //     value.push(current -> val);
        //     current = current -> next;
        // } while (current != nullptr);

        // current = head;
        // while (current != nullptr)
        // {
        //     current -> val = value.top();
        //     value.pop();
        //     current = current -> next;
        // }
        // return head;
    }
};