#include<stdio.h>
#include<malloc.h>

#define ���Ա����󳤶�

typedef struct{
    ������Ĵ���ռ�;
    int last;
}sqlist,*sqlink;

���ձ�;

�ÿձ� ;

ȡ��Ԫ�� ;

��� ;

����Ԫ�� ;

ɾ��Ԫ�� ;

��λԪ�� ;

�пձ� ;

��ӡ��Ԫ�� ;

int main(){



    һ���������ԵĶ���;







    return 0;
}

���ձ�(sqlink L){
    int tempNo = 1;
    int tempData = 0;
    do{
        printf("������˳����%d��Ԫ�أ�",tempNo);
        scanf("%d",&tempData);
        if(tempData!=-1){
            L->data[tempNo-1] = tempData;
            L->last = tempNo-1;
            tempNo++;
        }
    }while(tempNo<=maxsize&&tempData!=-1);
}
��ӡ��Ԫ��(sqlink L){
    int i;
    for(i = 0;i<LengthList(L);i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}
�ÿձ�(sqlink L){
    L->last = -1;
}
ȡ��Ԫ��(sqlink L,int no){
    int tempData = 0;
    tempData = L->data[no-1];
    return tempData;
}
���(sqlink L){
    int tempL;
    tempL = L->last+1;
    return tempL;
}

����Ԫ��{
    int j;
    if(L->last >= maxsize-1){
        printf("û�п��пռ䣡\n");
        return 0;
    }else if(no<0||no>L->last+1){
        printf("����λ�ò����ڣ�\n");
        return 0;
    }else{
        for(j=L->last;j>=no-1;j--)
            L->data[j+1] = L->data[j];
        L->data[no-1] = data;
        L->last++;
        return 0;
    }
}

ɾ��Ԫ��(sqlink L,int no){
    int j;
    if(no<0||no>L->last){
        printf("ɾ����Ԫ�ز�����");
        return 0;
    }else{
        for(j=no;j+1<=L->last;j++)
            L->data[j] = L->data[j+1];
        L->last--;
        return 0;
    }
}

��λԪ��{
    int i = 0;
    while(i<=L->last&&L->data[i]!=data)
        i++;
    if(i<L->last) return i;
    else return 0;
}
