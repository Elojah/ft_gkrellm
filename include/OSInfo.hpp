#ifndef O_S_INFO_H
# define O_S_INFO_H

# include "IMonitorModule.hpp"
class IMonitorModule;

class OSInfo: public IMonitorModule
{
public:
	OSInfo(void);
	~OSInfo(void);
	OSInfo(OSInfo const &src);
	OSInfo&	operator=(OSInfo const &rhs);
protected:
private:
};

#endif
