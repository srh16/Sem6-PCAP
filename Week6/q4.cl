__kernel void reverse (__global char *A,int len) {
	size_t i = get_global_id(0);
	int len=get_work_dim();
	char t = A[len - 1 - i];
	A[len - 1 - i] = A[i];
	A[i] = t;
}
