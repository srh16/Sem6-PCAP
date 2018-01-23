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
	int  bufsize=500; 
	char *buf = (char*)malloc(bufsize); 
	MPI_Buffer_attach( buf, bufsize ); 
	if(r==0)
	{
		int arr[size];
		printf("Enter the array:\n");
		for(int i=0;i<size-1;i++)
			cin>>arr[i];
		for(int i=0;i<size-1;i++)
			MPI_Bsend(&arr[i],1,MPI_INT,i+1,0,MPI_COMM_WORLD);
	}
	else if(r%2==0)
	{
		MPI_Recv(&rc,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
		printf("Square of %d is %d\n",rc,rc*rc);
	}
	else
	{
		MPI_Recv(&rc,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
		printf("Cube of %d is %d\n",rc,rc*rc*rc);
	}
	MPI_Buffer_detach( &buf, &bufsize ); 
	MPI_Finalize();
	return 0;
}

