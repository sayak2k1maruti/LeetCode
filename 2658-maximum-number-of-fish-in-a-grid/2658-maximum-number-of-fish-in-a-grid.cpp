class Solution {
public:
    int catchMaxFish(vector<vector<int>> &grid,int r,int c){
        if(r<0 || c <0 || r >= grid.size() || c >=grid[0].size())  return 0;
        int totalFish = grid[r][c];
        grid[r][c] = -1;//i.e, this cell is already visited in this search
        if(totalFish <= 0) return 0;

        int ans= totalFish + 
                catchMaxFish(grid,r,c+1) +
                catchMaxFish(grid,r,c-1) +
                catchMaxFish(grid,r+1,c) +
                catchMaxFish(grid,r-1,c) ;
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int fish = 0;
        for(int r = 0 ; r < grid.size(); r++)
            for(int c = 0 ; c < grid[0].size();c++)
                fish = max(fish,catchMaxFish(grid,r,c));
        return fish;
    }
};