#include <stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct{
	keytype key;
	othertype otherfields;
} recordtype;

void swap(recordtype &x, recordtype &y){
	recordtype temp = x;
	x = y;
	y = temp;
}

void SelectionSort(recordtype A[], int n){
	int i, j, lowindex;
	keytype lowkey;
	for(i = 0; i < n - 1; i++){ //Duyet n-1 phan trong mang de tim min gan vao lowkey, va gan vi tri hien tai cua no vao lowindex. 
		lowkey = A[i].key;
		lowindex = i;
		for(j = i + 1; j < n; j++){
			if(lowkey > A[j].key){
				lowkey = A[j].key;
				lowindex = j;
			}
		}
		swap(A[i], A[lowindex]);
	}
}

void InsertSort(recordtype A[], int n){
	int i, j;
	for(i = 1; i < n; i++){
		j = i;
		while((j > 0) && (A[j].key < A[j-1].key)){
			swap(A[j], A[j-1]);
			j--;
		}
	}
}

void BubleSort(recordtype A[], int n){
	int i, j;
	for(i = 0; i < n - 1; i++){
		for(j = i + 1; j < n; j++)
			if(A[i].key > A[j].key)
				swap(A[i], A[j]);
	}
}

//Hàm tìm chốt
int findPivot(recordtype A[], int i, int j){
	keytype firstkey;
	int k;
	k = i + 1;
	firstkey = A[i].key;
	while(k <= j && (A[k].key) == firstkey){
		k++;
	}
	if(k > j)
		return -1;
	if(A[k].key > firstkey)
		return k;
	return i;
}

//Hàm phân hoạch
int Partition(recordtype A[], int i, int j, keytype pivot){
	int L, R;
	L = i;
	R = j;
	while(L <= R){
		while(A[L].key < pivot)
			L++;
		while(A[R].key >= pivot)
			R--;
		if(L < R)
			swap(A[R], A[L]);
	}
	return L; //Tra ve diem phan hoach
}

//Hàm QuickSort.
void QuickSort(recordtype A[], int i, int j){
	keytype pivot;
	int pivotIndex, k;
	pivotIndex = findPivot(A, i, j);
	if(pivotIndex != -1){
		pivot = A[pivotIndex].key;
		k = Partition(A, i, j, pivot);
		QuickSort(A, i, k - 1);
		QuickSort(A, k ,j);
	}
}

int main(){
	int n, i;
	scanf("%d", &n); // n = 10
	recordtype A[n]; // 5 6 2 2 10 12 9 10 9 3
	for(i = 0; i < n; i++){
		scanf("%d", &A[i].key);
	}

	QuickSort(A, 0, n - 1);
	
	for(i = 0; i < n; i++){
		printf("%d ", A[i].key);
	}
	return 0;
}