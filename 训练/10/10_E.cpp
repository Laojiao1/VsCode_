#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
typedef long long ll;
int t;
char s[maxn];
int main()
{
    while(cin >> t)
    {
        while(t --)
        {
            cin >> s;
            int ans = 0;
            int len = strlen(s);
            int z = 0;
            for(int i = 0; i < len; i ++)
            {
                if(s[i] == '0')
                    z ++;
                else
                {
                    int now = i;
                    int temp = 1;
                    for(int j = 0; j < 20; j ++)
                    {
                        if(temp <= z + now - i + 1)
                            ans ++;
                        if(now + 1 >= len)
                            break;
                        now ++;
                        temp = temp * 2 + (s[now] - '0');
                    }
                    z = 0;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}


