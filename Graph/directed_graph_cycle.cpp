// link : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
    bool check(vector<vector<int>>&adj_list,vector<int>&visited,unordered_set<int>&s,int node){
        visited[node] =1;
        bool curr = false;
        for(auto it:adj_list[node]){
            if(!visited[it]){
                s.insert(it);
                curr |= check(adj_list,visited,s,it);
            }//process
            else{
                if(s.find(it)!=s.end()){
                    //already in set then we'll return true
                    return true;
                }
            }
        }
        s.erase(node);
        return curr;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        //mental map -> 1. build adj list
        //2. build two containers for visited and curr path
        //if same node found return true
        vector<vector<int>>adj_list(V);
        vector<int>visited(V,0);
        for(auto it:edges){
            adj_list[it[0]].push_back(it[1]);
        }
        bool ans = false;
        for(int i=0;i<V;i++){
            unordered_set<int>s;
            s.insert(i);
            ans |=check(adj_list,visited,s,i);
        }
        return ans;
    }
};