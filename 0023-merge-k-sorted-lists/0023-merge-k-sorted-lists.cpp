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
    ListNode* merge2List(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        else if(!l2)    return l1;
        else if(l1 && l2){
            if(l1->val < l2->val){
                l1->next = merge2List(l1->next,l2);
                return l1;
            }else{
                l2->next = merge2List(l1,l2->next);
                return l2;
            }
        }
        return NULL;
    }
    ListNode* _mergeKLists(vector<ListNode*>& lists,int begin,int end){
        if(begin > end)
            return NULL;
        else if(begin == end)
            return lists[begin];
        return merge2List(_mergeKLists(lists,begin,(begin+end)/2),_mergeKLists(lists,(begin+end)/2+1,end));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return _mergeKLists(lists,0,lists.size()-1);
    }
};