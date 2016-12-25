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


Step 1: Prepare the firework particle
-------------------------------
- Go to http://particle2dx.com/ an online free particle maker
- Go to the template and select "fw1" in the "Firework" section
- Adjust a bit the particle 
	My Setting is:
	- GravityY set to -400  
	- Using Additive blend instead
- Export the particle and test it in the CocosStudio

Expect output: the particle files (particle.list and particle.png) are ready to use.

Step 2: Create a custom view in CocosStudio
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

Expect output: The csb file of firework particles is ready to use. 

Step 3: Create the FireworkView 
-------------------------------
This step is simply create the FireworkView with the FireworkView.csb loaded

- Create the FireworkView class inherit from ui::Layout (.h & c++)
- 
- 




	 
