/*
-----------------------------------------------------------------------------
Filename:    Aspect.h
-----------------------------------------------------------------------------
*/
//Christopher Mollise
//ChrisJMollise@gmail.com

#ifndef ASPECT_H
#define ASPECT_H

//---------------------------------------------------------------------------

#include "Entity381.h"

enum AspectType {
	RendererAspect,
	PhysicsAspect,
	RotatorAspect,
	NoneAspect
};

class Aspect {

public:
	Aspect(Entity381* ent);
	virtual ~Aspect();

	virtual void Tick(float dt) = 0;
	Entity381 *entity;
	AspectType aspectType;


};

class Renderer: public Aspect {
public:
	Renderer(Entity381* ent);
	~Renderer();
	virtual void Tick(float dt);
};


class Physics: public Aspect {
public:
	Physics(Entity381* ent);
	~Physics();
	virtual void Tick(float dt);
};

class Rotator: public Aspect {
public:
	Rotator(Entity381 * ent);
	~Rotator();
	virtual void Tick(float dt);
};
//---------------------------------------------------------------------------

#endif

//---------------------------------------------------------------------------
