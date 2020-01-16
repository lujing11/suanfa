#include<iostream>
#include<set>//用到deque容器
#include<iterator>//用到输出迭代器
#include<algorithm>//用到copy函数
#include<functional>//用到仿函数
using namespace std;
 
int*  GetMinK(int *arr,int n,int k,int *Result)//用红黑树实现
{
	if(!arr || n<1 || k<1 || k>n || !Result)
	{
		cout<<"Invalid Input!";
		return NULL;
	}
	multiset<int,greater<int> >mset(arr,arr+k);//用降序排序
	int i=k;
	multiset<int,greater<int> >::iterator iter;
	for(;i<n;i++)
	{
		iter=mset.begin();
		if(arr[i]<*iter)//如果当前元素小于map中的最大值
		{
			mset.erase(iter);
			mset.insert(arr[i]);
		}
	}
	i=0;
	while(!mset.empty())//将集合中的元素复制到输出数组中后删除
	{
		iter=mset.begin();
		Result[i++]=*iter;
		mset.erase(iter);
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
