// #define N (100000 + 5)

int *adj1[N];
int adj_cnt1[N] = {0};

int *adj2[N];
int adj_cnt2[N] = {0};

int was[N] = {0};
 
void add_directed_edge(int ** adj, int * adj_cnt, int u, int v) {
  int index = adj_cnt[u]++;
  int is_power_of_two = (index & (index - 1)) == 0;
  if (index >= 2 && is_power_of_two) {
    adj[u] = (int *) realloc(adj[u], index * 2 * sizeof(*adj[u]));
  }
  adj[u][index] = v;
}
 
void add_edge(int ** adj, int * adj_cnt, int u, int v) {
  add_directed_edge(adj, adj_cnt, u, v);
  add_directed_edge(adj, adj_cnt, v, u);
}

void add_edge1(int u, int v) {
  add_directed_edge(adj1, adj_cnt1, u, v);
  add_directed_edge(adj1, adj_cnt1, v, u);
}

void add_edge2(int u, int v) {
  add_directed_edge(adj2, adj_cnt2, u, v);
  add_directed_edge(adj2, adj_cnt2, v, u);
}

void dfs(int u) {
  was[u] = 1;
  forn(i, adj_cnt1[u]) {
    int v = adj1[u][i];
    if (!was[v]) {
      dfs(v);
    }
  }
}
 
void init_graph() {
  for (int i = 0; i < ...; i++) {
    adj1[i] = (int *) malloc(2 * sizeof(*adj1[i]));
    adj2[i] = (int *) malloc(2 * sizeof(*adj2[i]));
  }
}
// do not forget to initiate it
// init_graph()
// forn(i, m) {
//   int from, to;
//   scanf("%d%d", &from, &to);
//   from--, to--;
//   add_edge1(from, to);
// }