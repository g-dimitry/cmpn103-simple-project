#pragma once
#include "../Defs.h"
#include "./Input.h"
#include "../Utils/Astar/Astar.h"

class Output //The application manager should have a pointer to this class
{
private:
	window *pWind; //Pointer to the Graphics Window
public:
	Output();										// Performs the Window Initialization
	Input *CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;

	void CreateDesignToolBar() const;			//Tool bar of the design mode
	void CreateSimulationToolBar() const; //Tool bar of the simulation mode
	void CreateStatusBar() const;					//Create Status bar
	// void CreateGrid() const;

	void ClearStatusBar() const;	 //Clears the status bar
	void ClearDrawingArea() const; //Clears the drawing area

	window *CreateWind(int wd, int h, int x, int y) const; //Creates user interface window

	// Draws 2-input AND gate
	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNot(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected = false, bool on = false) const;
	void DrawLED(GraphicsInfo r_GfxInfo, bool selected = false, bool on = false) const;
	void DrawWIRE(GraphicsInfo r_GfxInfo, bool selected = false) const;

	///TODO: Make similar functions for drawing all other gates, switch, and LED, .. etc

	// Draws Connection
	void DrawConnection(GraphicsInfo r_GfxInfo, vector<AStar::Pair> pointsVector, bool selected = false, bool on = false) const;

	void PrintMsg(string msg) const; //Print a message on Status bar
	void DrawErrorRectangle(GraphicsInfo g);

	void StartBuffer();
	void EndBuffer();
	void Output::CreateToolBar() const;

	~Output();
};
