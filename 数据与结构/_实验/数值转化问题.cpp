// 	数据结构定义
// 	算法设计思路简介
// 	算法描述：可以用自然语言、伪代码或流程图等方式
// 	算法的实现和测试结果：包括算法运行时的输入、输出，实验中出现的问题及解决办法等
// 	算法时间复杂度分析
#include <stdio.h>
#include <stdlib.h>
#define N 101
typedef struct {
    int data[N];
    int top;
} SeqStack;
int main() {
    int num, d, x, sum;
    printf("请输入一个十进制数字：\n");
    scanf("%d", &num);
    printf("请输入要转换的进制：\n");
    scanf("%d", &d);
    SeqStack *s;
    s = (SeqStack *) malloc (sizeof(SeqStack));
    s->top = -1; // 栈底初始化为-1
    while(num) {
        if(s->top != N-1) { // 如果没有到栈顶
            s->top++;
            s->data[s->top] = num % d;
            num /= d;
        }
    }
    printf("转化进之后结果为：\n");
    while(s->top != -1) {
        x = s->data[s->top];
        printf("%d", x);
        s->top--;
    }
    printf("\n");
    return 0;
}