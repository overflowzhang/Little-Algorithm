#include<iostream>
using namespace std;
int findMaxPos(int arr[],int n){
	int Max = arr[0];
	int Pos = 0;
	for(int i=0;i<n;i++){
		if(arr[i]>Max){
			Max = arr[i];
			Pos = i;
		}
	}
	return 0;
}

void SelectSort(int arr[],int n){
	int pos;
	int temp;
	while(n>1){
		pos = findMaxPos(arr,n);
		temp = arr[pos];
		arr[pos] = arr[n-1];
		arr[n-1] = temp;
		n--;
	}
}

int main(){
	int arr[10] = {2,4,7,3,1,9,7,8,0,5};
	SelectSort(arr,10);
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}

