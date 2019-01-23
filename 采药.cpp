#include <iostream>
#include <cstring>
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;

int main()
{
    int dp[101][1001] , n , t ,  a [101],v[101] ,  i ,  j;
    // dp[已经判断是否摘取的草药数量][剩余的时间]
    cin >> t >> n;
    for(i=1;i<=n;i++)
        cin  >> a[i]  >>  v[i] ;
    memset( dp , 0 , sizeof(dp)) ;
    for(i=1;i<=n;i++)
        for(j=0;j<=t;j++)  //这个的j 对应着剩余的时间
        {
            if( j >= a [i])   dp[i][j] = max (  dp[i-1][j]  , dp[i-1][j-a[i]] + v[i] ) ;
            //放还是不放的选择，如果时间允许采药
            else  dp[i][j] = dp[i-1][j] ;
             //时间不允许采药
        }
     cout<<dp[n][t]<<endl;
    return 0;
}
