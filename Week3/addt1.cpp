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
	for(int i=0;i<l;i++)
		if(rcs[i]>=65 && rcs[i]<=90)
			rcs[i]+=32;
		else if(rcs[i]>=97 && rcs[i]<=122)
			rcs[i]-=32;
	MPI_Gather(rcs, l, MPI_CHAR, s, l, MPI_CHAR, 0, MPI_COMM_WORLD);
	if(r==0)
	{
		for(int j=0;j<l*size;j++)
		{
			printf("%c %d\n",s[j],s[j]);
		}
	}
	MPI_Finalize();
	return 0;
}

