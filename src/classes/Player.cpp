/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Player.cpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Wed May 25 20:15:12 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Player.hpp"

Player::Player()
{
	this->name = "";
	this->health = 0;
	this->mana = 0;
	this->attack = 0;
	this->defense = 0;
	this->economy = 0;
}

Player::~Player() {}