#include<iostream>
using namespace std;

void bubble(int arr[],int n){
	int i;
	int temp;
	for(i=0;i<n-1;i++){
		if(arr[i]>arr[i+1]){
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
	}
}

void BubbleSort(int arr[],int n){
	int i;
	for(i=n;i>=1;i++){
		bubble(arr,i);
	}
}

int main(){
	int arr[10] = {1,3,5,4,2,6,8,7,9,0};
	bubbleSort(arr,10);
	for(int i =0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}