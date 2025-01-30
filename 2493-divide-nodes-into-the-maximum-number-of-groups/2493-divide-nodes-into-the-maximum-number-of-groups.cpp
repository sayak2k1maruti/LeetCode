class Solution {
public:
    bool BFS(int node, vector<vector<int>> &graph, vector<int> &layerMapping, unordered_map<int, int> &maxLayerMap) {
        queue<int> q;
        int totalNumOfLayer = 1;
        int minNumber = node;

        layerMapping[node] = 1;
        q.push(node);
        
        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            minNumber = min(minNumber, currNode);
            int currLayer = layerMapping[currNode];
            for (auto connectedNode : graph[currNode]) {
                if (layerMapping[connectedNode] != 0) {
                    if (abs(layerMapping[connectedNode] - layerMapping[currNode]) != 1) {
                        return false;
                    }
                } else {
                    q.push(connectedNode);
                    layerMapping[connectedNode] = currLayer + 1;
                    totalNumOfLayer = max(layerMapping[connectedNode], totalNumOfLayer);
                }
            }
        }
        maxLayerMap[minNumber] = max(maxLayerMap[minNumber], totalNumOfLayer);
        return true;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_map<int, int> maxLayerMap;
        vector<int> layerMapping(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            if (layerMapping[i] == 0) {
                if (!BFS(i, graph, layerMapping, maxLayerMap)) {
                    return -1;
                }
            }
        }

        int ans = 0;
        for (auto &it : maxLayerMap) {
            ans += it.second;
        }

        return ans;
    }
};