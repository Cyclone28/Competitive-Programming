struct UnionFind{
    vector<int> par; 
    vector<int> rank; 
    int num;
    UnionFind(int N){
        num = N;
        rank.resize(N);
        par.resize(N);
        for(int i  = 0; i < N; i++) {
            rank[i] = 0;
            par[i] = i;
        }
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(rank[x] > rank[y]){
            swap(x, y);
        }
        if(rank[x] == rank[y]) rank[y]++;
        par[x] = y;
        num--;
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
    int count() const{
        return num;
    }
};