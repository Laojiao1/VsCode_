#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int alpha = 0.75;
struct Node {
	int l, r; // 左右儿子 
	int size; // 子树大小 
	int fact; // 子树实际大小 
	int val; // 权值 
	bool exist; // 删除标记是否存在(点是否存 在) 
} t[N]; 
int idx, root, n;
vector<int> v;
void newnode(int& now, int v) {
	now = ++idx;
	t[now].val = v;
	t[now].size = t[idx].fact = 1;
	t[now].exist = true;
}
void updata(int now, int end) {
	if(!now) return;
	if(t[end].val < t[now].val) {
		updata(t[now].l, end);
	} else {
		updata(t[now].r, end);
	}
	t[now].size = t[t[now].l].size + t[t[now].r].size + 1;
}
bool imbalance(int now) {
	if(max(t[t[now].l].size, t[t[now].r].size) > t[now].size * alpha
	|| t[now].size - t[now].fact > t[now].size * 0.3) {
		return true;
	}
	return false;
}
void ldr(int now) {
	if(!now) return;
	ldr(t[now].l);
	if(t[now].exist) v.push_back(now);
	ldr(t[now].r);
}
void lift(int l, int r, int& now) {
	if(l == r) {
		now = v[l];
		t[now].l = t[now].r = 0;
		t[now].size = t[now].fact = 1;
		return;
	}
	int m = (l + r) >> 1;
	while(m && l < m && t[v[m]].val == t[v[m-1]].val) {
		m--;
	}
	now = v[m];
	if(l < m) lift(l, m-1, t[now].l);
	else t[now].l = 0;
	lift(m+1, r, t[now].r);
	t[now].size = t[t[now].l].size + t[t[now].r].size + 1;
    t[now].fact = t[t[now].l].fact + t[t[now].r].fact + 1;
}
void rebuild(int& now) {
	v.clear();
	ldr(now);
	if(v.empty()) {
		now = 0;
		return;
	}
	lift(0, v.size()-1, now);
}
void check(int& now, int end) {
	if(end == now) return;
	if(imbalance(now)) {
		rebuild(now);
		updata(root, now);
		return;
	}
	if(t[end].val < t[now].val) {
		check(t[now].l, end);
	} else {
		check(t[now].r, end);
	}
}
void insert(int& now, int val) {
	if(!now) {
		newnode(now, val);
		check(root, now);
		return;
	}
	t[now].size++;
	t[now].fact++;
	if(val < t[now].val) {
		insert(t[now].l, val);
	} else {
		insert(t[now].r, val);
	}
}
void del(int now, int val) {
	if(t[now].exist && t[now].val == val) {
		t[now].exist = false;
		t[now].fact--;
		check(root, now);
		return;
	}
	t[now].fact--;
	if(val < t[now].val) {
		del(t[now].l, val);
	} else {
		del(t[now].r, val);
	}
}
int get_rank(int val) {
	int now = root, rank = 1;
	while(now) {
		if(val <= t[now].val) {
			now = t[now].l;
		} else {
			rank += t[now].exist + t[t[now].l].fact;
			now = t[now].r;
		}
	}
	return rank;
}
int get_val(int rank) {
	int now = root;
	while(now) {
		if(t[now].exist && t[t[now].l].fact + t[now].exist == rank) {
			break;
		} else if(t[t[now].l].fact >= rank) {
			now = t[now].l;
		} else {
			rank -= t[t[now].l].fact + t[now].exist;
			now = t[now].r;
		}
	}
	return t[now].val;
}
int main() {
	scanf("%d", &n);
    while(n--) {
        int op, x;
        scanf("%d %d", &op, &x);
        if(op == 1) insert(root, x);
        if(op == 2) del(root, x);
        if(op == 3) printf("%d\n", get_rank(x));
        if(op == 4) printf("%d\n", get_val(x));
        if(op == 5) printf("%d\n", get_val(get_rank(x)-1));
        if(op == 6) printf("%d\n", get_val(get_rank(x+1)));
    }
	return 0;
} 