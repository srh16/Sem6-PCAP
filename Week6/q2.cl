__kernel void dup (__global char *A,__global char *B,int N) 
{
	int i = get_global_id(0);

	for(j=0;j<N;j++)
		B[i*N +j]=A[j];
}
