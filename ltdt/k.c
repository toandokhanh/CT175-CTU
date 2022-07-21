#include <stdio.h>
#define oo 999999
#define MAX_N 100
#define NO_EDGE -999999
typedef int ElementType;
typedef struct{
	int n,m;
	int A[MAX_N][MAX_N];
}Graph;
void init_graph(Graph *pG, int n){
	pG->n=n;
	pG->m=0;
	int u,v;
	for(u=1; u<=n; u++)
		for(v=1; v<=n; v++)
			pG->A[u][v]=0;
}

void add_edge(Graph *pG, int u, int v){
	pG->A[u][v]=1;
	pG->A[v][u]=1;
	pG->m++;
}
int adjacent(Graph *pG,int u,int v){
	return pG->A[u][v]>0;
}
typedef struct{
	int u,p;
}ElementType;
typedef struct{
	ElementType data[MAX_SIZE];
	int front,rear;
}Queue;
void make_null_queue(Queue *pQ){
	pQ->front=0;
	pQ->rear=-1;
}
void enqueue(Queue *pQ,ElementType u){
	pQ->rear++;
	pQ->data[pQ->rear]=u;
}
int empty(Queue *pQ){
	return pQ->front > pQ->rear;
}
ElementType front(Queue *pQ){
	return pQ->data[pQ->front];
}
void dequeue(Queue *pQ){
	pQ->front++;
}
#define NO_COLOR 0
#define BLUE 1
#define RED 2
int color[MAX_N];
int conflict;
void colorize(Graph *pG,int u,int c){
	color[u]=c;
	int v;
	for(v=1;v<=pG->n;v++){
		if(adjacent(pG,u,v)){
			if(color[v]==NO_COLOR)
				colorize(pG,v,3-c);
			else if(color[v]==color[u])
				conflict=1;	
		}
	}
}
int is_color(Graph *pG){
	int u;
	for(u=1;u<=pG->n;u++){
		color[u]=NO_COLOR;
	}
	conflict=0;
	colorize(pG,1,BLUE);
	return !conflict;
}
int main(){
	Graph G;
	int n,m,u,v,e;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(e=0;e<m;e++) {
    	scanf("%d%d",&u,&v);
    	add_edge(&G,u,v);
	}
	if(is_color(&G)){
		int i;
		for(i=1;i<=G.n;i++){
			if(color[i]==RED){
				printf("%d ",i);
			}
		}
		printf("\n");
		for(i=1;i<=G.n;i++){
			if(color[i]==BLUE){
				printf("%d ",i);
			}
		}
	}
	else printf("IMPOSSIBLE");
	return 0;
}
