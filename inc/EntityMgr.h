/*
-----------------------------------------------------------------------------
Filename:    EntityMgr.h
-----------------------------------------------------------------------------
*/
//Christopher Mollise
//ChrisJMollise@gmail.com

#ifndef ENTITYMGR_H
#define ENTITYMGR_H

#include <vector>
#include "BaseApplication.h"
#include "Entity381.h"

//---------------------------------------------------------------------------

enum EntityType {Destroyer, Carrier, Speedboat, Frigate, Alien};

class EntityMgr {
	public:
		EntityMgr(Ogre::SceneManager * mSceneMgr);
    	virtual ~EntityMgr(void);
    	void Tick(const float& dt);
    	Entity381 * CreateEntityOfTypeAtPositionAndHeading(EntityType type, Ogre::Vector3 pos, float head);
    	Ogre::SceneManager * entityMgrSM;
    	std::vector<Entity381*> entities;
    	Ogre::Real entitySelected;
};

//---------------------------------------------------------------------------

#endif

//---------------------------------------------------------------------------
