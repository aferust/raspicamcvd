module raspicamcvd;

import opencvd.cvcore;

struct RPCam {
    void* p;

    static RPCam opCall(){
        return RPC_NewCamera();
    }
    
    bool set(int prop, double val){
        return RPC_CameraSet(this, prop, val);
    }
    
    double get(int prop){
        return RPC_CameraGet(this, prop);
    }
    
    bool open(){
        return RPC_Open(this);
    }
    
    bool isOpened(){
        return RPC_IsOpened(this);
    }
    
    bool grab(){
        return RPC_grab(this);
    }
    
    void retrieve(Mat img){
        RPC_retrieve2(this, img);
    }

    void release(){
        RPC_Release(this);
    }
}

private extern (C) {
    RPCam RPC_NewCamera();
    bool RPC_CameraSet(RPCam cam, int prop, double val);
    double RPC_CameraGet(RPCam cam, int prop);
    bool RPC_Open(RPCam cam);
    bool RPC_IsOpened(RPCam cam);
    bool RPC_grab(RPCam cam);
    void RPC_retrieve2(RPCam cam, Mat img);
    void RPC_Release(RPCam cam);
}
