#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>&adj_list,vector<int>&visited,int node){
    visited[node] =1; // this marks the current node so it doesn't get
    //visited again to skip infinite loop
    cout<<"current node visited is: "<<node<<endl;
    int size = adj_list[node].size();
    for(int i=0;i<size;i++){
        //here you'll use i to traverse the adj list of the current node
        int curr_adj_node = adj_list[node][i];
        if(!visited[curr_adj_node]){
            //so if a node is not visited we'll make recursive calls
            //to visit that node
            DFS(adj_list,visited,curr_adj_node);
        }
    }
}

int main()
{
    vector<vector<int>>adj_list = {{0,3,1},{0,1,2},{1,2,3},{2,3,0}};
    //we'll start our traversal from node 0
    vector<int>visited(4,0); // 0 means the node is not visited 
    //if it is visited we'll simple turn the value to 1
    DFS(adj_list,visited,0);
}