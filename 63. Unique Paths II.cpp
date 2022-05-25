class Solution {
public:
    int DFS(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>> &dp,int m ,int n){
        if(i < 0 || j < 0 || i >= m || j >= n || obstacleGrid[i][j] == 1) return 0;
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(i == m-1 && j == n-1){    
            return 1;
        }           
           
        return dp[i][j] = dfs(obstacleGrid,i,j+1,dp,m,n)+dfs(obstacleGrid,i+1,j,dp,m,n);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m=obstacleGrid.size();     
        int n=obstacleGrid[0].size();   
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return DFS(obstacleGrid,0,0,dp,m,n);   
    }
};