#include <stdio.h>

#define INF 30000
#define MAX 10

int main() {
    int n, v, u, num, i, j, min;
    int cost[MAX][MAX], dist[MAX], path[MAX], S[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter Adjacency Matrix (use -1 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i == j)
                cost[i][j] = 0;
            else if (cost[i][j] == -1)
                cost[i][j] = INF;
        }
    }

    printf("Enter Source Vertex (0 to %d): ", n - 1);
    scanf("%d", &v);

    // Initialization
    for (i = 0; i < n; i++) {
        S[i] = 0;
        dist[i] = cost[v][i];
        path[i] = v;
    }
    dist[v] = 0;
    S[v] = 1;

    // Dijkstra’s Algorithm
    for (num = 1; num < n; num++) {
        min = INF;
        u = -1;
        for (i = 0; i < n; i++) {
            if (!S[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        S[u] = 1;

        for (i = 0; i < n; i++) {
            if (!S[i] && dist[i] > dist[u] + cost[u][i]) {
                dist[i] = dist[u] + cost[u][i];
                path[i] = u;
            }
        }
    }

    // Print result
    printf("\nShortest paths from source %d:\n", v);
    for (i = 0; i < n; i++) {
        if (i == v) continue;
        printf("To node %d: Distance = %d, Path = %d", i, dist[i], i);
        j = i;
        while (j != v) {
            j = path[j];
            printf(" <- %d", j);
        }
        printf("\n");
    }

    return 0;
}
