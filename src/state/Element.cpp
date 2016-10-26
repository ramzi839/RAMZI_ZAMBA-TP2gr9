#include "state/Element.h" 


state::Element::Element () {}
state::Element::~Element(){}

//Getters......
state::TypeId state::Element::getTypeId() {return this->typeId;}
int state::Element::getX() { return this->x;}
int state::Element::getY() { return this->y;}
//Setters.....
void state::Element::setTypeId(state::TypeId t){
	this->typeId = t;
}

void state::Element::setX(int x) {

	this->x = x;		}
void state::Element::setY(int y) {
	this->y = y; 		}


