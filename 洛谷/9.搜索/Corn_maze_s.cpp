// https://www.luogu.com.cn/problem/P1825
#include <bits/stdc++.h>
using namespace std;
const int N = 500;
char mp[N][N];
bool vis[N][N];
int n, m, startx, starty, endx, endy;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
struct point {
	int x;
	int y;
	int step;
};
queue<point> q;
void goto_another(int& x, int& y, int step) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(mp[i][j] == mp[x][y] && (i != x || j != y)) {
				x = i;
				y = j;
				return;	
			}
		}
	}
}
int main() {
    //freopen("in.in", "r", stdin);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
            cin >> mp[i][j];
			if(mp[i][j] == '@') {
				startx = i;
				starty = j;
			}
			if(mp[i][j] == '=') {
				endx = i;
				endy = j;
			}
			if(mp[i][j] == '#') {
				vis[i][j] = 1;
			}
		}
	}
	point start;
	start.x = startx;
	start.y = starty;
	start.step = 0;
	vis[startx][starty] = 1;
	q.push(start);
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		if(x == endx && y == endy) {
			cout << q.front().step << endl;
			break; 
		}
		if(mp[x][y] >= 'A' && mp[x][y] <= 'Z') {
			goto_another(x, y, q.front().step);
		}
		for(int i = 0; i < 4; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if(tx <= n && tx > 0 && ty <= m && ty > 0 && !vis[tx][ty]) {
				vis[tx][ty] = 1;
				point temp;
				temp.x = tx;
				temp.y = ty;
				temp.step = q.front().step + 1;
				q.push(temp);
			}
		}
		q.pop();
	}
	return 0;
}