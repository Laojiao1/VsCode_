    #include <bits/stdc++.h>
    #define MAX 7
    using namespace std;
    // 相邻数组
    int a[MAX][MAX] = {0};
    // 亮灯数组
    int b[MAX];
    // 映射数组
    int c[MAX];
    // 初始化图
    void init()
    {
        // 把每一条边看成一个结点
        // a[i][j]表示结点i与j相连
        // a b c d e f g
        // 0 1 2 3 4 5 6
        a[0][1] = 1;
        a[0][5] = 1;
        a[1][2] = 1;
        a[1][6] = 1;
        a[2][3] = 1;
        a[2][6] = 1;
        a[3][4] = 1;
        a[4][5] = 1;
        a[4][6] = 1;
        a[5][6] = 1;
    }
    // 深搜相邻的点并且关掉
    void dfs(int k)
    {
        // 把k位置关掉
        c[k] = 0;
        for (int i = 0; i < MAX; i++)
        {
            // 若i位置与k位置相连
            if (a[i][k] || a[k][i])
            {
                // 如果i位置亮着灯
                if (c[i])
                {
                    // 深搜
                    dfs(i);
                }
            }
        }
    }
    bool check()
    {
        // 数组映射
        for (int i = 0; i < MAX; i++)
        {
            c[i] = b[i];
        }
        int flag = 0;
        for (int i = 0; i < MAX; i++)
        {
            // 如果i位置亮灯
            if (c[i])
            {
                // 把他周围的灯全部灭掉
                dfs(i);
                // 连通块数+1 
                flag++;
            }
        }
        // 如果全连着
        if (flag == 1)
            return true;
        return false;
    }
    int main()
    {
        init();
        int sum = 0;
        // 可能亮1至7段
        for (int i = 0; i < MAX; i++)
        {
            // 初始化亮灯数组
            memset(b, 0, sizeof(b));
            for (int j = 7; j >= i; j--)
            {
                b[j] = 1;
            }
            do
            {
                // 如果确实是一段
                if (check())
                    sum++;
            } while (next_permutation(b, b + MAX));
        }
        cout << sum;//结果为80
    }
