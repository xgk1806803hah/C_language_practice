#include <stdio.h>
#include <stdlib.h>

/*
  ˼·:
  �ȶ�����¥�㰴Wi+Si���дӴ�С����Ȼ����̰������ѡ��Max(Wi+Si)��¥�㲢����ò��PDV, ��������С����ֵPDV

  ֪ʶ��: struct, qsort()
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXN 100002

struct node{
  int w,s;
  int sum;
} p[MAXN];

/* �Ƚ���д��1: �����ڻ�����������
int cmp(const void *a, const void *b){
      int x =(int) *a;
      int y =(int) *b;
   return x - y;
}
*/

/* �Ƚ���д��2: �����ڸ�����������--�ṹ�� */
int cmp(struct node *a, struct node *b){
   return b->sum - a->sum;
}


int main(){
  //freopen("din.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n,i;
  while( ~scanf("%d",&n) ){

    //���뵱ǰһ��������ݵĸ�¥��������ǿ�ȣ���ͳ��������
    __int64 s =0; //�洢����¥���������
    for(i=0;i<n;i++){
        scanf("%d%d",&p[i].w,&p[i].s);
        p[i].sum = p[i].w + p[i].s;
        s += p[i].w;
    }

    //��̰�İ�����¥�㰴���ŷ�����������( ��Max(Wi+Si)��̰�Ĳ���  )
    qsort(p,n,sizeof(p[0]),cmp);

    //����ѡ��Max(Wi+Si)��¥�㣬��������PDV=s-w[i]-s[i], ͬʱͳ�������ֵ
    __int64 ans=0;
    for(i=0;i<n;i++){
       s -=p[i].w;
       __int64 tmp = s-p[i].s;
       if(tmp>0){
          ans = ans>tmp?ans:tmp;
       }
    }
    printf("%I64d\n",ans);
  }


  return 0;
}
