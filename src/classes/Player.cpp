/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Player.cpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun  5 18:43:50 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Player.hpp"

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

Player::Player(): name("")
{
	this->health = 0;
	this->attack = 0;
	this->defense = 0;
	this->economy = 0;

	this->X = 0;
	this->Y = 0;
}

Player::Player(const Player &p): name(p.name)
{
	this->operator=(p);
}

Player::~Player()
{
}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

Player		&Player::operator=(const Player &p)
{
	this->health = p.health;
	this->attack = p.attack;
	this->defense = p.defense;
	this->economy = p.economy;

	this->X = p.X;
	this->Y = p.Y;

	return *this;
}

/* ****************************************************** */
/*                                                        */
/*                   GETTER AND SETTERS                   */
/* Simple functions which allows for control over objects */
/*                                                        */
/* ****************************************************** */

double		Player::getX(void) {return this->X;}
double		Player::getY(void) {return this->Y;}
std::string	Player::getName(void) {return this->name;}
size_t		Player::getHealth(void) {return this->health;}
size_t		Player::getAttack(void) {return this->attack;}
size_t		Player::getDefense(void) {return this->defense;}
double		Player::getEconomy(void) {return this->economy;}

double		Player::getX(void) const {return this->X;}
double		Player::getY(void) const {return this->Y;}
std::string	Player::getName(void) const {return this->name;}
size_t		Player::getHealth(void) const {return this->health;}
size_t		Player::getAttack(void) const {return this->attack;}
size_t		Player::getDefense(void) const {return this->defense;}
double		Player::getEconomy(void) const {return this->economy;}

void		Player::setX(double X) {this->X = X;}
void		Player::setY(double Y) {this->Y = Y;}
void		Player::setHealth(size_t hp) {this->health = hp;}
void		Player::setAttack(size_t atk) {this->attack = atk;}
void		Player::setDefense(size_t def) {this->defense = def;}
void		Player::setEconomy(double value) {this->economy = value;}
void		Player::setPos(double X, double Y) {this->X = X; this->Y = Y;}

/* ****************************************************** */
/*                                                        */
/*                    MEMBER FUNCTIONS                    */
/* Declarations of member functions ready to use anywhere */
/*                                                        */
/* ****************************************************** */
