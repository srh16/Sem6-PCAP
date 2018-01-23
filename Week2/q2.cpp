#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc,char*argv[])
{
	MPI_Init(&argc,&argv);
	int r,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&r);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	if(r==0)
		for(int i=1;i<size;i++)
			MPI_Send(&i,1,MPI_INT,i,0,MPI_COMM_WORLD);
	else
	{
		MPI_Recv(&r,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
		printf("%d\n",r);
	}
	MPI_Finalize();
	return 0;
}

