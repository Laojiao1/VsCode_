#include <bits/stdc++.h>

using namespace std;
#define int long long
const int m = 998244353;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;

        int n = log2(r / l) + 1;
        if (n == 1)
        {
            cout << 1 << " " << r - l + 1 << endl;
            continue;
        }
        int ans = 0;
        int x = 1 << (n - 1);
        ans = (r / x - l + 1) % m;
        
            x = x / 2 * 3;
            if (r/x >= l)
        {
            ans += ((r / x - l + 1) % m * (n - 1) % m) % m;
        }

        cout << n << " " << ans << endl;
    }

    return 0;
}
