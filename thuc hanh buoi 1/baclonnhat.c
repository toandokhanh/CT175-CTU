#include<stdio.h>
#define MAX_N 100
#define MAX_M 500
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct{
	ElementType data[MAX_ELEMENTS];
	int size;
}List;
typedef struct{
	int n,m;
	int A[MAX_N][MAX_M];
}Graph;
void init_graph(Graph *pG,int n,int m){
	int u,e;
	pG->n=n;
	pG->m=m;
	for(u=1;u<=n;u++){
		for(e=1;e<=m;e++){
			pG->A[u][e]=0;
		}
	}
}
void add_edge(Graph *pG,int e,int u,int v){
	pG->A[u][e]=1;
	pG->A[v][e]=1;
}
int adjacent(Graph *pG,int u,int v){
	int e;
	for(e=1;e<=pG->m;e++){
		if(pG->A[u][e]==1 && pG->A[v][e]==1)
			return 1;
	}
	return 0;
}
int degree(Graph *pG,int u){
	int e,deg_u=0;
	for(e=1;e<=pG->m;e++)
		if(pG->A[u][e]==1)
			deg_u++;
	return deg_u;
}
void make_null(List *pL){
	pL->size=0;
}
void push_back(List *pL,ElementType x){
	pL->data[pL->size]=x;
	pL->size++;
}
int element_at(List *pL,int i){
	return pL->data[i-1];
}
int count_list(List *pL){
	return pL->size;
}
void baclonnhat(Graph* G){
	int dinh,i,max=0; 
	for (i=1;i<=G->n;i++){ 
		if(degree(G,i)>max){ 
			max=degree(G, i); 
			dinh=i; 
		} 
	} 
	printf("%d %d\n",dinh,max); 
} 
int main(){ 
	Graph G; 
	int n,m,u,v,e; 
	scanf("%d%d",&n,&m); 
	init_graph(&G,n,m); 
	for (e=1;e<=m;e++){ 
		scanf("%d%d",&u,&v); 
		add_edge(&G,e,u,v); 
	} 
	baclonnhat(&G); 
	return 0; 
}
