#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc,char*argv[])
{
	MPI_Init(&argc,&argv);
	int r;
	MPI_Comm_rank(MPI_COMM_WORLD,&r);
	if(r%2==0)
		for(int i=1;i<=50;i++)
		{
			int f=0;
			for(int k=2;k<i;k++)
				if(i%k==0)
					f=1;
			if(f==0)
				printf("%d\n",i);
		}
	else
		for(int i=51;i<=100;i++)
		{
			int f=0;
			for(int k=2;k<i;k++)
				if(i%k==0)
					f=1;
			if(f==0)
				printf("%d\n",i);
		}
	MPI_Finalize();
	return 0;
}

