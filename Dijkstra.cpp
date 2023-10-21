#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int target;
    int weight;
};

// Custom comparator to compare pairs based on the first element.
struct ComparePair {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};


vector<int> dijkstra(const vector<vector<Edge>>& graph, int start) {
    int numVertices = graph.size();
    vector<int> distances(numVertices, INT_MAX);
    distances[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePair> minHeap;
    minHeap.push({0, start});

    while (!minHeap.empty()) {
        int dist = minHeap.top().first;
        int currentVertex = minHeap.top().second;
        minHeap.pop();

        if (dist > distances[currentVertex]) {
            continue;
        }

        for (const Edge& edge : graph[currentVertex]) {
            int neighbor = edge.target;
            int newDist = distances[currentVertex] + edge.weight;

            if (newDist < distances[neighbor]) {
                distances[neighbor] = newDist;
                minHeap.push({newDist, neighbor});
            }
        }
    }

    return distances;
}

int main() {
    int numVertices = 4;
    vector<vector<Edge>> graph(numVertices);

    graph[0].push_back({1, 1});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 5});
    graph[2].push_back({3, 1});

    int startVertex = 0;
    vector<int> shortestDistances = dijkstra(graph, startVertex);

    for (int i = 0; i < numVertices; i++) {
        cout << "Shortest distance from " << startVertex << " to " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
