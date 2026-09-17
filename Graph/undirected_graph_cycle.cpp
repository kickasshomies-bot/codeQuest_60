// link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
    bool ans = false;
    void helper(int child,int parent,vector<int>&visited,unordered_map<int,vector<int>>&adj){
        queue<pair<int,int>>q; //child,parent storage system
        q.push({child,parent});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto front = q.front();
                visited[front.first] = 1;
                q.pop();
                for(auto next:adj[front.first]){
                    if(visited[next] && next != front.second)ans = true;
                    else{
                        if(!visited[next])q.push({next,front.first});
                    }
                }
            }
        }
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // for bfs it is simple as if one visited node can only be visited
        //again if there is a cycle
        ans = false;
        unordered_map<int,vector<int>>adj;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>visited(V,0);
        // queue<pair<int,int>>q;
        for(int node=0;node<V;node++){
            if(!visited[node])helper(node,-1,visited,adj);
        }
        return ans;
    }
};