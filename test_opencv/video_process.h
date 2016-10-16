#pragma once

#include <opencv2\highgui\highgui.hpp>
#include <cv.h>

class CVideoProcess
{
private:
	const char* m_windowName;
	const char* m_fileName;
	
	static int s_trackbarSlidePos;
	static CvCapture* s_cvCapture;

	CVideoProcess() {}

public:
	CVideoProcess( const char* video_name) 
		:m_fileName(video_name)
		, m_windowName("CVideoProcess")
	{
		cvNamedWindow(m_windowName, CV_WINDOW_AUTOSIZE);
		if (!s_cvCapture)
		{
			s_cvCapture = cvCreateFileCapture(m_fileName);
		}
	}

	~CVideoProcess() 
	{
		cvReleaseCapture(&s_cvCapture);
		cvDestroyWindow(m_windowName);
	}

	void Run()
	{
		int frame_count = (int)cvGetCaptureProperty(
			s_cvCapture, CV_CAP_PROP_FRAME_COUNT);

		if (frame_count != 0) {
			cvCreateTrackbar(
				"Position",
				m_windowName,
				&s_trackbarSlidePos,
				frame_count,
				&CVideoProcess::OnTrackbarSlide
				//&(this->OnTrackbarSlide)
			);
		}

		IplImage* frame;
		frame = cvQueryFrame(s_cvCapture);
		IplImage* out_scale = cvCreateImage(cvSize(frame->width / 2, frame->height / 2), frame->depth, frame->nChannels);
		IplImage* out_canny = cvCreateImage(cvSize(frame->width / 2, frame->height / 2), IPL_DEPTH_8U, 1);
		IplImage* frame_out = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);
		while (1) {
			frame = cvQueryFrame(s_cvCapture);
			if (!frame)break;

			// do something with each frame

			//cvSmooth(frame, frame, CV_GAUSSIAN, 3, 3);

			cvPyrDown(frame, out_scale);
			cvCanny(out_scale, out_canny, 20, 100, 3);
			//if (!out_canny)break;

			// end

			s_trackbarSlidePos += 1;
			cvSetTrackbarPos("Position", m_windowName, s_trackbarSlidePos);
			cvShowImage(m_windowName, out_canny);
			char c = cvWaitKey(23);
			if (c == 27)break;
		}

		cvReleaseImage(&out_canny);
		cvReleaseImage(&out_scale);
	}

	static void OnTrackbarSlide(int pos) {
		s_trackbarSlidePos = pos;
		cvSetCaptureProperty(
			s_cvCapture, CV_CAP_PROP_POS_FRAMES, pos);
	}
};

CvCapture* CVideoProcess::s_cvCapture = NULL;
int CVideoProcess::s_trackbarSlidePos = 0;