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
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* temp=NULL,*prev = NULL;
        while(head->next){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        if(head)    head->next = prev;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head,*prevPrev=NULL,*ans = NULL;
        vector<pair<ListNode*,ListNode*>> lists;
        while(curr){
            ListNode* first = curr,*prev=curr;
            int n = k;
            for( ;curr && n ; curr = curr->next)  {n--;prev=curr;}
            prev->next = NULL;
            if(!n){
                ListNode* temp = reverseLinkedList(first);
                if(!ans) ans = temp;
                if(prevPrev)    prevPrev->next = temp;
                for(prev=temp;prev->next;prev=prev->next);
                prevPrev = prev;
            }else{
                if(prevPrev)    prevPrev->next = first;
                else return first;
            }
        }
        return ans;
    }
};