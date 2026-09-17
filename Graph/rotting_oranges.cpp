// link : https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    // first we'll put all the rotten oranges into the queue
    // we'll put the index of the rotten orange into the queue
    queue<pair<int,int>>q;
    int total_good_oranges = 0;
    int moveX[4] = {0,1,0,-1};
    int moveY[4] = {1,0,-1,0};
    bool isOk(int x,int y,int n,int m){
        if(x<0 || x>=n || y<0 || y>=m)return false;
        return true;
    }
    int reached_oranges =0;
    int time =0;
    void BFS(vector<vector<int>>&grid,vector<vector<int>>&visited){
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty() && reached_oranges<total_good_oranges){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto [r,c] = q.front();
                q.pop();
                visited[r][c] = 1; // mark popped node visited
                for(int i=0;i<4;i++){
                    //first we'll check if there is orange at all
                    int newRow = r+moveX[i];
                    int newCol = c+moveY[i];
                    if(isOk(newRow,newCol,n,m)&& (grid[newRow][newCol] ==1) && !visited[newRow][newCol]){
                        visited[newRow][newCol] =1;
                        reached_oranges++;
                        q.push({newRow,newCol});
                    }
                }
            }
            time++;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        total_good_oranges = 0;
        reached_oranges =0;
        time =0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //need to check two things
                //1. if the orange is rotten put into queue
                //2. if the ornage is normal increase our total_good_oranges
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    total_good_oranges++;
                }
            }
        }
        BFS(grid,visited);
        // total_good_oranges and reached_oranges
        return total_good_oranges == reached_oranges ? time : -1;
    }
};