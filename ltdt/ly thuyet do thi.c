#include<stdio.h>
#define MAX_Vertices 20
#define MAX_Length 20
typedef struct{
	int A[MAX_Vertices][MAX_Vertices];
	int n;//so luong dinh//
}Graph;
typedef struct{
	int data[MAX_Length];
	int size;
}List;
void init_Graph(Graph *G,int n){
	int i,j;
	G->n=n;
	for(i=1;i<=n;i++){//dong cua ma tran//
		for(j=1;j<=n;j++){//cot cua ma tran//
			G->A[i][j]=0;
		}
	}
}
//them cung vao do thi//
void add_edge(Graph *G,int x,int y){
	G->A[x][y]=1;
	G->A[y][x]=1;
}	
//kiem tra 2 cap dinh co phai la lang gieng cua nhau hay khong//
int adjacent(Graph *G,int x,int y){
	return (G->A[x][y]!=0);
}	
//tinh bac cua dinh x trong do thi//
int degree(Graph *G,int x){
	int deg=0,i;
	for(i=1;i<=G->n;i++){
		if(G->A[i][x]==1){//adjacent(G,i,x)
			deg++;
		}
	}
	return deg;
}		
//ham khoi tao danh sach rong
void make_null(List *list){
	list->size=0;
}	
//them 1 phan tu vao cuoi danh sach
void push_back(List *list,int x){
	list->data[list->size]=x;
	list->size++;
}
//lay 1 phan tu (dinh) trong danh sach tai vi tri i
int element_at(List *list,int i){
	return list->data[i-1];
}
//tim lang gieng cua dinh x
List neighbors(Graph *G, int x){
	List L;
	make_null(&L);
	int i;
	for(i=1;i<=G->n;i++){
		if(G->A[i][x]==1){
			push_back(&L,i);
		}
	}
	return L;
}
int main(){
	Graph G;
	freopen("dothi.txt","r",stdin);
	int n,m;//n- so luong dinh,m- so luong cung//
	scanf("%d%d",&n,&m);
	init_Graph(&G,n);
	int u,v,e;
	for(e=1;e<=m;e++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	//khoi tao do thi//
	//init_Graph(&G,6);
	//add_edge(&G,2,6);
	//add_edge(&G,6,4);
	//add_edge(&G,5,6);
	//add_edge(&G,1,4);
	//add_edge(&G,1,5);
	//add_edge(&G,2,3);
	//add_edge(&G,2,4);
	//add_edge(&G,4,5);
	//int i,j;
	//printf("%d\n",G.n);
	//for(i=1;i<=G.n;i++){
		//for(j=1;j<=G.n;j++){
			//printf("%d ",G.A[i][j]);
		//}
		//printf("\n");
	//}	
	//printf("%d",adjacent(&G,1,6));
	//printf("\n");
	int i,j;
	for(i=1;i<=G.n;i++){
		printf("degree(%d) = %d\n",i,degree(&G,i));
	}	
	//in ra lang gieng cua dinh 4
	printf("\nIn ra danh sach lang gieng cua cac dinh trong do thi:\n");
	for(i=1;i<=G.n;i++){
		List list=neighbors(&G,i);
		printf("Neighbors(%d)=[",i);
		for(j=1;j<=list.size;j++){
			printf("%d ",element_at(&list,j));
		}
		printf("]\n");
	}
	//for(i=1;i<=L.size;i++){
		//printf("\n%d",element_at(&L,i));
	//}
	return 0;
}	
