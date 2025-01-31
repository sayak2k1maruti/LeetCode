class Solution {
public:
    /*int areaOfIsLand(int x, int y,int n,vector<vector<int>>& grid){
        if(x<0 || y < 0 || x>=n || y>=n)    return 0;
        if(grid[x][y]!=1)   return 0;
        grid[x][y] = -1;//i.e, visited
        return 1+ 
                areaOfIsLand(x+1,y,n,grid) +
                areaOfIsLand(x-1,y,n,grid) +
                areaOfIsLand(x,y+1,n,grid) +
                areaOfIsLand(x,y-1,n,grid) ;
    }
    void updateGrid(int clusterNum,int n,vector<vector<int>>& grid){
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                if(grid[i][j]==-1)  grid[i][j] = clusterNum;
            }
        }
    }
    int getValueFromGrid(int x,int y,int n,vector<vector<int>> &grid){
        if(x>=n || y>=n || x < 0 || y < 0)  return 0;
        return grid[x][y];
    }*/
    bool isAllOne(int n,vector<vector<int>> &grid){
        for (int i = 0 ; i < n; i++)
            for(int j = 0 ; j < n ; j++)
                if(grid[i][j]!=1)   return false;
        return true;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int n = grid.size();
        int ans = INT_MIN;
        int clusterNumber = 2; //starting cluster name from 2 to avoid confusion with 1
        //unordered_map<int,int>clusterAreaMap;
        vector<int> clusterAreaMap(n*n+3,0);
        if (isAllOne(n,grid)) return n*n;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    stack<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = clusterNumber; 

                    while (!q.empty()) {
                        auto [x, y] = q.top();
                        q.pop();
                        area++;

                        for (const auto& dir : dirs) {
                            int x1 = x + dir[0];
                            int y1 = y + dir[1];
                            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && grid[x1][y1] == 1) {
                                grid[x1][y1] = clusterNumber; 
                                q.push({x1, y1});
                            }
                        }
                    }

                    clusterAreaMap[clusterNumber] = area;
                    clusterNumber++;
                }
            }
        }

        /*for (int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    int area = areaOfIsLand(i,j,n,grid);
                    
                    for (int i = 0 ; i < n ; i++){
                        for (int j = 0 ; j < n ; j++){
                            if(grid[i][j]==-1)  grid[i][j] = clusterNumber;
                        }
                    }
                    
                    clusterAreaMap[clusterNumber] = area;
                    clusterNumber++;
                    ans = max(ans,area);
                }
            }
        } */
        bool allIsland = true;
        
        for(int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0){
                    //what will be new area if we flip this zero
                    unordered_set<int> nearByClusters;
                    if (i > 0) nearByClusters.insert(grid[i - 1][j]);
                    if (i < n - 1) nearByClusters.insert(grid[i + 1][j]);
                    if (j > 0) nearByClusters.insert(grid[i][j - 1]);
                    if (j < n - 1) nearByClusters.insert(grid[i][j + 1]);
                    
                    int newArea = 1;
                    for(auto cluster : nearByClusters){
                        if(cluster > 0){
                            newArea += clusterAreaMap[cluster];
                        }
                    }

                    ans = max(ans,newArea);
                }
            }
        }
        return ans;

    }
};