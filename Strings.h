#pragma once
#include "TaskTemplates.h"
#include "Files.h"
#include <iostream>
#include <utility> 

using std::pair;

class Strings : public ITask
{
private:
	string filenameIn = "";
	string filenameOut = "";

	string getText();

	void writeText(string);
public:
	Strings();

	void start() override;

	static pair<string*, size_t> split(string text, char delimiter);
	
	static void onlyLatters(string& word);
};