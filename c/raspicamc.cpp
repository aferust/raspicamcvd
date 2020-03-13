#include "raspicamc.h"

RPCam RPC_NewCamera(){
    //raspicam::RaspiCam_Cv *camera = new raspicam::RaspiCam_Cv();
    /*raspicam::RaspiCam_Cv cm;
    
    cm.set(cv::CAP_PROP_FRAME_WIDTH, CV_8UC3);
    cm.set(cv::CAP_PROP_FRAME_WIDTH, width);
    cm.set(cv::CAP_PROP_FRAME_HEIGHT, height);
    cm.set(cv::CAP_PROP_FPS, 15);
    camera.rpc = cm;*/
    return new raspicam::RaspiCam_Cv();
}

bool RPC_CameraSet(RPCam cam, int prop, double val){
    return cam->set(prop, val);
}

double RPC_CameraGet(RPCam cam, int prop){
    return cam->get(prop);
}

bool RPC_Open(RPCam cam){
    return cam->open();
}

bool RPC_IsOpened(RPCam cam){
    return cam->isOpened();
}

bool RPC_grab(RPCam cam){
    return cam->grab();
}

void RPC_retrieve(RPCam cam, int* rows, int* cols, int* type, void* data){
    cv::Mat image;
    cam->retrieve(image);
    *rows = image.rows;
    *cols = image.cols;
    *type = image.type();
    data = image.data;
}

void RPC_retrieve2(RPCam cam, Mat img){
    cam->retrieve(*img);
}

void RPC_Release(RPCam cam){
    cam->release();
}
