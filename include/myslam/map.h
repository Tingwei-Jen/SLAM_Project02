#ifndef MAP_H
#define MAP_H

#include "myslam/common_include.h"
#include "myslam/frame.h"
#include "myslam/mappoint.h"

namespace myslam
{
class Map
{
public: 
	typedef std::shared_ptr<Map> Ptr;
	unordered_map<unsigned long, MapPoint::Ptr>     map_points_; // all landmarks
	unordered_map<unsigned long, Frame::Ptr>		keyframes_; // all keyframes

	Map(){}

	void insertMapPoint(MapPoint::Ptr map_points);
	void insertKeyFrame(Frame::Ptr frame);

};
}

#endif //MAP_H