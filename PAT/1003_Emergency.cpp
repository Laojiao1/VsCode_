// Dijkstra 最短路
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Edge;
struct Node {
	int v;
	int dist;
	Node(int v, int dist) : v(v), dist(dist) {};
    bool operator< (const Node e) const {
        return dist > e.dist;
    }
};
const int N = 510;
const int inf = 2147483647;
vector<Edge> mp[N];
int team[N], road[N], maxTeam[N], disTo[N];
bool vis[N];
int main() {
    freopen("in.in", "r", stdin);
	int n, m, c1, c2;
	cin >> n >> m >> c1 >> c2;
	for(int i = 0; i < n; i++) {
		cin >> team[i];
	}
	int v, w, l;
	for(int i = 0; i < m; i++) {
		cin >> v >> w >> l;
		mp[v].push_back(Edge(w, l));
		mp[w].push_back(Edge(v, l));
	}
	fill(disTo, disTo + N, inf);
    disTo[c1] = 0;
    road[c1] = 1;
    maxTeam[c1] = team[c1];
    priority_queue<Node> q;
    q.push(Node(c1, 0));
    while(!q.empty()) {
    	int v = q.top().v;
    	q.pop();
    	if(v == c2) break;
    	vis[v] = 1;
    	vector<Edge> edges = mp[v];
    	int w, weight, cmp;
    	for(Edge e : mp[v]) {
    		w = e.first;
    		if(vis[w]) continue;
    		if(disTo[w] > e.second + disTo[v]) {
    			disTo[w] = e.second + disTo[v];
				maxTeam[w] = maxTeam[v] + team[w];
				road[w] = road[v];
				q.push(Node(w, disTo[w])); 
    		} else if(disTo[w] == e.second + disTo[v]) {
    			maxTeam[w] = max(maxTeam[w], maxTeam[v] + team[w]);
                road[w] += road[v];
    		}
    	}
    }
    printf("%d %d", road[c2], maxTeam[c2]);
	return 0;
} 

