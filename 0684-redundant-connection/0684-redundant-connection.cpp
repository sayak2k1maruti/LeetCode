class Solution {
public:
    int findUnionParent(int edge,vector<int> & parent){
        if(parent[edge] == edge)    return edge;
        return findUnionParent(parent[edge],parent);
    }

    bool makeUnion(int edge1,int edge2, vector<int> &parent){
        int parent1 = findUnionParent(edge1,parent);
        int parent2 = findUnionParent(edge2,parent);
        if (parent1 == parent2) return false; //i.e, it's a loop
        parent[parent2] = parent1;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector <int> parent(edges.size()+1);
        for(int i = 0; i < parent.size(); i++) parent[i] = i;
        for (auto edge : edges){
            if (!makeUnion(edge[0],edge[1],parent)) return edge;}

        return edges[edges.size()-1];
    }
};