#pragma once

#include <opencv2/highgui/highgui.hpp>

class CImageProcess
{
private:
	const char* m_windowName;

	IplImage* m_img;
public:
	CImageProcess() 
		: m_windowName("CImageProgress")
		, m_img(nullptr)
	{}
	CImageProcess(const char* image_name) 
		: m_windowName("CImageProgress")
	{}
	~CImageProcess()
	{
		EndShowImg();
	}

	/**********************************************
	*** 流程控制
	**********************************************/
	void StartShowImg() {
		cvNamedWindow(m_windowName);
	}

	void RefreshImg() {
		cvShowImage(m_windowName, m_img);

		while (true) {
			if (cvWaitKey(1000) == 27) {
				break;
			}
		}
	}

	void EndShowImg() {
		if (m_img) {
			cvReleaseImage(&m_img);
		}
		cvDestroyWindow(m_windowName);
	}

	void CustomProcess() {
		do_create_load("test.jpg");
		StartShowImg();
		RefreshImg();
	}

	/**********************************************
	*** 图片处理函数
	**********************************************/
	// 加载图片
	void do_create_load(const char* img_file) {
		m_img = cvLoadImage(img_file);
	}
	// 将图片设置为单色图片
	void do_create_color()
	{
		int depth = IPL_DEPTH_8U;
		int channel = 3;
		m_img = cvCreateImage(CvSize(300, 300),
			depth,
			channel);

		// 画个什么图像呢
		for (int y = 0; y < m_img->height; ++y) {
			char* p_line = m_img->imageDataOrigin + y * m_img->widthStep;
			for (int x = 0; x < m_img->width; ++x) {
				long* p_pixel = (long*)(p_line + x * depth / 8 / sizeof(char) * channel);
 
				// 大端专属方式
				//long color = (0xff * x / m_img->width) | ((0xff * y / m_img->height) << 8);
				//*p_pixel = color;

				// 分别三个通道
				*p_pixel = 0xff;
				*(p_pixel + 1) = 0xff;
				*(p_pixel + 2) = 0;
			}
		}

	}
};