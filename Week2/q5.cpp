#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc,char*argv[])
{
	MPI_Init(&argc,&argv);
	int r,size,sum=0,l,rc;
	MPI_Comm_rank(MPI_COMM_WORLD,&r);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	if(r==0)
	{
		printf("Enter a number: ");
		cin>>rc;
		rc++;
		MPI_Ssend(&rc,1,MPI_INT,r+1,0,MPI_COMM_WORLD);
		MPI_Recv(&rc,1,MPI_INT,size-1,0,MPI_COMM_WORLD,&status);
		printf("Received %d\n",rc);
	}
	else if(r==size-1)
	{
		MPI_Recv(&rc,1,MPI_INT,r-1,0,MPI_COMM_WORLD,&status);
		rc++;
		MPI_Ssend(&rc,1,MPI_INT,0,0,MPI_COMM_WORLD);
	}
	else
	{
		MPI_Recv(&rc,1,MPI_INT,r-1,0,MPI_COMM_WORLD,&status);
		rc++;
		MPI_Ssend(&rc,1,MPI_INT,r+1,0,MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}

