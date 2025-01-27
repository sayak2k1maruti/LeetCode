class Solution {
public:
    bool isReachable(vector<set<int>> &preq,int a , int b,vector<vector<int>> &cache){
        if(cache[a][b] != -1)   return (bool)cache[a][b];
        if( preq[a].find(b) != preq[a].end())   return cache[a][b] = true;
        for(auto c : preq[a])
            if (isReachable(preq,c,b,cache))
                return cache[a][b] = true;
        return cache[a][b] = false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<set<int>> preq(numCourses,set<int>());
        vector <bool> ans;
        vector<vector<int>> cache(numCourses+1,vector<int>(numCourses+1,-1));
        for(auto coursePair : prerequisites){
            preq[coursePair[0]].insert(coursePair[1]);
        }
        for (auto query : queries){
            ans.push_back(isReachable(preq,query[0],query[1],cache));
        }
        return ans;
    }
};