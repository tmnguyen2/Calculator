#pragma once
#include "Main.h"
#include <wx/wx.h>

class ButtonFactory
{
private:
	Main* frame;
public:
	ButtonFactory(Main* _frame);
	~ButtonFactory();
	wxButton* CreateButton(int id);
};

