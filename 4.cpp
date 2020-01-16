#include <bits/stdc++.h>
using namespace std;
const int MAX = 1024;
int n; //��Ʒ����Ʒ������
int x[MAX]; //nԪ0-1
int c; //��������
int value[MAX]; //��Ʒ�ļ�ֵ
int weight[MAX]; //������
int m[MAX][MAX]; //�������
void Input()
{
    scanf("%d %d", &n, &c);
    for(int i = 1; i <= n; ++i)
        scanf("%d %d", &value[i], &weight[i]);
}
//�������Ž�
void Knapsack()
{
    int jMax = min(c, weight[n] - 1);
 
    //��һ�������m������һ��
    /*
      ����һ�¾��ǣ����ڿ�ѡ����Ʒֻ��n�����һ����Ʒn����������Ϊcʱ�� �����Ž⡣
      ��һ��forѭ����
      ����֪���ڱ�������Ϊ0 ~ weight[n] - 1��ʱ�򱳰��ǷŲ���ȥ��Ʒn�ģ��������
      ������С����Ʒn������������Ҳ�ǷŲ���ȥ��Ʒ�ģ����Դ�weight[n] - 1 �� c ��
      ѡ��һ����С�ģ�Ȼ��m[n][0:jMax]��ֵΪ��
      �ڶ���forѭ����
      ��Ȼ��֪��������������weigh[n]��ʱ��,�������ѡ�����Ʒֻ�� ��Ʒn�����m[n][weight[n]:c]
      ��ֵȫ��Ϊvalue[n].
    */
    for(int j = 0; j <= jMax; ++j)
        m[n][j] = 0;
    for(int j = weight[n]; j <= c; ++j)
        m[n][j] = value[n];
 
    //��һ������m���2 ~ n - 1�У��������
    for(int i = n - 1; i > 1; --i)
    {
        jMax = min(c, weight[i] - 1);
        for(int j = 0; j <= jMax; ++j)
            m[i][j] = m[i + 1][j];
        for(int j = weight[i]; j <= c; ++j)
            m[i][j] = max(m[i + 1][j], m[i + 1][j - weight[i]] + value[i]);
    }
 
    //��������m��ĵ�һ�У��ú����һ�£����ѣ��úÿ���һ�� ��(>��<*)
    m[1][c] = m[2][c];
    if(c >= weight[1])
        m[1][c] = max(m[1][c], m[2][c - weight[1]] + value[1]);
}
//��ȡ���Ž�(���跨����õ����Ž��������)
void Traceback()
{
    int cc = c;
    for(int i = 1; i < n; i++)
        if(m[i][cc] == m[i + 1][cc])
           x[i] = 0;
        else
        {
            x[i] = 1;
            cc -= weight[i];
        }
        x[n] = (m[n][cc]) ? 1 : 0;
}
void Output()
{
    cout << "���Ž�Ϊ : " << m[1][c] << endl;
    cout << "ѡ�����Ʒ�����Ϊ :" << endl;
    for(int i = 1; i <= n; ++i)
        if(x[i] == 1)
         cout << i << " ";
    cout << endl;
}
int main()
{
    Input();
    Knapsack();
    Traceback(); 
    Output();
//    cout << "*******" << endl;
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= c; ++j)
//            cout << m[i][j] << " ";
//        cout << endl;
//    }
}
