#pragma once
#include "Image.h"
#include <iostream>
#include <fstream>
#include <sstream>

class ImageLoader
{
private:

	std::ifstream ifs;
	Image src;

protected:

	//Load image from the path passed in
	Image loadImage(const char *filepath);
};

