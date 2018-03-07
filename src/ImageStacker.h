#pragma once
#include "Image.h"
#include "ImageLoader.h"
#include "ImageWriter.h"
#include "calcValues.h"
#include <array>
#include <cmath>
#include <algorithm>

class ImageStacker : public virtual ImageLoader, public calcValues
{
private:

	int w = 3264;
	int h = 2448;

	Image *image1 = new Image(w, h);
	Image *image2 = new Image(w, h);
	Image *image3 = new Image(w, h);
	Image *image4 = new Image(w, h);
	Image *image5 = new Image(w, h);
	Image *image6 = new Image(w, h);
	Image *image7 = new Image(w, h);
	Image *image8 = new Image(w, h);
	Image *image9 = new Image(w, h);
	Image *image10 = new Image(w, h);
	Image *image11 = new Image(w, h);
	Image *image12 = new Image(w, h);
	Image *image13 = new Image(w, h);
	Image *image14 = new Image(w, h);
	Image *image15 = new Image(w, h);
	Image *image16 = new Image(w, h);

	Image *imageArr[16] ={ image1,image2,image3,image4,image5,image6,image7,image8,image9,image10,image11,image12,image13,image14,image15,image16 };

	void pixelPlacement(Image &img, int i, float r, float g, float b);

public:
	
	virtual void load();
	void calculate();
	void write();

};

