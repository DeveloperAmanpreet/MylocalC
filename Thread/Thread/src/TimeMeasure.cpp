#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <thread>
#include <chrono>

int ThreadFunc(int number)
{
	std::vector<int> v_int(number);

	auto f = [&]()->int {return rand() % number; };

	generate(v_int.begin(), v_int.end(), f);
	std::sort(v_int.begin(), v_int.end());


	return 0;
}

int twoThreads(int (*Func_t)(int), int count, int (*Func1_t)(int), int count1) {
	std::thread mainThread(Func_t, count);
	std::thread secondThread(Func1_t, count1);
	mainThread.join();
	secondThread.join();
	return 0;

}

int time_measure(
	int (*Func_t)(int (*)(int), int, int (*)(int), int), 
	int (*func_sub_t) (int),
	int count2,
	int count3 )
{
	auto t1 = std::chrono::high_resolution_clock::now();
	std::thread mainThread(Func_t, func_sub_t, count2, func_sub_t, count3);
	mainThread.join();
	auto t2 = std::chrono::high_resolution_clock::now();

	// floating-point duration: no duration_cast needed
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;

	// integral duration: requires duration_cast
	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

	// converting integral duration to integral duration of shorter divisible time unit:
	// no duration_cast needed
	std::chrono::duration<long, std::micro> int_usec = int_ms;

	std::cout << "TwoThread() took " << fp_ms.count() << " ms, "
		<< "or " << int_ms.count() << " whole milliseconds "
		<< "(which is " << int_usec.count() << " whole microseconds)" << std::endl;

	return 0;


}

int time_measure(int (*Func_t)(int)  , int count ){
	auto t1 = std::chrono::high_resolution_clock::now();
	std::thread mainThread(Func_t, count);
	mainThread.join();
	auto t2 = std::chrono::high_resolution_clock::now();

	// floating-point duration: no duration_cast needed
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;

	// integral duration: requires duration_cast
	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

	// converting integral duration to integral duration of shorter divisible time unit:
	// no duration_cast needed
	std::chrono::duration<long, std::micro> int_usec = int_ms;

	std::cout << "ThreadFunc() took " << fp_ms.count() << " ms, "
		<< "or " << int_ms.count() << " whole milliseconds "
		<< "(which is " << int_usec.count() << " whole microseconds)" << std::endl;
	
	return 0;
}

int main_Thread()
{
	int int_count1 = 9999;
	int int_count2 = 8888;
	time_measure(ThreadFunc, int_count1);
	time_measure(ThreadFunc, int_count2);
	time_measure(twoThreads, ThreadFunc, int_count1, int_count2);

	return 0;
}