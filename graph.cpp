#include<iostream>
#include<string>
using namespace std;
template<class T>
class Data
{
      public:
	  		int id;
	  		T data;
	  public:
		  	Data();
			//~Data();
			void print();
};
template<class T>
Data<T>::Data()
{
	id=0;
	data=0;
}
template<class T>
void Data<T>::print()
{
	cout<<id;
}
template<class T>
class EdgeData
{
      public:
	  		int id;
	  		T data;
	  public:
		  	EdgeData();
			//~Data();
			void print();
};
template<class T>
EdgeData<T>::EdgeData()
{
	id=0;
	data=0;
}
template<class T>
void EdgeData<T>::print()
{
	cout<<id;
}
template<class T>
class Graph
{
	  private:
      class Vertex;
	  class Edge;
	  struct Vertex
      {
            Data<T> data;
            int no_edges;
            Edge* edge_list;
            Vertex* next;
			Vertex();
			//~Vertex();
	  		Edge* search(Data<T> );
	  		Vertex* searchVrtx(Data<T> );
	  		Edge* insertEdge(Vertex* );
	  		Edge* insertEdge(Edge* );
	  		int deleteEdge(Vertex* );
	  		void printEdges();
      };
      struct Edge
      {
            EdgeData<T> data;
			Vertex* to_vertex;
			Edge* twin;
            Edge* next;
            Edge* prev;
			Edge();
			Edge(Vertex* );
			Edge(Vertex* ,EdgeData<T> );
      		void deleteEdgeTwin();
			//~Edge();
      };
      Vertex* head;
      int no_vrtx;
      
