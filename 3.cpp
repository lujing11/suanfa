//�Ӹ�����n�������ҳ���С��k���� 
#include<queue>
#include<iostream>
#include<iterator>//�õ����������
#include<algorithm>//�õ�copy����
using namespace std;
 
int* GetMinK(int *arr,int n,int k,int *Result)//��priority_queueʵ��һ����
{
	if(!arr || n<1 || k<1 || k>n || !Result)
		return NULL;
	priority_queue<int,vector<int>,less<int> > q;//��һ���󶥶ѣ�less)��С����(greater)
	int i;
	for(i=0;i<k;i++)//��ѹ��k��Ԫ��
	{
		q.push(arr[i]);
	}
	int max=q.top();//��ȡ�Ѷ�Ԫ��
	for(i=k;i<n;i++)
	{
		if(arr[i]<max)//�����ǰԪ�رȶѶ�Ԫ�ػ�С
		{
			q.pop();//���Ѷ�Ԫ��ɾ��
			q.push(arr[i]);//������ǰԪ��ѹ�뵽����
			max=q.top();//����maxֵ��ջ��Ԫ��ֵ��
		}
	}
	i=0;
	while(!q.empty())//������ÿһ��Ԫ�ص�ֵ�Ӷ��е����������뵽���������
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
	cout<<"ԭ�����Ԫ��Ϊ:";
	copy(arr,arr+n,ostream_iterator<int>(cout," "));
	cout<<endl;
	cout<<"������kֵ:";
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
