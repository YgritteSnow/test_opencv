#include <opencv2\highgui\highgui.hpp>
#include <cv.h>

#include "frame_process.h"
#include "video_process.h"

void main(int argc, char**argv){
	//CVideoProcess t = CVideoProcess("test.mp4");
	//t.Run();
	CImageProcess t = CImageProcess("test.jpg");
	t.CustomProcess();
 }