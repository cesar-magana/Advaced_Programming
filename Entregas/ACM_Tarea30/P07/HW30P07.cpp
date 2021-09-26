/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW30P07
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <cstdio>
#define FOR(i, n) for( int i = 0, _n = (n); i < _n; i++ )
using namespace std;

//------------------------------------------------------------
template <class Item, class Key>
class TernaryTree
	{
	//-------------   
	private:
		struct Node
			{ 
			Item dato;
			Key llave;
			struct Node *l,*c,*r;
			Node(Item val,Key ll) : dato(val), llave(ll)
				{   
				l = NULL;
				c = NULL;
				r = NULL;
				};
			Node(Node &n)
				{   
				dato = n.dato;
				llave = n.llave;
				l = n.l;
				c = n.c;
				r = n.r;
				};					
			};
		Node *head;
		void inorden(Node *n);
		void del(Node *n);
		void insert(Node *&n,Item val,Key llave);
		Node *search(Node *n, Key llave);
	//-------------
	public:
		TernaryTree(Item val,Key llave)
			{   
			head = new Node(val,llave);
			};
		~TernaryTree();
		Item max();
		Item min();
		void print();
		void borra();
		void inserta(Item val,Key llave);
		Item busca(Key llave);
	};



template <class Item, class Key>
void TernaryTree<Item,Key>::insert(Node *&n,Item val,Key llave)
	{ 
	if(n == NULL)
		{   
		n = new Node(val,llave);
		return;
		}
	if(llave < n->llave)
		insert(n->l,val,llave);
	else if(n->r == NULL)
		insert(n->r,val,llave);
	else if(llave < n->r->llave)
		insert(n->c,val,llave);
	else
		insert(n->r,val,llave);			
	}


//------------------------------------------------------------
template <class Item, class Key>
Item TernaryTree<Item,Key>::max()
	{
	Node *temp = head;
	while(temp->r != NULL)
		temp = temp->r;
	return temp->dato;
	}


//------------------------------------------------------------
template <class Item, class Key>
Item TernaryTree<Item,Key>::min()
	{   
	Node *temp = head;
	while(temp->l != NULL)
		temp = temp->l;
	return temp->dato;
	}


//------------------------------------------------------------
template <class Item, class Key>
typename TernaryTree<Item,Key>::Node *TernaryTree<Item,Key>::search(Node *n, Key llave)
	{   
	if(n == NULL)
		return NULL;
	Key k = n->llave;
	if(llave == k)
		return n;
	if(llave < k)
		return search(n->l,llave);
	Node *temp = search(n->c,llave);
	if(temp == NULL)
		temp = search(n->r,llave);
	return temp;
	}


//------------------------------------------------------------
template <class Item, class Key>
void TernaryTree<Item,Key>::inorden(Node *n)
	{   
	if(n == NULL)
		return ;
	inorden(n->l);
	cout << n->dato << " ";
	inorden(n->c);
	inorden(n->r);
	}


//------------------------------------------------------------
template <class Item, class Key>
void TernaryTree<Item,Key>::del(Node *n)
	{ 
  if(n == NULL)
		return ;
	del(n->l);
	del(n->c);
	del(n->r);
	delete n;
	n = NULL;
	}


//------------------------------------------------------------
template <class Item, class Key>
void TernaryTree<Item,Key>::print()
	{   
	if(head != NULL)
		inorden(head);
	}


//------------------------------------------------------------
template <class Item, class Key>
void TernaryTree<Item,Key>::borra()
	{   
	del(head);
	}


//------------------------------------------------------------
template <class Item, class Key>
void TernaryTree<Item,Key>::inserta(Item i,Key k)
	{   
	insert(head,i,k);
	}

//------------------------------------------------------------
template <class Item, class Key>
TernaryTree<Item,Key>::~TernaryTree()
	{   
	if(head != NULL)
		del(head);
	}


//------------------------------------------------------------
template <class Item, class Key>
Item TernaryTree<Item,Key>::busca(Key k)
	{   
	Node *temp = search(head,k);
	if(temp != NULL)
		return temp -> dato;
	cout << "No hay nodos con esa llave." << endl;
	throw 1;
	}


//------------------------------------------------------------
int main()
	{   
	TernaryTree<int,int> A(13,13);
	int arreglo[] = { 190, 0, 40, 230, 240, 360, 110, 170, 80, 50, 310, 90, 300 };
	int n,v=0;
	n = sizeof(arreglo)/sizeof(arreglo[0]);
	FOR( i,n )
		A.inserta(arreglo[i],arreglo[i]);
	cout << "Maximo: " << A.max() << endl << "Minimo: " << A.min() <<   endl;
	A.print();
	cout << endl;
	if( (v=A.busca(90)) )
		cout << "Se busco el objeto con llave: " << v << endl;
	return 0;
	}
//------------------------------------------------------------