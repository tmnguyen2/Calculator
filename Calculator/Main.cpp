#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)

wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(357, 585))
{

	textBox = new wxTextCtrl(this, 0, wxEmptyString, wxPoint(0, 0), wxSize(340, 120), wxTE_RIGHT);

	// order of grid
	clear = new wxButton(this, 1, "C", wxPoint(0, 120), wxSize(85, 85));
	backspace = new wxButton(this, 2, "del", wxPoint(85, 120), wxSize(85, 85));
	mod = new wxButton(this, 3, "%", wxPoint(170, 120), wxSize(85, 85));
	divide = new wxButton(this, 4, "÷", wxPoint(255, 120), wxSize(85, 85));

	num7 = new wxButton(this, 5, "7", wxPoint(0, 205), wxSize(85, 85));
	num8 = new wxButton(this, 6, "8", wxPoint(85, 205), wxSize(85, 85));
	num9 = new wxButton(this, 7, "9", wxPoint(170, 205), wxSize(85, 85));
	multiply = new wxButton(this, 8, "×", wxPoint(255, 205), wxSize(85, 85));

	num4 = new wxButton(this, 9, "4", wxPoint(0, 290), wxSize(85, 85));
	num5 = new wxButton(this, 10, "5", wxPoint(85, 290), wxSize(85, 85));
	num6 = new wxButton(this, 11, "6", wxPoint(170, 290), wxSize(85, 85));
	subtract = new wxButton(this, 12, "-", wxPoint(255, 290), wxSize(85, 85));

	num1 = new wxButton(this, 13, "1", wxPoint(0, 375), wxSize(85, 85));
	num2 = new wxButton(this, 14, "2", wxPoint(85, 375), wxSize(85, 85));
	num3 = new wxButton(this, 15, "3", wxPoint(170, 375), wxSize(85, 85));
	add = new wxButton(this, 16, "+", wxPoint(255, 375), wxSize(85, 85));

	signSwitch = new wxButton(this, 17, "±", wxPoint(0, 460), wxSize(85, 85));
	num0 = new wxButton(this, 18, "0", wxPoint(85, 460), wxSize(85, 85));
	decimal = new wxButton(this, 19, ".", wxPoint(170, 460), wxSize(85, 85));
	equals = new wxButton(this, 20, "=", wxPoint(255, 460), wxSize(85, 85));
}

Main::~Main()
{
	
}

void Main::OnButtonClicked(wxCommandEvent& event)
{

}