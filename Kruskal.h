#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <utility>
#include <algorithm>
#include "UF.h"

using namespace std;

int kruskal(const int size, vector<pair<int, pair<int, int> > > &edges) {
	int cost = 0;
	sort(edges.begin(), edges.end());
	UF uf(size);
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		printf("%d %d %d\n", edges[i].first, u, v);
		if (!uf.connected(u, v)) {
			uf.merge(u, v);
			cost += edges[i].first;
		}
	}
	return cost;
}

#endif