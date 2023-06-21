// P2089 
// 暴力枚举
// 可以用队列
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct peiliao{//自定义类型peiliao作为队列的元素
    int a,b,c,d,e,f,g,h,i,j;
};
queue<peiliao>qwq;//存储容器在这里！！！！！！！

int main()
{
    int a,b,c,d,e,f,g,h,i,j,n;
    peiliao kaoji;//暂时性质的变量peiliao元素
    scanf("%d",&n);
    if (n<10||n>30)
    {//如果小于10或者是大于30，肯定做不出要求的烤鸡
        putchar('0');return 0;
    }
    for (a=1;a<=3;a++)
        for (b=1;b<=3;b++)
            for (c=1;c<=3;c++)
                for (d=1;d<=3;d++)
                    for (e=1;e<=3;e++)
                        for (f=1;f<=3;f++)
                            for (g=1;g<=3;g++)
                                for (h=1;h<=3;h++)
                                    for (i=1;i<=3;i++)
                                        for (j=1;j<=3;j++)
                                            if (a+b+c+d+e+f+g+h+i+j==n)
                                            {
                                            	kaoji=(peiliao){a,b,c,d,e,f,g,h,i,j};
                                                qwq.push(kaoji);//压入在这里！！！！！！！
                                            }
    if (qwq.empty())
    {
        putchar('0');
    }
    else
    {
        printf("%d\n",qwq.size());
        while (!qwq.empty())
        {//输出在这里！！！！！！！！
            kaoji=qwq.front();
            qwq.pop();
            cout<<kaoji.a<<' '<<kaoji.b<<' '<<kaoji.c;
            cout<<' '<<kaoji.d<<' '<<kaoji.e<<' '<<kaoji.f;
            cout<<' '<<kaoji.g<<' '<<kaoji.h<<' '<<kaoji.i;
            cout<<' '<<kaoji.j<<endl;
        }
    }
    return 0;
}