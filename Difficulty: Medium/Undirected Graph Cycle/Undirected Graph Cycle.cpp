class Solution {
	public:
	bool cycle = false;
	void dfs (vector<vector<int>> &a, int node, int parent, vector<int> & visited) {
		visited[node] = 1;
		
		for (int j = 0; j<a[node].size(); j++) {
			int neigh = a[node][j];
			if (visited[neigh] == 1 && neigh != parent)
				cycle = true;
			if (visited[neigh] == 0)
				dfs(a, neigh, node, visited);
		}
		return;
	}
	
	bool isCycle(int V, vector<vector<int>> & edges) {
		// Code here
		vector<vector<int>> a(V);
		for (int i = 0; i<edges.size(); i++) {
			int src = edges[i][0];
			int dst = edges[i][1];
			a[src].push_back(dst);
			a[dst].push_back(src);
		}
		vector<int>visited(V, 0);
		
		for (int i = 0; i<V; i++) {
			if (visited [i] == 0)
				dfs(a, i, -1, visited);
		}
		return cycle;
	}
};
