/*
-----------------------------------------------------------------------------
Filename:    As3.h
-----------------------------------------------------------------------------
*/
//Christopher Mollise
//ChrisJMollise@gmail.com

#ifndef AS3_H
#define AS3_H

#include "BaseApplication.h"
#include "EntityMgr.h"

//---------------------------------------------------------------------------

class As3 : public BaseApplication
{
	public:
    	As3(void);
    	virtual ~As3(void);
	protected:
    	virtual void createScene(void);
    	virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);
	private:
    	EntityMgr * entityMgr;
    	Ogre::Real surfaceHeight;
    	Ogre::SceneNode * cameraNode;
    	bool tabPressed, upHeadPressed, downHeadPressed, upVelPressed, downVelPressed;
    	void MakeGround();
    	void MakeSky();
    	void MakeEnts();
    	void UpdateCamera(const Ogre::FrameEvent& fe);
    	void UpdateDesiredSpeedHeading(const Ogre::FrameEvent& fe);
    	virtual bool keyPressed(const OIS::KeyEvent& ke, const OIS::MouseEvent &e);
    	virtual bool keyReleased(const OIS::KeyEvent& ke, const OIS::MouseEvent &e);

    	bool mLMouseDown, mRMouseDown;
};

//---------------------------------------------------------------------------

#endif

//---------------------------------------------------------------------------
