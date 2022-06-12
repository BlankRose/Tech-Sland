/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Entity.cpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun 12 18:43:50 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Entity.hpp"

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

Entity::Entity(): Entity(NULL, ENTITY_UNDEFINIED) {}
Entity::Entity(const size_t &id): Entity(NULL, id) {};

Entity::Entity(const std::string &name, const size_t &id): id(id)
{
	this->name = name;
	this->dir = NORTH;
	this->dx = 0.0f;
	this->dy = 0.0f;
	this->x = 0;
	this->y = 0;
}

Entity::Entity(const Entity &p): id(p.id) {*this = p;}
Entity::~Entity() {}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

Entity		&Entity::operator=(const Entity &p)
{
	this->dir = p.dir;
	this->dx = p.dx;
	this->dy = p.dy;
	this->x = p.x;
	this->y = p.y;

	return *this;
}

/* ****************************************************** */
/*                                                        */
/*                   GETTER AND SETTERS                   */
/* Simple functions which allows for control over objects */
/*                                                        */
/* ****************************************************** */

std::string		Entity::getName(void) {return this->name;}
std::string		Entity::getName(void) const {return this->name;}

size_t			Entity::getID(void) {return this->id;}
size_t			Entity::getID(void) const {return this->id;}

Direction		Entity::getDir(void) {return this->dir;}
Direction		Entity::getDir(void) const {return this->dir;}

float			Entity::getDX(void) {return this->dx;}
float			Entity::getDY(void) {return this->dy;}
float			Entity::getDX(void) const {return this->dx;}
float			Entity::getDY(void) const {return this->dy;}

int				Entity::getX(void) {return this->x;}
int				Entity::getY(void) {return this->y;}
int				Entity::getX(void) const {return this->x;}
int				Entity::getY(void) const {return this->y;}

/* ****************************************************** */
/*                                                        */
/*                    MEMBER FUNCTIONS                    */
/* Declarations of member functions ready to use anywhere */
/*                                                        */
/* ****************************************************** */

Direction		Entity::getDir(int x, int y, float dx, float dy)
{
	/* Horizontal movement */
	if (abs(x) > abs(y) || (x == y && (abs(dx) > abs(dy)))) {
		if (x >= 0) return EAST;
		else return WEST;
	}

	/* Vertical movement */
	else {
		if (y >= 0) return NORTH;
		else return SOUTH;
	}
}

void			Entity::movePos(int x, int y, float dx, float dy)
{
	this->x += x; this->dx += dx;
	this->y += y; this->dy += dy;
	dir = getDir(x, y, dx, dy);
}

void			Entity::setPos(int x, int y, float dx, float dy)
{
	this->x = x; this->dx = dx;
	this->y = y; this->dy = dy;
}