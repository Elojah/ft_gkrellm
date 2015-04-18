#include "FLDisplay.hpp"

FLDisplay::FLDisplay(void) {
}

FLDisplay::FLDisplay(FLDisplay const &src) {
	if (this != &src)
		*this = src;
}

FLDisplay::~FLDisplay(void) {
}

void			FLDisplay::start(std::vector<IMonitorModule *> const &mods) {
	(void)mods;

	Fl_Window *window = new Fl_Window(FLWWIDTH, FLWHEIGHT, "gkrellm");
	/*Fl_Box *box = new Fl_Box(20,40,260,100,"Hello, World!");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);*/
	window->end();
	window->show(0, 0x0);
	Fl::run();
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
