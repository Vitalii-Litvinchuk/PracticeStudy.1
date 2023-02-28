#include "Files.h"

string Files::readTxtFile(string filename)
{
	ifstream read(filename);

	string line = "",
		text = "";

	while (read.good())
	{
		getline(read, line);

		if (read.eof())
			break;

		text += line;
	}

	read.close();

	return text;
}

void Files::writeTxtFile(string filename, string text)
{
	ofstream write(filename, std::ios::app);

	write << text << std::endl;

	write.close();
}

std::pair<Academic*, size_t> Files::readBinaryAcademicFile(string filename)
{
	Academic* academic = new Academic();
	size_t size = 0;

	ifstream read(filename, std::ios::binary);
	while (read.good())
	{
		read.read((char*)academic, sizeof(Academic));

		if (read.eof())
			break;

		++size;
	}
	read.close();

	Academic* academics = new Academic[size];

	read.open(filename, std::ios::binary);
	for (size_t i = 0; i < size && read.good(); i++)
	{
		read.read((char*)academic, sizeof(Academic));

		if (read.eof())
			break;

		academics[i] = *academic;
	}
	read.close();

	return std::make_pair(academics, size);
}

void Files::writeBinaryAcademicFile(string filename, Academic academic)
{
	ofstream write(filename, std::ios::binary | std::ios::app);

	write.write((char*)&academic, sizeof(Academic));

	write.close();
}
