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
	pG->edges[pG->m].u=u;
	pG->edges[pG->m].v=v;
	pG->m++;
}
int adjacent(Graph *pG,int u,int v){
	int e;
	for(e=0;e<pG->m;e++){
		if((pG->edges[e].u==u && pG->edges[e].v==v)){
			return 1;
		}
	}
	return 0;
}
int main(){
	Graph G;
	init_graph(&G,4);
	add_edge(&G,1,2);
	add_edge(&G,3,4);
	printf("n = %d, m= %d\n",G.n,G.m);
	int e;
	for(e=0;e<G.m;e++){
	    printf("%d %d\n",G.edges[e].u,G.edges[e].v);
}
    printf("%d",adjacent(&G,4,3));
	return 0;    
}
