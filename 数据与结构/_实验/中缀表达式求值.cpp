#include <stdio.h>
#include <stdlib.h>
float Cal(char a, float b, float c) {
    switch (a) {
    case '+':
        return (b + c);
        break;
    case '-':
        return (b - c);
        break;
    case '*':
        return (b * c);
        break;
    case '/':
        return (1.0 * b / c);
        break;
    }
}
int main() {
    float Stack_num[200];//存放数字栈
    char Stack_str[100];//存放运算符栈
    int top_num = -1, top_str = -1;
    int i = 0;
    char str[200];
    char a;
    float b, c;
    printf("请输入一个要求值的中缀表达式：\n");
    scanf("%s", &str);
    while (str[i] != '\0') { // 一个字符一个字符进行扫描
        if (str[i] == '+' || str[i] == '-') { // 如果str[i]是加号或减号，那么栈顶运算符可以拿出来运算了
            if (top_str == -1) { //若栈表示没有运算符，自己是第一个，故须运算符入栈2
                Stack_str[++top_str] = str[i];
            } else {
                while (Stack_str[top_str] == '+' || Stack_str[top_str] == '-' || Stack_str[top_str] == '*' || Stack_str[top_str] == '/') {
                    a = Stack_str[top_str--];//取出一个数字
                    c = Stack_num[top_num--];//再取出一个数字
                    b = Stack_num[top_num--];//栈2顶运算符拿出来
                    Stack_num[++top_num] = Cal(a, b, c);//运算结果要入栈1
                    //printf("\n%f%c%f=%f\n", b, a, c, Stack_num[top_num]);//输出中间运算过程
                }
                Stack_str[++top_str] = str[i];//运算完了之后该运算符要入栈2
            }
        } else if (str[i] == '*' || str[i] == '/') { //如果str[i]是乘号或除号，则只有栈顶也是乘除号时才需要计算
            if (top_str == -1) {
                Stack_str[++top_str] = str[i];
            } else {
                while (Stack_str[top_str] == '*' || Stack_str[top_str] == '/') {
                    a = Stack_str[top_str--];
                    c = Stack_num[top_num--];
                    b = Stack_num[top_num--];
                    Stack_num[++top_num] = Cal(a, b, c);
                    //printf("\n%f%c%f=%f\n", b, a, c, Stack_num[top_num]);
                }
                Stack_str[++top_str] = str[i];
            }
        } else if (str[i] == '(') { //如果str[i]是左括号则直接压入栈2
            Stack_str[++top_str] = str[i];
        }
        else if (str[i] == ')') { //如果str[i]是右括号，则计算第一个左括号前的所有操作符，最后将此左括号直接弹出
            while (Stack_str[top_str] != '(') {
                a = Stack_str[top_str--];
                c = Stack_num[top_num--];
                b = Stack_num[top_num--];
                Stack_num[++top_num] = Cal(a, b, c);
                //printf("\n%f%c%f=%f\n", b, a, c, Stack_num[top_num]);
            }
            Stack_str[top_str--];//弹出
        } else { //如果str[i]不是操作符则直接数字栈
            Stack_num[++top_num] = str[i] - '0';//数字，转为整数
        }
        i++;
    }
    while (top_str != -1) { //遍历后如果栈不为空，计算剩下操作符
        a = Stack_str[top_str--];
        c = Stack_num[top_num--];
        b = Stack_num[top_num--];
        Stack_num[++top_num] = Cal(a, b, c);
        //printf("\n%f%c%f=%f\n", b, a, c, Stack_num[top_num]);
    }
    printf("该中缀表达式结果为(保留两位小数): %.2f\n", Stack_num[top_num]);
    return 0;
}

