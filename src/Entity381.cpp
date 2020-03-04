/*
-----------------------------------------------------------------------------
Filename:    Entity381.cpp
-----------------------------------------------------------------------------
*/
//Christopher Mollise
//ChrisJMollise@gmail.com

#include <Entity381.h>
#include <Aspect.h>

Entity381::Entity381(void) {
	entity381SM = NULL;
	entityId = 0;
	entityName = Ogre::String("Null");
	entityMinSpeed = 0;
	entityMaxSpeed = 0;
	entitySpeed = 0;
	entityHead = 0;
	entityDesSpeed = 0;
	entityDesHead = 0;
	entityAccel = 0;
	entityTurnRate = 0;
	entityPos = Ogre::Vector3::ZERO;
	entityVel = Ogre::Vector3::ZERO;
	ogreSceneNode = NULL;
	ogreEntity = NULL;

	aspects.push_back(new Physics(this));
	aspects.push_back(new Renderer(this));
	aspects.push_back(new Rotator(this));
}
Entity381::~Entity381(void) {

}
void Entity381::Tick(const float& dt) {
	for (size_t i = 0; i < aspects.size(); i++)
		aspects[i]->Tick(dt);

}
DestroyerEntity::DestroyerEntity(const Ogre::Real& id, const Ogre::String& name, const Ogre::Vector3& pos, const float& head, Ogre::SceneManager * mSceneMgr): Entity381() {
	//Set all variables
	entityId = id;
	entityName = name;
	entityPos = pos;
	entity381SM = mSceneMgr;
	entityMinSpeed = 0;
	entityMaxSpeed = 40;
	entitySpeed = 0;
	entityHead = head;
	entityDesSpeed = 0;
	entityDesHead = head;
	entityAccel = 4;
	entityTurnRate = 10;
	entityMeshName = "ddg51.mesh";
	//Create ogreEntity
	ogreEntity = entity381SM->createEntity(entityMeshName);
	//Create SceneNode For Entity As a Child of the RootSceneNode
	ogreSceneNode = entity381SM->getRootSceneNode()->createChildSceneNode(entityName);
	//Change Position/Scale/Rotation Settings
	ogreSceneNode->setPosition(entityPos);
	//Attach created entity to SceneNode
	ogreSceneNode->attachObject(ogreEntity);
}
DestroyerEntity::~DestroyerEntity(void) {

}
CarrierEntity::CarrierEntity(const Ogre::Real& id, const Ogre::String& name, const Ogre::Vector3& pos, const float& head, Ogre::SceneManager * mSceneMgr): Entity381() {
	//Set all variables
	entityId = id;
	entityName = name;
	entityPos = pos;
	entity381SM = mSceneMgr;
	entityMinSpeed = 0;
	entityMaxSpeed = 80;
	entitySpeed = 0;
	entityHead = head;
	entityDesSpeed = 0;
	entityDesHead = head;
	entityAccel = 10;
	entityTurnRate = 2;
	entityMeshName = "cvn68.mesh";
	//Create ogreEntity
	ogreEntity = entity381SM->createEntity(entityMeshName);
	//Create SceneNode For Entity As a Child of the RootSceneNode
	ogreSceneNode = entity381SM->getRootSceneNode()->createChildSceneNode(entityName);
	//Change Position/Scale/Rotation Settings
	ogreSceneNode->setPosition(entityPos);
	//Attach created entity to SceneNode
	ogreSceneNode->attachObject(ogreEntity);
}
CarrierEntity::~CarrierEntity(void) {

}
SpeedboatEntity::SpeedboatEntity(const Ogre::Real& id, const Ogre::String& name, const Ogre::Vector3& pos, const float& head, Ogre::SceneManager * mSceneMgr): Entity381() {
	//Set all variables
	entityId = id;
	entityName = name;
	entityPos = pos;
	entity381SM = mSceneMgr;
	entityMinSpeed = 0;
	entityMaxSpeed = 30;
	entitySpeed = 0;
	entityHead = head;
	entityDesSpeed = 0;
	entityDesHead = head;
	entityAccel = 8;
	entityTurnRate = 20;
	entityMeshName = "cigarette.mesh";
	//Create ogreEntity
	ogreEntity = entity381SM->createEntity(entityMeshName);
	//Create SceneNode For Entity As a Child of the RootSceneNode
	ogreSceneNode = entity381SM->getRootSceneNode()->createChildSceneNode(entityName);
	//Change Position/Scale/Rotation Settings
	ogreSceneNode->setPosition(entityPos);
	//Attach created entity to SceneNode
	ogreSceneNode->attachObject(ogreEntity);
}
SpeedboatEntity::~SpeedboatEntity(void) {

}
FrigateEntity::FrigateEntity(const Ogre::Real& id, const Ogre::String& name, const Ogre::Vector3& pos, const float& head, Ogre::SceneManager * mSceneMgr): Entity381() {
	//Set all variables
	entityId = id;
	entityName = name;
	entityPos = pos;
	entity381SM = mSceneMgr;
	entityMinSpeed = 0;
	entityMaxSpeed = 50;
	entitySpeed = 0;
	entityHead = head;
	entityDesSpeed = 0;
	entityDesHead = head;
	entityAccel = 6;
	entityTurnRate = 12;
	entityMeshName = "sleek.mesh";
	//Create ogreEntity
	ogreEntity = entity381SM->createEntity(entityMeshName);
	//Create SceneNode For Entity As a Child of the RootSceneNode
	ogreSceneNode = entity381SM->getRootSceneNode()->createChildSceneNode(entityName);
	//Change Position/Scale/Rotation Settings
	ogreSceneNode->setPosition(entityPos);
	//Attach created entity to SceneNode
	ogreSceneNode->attachObject(ogreEntity);
}
FrigateEntity::~FrigateEntity(void) {

}
AlienEntity::AlienEntity(const Ogre::Real& id, const Ogre::String& name, const Ogre::Vector3& pos, const float& head, Ogre::SceneManager * mSceneMgr): Entity381() {
	//Set all variables
	entityId = id;
	entityName = name;
	entityPos = pos;
	entity381SM = mSceneMgr;
	entityMinSpeed = 0;
	entityMaxSpeed = 200;
	entitySpeed = 0;
	entityHead = head;
	entityDesSpeed = 0;
	entityDesHead = head;
	entityAccel = 30;
	entityTurnRate = 60;
	entityMeshName = "alienship.mesh";
	//Create ogreEntity
	ogreEntity = entity381SM->createEntity(entityMeshName);
	//Create SceneNode For Entity As a Child of the RootSceneNode
	ogreSceneNode = entity381SM->getRootSceneNode()->createChildSceneNode(entityName);
	//Change Position/Scale/Rotation Settings
	ogreSceneNode->setPosition(entityPos);
	//Attach created entity to SceneNode
	ogreSceneNode->attachObject(ogreEntity);
}
AlienEntity::~AlienEntity(void) {

}
