#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct student)

struct student
{
    long num;
    char name[20];
    int age;
    struct student*next;
};
int n;
struct student *creat(void)
{
    struct student *head;
    struct student *p1,*p2;
    n=0;
    p1=p2=(struct student *)malloc(LEN);
    scanf("%ld,%s,%d",&p1->num,&p1->name,&p1->age);
    head=NULL;
    while(p1->num!=0)
    {
        n=n+1;
        if(n==1)head=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct student *)malloc(LEN);
        scanf("%ld,%s,%d",&p1->num,&p1->name,&p1->age);
    }
    p1->next=NULL;
    return(head);
}
void add(struct student *head,long num,struct student *p,int n)
{
    int s;
    scanf("%d",&s);
    while(num!=(p->num))
    {

    }
}
void print(struct student head)
{
    struct student*p;
    *p=head;
    if(p!=NULL)
    do
    {
        printf("%ld %s %d\n",p->num,p->name,p->age);
        p=p->next;
    }while(p!=NULL);
}
int main()
{
    struct student *head;
    head=creat();
    print(*head);
    return 0;
};
