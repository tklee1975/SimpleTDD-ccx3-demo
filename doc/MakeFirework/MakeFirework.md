How to make firework effect in a game with TDD 
=====================================================


Overview 
-------------
- Concept 
- Prepare the firework particle
- Create a custom view in CocosStudio
- Create a custom class FireworkView with TDD methodology
	- Import the cocostudio data and Test 
	- Bind the particle objects and Test
	- Add method to play specific firework emitter
	- Add logic to play all firework emitter automatically
- Further improvement 


Concept 
---------------
The firework visual effect is based on playing several firework particles on different
location of the screen.
Therefore the components should serves the following functions:
- Play a specific firework emitter
- Logic to tell the firework emitter play the "firework"

Project
-----------------
github: 
//step 1 & 2: tag=


Setup #1: Prepare the firework particle
-------------------------------
- Go to http://particle2dx.com/ an online free particle maker
- Go to the template and select "fw1" in the "Firework" section
- Adjust a bit the particle 
	My Setting is:
	- GravityY set to -400  
	- Using Additive blend instead
- Export the particle and test it in the CocosStudio

Expect output: the particle files (particle.list and particle.png) are ready to use.

Setup #2: Create a custom view in CocosStudio
-------------------------------
The second step is making a view contain several "firework" particle that we need 
in the next step. You can use the firework particle made in step1 or from somewhere else;

- Create a custom view (Layer) called "FireworkView" in CocosStudio under '/gui/' folder	
	- Size: 320 x 600	// Size can be vared if you like
- Add the first particle
	- Add a particle to your view
	- Name it as "firework1" 
- Add other 4 particles
	- Copy "firework1" to other 4 particles
	- Rename them as "firework2", "firework3", .. "firework5"
	- Place them evenly in the screen
	- note: you can more if you like 
- Publish the file
- Make sure the particles and gui are imported to XCode

Expect output: 
- The csb file of firework particles is ready to use.
- The particles are ready to use.

Step 1: Create the FireworkView 
-------------------------------
This step is simply create the FireworkView with the FireworkView.csb loaded

- Create the FireworkView class inherit from ui::Layout (.h & c++)
- Create setupCsb method with following code:
		void FireworkView::setupCsb(const std::string &csbName)
		{
			Node *rootNode = CSLoader::createNode(csbName);
			addChild(rootNode);

			setContentSize(rootNode->getContentSize());		// update the layout size based on the CSB size
		}
- Call the setupCsb in init like this:
	bool FireworkView::init()
	{
		if(Layout::init() == false) {
			return false;
		}

		std::string csb = "gui/FireworkView.csb";
		setupCsb(csb);


		return true;
	}
- Assume the FireworkView is good to test now!

Step 2: Create the Unit Test FireworkViewTest 
-------------------------------
This step is to create an unit test to the FireworkView

- Go to to project folder 
- run ./script/createTest.sh FireworkView
	- when success, an unit test called 'FireworkViewTest' in '/Classes/UnitTest' folder
- Add "FireworkViewTest.cpp" and "FireworkViewTest.h" to the project
- Change testSample in FireworkViewTest to testCreate and add the following source
	void FireworkViewTest::testCreate()
	{
		FireworkView *view = FireworkView::create();
		view->setAnchorPoint(Vec2(0.5, 0.5f));
		view->setPosition(Vec2(250, 160));

		addChild(view);

	}
- Modiy "MyTDDCases.h" and "FireworkViewTest" to it like this
	#include "FireworkViewTest.h"

	TDD_CASES
	{
		TEST(FireworkViewTest),
		... 

- Run the Test (Main Screen -> Click "simpleTDD" -> Click "FireworkViewTest" -> Click "testCreate")

Expected: You will the five particle fire at the same time.
What's next? 
- We are not expect the particles fire at the same time. 
- And we need to bind the Particle in code and control them.
