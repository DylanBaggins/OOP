#pragma once
#include "Image.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <array>

class ImageWriter
{
private:

	std::ofstream ofs;

public:

	void writeImage(const Image &img, const char *filepath);

};

