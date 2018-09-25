#pragma once

#include <windows.h>
#include <iostream>

#define ERROR_COLOR		FOREGROUND_INTENSITY | FOREGROUND_RED
#define WARNING_COLOR	FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN
#define MESSAGE_COLOR	FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define GOOD_COLOR		FOREGROUND_INTENSITY | FOREGROUND_GREEN

enum class EMessageCategory
{
	Message,
	Good,
	Warning,
	Error
};

class Logger
{
public:

	static void ConsoleLog(const std::string message, const EMessageCategory category = EMessageCategory::Message)
	{
		switch (category)
		{
		case EMessageCategory::Message:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MESSAGE_COLOR);
			break;
		case EMessageCategory::Warning:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WARNING_COLOR);
			break;
		case EMessageCategory::Error:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ERROR_COLOR);
			break;
		case EMessageCategory::Good:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ERROR_COLOR);
			break;
		default:
			break;
		}


		printf("%s \n", message.c_str());
	}

};