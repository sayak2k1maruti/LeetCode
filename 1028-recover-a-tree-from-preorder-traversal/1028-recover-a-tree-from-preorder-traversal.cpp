/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countD(string &s,int &i){
        int count = 0; 
        for(;s[i]=='-';i++) count++;
        return count;
    }
    int readNum(string &s,int &i){
        int num = 0, n = s.length();
        for(;i < n && s[i] != '-'; i++) num = num*10 + (s[i] - '0');
        return num;
    }
    TreeNode* recoverFromPreorder(string s) {
        stack <TreeNode*> st;
        int i = 0;
        TreeNode* root = new TreeNode(readNum(s,i));
        st.push(root);
        int n = s.length();
        int currDepth = 1;
        while( i < n){
            int depth = countD(s,i);

            int val = readNum(s,i);
            TreeNode* curr = new TreeNode(val);

            for(int x = 0 ; x < currDepth-depth; x++)   st.pop();
            TreeNode* t = st.top();
            
            if(t->left == NULL) t-> left = curr;
            else t -> right = curr;
            st.push(curr);
            currDepth = depth+1;
        }
        return root;
    }
};