#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc,char*argv[])
{
	MPI_Init(&argc,&argv);
	int r,size,l;
	MPI_Comm_rank(MPI_COMM_WORLD,&r);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	char s[100], rcs[100];
	int nvwl[100];
	if(r==0)
	{
		printf("Enter the string: ");
		cin>>s;
		l=strlen(s);
	}
	MPI_Bcast(&l,1,MPI_INT,0,MPI_COMM_WORLD);
	l/=size;
	MPI_Scatter(s, l, MPI_CHAR, rcs, l, MPI_CHAR, 0, MPI_COMM_WORLD);
	int nonvowels=0;
	for(int i=0;i<l;i++)
		if(rcs[i]!='a' && rcs[i]!='e' && rcs[i]!='i' && rcs[i]!='o' && rcs[i]!='u' && rcs[i]!='A' && rcs[i]!='E' && rcs[i]!='I' && rcs[i]!='O' && rcs[i]!='U')
			nonvowels++;
	
	MPI_Gather(&nonvowels, 1, MPI_INT, nvwl, 1, MPI_INT, 0, MPI_COMM_WORLD);
	if(r==0)
	{
		int sum=0;
		for(int j=0;j<size;j++)
		{
			sum+=nvwl[j];
			printf("Process %d found %d non-vowels\n",j,nvwl[j]);
		}
		printf("Total vowels found = %d\n",sum);
	}
	MPI_Finalize();
	return 0;
}

