#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main (int argc,char*argv[]) 
{
	MPI_Init(&argc,&argv);
	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int arr[16],rc[4],res[4];
	if (rank == 0) 
	{
		printf("Enter 4x4 matrix\n");
		for(int i=0;i<16;i++)
			cin>>arr[i];
	}
	MPI_Scatter(arr, 4, MPI_INT, rc, 4, MPI_INT, 0,MPI_COMM_WORLD);
	MPI_Scan(&rc,&res,4,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
	printf("%d %d %d %d\n",res[0],res[1],res[2],res[3]);
	MPI_Finalize();
	return 0;
}

