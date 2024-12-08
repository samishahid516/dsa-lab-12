#include <iostream>
#include <climits>

using namespace std;

const int MAX_NODES = 5;

class Graph {
private:
    int matrix[MAX_NODES][MAX_NODES];

public:

    Graph() {
        for (int i = 0; i < MAX_NODES; i++) {
            for (int j = 0; j < MAX_NODES; j++) {
                if (i == j) {
                    matrix[i][j] = 0;
                }
                else {
                    matrix[i][j] = INT_MAX;
                }
            }
        }
    }


    void addConnection(int from, int to, int weight) {
        matrix[from][to] = weight;
        matrix[to][from] = weight;
    }


    void removeConnection(int from, int to) {
        matrix[from][to] = INT_MAX;
        matrix[to][from] = INT_MAX;
    }


    void showMatrix() {
        cout << "       ";
        for (int i = 0; i < MAX_NODES; i++) {
            cout << "V" << i << "   ";
        }
        cout << endl;

        for (int i = 0; i < MAX_NODES; i++) {
            cout << "V" << i << " | ";
            for (int j = 0; j < MAX_NODES; j++) {
                if (matrix[i][j] == INT_MAX)
                    cout << "INF   ";
                else
                    cout << matrix[i][j] << "    ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;


    g.addConnection(0, 1, 15);
    g.addConnection(0, 4, 25);
    g.addConnection(1, 4, 35);
    g.addConnection(1, 3, 45);


    cout << "Adjacency Matrix with Weights:" << endl <<endl;
    g.showMatrix();

    return 0;
}