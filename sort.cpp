#include <iostream>
#include <ctime>
#include <dos.h>
#include "sort.h"
using namespace std;
#define N 100000
void fill_random(int *A, int n)
{
	for (int i=0; i<n; i++)
	{
		*(A+i)=rand()%n;
	}
	
}

int main()
{
	
	int a[N];
	int *p=&a[0];
	sort_interface<int> *sarray[4]={new merge_sort<int>, new insert_sort<int>, new bubble_sort<int>, new shell_sort<int>};


	double t0,t1;
	for(int n=10; n<=N; n*=10)
	{
		cout<<n<<" ";
		fill_random(p,n);
		for(int i=0; i<4; i++)
		{
			t0=clock();
			sarray[i]->sort(p,n);
			t1=clock();
			double time=((t1-t0)/CLOCKS_PER_SEC);
			cout<< time<<"   ";
			
		}
		cout<<endl;
	}
	

	/*
	for (int i=0; i<N; i++)
	{
		cout<<a[i]<<"-";
	}
	s->sort(p,N);
	cout<<endl;
	for (int i=0; i<N; i++)
	{
		cout<<a[i]<<"-";
	}
	*/
	return 0;
}
