#include "Output.h"
#include "../CMUgraphicsLib/image.h";

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN; //Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width + UI.widthError, UI.height + UI.heightError, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");
	CreateGrid();
	CreateDesignToolBar(); //Create the desgin toolbar
	CreateStatusBar();	   //Create Status bar
}

Input *Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input *pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window *Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateGrid() const
{
	pWind->SetBrush(color(223, 223, 223));
	pWind->SetPen(color(223, 223, 223), 2);
	int rows = UI.height / UI.GridSize + 1;
	int cols = UI.width / UI.GridSize + 1;
	for (int i = 0; i < max(rows, cols); i++)
	{
		if (i <= rows && i >= 0)
		{
			pWind->DrawRectangle(0, i * UI.GridSize - 1, UI.width, i * UI.GridSize + 1);
		}
		if (i <= cols && i >= 0)
		{
			pWind->DrawRectangle(i * UI.GridSize - 1, 0, i * UI.GridSize + 1, UI.height);
		}
	}
}
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar(); //Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN; //Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_NOT] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_OR3] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_BUFFER] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_WIRE] = "images\\Menu\\Menu_AND2.jpg";

	//TODO: Prepare image for each menu item and add it to the list
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolBarItemWidth, 0, UI.ToolBarItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	//UI.AppMode = SIMULATION; //Simulation Mode

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "Images\\components\\faded\\and.png";
	pWind->DrawImage(new image(GateImage, imagetype::PNG), r_GfxInfo.x1, r_GfxInfo.y1, UI.Gate_Width, UI.Gate_Height);
}
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "Images\\components\\faded\\and.png";
	pWind->DrawImage(new image(GateImage, imagetype::PNG), r_GfxInfo.x1, r_GfxInfo.y1, UI.Gate_Width, UI.Gate_Height);
}
void Output::DrawNot(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "Images\\components\\faded\\and.png";
	pWind->DrawImage(new image(GateImage, imagetype::PNG), r_GfxInfo.x1, r_GfxInfo.y1, UI.Gate_Width, UI.Gate_Height);
}
void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "Images\\components\\faded\\and.png";
	pWind->DrawImage(new image(GateImage, imagetype::PNG), r_GfxInfo.x1, r_GfxInfo.y1, UI.Gate_Width, UI.Gate_Height);
}
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "Images\\components\\faded\\and.png";
	pWind->DrawImage(new image(GateImage, imagetype::PNG), r_GfxInfo.x1, r_GfxInfo.y1, UI.Gate_Width, UI.Gate_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "Images\\components\\faded\\and.png";
	pWind->DrawImage(new image(GateImage, imagetype::PNG), r_GfxInfo.x1, r_GfxInfo.y1, UI.Gate_Width, UI.Gate_Height);
}
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "Images\\components\\faded\\and.png";
	pWind->DrawImage(new image(GateImage, imagetype::PNG), r_GfxInfo.x1, r_GfxInfo.y1, UI.Gate_Width, UI.Gate_Height);
}
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "Images\\components\\faded\\and.png";
	pWind->DrawImage(new image(GateImage, imagetype::PNG), r_GfxInfo.x1, r_GfxInfo.y1, UI.Gate_Width, UI.Gate_Height);
}
void Output::DrawOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "Images\\components\\faded\\and.png";
	pWind->DrawImage(new image(GateImage, imagetype::PNG), r_GfxInfo.x1, r_GfxInfo.y1, UI.Gate_Width, UI.Gate_Height);
}
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "Images\\components\\faded\\and.png";
	pWind->DrawImage(new image(GateImage, imagetype::PNG), r_GfxInfo.x1, r_GfxInfo.y1, UI.Gate_Width, UI.Gate_Height);
}
void Output::DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "Images\\components\\faded\\and.png";
	pWind->DrawImage(new image(GateImage, imagetype::PNG), r_GfxInfo.x1, r_GfxInfo.y1, UI.Gate_Width, UI.Gate_Height);
}
void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "Images\\components\\faded\\and.png";
	pWind->DrawImage(new image(GateImage, imagetype::PNG), r_GfxInfo.x1, r_GfxInfo.y1, UI.Gate_Width, UI.Gate_Height);
}
void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "Images\\components\\faded\\and.png";
	pWind->DrawImage(new image(GateImage, imagetype::PNG), r_GfxInfo.x1, r_GfxInfo.y1, UI.Gate_Width, UI.Gate_Height);
}
void Output::DrawWIRE(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "Images\\components\\faded\\and.png";
	pWind->DrawImage(new image(GateImage, imagetype::PNG), r_GfxInfo.x1, r_GfxInfo.y1, UI.Gate_Width, UI.Gate_Height);
}

//TODO: Add similar functions to draw all components

void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection
}

Output::~Output()
{
	delete pWind;
}

void Output::StartBuffer()
{
	pWind->SetBuffering(true);
}
void Output::EndBuffer()
{
	pWind->UpdateBuffer();
	pWind->SetBuffering(false);
}
void Output::DrawErrorRectangle(GraphicsInfo g)
{
	pWind->SetBrush(RED);
	pWind->DrawRectangle(g.x1, g.y1, g.x2, g.y2);
}