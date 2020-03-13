#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <stdbool.h>
#include <raspicam/raspicam_cv.h>

extern "C" {
#endif

#ifdef __cplusplus
typedef cv::Mat* Mat;
typedef raspicam::RaspiCam_Cv* RPCam;
#else
typedef void* Mat;
typedef void* RPCam;
#endif

RPCam camera;

RPCam RPC_NewCamera();
bool RPC_CameraSet(RPCam cam, int prop, double val);
double RPC_CameraGet(RPCam cam, int prop);
bool RPC_Open(RPCam cam);
bool RPC_IsOpened(RPCam cam);
bool RPC_grab(RPCam cam);
void RPC_retrieve(RPCam cam, int* rows, int* cols, int* type, void* data);
void RPC_retrieve2(RPCam cam, Mat img);
void RPC_Release(RPCam cam);

#ifdef __cplusplus
}
#endif
