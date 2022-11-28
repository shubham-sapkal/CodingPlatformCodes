#include <bits/stdc++.h> 
#include<unordered_map>
#include<queue>
#include<list>
#include<set>

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> edges)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    
    q.push(node);
    
    visited[node] = 1;
    
    while(!q.empty())
    {
        int frontnode = q.front();
        q.pop();
        
        // store frontNode into ans
        ans.push_back(frontnode);
        
        // traverse all neighbours of frontNode
        for(auto i : adjList[frontnode])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
        
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    
    // prepare adj list;
    prepareAdjList(adjList, edges);
    
    // traverse all component of graph
    for(int i=0; i<vertex; i++)
    {
        if(!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }
    
    return ans;
}