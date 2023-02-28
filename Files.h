#pragma once
#include "TaskTemplates.h"
#include "Academic.h"
#include <string>
#include <utility>
#include <fstream>

using std::string;
using std::ofstream;
using std::ifstream;

class Files
{
public:
	static string readTxtFile(string filename);
	static void writeTxtFile(string filename, string text);

	static std::pair<Academic*, size_t> readBinaryAcademicFile(string filename);
	static void writeBinaryAcademicFile(string filename, Academic academic);
};
