#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>>&adj_list,vector<int>&visited,int node){
    queue<int>q ;
    q.push(node);
    visited[node] =1;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int front = q.front();
            q.pop();
            visited[front] = 1; // mark popped node visited
            cout<<"current node is :"<<front<<endl;
            for(int j=0;j<adj_list[front].size();j++){
                // how will you push into the queue
                int curr_adj_node = adj_list[front][j];
                if(!visited[curr_adj_node]){
                    visited[curr_adj_node] =1;
                    q.push(curr_adj_node);
                }
            }
        }
    }
}

int main()
{
    vector<vector<int>>adj_list = {{0,3,1},{0,1,2},{1,2,3},{2,3,0}};
    //we'll start our traversal from node 0
    vector<int>visited(4,0); // 0 means the node is not visited 
    //if it is visited we'll simple turn the value to 1
    BFS(adj_list,visited,0);
}