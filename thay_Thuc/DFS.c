#include <stdio.h>
#define MAX_Vertices 20 // so dinh lon nhat trong ma tran
#define MAX_Length 20
#define MAX_Element 40
typedef struct{
	int A[MAX_Vertices][MAX_Vertices];
	int n; //so luong dinh
}Graph;
// khoi tao do thi
void init_Graph(Graph *G, int n){ 
	G->n = n;
	int i, j;
	for(i= 1; i<=n; i++) // dong cua ma tran
		for(j= 1; j<=n; j++) // cot cua ma tran
			G->A[i][j] = 0;		
}
// them cung vao do thi cho do thi vo huong
void add_edge(Graph *G, int x, int y){
	G->A[x][y] = 1;
	G->A[y][x] =1;
}
//kiem tra x va y co la lang gieng hay khong?
int adjacent(Graph *G, int x, int y){
	printf("%d la lang gieng cua %d : %d" ,x,y,(G->A[x][y] != 0));
	printf("\n1 là dung");
	printf("\n0 là sai");
	return 0;
}
//ham tinh bac cua dinh x trong do thi
int degree(Graph *G, int j){
	int deg = 0, i;
	for(i=1; i<=G->n;i++){
		if(G->A[i][j] == 1)
			deg++;
	}
	return deg;
}
//Khai bao cau truc danh sach
typedef struct{
	int data[MAX_Length];
	int size;
}List;

//ham khoi tao danh sach
void make_null(List *list){
	list->size = 0;
};

// thêm 1 phan tu vao cuoi danh sach
void push_back(List *list, int x){
	list->data[list->size] = x;
	list->size++;
};

// lay 1 phan tu trong danh sach tai vi tri i
int element_at(List *list, int i){
	return list->data[i-1];	
};
// tim lang gieng cua dinh x
List neighbors(Graph *G, int x ){
	List L;
	make_null(&L);
	int i;
	for(i=1; i<=G->n; i++)
		if(G->A[i][x] == 1){
			push_back(&L, i); 
		}
		return L;
}
// khai báo cau truc ngan xep
typedef struct{
	int data[MAX_Element];
	int size;
}Stack;

// khoi tao stack rong
void make_null_stack(Stack *stack){
	stack->size = 0;
}

// them 1 phan tu vao stack
void push_stack(Stack *stack, int x){
	stack->data[stack->size] = x;
	stack->size++;
}

// lay 1 phan tu trong stack tai vi tri i
int top(Stack *stack){
	return stack->data[stack->size - 1];	
};

//xoa 1 phan tu trong stack
void pop(Stack *stack){
	stack->size--;
}
// kiem tra stack co rong hay khong
int empty(Stack *stack){
	return stack->size == 0;
}
//thuat toan duyet theo chieu sau
void DFS(Graph *G, int x){
	Stack S;
	make_null_stack(&S);
	push_stack(&S, x); 
	int mark[MAX_Vertices];
	int i, j;
	for(i=1; i<=G->n ; i++)
		mark[i] =0;
	while(!empty(&S)){
		int u = top(&S);
		pop(&S);
		if(mark[u] == 1)  
			continue;
		printf("Duyet: %d\n",u );
		mark[u] = 1;
		List list = neighbors(G, u);
		for(i=1; i<=list.size; i++){
			int v = element_at(&list, i);  
			if(mark[v] == 0 ){
				push_stack(&S, v);
			}
	}
}
}
int main(){	
	Graph G;
//	int i, j;
	int n,m; //n la so luong dinh | m la so luong cung 
	freopen("DFS.txt", "r", stdin);
	scanf("%d%d", &n,&m);
	init_Graph(&G, n);
	int u, v , e; 
	for(e = 1; e<=m; e++){
		scanf("%d%d", &u,&v);
		add_edge(&G, u, v);
	}
	int i, j;
	for(i= 1; i<=G.n; i++){ 
		for(j= 1; j<=G.n; j++)
			printf("%d ", G.A[i][j]);
		printf("\n");
	}
	DFS(&G, 1); 
	return 0;
}
