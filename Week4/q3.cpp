#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main (int argc,char*argv[]) 
{
	MPI_Init(&argc,&argv);
	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int arr[9],rc[3],srh,occi=0,occ=0;
	if (rank == 0) 
	{
		printf("Enter 3x3 matrix\n");
		for(int i=0;i<9;i++)
			cin>>arr[i];
		printf("Enter the value to search ");
		cin>>srh;
	}
	MPI_Bcast(&srh,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scatter(arr, 3, MPI_INT, rc, 3, MPI_INT, 0, MPI_COMM_WORLD);
	for(int i=0;i<3;i++)
		if(srh==rc[i])
			occi++;
	MPI_Reduce(&occi,&occ,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank==0)
		printf("There are %d occurences\n",occ);
	MPI_Finalize();
	return 0;
}

