/*所有排序算法,按升序排列*/

#include <stdio.h>

#define SIZE 10
int a[SIZE]={9,7,5,8,1,3,2,3,5,10};

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b =temp;
}
/*冒泡排序，交换相邻的两个元素*/
void bubble_sort(int array[], int length)
{
    int i,j;
    for(i=0;i < length;i++)
        for(j=0; j<length -1- i; j++){
            if(array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
}

/*将序列分为两部分，假设前一部分已经排好序，从后面部分选取后插入前面，类似于打扑克*/
void insert_sort(int *array,int length)
{
	int i,j;
	for(i=1; i<length; i++){
		int temp = array[i];
		for(j=i-1; j>=0&&array[j]>temp; j--)
			array[j+1] = array[j];
		array[j+1] = temp;
	}
}

void insert_sort1(int *array,int length)
{
	int i,j;
	for(i=1; i<length; i++){
		int temp = array[i];
		for(j=i-1; j>=0&&array[j]>temp; j--)
			swap(a+j,a+j+1);
	}
}
/*选择排序，从序列中选取最小的，放在第一个位置值*/
void select_sort(int *array, int length)
{
	int i,j;	
	for(i=0; i<length; i++)
		for(j=i+1; j<length; j++){
			if(array[i] > array[j])
				swap(&array[i], &array[j]);
		}
}
/*merge sort*/
void merge(int unsorted[], int head, int middle, int tail, int sorted[])
{
	int i = head;
	int j = middle+1;
	int m = 0;
	while(i <= middle && j <= tail){
		if(unsorted[i] < unsorted[j]){
			sorted[m++] = unsorted[i++];
		}else{
			sorted[m++] = unsorted[j++];
		}
	}

	while(i<=middle){
		sorted[m++] = unsorted[i++];
	}

	while(j <= tail){
		sorted[m++] = unsorted[j++];
	}

	for(i = 0;i < m; i++)
		unsorted[i+head] = sorted[i];
}
void merge_sort(int array[], int low, int high, int sorted[])
{
	if(high>low){
		int mid = (low+high)/2;
		merge_sort(array, low, mid, sorted);
		merge_sort(array, mid+1,high,sorted);
		merge(array, low, mid ,high, sorted);
	}
}

/*quick sort,选取岗哨第一个*/
int partion(int array[], int low, int high)
{
	int pivot = array[low];  //choose the first value as a pivot
	int first = low;
	int last = high;
	while(last > first){
		while(last > first && array[last] >= pivot)
			last--;
		if(last > first)
			array[first++] = array[last];
	
		while(last > first && array[first] < pivot)
			first++;
		if(last > first)
			array[last--] = array[first];
	}
	array[first] = pivot;
	return first;
}

void quick_sort(int array[], int low, int high)
{
	if(low < high){
		int position = partion(a, low , high);
		quick_sort(array, low, position-1);
		quick_sort(array, position+1, high);
	}
}

int main()
{
	int m;
	printf("before sort:\n");
	for(m =0; m<SIZE; m++){
		if(m == SIZE-1)
			printf("%d\n",a[m]);
		else 
			printf("%d, ",a[m]);
	}
	//insert_sort1(a,SIZE);
	int b[SIZE];
	merge_sort(a, 0 , SIZE-1, b);
	//quick_sort(a, 0, SIZE-1);
	printf("after sort:\n");
	for(m =0; m<SIZE; m++){
		if(m == SIZE-1)
			printf("%d\n",a[m]);
		else 
			printf("%d, ",a[m]);
	}
	return 0;
}
