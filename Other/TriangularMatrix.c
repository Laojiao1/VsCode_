#include<stdio.h>
int main()
{
	int T;//待测矩阵的个数
	scanf("%d", &T);
	int i, j, t, flag, n;
	int a[10][10];
	for (t = 1; t <= T; t++)//循环矩阵个数
	{
		flag = 1;
		scanf("%d", &n);//输入行列数
		for(i = 0; i < n; i++)//把数字填入二维数组
			for (j = 0; j < n; j++)
			{
				scanf("%d", &a[i][j]);
					if (i > j)//当行大于列时，如果元素不为0，则不是上三角矩阵
						if (a[i][j] != 0)
						{
							flag = 0;
						}
			}
		if (flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}