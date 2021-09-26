/*------------------------------------------------------------

PROGRAMACIÓN AVANZADA I HW30P04
César Magaña
cesar@cimat.mx

--------------------------------------------------------------*/
# include <algorithm>
# include <cmath>
# include <cstdio>
# include <iostream>
# include <iomanip>
# include <vector>
#define FOR(i, n) for( int i = 0, _n = (n); i < _n; i++ )

using namespace std;
const double l2 = log10(2.0);
vector< int > pA, sA, pot2(1,1);
vector< pair<int,int> > data;


//------------------------------------------------------------
void print_pair_vector(vector< pair<int,int> >& vector)
	{
	FOR ( i, vector.size() )
		cout << vector[i].second << " ";
	cout<<endl;
	}


//------------------------------------------------------------
void read_data(int n)
	{
	FOR ( i, n )
		{
		cin>>data[i].second;
		data[i].first = data[i].second;
		}
	}

//------------------------------------------------------------
void fill_pot2(int n)
	{
	while( pot2[pot2.size()-1]<n )	
		pot2.push_back( 2*pot2[pot2.size()-1] );
	}

//------------------------------------------------------------
void move_down(int curr, pair<int,int> paseador, int n)
	{
	int childl, childr=curr;
	while(childr<n)
		{
		childl = childr = -1;
		if(sA[curr]<n) childr = sA[curr];
		if(curr+1<n && pA[curr+1]==curr )	childl = curr+1;
		if( (childl==-1) && (childr==-1) )	break;
		if( childr==-1 )	childr=childl;
		if( childl==-1 )	childl=childr;
		if(data[childr].second < data[childl].second)	childr = childl;
		if(data[childr].second > paseador.second)
			{
			data[curr]=data[childr];
			curr=childr;
			}
		else	
			break;
		}
	data[curr]=paseador;
	}


//------------------------------------------------------------
void fill_arrays(int i, int j)	
	{
	if(j<=i)	return;
	int N=j-i+1;
	double  log2 = log10( (double)(N) ) / l2;
	int l = (int)( floor( log2 ) );
	pA[i+1]=i;
	if( N-pot2[l] <= pot2[l-1]-1 )
		{
		sA[i]=i+pot2[l-1];
		pA[i+pot2[l-1]]=i;
		fill_arrays(i+1,i+pot2[l-1]-1);
		fill_arrays(i+pot2[l-1],j);
		}
	else
		{
		sA[i]=i+N-pot2[l]+1;
		pA[i+N-pot2[l]+1]=i;
		fill_arrays(i+1,i+N-pot2[l]);
		fill_arrays(i+N-pot2[l]+1,j);
		}
	}
	
	
//------------------------------------------------------------
void heap_sort(int n)
	{
	for(int i=n-2; i>=0; --i)			
		move_down(i,data[i],n);
	for(int i=0; i<n-1; ++i)			
		{									
		swap(data[0],data[n-1-i]);
		move_down(0,data[0],n-i-1);
		}		
	}


//------------------------------------------------------------
int main (void)
	{
	freopen("entrada.txt","r",stdin);
	int n;
	while(cin>>n)
		{
		data.resize(n);
		pA.resize(n,-1);
		sA.resize(n,-1);
		read_data(n);
		fill_pot2(n);
		fill_arrays(0,n-1);
		heap_sort(n);
		print_pair_vector(data);		
		}
	return 0;
	}
//------------------------------------------------------------