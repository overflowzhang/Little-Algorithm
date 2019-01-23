#include <iostream>
using namespace std;
#define MAX 10
#define INF 999
void Floyd(int arc[MAX][MAX],int dist[MAX][MAX],int n)
{
	int i, j, k;
	for(i = 0; i < n; i++)
		for(j = 0 ;j < n;j++)
			dist[i][j] = arc[i][j];
	for(k = 0; k < n ; k++)
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	cout<<"输出结果:"<<endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout<<dist[i][j]<<" ";
		cout<<endl;
	}		
}

int main()
{
	int arc[MAX][MAX], dist[MAX][MAX];
	int n;
	cout<<"输入顶点数:"<<endl;
	cin>>n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			cin>>arc[i][j];
			if(arc[i][j] == -1)
				arc[i][j] = INF;
		}
	Floyd(arc,dist,n);

}





