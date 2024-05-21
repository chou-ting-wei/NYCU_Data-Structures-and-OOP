#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

vector<int> bellmanFord(int N, int S, const vector<Edge>& edges) {
    vector<int> dist(N + 1, INF);
    dist[S] = 0;
    
    for(int i = 1; i < N; i ++){
        for(const Edge& edge : edges){
            int from = edge.from;
            int to = edge.to;
            int weight = edge.weight;
            if(dist[from] != INF && dist[from] + weight < dist[to]){
                dist[to] = dist[from] + weight;
            }
        }
    }

    for(const Edge& edge : edges){
        int from = edge.from;
        int to = edge.to;
        int weight = edge.weight;
        if(dist[from] != INF && dist[from] + weight < dist[to]){
            return vector<int>(N + 1, INF);
        }
    }

    return dist;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    int S, T;
    cin >> S >> T;

    vector<int> dist = bellmanFord(N, S, edges);
    int result = dist[T] == INF ? -1 : dist[T];
    cout << result << endl;

    return 0;
}