#include <opencv2\highgui\highgui.hpp>
#include <cv.h>

#include "frame_process.h"
#include "video_process.h"
//#pragma comment(lib,"opencv_contrib2413d.lib")
//#pragma comment(lib,"opencv_core2413d.lib")
//#pragma comment(lib,"opencv_features2d2413d.lib")
//#pragma comment(lib,"opencv_flann2413d.lib")
//#pragma comment(lib,"opencv_gpu2413d.lib")
//#pragma comment(lib,"opencv_highgui2413d.lib")
//#pragma comment(lib,"opencv_imgproc2413d.lib")
//#pragma comment(lib,"opencv_legacy2413d.lib")
//#pragma comment(lib,"opencv_ml2413d.lib")
//#pragma comment(lib,"opencv_objdetect2413d.lib")
//#pragma comment(lib,"opencv_ts2413d.lib")
//#pragma comment(lib,"opencv_video2413d.lib")
//opencv_contrib2413d.lib
//opencv_core2413d.lib
//opencv_features2d2413d.lib
//opencv_flann2413d.lib
//opencv_gpu2413d.lib
//opencv_highgui2413d.lib
//opencv_imgproc2413d.lib
//opencv_legacy2413d.lib
//opencv_ml2413d.lib
//opencv_objdetect2413d.lib
//opencv_ts2413d.lib
//opencv_video2413d.lib

#pragma comment(lib,"opencv_world310d.lib")

const char* g_windowName = "Example";
const char* g_filename = "chongai.mp4";

void main(int argc, char**argv){
	CVideoProcess t = CVideoProcess("chongai.mp4");
	t.Run();
 }