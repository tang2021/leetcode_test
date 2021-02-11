//63. 不同路径 II
//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
//网格中的障碍物和空位置分别用 1 和 0 来表示。
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n=obstacleGrid.size();
    int m=obstacleGrid[0].size();
    if(n<1||m<1)return 0;
    if(obstacleGrid[0][0]==1)return 0;
    if(n<2||m<2){
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    if(obstacleGrid[i][j]==1)return 0;
    return 1;
    }
    obstacleGrid[0][0]=1;
    for(int i=1;i<n;i++){
        if(obstacleGrid[i][0]==1||obstacleGrid[i-1][0]==0)obstacleGrid[i][0]=0;
        else obstacleGrid[i][0]=1;
    }
    for(int j=1;j<m;j++){
        if(obstacleGrid[0][j]==1||obstacleGrid[0][j-1]==0)obstacleGrid[0][j]=0;
        else obstacleGrid[0][j]=1;
    }

    for(int i=1;i<n;i++)
    for(int j=1;j<m;j++){
        if(obstacleGrid[i][j]==1)obstacleGrid[i][j]=0;
        else obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
    }

    return obstacleGrid[n-1][m-1];

}