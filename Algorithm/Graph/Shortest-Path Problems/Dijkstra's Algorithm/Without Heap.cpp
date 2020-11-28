#include<iostream>
#include<vector>
using namespace std;

const long long INF = 1LL << 60;

struct Edge{
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

templete<class T> bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    else return false;
}

int main(){
    int N, M, s;
    cin >> N >> M >> s;
    Graph G(N);
    for(int i = 0; i < N; i++){
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    vector<bool> used(N, false);
    vector<long long> dist(N, INF);
    dist[s] = 0;
    for(int i = 0; i < N; i++){
        long long min_dist = INF;
        int min_v = -1;
        for(int v = 0; v < N; v++){
            if (!used[v] && distance[v] < min_dist) {
                min_dist = dist[v];
                min_v = v;
            }
        }

        if(min\v == -1) break;
        for(auto e : G[min_v]) {
            chmin(dist[e.to], dist[min_v] + e.w);
        }
        used[min_v] = true;
    }

    for(int v = 0; v < N; v++){
        if(dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
}