/*
----------------------------------------------------------------------------------------------------
| Plik:             Graph.cpp
| Opis:             Implementacja klasy grafu skierowanego.
| Autor:            Dawid Janik
| Data utworzenia:  10.06.2014
----------------------------------------------------------------------------------------------------
*/
#include "Graph.h"

GraphEdge::GraphEdge()
{
	Target = 0;
	Distance = 0;


}

GraphEdge::GraphEdge(string tmp)
{
	//delimiter dzieli stringa
	std::string delimiter = ":";
	string s1;
	string s2;
	int counter=0;

	size_t pos = 0;
	string token;
	while ((pos = tmp.find(delimiter)) != std::string::npos) 
	{
		token = tmp.substr(0, pos);
		if (counter == 0)
		{
			s1 = token;
		}
		if (counter == 1)
		{
			s2 = token;

		}

		tmp.erase(0, pos + delimiter.length());
		
		counter++;
		if (counter > 1)
			break;

	}
		
	
	Distance = atoi(s1.c_str());
	Target = atoi(s2.c_str());


}

GraphVertex::GraphVertex()
{



}

GraphVertex::GraphVertex(string tmp)
{

}

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
		Vertices[i].Quantity = 0;
	}
}

void Graph::AddNewEdge(int VertexNo, int edgeNo, int destVertexNo, int dist)
{
	Vertices[VertexNo].Edges[edgeNo].Target = destVertexNo;
	Vertices[VertexNo].Edges[edgeNo].Distance = dist;
}

void Graph::AddNewEdge(int VertexNo, int edgeNo, GraphEdge e)
{
	Vertices[VertexNo].Edges[edgeNo] = e;
	//Vertices[VertexNo].Edges[edgeNo].Target = e.Target;
	//Vertices[VertexNo].Edges[edgeNo].Distance = e.Distance;
}

string Graph::ToString()
{
	stringstream out;
	for (int i = 0; i < this->NumberOfVertices; i++)
	{
		out << "Vertex" << i << "\n";
		for (int j = 0; j < this->Vertices[i].Quantity; j++)
		{
			out << "\t" << "Edge " << j << ": Distance : " <<
				this->Vertices[i].Edges[j].Distance << " Target : " <<
				this->Vertices[i].Edges[j].Target << "\n";
		}
	}
	return out.str();
}

string Graph::ToFile()

{
	stringstream out;
	int *Vertex = new int[NumberOfVertices];

	for (int i = 0; i < this->NumberOfVertices; i++)
	{

		//m ilosc krawedzi w danym V
		for (int j = 0; j < this->Vertices[i].Quantity; j++)
		{
			out << this->Vertices[i].Edges[j].Distance << ":";
			out << this->Vertices[i].Edges[j].Target;

			if (j < this->Vertices[i].Quantity - 1)
				out << ",";


		}

		if (i < this->NumberOfVertices - 1)
			out << ";";


	}

	return out.str();
}
int Graph::Length()
{
	int sOi = sizeof(int);
	int edges = 0;
	for (int i = 0; i < NumberOfVertices; i++)
		edges += Vertices[i].Quantity;

	return (sOi + NumberOfVertices * (sOi + 2 * edges * sOi));
}