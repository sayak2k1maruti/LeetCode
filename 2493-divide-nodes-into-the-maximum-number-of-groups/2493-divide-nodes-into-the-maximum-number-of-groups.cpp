class Solution {
public:
    bool BFS(int node,vector<vector<int>> &graph,unordered_map<int,int> &maxLayerMap){
        queue <int> q;
        unordered_map<int,int> layerMapping;
        int totalNumOfLayer = 1;
        int minNumber = INT_MAX;

        layerMapping[node] = 1;
        q.push(node);
        
        while (!q.empty()){
            int currNode = q.front();
            q.pop();
            minNumber = min(minNumber,currNode);
            int currLayer = layerMapping[currNode];
            for(auto connectedNode : graph[currNode]){
                if(layerMapping.find(connectedNode)!=layerMapping.end()){
                    if(abs(layerMapping[connectedNode]-layerMapping[currNode])!=1)   return false;
                }else{
                    q.push(connectedNode);
                    layerMapping[connectedNode] = currLayer + 1;
                    totalNumOfLayer = max(layerMapping[connectedNode],totalNumOfLayer);
                }
            }
        }
        maxLayerMap[minNumber] = max(maxLayerMap[minNumber],totalNumOfLayer);
        return true;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n+1,vector<int>());
        for(auto i : edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        unordered_map<int,int> maxLayer;
        for (int i =1 ; i <= n ; i++){
            if (!BFS(i,graph,maxLayer))  return -1;
        }
        int ans = 0;
        for(auto it : maxLayer){
            ans += it.second;
        }
        return ans;
    }
};