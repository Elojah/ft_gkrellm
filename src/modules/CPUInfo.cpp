#include "CPUInfo.hpp"
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>
#include <iostream>

CPUInfo::CPUInfo(void) {
	_data.title = "CPU info";
	_data.h = 15;
	_data.w = 50;
	_data.y = 7;
	_data.x = 52;
	_data.type = 1;
}

CPUInfo::CPUInfo(CPUInfo const &src) {
	if (this != &src)
		*this = src;
}

CPUInfo::~CPUInfo(void) {
}

CPUInfo		&CPUInfo::operator=(CPUInfo const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void	CPUInfo::start(void) {
	FILE			*pipe(popen("sysctl -n machdep.cpu.brand_string", "r"));
	char			buffer[128];
	std::string		os;
	std::string		version;

	if (pipe)
	{
		while(!feof(pipe))
		{
			if(fgets(buffer, 128, pipe))
				os += buffer;
		}
		pclose(pipe);
		_data.str_content += " CPU: " + os;
		_data.str_content.pop_back();
		_data.str_content += "  /  ";
	}
}

void						CPUInfo::refresh(void) {
	static unsigned long long _previousTotalTicks = 0;
	static unsigned long long _previousIdleTicks = 0;

   host_cpu_load_info_data_t cpuinfo;
   mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
   if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
   {
		unsigned long long totalTicks = 0;
		for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
		unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
		unsigned long long idleTicksSinceLastTime  = cpuinfo.cpu_ticks[CPU_STATE_IDLE]-_previousIdleTicks;
		float sysLoadPercentage = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
		_previousTotalTicks = totalTicks;
		_previousIdleTicks  = cpuinfo.cpu_ticks[CPU_STATE_IDLE];
		std::cout << sysLoadPercentage * 100 << std::endl;
   }

}

IMonitorModule::sData const	&CPUInfo::getData(void) const {
	return (_data);
}


