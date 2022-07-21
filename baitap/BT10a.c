#include <stdio.h>
#define MAX_N 100
typedef struct{
	int n,m;
	int A[MAX_N][MAX_N];
}Graph;

void init_graph(Graph *pG, int n){
	int i,j;
	pG->n=n;
	pG->m=0;
	for(i=1;i<=n;i++) 
		for(j=1;j<=n;j++)
			pG->A[i][j]=0;
}

void add_edge(Graph *pG, int u, int v){
	if(u==v){
		pG->A[u][v]++;
	}
	else{	
		pG->A[u][v]++;
		pG->A[v][u]++;
	}	
	pG->m;
}

int degree(Graph *pG, int u){
	int i, deg=0;
	for(i=1;i<=pG->n;i++)
			deg+=pG->A[u][i];
		return deg+pG->A[u][u];
}

int main(){
	Graph G;
	int m,n,u,v,e;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(e= 0;e<m;e++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	for(u=1;u<=G.n;u++){
		printf("degree(%d) = %d\n",u,degree(&G,u));
	}
	
	return 0;
}
