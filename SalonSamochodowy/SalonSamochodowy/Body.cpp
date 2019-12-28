#include<string>
#include"Body.h"

Body::Body(std::string t, int doors, int seats,
	int trunk, std::string clr, std::string sclr)
	:
	type(t),
	doors(doors),
	seats(seats),
	trunkCapacity(trunk),
	color(clr),
	specificColor(sclr)
{}
std::string Body::getColor() {
	return this->color;
}
std::string Body::getType() {
	return this->type;
}
int Body::getDoors() {
	return this->doors;
}