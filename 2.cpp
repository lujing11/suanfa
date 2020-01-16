#include <iostream>
using namespace std;

void sort(int data[], int left, int right)// 排序从left到right
{
int item;//存储临时变量
sort(data,left+1,right);//先排序从left+1到right
if (data[left]>data[right])//如果data[left]大于data[right],把data[left]放好位置
{
item=data[left];
for (int i=1; i<=right; i++)
data[i-1]=data[i];
data[right]=item;
}
else if (data[left]>data[left+1] && data[left]<data[right])
        //如果data[left]小于data[right],并且大于data[left+1],把data[left]放好位置
{
for (int i=1; i<=right; i++)//找到data[left]放的具体位置
if (data[left]>data[i] && data[left]<data[i+1])
break;	
item=data[left];
for(int j=1;j<=i;j++) 
data[j-1]=data[j];
data[i]=item;
}
}

int main()
{
const int size=10;
int array[size]={9,8,7,6,5,4,3,2,1,0};
sort(array,0,size-1);

for (int n=0; n<size; n++)
cout<<array[n]<<' ';
cout<<endl;

return 0;
}

