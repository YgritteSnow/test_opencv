#include <opencv2\highgui\highgui.hpp>
#include <cv.h>

#pragma comment(lib,"opencv_contrib2413d.lib")
#pragma comment(lib,"opencv_core2413d.lib")
#pragma comment(lib,"opencv_features2d2413d.lib")
#pragma comment(lib,"opencv_flann2413d.lib")
#pragma comment(lib,"opencv_gpu2413d.lib")
#pragma comment(lib,"opencv_highgui2413d.lib")
#pragma comment(lib,"opencv_imgproc2413d.lib")
#pragma comment(lib,"opencv_legacy2413d.lib")
#pragma comment(lib,"opencv_ml2413d.lib")
#pragma comment(lib,"opencv_objdetect2413d.lib")
#pragma comment(lib,"opencv_ts2413d.lib")
#pragma comment(lib,"opencv_video2413d.lib")

CvCapture* g_cvCapture = NULL;
int g_slider_position = 0;

void OnTrackbarSlide(int pos){
	g_slider_position = pos;
	cvSetCaptureProperty(
		g_cvCapture, CV_CAP_PROP_POS_FRAMES, pos);
}

const char* g_windowName = "Example";
const char* g_filename = "test.avi";

void main(int argc, char**argv){
	cvNamedWindow(g_windowName, CV_WINDOW_AUTOSIZE);
	g_cvCapture = cvCreateFileCapture(g_filename);

	int frame_count = (int)cvGetCaptureProperty(
		g_cvCapture, CV_CAP_PROP_FRAME_COUNT);

	
	if (frame_count != 0){
		cvCreateTrackbar(
			"Position",
			g_windowName,
			&g_slider_position,
			frame_count,
			OnTrackbarSlide
			);
	}

	IplImage* frame;
	frame = cvQueryFrame(g_cvCapture);
	//IplImage* frame_out = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);
	while (1){
		frame = cvQueryFrame(g_cvCapture);
		cvSmooth(frame, frame, CV_GAUSSIAN, 13, 13);
		g_slider_position += 1;
		cvSetTrackbarPos("Position", g_windowName, g_slider_position);
		if (!frame)break;
		cvShowImage(g_windowName, frame);
		char c = cvWaitKey(23);
		if (c == 27)break;
	}

	cvReleaseCapture(&g_cvCapture);
	//cvReleaseImage(&frame_out);
	cvDestroyWindow(g_windowName);
}