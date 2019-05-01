#include "Sort.h"

void _print(int* a,int n) //打印数组
{
  int i=0;
  for(i=0;i<n;i++)
  {
    printf("%d",a[i]);
  }
}

void Swap(int* a,int* b) 
{
   int tmp=0;
   tmp=*a;
   *a=*b;
   *b=tmp;
}
void insertSort(int* a,int n) //直接插入排序
{
   int i=0;
   for(i=0;i<n-1;i++){
	 int end=i;
	 int tmp=a[end+1];
	 while(end>=0)
	 {
		 if(a[end]>tmp){
		   a[end+1]=a[end];
		   --end;
		 }
	     else
		   break;
     }
	 a[end+1]=tmp;
   }
}

void ShellSort(int* a,int gap,int n) //希尔排序
{
   int i=0;
   for(i=0;i<n-gap-1;i++){
   int end=i;
   int tmp=a[end+gap];
   while(end>=0)
  {
    if(a[end]>tmp){
      a[end+gap]=a[end];
      end-=gap;
    }
    else
      break;
  }
  a[end+gap]=tmp;
 }
 insertSort(a,n);
}

void adjust(int* a,int n,int parent) //向下调整法
{
   int child=parent*2+1;
   while(child<n){
       if(child+1<n && a[child]<a[child+1])
		   child++;
	   if(a[parent]<a[child])
	   {
	     Swap(&a[parent],&a[child]);
		 parent=child;
		 child=parent*2+1;
	   }
	   else
		 break;
	 }
}

void HeapSort(int* a,int n) //堆排序
{
   int i=0;
   int end=n-1;
   for(i=(n-1-1)/2;i>=0;i--) //建堆
   {
     adjust(a,n,i);
   }
   while(end>0){
     Swap(&a[end],&a[0]);
	 end--;
     adjust(a,end,0);
   }
}


void SortTest()
{
	int a[]={4,3,5,8,9,7,6,2,1,0};
    //insertSort(a,sizeof(a)/sizeof(int));
    //ShellSort(a,3,sizeof(a)/sizeof(int));
	//HeapSort(a,sizeof(a)/sizeof(int));
	_print(a,sizeof(a)/sizeof(int));

}