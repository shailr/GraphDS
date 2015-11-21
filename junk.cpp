Graph::Edge* Graph::Vertex::insertEdge(Vertex* frnd)
{
		if(!this->searchEdge(frnd))
		{
				Edge* new_edge = new Edge(frnd);
				Edge *ptr = this->edge_list, *tmp = NULL;
				new_edge->next = NULL;
				new_edge->prev = NULL;
				if(ptr==NULL)
				{
						//cout<<"here0";
						this->edge_list = new_edge;
				}
				else
				{
						while(ptr!=NULL && (ptr->to_vertex->d.id)<(new_edge->to_vertex->d.id))
						{
								tmp = ptr;
								ptr = ptr->next;
						}
						new_edge->next = ptr;
						new_edge->prev = tmp;
						if(ptr!=NULL)
						{
								ptr->prev = new_edge;
						}
						if(tmp!=NULL)
						{
								tmp->next = new_edge;
						}
						else
						{
								this->edge_list = new_edge;
						}
				}
		}
        else
        {
                 cout<<"\nError: This user is already ur friend...\n";
        }
        return this->edge_list;
}
