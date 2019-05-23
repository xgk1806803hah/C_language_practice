#include<stdio.h>
#include<malloc.h>

#define 线性表的最大长度

typedef struct{
    声明表的储存空间;
    int last;
}sqlist,*sqlink;

创空表;

置空表 ;

取表元素 ;

求表长 ;

插入元素 ;

删除元素 ;

定位元素 ;

判空表 ;

打印表元素 ;

int main(){



    一堆用来测试的东西;







    return 0;
}

创空表(sqlink L){
    int tempNo = 1;
    int tempData = 0;
    do{
        printf("请输入顺序表第%d个元素：",tempNo);
        scanf("%d",&tempData);
        if(tempData!=-1){
            L->data[tempNo-1] = tempData;
            L->last = tempNo-1;
            tempNo++;
        }
    }while(tempNo<=maxsize&&tempData!=-1);
}
打印表元素(sqlink L){
    int i;
    for(i = 0;i<LengthList(L);i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}
置空表(sqlink L){
    L->last = -1;
}
取表元素(sqlink L,int no){
    int tempData = 0;
    tempData = L->data[no-1];
    return tempData;
}
求表长(sqlink L){
    int tempL;
    tempL = L->last+1;
    return tempL;
}

插入元素{
    int j;
    if(L->last >= maxsize-1){
        printf("没有空闲空间！\n");
        return 0;
    }else if(no<0||no>L->last+1){
        printf("插入位置不存在！\n");
        return 0;
    }else{
        for(j=L->last;j>=no-1;j--)
            L->data[j+1] = L->data[j];
        L->data[no-1] = data;
        L->last++;
        return 0;
    }
}

删除元素(sqlink L,int no){
    int j;
    if(no<0||no>L->last){
        printf("删除的元素不存在");
        return 0;
    }else{
        for(j=no;j+1<=L->last;j++)
            L->data[j] = L->data[j+1];
        L->last--;
        return 0;
    }
}

定位元素{
    int i = 0;
    while(i<=L->last&&L->data[i]!=data)
        i++;
    if(i<L->last) return i;
    else return 0;
}
