#ifndef UI_INFO_H
#define UI_INFO_H

#include "../CMUgraphicsLib/CMUgraphics.h"
#include "../Defs.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

		struct UI_Info //User Interface Info.
{
	MODE AppMode; //Application Mode (design or simulation)

	static const int  GridSize = 16, widthError = 14, heightError = 15, width = 80 * GridSize, height = 45 * GridSize, //Window width and height
		wx = 0, wy = 0,												 //Window starting coordinates
		StatusBarHeight = 48,										 //Status Bar Height
		ToolBarHeight = 32,											 //Tool Bar Height (distance from top of window to bottom line of toolbar)
		ToolBarItemWidth = 32,											 //Width of each item in toolbar menu
		GateBarHeight = 32,
		GateBarItemWidth = 48;

	color DrawColor;	 //Drawing color
	color SelectColor; //Highlighting color
	color ConnColor;	 //Connector color
	color MsgColor;		 //Messages color
	color BkGrndColor; //Back ground color
	color background;
	color onBackround;
	color surface;
	color onSurface;
	color error;
	color high;
	color low;
	color primary;

	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50
	static const int Gate_Width = 96, //AND2 Gate Image default width
			Gate_Height = 64,							//AND2 Gate Image default height
			LED_HEIGHT = 64,
			SWITCH_HEIGHT = 64,
			LED_WIDTH = 96,
			SWITCH_WIDTH = 96;
} UI; //create a single global object UI

#endif