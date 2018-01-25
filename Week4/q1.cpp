#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc,char*argv[])
{
	MPI_Init(&argc,&argv);
	int r,size;
	long long int fact=1,fs=0;
	MPI_Comm_rank(MPI_COMM_WORLD,&r);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	for(int i=1;i<=r+1;i++)
		fact*=i;
	MPI_Scan(&fact,&fs,1, MPI_INT,MPI_SUM,MPI_COMM_WORLD);
	if(r==size-1)
		printf("The sum of the factorials is %lld\n",fs);
	MPI_Finalize();
	return 0;
}

