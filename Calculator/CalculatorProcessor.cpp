#include "CalculatorProcessor.h"

void CalculatorProcessor::Operator(wxString textBoxValue, int functionID)
{
	if (first == 0)
	{
		first = wxAtof(textBoxValue);
	}
	function = (CalculatorProcessor::Function)functionID;
	justCalculated = false;
}

void CalculatorProcessor::Calculate(wxString textBoxValue)
{
	if (function == (CalculatorProcessor::Function)0)
	{
		result = textBoxValue;
	}
	else if (!justCalculated)
	{
		last = wxAtof(textBoxValue);
	}
	switch (function)
	{
	case CalculatorProcessor::Function::Add:
		answer = first + last;
		result = wxString::Format(wxT("%g"), answer);
		break;
	case CalculatorProcessor::Function::Subtract:
		answer = first - last;
		result = wxString::Format(wxT("%g"), answer);
		break;
	case CalculatorProcessor::Function::Multiply:
		answer = first * last;
		result = wxString::Format(wxT("%g"), answer);
		break;
	case CalculatorProcessor::Function::Divide:
		answer = first / last;
		result = wxString::Format(wxT("%g"), answer);
		break;
	case CalculatorProcessor::Function::Mod:
		answer = fmod(first, last);
		result = wxString::Format(wxT("%g"), answer);
		break;
	}
	first = answer;
	justCalculated = true;
}

void CalculatorProcessor::Convert(wxString textBoxValue, wxString textBoxMiniValue, int functionID)
{
	function = (CalculatorProcessor::Function)functionID;
	int i = 0;
	result = "";
	switch (function)
	{
	case CalculatorProcessor::Function::Binary:if (textBoxMiniValue.Contains("hex"))
		{
			result = HexToDecConvert(textBoxValue);
			result = DecToBinConvert(result);
		}
		else
		{
			result = DecToBinConvert(textBoxValue);
		}
		break;
	case CalculatorProcessor::Function::Decimal:
		if (textBoxMiniValue.Contains("bin"))
		{
			result = BinToDecConvert(textBoxValue);
		}
		else if (textBoxMiniValue.Contains("hex"))
		{
			result = HexToDecConvert(textBoxValue);
		}
		break;
	case CalculatorProcessor::Function::Hexadecimal:
		if (textBoxMiniValue.Contains("bin"))
		{
			result = BinToDecConvert(textBoxValue);
			result = DecToHexConvert(result);
		}
		else
		{
			result = DecToHexConvert(textBoxValue);
		}
		break;
	}
}

wxString CalculatorProcessor::BinToDecConvert(wxString num)
{
	wxString tempResult;
	int bin = wxAtoi(num);
	int dec = 0;
	int base = 1;

	while (bin)
	{
		int last_digit = bin % 10;
		bin = bin / 10;

		dec += last_digit * base;

		base = base * 2;
	}

	tempResult << dec;
	return tempResult;
}

wxString CalculatorProcessor::DecToBinConvert(wxString num)
{
	wxString tempResult;
	int dec = wxAtoi(num);
	int bin[32];
	int i = 0;

	while (dec > 0)
	{
		bin[i] = dec % 2;
		dec = dec / 2;
		i++;
	}

	for (int j = i - 1; j >= 0; j--)
	{
		tempResult << bin[j];
	}

	return tempResult;
}

wxString CalculatorProcessor::HexToDecConvert(wxString num)
{
	int len = num.size();
	int base = 1;
	int dec = 0;
	wxString tempResult;

	for (int i = len - 1; i >= 0; i--)
	{
		if (num[i] >= '0' && num[i] <= '9')
		{
			dec += (int(num[i]) - 48) * base;
			base = base * 16;
		}
		else if (num[i] >= 'A' && num[i] <= 'F')
		{
			dec += (int(num[i]) - 55) * base;
			base = base * 16;
		}
	}

	tempResult << dec;
	return tempResult;
}

wxString CalculatorProcessor::DecToHexConvert(wxString num)
{
	wxString tempResult;
	int dec = wxAtoi(num);
	char hex[100];
	int i = 0;

	while (dec != 0)
	{
		int temp = 0;
		temp = dec % 16;

		if (temp < 10) {
			hex[i] = temp + 48;
			i++;
		}
		else {
			hex[i] = temp + 55;
			i++;
		}

		dec = dec / 16;
	}

	for (int j = i - 1; j >= 0; j--)
	{
		tempResult << hex[j];
	}
	return tempResult;
}

void CalculatorProcessor::Reset()
{
	first = 0;
	last = 0;
	result = "";
	function = (CalculatorProcessor::Function)0;
	justCalculated = false;
}


wxString CalculatorProcessor::GetResult()
{
	return result;
}
