#include <bits/stdc++.h>
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
        int inHand = 0;
        ListNode *head = NULL;
        ListNode *prev = head;
        while (l1 != NULL || l2 != NULL || inHand > 0)
        {
            int a = (l1 != NULL) ? l1->val : 0;
            int b = (l2 != NULL) ? l2->val : 0;
            int sum = a + b + inHand;
            inHand = sum / 10;
            ListNode *temp = new ListNode(sum % 10);
            if (prev != NULL)
            {
                prev->next = temp;
                prev = temp;
            }
            else
            {
                prev = temp;
                head = temp;
            }
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return head;
    }
};