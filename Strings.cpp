#include "Strings.h"

string Strings::getText()
{
	return Files::readTxtFile(this->filenameIn);
}

void Strings::writeText(string text)
{
	Files::writeTxtFile(this->filenameOut, text);
}

Strings::Strings()
{
	filenameIn = "Text.txt";
	filenameOut = "SimilarSent.txt";
}

void Strings::start()
{
	string text = getText();
	pair<string*, size_t> pair1 = split(text, '.');

	if (pair1.first == nullptr)
		return;

	pair<pair<string*, size_t>*, size_t> pair2(new pair<string*, size_t>[pair1.second], pair1.second);
	bool isFound = false;

	for (size_t i = 0; i < pair1.second; i++)
	{
		pair2.first[i] = split(pair1.first[i], ' ');

		for (size_t b = 0; b < pair2.first[i].second; b++)
			onlyLatters(pair2.first[i].first[b]);
	}

	for (size_t i = 0; i < pair2.second; i++)
		for (size_t b = i + 1, counter = 0; b < pair2.second; b++, counter = 0)
			for (size_t c = 0; c < pair2.first[i].second; c++)
				for (size_t d = 0; d < pair2.first[b].second; d++)
					if (pair2.first[i].first[c] == pair2.first[b].first[d])
					{
						++counter;

						if (counter == 4)
						{
							std::cout << pair1.first[i] << " <----> " << pair1.first[b] << std::endl;
							writeText(pair1.first[i] + " <----> " + pair1.first[b]);
							
							if (!isFound)
								isFound = true;
						}

						break;
					}

	if (!isFound)
		writeText(pair1.first[0]);

	for (size_t i = 0; i < pair2.second; i++)
		delete[] pair2.first[i].first;
	
	delete[] pair2.first, pair1.first;
}

pair<string*, size_t> Strings::split(string text, char delimiter)
{
	if (text.length() == 0)
		return std::make_pair(nullptr, 0);
	
	size_t pos = 0,
		size = 1;

	for (size_t i = 0; i < text.length() - 1; i++)
		if (text[i] == delimiter && text[i + 1] != delimiter)
			++size;

	string* arr = new string[size]{ };

	for (size_t i = 0; i < size;)
	{
		pos = text.find(delimiter);

		if (text[pos + 1] != delimiter && pos != 0)
			arr[i++] = text.substr(0, pos);

		text.erase(0, pos + 1);
	}

	return std::make_pair(arr, size);
}

void Strings::onlyLatters(string& word)
{
	for (size_t i = 0; i < word.length(); i++)
		if (!(word[i] >= 'a' && word[i] <= 'z'
			|| word[i] >= 'A' && word[i] <= 'Z'))
			word.erase(i, 1);
}
