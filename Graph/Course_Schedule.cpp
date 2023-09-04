

class Solution:
{
public:
    vector<int> findOrder(int V, int m, vector<vector<int, int>> &prerequisites)
    {
        vector<int> adj[V];
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        // TopoSOrt
        int V = adj.size();
        int indegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        } 

        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]] == 0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);
            // node is in your topo sort
            // so please remove it from the indegree array
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if(topo.size() == N) return topo;
       return {};
    }
};