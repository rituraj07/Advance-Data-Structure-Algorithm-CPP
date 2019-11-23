int find(int v){
	return (v == par[v])? v : (par[v] = find(par[v]));
}
void setP(int u, int v){
	u = find(u); v = find(v);
	if (u != v) {
		par[u] = v;
	}
}