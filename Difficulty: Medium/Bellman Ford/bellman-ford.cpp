class Solution {
	public:
	vector<int> bellmanFord(int V, vector<vector<int>> & edges, int src) {
		// Code here
		vector<int> res (V, 1e8);
		res[src] = 0;
		for (int i = 0; i<V - 1; i++) {
			bool changed = false;
			for (int j = 0; j<edges.size(); j++) {
				int src = edges[j][0];
				int dst = edges[j][1];
				int wt = edges[j][2];
				if (res[src] != 1e8 && res[dst]> res[src]+wt) {
					res[dst] = res[src]+wt;
					changed = true;
				}
			}
			if (!changed)
				break;
		}
		for (int j = 0; j<edges.size(); j++) {
			int src = edges[j][0];
			int dst = edges[j][1];
			int wt = edges[j][2];
			if (res[src] != 1e8 && res[dst]> res[src]+wt)
				return {-1};
			
		}
		return res;
	}
};