      public:
	  	  Graph();
	      void insertVrtx(Vertex* );
	      int deleteVrtx(Vertex* );
	      Vertex* search(Data<T> );
		  void printGraph();
		  void example();
};
template<class T>
Graph<T>::Graph()
{
	head=NULL;
	no_vrtx = 0;
}
template<class T>
Graph<T>::Vertex::Vertex()
{
	no_edges = 0;
	edge_list = NULL;
	next = NULL;
}
template<class T>
Graph<T>::Edge::Edge()
{
	to_vertex = NULL;
	next = NULL;
	prev = NULL;
	twin = NULL;
}
template<class T>
Graph<T>::Edge::Edge(Vertex* to)
{
	to_vertex = to;
	next = NULL;
	prev = NULL;
	twin = NULL;
}
template<class T>
Graph<T>::Edge::Edge(Vertex* to, EdgeData<T> d)
{
	to_vertex = to;
	data = d;
	next = NULL;
	prev = NULL;
	twin = NULL;
}
template<class T>
void Graph<T>::insertVrtx(Vertex* new_vrtx)
{
        Graph::Vertex* tmp = head;
        if(head==NULL)
        {
                head = new_vrtx;
                head->next = head;
                no_vrtx++;
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
                no_vrtx++;
        }
}
template<class T>
typename Graph<T>::Vertex* Graph<T>::search(Data<T> sid)
{
		Vertex *tmp=head, *found=NULL;
		if(tmp==NULL)
		{
			;//cout<<"Error"<<endl;
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
template<class T>
typename Graph<T>::Vertex* Graph<T>::Vertex::searchVrtx(Data<T> sid)
{
		Vertex *tmp=this, *found=NULL;
		if(tmp==NULL)
		{
			;cout<<"Error.\n";
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
			}while(tmp!=this);
		}
		return found;
}
template<class T>
typename Graph<T>::Edge* Graph<T>::Vertex::search(Data<T> sid)
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
template<class T>
typename Graph<T>::Edge* Graph<T>::Vertex::insertEdge(Edge* new_edge)
{
		//cout<<new_edge->to_vertex->data.id<<endl;
		this->no_edges++;
		if(this->edge_list==NULL)
		{
				//cout<<"here0"<<endl;
				this->edge_list = new_edge;
		}
		else
		{
				new_edge->next = this->edge_list;
				this->edge_list->prev = new_edge;
				this->edge_list = new_edge;
		}
		return this->edge_list;
}
template<class T>
typename Graph<T>::Edge* Graph<T>::Vertex::insertEdge(Vertex* ver)
{
		Edge* new_edge = NULL;
		if(ver)
		{
				if(new_edge = this->search(ver->data))
				{
						//cout<<"\nError: Edge already exists...\n";
						return new_edge;
				}
				else
				{
						new_edge = new Edge(ver);
						this->insertEdge(new_edge);
						new_edge->twin = ver->insertEdge(this);
						return new_edge;
				}
		}
		else
		{
			cout<<endl<<"Error: Null Vertex..."<<endl;
		}
		return new_edge;
}
template<class T>
int Graph<T>::Vertex::deleteEdge(Vertex* frnd)
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
			ptr->deleteEdgeTwin();
			delete ptr;
			this->no_edges--;
        }
        else
        {
                 cout<<"\nError: Friend does not exists...\n";
        }
}
template<class T>
int Graph<T>::deleteVrtx(Vertex* frnd)
{
		int sc=0;
		if(frnd!=NULL)
		{
				Vertex *ptr = search(frnd->data), *tmp = ptr;
				Edge* prev = NULL;
				if(ptr==NULL)
				{
					//No Vertex in graph
					cout<<"\nError: Vertex not found...\n";
					sc = 0;
				}
				else
				{
					//cout<<"\ndeleteVrtx\t"<<ptr->data.id<<endl;
					while(tmp->next!=ptr)
					{
						tmp = tmp->next;
					}
					tmp->next = ptr->next;
					if(head==ptr)
					{
						head = head->next;
					}
					while(ptr->edge_list!=NULL)
					{
						//cout<<(ptr->edge_list)->to_vertex->data.id<<endl;
						prev = ptr->edge_list;
						ptr->edge_list = (ptr->edge_list)->next;
						prev->deleteEdgeTwin();
						delete prev;
					}
					delete ptr;
					this->no_vrtx--;
					sc=1;
				}
		}
		return sc;
}
template<class T>
void Graph<T>::Edge::deleteEdgeTwin()
{
	//cout<<"\ndeleteEdgeTwin\t"<<to_vertex->data.id<<"\t"<<twin->prev->to_vertex->data.id<<endl;
	if(twin!=NULL)
	{
		if(twin->prev==NULL)
		{
			//cout<<"1>"<<to_vertex->edge_list->data.type<<endl;
			to_vertex->edge_list = twin->next;
		}
		else
		{
			//cout<<"2>"<<to_vertex->edge_list->data.type<<endl;
			(twin->prev)->next = twin->next;
		}
		if(twin->next!=NULL)
		{
			//cout<<"3>"<<to_vertex->edge_list->data.type<<endl;
			(twin->next)->prev = twin->prev;
		}
		twin->twin = NULL;
		to_vertex->no_edges--;
		delete twin;
		//cout<<to_vertex->edge_list->data.type<<endl;
		twin = NULL;
	}
}
template<class T>
void Graph<T>::printGraph()
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
template<class T>
void Graph<T>::Vertex::printEdges()
{
	Edge* ptr = edge_list;
	if(ptr==NULL)
	{
		cout<<"NULL";
	}
	else
	{
		while(ptr->next!=NULL)
		{
			cout<<ptr->to_vertex->data.id<<endl;
			ptr=ptr->next;
		}
		while(ptr->prev!=NULL)
		{
			cout<<ptr->to_vertex->data.id<<endl;
			ptr=ptr->prev;
		}
	}
}
template<class T>
void Graph<T>::example()
{
	Data<int> d, f;
	Graph::Vertex* vrtx = new Graph::Vertex();
	Graph::Edge* e;
	vrtx->data.id=15;
			//cout<<vrtx->data.id<<endl<<vrtx->data.name;
	insertVrtx(vrtx);
	
	vrtx = new Graph::Vertex();
	vrtx->data.id=20;
	insertVrtx(vrtx);
	
	vrtx = new Graph::Vertex();
	vrtx->data.id=10;
	insertVrtx(vrtx);
	
	vrtx = new Graph::Vertex();
	vrtx->data.id=5;
	insertVrtx(vrtx);
	
	vrtx = new Graph::Vertex();
	vrtx->data.id=30;
	insertVrtx(vrtx);
	
	d.id=5;f.id=20;
	(search(f))->insertEdge(search(d));
	
	d.id=15;f.id=5;
	(search(f))->insertEdge(search(d));
	
	d.id=15;f.id=10;
	(search(f))->insertEdge(search(d));
	
	d.id=5;f.id=10;
	(search(f))->insertEdge(search(d));
	
	//(search(d))->printEdges();
	//cout<<endl<<endl;
	
	printGraph();
	cout<<endl<<endl;
	d.id=15;f.id=10;/*
	(search(f))->deleteEdge(search(d));
	(search(d))->deleteEdge(search(f));
	
	printGraph();*/
	deleteVrtx(search(f));
	printGraph();
}
int main()
{
	Graph<int> g;
	g.example();
	return 0;
}
