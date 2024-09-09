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
        int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        int i = 0 , j = 0, di = 0;
        while(head != NULL){
            arr[i][j] = head->val;
            int _i,_j;
            _i = directions[di][0] + i;
            _j = directions[di][1] + j;
            if (_j < 0  || _i < 0 || _i>=m || _j >=n || arr[_i][_j]!=-1){
                di = (di+1)%4;
            }
            i = directions[di][0] + i;
            j = directions[di][1] + j;
            head = head->next;
        }
        return arr;
    }
};