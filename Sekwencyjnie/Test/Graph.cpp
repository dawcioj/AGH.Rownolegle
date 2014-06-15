#include "Graph.h"

Graph::Graph()
{
}

Graph::Graph(int n)
{
	NumberOfVertices = n;

	Vertices = new GraphVertex[n];
	m_InitVertices();
}

/*Graph::~Graph()
{
delete [] Vertices;
}*/

void Graph::Clear()
{
	/* for(int i = 0; i < NumberOfVertices; i++)
	delete Vertices[i];*/

	delete[] Vertices;
}

void Graph::m_InitVertices()
{
	for (int i = 0; i < NumberOfVertices; i++)
	{
		Vertices[i].Edges = 0;
		Vertices[i].Size = 0;
	}
}

void Graph::AddNewEdge(int VertexNo, int edgeNo, int destVertexNo, int dist)
{
	Vertices[VertexNo].Edges[edgeNo].Target = destVertexNo;
	Vertices[VertexNo].Edges[edgeNo].Distance = dist;
}

string Graph::ToString()
{
	stringstream out;
	for (int i = 0; i < this->NumberOfVertices; i++)
	{
		out << "Vertex" << i << "\n";
		for (int j = 0; j < this->Vertices[i].Size; j++)
		{
			out << "\t" << "Edge " << j << ": Distance : " <<
				this->Vertices[i].Edges[j].Distance << " Target : " <<
				this->Vertices[i].Edges[j].Target << "\n";
		}
	}
	return out.str();
}

int Graph::Length()
{
	int sOi = sizeof(int);
	int edges = 0;
	for (int i = 0; i < NumberOfVertices; i++)
		edges += Vertices[i].Size;

	return (sOi + NumberOfVertices * (sOi + 2 * edges * sOi));
}