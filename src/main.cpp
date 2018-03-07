//Libraries
#include <iostream>

//Header files
#include "Image.h"
#include "ImageStacker.h"
#include "ImageScaler.h"

//Classes
ImageStacker stack;
ImageScaler scale;
ImageStacker* polyStack = &scale;

//Globals
const Image::Rgb Image::kBlack = Image::Rgb(0);
const Image::Rgb Image::kWhite = Image::Rgb(1);
const Image::Rgb Image::kRed = Image::Rgb(1, 0, 0);
const Image::Rgb Image::kGreen = Image::Rgb(0, 1, 0);
const Image::Rgb Image::kBlue = Image::Rgb(0, 0, 1);

int main()
{
	//Nice presentation
	std::cout << "************************************" << std::endl;
	std::cout << "----Image Stacker / Image Scaler----" << std::endl;
	std::cout << "************************************" << std::endl;

	//Image stacking first
	std::cout << "" << std::endl; // Just spacing
	std::cout << "************************************" << std::endl;
	std::cout << "-----------Image Stacking-----------" << std::endl;
	std::cout << "************************************" << std::endl;

	stack.load(); //stacks the images
	stack.calculate(); //Creates (Mean, Median, Sigma) Images
	stack.write(); //Saves Images as PPM files

	//Image Scaling next
	std::cout << "************************************" << std::endl;
	std::cout << "-----------Image Scaling------------" << std::endl;
	std::cout << "************************************" << std::endl;

	polyStack->load(); //stacks the images
	scale.enhance(); //Creates (Mean, Median, Sigma) Images
	scale.write(); //Saves Images as PPM files

	//Process Finished
	std::cout << "************************************" << std::endl;
	std::cout << "----------Process Complete----------" << std::endl;
	std::cout << "--------Press Return To Exit--------" << std::endl;
	std::cout << "************************************" << std::endl;
					
	//Wait for user to exit CMD
	system("PAUSE");

	return 0;
};