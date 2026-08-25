// question link
// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution {
  public:
    vector<int>moveX = {0,1,0,-1};
    vector<int>moveY = {1,0,-1,0};
    vector<string>dir = {"R","D","L","U"};

    bool check(int n,int m, int currX, int currY){
        //we return true if it is a valid index to move on
        if(currX >=0 && currX<n && currY>=0 && currY <m)return true;
        return false;
    }

    void generator(vector<vector<int>>&visited,string currPath,vector<string>&ans,
    int n,int m,int currX,int currY,vector<vector<int>>&maze){
        if(currX == n-1 && currY == m-1){
            //we have already reached our destination
            ans.push_back(currPath);
            return;
        }
        visited[currX][currY] = 1;
        for(int i=0;i<4;i++){
            int newX = currX+moveX[i];
            int newY = currY+moveY[i];
            if(check(n,m,newX,newY) && !visited[newX][newY] && maze[currX][currY]!=0){
                generator(visited,currPath+dir[i],ans,n,m,newX,newY,maze);
            }
        }
        visited[currX][currY]= 0;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0)); // 0 denotes node is not
        //visited and 1 means visited
        vector<string>ans;
        generator(visited,"",ans,n,m,0,0,maze); // as we are starting from origin
        sort(ans.begin(),ans.end());
        return ans;
    }
};