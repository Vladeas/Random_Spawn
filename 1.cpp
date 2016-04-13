#include <iostream> 
#include <fstream>
#include <random>
#include <ctime>


using namespace std; 
//n - numar lini ; m - numar coloane
 

void citire(int &n,int &m,int mat[1000][1000],int &tr_l,int &tr_c)
{
	ifstream f("text.txt");
	int i, j;
	f>>tr_l>>tr_c;// pozitie obiect inamic
	f>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			f>>mat[i][j];
	f.close();
}


void stergere(int n,int m,int mat[1000][1000],int tr_l,int tr_c)
{
	int i, j;
	for(i=tr_l-3;i<=tr_l+3;i++)
		for(j=1;j<=m;j++)
			mat[i][j]=0;
	for(i=1;i<=n;i++)
		for(j=tr_c-3;j<=tr_c+3;j++)
			mat[i][j]=0;
}


void afisare(int n,int m,int mat[1000][1000])
{
	ofstream g("text2.txt");
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			g<<mat[i][j]<<" ";
		g<<endl;
	}
	g.close();
}


void transformare(int n,int m,int mat[1000][1000],int x_l[],int x_c[],int &k)
{
	int i, j;
	k=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(mat[i][j]==1)
			{
				x_l[k]=i;
				x_c[k]=j;
			}
		}
}


int random(int k)
{
	static default_random_engine Random(time(0));
	uniform_int_distribution<int> Roll(0,k-1);
	return Roll(Random);
}


int main()
{
	int n=0,m=0,mat[1000][1000],tr_l,tr_c,k,p=0,x_l[1000],x_c[1000];
	citire(n,m,mat,tr_l,tr_c);
	stergere(n,m,mat,tr_l,tr_c);
	//afisare(n,m,mat);
	transformare(n,m,mat,x_l,x_c,k);
	p=random(k);
	cout<<x_l[p]<<" "<<x_c[p]<<endl;
	system("pause");
}