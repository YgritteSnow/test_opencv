/************************************************************************/
/* ʹ�ú�������һЩͼ��                                                                     */
/************************************************************************/
#pragma once

#include <opencv2/highgui/highgui.hpp>

void setImgPixel(IplImage* img, int x, int y, char r, char g, char b) {
	char* pixel = img->imageDataOrigin + y * img->widthStep + x * img->depth / 8 / sizeof(char) * img->nChannels;
	*pixel = r;
	*(pixel + 1) = g;
	*(pixel + 2) = b;
}

/************************************************************************/
/* ˮ����ģ��                                                                     */
/************************************************************************/
// ���Ҳ�
double waterFunc_gerstner(double x) {
	return sqrt(1 - x*x);
}
// Gerstner��
// x(p) = p - QDAsin(Dp-wt)
// y(p) = Acos(Dp-wt)
double waterFunc_gerstner(double x, const double shapePara, const double wavelength, const double amplitude, const double wt) {
	return sqrt(1 - x*x);
}

void AddWaterWave(IplImage* img, int shapePara, int amplitude, int frequence, int time = 0) {

}