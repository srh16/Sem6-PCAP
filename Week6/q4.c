#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SOURCE_SIZE 0x100000

int main (void) {

	int i;
	

	// 0. Create and initialize two vectors

	char A[100];

	printf("Enter the string: ");
	scanf("%s", A);
	int len=strlen(A);

	// 1. Load the kernel code

	FILE *kernel_code_file = fopen("q4.cl", "r");
	if (kernel_code_file == NULL) {
		printf("Kernel loading failed.");
		exit(1);
	}

	char *source_str = (char *)malloc(MAX_SOURCE_SIZE);
	size_t source_size = fread(source_str, 1, MAX_SOURCE_SIZE, kernel_code_file);

	fclose(kernel_code_file);

	// 2. Get platform and device information

	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;

	cl_uint ret_num_devices, ret_num_platforms;

	cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &ret_num_devices);


	// 3. Create an OpenCL context

	cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);


	// 4. Create a command queue

	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, NULL, &ret);


	// 5. Create memory buffers on the device for each vector A and B

	cl_mem mem_obj_a = clCreateBuffer(context, CL_MEM_READ_ONLY, len * sizeof(char), NULL, &ret);

	cl_mem mem_obj_b = clCreateBuffer(context, CL_MEM_WRITE_ONLY, len * sizeof(char), NULL, &ret);


	// 6. Copy the list A to the respective memory buffers

	ret = clEnqueueWriteBuffer(command_queue, mem_obj_a, CL_TRUE, 0, len * sizeof(char), A, 0, NULL, NULL);


	// 7. Create a program from kernel source

	cl_program program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);


	// 8. Build the kernel program

	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);


	// 9. Create the OpenCL kernel object

	cl_kernel kernel = clCreateKernel(program, "reverse", &ret);


	// 10. Set the arguments of the kernel dode

	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&mem_obj_a);
	ret = clSetKernelArg(kernel, 1, sizeof(int), &len);


	// 11. Execute the kernel on device
	
	size_t global_item_size = len/2;
	size_t local_item_size = 1;

	// cl_event event;
	ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);

	ret = clFinish(command_queue);


	// 12. Read the memory buffer C on the device to the local variable C, and display

	char *B = (char *)malloc(sizeof(char) * 100);

	ret = clEnqueueReadBuffer(command_queue, mem_obj_b, CL_TRUE, 0, len * sizeof(char), B, 0, NULL, NULL);
	
	B[len]='\0';
	
	printf("\n\n%s\n",B);


	// 13. Clean up

	clFlush(command_queue);
	clReleaseKernel(kernel);
	clReleaseProgram(program);

	clReleaseMemObject(mem_obj_a);
	clReleaseMemObject(mem_obj_b);
	
	clReleaseCommandQueue(command_queue);
	clReleaseContext(context);
	
	
	return 0;

}

