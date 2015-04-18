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
# include <FL/Fl_Box.H>

class FLDisplay : public IMonitorDisplay
{
public:
	FLDisplay(void);
	~FLDisplay(void);
	FLDisplay(FLDisplay const &src);
	FLDisplay&	operator=(FLDisplay const &rhs);
	virtual void			start(std::vector<IMonitorModule *> const &mods);
	virtual void			render(std::vector<IMonitorModule *> const &mods);
	virtual char			input(void);

protected:
private:
	Fl_Window				*_win;
	std::vector<Fl_Box *>	_children;
};

#endif
