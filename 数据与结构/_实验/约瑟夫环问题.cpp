#include <bits/stdc++.h>
using namespace std;
typedef struct LNode {
    int code;
    int key;
    struct  LNode *next;
} LNode, *LinkList;
void CreatList(LinkList &L, int i) { // 建立有i个元素的单向循环链表
    LinkList p, s;
    L = (LinkList) malloc (sizeof(LNode));
    L->next = NULL;
    p = L;
    if(i != 0) {
        printf("请按提示输入元素\n");
    }
    for(int j = 0; j < i; j++) {
        s = (LinkList)malloc(sizeof(LNode));
        s->code = j + 1;
        printf("请输入第%d个的密码: ", j+1);
        scanf("%d", &s->key);
        p->next = s;
        p = s;
    }
    p->next = L->next;
}
void ListDelete(LinkList &L, int i, int& e) { // 删除链表L中第i个元素并输出
    LinkList p;
    for(int j = 0; L && j < i-1; j++) {
        L = L->next;
    }
    p = L->next;
    e = p->key;
    L->next = p->next;
    printf("出队人的序号为%d, 密码为%d\n", p->code, p->key);
    free(p);
}
int main() {
    LinkList L;
    int m, n, code;
    CreatList(L, 0);
    printf("请输入总人数n: ");
    scanf("%d", &n);
    printf("请输入报数上线m: ");
    scanf("%d", &m);
    CreatList(L, n);
    code = 0;
    while(L) {
        ListDelete(L, m, code);
        m = code;
    }
    return 0;
}
