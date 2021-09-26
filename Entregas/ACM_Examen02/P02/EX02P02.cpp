/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I EX02P02
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#include <cstdio>
#define FOR(i, n) for( int i = 0, _n = (n); i < _n; i++ )
using namespace std;

//------------------------------------------------------------
//Este es un árbol de búsqueda de 5 nodos común.
template <class Item, class Key>
class QuintaryTree
	{
	//-------------   
	private:
		struct Node
			{ 
			Item dato;
			Key llave;
			struct Node *l,*lc, *c, *rc, *r;
			Node(Item val,Key ll) : dato(val), llave(ll)
				{   
				l = NULL;
				lc= NULL;
				c = NULL;
				rc= NULL;
				r = NULL;
				};
			Node(Node &n)
				{   
				dato = n.dato;
				llave = n.llave;
				l = n.l;
				lc= n.lc;
				c = n.c;
				rc= n.rc;
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
		QuintaryTree(Item val,Key llave)
			{   
			head = new Node(val,llave);
			};
		~QuintaryTree();
		Item max();
		Item min();
		void print();
		void borra();
		void inserta(Item val,Key llave);
		Item busca(Key llave);
		void inserta_secuencia(Item i);		
	};



template <class Item, class Key>
void QuintaryTree<Item,Key>::insert(Node *&n,Item val,Key llave)
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
Item QuintaryTree<Item,Key>::max()
	{
	Node *temp = head;
	while(temp->r != NULL)
		temp = temp->r;
	return temp->dato;
	}


//------------------------------------------------------------
template <class Item, class Key>
Item QuintaryTree<Item,Key>::min()
	{   
	Node *temp = head;
	while(temp->l != NULL)
		temp = temp->l;
	return temp->dato;
	}


//------------------------------------------------------------
template <class Item, class Key>
typename QuintaryTree<Item,Key>::Node *QuintaryTree<Item,Key>::search(Node *n, Key llave)
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
void QuintaryTree<Item,Key>::inorden(Node *n)
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
void QuintaryTree<Item,Key>::del(Node *n)
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
void QuintaryTree<Item,Key>::print()
	{   
	if(head != NULL)
		inorden(head);
	}


//------------------------------------------------------------
template <class Item, class Key>
void QuintaryTree<Item,Key>::borra()
	{   
	del(head);
	}


//------------------------------------------------------------
template <class Item, class Key>
void QuintaryTree<Item,Key>::inserta(Item i,Key k)
	{   
	insert(head,i,k);
	}

//------------------------------------------------------------
template <class Item, class Key>
QuintaryTree<Item,Key>::~QuintaryTree()
	{   
	if(head != NULL)
		del(head);
	}


//------------------------------------------------------------
template <class Item, class Key>
Item QuintaryTree<Item,Key>::busca(Key k)
	{   
	Node *temp = search(head,k);
	if(temp != NULL)
		return temp -> dato;
	cout << "No hay nodos con esa llave." << endl;
	throw 1;
	}


//------------------------------------------------------------
template <class Item, class Key>
void QuintaryTree<Item,Key>::inserta_secuencia(Item i)
	{
	Node *temp = head;
	int j=0;
	i +="E";
	int m=i.length();   
	while (j<m)
		{
		if (i[j]=='A')
			{
			if (temp->l != NULL)
				temp = temp->l;
			else
				{
				temp->l=new Node("A",0);
				}
			}
		if (i[j]=='C')
			{
			if (temp->lc != NULL)
				temp = temp->lc;
			else
				{
				temp->lc=new Node("C",0);
				}
			}

			
		if (i[j]=='E')
			{
			if (temp->c != NULL)
				temp = temp->c;
			else
				{
				temp->c=new Node("E",0);
				}
			}
			
		if (i[j]=='G')
			{
			if (temp->rc != NULL)
				temp = temp->rc;
			else
				{
				temp->rc=new Node("G",0);
				}
			}
			
		if (i[j]=='T')
			{
			if (temp->r != NULL)
				temp = temp->r;
			else
				{
				temp->r=new Node("T",0);
				}
			}
			
			
			j++;
		}
	}



//------------------------------------------------------------
int main()
	{   
	QuintaryTree<string,int> Arbol("S",10);
	Arbol.inserta_secuencia("GATTACA");
	//Arbol.inserta_secuencia("T",0);

	
	//string arreglo[] = { "", "", "", "", "", "", "", "", "", "", "", "", "" };
	
	//int arreglo[] = { 190, 0, 40, 230, 240, 360, 110, 170, 80, 50, 310, 90, 300 };
	//int n,v=0;
	//n = sizeof(arreglo)/sizeof(arreglo[0]);
	//FOR( i,n )
	//	Arbol.inserta(arreglo[i],arreglo[i]);
	//cout << "Maximo: " << Arbol.max() << endl << "Minimo: " << Arbol.min() <<   endl;
	Arbol.print();
	cout << endl;
	//if( (v=Arbol.busca(90)) )
	//	cout << "Se busco el objeto con llave: " << v << endl;
	return 0;
	}
//------------------------------------------------------------