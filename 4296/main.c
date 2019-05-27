#include <stdio.h>
#include <stdlib.h>

/*
  思路:
  先对所有楼层按Wi+Si进行从大到小排序，然后用贪心依次选择Max(Wi+Si)的楼层并求出该层的PDV, 最后输出最小的正值PDV

  知识点: struct, qsort()
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXN 100002

struct node{
  int w,s;
  int sum;
} p[MAXN];

/* 比较器写法1: 适用于基本数据类型
int cmp(const void *a, const void *b){
      int x =(int) *a;
      int y =(int) *b;
   return x - y;
}
*/

/* 比较器写法2: 适用于复杂数据类型--结构体 */
int cmp(struct node *a, struct node *b){
   return b->sum - a->sum;
}


int main(){
  //freopen("din.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n,i;
  while( ~scanf("%d",&n) ){

    //输入当前一组测试数据的各楼层重量与强度，并统计总重量
    __int64 s =0; //存储所有楼层的总重量
    for(i=0;i<n;i++){
        scanf("%d%d",&p[i].w,&p[i].s);
        p[i].sum = p[i].w + p[i].s;
        s += p[i].w;
    }

    //用贪心把所有楼层按最优方案进行排序( 按Max(Wi+Si)的贪心策略  )
    qsort(p,n,sizeof(p[0]),cmp);

    //依次选择Max(Wi+Si)的楼层，计算它的PDV=s-w[i]-s[i], 同时统计最大正值
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
