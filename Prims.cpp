#define infinity 9999
#define MAX 20

#include<iostream>
using namespace std;

class graph
{
    int G[ MAX ][ MAX ];
    int n;


public:
    graph() {
        n = 0;
    }

    void readgraph();
    void printgraph();
    int prims( graph& );

};

void graph::readgraph()
{
    int i, j, vi, vj, no_of_edges, weight;
    cout << "\nEnter number of vertices :";
    cin >> n;
    cout << "Enter number of edges :";
    cin >> no_of_edges;
    for ( i = 0; i < n; i++ ) {      // initialize adjacency matrix to 0
        for ( j = 0; j < n; j++ ) {
            G[ i ][ j ] = 0;
        }
    }
    cout << "Enter the list of edges";
    for ( i = 0; i < no_of_edges; i++ ) {
        cout << "\nEnter an edge (u,v,weight)  :";
        cin >> vi >> vj >> weight;
        G[ vi ][ vj ] = G[ vj ][ vi ] = weight;


    }
}

void graph::printgraph() {
    int i, j;
    cout << "\nList of edges in the spanning tree :";
    for ( i = 0; i < n - 1; i++ )           //scan upper triangle of the adjacncyc matrix
        for ( j = i + 1; j < n; j++ )
            if ( G[ i ][ j ] != 0 )

                cout << "\n(u,v,weight) = (" << i << "," << j << "," << G[ i ][ j ] << ")";
}


int graph::prims( graph& spanning )
{
    int cost[ MAX ][ MAX ];
    int u, v, min_distance, distance[ MAX ], from[ MAX ];
    int visited[ MAX ], no_of_edges, i, min_cost, j;
    spanning.n = n;

    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ )
        {
            if ( G[ i ][ j ] == 0 ) {
                cost[ i ][ j ] = infinity;
            }
            else {
                cost[ i ][ j ] = G[ i ][ j ];
            }

        }
    }

    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            spanning.G[ i ][ j ] = 0;
        }
    }
    // initialize distance , vertex[], visited[]
    distance[ 0 ] = 0; visited[ 0 ] = 1;

    for ( i = 0; i < n; i++ ) {
        distance[ i ] = cost[ 0 ][ i ];
        from[ i ] = 0;
        visited[ i ] = 0;
    }

    min_cost = 0;
    no_of_edges = n - 1;
    while ( no_of_edges > 0 ) {

        //find vertex at minimum dstance from te tree

        min_distance = infinity;
        for ( int i = 0; i < n; i++ )
            if ( visited[ i ] == 0 && distance[ i ] < min_distance )
            {
                v = i;
                min_distance = distance[ i ];
            }
        u = from[ v ];
        //insert the edge in spanning tree
        spanning.G[ u ][ v ] = distance[ v ];
        spanning.G[ v ][ u ] = distance[ v ];
        min_cost = min_cost + cost[ u ][ v ];

        no_of_edges--;
        visited[ v ] = 1;

        //update the distance[] array

        for ( i = 1; i < n; i++ ) {
            if ( visited[ i ] == 0 && cost[ i ][ v ] < distance[ i ] )
            {
                distance[ i ] = cost[ i ][ v ];
                from[ i ] = v;
            }
        }

    }
    return (min_cost);
}


int main() {

    graph g1, spanning;
    g1.readgraph();
    int total_costing = g1.prims( spanning );
    cout << "Minimum Spanning tree matrx :\n";
    spanning.printgraph();
    cout << "\ntotal cost of spanning tree = " << total_costing;

    return 0;
}

