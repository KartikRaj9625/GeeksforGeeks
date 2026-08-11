class Solution {
	public:
	bool cycle = false;
	void dfs(vector<vector<int>> & a, int node, vector<bool>& path, vector<bool>& visited) {
		visited[node] = 1;
		path[node] = 1;
		
		for (int i = 0; i<a[node].size(); i++) {
			int neigh = a[node][i];
			if (visited[neigh] == 1 && path[neigh] == 1) {
				cycle = true;
				return;
			}
			if (visited[neigh] == 0)
				dfs (a, neigh, path, visited);
		}
		path[node] = 0;
		return;
	}
	bool isCyclic(int V, vector<vector<int>> &edges) {
		// code here
		vector<vector<int>> a(V);
		
		for (int i = 0; i<edges.size(); i++) {
			int src = edges[i][0];
			int dst = edges[i][1];
			a[src].push_back(dst);
		}
		vector<bool> visited(V, 0);
		vector<bool> path(V, 0);
		
		for (int i = 0; i<V; i++) {
			if (visited[i] == 0)
				dfs(a, i, path, visited);
		}
		return cycle;
	}
};
