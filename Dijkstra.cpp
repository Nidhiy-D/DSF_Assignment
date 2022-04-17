#include<bits/stdc++.h>
using namespace std;

int findMinVertex( int* distance, bool* visited, int n ) // function to fing the minimum vertex in graph
{
	int minVertex = -1; // assigning initial value to -1
	for ( int i = 0; i < n; i++ )
	{
		if ( !visited[ i ] && (minVertex == -1 || distance[ i ] < distance[ minVertex ]) )  // if not visited and it is -1 or new vertex less than -1 is found
		{
			minVertex = i; 
		}

		return minVertex;
	}
}

void dijkstra( int** edges, int n ) // 
{
	int* distance = new int[ n ]; // taking pointer to integer 
	bool* visited = new bool[ n ];

	for ( int i = 0; i < n; i++ )
	{
		distance[ i ] = INT_MAX; // assigning max distance 
		visited[ i ] = false;
	}

	distance[ 0 ] = 0;
	for ( int i = 0; i < n - 1; i++ ) // iterating in the graph to find min vertex
	{
		int minVertex = findMinVertex(distance, visited, n);
		visited[ minVertex ] = true; // marking min veertex visited as true
		for ( int j = 0; j < n; j++ )
		{
			if ( edges[ minVertex ][ j ] != 0 && !visited[ j ] ) // to check if all edges are not zero and not visited
			{
				int dist = distance[ minVertex ] + edges[ minVertex ][ j ];
				if ( dist < distance[ j ] )
				{
					distance[ j ] = dist;
				}
			}
		}

	}

	for ( int i = 0; i < n; i++ )
	{
		cout << i << " " << distance[ i ] << endl;
	}

	delete[] visited;
	delete[] distance;
}


int main()
{
	int n; // number of nodes
	int e; // number of edges
	cin >> n >> e;
	int** edges = new int* [ n ];
	for ( int i = 0; i < n; i++ )
	{
		edges[ i ] = new int[ n ];

		for ( int j = 0; j < n; j++ )
		{
			edges[ i ][ j ] = 0;
		}
	}

	for ( int i = 0; i < e; i++ )
	{
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[ f ][ s ] = weight;
		edges[ s ][ f ] = weight;
	}

	cout << endl;
	
	dijkstra( edges, n );

	for ( int i = 0; i < n; i++ )
	{
		delete[] edges[ i ];
	}
	delete [] edges; //deallocating memory
}

