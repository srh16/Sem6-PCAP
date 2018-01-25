#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main (int argc,char*argv[]) 
{
	MPI_Init(&argc,&argv);
	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int arr[9],rc[3],sum=0,si=0;
	if (rank == 0) 
	{
		printf("Enter 3x3 matrix\n");
		for(int i=0;i<9;i++)
			cin>>arr[i];
	}
	MPI_Scatter(arr, 3, MPI_INT, rc, 3, MPI_INT, 0, MPI_COMM_WORLD);
	for(int i=0;i<3;i++)
	{
		int np=0;
		for(int j=2;j<rc[i];j++)
			if(rc[i]%j==0)
			{	
				np=1;
				break;
			}
		if(!np)
			si+=rc[i];
	}
	MPI_Reduce(&si,&sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank==0)
		printf("The sum of all prime numbers is %d\n",sum);
	MPI_Finalize();
	return 0;
}

