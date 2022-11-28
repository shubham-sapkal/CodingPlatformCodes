#include<unordered_map>
#include<list>

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    dfsVisited[node] = true;
    
    for(auto i : adjList[node])
    {
        if(!visited[i])
        {
            bool cycleDetected = checkCycleDFS(i, visited, dfsVisited, adjList);
            if(cycleDetected)
                return true;
        }
        else if(dfsVisited[i]){
            // visited true
            return true;
        }
    }
    
    // backtrack
    dfsVisited[node] = false;
    
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
 
     // prepare adj list
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].push_back(v);
    }
    
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    
    // call dfs for all componenets
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adjList);
                if(cycleFound)
                    return true;
        }
    }
    
    return false;
 
}