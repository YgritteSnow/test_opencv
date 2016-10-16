#pragma once

#include <opencv2/highgui/highgui.hpp>

bool do_canny(IplImage* in, IplImage** out, double loThresh, double hiThresh, double aperture)
{
	//if (in->nChannels != -1)
	//	return false;

	if (*out == NULL)
	{
		*out = cvCreateImage(in->nSize, in->depth, in->nChannels);
	}

	cvCanny(in, *out, loThresh, hiThresh, aperture);
	return true;
}

class CImageProcess
{
private:
	const char* m_fileName;
	const char* m_windowName;
public:
	CImageProcess(const char* image_name) 
		:m_fileName(image_name) 
	{}
	~CImageProcess()
	{}

	void Run()
	{}
};