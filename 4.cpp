#include <bits/stdc++.h>
using namespace std;
const int MAX = 1024;
int n; //物品个数
int x[MAX]; //n元0-1
int c; //包的容量
int value[MAX]; //物品的价值
int weight[MAX]; //物品质量
int m[MAX][MAX]; //解的容器
void Input()
{
    
    scanf("%d %d", &n, &c);//输入物品个数，包的容量
    for(int i = 1; i <= n; ++i)
       
        scanf("%d %d", &value[i], &weight[i]);//输入物品的价值，物品质量
    
}
//创建最优解
void Knapsack()
{
    int jMax = min(c, weight[n] - 1);
 
    //这一块填最后m表的最后一行
    /*
      解释一下就是：“在可选的物品只有n即最后一个物品n，包的容量为c时” 的最优解。
      第一个for循环：
      容易知道在背包容量为0 ~ weight[n] - 1的时候背包是放不进去物品n的，如果背包
      的容量小于物品n的质量，背包也是放不进去物品的，所以从weight[n] - 1 和 c 中
      选择一个较小的，然后m[n][0:jMax]的值为零
      第二个for循环：
      自然可知当背包容量大于weigh[n]的时候,由于其可选则的物品只有 物品n，因此m[n][weight[n]:c]
      的值全部为value[n].
    */
    for(int j = 0; j <= jMax; ++j)
        m[n][j] = 0;
    for(int j = weight[n]; j <= c; ++j)
        m[n][j] = value[n];
 
    //这一块是填m表的2 ~ n - 1行，容易理解
    for(int i = n - 1; i > 1; --i)
    {
        jMax = min(c, weight[i] - 1);
        for(int j = 0; j <= jMax; ++j)
            m[i][j] = m[i + 1][j];
        for(int j = weight[i]; j <= c; ++j)
            m[i][j] = max(m[i + 1][j], m[i + 1][j - weight[i]] + value[i]);
    }
 
    //这里是填m表的第一行，好好理解一下，不难，好好考虑一下 φ(>ω<*)
    m[1][c] = m[2][c];
    if(c >= weight[1])
        m[1][c] = max(m[1][c], m[2][c - weight[1]] + value[1]);
}
//获取最优解(即设法将求得的最优解输出出来)
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
    cout << "最优解为 : " << m[1][c] << endl;
    cout << "选择的物品的序号为 :" << endl;
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
