// 模拟
#include <bits/stdc++.h>
using namespace std;
const int N = 10001;
struct Node {
	int arrive;
	int cost;
} customers[N];
struct Window {
	int customerId;
	int popTime;
	Window(int customerId, int popTime) : customerId(customerId), popTime(popTime){};
	friend bool operator< (Window w1, Window w2) {
		return w1.popTime > w2.popTime;
	} 
};
bool cmp(Node c1, Node c2) {
	return c1.arrive < c2.arrive;
}
int main() {
    //freopen("in.in", "r", stdin);
	int n, k, count = 0, total = 0;
	int h, m, s, cost;
	int limit = 9 * 60 * 60;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		scanf("%d:%d:%d %d", &h, &m, &s, &cost);
		int t = ((h - 8) * 60 + m) * 60 + s; // 换算成s
		if(t > limit) continue;
		customers[count].arrive = t;
		customers[count].cost = cost * 60;
		count++; 
	}
	sort(customers, customers + count, cmp);
	priority_queue<Window> q;
	// 让每个窗口服务第一位客户
	int id = 0; 
	for(;id < k && id < count; id++) {
		int t = customers[id].arrive;
		if(t < 0) {
			total -= t;
			q.push(Window(id, customers[id].cost));
		} else {
			q.push(Window(id, customers[id].cost + t));
		}
	}
	if(k < count) {
		while(1) {
			Window temp = q.top();
			q.pop();
			int t = temp.popTime;
			if(id >= count) break;
			if(customers[id].arrive < t) {
				total += t - customers[id].arrive;
				q.push(Window(id, t + customers[id].cost));
			} else {
				q.push(Window(id, customers[id].arrive + customers[id].cost));
			}
			id++;
		}
	}
	printf("%.1lf", total / 60.0 / count);
	return 0;
}





