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
		for(v=1;v<=n;v++)
			pG->A[u][v]=0;
	}
}
void add_edge(Graph *pG,int u,int v) {
    pG->A[u][v]+=1;
}
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
} List;

void make_null(List* L) {
	L->size = 0;
}

void push_back(List* L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}

ElementType element_at(List* L, int i) {
	return L->data[i-1];
}

int count_list(List* L) {
	return L->size;
}

int empty_list(List* L) {
	return L->size == 0;
}
typedef struct{
	int data[MAX_N];
	int front,rear;
}Queue;
void make_null_queue(Queue *pQ){
	pQ->front=0;
	pQ->rear=-1;
}
void enqueue(Queue *pQ,int u){
	pQ->rear++;
	pQ->data[pQ->rear]=u;
}
int empty_queue(Queue *pQ){
	return pQ->front > pQ->rear;
}
int front(Queue *pQ){
	return pQ->data[pQ->front];
}
void dequeue(Queue *pQ){
	pQ->front++;
}
void topo_sort(Graph *pG,List *pL){
	int d[MAX_N];
	int u,x;
	for(u=1;u<=pG->n;u++){
		d[u]=0;
		for(x=1;x<=pG->n;x++)
			if(pG->A[x][u]!=0)
				d[u]++;
	}
	Queue Q;
	make_null_queue(&Q);
	for(u=1;u<=pG->n;u++)
		if(d[u]==0)
			enqueue(&Q,u);
	make_null(pL);
	while(!empty_queue(&Q)){
		int u=front(&Q);
		dequeue(&Q);
		push_back(pL,u);
		int v;
		for(v=1;v<=pG->n;v++)
			if(pG->A[u][v]!=0){
				d[v]--;
				if(d[v]==0)
					enqueue(&Q,v);
			}
	}		
}
int main(){
	Graph G;
	int n,m,u,e,v,i;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(e=0;e<m;e++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	List L;
	topo_sort(&G,&L);
	for(i=1;i<=L.size;i++){
		printf("%d ",element_at(&L,i));
	}
	return 0;
}