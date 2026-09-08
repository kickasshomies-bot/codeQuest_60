// link : https://leetcode.com/problems/number-of-provinces/

//fully working code
class Solution {
public:
    void DFS(vector<vector<int>>& isCon,vector<int>&visited,int node){
        //if we visit a node we'll mark it visited then
        //from there we'll go to the adjacent nodes
        visited[node] = 1;
        int n = isCon.size();
        for(int i=0;i<n;i++){
            if(!visited[i] && isCon[node][i]==1){
                DFS(isCon,visited,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isCon) {
        //DFS -> 
        //1. visited array (too keep track of nodes that are
        //already visited)
        // DFS function call
        int n = isCon.size(); // our adjacency matrix is
        //always nxn so extract number of nodes here
        vector<int>visited(n+1,0); // here you mark all the nodes
        //starting as not visited
        int ans = 0;
        for(int i=0;i<n;i++){
            //what to check here??
            if(!visited[i]){
                DFS(isCon,visited,i);
                ans++;
            }
        }
        return ans;
    }
};