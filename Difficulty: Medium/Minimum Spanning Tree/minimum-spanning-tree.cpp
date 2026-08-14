class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(int i = 0; i< edges.size(); i++){
            int src = edges[i][0];
            int dst = edges[i][1];
            int wt = edges[i][2];
            
            adj[src].push_back({wt,dst});
            adj[dst].push_back({wt,src});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> visited(V,0);
        pq.push({0,0});
        // visited[0] = 1;
        int sum = 0;
        
        while(!pq.empty()){
            auto[wt,node] = pq.top();
            pq.pop();
            
            if(visited[node]==1){
                continue;
            }
            visited[node]=1;
            sum = sum+wt;
            
            for(int i=0; i<adj[node].size();i++){
            auto[weight,neigh]= adj[node][i];
            if(visited[neigh]==0){
                pq.push({weight,neigh});
            }
            }
            
            
            
        }
        return sum;
        
    }
};