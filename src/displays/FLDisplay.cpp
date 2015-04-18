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
	// for (std::vector<Fl_Text_Buffer *>::const_iterator i = _buffers.begin(); i != _buffers.end(); ++i) {
	// 	delete *i;
	// }
	// for (std::vector<Fl_Text_Display *>::const_iterator i = _text.begin(); i != _text.end(); ++i) {
	// 	delete *i;
	// }
	// for (std::vector<Fl_Group *>::const_iterator i = _children.begin(); i != _children.end(); ++i) {
	// 	delete *i;
	// }
	_win->hide();
	delete _tab;
	delete _win;
}

void			FLDisplay::start(std::vector<IMonitorModule *> const &mods) {
	IMonitorModule::sData		d;
	Fl_Group					*tmp;

	_win = new Fl_Window(FLWWIDTH, FLWHEIGHT, "gkrellm");
	{
		_tab = new Fl_Tabs(10, 10, FLWWIDTH - 20, FLWHEIGHT - 20);
		{
			int		width;
			int		height;

			width = 20;
			height = 35;
			for (std::vector<IMonitorModule *>::const_iterator i = mods.begin(); i != mods.end(); ++i) {
				d = (*i)->getData();
				tmp = new Fl_Group(10, 35, FLWWIDTH - width, FLWHEIGHT - height, strdup(d.title.c_str()));
				{
					interpretData(d);
				}
				_children.push_back(tmp);
				_children.back()->end();
				width -= 10;
				height -= 10;
			}
		}
		_tab->end();
	}
	_win->end();
	_win->show(0, 0x0);
}

void			FLDisplay::interpretData(IMonitorModule::sData &d) {
	Fl_Text_Display	*tmp;
	Fl_Text_Buffer	*buf;

	if (d.type == 1) {
		buf = new Fl_Text_Buffer();
		tmp = new Fl_Text_Display(20, 50, FLWWIDTH - 40, 50, "");
		tmp->buffer(buf);
		_win->resizable(*tmp);
		_win->show();
		_text.push_back(tmp);
		_buffers.push_back(buf);
		buf->text(d.str_content.c_str());
	}
}

void			FLDisplay::render(std::vector<IMonitorModule *> const &mods) {
	unsigned int	i;
	unsigned int	len;

	len = mods.size();
	for (i = 0; i < len; ++i) {
		_buffers[i]->text(mods[i]->getData().str_content.c_str());
	}
	Fl::wait(0.5);/*HARDCODE*/
}

int			FLDisplay::input(void) {
	int			n(0);

	n = Fl::event_key();
	return (n);
}

FLDisplay		&FLDisplay::operator=(FLDisplay const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}
