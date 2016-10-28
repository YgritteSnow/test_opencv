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
	CImageProcess() 
		: m_fileName(NULL) 
		, m_windowName("CImageProgress")
	{}
	CImageProcess(const char* image_name) 
		: m_fileName(image_name)
		, m_windowName("CImageProgress")
	{}
	~CImageProcess()
	{}

	void Run()
	{
		int depth = IPL_DEPTH_8U;
		int channel = 3;
		IplImage* img = cvCreateImage(CvSize(300, 300),
			depth,
			channel);

		// 画个什么图像呢
		for (int y = 0; y < img->height; ++y) {
			char* p_line = img->imageDataOrigin + y * img->widthStep;
			for (int x = 0; x < img->width; ++x) {
				long* p_pixel = (long*)(p_line + x * depth / 8 / sizeof(char) * channel);
 
				// 大端专属方式
				//long color = (0xff * x / img->width) | ((0xff * y / img->height) << 8);
				//*p_pixel = color;

				// 分别三个通道
				*p_pixel = 0xff;
				*(p_pixel + 1) = 0xff;
				*(p_pixel + 2) = 0;
			}
		}

		cvNamedWindow(m_windowName);
		cvShowImage(m_windowName, img);
		while (true) {
			if (cvWaitKey(1000) == 27) {
				break;
			}
		}
		cvReleaseImage(&img);
		cvDestroyWindow(m_windowName);
	}
};