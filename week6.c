#include <stdio.h>

#define INFINITY 999
#define MAX 10

struct RoutingTable {
    int dist[MAX];    // Distance to each node
    int nextHop[MAX]; // Next hop for each node
} rt[MAX];

int main() {
    int costMatrix[MAX][MAX];
    int nodes, i, j, k, count;

    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the cost adjacency matrix (use %d for infinity):\n", INFINITY);
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &costMatrix[i][j]);
            rt[i].dist[j] = costMatrix[i][j];
            rt[i].nextHop[j] = j; // Initially, assume direct connection
        }
    }

    // Distance Vector Algorithm (Bellman-Ford relaxation)
    do {
        count = 0;
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                for (k = 0; k < nodes; k++) {
                    if (rt[i].dist[j] > costMatrix[i][k] + rt[k].dist[j]) {
                        rt[i].dist[j] = costMatrix[i][k] + rt[k].dist[j];
                        rt[i].nextHop[j] = k; // Update next hop
                        count++;
                    }
                }
            }
        }
    } while (count != 0);

    // Print the routing tables
    for (i = 0; i < nodes; i++) {
        printf("\nRouting table for Node %d:\n", i);
        printf("Destination\tNext Hop\tDistance\n");
        for (j = 0; j < nodes; j++) {
            if (j != i) {
                printf("%d\t\t%d\t\t%d\n", j, rt[i].nextHop[j], rt[i].dist[j]);
            }
        }
    }

    return 0;
}
