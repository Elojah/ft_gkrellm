#include "OSInfo.hpp"

OSInfo::OSInfo(void) {
}

OSInfo::OSInfo(OSInfo const &src) {
	if (this != &src)
		*this = src;
}

OSInfo::~OSInfo(void) {
}

OSInfo		&OSInfo::operator=(OSInfo const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}
