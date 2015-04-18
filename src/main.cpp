#include "Master.hpp"

int		main(void) {
	Master	m(1);

	m.createModules(1);
	m.loop();
	return (0);
}
