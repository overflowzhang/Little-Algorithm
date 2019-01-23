#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int m[4][10];
//存储符合条件的数字 
int Count = 0;

int Convert(char chars[][3],char s[][3])
{//将时钟数字转化成十进制数字表示
    int a = 0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
          if(chars[i][j]==s[i][j])
          {
            a += (int)pow(2,(8-(i*3+j)));
          }

    return a;
}

void Compare(int Time[],int flag[])
{//遍历数组，将符合条件的数字存入数组
    int binary;
    int count = 0;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<10;j++)
        {
            binary = Time[i]&flag[j];
			//若与操作为0，则表示符合条件 
            if(binary==0)
                m[i][count++] = j;
            else
                m[i][count++] = 99;
        }
        count = 0;
    }
    return ;
}


void Print_1(char number[][3][3],int a,int b,int c,int d)
{//输出时钟时间 

    for(int i=0;i<3;i++)
    {
        for(int r1=0;r1<3;r1++)
            cout<<number[a][i][r1];
        cout<<"  ";
        for(int r2=0;r2<3;r2++)
            cout<<number[b][i][r2];
        cout<<"  ";
        for(int r3=0;r3<3;r3++)
            cout<<number[c][i][r3];
        cout<<"  ";
        for(int r4=0;r4<3;r4++)
            cout<<number[d][i][r4];
        cout<<endl;
    }
}

void Get_It(char number[][3][3])
{//筛选上述符合条件的时钟显示 
    for(int i=0;i<10;i++)
    {
        if(m[0][i]<=2)
        {
            for(int j=0;j<10;j++)
            {
                if((m[1][j]<=9)||(m[0][i]==0&&m[1][j]<4))
                {
                    for(int k=0;k<10;k++)
                    {
                        if(m[2][k]<6)
                        {
                            for(int p=0;p<10;p++)
                            {
                                if(m[3][p]<=9)
                                {
                                    Print_1(number,m[0][i],m[1][j],m[2][k],m[3][p]);
                                    Count++;
                                    cout<<endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


int main()
{

    char number[10][3][3] = {{{' ','_',' '},{'|',' ','|'},{'|','_','|'}},//0
                            {{' ',' ',' '},{' ',' ','|'},{' ',' ','|'}}, //1
                            {{' ','_',' '},{' ','_','|'},{'|','_',' '}}, //2
                            {{' ','_',' '},{' ','_','|'},{' ','_','|'}}, //3
                            {{' ',' ',' '},{'|','_','|'},{' ',' ','|'}}, //4
                            {{' ','_',' '},{'|','_',' '},{' ','_','|'}}, //5
                            {{' ','_',' '},{'|','_',' '},{'|','_','|'}}, //6
                            {{' ','_',' '},{' ',' ','|'},{' ',' ','|'}}, //7
                            {{' ','_',' '},{'|','_','|'},{'|','_','|'}}, //8
                            {{' ','_',' '},{'|','_','|'},{' ','_','|'}}};//9
    int flag[10] = {16,182,33,36,134,12,8,54,0,4};
    //各个数字的时钟表示->二进制->取反->十进制 
    char chars[3][3] = {{' ','_',' '},{'|','_','|'},{'|','_','|'}}; //数字8 
    int Time[4];
    char s[3][3];
    char ch;
    int count = 0;


//输入四个残缺的时钟数字
    cout<<"输入四个残缺的时钟数字："<<endl;
    cout<<"按列输入，数字格式为 3*3："<<endl;
    for(int k=0;k<4;k++)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                s[i][j] = cin.get();
            ch = getchar();
        }
        Time[count++] = Convert(chars,s);
        //cout<<Time[count-1]<<endl;
    }
    
    Compare(Time,flag);
    //将Time中的四个数字分别与flag中的十个数字对比
	//符合条件的存入m二维数组(全局变量)中 

    Get_It(number);

    cout<<"共有"<<Count<<"种可能~"<<endl;

    return 0;
}

/*
    将每个数字拆分成9部分，分别用二进制0-1来表示
    讲九位二进制数取反->在转换成十进制->flag[9]
    将输入的四个时钟数字用二进制表示，再转换成十进制
    分别与flag[]中的数字进行逻辑与&操作，与结果为0
    表示该数字符合条件，否则不符合条件
    
    */


