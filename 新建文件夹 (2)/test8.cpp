#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1000005;
const int MOD = 100003;

vector<int> graph[MAXN];
int dist[MAXN];
int ways[MAXN];

int main() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    ways[1] = 1;
    
    queue<int> q;
    q.push(1);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : graph[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                ways[v] = ways[u];
                q.push(v);
            } else if (dist[v] == dist[u] + 1) {
                ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        cout << ways[i] << endl;
    }
    
    return 0;
}
