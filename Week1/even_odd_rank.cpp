#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc,char*argv[])
{
	MPI_Init(&argc,&argv);
	int r;
	MPI_Comm_rank(MPI_COMM_WORLD,&r);
	if(r%2==0)
		printf("Hello\n");
	else
		printf("World\n");
	MPI_Finalize();
	return 0;
}

