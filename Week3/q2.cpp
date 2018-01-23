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
	int factorial[size];
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
	MPI_Gather(&fact, 1, MPI_INT, factorial, 1, MPI_INT, 0, MPI_COMM_WORLD);
	if(r==0)
	{
		long long int sum=0;
		for(int j=0;j<size;j++)
			sum+=factorial[j]; 
		printf("The sum of the factorials is %lld\n",sum);
	}
	MPI_Finalize();
	return 0;
}

