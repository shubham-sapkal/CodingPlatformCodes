#include <bits/stdc++.h> 
#include<unordered_map>
#include<queue>
#include<list>


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create adj list
    unordered_map<int, list<int>> adjList;
    
    for(int i=0; i<e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        // directed graph
        adjList[u].push_back(v);
    }
    
    // find all indegrees
    vector<int> indegree(v);
    for(auto i : adjList)
    {
        for(auto j : i.second)
        {
            indegree[j]++;
        }
    }
    
    // 0 indegree valo ko push kardo 
    queue<int> q;
    for(int i=0; i<v; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    
    // do bfs 
    vector<int> ans;
    while(!q.empty())
    {
        int frontnode = q.front();
        q.pop();
        
        // ans store
        ans.push_back(frontnode);
        
        // neighbour indegree updae
        for(auto neighbour : adjList[frontnode])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0 )
            {
                q.push(neighbour);
            }
        }
    }
    
    
    
    return ans;
}