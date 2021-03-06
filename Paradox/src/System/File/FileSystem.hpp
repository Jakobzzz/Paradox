#pragma once

// C++
#include <string>

// NFD
#include <nfd/nfd.h>

namespace paradox::utils
{
	// Open a file path and return if path was valid
	inline bool openFile(std::string& path, const std::string& filter)
	{
		nfdchar_t* outPath = nullptr;
		nfdresult_t result = NFD_OpenDialog(filter.c_str(), nullptr, &outPath);

		if (result == NFD_OKAY)
		{
			path = outPath;
			free(outPath);
			return true;
		}

		return false;
	}

	// Request a save location and return if operation was successful
	inline bool saveFile(std::string& path, const std::string& filter, const std::string& extension)
	{
		nfdchar_t* outPath = nullptr;
		nfdresult_t result = NFD_SaveDialog(filter.c_str(), nullptr, &outPath);

		if (result == NFD_OKAY)
		{
			path = outPath;

			// Add input extension as the file format if missing
			if (path.find(extension) == std::string::npos)
			{
				path.append(extension);
			}

			free(outPath);
			return true;
		}

		return false;
	}
}