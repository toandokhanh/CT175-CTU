#include<stdio.h>
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
void add_edge(Graph *pG,int u,int v,int w){
	pG->edges[pG->m].u=u;
	pG->edges[pG->m].v=v;
	pG->edges[pG->m].w=w;
	pG->m++;
}
void BellmanFord(Graph *pG,int s){
	int u,v,w,it,k;
	for(u=1;u<=pG->n;u++){
		pi[u]=oo;
	}
	pi[s]=0;
	p[s]=-1;
	for(it=1;it<pG->n;it++){
		for(k=0;k<pG->m;k++){
			u=pG->edges[k].u;
			v=pG->edges[k].v;
			w=pG->edges[k].w;
			if(pi[u]==oo)
				continue;
			if(pi[u]+w<pi[v]){
				pi[v]=pi[u]+w;
				p[v]=u;
			}	
		}
	}
}
int main(){
	Graph G;
	int n,m,u,v,e,w;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(e=0;e<m;e++){
		scanf("%d%d%d",&u,&v,&w);
		add_edge(&G,u,v,w);
	}
	int s,t;
	scanf("%d%d",&s,&t);
	BellmanFord(&G,s);
	if(pi[n]!=oo){
    	printf("%d",pi[n]);
	}
	else if(pi[n]==oo) printf("-1");
	return 0;
}
