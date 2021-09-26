/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW30P09
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
using namespace std;
template <class Item>

//------------------------------------------------------------
class BinaryTree
	{
	public:
		struct Node
			{
			Item item;
			struct Node *l, *r;
			Node( Item x) 
				{ 
				item =x; 
				l=NULL; 
				r=NULL;
				}
			};
		bool trav (Node *h)
			{
			static Item previous;
			static bool first=false;
			if(first)
				{
				Node *min=h;
				while(min->l!=NULL)
					min=min->l;
				previous=min->item;
				}
			if (h==NULL)
				return true;
			if (trav (h->l) ==false)
				return false;
			if(previous > h->item)
				return false;
			previous= h->item;
			if(trav(h->r)==false)
				return false;
			return true;
			}
		Node * head;
		bool is_abb ()
			{
			return trav(head);
			}
	};


//------------------------------------------------------------
int main(){
	BinaryTree<int> tree;
	tree.head = new BinaryTree<int>::Node(1);
	tree.head->l = new BinaryTree<int>::Node(0);
	tree.head->r = new BinaryTree<int>::Node(3);
	tree.head->l = new BinaryTree<int>::Node(2);	
	cout << "El arbol "<< (tree.is_abb()?"si":"no") << " es ABB.";
}
//------------------------------------------------------------