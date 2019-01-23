
//单向循环链表
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
    struct Node* next;
}LNode,*LinkList;

void monkey(int n,int m)
{
    LinkList p=NULL,x =NULL,list=NULL;
    int i;

	for(i=1;i<=n;i++)
    {
        p=(LNode*)malloc(sizeof(LNode));    //向系统申请内存

        if (p==NULL)
		{                               //确保指针使用前为非空指针，当p为空指针时结束程序
            printf("分配失败!");
            exit(1);
        }
        p->data=i;//编号

        if(list==NULL)
            list=p;
        else
            x->next=p;                  //将x和p节点串起来
            x=p;                        //x指针后移
    }

    p->next=list;                       //建立一个循环链表
    p=list;                             //p指针后移

    while(p->next!=p)
    {
        for(i=1;i<m;i++)
        {
            x=p;
            p=p->next;
        }                               //p指向第m个结点，x指向第m-1个结点
        x->next=p->next;                //删除第m个结点

        free(p);                        //释放被删除结点的空间
        p=x->next;                      //p指向新的出发点
    }

    printf("当选为猴子大王的为\n%d号\n", p->data);   //输出最后那个结点的编号
    free(p);
}

int main()
{
    int m,k,n;

    printf("请输入猴子的个数:\n");
    scanf("%d",&n);

    printf("请输入数到的个数:\n");
    scanf("%d",&m);

    monkey(n, m);
}