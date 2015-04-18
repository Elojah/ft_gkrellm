#ifndef I_MONITOR_DISPLAY_H
# define I_MONITOR_DISPLAY_H

# define REFRESH_TIME 500
# define ESCFL 65307
# define ESCNC 27
# define FLWWIDTH 1200
# define FLWHEIGHT 900

# include <vector>
class IMonitorModule;

class IMonitorDisplay
{
public:
	virtual ~IMonitorDisplay(void){}
	virtual void			start(std::vector<IMonitorModule *> const &mods) = 0;
	virtual void			render(std::vector<IMonitorModule *> const &mods) = 0;
	virtual int				input(void) = 0;
protected:
private:
};

#endif
