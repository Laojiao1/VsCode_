#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, k;
char s[maxn];

int solve(char c) {
    int l = 0;
    int r = 0;
    int cnt = 0;
    int ans = 0;

    while (r < n) {
        if (s[r] != c)
            if (cnt >= k)
                while (s[l++] == c) {
                    continue;
                }
            else
                cnt++;
        r++;
        ans = max(ans, r - l);
    }
    return ans;
}
int main() {
    scanf("%d %d %s", &n, &k, s);
    printf("%d\n", max(solve('a'), solve('b')));
    return 0;
}