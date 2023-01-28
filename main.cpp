#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>

bool isLetter(int ascii_value)
{
	return ascii_value >= 97 && ascii_value <= 122;
}

char toLowerCase(int ascii_value)
{
	if (ascii_value >= 65 && ascii_value <= 90)
	{
		return ascii_value + 32;
	}

	return ascii_value;
}

std::string buildHistogramBar(int value)
{
	return std::string(value, '#');
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: enter the file name as an argument!\n";
		return 1;
	}

	std::ifstream FileReader(argv[1]);
	bool showAsHistogram = argc > 2 && std::string(argv[2]) == "-h";

	std::map<char, int> output;

	if (FileReader.good())
	{
		char c;
		while (FileReader.get(c))
		{
			c = toLowerCase(c);
			if (isLetter(c))
			{
				output[c] += 1;
			}
		}
	}

	FileReader.close();

	std::vector<std::pair<char, int>> pairs;
	for (auto &pair : output)
	{
		pairs.push_back(pair);
	}

	std::sort(pairs.begin(), pairs.end(), [](auto a, auto b)
			  { return a.second > b.second; });

	for (auto it = pairs.begin(); it != pairs.end(); it++)
	{
		if (showAsHistogram)
		{
			std::cout << it->first << ": " << buildHistogramBar(it->second) << "\n";
		}
		else
		{
			std::cout << it->first << ": " << it->second << "\n";
		}
	}

	return 0;
}
