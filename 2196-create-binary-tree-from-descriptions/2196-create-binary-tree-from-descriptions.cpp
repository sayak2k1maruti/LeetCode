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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*> nodeLoc;
        map<int,bool> isParentNode;
        for(int i = 0; i < descriptions.size();i++){
            for (int j = 0 ; j < 2;j++){
                if(isParentNode.find(descriptions[i][j]) == isParentNode.end()) isParentNode[descriptions[i][j]]= true;   
            }
        }
        for(int i = 0; i < descriptions.size();i++){
            TreeNode* parent =  nodeLoc.find(descriptions[i][0]) != nodeLoc.end() ?   
                                    nodeLoc[descriptions[i][0]] :  new TreeNode(descriptions[i][0]);
            TreeNode* child = nodeLoc.find(descriptions[i][1]) != nodeLoc.end() ?   
                                    nodeLoc[descriptions[i][1]] :  new TreeNode(descriptions[i][1]);
            nodeLoc[descriptions[i][0]] = parent;
            nodeLoc[descriptions[i][1]] = child;
            if (descriptions[i][2]) parent->left = child;
            else parent->right = child;
            isParentNode[descriptions[i][1]] = false;
        }
        for (auto i : isParentNode){
            if (i.second)      return nodeLoc[i.first];
        }
        return NULL;
    }
};