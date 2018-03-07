#include "ImageLoader.h"

Image ImageLoader::loadImage(const char *filepath)
{
	ifs.open(filepath, std::ios::binary);
	try
	{
		if (ifs.fail())// checks to see if the data is okay
		{
			throw("Can't open the input file - is it named correctly/is it in the right directory?");
		}
		std::string header;

		int w, h, b;
		ifs >> header;
		if (strcmp(header.c_str(), "P6") != 0)
		{
			throw("Can't read the input file - is it in binary format (Has P6 in the header)?");
		}
		ifs >> w >> h >> b;
		src.w = w;
		src.h = h;

		src.pixels = new Image::Rgb[w * h];// this is throw an exception if bad_alloc 
		ifs.ignore(256, '\n');// skip empty lines in necessary until we get to the binary data 
		unsigned char pix[3];// read each pixel one by one and convert bytes to floats 
		for (int i = 0; i < w * h; ++i)
		{
			ifs.read(reinterpret_cast<char *>(pix), 3);
			src.pixels[i].r = pix[0] / 255.f;
			src.pixels[i].g = pix[1] / 255.f;
			src.pixels[i].b = pix[2] / 255.f;
		}

		ifs.close();
	}
	catch (const char *err) {
		fprintf(stderr, "%s\n", err);
		ifs.close();
	}

	return src;
}
