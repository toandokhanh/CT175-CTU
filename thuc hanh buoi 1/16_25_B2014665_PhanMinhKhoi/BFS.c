#include<stdio.h>
#define MAX_Vertices 20
#define MAX_Length 20
#define MAX_Element 40
typedef struct{
	int A[MAX_Vertices][MAX_Vertices];
	int n;//so luong dinh//
}Graph;
typedef struct{
	int data[MAX_Length];
	int size;
}List;
void init_Graph(Graph *G,int n){
	int i,j;
	G->n=n;
	for(i=1;i<=n;i++){//dong cua ma tran//
		for(j=1;j<=n;j++){//cot cua ma tran//
			G->A[i][j]=0;
		}
	}
}
//them cung vao do thi//
void add_edge(Graph *G,int x,int y){
	G->A[x][y]=1;
	G->A[y][x]=1;
}	
//kiem tra 2 cap dinh co phai la lang gieng cua nhau hay khong//
int adjacent(Graph *G,int x,int y){
	return (G->A[x][y]!=0);
}	
//tinh bac cua dinh x trong do thi//
int degree(Graph *G,int x){
	int deg=0,i;
	for(i=1;i<=G->n;i++){
		if(adjacent(G,i,x)){
			deg++;
		}
	}
	return deg;
}		
//ham khoi tao danh sach rong
void make_null(List *list){
	list->size=0;
}	
//them 1 phan tu vao cuoi danh sach
void push_back(List *list,int x){
	list->data[list->size]=x;
	list->size++;
}
//lay 1 phan tu (dinh) trong danh sach tai vi tri i
int element_at(List *list,int i){
	return list->data[i-1];
}
//tim lang gieng cua dinh x
List neighbors(Graph *G, int x){
	List L;
	make_null(&L);
	int i;
	for(i=1;i<=G->n;i++){
		if(G->A[i][x]==1){
			push_back(&L,i);
		}
	}
	return L;
}
typedef struct{
	int data[MAX_Element];
	int front;
	int rear;
}Queue;
void make_null_Queue(Queue *Q){
	Q->front=0;
	Q->rear=-1;
}
void push_Queue(Queue *Q,int x){
	Q->rear++;
	Q->data[Q->rear]=x;
}
int empty_Queue(Queue *Q){
	return Q->front > Q->rear;
}
int top(Queue *Q){
	return Q->data[Q->front];
}
void pop(Queue *Q){
	Q->front++;
}
List breath_first_search(Graph *G,int x,int parent[]){
	Queue Q;
	make_null_Queue(&Q);
	int mark[MAX_Vertices];
	int i;
	for(i=1;i<=G->n;i++)
		mark[i]=0;
	push_Queue(&Q,1);
	parent[x]=0;
	List L_bfs;
	make_null(&L_bfs);
	while(!empty_Queue(&Q)){
		int u=top(&Q);
		pop(&Q);
		if(mark[u]==1)
			continue;
		push_back(&L_bfs,u);
		mark[u]=1;
		List L;
		make_null(&L);
		L=neighbors(G,u);
		int v;
		for(i=1;i<=L.size;i++){
			v=element_at(&L,i);
			if(mark[v]==0){
				push_Queue(&Q,v);
				if(parent[v]==-1)
					parent[v]=u;
		}
		}	
	}
	return L_bfs;
}
int main(){
	Graph G;
	freopen("BFS_Data.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	init_Graph(&G,n);
	int e,x,y;
	for(e=1;e<=m;e++){
		scanf("%d%d",&x,&y);
		add_edge(&G,x,y);
	}
	int mark_bfs[MAX_Vertices],parent[MAX_Vertices],u;
	for(u=1;u<=G.n;u++){
		mark_bfs[u]=0;	
		parent[u]=-1;
	}
	for(u=1;u<=G.n;u++){
		if(mark_bfs[u]==0){
		    List L=breath_first_search(&G,u,parent);
			int i,v;
			for(i=1;i<=L.size;i++){
				v=element_at(&L,i);
				printf("%d\n",v);
				mark_bfs[v]=1;
    		}
    	}	
	}
	for(u=1;u<=G.n;u++){
		printf("parent[%d] = %d\n",u,parent[u]);
	}
	return 0;
}
