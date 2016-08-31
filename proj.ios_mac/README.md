SimpleTDD Demo: An example of using SimpleTDD
==========================================================

This is a demo application using SimpleTDD as the test framework;

## Objective
* Demostrate the usage of SimpleTDD
* Demostrate different test scene built based on SimpleTDD

## Requirement
* simpleTDD (
* cocos2d-x 3.10 or above
* python 2.7

## Installation 
 
This project have excluded (gitignore) the 'cocos2d' folder; 
So, please copy your cococ2d engine folder to SimpleTDDDemo/cocos2d folder to make it running

Command Example:
  cp -R /drive/cocos2d-x-3.10 /project/SimpleTDDDemo/cocos2d


## Folder Structure
* Classes			: Source code of the project
* Classes/SimpleTDD : SimpleTDD Library
* Classes/UnitTest	: Source Location of different unit tests
	* MyTDDCases.h	: The definition of different unit tests
* Resources			: Resource folder (most of the resource is export from cocosstudio)
* cocosstudio		: Cocost Studio Project folder


## Demo insides 
* CocosGUITest		: Showing an GUI made by CocosStudio 3.10    
* SpriteCreateTest	: Showing different ways to create Sprites	// todo
* SpriteOpTest		: Showing different ways to create Sprites	// todo

