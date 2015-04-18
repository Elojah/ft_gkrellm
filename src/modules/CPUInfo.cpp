#include "CPUInfo.hpp"

CPUInfo::CPUInfo(void) {
	_data.title = "CPU info";
	_data.h = 5;
	_data.w = 50;
	_data.y = 7;
	_data.x = 52;
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
	FILE		*pipe(popen("sysctl -n machdep.cpu.brand_string", "r"));
	char		buffer[128];
	std::string	os("");
	std::string	version("");

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
	pipe = popen("uname -r", "r");
	if (pipe)
	{
		while(!feof(pipe))
		{
			if(fgets(buffer, 128, pipe))
				version += buffer;
		}
		pclose(pipe);
		_data.str_content += " Version: " + version;
		_data.str_content.pop_back();
	}
}

void						CPUInfo::refresh(void) {
	;
}

IMonitorModule::sData const	&CPUInfo::getData(void) const {
	return (_data);
}


