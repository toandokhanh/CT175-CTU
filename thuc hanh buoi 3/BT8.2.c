#include <stdio.h>

#define MAXM 500
#define MAXN 100
#define oo 999999
#define NO_EDGE -999999

typedef struct {
    int u, v;
    int w;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAXM];
} Graph;

void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v, int w) {
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->edges[pG->m].w = w;

    pG->m++;
}


int pi[MAXN];
int p[MAXN];

int BellmanFord(Graph *pG, int s) {
	int u, v, w, it, k;
	for (u = 1; u <= pG->n; u++) {
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1; //tru?c d?nh s kh�ng c� d?nh n�o c?

	// l?p n-1 l?n
	for (it = 1; it < pG->n; it++) {
		// Duy?t qua c�c cung v� c?p nh?t (n?u tho?)
		for (k = 0; k < pG->m; k++) {
			u = pG->edges[k].u;
			v = pG->edges[k].v;
			w = pG->edges[k].w;
			
			if (pi[u] == oo)    //chua c� du?ng di t? s -> u, b? qua cung n�y
			    continue;
			    
			if (pi[u] + w < pi[v]) {
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
	//L�m th�m 1 l?n n?a d? ki?m tra chu tr�nh �m (n?u c?n thi?t)
	for (k = 0; k < pG->m; k++) {
		u = pG->edges[k].u;
		v = pG->edges[k].v;
		w = pG->edges[k].w;
		
		if (pi[u] == oo)    //chua c� du?ng di t? s -> u, b? qua cung n�y
		    continue;
		    
		if (pi[u] + w < pi[v]) {
			return 1;
		}
	}
	return 0;
}

int cube(int x) {
    return x*x*x;
}

int main() {
    Graph G;
    int n, m,u,e;
    
    int b[MAXN];
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for (u = 1; u <= n; u++)
        scanf("%d", &b[u]);

    for (e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v, cube(b[v] - b[u]));
        //add_edge(&G, v, u, cube(b[u] - b[v]));
    }
    int s, t;
    scanf("%d%d", &s, &t);
    
    BellmanFord(&G, s);
    if (pi[t] < oo)
        printf("%d\n", pi[t]);
    else
        printf("?\n");
    

    return 0;
}
