#pragma once
#include "Image.h"
#include "ImageStacker.h"

class ImageScaler : public virtual ImageLoader, public ImageWriter, public virtual ImageStacker
{
private:

	int wH = 750;

	void reCalcPixels(Image img, int scale, int width, int height, int heightnew, int widthnew, Image &scaled);

	Image *toScale = new Image(wH, wH);
	Image *Scale2 = new Image((wH * 2), (wH * 2));
	Image *Scale4 = new Image((wH * 4), (wH * 4));

public:

	virtual void load();
	void enhance();
	virtual void write();
};

