#include "Asteroid.h"
	
Asteroid::Asteroid( list<Asteroid> *asteroids )
{
	force = vector3df(0.0f);
	velocity = vector3df(0.0f);
}

Asteroid::~Asteroid()
{

}
		
void Asteroid::Move()
{

}
		
void Asteroid::ApplyForce( vector3df direction, float strength )
{

}

float Asteroid::DistanceTo( Asteroid *other )
{

}
	
void Asteroid::ResolveCollision( Asteroid *other )//this is your job Anto
{

}

float Asteroid::GetGravityBetween( Asteroid *a, Asteroid *b )
{

}