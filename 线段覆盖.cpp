#include <iostream>
using namespace std;

int main()
{
	int a[2][20];
	int flag[2];
	int n,len,tmp;
	cin>>n;
	for(int i = 0;i < n; i++)
	{
		cin>>a[0][i]>>a[1][i];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - i - 1;j++)
		{
			if(a[0][j] > a[0][j+1])
			{
				swap(a[1][j],a[1][j+1]);
				swap(a[0][j],a[0][j+1]);
			}
		}
	}
	len = a[1][0] - a[0][0];
	flag[0] = a[0][0];
	flag[1] = a[1][0];
	for(int i = 0;i < n;i++)
	{
		if(a[0][i] >= flag[1])
		{
			tmp = (a[1][i] - a[0][i]);
			len += tmp;
			flag[0] = a[0][i];
			flag[1] = a[1][i];
		}
		if(a[0][i] < flag[1])
		{
			if(a[1][i] > flag[1])
			{
				tmp = (a[1][i] - flag[1]);
				len += tmp;
				flag[0] = a[0][i];
				flag[1] = a[1][i];
			}
		}
	}
	cout<<len<<endl;
	return 0;
}

