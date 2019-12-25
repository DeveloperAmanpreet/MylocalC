#include <iostream>
using namespace std;

#include <SubArraySum.h>

int  main_ProgramSubArraySum()
{
	int No_of_arrays = 0;
	cin >> No_of_arrays;
	for (; No_of_arrays > 0; --No_of_arrays)
	{
		//first line is the array size and sum to find
		int array_size = 0, sum_in = 0, found = 0;
		cin >> array_size >> sum_in;
		const int array_size_C = (const int)array_size, sun_in_C = (const int)sum_in;

		//create and read array from stdin
		int* array = ArrayCreate(array_size_C);
		if (ArrayPopulateRandom)
		{
			int result = SubArraySum(array, array_size, sum_in);
		}
		ArrayFree(array);
	}
	
	return 0;
}

int ArrayPopulateRandom(int* array, int size)
{
	for (int i = 0; i < size; ++i)
		array[i] = rand();

	return 1;//success
}

int ArrayPopuLateFromStdin(int * array, int array_size) {
	for (int i = 0; i < array_size; ++i)
	{
		cin >> array[i];
	}
	return 1;//success
}

int* ArrayCreate(const int array_size)
{
	int* array = new int[array_size];
	for (int i = 0; i < array_size; ++i)
		array[i]=-1;
	return array;
}

int ArrayFree(int* array)
{
	delete[] array;
	return 0;
}

int SubArraySum(int* array, const int array_size, int sum_in)
{
	//sliding window style
	int i=0, j=0, sum=0;
	
	//traverse the subarrays to compute and compre the sum
	for (; i < array_size && j < array_size; )
	{
		sum = array[j];
		
		if (sum < sum_in)
		{
			//if sum is smaller then we need to add next element to sum
			++j;
			continue;
			//compare again
		}
		//else if equal we have a match
		else if (sum == sum_in)
		{
			std::cout << i << ": " << j << std::endl;
			return 0;
		}
		else
		{
			//the sum is greater than sum_in
			//to change the subarray to exclude first array ele and restart the loop from here
			sum -= array[i];
			++i;
			continue;
		}
	}

	//if i or j reached the end of array, then nothing was found
	std::cout << "Nothing Found" << std::endl;
	return -1;
}