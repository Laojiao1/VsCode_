#include <stdio.h>
#include <stdlib.h>
#define keyType int
typedef struct {
    keyType key;//���ұ���ÿ������Ԫ�ص�ֵ
    //�����Ҫ��������������������
}ElemType;

typedef struct{
    ElemType *elem;//��Ų��ұ�������Ԫ�ص�����
    int length;//��¼���ұ������ݵ�������
}SSTable;
//�������ұ�
void Create(SSTable **st){
    printf("������е�����Ԫ�ظ�����\n");
    int length;
    scanf("%d", &length);
    (*st)=(SSTable*)malloc(sizeof(SSTable));
    (*st)->length=length;
    (*st)->elem =(ElemType*)malloc((length+1)*sizeof(ElemType));
    printf("������е�����Ԫ�أ�\n");
    //���ݲ��ұ�������Ԫ�ص��ܳ��ȣ��ڴ洢ʱ���������±�Ϊ 1 �Ŀռ俪ʼ�洢����
    for (int i=1; i<=length; i++) {
        scanf("%d",&((*st)->elem[i].key));
    }
}
//���ұ����ҵĹ��ܺ���������keyΪ�ؼ���
int Search_seq(SSTable *st,keyType key){
    st->elem[0].key=key;//���ؼ�����Ϊһ������Ԫ�ش�ŵ����ұ��ĵ�һ��λ�ã�������ڵ�����
    int i=st->length;
    //�Ӳ��ұ������һ������Ԫ�����α�����һֱ�����������±�Ϊ0
    while (st->elem[i].key!=key) {
        i--;
    }
    //��� i=0��˵������ʧ�ܣ���֮�����ص��Ǻ��йؼ���key������Ԫ���ڲ��ұ��е�λ��
    return i;
}
int main(int argc, const char * argv[]) {
    SSTable *st;
    Create(&st);
    getchar();
    printf("������������ݵĹؼ��֣�\n");
    int key;
    scanf("%d",&key);
    int location=Search_seq(st, key);
    if (location==0) {
        printf("����ʧ��");
    }else{
        printf("�����ڲ��ұ��е�λ��Ϊ��%d",location);
    }
    return 0;
}