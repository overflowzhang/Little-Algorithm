
void QuickSort(int left, int right){
	
	int i,j,t,temp;
	if(left > right)
		return;
	temp = a[left];
	i = left;
	j = right;

	while(i != j){
		while(a[j] >= temp && i < j)
			j --;
		while(a[i] <= temp && i < j)
			i ++;
		if(i < j)
			swap(a[i],a[j]);
	}
	a[left] = a[i];
	a[i] = temp;
	quicksort(left,i-1);
	quicksort(i+1,right);
	return;
}
