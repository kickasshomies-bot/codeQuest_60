// problem link
// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<int>moveX = {0,1,0,-1};
    vector<int>moveY = {1,0,-1,0};

    bool check(int n,int m, int currX, int currY){
        //we return true if it is a valid index to move on
        if(currX >=0 && currX<n && currY>=0 && currY <m)return true;
        return false;
    }
    void generator(vector<vector<int>>&visited,
int n,int m,int currX,int currY,vector<vector<int>>&image,int color){
        visited[currX][currY] = 1;
        int prevColor = image[currX][currY];
        image[currX][currY] = color;
        for(int i=0;i<4;i++){
            int newX = currX+moveX[i];
            int newY = currY+moveY[i];
            if(check(n,m,newX,newY) && !visited[newX][newY] && image[newX][newY] == prevColor){
                generator(visited,n,m,newX,newY,image,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        generator(visited,n,m,sr,sc,image,color);
        return image;
    }
};