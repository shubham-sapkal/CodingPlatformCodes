#include<unordered_map>
#include<list>
#include<queue>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  
    // create adj list
    unordered_map<int, list<int>> adjList;
    
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first -1;
        int v = edges[i].second -1;
        
        // directed graph
        adjList[u].push_back(v);
    }
    
    // find all indegrees
    vector<int> indegree(n);
    for(auto i : adjList)
    {
        for(auto j : i.second)
        {
            indegree[j]++;
        }
    }
    
    // 0 indegree valo ko push kardo 
    queue<int> q;
    for(int i=0; i<n; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    
    // do bfs 
    int count=0;
    while(!q.empty())
    {
        int frontnode = q.front();
        q.pop();
        
        // ans store
        count++;
        
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
    
    // if its valid topologial sort then count should be equal to the n 
    // if count != n, cycle is present
    return count == n ? false : true;
    
}