#include <stdio.h>
#define MAX_Vertices 20 // so dinh lon nhat trong ma tran
typedef struct{
	int A[MAX_Vertices][MAX_Vertices];
	int n; //so luong dinh
}Graph;
// khoi tao do thi
void init_Graph(Graph *G, int n){ 
	G->n = n;
	int i, j;
	for(i= 1; i<=n; i++) // dong cua ma tran
		for(j= 1; j<=n; j++) // cot cua ma tran
			G->A[i][j] = 0;		
}
// them cung vao do thi
void add_edge(Graph *G, int x, int y){
	G->A[x][y] = 1;
	G->A[y][x] =1;
}
//kiem tra x va y co la lang gieng hay khong?
int adjacent(Graph *G, int x, int y){
	printf("%d la lang gieng cua %d : %d" ,x,y,(G->A[x][y] != 0));
	printf("\n1 là dung");
	printf("\n0 là sai");
	return 0;
}
int degree(Graph *G, int j){
	int deg = 0, i;
	for(i=1; i<=G->n;i++){
		if(G->A[i][j] == 1)
			deg++;
	}
	return deg;
}
int main(){	
	Graph G;
	int i, j;
	freopen("dothi.txt", "r", stdin);
	int n,m; //n la so luong dinh | m la so luong cung 
	scanf("%d%d", &n,&m);
	init_Graph(&G, n);
	int u, v ,e; 
	for(e = 1; e<=m; e++){
		scanf("%d%d", &u,&v);
		add_edge(&G, u, v);
	}
	printf("so dinh cua ma tran la %d\n" , n);
//	printf("--------------------------------\n");
//	for(i= 1; i<=G.n; i++){ 
//		for(j= 1; j<=G.n; j++)
//			printf("%d ", G.A[i][j]);
//		printf("\n");
//	}	
//	printf("--------------------------------\n");
//	adjacent(&G, 5, 3);
	printf("--------------------------------\n");
	printf("Bac cua cac dinh tren do thi : \n");
	for(i=1; i<=G.n; i++)
		printf("Degree(%d) = %d \n",i,degree(&G,i));
	return 0;
};
