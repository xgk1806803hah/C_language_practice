#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct student)

struct student
{
    long num;
    float score;
    struct student *next;
};
struct student *create()
{
    struct student *p1,*p2,*head;
    int n = 0;
    head = NULL;
    p1 = p2 =(struct student *)malloc(LEN);
    printf("please input num and score.\n");
    scanf("%ld,%f",&p1->num,&p1->score);
    head=NULL;
    while(p1->num != 0)
    {
        n++;
        if(n == 1)
            head = p1;
        else p2->next = p1;
        p2 = p1;
        p1 = (struct student*)malloc(sizeof(struct student));
        scanf("%ld,%f",&p1->num,&p1->score);
    }

    p2->next = NULL;
    return head;
}
void print(struct student *head)
{
    printf("*********print************\n");
    struct student *p;
    p=head;
    if(head != NULL)
    {
        do
        {
            printf("num = %ld score = %f\n",p -> num,p -> score);
            p = p -> next;
        }
        while(p != NULL);
    }
}
struct student *delete(struct student *head,int num)
{
    printf("*********delete.************\n");
    struct student *p1,*p2;
    if(head == NULL)
    {
        printf("The List is NULL\n");
    }
    else
    {
        p1 = head;
        while(p1 -> next != NULL && p1 -> num != num)
        {
            p2 = p1;
            p1 = p1 -> next;
        }
        if(p1 -> num == num)
        {
            if(p1 == head)
                head =p1 -> next;
            else
                p2 -> next = p1 -> next;
        }
        else
            printf("Can not find list num.\n");
    }
    return head;
}
struct student *change(struct student *head,int index,int num,float score)
{
    printf("**********change.**************\n");
    struct student *p;
    if(head == NULL)
    {
        printf("The List is NULL.\n");
    }
    else
    {
        p = head;
        while(p -> next != NULL && p -> num != index)
        {
            p = p -> next;
        }
        if(p -> num == index)
        {
            p ->num = num;
            p ->score =score;
        }
        else
            printf("Can not fine list index.\n");
    }
    return head;
}
struct student *add(struct student *head,int index,int num,float score)
{
    printf("******add************.\n");
    struct student *p1,*p2,*p3;
    if(head == NULL)
    {
        printf("The List is NULL.\n");
    }
    else
    {
        p1 = p2 = head;
        while(p1 -> next != NULL && p1 -> num != index)
        {
            p1 = p1 -> next;
            p2 = p1;
        }
        if(p1 -> num ==index)
        {
            p3 = (struct student *)malloc(LEN);
            p3 -> num = num;
            p3 -> score = score;
            if(p2 -> next == NULL)
            {
                p2 -> next = p3;
                p3 -> next = NULL;
            }
            else
            {
                p3 ->next=p2->next;
                p2 ->next=p3;
            }
        }
        else
            printf("Can not find list index.\n");
        return head;
    }
}
struct student *search(struct student *head,int num)
{
    printf("**********change**************\n");
    struct student *p;
    if(head == NULL)
    {
        printf("The List is NULL.\n");
    }
    else
    {
        p = head;
        while(p -> next != NULL && p -> num != num)
        {
            p = p -> next;
        }
    }
    return p;
}

int main()
{
    int i=4,a,b,c,e,f;
    float d,g;
    struct student *head;
    head = create();
    print(head);
    printf("删除按1改分按2加人按3按0取消\n");
    while(i!=0)
    {scanf("%d",&i);
    if(i==1)
    {
        printf("请输入查询学号:");
        scanf("%d",&a);
        delete(head,a);
        print(head);
    }
        else if(i==2)
             {
                 printf("请输入查询学号,修改后信息:");
                 scanf("%d,%d,%.2f",&b,&c,&d);
                 change(head,b,c,d);
                 print(head);
             }
             else if(i==3)
                {
                    printf("请输入查询学号,新增信息:");
                    scanf("%d,%d,%.2f",&e,&f,&g);
                    add(head,e,f,g);
                    print(head);
                }
    }
    return 0;
}
