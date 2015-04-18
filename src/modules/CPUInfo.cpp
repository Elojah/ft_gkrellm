#include "CPUInfo.hpp"

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
	;
}

IMonitorModule::sData const	&CPUInfo::getData(void) const {
	return (_data);
}


