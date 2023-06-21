// P1618 https://www.luogu.com.cn/problem/P1618
// 思路一, 逆推，把所有满足题意的数的每一位都存起来，每次循环
// 思路二，STL大法 —— next_permutation(start, end);
// 全排列函数，当当前序列不存在下一个排列时，函数返回false，否则返回true
// next_permutation(num, num+n)函数是对数组num中的前n个元素进行全排列，
// 同时并改变 num 数组的值。
// 另外，需要强调的是，next_permutation()在使用前需要对欲排列数组按升序排序
// 否则只能找出该序列之后的全排列数。
// 参考网站: https://blog.csdn.net/howardemily/article/details/68064377

// 以下是思路一代码：
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[10] = {0};
    int x, y, z, t = 0;
    scanf("%d %d %d",&x, &y, &z);
    int i, j;
    for(i = 1; i < 987; i++) {
        if(x * i <= 987) {
            a[x*i % 10] ++;
            a[x*i/10%10] ++;
            a[x*i/100] ++;
        }
        if(y * i <= 987) {
            a[y*i % 10] ++;
            a[y*i/10%10] ++;
            a[y*i/100] ++;
        }
        if(z * i <= 987) {
            a[z*i % 10] ++;
            a[z*i/10%10] ++;
            a[z*i/100] ++;
        }
        for(j = 1; j <= 9; j++)
       		if(a[j] == 0) break;
      	if(j >= 10) {
           printf("%d %d %d\n", x*i, y*i, z*i);
           t = 1;
       	}
      	for(j = 1; j <= 9; j++) a[j] = 0;
   	} 
    if(t == 0) cout << "No!!!" << endl;
    return 0;
}

// 思路二代码：
// #include <bits/stdc++.h>
// using namespace std;
// int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// int main() {
//     int A, B , C, cnt = 0;
//     cin >> A >> B >> C;
//     int t = A * B * C;
//     A = t / A;
//     B = t / B;
//     C = t / C;
//     do {
//         if((100*a[1] + 10*a[2] + a[3]) * A == (100*a[4] + 10*a[5] + a[6]) * B && 
//            (100*a[1] + 10*a[2] + a[3]) * A == (100*a[7] + 10*a[8] + a[9]) * C)//如果符合比例；
//         {
//             cout << a[1] << a[2] << a[3] << " " 
//                  << a[4] << a[5] << a[6] << " " 
//                  << a[7] << a[8] << a[9] << endl;//输出
//             cnt++;
//         }
//     } while(next_permutation(a+1, a+10));//STL中的下一个排列函数；
//     if(cnt == 0) cout << "No!!!" << endl;//没有解输出NO；
//     return 0;
// }