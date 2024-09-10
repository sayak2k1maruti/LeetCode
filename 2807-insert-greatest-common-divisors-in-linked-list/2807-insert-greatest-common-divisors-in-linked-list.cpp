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
#define NUM_MAX 1000 
class Solution {
public:
    int gcdMatrix[NUM_MAX+1][NUM_MAX+1];
    Solution(){
        for(int i = 0;i < NUM_MAX+1; i++){
            for(int j = 0 ; j < NUM_MAX+1;j++){
                gcdMatrix[i][j] = -1;
            }
        }
    }
    int gcd(int a , int b){
        if (gcdMatrix[a][b] != -1)  return gcdMatrix[a][b];
        int big = max(a,b),small = min(a,b);
        if (big%small == 0){
            gcdMatrix[a][b] = small;
            gcdMatrix[b][a] = small;
            return small;
        }
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