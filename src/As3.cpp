/*
-----------------------------------------------------------------------------
Filename:    As3.cpp
-----------------------------------------------------------------------------
*/
//Christopher Mollise
//ChrisJMollise@gmail.com

#include <As3.h>
#include <EntityMgr.h>
#include <vector>

//---------------------------------------------------------------------------
As3::As3(void) {
	cameraNode = NULL;
	entityMgr = NULL;
	surfaceHeight = -50;
	tabPressed = false;
	upHeadPressed = false;
	downHeadPressed = false;
	upVelPressed = false;
	downVelPressed = false;
	mRMouseDown = false;
	mLMouseDown = false;
}
//---------------------------------------------------------------------------
As3::~As3(void) {
}
//Create Scene
void As3::createScene(void)
{

  mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

  mCamera->lookAt(Ogre::Vector3(0, 0, 0));

  Ogre::Light* light = mSceneMgr->createLight("MainLight");
  light->setPosition(20.0, 80.0, 50.0);

  // a fixed point in the ocean so you can see relative motion

  Ogre::Entity* ogreEntityFixed = mSceneMgr->createEntity("robot.mesh");
  Ogre::SceneNode* sceneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("Robot", Ogre::Vector3(0, 100, -200));
  sceneNode->attachObject(ogreEntityFixed);
  sceneNode->showBoundingBox(true);

  // A node to attach the camera to so we can move the camera node instead of the camera.
  cameraNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("MyCamera");
  cameraNode->setPosition(0, 200, 1000);
  cameraNode->attachObject(mCamera);

  MakeGround();
  MakeSky();

  entityMgr = new EntityMgr(mSceneMgr);//=========================
  MakeEnts();
}
bool As3::frameRenderingQueued(const Ogre::FrameEvent& fe){

	mKeyboard->capture();
	mKeyboard->setEventCallback(this);
	if(mKeyboard->isKeyDown(OIS::KC_Q)){
		return false;
	}

	mTrayMgr->frameRenderingQueued(fe);

	UpdateCamera(fe);

	UpdateDesiredSpeedHeading(fe);

	entityMgr->Tick(fe.timeSinceLastFrame);//================

	return true;
}
void As3::MakeGround(){

	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, surfaceHeight);

	  Ogre::MeshManager::getSingleton().createPlane(
	    "ground",
	    Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
	    plane,
	    10000, 10000, 20, 20,
	    true,
	    1, 5, 5,
	    Ogre::Vector3::UNIT_Z);

	  Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
	  mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
	  groundEntity->setCastShadows(false);
	  //groundEntity->setMaterialName("Ocean2_HLSL_GLSL");
	  groundEntity->setMaterialName("OceanHLSL_GLSL");
	  //groundEntity->setMaterialName("Ocean2_Cg");
	  //groundEntity->setMaterialName("NavyCg");
}
void As3::MakeSky(){
	mSceneMgr->setSkyBox(true, "Examples/MorningSkyBox");
	//mSceneMgr->setSkyBox(true, "Examples/EveningSkyBox");
}
void As3::MakeEnts() {
	entityMgr->entities.push_back (
				entityMgr->CreateEntityOfTypeAtPositionAndHeading(Destroyer, Ogre::Vector3(-500,-50,0), 0));
	entityMgr->entities.push_back (
			entityMgr->CreateEntityOfTypeAtPositionAndHeading(Carrier, Ogre::Vector3(-250,-50,0), 0));
	entityMgr->entities.push_back (
			entityMgr->CreateEntityOfTypeAtPositionAndHeading(Speedboat, Ogre::Vector3(0,-50,0), 0));
	entityMgr->entities.push_back (
			entityMgr->CreateEntityOfTypeAtPositionAndHeading(Frigate, Ogre::Vector3(250,-50,0), 0));
	entityMgr->entities.push_back (
			entityMgr->CreateEntityOfTypeAtPositionAndHeading(Alien, Ogre::Vector3(500,-50,0), 0));
}
void As3::UpdateCamera(const Ogre::FrameEvent& fe) {
	/**Variables**/
	static Ogre::Real camMove = 300; //Stores Camera Move Degree
	static Ogre::Real rotate = 0.5; //Stores Camera Rotate Degree
	Ogre::Vector3 camDisVec = Ogre::Vector3::ZERO;	//Stores Vector Used for Camera Distance

	//Get Camera Inputs
		if (mKeyboard->isKeyDown(OIS::KC_R))
			camDisVec.y += camMove;
		if (mKeyboard->isKeyDown(OIS::KC_F))
			camDisVec.y -= camMove;
		if (mKeyboard->isKeyDown(OIS::KC_D)) {
			if(mKeyboard->isKeyDown(OIS::KC_LSHIFT)) //Use Shift to Change Yaw
				mSceneMgr->getSceneNode("MyCamera")->yaw(Ogre::Degree(-1* rotate));
			else //Otherwise Move
				camDisVec.x += camMove;
		}
		if (mKeyboard->isKeyDown(OIS::KC_A)) {
			if(mKeyboard->isKeyDown(OIS::KC_LSHIFT)) //Use Shift to Change Yaw
				mSceneMgr->getSceneNode("MyCamera")->yaw(Ogre::Degree(rotate));
			else //Otherwise Move
				camDisVec.x -= camMove;
		}
		if (mKeyboard->isKeyDown(OIS::KC_S)) {
			if(mKeyboard->isKeyDown(OIS::KC_LSHIFT)) //Use Shift to Change Yaw
				mSceneMgr->getSceneNode("MyCamera")->pitch(Ogre::Degree(-1* rotate));
			else //Otherwise Move
				camDisVec.z += camMove;
		}
		if (mKeyboard->isKeyDown(OIS::KC_W)) {
			if(mKeyboard->isKeyDown(OIS::KC_LSHIFT)) //Use Shift to Change Yaw
				mSceneMgr->getSceneNode("MyCamera")->pitch(Ogre::Degree(rotate));
			else //Otherwise Move
				camDisVec.z -= camMove;
		}
		//Get the Scene Node and set new camera position
		mSceneMgr->getSceneNode("MyCamera")->translate(
			camDisVec * fe.timeSinceLastFrame,
			Ogre::Node::TS_LOCAL);
}
void As3::UpdateDesiredSpeedHeading(const Ogre::FrameEvent& fe) {
	if (mKeyboard->isKeyDown(OIS::KC_SPACE)) {
		entityMgr->entities[entityMgr->entitySelected]->entityDesSpeed = 0;
		entityMgr->entities[entityMgr->entitySelected]->entityDesHead = 0;
	}
}
bool As3::keyPressed(const OIS::KeyEvent& ke, const OIS::MouseEvent &e) {
	static Ogre::Real boatVel = 10; //Stores Boat Velocity Degree
	static Ogre::Real boatRot = 15; //Stores Boat Rotate Degree


	switch(ke.key) {
		case OIS::KC_TAB:
			if(!tabPressed) {
				entityMgr->entitySelected++;
  				if (entityMgr->entitySelected >= entityMgr->entities.size())
  					entityMgr->entitySelected = 0;
  				tabPressed = true;
			}
		break;
		case OIS::KC_NUMPAD2:
			if (!downVelPressed){
				entityMgr->entities[entityMgr->entitySelected]->entityDesSpeed -= boatVel;
				downVelPressed = false;
			}
		break;
		case OIS::KC_NUMPAD8:
			if (!upVelPressed){
				entityMgr->entities[entityMgr->entitySelected]->entityDesSpeed += boatVel;
				upVelPressed = false;
			}
		break;
		case OIS::KC_NUMPAD4:
			if (!downHeadPressed){
				entityMgr->entities[entityMgr->entitySelected]->entityDesHead -= boatRot;
				downHeadPressed = false;
			}
		break;
		case OIS::KC_NUMPAD6:
			if (!upHeadPressed){
				entityMgr->entities[entityMgr->entitySelected]->entityDesHead += boatRot;
				upHeadPressed = false;
			}
		break;
		case OIS::MB_Left:
			mLMouseDown = true;
  		break;
		case OIS::MB_Right:
			mRMouseDown = true;
		break;
		default:
		break;
	}

	if (entityMgr->entities[entityMgr->entitySelected]->entityDesSpeed <= entityMgr->entities[entityMgr->entitySelected]->entityMinSpeed)
		entityMgr->entities[entityMgr->entitySelected]->entityDesSpeed = entityMgr->entities[entityMgr->entitySelected]->entityMinSpeed;
	if (entityMgr->entities[entityMgr->entitySelected]->entityDesSpeed >= entityMgr->entities[entityMgr->entitySelected]->entityMaxSpeed)
		entityMgr->entities[entityMgr->entitySelected]->entityDesSpeed = entityMgr->entities[entityMgr->entitySelected]->entityMaxSpeed;


	return true;
}

bool As3::keyReleased(const OIS::KeyEvent& ke, const OIS::MouseEvent &e) {
	switch(ke.key) {
		case OIS::KC_TAB:
  			tabPressed = false;
		break;
		case OIS::MB_Left:
			mLMouseDown = false;
		  break;
		case OIS::MB_Right:
			mRMouseDown = false;
		break;
		default:
		break;
	}
	return true;
}
//---------------------------------------------------------------------------

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        As3 app;

        try {
            app.go();
        } catch(Ogre::Exception& e)  {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox(NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occurred: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif

//---------------------------------------------------------------------------
