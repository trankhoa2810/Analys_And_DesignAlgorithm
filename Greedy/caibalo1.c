#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char TenDV[20];
	float TL, GT, DG;
	int PA;
} DoVat;

DoVat * ReadFromFile(float *W, int *n){
 	FILE *f = fopen("CaiBalo1.inp", "r");
 	fscanf(f, "%f", W); // Xac dinh trong luong Ba lo
	DoVat *dsdv;
	dsdv=(DoVat*)malloc(sizeof(DoVat));
	int i=0;	
	while (!feof(f)){
		fscanf(f, "%f%f",&dsdv[i].TL,&dsdv[i].GT);
	 	fgets(dsdv[i].TenDV, 20, f);
	 	if(dsdv[i].TenDV[strlen(dsdv[i].TenDV) - 1] == '\n')
	 		dsdv[i].TenDV[strlen(dsdv[i].TenDV) - 1] = '\0';
 		dsdv[i].PA=0;
 		i++;
 		dsdv=(DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1)); 
	} 
	*n=i;
	fclose(f);
	return dsdv;
}

void swap(DoVat *x, DoVat *y){
	DoVat Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
}

void BubbleSort(DoVat *dsdv, int n){
	int i,j;
	for(i = 0; i <= n-2; i++)
		for (j = n-1; j >= i+1; j--){
			float DGJ = dsdv[j].GT / dsdv[j].TL; // DGJ: don gia cua vat sau.
			float DGJ_1 = dsdv[j-1].GT / dsdv[j-1].TL; // DGJ_1: don gia cua vat truoc.
			if (DGJ > DGJ_1) 
				swap(&dsdv[j], &dsdv[j-1]);
		}
}

void InDSDV(DoVat *dsdv ,int n, float W){
	int i;
	float TongTL = 0.0, TongGT = 0.0;
	printf("Bai toan cai balo 1 su dung giai thuat tham an\n");
	printf("|---|--------------------|---------|---------|---------|---------|\n");
	printf("|%-3s|%-20s|%-9s|%-9s|%-9s|%-9s|\n", "STT", " Ten Do Vat","T. Luong", "Gia Tri", "Don Gia", "P. An");
	printf("|---|--------------------|---------|---------|---------|---------|\n");
	for(i = 0; i < n; i++){
		printf("|%-3d", i+1);
		printf("|%-20s", dsdv[i].TenDV); // Ten do vat
		printf("|%-9.1f", dsdv[i].TL); // Trong luong
		printf("|%-9.1f", dsdv[i].GT); // Gia tri
		printf("|%-9.1f", dsdv[i].GT/dsdv[i].TL);  // Don gia = Gia tri / trong luong
		printf("|%-9d|\n", dsdv[i].PA);
		TongTL = TongTL + dsdv[i].PA * dsdv[i].TL;
		TongGT = TongGT + dsdv[i].PA * dsdv[i].GT;
	}
	printf("|---|--------------------|---------|---------|---------|---------|\n");
	printf("Trong luong cua balo = %9.1f\n",W);
	printf("Tong trong luong = %9.1f\nTong gia tri = %9.1f\n", TongTL,TongGT);
	printf("X(");
	for(i = 0; i < n; i++){
		printf("%d", dsdv[i].PA);
		if(i < n - 1)
			printf(",");
	}
	printf(")");
}

void Greedy(DoVat *dsdv, int n, float W){
	int i;
	for(i = 0; i < n; i++) {
		dsdv[i].PA = (W / dsdv[i].TL); // Phuong an = trong luong balo / trong luong do vat.
 		W = W - dsdv[i].PA * dsdv[i].TL;
	}
}

int main(){
	int n;//So do vat
	float W;//Tong trong luong
	DoVat *dsdv;

	dsdv=ReadFromFile(&W, &n);
	BubbleSort(dsdv,n);
	Greedy(dsdv,n,W);
	InDSDV(dsdv,n,W);
	
	free(dsdv);
	return 0;
}
