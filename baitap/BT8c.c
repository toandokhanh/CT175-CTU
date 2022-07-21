#include<stdio.h>
#define MAX_N 100
typedef struct{
	int n,m;
	int A[MAX_N][MAX_N];
}Graph;
void init_graph(Graph *pG,int n){
	pG->n=n;
	pG->m=0;
	int u,v;
	for(u=1;u<=n;u++){
		for(v=1;v<=n;v++)
			pG->A[u][v]=0;
	}
}
void add_edge(Graph *G,int u,int v){
	G->A[u][v]++;
	G->A[v][u]++;
	G->m++;
}
int main(){
	Graph G;
	int e,n,m,u,v;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(e=0;e<m;e++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	for(u=1;u<=G.n;u++){
		for(v=1;v<=G.n;v++)
			printf("%d \n",G.A[u][v]);
		printf("\n");
	}
	return 0;
}
