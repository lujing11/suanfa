#include <iostream>
using namespace std;

void sort(int data[], int left, int right)// �����left��right
{
int item;//�洢��ʱ����
sort(data,left+1,right);//�������left+1��right
if (data[left]>data[right])//���data[left]����data[right],��data[left]�ź�λ��
{
item=data[left];
for (int i=1; i<=right; i++)
data[i-1]=data[i];
data[right]=item;
}
else if (data[left]>data[left+1] && data[left]<data[right])
        //���data[left]С��data[right],���Ҵ���data[left+1],��data[left]�ź�λ��
{
for (int i=1; i<=right; i++)//�ҵ�data[left]�ŵľ���λ��
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

