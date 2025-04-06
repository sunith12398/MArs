#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 11  // Arena size (0 to 10 for 11x11 grid)

// Directions for movement: North, East, South, West
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// Queue for BFS
typedef struct {
    int x, y, dist;
} Node;

Node queue[N * N];
int front = 0, rear = 0;

// Enqueue operation
void enqueue(Node node) {
    queue[rear++] = node;
}

// Dequeue operation
Node dequeue() {
    return queue[front++];
}

// Check if the position is within bounds and safe
bool isSafe(int x, int y, int arena[N][N], bool visited[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && arena[x][y] == 1 && !visited[x][y]);
}

// BFS to find the shortest path
int bfs(int arena[N][N], int startX, int startY, int endX, int endY) {
    bool visited[N][N] = {false};
    enqueue((Node){startX, startY, 0});
    visited[startX][startY] = true;

    while (front != rear) {
        Node current = dequeue();

        if (current.x == endX && current.y == endY) {
            return current.dist;  // Shortest path found
        }

        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isSafe(newX, newY, arena, visited)) {
                visited[newX][newY] = true;
                enqueue((Node){newX, newY, current.dist + 1});
            }
        }
    }
    return -1;  // No path found
}

int main() {
    int arena[N][N];
    FILE *file = fopen("sample.txt", "r");
    if (!file) {
        printf("Error opening sample.txt\n");
        return 1;
    }

    // Initialize arena with safe positions
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            arena[i][j] = 1;

    // Read obstacle data and mark obstacles as 0
    int north, east, south, west;
    while (fscanf(file, "%d %d %d %d", &north, &east, &south, &west) == 4) {
        arena[north][east] = 0;
        arena[south][west] = 0;
    }
    fclose(file);

    // Print the arena
    printf("Arena Map:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", arena[i][j]);
        }
        printf("\n");
    }

    // Calculate the shortest path from [0,0] to [10,10]
    int shortestPath = bfs(arena, 0, 0, 10, 10);
    if (shortestPath != -1) {
        printf("Shortest path from [0,0] to [10,10] is: %d steps\n", shortestPath);
    } else {
        printf("No path found from [0,0] to [10,10].\n");
    }

    return 0;
}
