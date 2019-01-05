// hamiltonian.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class hamil{
public:
	void hamitonian(int );
	bool promising(int);
};

hamil h;

int** w;
int tag;
int n;
int *Vindex;

void main(int argc, _TCHAR* argv[])
{
	tag =0;
	cout<<"\nenter the number of vertexs	:	";
	cin>>n;
	Vindex = new int[n+1];
	Vindex[0] =1;
	w = new int* [n+1];
	for(int i=1; i<=n; i++)
		w[i] = new int [n];
	for (int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			if(i<j)
			{
				cout<<"\nenter the edge weight between V"<<i<<" and V"<<j<<"	:	";
				cin >> w[i][j];
			}
			else if(i>j)
				w[i][j] = w[j][i];
			else
				w[i][j]=0;
	}
	system("cls");
	h.hamitonian(0);
	if(tag)
		cout<<"\n\n number of answers is	:	"<<tag;
	else
		cout<<"\n it doesn't have any answer";
	getch();
}

void hamil::hamitonian(int i)
{
	int j;
	if (h.promising(i))
		if(i == n-1){
			tag++;
			cout<<"\n\n"<<tag<<"  : \n";
			for(int k=0; k<n; k++)
				cout<<'V'<<Vindex[k]<<"  ";
			cout<<"V1";
		}
		else
			for(j=2; j<=n; j++)
			{
				Vindex[i+1]=j;
				h.hamitonian(i+1);
			}
}

bool hamil::promising(int i)
{
	bool Switch;
	if(i == n-1 && w[Vindex[i]][Vindex[0]] == 0)
		Switch = false;
	else if(i>0 && w[Vindex[i]][Vindex[i-1]] == 0)
		Switch = false;
	else
	{
		Switch = true;
		int j=1;
		while(i>j && Switch){
			if(Vindex[i] == Vindex[j])
				Switch = false;
			j++;
		}
	}
	return Switch;
}