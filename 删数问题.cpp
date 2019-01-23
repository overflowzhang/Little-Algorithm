#include <iostream>
#include <string.h>
using namespace std;

int main(){
	string a;
	int len,k;
	cin>>a;
	cin>>k;
	len = a.size();
	while(k--){
		for(int i = 0; i < len - 1; i++){
			if(a[i] > a[i+1]){
				for(int j = i; j < len - 1; j++){
					a[j] = a[j+1];
				}
				len--;
				break;
			}
		}
	}
	for(int i = 0; i < len; i++)
		cout<<a[i];
	cout<<endl;
	return 0;
}