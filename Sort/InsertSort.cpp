
int* InsertSort(int arr[] , int n ){ 

	for( int i = 1 ; i < n ; i ++ ){
		int e = arr[i];
		for( j = i ; j > 0 && arr[j] < ar[j-1] ; j -- )
			arr[j] = arr[j-1];
		arr[j] = e;
	}
	return arr;
}
