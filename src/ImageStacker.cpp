#include "ImageStacker.h"

void ImageStacker::load()
{
	std::cout << "Reading images ..." << std::endl;

		for (int i = 1; i < 13; i++)
		{
			std::string path = "../Images/ImageStacker_set1/IMG_" + std::to_string(i) + ".ppm";
			const char* thing = path.c_str();
			std::cout << thing << std::endl;
			*imageArr[i] = loadImage(thing);
		}
	
	std::cout << "... Images Read" << std::endl;
}

void ImageStacker::calculate()
{
	std::cout << "Processing Images ..." << std::endl;
	const int size = 13;
	float redMean, greenMean, blueMean;
	float redMedian, greenMedian, blueMedian; 
	float redSigma, greenSigma, blueSigma;
	float redPix[size] = {};
	float greenPix[size] = {};
	float bluePix[size] = {};
	for (int i = 0; i < (imageArr[0]->w * imageArr[0]->h); i++)
	{
		redMean = greenMean = blueMean = redMedian = greenMedian = blueMedian = redSigma = greenSigma = blueSigma = 0;
		for (int j = 0; j < size; j++)
		{
			redPix[j] = (imageArr[j]->pixels[i].r / 255.f);
			greenPix[j] = (imageArr[j]->pixels[i].g / 255.f);
			bluePix[j] = (imageArr[j]->pixels[i].b / 255.f);
		}

		//Sort pixel arrays before finding mean, median, sigma
		std::sort(std::begin(redPix),std::end(redPix));
		std::sort(std::begin(greenPix), std::end(greenPix));
		std::sort(std::begin(bluePix), std::end(bluePix));

		calcMean(size, redPix, redMean);
		calcMean(size, greenPix, greenMean);
		calcMean(size, bluePix, blueMean);

		calcMedian(size, redPix, redMedian);
		calcMedian(size, greenPix, greenMedian);
		calcMedian(size, bluePix, blueMedian);

		calcSigma(redPix, redMean, redSigma);
		calcSigma(greenPix, greenMean, greenSigma);
		calcSigma(bluePix, blueMean, blueSigma);

		pixelPlacement(*image14, i, redMean, greenMean, blueMean);
		pixelPlacement(*image15, i, redMedian, greenMedian, blueMedian);
		pixelPlacement(*image16, i, redSigma, greenSigma, blueSigma);
	}
	std::cout << "... Images Processed" << std::endl;
}

void ImageStacker::write()
{
	ImageWriter imageWrite;
	imageWrite.writeImage(*image14, "../Images/MeanPPM.ppm");
	imageWrite.writeImage(*image15, "../Images/MedianPPM.ppm");
	imageWrite.writeImage(*image16, "../Images/SigmaMeanPPM.ppm");
}

void ImageStacker::pixelPlacement(Image &img, int i, float r, float g, float b)
{
	img.pixels[i].r = r * 255;
	img.pixels[i].g = g * 255;
	img.pixels[i].b = b * 255;
}
