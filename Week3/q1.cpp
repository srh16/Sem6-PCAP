#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc,char*argv[])
{
	MPI_Init(&argc,&argv);
	int r,size,rc,l,sz;
	MPI_Comm_rank(MPI_COMM_WORLD,&r);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	int arr[size];
	if(r==0)
	{
		printf("Enter the array:\n");
		for(int i=0;i<size;i++)
			cin>>arr[i];
	}
	MPI_Scatter(arr, 1, MPI_INT, &rc, 1, MPI_INT, 0, MPI_COMM_WORLD);
	int fact=1;
	for(int i=1;i<=rc;i++)
		fact*=i;
	printf("Factorial of %d is %d\n",rc,fact);
	MPI_Finalize();
	return 0;
}

