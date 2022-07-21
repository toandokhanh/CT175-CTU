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
int degree(Graph *pG,int u){
	int e,deg_u=0;
	for(e=0;e<pG->m;e++){
		if(pG->edges[e].u==u)
			deg_u++;
		if(pG->edges[e].v==u)
			deg_u++;
	}
	return deg_u;
}
int main(){
	Graph G;
	int n=4,u;
	init_graph(&G,n);
	add_edge(&G,1,2);
	add_edge(&G,1,3);
	add_edge(&G,1,3);
	add_edge(&G,3,4);
	add_edge(&G,1,4);
	for(u=1;u<=n;u++)
		printf("deg(%d) = %d\n",u,degree(&G,u));
	return 0;	
}
