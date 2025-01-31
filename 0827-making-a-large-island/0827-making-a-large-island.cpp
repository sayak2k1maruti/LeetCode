class Solution {
public:
    int areaOfIsLand(int x, int y,int n,vector<vector<int>>& grid){
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
    }
    bool isAllOne(int n,vector<vector<int>> &grid){
        for (int i = 0 ; i < n; i++)
            for(int j = 0 ; j < n ; j++)
                if(grid[i][j]!=1)   return false;
        return true;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = INT_MIN;
        int clusterNumber = 1;
        //unordered_map<int,int>clusterAreaMap;
        vector<int> clusterAreaMap(n*n+2,0);
        if (isAllOne(n,grid)) return n*n;

        for (int i = 0 ; i < n; i++){
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
                    // for(int i = 0 ; i < n; i++){
                    //     for(int j = 0 ; j < n; j++) cout << grid[i][j] << " ";
                    //     cout <<endl;
                    // }
                    ans = max(ans,area);
                }
                //cout << endl;
            }
        }
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