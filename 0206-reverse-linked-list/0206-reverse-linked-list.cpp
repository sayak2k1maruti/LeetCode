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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)    return head;
        ListNode* prev = NULL;
        ListNode* curr=head;
        ListNode* _next=head->next;
        while(_next){
            head->next=prev;
            prev = head;
            head = _next;
            _next=_next->next;
        }
        head->next=prev;
        return head;
    }
};