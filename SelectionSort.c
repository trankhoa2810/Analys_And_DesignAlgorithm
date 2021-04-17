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
	for(i = 0; i < n - 1; i++){
		lowkey = A[i].key;
		lowindex = i;
		for(j = i + 1; j < n; j++){
			if(A[j].key < lowkey){
				lowindex = j;
				lowkey = A[j].key;
			}
		}
		swap(A[i], A[lowindex]);
	}
}

int main(){
	int n, i;
	scanf("%d", &n); // n = 10
	recordtype A[n]; // 5 6 2 2 10 12 9 10 9 3
	for(i = 0; i < n; i++){
		scanf("%d", &A[i].key);
	}

	SelectionSort(A, n);
	
	for(i = 0; i < n; i++){
		printf("%d ", A[i].key);
	}
	return 0;
}
