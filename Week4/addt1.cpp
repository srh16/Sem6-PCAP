#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main (int argc,char*argv[]) 
{
	MPI_Init(&argc,&argv);
	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int a[18],r[9],res[9];
	if (rank == 0) 
	{
		printf("Enter 3x3 matrix\n");
		for(int i=0;i<9;i++)
			cin>>a[i];
		printf("Enter 3x3 matrix\n");
		for(int i=0;i<9;i++)
			cin>>a[i+9];
	}
	MPI_Scatter(a, 9, MPI_INT, r, 9, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Reduce(r,res,9,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank==0)
	{
		printf("The sum is \n");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
				cout<<res[i*3+j]<<" ";
			cout<<endl;
		}
	}
	MPI_Finalize();
	return 0;
}

