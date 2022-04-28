#include "ButtonFactory.h"



ButtonFactory::ButtonFactory(Main* _frame)
{
	frame = _frame;
}

ButtonFactory::~ButtonFactory()
{
}

wxButton* ButtonFactory::CreateButton(int id)
{
	wxButton* temp = nullptr;
	switch (id)
	{
	case 0:
		temp = new wxButton(frame, id, "0", wxPoint(86, 546), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 1:
		temp = new wxButton(frame, id, "1", wxPoint(1, 461), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 2:
		temp = new wxButton(frame, id, "2", wxPoint(86, 461), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 3:
		temp = new wxButton(frame, id, "3", wxPoint(171, 461), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 4:
		temp = new  wxButton(frame, id, "4", wxPoint(1, 376), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 5:
		temp = new wxButton(frame, id, "5", wxPoint(86, 376), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 6:
		temp = new wxButton(frame, id, "6", wxPoint(171, 376), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 7:
		temp = new wxButton(frame, id, "7", wxPoint(1, 291), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 8:
		temp = new wxButton(frame, id, "8", wxPoint(86, 291), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 9:
		temp = new wxButton(frame, id, "9", wxPoint(171, 291), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 10:
		temp = new wxButton(frame, id, ".", wxPoint(171, 546), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 11:
		temp = new wxButton(frame, id, "±", wxPoint(1, 546), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 12:
		temp = new wxButton(frame, id, "+", wxPoint(1, 206), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 13:
		temp = new wxButton(frame, id, "-", wxPoint(86, 206), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 14:
		temp = new wxButton(frame, id, "×", wxPoint(171, 206), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 15:
		temp = new wxButton(frame, id, "÷", wxPoint(256, 206), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 16:
		temp = new wxButton(frame, id, "%", wxPoint(256, 121), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 17:
		temp = new wxButton(frame, id, "bin", wxPoint(1, 121), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 18:
		temp = new wxButton(frame, id, "dec", wxPoint(86, 121), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 19:
		temp = new wxButton(frame, id, "hex", wxPoint(171, 121), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 20:
		temp = new wxButton(frame, id, "C", wxPoint(256, 376), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 21:
		temp = new wxButton(frame, id, "del", wxPoint(256, 291), wxSize(83, 83), wxBORDER_NONE);
		break;
	case 22:
		temp = new wxButton(frame, id, "=", wxPoint(256, 461), wxSize(83, 168), wxBORDER_NONE);
		break;
	}
	if (id <= 11)
	{
		temp->SetBackgroundColour(wxColour(*wxWHITE));
	}
	else if (id <= 19)
	{
		temp->SetBackgroundColour(wxColour(216, 216, 216));
	}
	else
	{
		temp->SetBackgroundColour(wxColour(173, 216, 230));
	}

	return temp;
}
