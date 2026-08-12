class Solution {
	public:
	vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
		vector<vector<pair<int, int>> > adj(V);
		for (int i = 0; i<edges.size(); i++) {
			int src = edges[i][0];
			int dst = edges[i][1];
			int w = edges[i][2];
			adj[src].push_back({dst, w});
			adj[dst].push_back({src, w});
		}
		
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		vector<int>shortdist(V,INT_MAX);
		
		shortdist[src]=0;
		pq.push({0,src});
		
		while(!pq.empty()){
		    auto[dist,node] = pq.top();
		    pq.pop();
		    
		    if(dist>shortdist[node])
		    continue;
		    
		    for(int i = 0;i<adj[node].size(); i++){
		        int neigh = adj[node][i].first;
		        int w = adj[node][i].second;
		        
		        if(dist+w<shortdist[neigh]){
		            shortdist[neigh] = dist+w;
		            pq.push({dist+w,neigh});
		        }
		    }
		}
		return shortdist;
	}
};
