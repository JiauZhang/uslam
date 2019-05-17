#include "init.hpp"
#include <pangolin/pangolin.h>

//#include <boost/thread/mutex.hpp>
#include <mutex>
#include <iostream>

//using namespace mutex = boost::mutex;
//using namespace boost;
using namespace std;

Viewer::Viewer(): mbFinishRequested(false), mbFinished(true), mbStopped(true), mbStopRequested(false)
{

    double fps=30.0;
    mT = 1e3/fps;

	mImageWidth = 640;
	mImageHeight = 480;
	
	mViewpointX = 0;
	mViewpointY = -0.7;
	mViewpointZ = -1.8;
    mViewpointF = 500;
}

void Viewer::Run()
{
    mbFinished = false;
    mbStopped = false;	
	
    pangolin::CreateWindowAndBind("USLAM: Map Viewer",1024,768);

    // 3D Mouse handler requires depth testing to be enabled
    glEnable(GL_DEPTH_TEST);

    // Issue specific OpenGl we might need
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    pangolin::CreatePanel("menu").SetBounds(0.0,1.0,0.0,pangolin::Attach::Pix(175));
    pangolin::Var<bool> menuFollowCamera("menu.Follow Camera",true,true);
    pangolin::Var<bool> menuShowPoints("menu.Show Points",true,true);
    pangolin::Var<bool> menuShowKeyFrames("menu.Show KeyFrames",true,true);
    pangolin::Var<bool> menuShowGraph("menu.Show Graph",true,true);
    pangolin::Var<bool> menuLocalizationMode("menu.Localization Mode",false,true);
    pangolin::Var<bool> menuReset("menu.Reset",false,false);

    // Define Camera Render Object (for view / scene browsing)
    pangolin::OpenGlRenderState s_cam(
                pangolin::ProjectionMatrix(1024,768,mViewpointF,mViewpointF,512,389,0.1,1000),
                pangolin::ModelViewLookAt(mViewpointX,mViewpointY,mViewpointZ, 0,0,0,0.0,-1.0, 0.0)
                );

    // Add named OpenGL viewport to window and provide 3D Handler
    pangolin::View& d_cam = pangolin::CreateDisplay()
            .SetBounds(0.0, 1.0, pangolin::Attach::Pix(175), 1.0, -1024.0f/768.0f)
            .SetHandler(new pangolin::Handler3D(s_cam));

    pangolin::OpenGlMatrix Twc;
    Twc.SetIdentity();

    //cv::namedWindow("USLAM: Current Frame");

    bool bFollow = true;
    bool bLocalizationMode = false;


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	if(menuFollowCamera && bFollow)
	{
		s_cam.Follow(Twc);
	}
	else if(menuFollowCamera && !bFollow)
	{
		s_cam.SetModelViewMatrix(pangolin::ModelViewLookAt(mViewpointX,mViewpointY,mViewpointZ, 0,0,0,0.0,-1.0, 0.0));
		s_cam.Follow(Twc);
		bFollow = true;
	}
	else if(!menuFollowCamera && bFollow)
	{
		bFollow = false;
	}

	if(menuLocalizationMode && !bLocalizationMode)
	{
		std::cout << "Activate Localization Mode" << std::endl;
		bLocalizationMode = true;
	}
	else if(!menuLocalizationMode && bLocalizationMode)
	{
		std::cout << "Deactivate Localization Mode" << std::endl;
		bLocalizationMode = false;
	}

	d_cam.Activate(s_cam);
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	
	/*
	if(menuShowKeyFrames || menuShowGraph)
		mpMapDrawer->DrawKeyFrames(menuShowKeyFrames,menuShowGraph);
	if(menuShowPoints)
		mpMapDrawer->DrawMapPoints();
	*/

	pangolin::FinishFrame();

	//cv::Mat im = mpFrameDrawer->DrawFrame();
	//cv::imshow("ORB-SLAM2: Current Frame",im);
	//cv::waitKey(mT);

	if(menuReset)
	{
		menuShowGraph = true;
		menuShowKeyFrames = true;
		menuShowPoints = true;
		menuLocalizationMode = false;
		if(bLocalizationMode)
			std::cout << "Deactivate Localization Mode" << std::endl;
		bLocalizationMode = false;
		bFollow = true;
		menuFollowCamera = true;
		//mpSystem->Reset();
		menuReset = false;
	}
}

void Viewer::RequestFinish()
{
    unique_lock<mutex> lock(mMutexFinish);
    mbFinishRequested = true;
}

bool Viewer::CheckFinish()
{
    unique_lock<mutex> lock(mMutexFinish);
    return mbFinishRequested;
}

void Viewer::SetFinish()
{
    unique_lock<mutex> lock(mMutexFinish);
    mbFinished = true;
}

bool Viewer::isFinished()
{
    unique_lock<mutex> lock(mMutexFinish);
    return mbFinished;
}

void Viewer::RequestStop()
{
    unique_lock<mutex> lock(mMutexStop);
    if(!mbStopped)
        mbStopRequested = true;
}

bool Viewer::isStopped()
{
    unique_lock<mutex> lock(mMutexStop);
    return mbStopped;
}

bool Viewer::Stop()
{
    unique_lock<mutex> lock(mMutexStop);
    unique_lock<mutex> lock2(mMutexFinish);

    if(mbFinishRequested)
        return false;
    else if(mbStopRequested)
    {
        mbStopped = true;
        mbStopRequested = false;
        return true;
    }

    return false;

}

void Viewer::Release()
{
    unique_lock<mutex> lock(mMutexStop);
    mbStopped = false;
}
