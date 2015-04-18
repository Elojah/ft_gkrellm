#ifndef I_MONITOR_MODULE_H
# define I_MONITOR_MODULE_H

# define MAX_MODULES 8
# include <string>

class IMonitorModule
{
public:
	struct sData {
		std::string		title;
		int				h;
		int				w;
		int				y;
		int				x;
		std::string		str_content;
		int				type; // [1] string [2] graph [3] image
	};
	virtual ~IMonitorModule(void){}
	virtual void						start(void) = 0;
	virtual void						refresh(void) = 0;
	virtual IMonitorModule::sData const	&getData(void) const = 0;
protected:
private:
};

#endif
