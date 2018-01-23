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
		printf("Enter the size of array: ");
		cin>>l;
		MPI_Ssend(&l,1,MPI_INT,1,0,MPI_COMM_WORLD);
		int arr[l];
		printf("Enter the array:\n");
		for(int i=0;i<l;i++)
			cin>>arr[i];
		for(int i=0;i<l;i++)
		{
			if(i%2==1)
				MPI_Ssend(&arr[i],1,MPI_INT,1,i,MPI_COMM_WORLD);
			else
				sum+=arr[i];
		}
		MPI_Recv(&r,1,MPI_INT,1,0,MPI_COMM_WORLD,&status);
		sum+=r;
		printf("Sum of array is %d\n",sum);
	}
	else if(r==1)
	{
		MPI_Recv(&l,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
		for(int i=1;i<l;i+=2)
		{
			MPI_Recv(&rc,1,MPI_INT,0,i,MPI_COMM_WORLD,&status);
			sum+=rc;
		}
		MPI_Ssend(&sum,1,MPI_INT,0,0,MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}

