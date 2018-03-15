#ifndef MAPPOINT_H
#define MAPPOINT_H

#include "myslam/common_include.h"
#include "myslam/frame.h"

namespace myslam
{
// forward declare : 
//if there is any change in Frame.h or Frame.cpp, mappoint.cpp will not compile.
//class Frame;
class MapPoint
{
public:
	typedef std::shared_ptr<MapPoint> Ptr;
	unsigned long                     id_;			 // ID
	static unsigned long              factory_id_;   // factory id
	bool                              good_;         // whether a good point
	Vector3d                          pos_;  		 // Position in world
	Vector3d                          norm_; 		 // Normal of viewing direction 
	Mat                               descriptor_; 	 // Descriptor for matching 
    
    list<Frame*>                       observed_frames_; // key-frames that can observe this point 
   	//只要使用前置宣告 (Forward Declaration) 的方式，並且將原來的實名物件轉換成物件指標的宣告方式，
   	//就能夠避免在表頭檔中 #include 其他表頭檔而造成的編譯依存關係。
    
    int         visible_times_;     // being visible in current frame 
    int         matched_times_;     // being an inliner in pose estimation

public: 
	MapPoint();
	MapPoint(
		unsigned long id, 
		const Vector3d& position, 
		const Vector3d& norm,
		Frame* frame = nullptr,
		const Mat& descriptor=Mat()   
	);

    inline cv::Point3f getPositionCV() const {
        return cv::Point3f( pos_(0,0), pos_(1,0), pos_(2,0) );
    }

	//factory method
	static MapPoint::Ptr createMapPoint();
	static MapPoint::Ptr createMapPoint(
        const Vector3d& pos_world, 
        const Vector3d& norm_,
        const Mat& descriptor,
        Frame* frame  );
};

}
#endif //MAPPOINT_H