class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1;
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<vector<int>> cells;
        //row, cols, cnt
        cells.push({0, 0, 1});
        grid[0][0] = 1;
        
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        
        while(!cells.empty()){
            int size = cells.size();
            while(size > 0){
                vector<int> tmp = cells.front();
                cells.pop();
                if(tmp[0] == rows-1 && tmp[1] == cols-1)
                    return tmp[2];
                
                for(vector<int> d : dir){
                    int row = tmp[0] + d[0];
                    int col = tmp[1] + d[1];
                    
                    if(row >= 0 && col >= 0 && row < rows && col < cols && grid[row][col] == 0){
                        cells.push({row, col, tmp[2]+1});
                        grid[row][col] = 1;
                    }
                }
                --size;
            }
        }
        return -1;
    }
};