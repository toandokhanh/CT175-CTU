#include<stdio.h>
#define MAX_N 100 
typedef struct{ 
	int n,m; 
	int A[MAX_N][MAX_N]; 
}Graph; 
void init_graph(Graph *G,int n){ 
	int i,j; 
	G->n=n; 
	for(i=1;i<=n;i++){ 
		for(j=1;j<=n;j++){ 
			G->A[i][j]=0; 
		} 
	} 
} 
void add_edge(Graph *G,int x,int y){ 
	G->A[x][y]=1; 
	G->A[y][x]=1; 
} 
int adjacient(Graph *G,int x,int y){ 
	return G->A[x][y]!=0; 
} 
void neighbours(Graph *pG,int u){
	int v,j;
	for(v=1;v<=pG->n;v++){
		for(j=1;j<=pG->A[u][v];j++){
			printf("%d ",v);
		}
	}
	printf("\n");
}	
int main(){ 
	Graph G; 
	int n,i,j,e,x,y; 
	int flag=0; 
	scanf("%d",&n); 
	init_graph(&G,n); 
	for(i=1;i<=n;i++){ 
		for(j=1;j<=n;j++){ 
			scanf("%d",&e); 
			if(e==1) 
				add_edge(&G,i,j); 
		} 
	} 
	scanf("%d%d",&x,&y); 
	for(i=1;i<=n;i++){ 
		if((adjacient(&G,x,i)==1)&&(adjacient(&G,y,i)==1)){ 
			printf("%d ",i);
			flag=1;
		} 
	}  
	if(flag==0){
		printf("KHONG CHUNG DOI THU");
	}	
	return 0;
}
