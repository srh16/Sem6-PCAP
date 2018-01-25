#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc,char*argv[]) 
{
	MPI_Init(&argc,&argv);
	int r,size;
	float x,y,area,pi;
	MPI_Comm_rank(MPI_COMM_WORLD,&r);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	x=(float)(r+1)/size;
	y=4.0/(1+x*x);
	area = (1/(float)size)*y;
	MPI_Reduce(&area, &pi, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (rank == 0) 
		printf("Value of pi is %f\n",pi);
	MPI_Finalize();
	return 0;
}

