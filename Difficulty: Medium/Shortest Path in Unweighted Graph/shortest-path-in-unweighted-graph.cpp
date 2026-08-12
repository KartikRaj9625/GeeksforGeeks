class Solution {
	public:
	int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
		vector<vector<int>> adj(V);
		
		for (int i = 0; i<edges.size(); i++) {
			int src = edges[i][0];
			int dst = edges[i][1];
			adj[src].push_back(dst);
			adj[dst].push_back(src);
		}
		
		vector<int>visited(V, 0);
		queue <pair<int, int>> q;
		
		q.push({src, 0});
		visited[src] = 1;
		
		while (!q.empty()) {
			auto[node, dist] = q.front();
			q.pop();
			
			if (node == dest)
				return dist ;
			
			for (int k = 0; k<adj[node].size(); k++) {
				int neigh = adj[node][k];
				if (visited[neigh] == 0) {
					q.push({neigh, dist+1});
					visited[neigh] = 1;
				}
			}
		}
		return -1;
	}
};
