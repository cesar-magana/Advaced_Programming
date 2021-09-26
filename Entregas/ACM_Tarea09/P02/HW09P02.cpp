/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW09P02
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
using namespace std;
#define FOR(i, n) for( int i = 0, _n = (n); i < _n; i++ )

class Queue {
	public:
			Queue(int dataSize); 
			~Queue(); 
	
			class Node 
				{ 
				public:
				unsigned char *data;
				Node* next; 
				~Node(); 
				Node( void *data,unsigned int dsize );
				}; 
			unsigned int dataSize; 
			unsigned int size;
			Node *head; 
			void push(void *data); 
			int pop(); 
			void *front(); 
			void *back();
			void cleanup();
			void delete_node(Node **node);

}; 


Queue::Queue ( int dataSize ) : size(0){
	this->dataSize = dataSize;
	head = NULL;
}


Queue::~Queue ( ){
	cleanup();
}


Queue::Node::Node ( void *data, unsigned int dsize ){
	dsize /= sizeof(unsigned char);
	this->data = static_cast <unsigned char*> (data);
}


Queue::Node::~Node (  ){
}



void Queue::push ( void *data ){
	Node *newnode;
	Node *last;
	this->size++;
	newnode = new Node( data,sizeof(data) );
	if (this->head == NULL)
		{
		this->head = newnode;
		this->head->next = NULL;
		}
	else
		{
		last = this->head;
		while ( last->next != NULL )
			last=last->next;
		last->next = newnode;
		}
}


int Queue::pop ( ){
	if( this->head == NULL )
		return 0;
	Node *first = head;
	this->head = first->next;
	delete_node(&first);
	this->size--;
	return 1;
}

void *Queue::front ( ){
	return this->head->data; 
}


void *Queue::back ( ){
	Node *temp;
	temp = this->head;
	while ( temp->next != NULL )
		temp=temp->next;
	return temp->data; 
}


void Queue::cleanup ( ){
	while( pop() );
	head = NULL;
}


void Queue::delete_node(Node **node){
    delete *node;
		*node = NULL;
}


//------------------------------------------------------------
int main (int argc, char * const argv[]) {

	Queue queue(sizeof(int));
	int i = 2009;
	int j = 2010;
	int k = 2011;
	int l = 2012;
	queue.push(&i);
	queue.push(&j);
	queue.push(&k);
	queue.push(&l);
	queue.pop();
	cout << "Tamano de la cola: "<< queue.size << endl;
	cout << "Primer elemento de la cola: " << *static_cast <int*> (queue.front()) << endl;
	cout << "Ultimo elemento de la cola: " << *static_cast <int*> (queue.back()) << endl;
	
  return 0;
}
//------------------------------------------------------------
