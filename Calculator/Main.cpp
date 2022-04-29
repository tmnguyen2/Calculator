#include "Main.h"
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)
	EVT_BUTTON(wxID_ANY, Main::OnButtonClicked)
wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(357, 670))
{
	SetBackgroundColour(wxColour(*wxBLACK));

	textBoxMini = new wxTextCtrl(this, 24, "", wxPoint(1, 1), wxSize(338, 22), wxTE_READONLY);
	textBoxMini->SetWindowStyle(wxTE_RIGHT);
	textBox = new wxTextCtrl(this, 23, "0", wxPoint(1, 22), wxSize(338, 98), wxTE_RIGHT);
	
	ButtonFactory factory = ButtonFactory(this);
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
	CalculatorProcessor* processor = &CalculatorProcessor::getInstance();
	wxButton* eventButton = dynamic_cast<wxButton*>(event.GetEventObject());
	wxString textBoxValue = textBox->GetValue();
	//numbers
	if (event.GetId() <= 11)
	{
		//0 in textbox
		if (textBoxValue == "0" || converted || textBox->GetValue() == "error")
		{
			//decimal
			if (event.GetId() == 10)
			{
				textBox->SetValue("0.");
			}
			//numbers
			else if (event.GetId() != 11)
			{
				textBox->SetValue(eventButton->GetLabel());
			}
		}
		//something in textbox
		else
		{
			//sign switch
			if (event.GetId() == 11)
			{
				if (textBox->GetValue().Contains("-"))
				{
					textBox->SetValue(textBoxValue.SubString(1, textBoxValue.Len() - 1));
				}
				else
				{
					textBox->SetValue("-" + textBoxValue);
				}
			}
			//function pressed
			else if (functionPressed)
			{
				//decimal
				if (event.GetId() == 10)
				{
					textBox->SetValue("0.");
				}
				//numbers
				else
				{
					textBox->SetValue(eventButton->GetLabel());
				}
			}
			else
			{
				//decimal
				if (event.GetId() == 10)
				{
					if (!textBox->GetValue().Contains("."))
					{
						textBox->AppendText(eventButton->GetLabel());
					}
				}
				//numbers
				else
				{
					textBox->AppendText(eventButton->GetLabel());
				}
			}
		}
		functionPressed = false;
		calculated = false;
		converted = false;
	}
	//clear
	else if (event.GetId() == 20)
	{
		processor->Reset();
		textBox->SetValue("0");
		textBoxMini->Clear();
		functionPressed = false;
		calculated = false;
		converted = false;
	}
	//delete
	else if (event.GetId() == 21)
	{
		if (calculated || textBox->GetValue() == "error")
		{
			processor->Reset();
			textBoxMini->Clear();
			textBox->SetValue("0");
		}
		else if (textBoxValue.length() > 1)
		{
			textBox->SetValue(textBoxValue.SubString(0, textBoxValue.Len() - 2));
		}
		else
		{
			textBox->SetValue("0");
		}
		functionPressed = false;
		calculated = false;
	}
	//equals
	else if (event.GetId() == 22)
	{
		if (textBoxMini->GetValue().Contains("("))
		{
			processor->Reset();
			textBoxMini->Clear();
			textBoxMini->SetValue(eventButton->GetLabel() + processor->GetResult());
		}
		if (textBox->GetValue() != "error" && !converted)
		{
			processor->Calculate(textBoxValue);
			textBox->SetValue(processor->GetResult());
			if (functionPressed || textBoxMini->GetValue().StartsWith("="))
			{
				textBoxMini->Clear();
				textBoxMini->SetValue(eventButton->GetLabel() + processor->GetResult());
			}
			else
			{
				textBoxMini->AppendText(textBoxValue + eventButton->GetLabel() + processor->GetResult());
			}
			functionPressed = true;
			calculated = true;
			converted = false;
		}
		else
		{
			processor->Reset();
			textBoxMini->Clear();
			textBox->SetValue("error");
			functionPressed = false;
			calculated = false;
			converted = false;
		}
		
	}
	//+, -, ×, /, %
	else if (event.GetId() <= 16)
	{
		if (!converted)
		{
			if (textBox->GetValue() != "error")
			if (calculated)
			{
				processor->Operator(textBoxValue, event.GetId());
				textBoxMini->Clear();
				textBoxMini->AppendText(textBoxValue + eventButton->GetLabel());
			}
			else if (!(textBoxMini->GetValue().Contains("+") || textBoxMini->GetValue().Contains("-") || textBoxMini->GetValue().Contains("/") || textBoxMini->GetValue().Contains("×") || textBoxMini->GetValue().Contains("%")))
			{
				processor->Operator(textBoxValue, event.GetId());
				textBoxMini->Clear();
				textBoxMini->AppendText(textBoxValue + eventButton->GetLabel());
			}
			functionPressed = true;
			calculated = false;
			converted = false;
		}
		else
		{
			processor->Reset();
			textBoxMini->Clear();
			textBox->SetValue("error");
			functionPressed = false;
			calculated = false;
			converted = false;
		}
	}
	// base conversion
	else
	{
		if (calculated || !(textBoxMini->GetValue().Contains("+") || textBoxMini->GetValue().Contains("-") || textBoxMini->GetValue().Contains("/") || textBoxMini->GetValue().Contains("×") || textBoxMini->GetValue().Contains("%")))
		{
			if (textBox->GetValue() != "error" && !textBox->GetValue().Contains("."))
			{
				processor->Convert(textBoxValue, textBoxMini->GetValue(), eventButton->GetId());
				if (processor->GetResult() != "")
				{
					textBoxMini->SetValue(eventButton->GetLabel() + "(" + textBox->GetValue() + ")");
					textBox->SetValue(processor->GetResult());
				}
				converted = true;
			}
			else
			{
				processor->Reset();
				textBoxMini->Clear();
				textBox->SetValue("error");
				functionPressed = false;
				calculated = false;
				converted = false;
			}
		}
	}
}