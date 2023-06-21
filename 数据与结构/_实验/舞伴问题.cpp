// 	数据结构定义
// 	算法设计思路简介
// 	算法描述：可以用自然语言、伪代码或流程图等方式
// 	算法的实现和测试结果：包括算法运行时的输入、输出，实验中出现的问题及解决办法等
// 	算法时间复杂度分析
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100    //队列可能达到的最大长度
#define OK  1
#define ERROR  0
#define OVERFLOW -2

typedef struct {
	char name[20]; //姓名
	char sex; //性别，'F'表示女性，'M'表示男性
}Person;

typedef struct {
	Person* base; //队列中数据元素类型为Person
	int front; //头指针
	int rear;  //尾指针
}SqQueue;

int InitQueue(SqQueue* Q);//构造一个空队列Q
int Push_back(SqQueue* Q, Person e);//插入元素e为Q的新的队尾元素
int Pop_front(SqQueue* Q, Person* e);//删除Q的队头元素，用e返回其值
Person GetHead(SqQueue Q);//返回Q的队头元素，不修改队头指针
int QueueEmpty(SqQueue Q);//判断队列是否为空，空则返回1
void DancePartner(Person dancer[], int num);//舞伴问题匹配算法

int InitQueue(SqQueue* Q) {
	Q->base = (Person*)malloc(MAXSIZE * sizeof(Person));
	if (!Q->base) exit(OVERFLOW);//存储分配失败
	Q->front = Q->rear = 0;//头指针和尾指针置为零、队列为空
	return OK;
}
int Push_back(SqQueue* Q, Person e) { 
	if ((Q->rear + 1) % MAXSIZE == Q->front)//尾指针在循环意义上加1后等于头指针，表明队满
		return ERROR;
	Q->base[Q->rear] = e;//新元素插入队尾
	Q->rear = (Q->rear + 1) % MAXSIZE;//队尾指针加1
	return OK;
}
int Pop_front(SqQueue* Q, Person* e) {
	if (Q->front == Q->rear) return ERROR; //队空
	*e = Q->base[Q->front]; //保存队头元素
	Q->front = (Q->front + 1) % MAXSIZE; //队头指针加1
	return OK;
}
Person GetHead(SqQueue Q) {
	if (Q.front != Q.rear) //队列非空
		return Q.base[Q.front]; //返回队头元素的值，队头指针不变
}
int QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear) return OK;//队列空，返回1
	else return ERROR;//队列不空，返回0
}
void DancePartner(Person dancer[], int num) { //结构数组dancer中存放跳舞的男女，num是跳舞的人数。
	SqQueue Mdancers, Fdancers;
	Person p;
	int i;
	InitQueue(&Mdancers); //男士队列初始化
	InitQueue(&Fdancers); //女士队列初始化
	for (i = 0; i < num; i++) //依次将跳舞者根据其性别人队
	{
		p = dancer[i];
		if (p.sex == 'F') Push_back(&Fdancers, p); //插入女队
		else Push_back(&Mdancers, p); //插人男队
	}
	printf("The dancing partners are:\n");
	while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers))
	{//依次输出男女舞伴的姓名
		Pop_front(&Fdancers, &p); //女士出队
		printf("%s ", p.name);; //输出出队女士姓名
		Pop_front(&Mdancers, &p); //男士出队
		printf("%s\n", p.name); //输出出队男士姓名
	}
	if (!QueueEmpty(Fdancers)) //女士队列非空，输出队头女士的姓名
	{
		p = GetHead(Fdancers); //取女士队头
		printf("The first woman to get a partner is: %s\n", p.name);
	}
	else if (!QueueEmpty(Mdancers)) //男士队列非空，输出队头男士的姓名
	{
		p = GetHead(Mdancers); //取男士队头
		printf("The first man to get a partner is: %s\n", p.name);
	}
}
int main() {
	Person dancer[MAXSIZE];int i, num;
	printf("请输入跳舞总人数：");
	scanf("%d", &num);
	printf("请输入各个跳舞人的姓名和性别('F'表示女性，'M'表示男性):\n");
	for (i = 0;i < num;i++) {
		printf("请输入第%d个跳舞人的姓名和性别(用空格隔开): ", i + 1);
		scanf("%s %c", &dancer[i].name, &dancer[i].sex);
	}
	DancePartner(dancer, num);
	return 0;
}