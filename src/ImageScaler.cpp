#include "ImageScaler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

void ImageScaler::load()
{
	std::cout << "Reading image ..." << std::endl;
	*toScale = loadImage("../Images/Zoom/zIMG_1.ppm");
	std::cout << "../Images/Zoom/zIMG_1.ppm" << std::endl;
	std::cout << "... Image Read" << std::endl;
}

void ImageScaler::enhance()
{
	reCalcPixels(*toScale, 2, toScale->w, toScale->h, 1500, 1500, *Scale2);
	reCalcPixels(*toScale, 4, toScale->w, toScale->h, 3000, 3000, *Scale4);
}

void ImageScaler::write()
{
	writeImage(*Scale2, "../Images/2XScale.ppm");
	writeImage(*Scale4, "../Images/4XScale.ppm");
}

void ImageScaler::reCalcPixels(Image img, int scale, int width, int height, int heightnew, int widthnew, Image &scaled)
{

	float rx = ((float)width / (float)widthnew);
	float ry = ((float)height / (float)heightnew);
	float xp, yp;
	float output, input;
	for (int i = 0; i < heightnew; i++)
	{
		for (int j = 0; j < widthnew; j++)
		{
			xp = floor(j * rx);
			yp = floor(i * ry);
			input = ((i * widthnew) + j);
			output = ((yp * width) + xp);
			scaled[input] = img[output];
		}
	}
}

