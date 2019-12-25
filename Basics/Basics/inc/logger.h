#include <iostream>
#include <chrono>
#include <time.h>

//auto nanos = std::chrono::duration_cast<nanoseconds>(now.time_since_epoch()).count();

//#define LOGGER_ENABLE
#define LOGGER_ENABLE
#ifdef LOGGER_ENABLE
	
	//#define nanoTime() std::chrono::high_resolution_clock::now().time_since_epoch()

#define LOGGER_INFO(info) {\
	auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());\
	std::cout << ctime(& now) << "::" << __FUNCTION__ << ":: " << info << std::endl;\
			}


	#define LOGGER_WARN(warning) std::cout << ctime(auto now) << "::" << __FUNCTION__ << ":: " << warning <<std::endl
	#define LOGGER_ERROR(error) std::cerr << ctime_s(auto now) << "::" << __FUNCTION__ << ":: " << error <<std::endl

#elif
	#define LOGGER_INFO(funcName, info)
	#define LOGGER_WARN(funcName, warning)
	#define LOGGER_ERROR(funcName, error)

#endif // LOGGER_ENABLE