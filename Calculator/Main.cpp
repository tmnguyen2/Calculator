#include "Main.h"
#include "ButtonFactory.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)
	EVT_BUTTON(wxID_ANY, Main::OnButtonClicked)
wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(357, 670))
{
	SetBackgroundColour(wxColour(*wxBLACK));
	ButtonFactory factory = ButtonFactory(this);
	textBox = new wxTextCtrl(this, 23, "0", wxPoint(1, 1), wxSize(338, 118), wxTE_RIGHT);
	num0 = factory.CreateButton(0);
	num1 = factory.CreateButton(1);
	num2 = factory.CreateButton(2);
	num3 = factory.CreateButton(3);
	num4 = factory.CreateButton(4);
	num5 = factory.CreateButton(5);
	num6 = factory.CreateButton(6);
	num7 = factory.CreateButton(7);
	num8 = factory.CreateButton(8);
	num9 = factory.CreateButton(9);
	decimal = factory.CreateButton(10);
	signSwitch = factory.CreateButton(11);
	add = factory.CreateButton(12);
	subtract = factory.CreateButton(13);
	multiply = factory.CreateButton(14);
	divide = factory.CreateButton(15);
	mod = factory.CreateButton(16);
	binConvert = factory.CreateButton(17);
	decConvert = factory.CreateButton(18);
	hexConvert = factory.CreateButton(19);
	clear = factory.CreateButton(20);
	backspace = factory.CreateButton(21);
	equals = factory.CreateButton(22);
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
	delete backspace;
	delete clear;
	delete equals;
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