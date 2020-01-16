//从给定的n个数中找出最小的k个数 
#include<queue>
#include<iostream>
#include<iterator>//用到输出迭代器
#include<algorithm>//用到copy函数
using namespace std;
 
int* GetMinK(int *arr,int n,int k,int *Result)//用priority_queue实现一个堆
{
	if(!arr || n<1 || k<1 || k>n || !Result)
		return NULL;
	priority_queue<int,vector<int>,less<int> > q;//建一个大顶堆（less)，小顶堆(greater)
	int i;
	for(i=0;i<k;i++)//先压入k个元素
	{
		q.push(arr[i]);
	}
	int max=q.top();//获取堆顶元素
	for(i=k;i<n;i++)
	{
		if(arr[i]<max)//如果当前元素比堆顶元素还小
		{
			q.pop();//将堆顶元素删除
			q.push(arr[i]);//并将当前元素压入到堆中
			max=q.top();//更新max值（栈顶元素值）
		}
	}
	i=0;
	while(!q.empty())//将堆中每一个元素的值从堆中弹出，并放入到输出数组中
	{
		Result[i++]=q.top();
		q.pop();
	}
	return Result;
}

int main()
{
	int arr[]={9,4,2,5,6,7,8,11};
	int n=sizeof(arr)/sizeof(int);
	cout<<"原数组的元素为:";
	copy(arr,arr+n,ostream_iterator<int>(cout," "));
	cout<<endl;
	cout<<"请输入k值:";
	int k;
	while(cin>>k)
	{
		int *result=new int[k];
		result=GetMinK(arr,n,k,result);
		if(result)
		{
			copy(result,result+k,ostream_iterator<int>(cout," "));
		}
		cout<<endl;
		delete []result;
	}
	return 0;
}
