class Solution {
public:
    bool isRechable(vector<vector<int>> &preq,int a , int b,vector<vector<int>> &cache){
        if(cache[a][b] != -1)   return cache[a][b];
        //if( preq[a].find(b) != preq[a].end())   return cache[a][b] = true;
        for(auto c : preq[a])
            if (c==b || isRechable(preq,c,b,cache))
                return cache[a][b] = true;
        return cache[a][b] = false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> preq(numCourses,vector<int>());
        vector <bool> ans(queries.size());
        vector<vector<int>> cache(numCourses+1,vector<int>(numCourses+1,-1));
        for(auto coursePair : prerequisites){
            preq[coursePair[0]].push_back(coursePair[1]);
        }
        int indx=0;
        for(int i = 0 ; i < queries.size(); i++)    
            ans[i] = isRechable(preq,queries[i][0],queries[i][1],cache);
        return ans;
    }
};