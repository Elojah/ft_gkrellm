#include "Master.hpp"
#include "NCursesDisplay.hpp"
#include "FLDisplay.hpp"
#include "UserInfo.hpp"
#include "OSInfo.hpp"
#include <cstdlib>
#include <iostream>

Master::Master(int nDisplay) {
	if (nDisplay == 0) {
		_dis = new NCursesDisplay();
	} else if (nDisplay == 1) {
		_dis = new FLDisplay();
	}
	std::cout << "Dis:\t" << _dis << std::endl;
}

void			Master::createModules(int nModules) {
	if (nModules < 0 || nModules > MAX_MODULES - 1) {
		return ;
	}
	_mods.push_back(new UserInfo());
	_mods.push_back(new OSInfo());
	/*
	ADD
	*/
	for (std::vector<IMonitorModule *>::iterator i = _mods.begin(); i != _mods.end(); ++i) {
		(*i)->start();
		(*i)->refresh();
	}
	_dis->start(_mods);
}

Master::Master(Master const &src) {
	if (this != &src)
		*this = src;
}

void			Master::loop(void) {
	clock_t		t;
	clock_t		tmp;
	char		input;

	t = clock();
	_dis->render(_mods);
	while (true) {
		input = _dis->input();
		if (input == ESC) {
			break ;
		}
		if ((tmp = clock() - t) > REFRESH_TIME) {
			for (std::vector<IMonitorModule *>::iterator i = _mods.begin(); i != _mods.end(); ++i) {
				(*i)->refresh();
			}
			_dis->render(_mods);
		}
	}
}


Master::~Master(void) {
	delete _dis;
	for (std::vector<IMonitorModule *>::iterator i = _mods.begin(); i != _mods.end(); ++i) {
		delete *i;
	}

}

Master		&Master::operator=(Master const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}
