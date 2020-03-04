/*
-----------------------------------------------------------------------------
Filename:    EntityMgr.cpp
-----------------------------------------------------------------------------
*/
//Christopher Mollise
//ChrisJMollise@gmail.com

#include <EntityMgr.h>
#include <Entity381.h>

EntityMgr::EntityMgr(Ogre::SceneManager * mSceneMgr) {
	entityMgrSM = mSceneMgr;
	entitySelected = 0;
}
EntityMgr::~EntityMgr(void) {

}
void EntityMgr::Tick(const float& dt) {
	for (size_t i = 0; i < entities.size(); i++){
		if (i == entitySelected)
			entities[i]->ogreSceneNode->showBoundingBox(true);
		else
			entities[i]->ogreSceneNode->showBoundingBox(false);
		entities[i]->Tick(dt);
	}
}
Entity381 * EntityMgr::CreateEntityOfTypeAtPositionAndHeading(EntityType type, Ogre::Vector3 pos, float head) {
	Entity381 * newEntity;
	Ogre::Real id = entities.size() + 1;
	Ogre::String name;

	switch (type) {
		case Destroyer:
			name = "Destroyer" + Ogre::StringConverter::toString(id);
			newEntity = new DestroyerEntity(id, name, pos, head, entityMgrSM);
		break;
		case Carrier:
			name = "Carrier" + Ogre::StringConverter::toString(id);
			newEntity = new CarrierEntity(id, name, pos, head, entityMgrSM);
		break;
		case Speedboat:
			name = "Speedboat" + Ogre::StringConverter::toString(id);
			newEntity = new SpeedboatEntity(id, name, pos, head, entityMgrSM);
		break;
		case Frigate:
			name = "Frigate" + Ogre::StringConverter::toString(id);
			newEntity = new FrigateEntity(id, name, pos, head, entityMgrSM);
		break;
		case Alien:
			name = "Alien" + Ogre::StringConverter::toString(id);
			newEntity = new AlienEntity(id, name, pos, head, entityMgrSM);
		break;
	}
	return newEntity;
}
