/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW30P06
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
#include <iostream>
#define FOR(i, n) for( int i = 0, _n = (n); i < _n; i++ )

using namespace std;
char nodes[9] = { 'F', 'B', 'G', 'I', 'H', 'A', 'D', 'C', 'E' };

//------------------------------------------------------------
template<typename Item>
class BinaryTree
	{
	//----------------------
	private:
		struct Node
			{
			Item item;
			Node *l, *r;
			Node(Item it)
				{
				item = it;
				l = NULL;
				r = NULL;
				}
			};
		Node *head;
		void show(Node *h)
			{
			if(h == NULL) return;
			show(h->l);
			cout<<h->item<<" ";
			show(h->r);
			}
		void insert(Node *& h, Item x)
			{
			if(h == NULL)
				{
				h = new Node(x);
				return;
				}
			if(x < h->item)
				insert(h->l, x);
			else
				insert(h->r, x);
			}
		void countLevelRecursive(Node *h, int level, int &total)
			{
			if(h != NULL)
				if(level == 1)
					total++;
			else
				{
				countLevelRecursive(h->l, level-1, total);
				countLevelRecursive(h->r, level-1, total);
				}
			}
		int depth(Node *h)
			{
			if(h == NULL)
				return 0;
			return 1 + max(depth(h->l), depth(h->r));
			}
	//----------------------	
	public:
		BinaryTree()
			{
			head = NULL;
			}
		int internal_path_length()
			{
			int d = depth(head), ipl = 0, n;
			FOR (i,d+1)
				{
				n = 0;
				countLevelRecursive(head, i+1, n);
				ipl += (i+1)*n; 
				}
			return ipl;
			}			
		void insert( Item x )
			{
			insert(head, x);
			}
		void show()
			{
			show(head);
			}
	};
//------------------------------------------------------------
int main (int argc, char * const argv[]) {
	BinaryTree<char> tree;
	FOR(i,9)
		tree.insert(nodes[i]);
	cout << "Recorrido: " ;
	tree.show();
	cout << endl << "I_N: "<< tree.internal_path_length()	<< endl;
}
//------------------------------------------------------------