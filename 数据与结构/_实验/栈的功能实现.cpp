// 程序完成如下功能：
// （1）初始化栈 s； 
// （2）判断栈 s 是否非空；
// （3）以此进栈元素 a,b,c,d,e; 
// （4）判断栈 s 是否非空；
// （5）输出栈长度；
// （6）输出从栈顶到栈底元素；
// （7）输出出栈序列；
// （8）判断栈 s 是否非空；
// （9）释放栈
#include <stdio.h>
#include <malloc.h>
#define MAX 1024
#define OK 1
#define ERROR 0
typedef struct {
    char data[MAX];
    int top;
}SqStack;
void InitStack(SqStack *&s) { // 初始化
    s = (SqStack*)malloc(sizeof(SqStack));
    s->top = -1;
}
int StackEmpty(SqStack *s) { // 判断栈是否为空
    return (s->top == -1);
}
int Push(SqStack *&s, char e) { // 进栈
    if(s->top == MAX-1) {
        return ERROR;
    }
    s->top++;
    s->data[s->top] = e;
    return OK;
}
int Pop(SqStack *&s, char& e) { // 出栈
    if(s->top == -1) {
        return ERROR;
    }
    e = s->data[s->top];
    s->top--;
    return OK;
}
int Stack_Length(SqStack *s) { // 求栈中长度
    return s->top+1;
}
int Show_Stack(SqStack *s) { // 输出从栈顶到栈底元素
    int i;
    for(int i = s->top; i >= 0; i--) {
        printf("%c ", s->data[i]);
    }
    printf("\n");
}
int Clear_Stack(SqStack *&s) {
    free(s);
}
int main() {
    SqStack *s;
    char e;
    InitStack(s); // 初始化栈
    printf("1. 初始化栈成功\n");
    printf("2. 判断栈是否为空：");
    printf("栈%s\n", (StackEmpty(s) == 1 ? "空" : "非空"));
    printf("3. 依次进栈：a, b, c, d, e\n");
    Push(s, 'a'), Push(s, 'b'), Push(s, 'c'), Push(s, 'd'), Push(s, 'e');
    printf("4. 判断栈是否为空: ");
    printf("栈%s\n", (StackEmpty(s) == 1 ? "空" : "非空"));
    printf("5. 输出栈长度：%d\n", Stack_Length(s));
    printf("6. 输出从栈顶到栈底元素："); 
    Show_Stack(s);
    printf("7. 输出出栈序列："); 
    while(!StackEmpty(s)) { 
        Pop(s, e); 
        printf("%c ",e);
    }
    printf("\n");
    printf("8. 判断栈s是否为空："); 
    printf("栈%s\n", (StackEmpty(s) == 1 ? "空" : "非空")); 
    printf("9. 释放栈\n"); 
    Clear_Stack(s); 
    printf("释放成功!\n");  
    return 0;
}