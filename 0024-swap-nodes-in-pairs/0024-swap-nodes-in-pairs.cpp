/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* next = NULL;
        if(! head)  return NULL;
        next = head->next;
        if(! next)  return head;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};