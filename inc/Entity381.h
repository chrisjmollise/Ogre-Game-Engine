/*
-----------------------------------------------------------------------------
Filename:    Entity381.h
-----------------------------------------------------------------------------
*/
//Christopher Mollise
//ChrisJMollise@gmail.com

#ifndef ENTITY381_H
#define ENTITY381_H

#include <vector>
#include "BaseApplication.h"

//---------------------------------------------------------------------------

class Aspect;

class Entity381 {
	public:
		Entity381(void);
    	virtual ~Entity381(void);
    	void Tick(const float& dt);
    	Ogre::SceneManager * entity381SM;
    	Ogre::Real entityId;
    	Ogre::String entityName;
    	Ogre::Real entityMinSpeed;
    	Ogre::Real entityMaxSpeed;
    	Ogre::Real entitySpeed;
    	Ogre::Real entityHead;
    	Ogre::Real entityDesSpeed;
    	Ogre::Real entityDesHead;
    	Ogre::Real entityAccel;
    	Ogre::Real entityTurnRate;
    	Ogre::String entityMeshName;
    	Ogre::Vector3 entityPos;
    	Ogre::Vector3 entityVel;
    	Ogre::SceneNode* ogreSceneNode;
    	Ogre::Entity* ogreEntity;
    	std::vector<Aspect*> aspects;
};
class DestroyerEntity : public Entity381{
	public:
		DestroyerEntity(const Ogre::Real& id, const Ogre::String& name, const Ogre::Vector3& pos, const float& head, Ogre::SceneManager * mSceneMgr);
    	virtual ~DestroyerEntity();
};
class CarrierEntity : public Entity381{
	public:
		CarrierEntity(const Ogre::Real& id, const Ogre::String& name,  const Ogre::Vector3& pos, const float& head, Ogre::SceneManager * mSceneMgr);
    	virtual ~CarrierEntity();
};
class SpeedboatEntity : public Entity381{
	public:
		SpeedboatEntity(const Ogre::Real& id, const Ogre::String& name, const Ogre::Vector3& pos, const float& head, Ogre::SceneManager * mSceneMgr);
    	virtual ~SpeedboatEntity();
};
class FrigateEntity : public Entity381{
	public:
		FrigateEntity(const Ogre::Real& id, const Ogre::String& name,  const Ogre::Vector3& pos, const float& head, Ogre::SceneManager * mSceneMgr);
    	virtual ~FrigateEntity();
};
class AlienEntity : public Entity381{
	public:
		AlienEntity(const Ogre::Real& id, const Ogre::String& name,  const Ogre::Vector3& pos, const float& head, Ogre::SceneManager * mSceneMgr);
    	virtual ~AlienEntity();
};
//---------------------------------------------------------------------------

#endif

//---------------------------------------------------------------------------
