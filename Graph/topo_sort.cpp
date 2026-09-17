// link : https://www.naukri.com/code360/problems/topological-sort_982938?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

vector<int> topo(vector<vector<int>>&adj_list,unordered_map<int,int>&mp){
    queue<int>q;
    vector<int>ans;
    // our map has elements in this order -> 2 -> 1
    for(auto it:mp){
        if(it.second==0)q.push(it.first);
    }
    while(!q.empty()){
        int curr_node = q.front();
        q.pop();
        ans.push_back(curr_node);
        for(auto it:adj_list[curr_node]){
            mp[it]--; //this simply can be used to remove edges
            if(mp[it]==0)q.push(it);
        }
    }
    return ans;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    //first we need to convert the edges to adjcency list
    // we also can calculate the indegress of the nodes
    // [[0,1], [0,2]]
    //first we'll set all nodes to indegree 0
    unordered_map<int,int>mp;
    vector<vector<int>>adj_list(v);

    //iterate through all the edges and build our adjacency list and
    // also process elements for their in degree
    for(int i=0;i<v;i++)mp[i]=0;
    for(auto it:edges){
        // [0,1]
        adj_list[it[0]].push_back(it[1]);
        mp[it[1]]++;
    }
    vector<int>ans = topo(adj_list,mp);
    return ans;
}