#ifndef ASTEROID_H
#define ASTEROID_H

#include <irrlicht.h>
#include <cmath>

using namespace irr;
using namespace irr::core;

#define DENSITY 3346.4//kilograms per cube meter... density of the moon... very arbitrary
#define G 0.000000000066742

class Asteroid
{
private:
	vector3di gridLocation;
	vector3df position;
	vector3df prevPosition;//prevposition tells us where it was last frame, we can use this to avoid tunnelling... optional
	vector3df force;//the amount of force acting upon 
	vector3df velocity;
	float radius;
	float mass;
	
public:
	vector3di SetGridLocation( vector3di gl ){ gridLocation = gl; }
	vector3di GetGridLocation(){ return gridLocation; }
	vector3df GetPosition(){ return position; }
	vector3df GetPrevposition(){ return prevPosition; }
	float GetMass(){ return mass; }
	float GetRadius(){ return radius; }
	
	Asteroid( list<Asteroid> *asteroids );//a pointer to all of the asteroids already created
	~Asteroid();
		
	void Move();
		
	//strength should be in newtons
	void ApplyForce( vector3df direction, float strength );//direction need not be normalised, just subtract the position of this asteroid from the one exerting the force... if strength is negative then the force will be away from direction... good for using when trying to push away from collisions

	float DistanceTo( Asteroid *other );
	
	void ResolveCollision( Asteroid *other );

	static float GetGravityBetween( Asteroid *a, Asteroid *b );
};

#endif