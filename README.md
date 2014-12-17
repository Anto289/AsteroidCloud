AsteroidCloud
=============

Physics based depiction of asteroid behaviour when interacting with other asteroids/planets given their mass, gravity effect and collision

Anto
	Initialisation
		setup, create al of the asteroids, random position, blah blah blah
	Narrow Phase
		detect collisions between pairs of asteroids in the surrounding grids
	Collision Response
		decide what to do with each collision pair i.e. alter their velocity and move them so they are no longer intersecting

Cormac
	Asteroid Class
		simples
	Broad Phase Collision
		3d grid, put every asteroid into a certain box in the grid, resize the grid when the outer boxes are all empty
	Gravity
		use the grid to calculate the gravity acting upon every asteroid and alter their velocities accordingly
