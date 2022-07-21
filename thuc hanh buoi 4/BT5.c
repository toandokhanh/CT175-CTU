#include<stdio.h>
#define MAX_N 100
#define oo 999999
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
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int min(int a,int b){
	if(a>b) return b;
	else return a;
}
int d[MAX_N];
int main(){
	Graph G;
	int n,u,x,v,j;
	scanf("%d",&n);
	init_graph(&G,n+2);
	int alpha=n+1,beta=n+2;
	d[alpha]=0;
	for(u=1;u<=n;u++){
		scanf("%d",&d[u]);
		do{
			scanf("%d",&x);
			if(x>0)
				add_edge(&G,x,u);
		}while(x>0);
	}
	for(u=1;u<=n;u++){
		int deg_neg=0;
		for(x=1;x<=n;x++){
			if(G.A[x][u]>0)
				deg_neg++;		
		}
		if(deg_neg==0)
			add_edge(&G,alpha,u);
	}
	for(u=1;u<=n;u++){
		int deg_pos=0;
		for(v=1;v<=n;v++){
			if(G.A[u][v]>0)
				deg_pos++;
		}
		if(deg_pos==0)
			add_edge(&G,u,beta);
	}
	List L;
	topo_sort(&G,&L);
	int t[MAX_N];
	t[alpha]=0;
	for(j=2;j<=L.size;j++){
		int u=element_at(&L,j);
		t[u]=-oo;
		for(x=1;x<=G.n;x++)
			if(G.A[x][u]>0)
				t[u]=max(t[u],t[x]+d[x]);
	}
	int T[MAX_N];
	T[beta]=t[beta];
	for(j=L.size-1;j>=1;j--){
		int u=element_at(&L,j);
		T[u]=+oo;
		for(v=1;v<=G.n;v++)
			if(G.A[u][v]>0)
				T[u]=min(T[u],T[v]-d[u]);
	}
	for(u=1;u<=n;u++){
		printf("%d %d\n",t[u],T[u]);
	}
	return 0;
}
