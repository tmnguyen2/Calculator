#pragma once
#include <cmath>

class IBaseCommand
{
public:
	virtual float Execute() = 0;
};

class AddCommand : public IBaseCommand
{
private:
	float first;
	float last;
	float result = 0;
public:
	AddCommand(float _first, float _last)
	{
		first = _first;
		last = _last;
	}
	float Execute()
	{
		return first + last;
	}
};

class SubtractCommand : public IBaseCommand
{
private:
	float first;
	float last;
public:
	SubtractCommand(float _first, float _last)
	{
		first = _first;
		last = _last;
	}
	float Execute()
	{
		return first - last;
	}
};

class MultiplyCommand : public IBaseCommand
{
private:
	float first;
	float last;
public:
	MultiplyCommand(float _first, float _last)
	{
		first = _first;
		last = _last;
	}
	float Execute()
	{
		return first * last;
	}
};

class DivideCommand : public IBaseCommand
{
private:
	float first;
	float last;
public:
	DivideCommand(float _first, float _last)
	{
		first = _first;
		last = _last;
	}
	float Execute()
	{
		return first / last;
	}
};

class ModCommand : public IBaseCommand
{
private:
	float first;
	float last;
public:
	ModCommand(float _first, float _last)
	{
		first = _first;
		last = _last;
	}
	float Execute()
	{
		return fmod(first, last);
	} 
};