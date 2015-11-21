#include<iostream>
#include<string>
using namespace std;
class Data
{
      public:
	  		int id;
			string name;
			string status;
	  public:
		  	Data();
			//~Data();
			void print();
};
Data::Data()
{
	id=0;
	name="NULL";
	status="active";
}
void Data::print()
{
	cout<<id<<"\t"<<name;
}
class EdgeData
{
      public:
	  		string type;
	  public:
		  	EdgeData();
			//~Data();
			void print();
};
EdgeData::EdgeData()
{
	type="NULL";
}
void EdgeData::print()
{
	cout<<type;
}
class Graph
{
	  public:
      class Vertex;
	  class Edge;
	  struct Vertex
      {
            Data data;
            Edge* edge_list;
            Vertex* next;
			Vertex();
			~Vertex();
	  		Edge* search(Data );
	  		void insertEdge(Vertex* );
	  		void insertEdge(Edge* );
	  		int deleteEdge(Vertex* );
      };
      struct Edge
      {
            EdgeData data;
			Vertex* to_vertex;
			Edge* twin;
            Edge* next;
            Edge* prev;
			Edge();
			Edge(Vertex* );
			Edge(Vertex* ,EdgeData );
			//~Edge();
      };
      Vertex* head;
      Graph();
      void insertVrtx(Vertex* );
      Vertex* search(Data );
	  void printGraph();
};
Graph::Graph()
{
	head=NULL;
}
Graph::Vertex::Vertex()
{
	edge_list = NULL;
	next = NULL;
}
Graph::Edge::Edge()
{
	to_vertex = NULL;
	next = NULL;
	prev = NULL;
	twin = NULL;
}
Graph::Edge::Edge(Vertex* to)
{
	to_vertex = to;
	next = NULL;
	prev = NULL;
	twin = NULL;
}
Graph::Edge::Edge(Vertex* to, EdgeData d)
{
	to_vertex = to;
	data = d;
	next = NULL;
	prev = NULL;
	twin = NULL;
}
void Graph::insertVrtx(Vertex* new_vrtx)
{
        Graph::Vertex* tmp = head;
        if(head==NULL)
        {
                head = new_vrtx;
                head->next = head;
        }
        else if(search(new_vrtx->data))
	    {
	            cout<<"\nUser id already exist.\n";
	    }
        else
        {
                while(tmp->next!=head)
                		tmp=tmp->next;
                tmp->next=new_vrtx;
                new_vrtx->next=head;
        }
}
Graph::Vertex* Graph::search(Data sid)
{
         Vertex *tmp=head, *found=NULL;
         if(tmp==NULL)
         {
                ;//printf("Error.\n");
         }
         else
         {
                  do
                  {
                        if(tmp->data.id==sid.id)
                        {
                               found=tmp;
                               break;
                        }
                        tmp=tmp->next;
                  }while(tmp!=head);
         }
         return found;
}
Graph::Edge* Graph::Vertex::search(Data sid)
{
         Edge *tmp=this->edge_list, *found=NULL;
         if(tmp==NULL)
         {
                      ;//cout<<"Error.\n";
         }
         else
         {
                  do
                  {
                        if(((tmp->to_vertex)->data).id==sid.id)
                        {
                               found=tmp;
                               break;
                        }
                        tmp=tmp->next;
                  }while(tmp!=NULL);
         }
         return found;
}
void Graph::Vertex::insertEdge(Edge* new_edge)
{
		new_edge->next = NULL;
		new_edge->prev = NULL;
		if(this->edge_list==NULL)
		{
				//cout<<"here0";
				this->edge_list = new_edge;
		}
		else
		{
				new_edge->next = this->edge_list;
				this->edge_list->prev = new_edge;
				this->edge_list = new_edge;
		}
}
void Graph::Vertex::insertEdge(Vertex* ver)
{
		if(!this->search(ver->data))
		{
				Edge* new_edge = new Edge(ver);
				this->insertEdge(new_edge);
		}
		else
		{
				cout<<"\nError: Edge already exists...\n";
		}
}
int Graph::Vertex::deleteEdge(Vertex* frnd)
{
		Edge *ptr = NULL, *tmp = NULL;
		if(ptr = this->search(frnd->data))
        {
			tmp = ptr->next;
			if(tmp)
				tmp->prev = ptr->prev;
			tmp = ptr->prev;
			if(tmp)
				tmp->next = ptr->next;
			else
				this->edge_list = ptr->next;
			delete ptr;
        }
        else
        {
                 cout<<"\nError: Friend does not exists...\n";
        }
}
void Graph::printGraph()
{
	Graph::Vertex* temp = head;
	Graph::Edge* tedge;
	do
	{
		if(temp!=NULL)
		{
			cout<<"vertex:";(temp->data).print();cout<<endl;
			tedge = temp->edge_list;
			while(tedge)
			{
				cout<<"\t";(tedge->to_vertex->data).print();cout<<endl;
				tedge=tedge->next;
			}
			temp=temp->next;
		}
	}while(temp!=head);
}
int main()
{
	Graph g;
	Data d, f;
	Graph::Vertex* vrtx = new Graph::Vertex();
	Graph::Edge* e;
	vrtx->data.id=15;
	vrtx->data.name="sum";
			//cout<<vrtx->data.id<<endl<<vrtx->data.name;
	g.insertVrtx(vrtx);
	
	vrtx = new Graph::Vertex();
	vrtx->data.id=20;
	vrtx->data.name="sum";
	g.insertVrtx(vrtx);
	
	vrtx = new Graph::Vertex();
	vrtx->data.id=10;
	vrtx->data.name="sum";
	g.insertVrtx(vrtx);
	
	vrtx = new Graph::Vertex();
	vrtx->data.id=5;
	vrtx->data.name="sum";
	g.insertVrtx(vrtx);
	
	vrtx = new Graph::Vertex();
	vrtx->data.id=30;
	vrtx->data.name="sum";
	g.insertVrtx(vrtx);
	
	d.id=5;f.id=10;
	(g.search(f))->insertEdge(g.search(d));
	(g.search(d))->insertEdge(g.search(f));
	
	d.id=15;f.id=5;
	(g.search(f))->insertEdge(g.search(d));
	(g.search(d))->insertEdge(g.search(f));
	
	d.id=15;f.id=10;
	(g.search(f))->insertEdge(g.search(d));
	(g.search(d))->insertEdge(g.search(f));
	
	g.printGraph();
	cout<<endl<<endl;
	d.id=15;f.id=5;
	(g.search(f))->deleteEdge(g.search(d));
	(g.search(d))->deleteEdge(g.search(f));
	
	g.printGraph();
	return 0;
}
