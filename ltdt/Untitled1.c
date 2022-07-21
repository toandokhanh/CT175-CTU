#include<stdio.h>
#define MAX_N 10
typedef struct{
	int n,m;//n la so dinh, m la so cung
	int A[MAX_N][MAX_N];
}Graph;
void init_graph(Graph *G, int n){
	G->n=4;
	G->m=7;
	int i,j;
	for(i=1;i<=G->n;i++){
		for(j=1;j<=G->n;j++)
			G->A[i][j]=0;
	}
}
//void add_edge(Graph *G,int x,int y){
	//G->A[x][y]=1;
	//G->A[y][x]=1;
	//G->m++;
//}
void add_edge(Graph *G,int x,int y){
	if(x==y){
		G->A[x][y]++;
	}
	else{
		G->A[x][y]++;
		G->A[y][x]++;
	}
	G->m++;
}
int adjacent(Graph *G,int u,int v){
	return (G->A[u][v]!=0);
}	
int degree(Graph *G,int v){
	int u,deg=0;
	for(u=1;u<=G->n;u++)
		if(G->A[u][v]!=0)
			deg+=G->A[u][v];
	deg=deg+G->A[v][v];
	return deg;
}		
int main(){
	Graph G;
	int n,m,u,v,e;
	freopen("dt.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(e=1;e<=m;e++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}	
	int i,j;
	for(i=1;i<=G.n;i++){
		for(j=1;j<=G.n;j++){
			printf("%d ",G.A[i][j]);
		}	
		printf("\n");
	}	
	for(u=1;u<=G.n;u++)
		printf("deg(%d) = %d\n",u,degree(&G,u));
	return 0;
}	
