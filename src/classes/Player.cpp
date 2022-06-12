/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Player.cpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun 12 18:34:34 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Player.hpp"

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

Player::Player(): Entity("Noob", ENTITY_PLAYER) {};
Player::Player(const std::string &name): Entity(name, ENTITY_PLAYER) {}
Player::Player(const Player &p): Entity(p.name, ENTITY_PLAYER) {}
Player::~Player() {}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

Player		&Player::operator=(const Player &p)
{
	Entity::operator=(p);
	return *this;
}

/* ****************************************************** */
/*                                                        */
/*                   GETTER AND SETTERS                   */
/* Simple functions which allows for control over objects */
/*                                                        */
/* ****************************************************** */

/* Currently None */

/* ****************************************************** */
/*                                                        */
/*                    MEMBER FUNCTIONS                    */
/* Declarations of member functions ready to use anywhere */
/*                                                        */
/* ****************************************************** */

/* Currently None */