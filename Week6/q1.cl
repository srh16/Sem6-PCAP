__kernel void reverse_ascii (__global char *A,__global char *B) 
{
	int i = get_global_id(0);
	char temp=A[i],rev=0;
	while(temp>0)
	{
		rev=rev*10+temp%10;
		temp/=10;
	}
	B[i]=rev;
}
