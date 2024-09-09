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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> arr(m,vector<int>(n,-1));

        int left=0,right=n-1;
        int up=0,down=m-1;
        
        while(down>=up && right>=left && head!=NULL){

            for(int i=left;i<=right && head!=NULL;i++,head=head->next)    
                arr[up][i] = head->val;
            for(int i=up+1;i<=down-1 && head!=NULL;i++,head=head->next)   
                arr[i][right] = head->val;
            for(int i=right;i>=left && head!=NULL;i--,head=head->next)
                arr[down][i] = head->val;
            for(int i=down-1;i>=up+1 && head!=NULL;i--,head=head->next)
                arr[i][left] = head->val;
            up++;left++;
            down--;right--;
        }

        return arr;
    }
};