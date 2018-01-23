#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc,char*argv[])
{
	MPI_Init(&argc,&argv);
	int a=atoi(argv[1]),b=atoi(argv[2]);
	int r;
	MPI_Comm_rank(MPI_COMM_WORLD,&r);
	if(r==0)
		printf("Sum= %d\n",a+b);
	else if(r==1)
		printf("Difference= %d\n",a-b);
	else if(r==2)
		printf("Product= %d\n",a*b);
	else if(r==3)
		printf("Quotient= %d\n",a/b);
	else if(r==4)
		printf("Remainder= %d\n",a%b);
	MPI_Finalize();
	return 0;
}

