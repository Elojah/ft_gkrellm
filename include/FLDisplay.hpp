#ifndef F_L_DISPLAY_H
# define F_L_DISPLAY_H

# define MULT_PIX 10

# include "IMonitorDisplay.hpp"
class IMonitorDisplay;
class IMonitorModule;

/*
RISKED !!!
*/
# undef border

# include <FL/Fl.H>
# include <FL/Fl_Window.H>
# include <FL/Fl_Group.H>
# include <FL/Fl_Tabs.H>

class FLDisplay : public IMonitorDisplay
{
public:
	FLDisplay(void);
	~FLDisplay(void);
	FLDisplay(FLDisplay const &src);
	FLDisplay&	operator=(FLDisplay const &rhs);
	virtual void			start(std::vector<IMonitorModule *> const &mods);
	virtual void			render(std::vector<IMonitorModule *> const &mods);
	virtual int				input(void);

protected:
private:
	Fl_Window				*_win;
	Fl_Tabs					*_tab;
	std::vector<Fl_Group *>	_children;
};

#endif
