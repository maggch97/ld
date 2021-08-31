
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
    ListNode *deleteDuplicates2(ListNode *head)
    {
        // 1 -> 1 -> 1 -> 2 -> 2 -> 3 -> 3 -> 3
        //                          h             c
        ListNode *root = new ListNode();
        ListNode *current = root;
        root->next = head;
        while (head != nullptr)
        {
            current = head->next;
            while (current != nullptr && current->val == head->val)
            {
                current = current->next;
            }
            head->next = current;
            head = head->next;
        }
        return root->next;
    }

    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *root = new ListNode();
        ListNode *current = root;
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        current->next = new ListNode(head->val);
        current = current->next;
        head = head->next;
        while (head != nullptr)
        {
            while (current->val == head->val)
            {
                if (head->next != nullptr)
                {
                    head = head->next;
                }
                else
                {
                    return root->next;
                }
            }
            current->next = new ListNode(head->val);
            current = current->next;
            head = head->next;
        }
        for (auto cur = head; cur != nullptr; cur++)
        {
            auto nxt = cur->next;
            delete cur;
            cur = cur->next;
        }
        return root->next;
    }
};