#include "Office.h"

void Office::taxBuilding() {
	// TODO - implement Office::taxBuilding
	throw "Not yet implemented";
}

Office::Office() : Commercial("Office")
{
}

void Office::setIcon()
{
}

void Office::payEmployees()
{
}

void Office::addCitizenToBuilding(Citizen *newCitizen)
{
}

Cell *Office::clone()
{
    Cell* c = new Office();
    c->setCellType(this->getCellType());
    c->setCoordinates(this->getCoordinates());
    return c;
}
