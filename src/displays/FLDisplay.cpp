#include "FLDisplay.hpp"
#include "IMonitorModule.hpp"
#include <iostream>

FLDisplay::FLDisplay(void) {
}

FLDisplay::FLDisplay(FLDisplay const &src) {
	if (this != &src)
		*this = src;
}

FLDisplay::~FLDisplay(void) {
	for (std::vector<Fl_Box *>::const_iterator i = _children.begin(); i != _children.end(); ++i) {
		delete *i;
	}
	delete _win;

}

void			FLDisplay::start(std::vector<IMonitorModule *> const &mods) {
	IMonitorModule::sData		d;

	_win = new Fl_Window(FLWWIDTH, FLWHEIGHT, "gkrellm");
	for (std::vector<IMonitorModule *>::const_iterator i = mods.begin(); i != mods.end(); ++i) {
		d = (*i)->getData();
		_children.push_back(new Fl_Box(d.x * MULT_PIX, d.y * MULT_PIX, d.w * MULT_PIX, d.h * MULT_PIX, strdup(d.title.c_str())));
		_children.back()->box(FL_UP_BOX);
		_children.back()->labelsize(12);
		_children.back()->labelfont(FL_BOLD + FL_ITALIC);
		// _children.back()->labeltype(FL_SHADOW_LABEL);
	}
	_win->end();
	_win->show(0, 0x0);
}

void			FLDisplay::render(std::vector<IMonitorModule *> const &mods) {
	(void)mods;
}

char			FLDisplay::input(void) {
	;
	return (0);
}

FLDisplay		&FLDisplay::operator=(FLDisplay const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}
