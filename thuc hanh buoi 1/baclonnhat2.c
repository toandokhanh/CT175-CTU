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
		for(v=1;v<=n;v++){
			pG->A[u][v]=0;
		}
	}
}
void add_edge(Graph *pG,int u,int v){
	pG->A[u][v]=1;
	pG->A[v][u]=1;
	pG->m++;
}
int degree(Graph *pG,int u){
	int deg_u=0;
	int v;
	for(v=1;v<=pG->n;v++){
		deg_u+=pG->A[u][v];
	}
	return deg_u;
}
void baclonnhat(Graph *pG){
	int u,max=0,i;
	for(i=1;i<=pG->n;i++){
		if(degree(pG,i)>max){
			max=degree(pG,i);
			u=i;
		}
	}
	printf("%d %d",u,max);
}
int main(){
	Graph G;
	int n,m,e,u,v;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(e=0;e<m;e++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	baclonnhat(&G);
	return 0;
}
