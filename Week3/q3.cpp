#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc,char*argv[])
{
	MPI_Init(&argc,&argv);
	int r,size,m;
	MPI_Comm_rank(MPI_COMM_WORLD,&r);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	int arr[100];
	float rcf[100];
	if(r==0)
	{
		printf("Enter the M: ");
		cin>>m;
		printf("Enter the array:\n");
		for(int i=0;i<size*m;i++)
				cin>>arr[i];
	}
	int rc[m];
	MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scatter(arr, m, MPI_INT, rc, m, MPI_INT, 0, MPI_COMM_WORLD);
	float avg=0;
	for(int i=0;i<m;i++)
		avg+=rc[i];
	avg/=m;
	MPI_Gather(&avg, 1, MPI_FLOAT, rcf, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
	if(r==0)
	{
		float sum=0;
		for(int j=0;j<size;j++)
			sum+=rcf[j];
		printf("The avg of the numbers is %f\n",sum/size);
	}
	MPI_Finalize();
	return 0;
}

