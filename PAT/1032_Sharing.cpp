// 考察链表
#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int main() {
    int next[N], sorted1[N], sorted2[N], l1 = 0, l2 = 0;
    int S1, S2, n;
    cin >> S1 >> S2 >> n;
    for(int i = 0; i < n; i++) {
        int address;
        scanf("%d ", &address);
        getchar();// 数值用不到，直接吞掉即可
        scanf("%d", &next[address]);
    }
    for(int i = S1; i != -1; i = next[i]) {
        sorted1[l1++] = i;
    }
    for(int i = S2; i != -1; i = next[i]) {
        sorted2[l2++] = i;
    }
    int i = 0, j = 0;
    if(l1 > l2) {
        i += l1 - l2;
    } else {
        j += l2 - l1;
    }
    while(i < l1 && j < l2 && sorted1[i] != sorted2[j]) {
        i++;
        j++;
    }
    if(i < l1 && j < l2 && sorted1[i] == sorted2[j]) {
        printf("%05d", sorted1[i]);
    } else {
        cout << "-1" << endl;
    }
    return 0;
}