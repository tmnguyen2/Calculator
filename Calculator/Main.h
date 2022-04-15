#pragma once
#include <wx/wx.h>

class Main : public wxFrame
{
public:
	Main();
	~Main();
public:
	wxTextCtrl* textBox = nullptr;
	wxButton* num1 = nullptr;
	wxButton* num2 = nullptr;
	wxButton* num3 = nullptr;
	wxButton* num4 = nullptr;
	wxButton* num5 = nullptr;
	wxButton* num6 = nullptr;
	wxButton* num7 = nullptr;
	wxButton* num8 = nullptr;
	wxButton* num9 = nullptr;
	wxButton* num0 = nullptr;
	wxButton* decimal = nullptr;
	wxButton* signSwitch = nullptr;
	wxButton* add = nullptr;
	wxButton* subtract = nullptr;
	wxButton* multiply = nullptr;
	wxButton* divide = nullptr;
	wxButton* mod = nullptr;
	wxButton* equals = nullptr;
	wxButton* clear = nullptr;
	wxButton* backspace = nullptr;
private:
	void OnButtonClicked(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};

