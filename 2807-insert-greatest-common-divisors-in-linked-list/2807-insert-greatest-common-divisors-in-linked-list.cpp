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
    int gcd(int a , int b){
        int big = max(a,b),small = min(a,b);
        if (big%small == 0)   return small;
        return gcd(big-small,small);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        for (ListNode* it = head;  it->next != NULL;it = it->next){
            int _gcd = gcd(it->val,it->next->val);
            ListNode* temp = it->next;
            it->next =  new ListNode(_gcd);
            it->next->next = temp;
            it = it->next;
        }
        return head;
    }
};