#include<iostream>
#include<set>//�õ�deque����
#include<iterator>//�õ����������
#include<algorithm>//�õ�copy����
#include<functional>//�õ��º���
using namespace std;
 
int*  GetMinK(int *arr,int n,int k,int *Result)//�ú����ʵ��
{
	if(!arr || n<1 || k<1 || k>n || !Result)
	{
		cout<<"Invalid Input!";
		return NULL;
	}
	multiset<int,greater<int> >mset(arr,arr+k);//�ý�������
	int i=k;
	multiset<int,greater<int> >::iterator iter;
	for(;i<n;i++)
	{
		iter=mset.begin();
		if(arr[i]<*iter)//�����ǰԪ��С��map�е����ֵ
		{
			mset.erase(iter);
			mset.insert(arr[i]);
		}
	}
	i=0;
	while(!mset.empty())//�������е�Ԫ�ظ��Ƶ���������к�ɾ��
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
