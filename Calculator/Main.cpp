#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)
	EVT_BUTTON(wxID_ANY, Main::OnButtonClicked)
wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(357, 670))
{

	textBox = new wxTextCtrl(this, 21, "0", wxPoint(0, 0), wxSize(340, 120), wxTE_RIGHT);

	binConvert = new wxButton(this, 17, "bin", wxPoint(0, 120), wxSize(85, 85));
	decConvert = new wxButton(this, 18, "dec", wxPoint(85, 120), wxSize(85, 85));
	hexConvert = new wxButton(this, 19, "hex", wxPoint(170, 120), wxSize(85, 85));
	mod = new wxButton(this, 16, "%", wxPoint(255, 120), wxSize(85, 85));

	add = new wxButton(this, 12, "+", wxPoint(0, 205), wxSize(85, 85));
	subtract = new wxButton(this, 13, "-", wxPoint(85, 205), wxSize(85, 85));
	multiply = new wxButton(this, 14, "×", wxPoint(170, 205), wxSize(85, 85));
	divide = new wxButton(this, 15, "÷", wxPoint(255, 205), wxSize(85, 85));

	num7 = new wxButton(this, 7, "7", wxPoint(0, 290), wxSize(85, 85));
	num8 = new wxButton(this, 8, "8", wxPoint(85, 290), wxSize(85, 85));
	num9 = new wxButton(this, 9, "9", wxPoint(170, 290), wxSize(85, 85));
	backspace = new wxButton(this, 21, "del", wxPoint(255, 290), wxSize(85, 85));

	num4 = new wxButton(this, 4, "4", wxPoint(0, 375), wxSize(85, 85));
	num5 = new wxButton(this, 5, "5", wxPoint(85, 375), wxSize(85, 85));
	num6 = new wxButton(this, 6, "6", wxPoint(170, 375), wxSize(85, 85));
	clear = new wxButton(this, 22, "C", wxPoint(255, 375), wxSize(85, 85));

	num1 = new wxButton(this, 1, "1", wxPoint(0, 460), wxSize(85, 85));
	num2 = new wxButton(this, 2, "2", wxPoint(85, 460), wxSize(85, 85));
	num3 = new wxButton(this, 3, "3", wxPoint(170, 460), wxSize(85, 85));
	equals = new wxButton(this, 20, "=", wxPoint(255, 460), wxSize(85, 170));

	signSwitch = new wxButton(this, 11, "±", wxPoint(0, 545), wxSize(85, 85));
	num0 = new wxButton(this, 0, "0", wxPoint(85, 545), wxSize(85, 85));
	decimal = new wxButton(this, 10, ".", wxPoint(170, 545), wxSize(85, 85));
}

Main::~Main()
{
	delete textBox;
	delete num1;
	delete num2;
	delete num3;
	delete num4;
	delete num5;
	delete num6;
	delete num7;
	delete num8;
	delete num9;
	delete num0;
	delete decimal;
	delete signSwitch;
	delete add;
	delete subtract;
	delete multiply;
	delete divide;
	delete mod;
	delete binConvert;
	delete decConvert;
	delete hexConvert;
	delete equals;
	delete clear;
	delete backspace;
}

void Main::OnButtonClicked(wxCommandEvent& event)
{
	wxButton* temp = dynamic_cast<wxButton*>(event.GetEventObject());
	if (textBox->GetValue() == "0")
	{
		textBox->SetValue(temp->GetLabel());
	}
	else
	{
		textBox->AppendText(temp->GetLabel());
	}
}