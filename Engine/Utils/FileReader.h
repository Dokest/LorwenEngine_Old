#pragma once

#include <fstream>
#include <sstream>
#include <string>

namespace Lorwen {

	class FileReader
	{
	public:
		static std::string ReadFile(const char* filePath)
		{
			std::ifstream inputFile(filePath);
			std::string resultString;

			for (std::string line; getline(inputFile, line); )
				resultString += line + "\n";

			return resultString;
		}

		static std::ifstream GetFileStream(const char* filePath)
		{
			return std::ifstream(filePath);
		}


	};

}
