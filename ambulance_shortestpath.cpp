#include<iostream>
#include<queue>

using namespace std;

class Graph
{
    int location; // number of vertices
    int **adjacent; // represent road between locations

public:
    Graph(int location)// constructor to initialize node
    {
        this->location = location;

        adjacent = new int*[location];
        for(int i = 0; i < location; i++) // initialize adjacent matrix with all elements 0
        {
            adjacent[i] = new int[location];
            for(int j = 0; j < location; j++)
            {
                adjacent[i][j] = 0;
            }
        }
    }

    void addedge(int u, int v)// add edge (road) between 2 nodes
    {
        // it is an undirected graph
        adjacent[u][v] = 1;
        adjacent[v][u] = 1;
    }

    int* mininteractionpath(int source, int destination)// BFS is used because it explores all node at depth and time complexity is also less O(V+E).
    {
        int* parent = new int[location];
        bool* visited = new bool[location];
        queue<int> q;

        for(int i = 0; i < location; i++)
        {
            parent[i] = -1; // initialize parent array with -1
            visited[i] = false; // initialize visited array as false
        }

        visited[source] = true;
        q.push(source);

        while(!q.empty())
        {
            int current = q.front();
            q.pop();

            if(current == destination) // we have reached the destination
                break;

            for(int i = 0; i < location; i++)
            {
                if(adjacent[current][i] && !visited[i])
                {
                    visited[i] = true;
                    parent[i] = current;
                    q.push(i);
                }
            }
        }

        if(!visited[destination])
        {
            delete[] parent;
            delete[] visited;
            return 0; // No path found
        }

        // Trace the path
        int pathsize = 0;
        int* temppath = new int[location];
        for(int i = destination; i != -1; i = parent[i])
        {
            temppath[pathsize++] = i;
        }

        // Reverse the path to get the correct order
        int* correctpath = new int[pathsize];
        for(int i = 0; i < pathsize; i++)
        {
            correctpath[i] = temppath[pathsize - i - 1];
        }

        delete[] temppath;
        delete[] visited;
        delete[] parent;

        return correctpath;
    }

    int* nonoverlappath(int source, int destination, bool* blockednode, bool** blockededge) // avoid usage of same node & edge
    {
        int* parent = new int[location];
        bool* visited = new bool[location];
        queue<int> q;

        for(int i = 0; i < location; i++)
        {
            parent[i] = -1; // initialize parent array with -1
            visited[i] = false; // initialize visited array as false
        }

        visited[source] = true;
        q.push(source);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            if(u == destination) break;

            for(int v = 0; v < location; v++)
            {
                if(adjacent[u][v] && !visited[v] && !blockednode[v] && !blockededge[u][v])
                {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        if(!visited[destination])
        {
            delete[] parent;
            delete[] visited;
            return 0; // No path found
        }

        // Trace the path
        int pathsize = 0;
        int* temppath = new int[location];
        for(int v = destination; v != -1; v = parent[v])
        {
            temppath[pathsize++] = v;
        }

        // Reverse the path to get the correct order
        int* correctpath = new int[pathsize];
        for(int i = 0; i < pathsize; i++)
        {
            correctpath[i] = temppath[pathsize - i - 1];
        }

        delete[] temppath;
        delete[] visited;
        delete[] parent;

        return correctpath;
    }
};



int main()
{
    int location;//getting nodes
    cout << "Enter the number of locations(nodes): ";
    cin >> location;
    Graph g(location);

    int E;//getting edges
    cout << "Enter the number of roads(edges): ";
    cin >> E;

    cout << "Enter the roads as pairs of intersections (u v):" << endl;
    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v);
    }

    int source, destination;
    cout << "Enter the source and destination intersections for minimum path: ";
    cin >> source >> destination;

    int* path = g.mininteractionpath(source, destination);
    if(path != 0)
    {
        cout << "Path with minimum intersections: ";
        for(int i = 0; path[i] != destination; i++)
        {
            cout << path[i] << " ";
        }
        cout << destination << endl;
        delete[] path;
    }
    else
    {
        cout << "No path found" << endl;
    }

    bool* blockednode = new bool[location];
    bool** blockededge = new bool*[location];
    for(int i = 0; i < location; i++)
    {
        blockededge[i] = new bool[location];
        for(int j = 0; j < location; j++)
        {
            blockededge[i][j] = false; // Initialize all to false
        }
        blockednode[i] = false;
    }

    if(path != 0)
    {
        for(int i = 0; path[i] != destination; i++)
        {
            blockednode[path[i]] = true;
        }
        for(int i = 0; path[i] != destination; i++)
        {
            blockededge[path[i]][path[i + 1]] = true;
            blockededge[path[i + 1]][path[i]] = true;
        }
    }

    cout << "Enter the source and destination intersections for the non overlapping path: ";
    cin >> source >> destination;

    int* altpath = g.nonoverlappath(source, destination, blockednode, blockededge);
    if(altpath != 0)
    {
        cout << "Non overlapping path: ";
        for(int i = 0; altpath[i] != destination; i++)
        {
            cout << altpath[i] << " ";
        }
        cout << destination << endl;
        delete[] altpath;
    }
    else
    {
        cout << "No non overlapping path found" << endl;
    }

    // Clean up dynamically allocated memory
    delete[] blockednode;
    for(int i = 0; i < location; i++)
    {
        delete[] blockededge[i];
    }
    delete[] blockededge;

    return 0;
}
