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
		if(u!=v){
			if((pG->edges[e].u==v && pG->edges[e].v==u)){
				f=1;
				return;
			}
		}
	}
	if(f==0){
		pG->edges[pG->m].u=u;
		pG->edges[pG->m].v=v;
		pG->m++;
	}
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
	int n,u,v,i;
	scanf("%d",&n);
	int m[n][n];
	init_graph(&G,n);
	for(u=1;u<=n;u++){
		for(v=1;v<=n;v++){
			scanf("%d",&m[u][v]);
			for(i=1;i<=m[u][v];i++){
				add_edge(&G,u,v);
			}
		}
	}
	int e;
	for(e=0;e<G.m;e++){
		printf("%d %d\n",G.edges[e].u,G.edges[e].v);
	}
	return 0;
}

