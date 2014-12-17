#include <irrlicht.h>

#ifndef _MSC_VER_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystems:windows /ENTRY:mainCRTStartup")
#endif

using namespace irr;

int main()
{
	IrrlichtDevice *device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(640, 480));

	if (device == 0)
		return 1; // could not create selected driver.

	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();

	// Change camera position from the default value of (0, 0 ,0) to (300, 100, 500)
	//smgr->addCameraSceneNodeFPS(); // Default (0, 0, 0)
	smgr->addCameraSceneNodeFPS()->setPosition(core::vector3df(300, 100, 500)); 

	device->getCursorControl()->setVisible(false);

	int lastFPS = -1;

	while(device->run())
	{
		if (device->isWindowActive())
		{
			driver->beginScene(true, true, video::SColor(255,200,200,200));
			smgr->drawAll();
			driver->endScene();

			int fps = driver->getFPS();

			if (lastFPS != fps)
			{
				core::stringw str = L"Irrlicht Engine - Quake 3 Map example [";
				str += driver->getName();
				str += "] FPS:";
				str += fps;

				device->setWindowCaption(str.c_str());
				lastFPS = fps;
			}
		}
		else
			device->yield();
	}

	device->drop();
	return 0;
};