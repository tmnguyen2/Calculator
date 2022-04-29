#pragma once
#include <string>
#include <wx/wx.h>

class CalculatorProcessor
{
	enum class Function
	{
		Add = 12,
		Subtract,
		Multiply,
		Divide,
		Mod,
		Binary,
		Decimal,
		Hexadecimal
	};

	Function function;
public:
	static CalculatorProcessor& getInstance()
	{
		static CalculatorProcessor processor;
		return processor;
	}
private:
	CalculatorProcessor() {};
	float first;
	float last;
	float answer;
	wxString result;
	bool justCalculated = false;
public:
	CalculatorProcessor(CalculatorProcessor const&) = delete;
	void operator = (CalculatorProcessor const&) = delete;
	void Operator(wxString textBoxValue, int functionID);
	void Calculate(wxString textBoxValue);
	void Convert(wxString textBoxValue, wxString textBoxMiniValue, int functionID);
	wxString BinToDecConvert(wxString num);
	wxString DecToBinConvert(wxString num);
	wxString HexToDecConvert(wxString num);
	wxString DecToHexConvert(wxString num);
	void Reset();
	wxString GetResult();
};