/*
-----------------------------------------------------------------------------
Filename:    Aspect.cpp
-----------------------------------------------------------------------------
*/
//Christopher Mollise
//ChrisJMollise@gmail.com

#include <Entity381.h>
#include <Aspect.h>
#include <math.h>

Aspect::Aspect(Entity381* ent){
	entity = ent;
	aspectType = NoneAspect;
}
Aspect::~Aspect(){

}

Physics::Physics(Entity381 * ent): Aspect(ent) {
	aspectType = PhysicsAspect;
}
Physics::~Physics(){

}

void Physics::Tick(float dt){
	if (entity->entitySpeed < entity->entityDesSpeed){
		entity->entitySpeed += entity->entityAccel * dt;
		if (entity->entitySpeed > entity->entityDesSpeed)
			entity->entitySpeed = entity->entityDesSpeed;
	}
	else if (entity->entitySpeed > entity->entityDesSpeed){
		entity->entitySpeed -= entity->entityAccel * dt;
		if (entity->entitySpeed < entity->entityDesSpeed)
			entity->entitySpeed = entity->entityDesSpeed;
	}
	if (entity->entityHead < entity->entityDesHead){
		entity->entityHead += entity->entityTurnRate * dt;
		if (entity->entityHead > entity->entityDesHead)
			entity->entityHead = entity->entityDesHead;
	}
	else if (entity->entityHead > entity->entityDesHead){
		entity->entityHead -= entity->entityTurnRate * dt;
		if (entity->entityHead < entity->entityDesHead)
			entity->entityHead = entity->entityDesHead;
	}
	entity->entityVel.x = (cos(entity->entityHead * M_PI/180)*entity->entitySpeed);
	entity->entityVel.y = 0;
	entity->entityVel.z = -(sin(entity->entityHead * M_PI/180)*entity->entitySpeed);
	entity->entityPos += entity->entityVel * dt;
}

//----------------------------------------------------------

Renderer::Renderer(Entity381 * ent): Aspect(ent) {
	aspectType = RendererAspect;
}
Renderer::~Renderer(){

}

void Renderer::Tick(float dt){
	entity->ogreSceneNode->setPosition(entity->entityPos);
}

//----------------------------------------------------------

Rotator::Rotator(Entity381 * ent): Aspect(ent) {
	aspectType = RotatorAspect;
}
Rotator::~Rotator(){

}

void Rotator::Tick(float dt){
	if (entity->entityName == "Destroyer1") {
		std::cout << "Actual Head " << entity->entityHead << '\n';
		std::cout << "Desired Head " << entity->entityDesHead << '\n';
	}
	entity->ogreSceneNode->setOrientation(entity->ogreSceneNode->getInitialOrientation());
	entity->ogreSceneNode->yaw(Ogre::Degree(entity->entityHead));
}
