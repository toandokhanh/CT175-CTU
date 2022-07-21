#include<stdio.h>
#include<stdlib.h>
#define MAX_N 1000
#define oo 999999
int pi[MAX_N];
int p[MAX_N];
typedef struct{
	int u,v;
	int w;
}Edge;
typedef struct{
	int n,m;
	Edge edges[MAX_N];
}Graph;
void init_graph(Graph *G,int n){
	G->n=n;
	G->m=0;
}
int min(int a,int b){
	if(a>b)	return b;
	else return a;
}
int max(int a,int b){
	if(a<b)	return b;
	else return a;
}
void add_edge(Graph *pG,int u,int v,int w){
	pG->edges[pG->m].u=min(u,v);
	pG->edges[pG->m].v=max(u,v);
	pG->edges[pG->m].w=w;
	pG->m++;
}
int parent[MAX_N];
int findRoot(int u){
	if(parent[u]==u){
		return u;
	}
	return findRoot(parent[u]);
}
int cmpfunc(const void *a,const void *b){
	return ((const Edge*)a)->w - ((const Edge*)b)->w;
}
int Kruskal(Graph *pG,Graph *pT){
	/*int i,j;
	Edge temp;
	for(i=0;i<m;i++){
		for(j=i+1;j<m;j++){
			if((pG->edges[j].w)<(pG->edges[i].w)){
				temp=pG->edges[i];
				pG->edges[i]=pG->edges[j];
				pG->edges[j]=temp;
			}
		}
	}*/
	qsort(pG->edges,pG->m,sizeof(Edge),cmpfunc);
	init_graph(pT,pG->n);
	int u,e;	
	for(u=1;u<=pG->n;u++){
		parent[u]=u;
	}
	int sum_w=0;
	for(e=0;e<pG->m;e++){
		int u=pG->edges[e].u;
		int v=pG->edges[e].v;
		int w=pG->edges[e].w;
		int root_u=findRoot(u);
		int root_v=findRoot(v);
		if(root_u!=root_v){
			add_edge(pT,u,v,w);
			parent[root_v]=root_u;
			sum_w+=w;
		}
	}
	return sum_w;
}
int main(){
	Graph G,T;
	int n,m,u,v,w,e;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(e=1;e<=m;e++){
		scanf("%d%d%d",&u,&v,&w);
		add_edge(&G,u,v,w);
	}
	int sum_w=Kruskal(&G,&T);
	printf("%d\n",sum_w);
	for(e=0;e<T.m;e++){
		printf("%d %d %d\n",T.edges[e].u,T.edges[e].v,T.edges[e].w);
	}
	return 0;
}
