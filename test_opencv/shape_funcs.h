/************************************************************************/
/* 使用函数创建一些图形                                                                     */
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
/* 水波的模拟                                                                     */
/************************************************************************/
// 正弦波
double waterFunc_gerstner(double x) {
	return sqrt(1 - x*x);
}
// Gerstner波
// x(p) = p - QDAsin(Dp-wt)
// y(p) = Acos(Dp-wt)
double waterFunc_gerstner(double x, const double shapePara, const double wavelength, const double amplitude, const double wt) {
	return sqrt(1 - x*x);
}

void AddWaterWave(IplImage* img, int shapePara, int amplitude, int frequence, int time = 0) {

}