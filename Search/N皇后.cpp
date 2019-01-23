#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int queen[9] = {0}; //queen[i] 表示第i行的皇后，摆放在第queen[i]列

bool Place(int x,int y) //判断（x,y）位置能否摆放皇后，如果可以，则返回true;
{
    int len = x;
    for (int i = 1; i < len; i++) //判断列，和对角线上有无冲突
        if (queen[i] == y || fabs(y-queen[i]) == fabs(x-i)) 
			return false;
    	return true;
}

void print()  //打印每个皇后的列的位置
{
     int i;
     cout<<"(";
     for (i = 1; i <= 7; i++)
         cout<<queen[i]<<",";
     cout<<queen[i]<<")"<<endl<<endl;
}
void search(int i)
{
    int flag;
    int count = 0;
    while (i <= 8)
    {
        flag = 0;
        for (int j = queen[i] + 1; j <= 8; j++) //j = queen[i] + 1表示从第queen[i]列，

                                   //往后找另一个不冲突的位置，因为前面的已经找过了
        {
            if (Place(i,j))     //如果(x,y)位置能否摆放皇后
            {
                queen[i] = j;  //将第i行的皇后摆放在第j列
                flag = 1;   //标记这一行可以摆放
                break;      //跳出这一层循环，开始摆放下一行的皇后
            }
        }
        if (flag == 0)  //如果循环完这一行，每个位置都冲突

        {
                 queen[i] = 0; //将这一行的皇后位置重置为0;
                 i--;       //返回到上一行
                 if(i==0)break; //如果已经返回到了第0行，说明所有情况都找完了
        }
        else
        {
             if (i == 8)  //如果找到了第8行，说明有满足条件的结果
             {
                print();  //输出结果
                count++;
             }
             else i++;
        }
    }
    cout<<count<<endl;
}
int main()
{
    search(1);
    return 0;

}   
