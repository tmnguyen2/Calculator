#pragma once
#include <wx/wx.h>

class ButtonFactory
{
public:
	ButtonFactory();
	~ButtonFactory();
private:
	wxButton CreateAddButton();
};

