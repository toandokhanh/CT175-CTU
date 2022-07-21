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
	int f=0;
	int e;
	for(e=0;e<pG->m;e++){
		if(pG->edges[e].u==u && pG->edges[e].v==v){
			f=1;
			return;
	}
	}
	if(f==0){
		pG->edges[pG->m].u=u;
		pG->edges[pG->m].v=v;
		pG->m++;
	}
}
int main(){
	Graph G;
	init_graph(&G,4);
	add_edge(&G,1,2);
	add_edge(&G,3,4);
	add_edge(&G,3,4);
	add_edge(&G,3,4);
	add_edge(&G,3,4);
	printf("n = %d, m= %d\n",G.n,G.m);
	int e;
	for(e=0;e<G.m;e++)
	    printf("%d %d\n",G.edges[e].u,G.edges[e].v);
	return 0;    
}
