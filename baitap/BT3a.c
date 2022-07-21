#include<stdio.h>
#define MAX_M 500
typedef struct{
	int u,v;
}Edge;
typedef struct{
	int n,m;
	Edge edges[MAX_M];
}Graph;
void init_graph(Graph *pG,int n){
	pG->n=n;
	pG->m=0;
}
void add_edge(Graph *pG,int u,int v){
	if((u<1 || u>(pG->n))||(v<1 || v>(pG->n))){
		return;
	}
	else{
		pG->edges[pG->m].u=u;
		pG->edges[pG->m].v=v;
		pG->m++;
	}
}
int main(){
	Graph G;
	init_graph(&G,4);
	add_edge(&G,4,2);
	add_edge(&G,2,-4);
	add_edge(&G,2,4);
	add_edge(&G,0,2);
	printf("n = %d, m= %d\n",G.n,G.m);
	int e;
	for(e=0;e<G.m;e++)
	    printf("%d %d\n",G.edges[e].u,G.edges[e].v);
	return 0;    
}
