class Solution {
	public:
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		vector<vector<int>> a(V);
		vector<int>indegree(V, 0);
		
		for (int i = 0; i<edges.size(); i++) {
			int src = edges[i][0];
			int dst = edges[i][1];
			a[src].push_back(dst);
			indegree[dst]++;
		}
		queue<int> q;
		for (int i = 0; i<V; i++) {
			if (indegree[i] == 0)
				q.push(i);
		}
		vector<int>res;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			res.push_back(node);
			for (int i = 0; i<a[node].size(); i++) {
				int neigh = a[node][i];
				indegree[neigh]--;
				if (indegree[neigh] == 0)
					q.push(neigh);
			}
		}
		return res;
		
	}
};
