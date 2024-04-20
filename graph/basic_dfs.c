// #define N (100000 + 5)

int *adj[N];
int adj_cnt[N] = {0};
int was[N] = {0};
 
void add_directed_edge(int u, int v) {
  int index = adj_cnt[u]++;
  int is_power_of_two = (index & (index - 1)) == 0;
  if (index >= 2 && is_power_of_two) {
    adj[u] = (int *) realloc(adj[u], index * 2 * sizeof(*adj[u]));
  }
  adj[u][index] = v;
}
 
void add_edge(int u, int v) {
  add_directed_edge(u, v);
  add_directed_edge(v, u);
}

void dfs(int u) {
  was[u] = 1;
  forn(i, adj_cnt[u]) {
    int v = adj[u][i];
    if (!was[v]) {
      dfs(v);
    }
  }
}
 
void init_graph() {
  for (int i = 0; i < ...; i++) {
    adj[i] = (int *) malloc(2 * sizeof(*adj[i]));
  }
}
// do not forget to initiate it
// init_graph()
// forn(i, m) {
//   int from, to;
//   scanf("%d%d", &from, &to);
//   from--, to--;
//   add_edge(from, to);
// }