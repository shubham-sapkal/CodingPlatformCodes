#include<unordered_map>
#include<list>
#include<queue>

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    unordered_map<int, int> parent;
    
    parent[src] = -1;
    visited[src] = true;
    
    queue<int> q;
    q.push(src);
    
    while(!q.empty())
    {
        int frontnode = q.front();
        q.pop();
        
        for(auto neighbour : adjList[frontnode])
        {
            if(visited[neighbour] == true && neighbour != parent[frontnode] )
            {
                return true;
            }
            else{
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontnode;
                }
            }
        }
    }
    
    return false;
}

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    
    for(auto i : adjList[node])
    {
        if(!visited[i])
        {
            bool isCycleDetected = isCyclicDFS(i, node, visited, adjList);
            if(isCycleDetected){
                return true;
            }
            
        }
        else if(i != parent){
            // cycle present
            return true;
        }
    }
    
    return false;
} 

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // prepare adj list
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    // to handle disconnected component
    unordered_map<int, bool> visited;
    for(int i=0; i<n; i++)
    {
        if(!visited[i]){
            bool ans = isCyclicDFS(i, -1, visited, adjList);
            if(ans == true){
                return "Yes";
            }
        }
    }
    
    return "No";
}
