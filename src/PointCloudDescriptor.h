#include <iostream>
#include <vector>
#include <fcntl.h>

//old line: #include<io.h>
#ifdef _WIN32
	#include <io.h>
#elif __linux__
	#include <inttypes.h>
	#include <unistd.h>
	#define __int64 int64_t
	#define _close close
	#define _read read
	#define _lseek64 lseek64
	#define _O_RDONLY O_RDONLY
	#define _open open
	#define _lseeki64 lseek64
	#define _lseek lseek
	#define stricmp strcasecmp
#endif
// //SAF_Handle.cpp line:458 old line:INFILE = _open(infilename, _O_RDONLY | _O_BINARY);
// #ifdef __linux__
// 	INFILE = _open(infilename, _O_RDONLY);
// #elif
// 	INFILE = _open(infilename, _O_RDONLY | _O_BINARY);
// #endif



// load pcl libraries
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/features/normal_3d.h>
#include <pcl/filters/voxel_grid.h>

#include "cnpy_header_only.h"

#include <pcl/io/vlp_grabber.h>

/* local 3D descriptors */

// descriptor - USC : Unique Shape Context
#include <pcl/features/usc.h>
// descriptor - SHOT : Unique Signatures of Histograms for Local Surface
#include <pcl/features/shot.h>

// histogram visualization
#include <pcl/visualization/histogram_visualizer.h>


#ifndef POINTCLOUDDESCRIPTOR_H
#define POINTCLOUDDESCRIPTOR_H

class PointCloudDescriptor {
public:
	PointCloudDescriptor(std::string& plyFileName, bool rgb, double radiusSearch);
	~PointCloudDescriptor();

	void ComputeSHOTFeature(pcl::PointCloud<pcl::PointXYZ>::Ptr _cloud, pcl::PointCloud<pcl::Normal>::Ptr _normals);
	void ComputeSHOTRGBFeature(pcl::PointCloud<pcl::PointXYZRGB>::Ptr _cloud, pcl::PointCloud<pcl::Normal>::Ptr _normals);
	void ComputeUSCFeature(pcl::PointCloud<pcl::PointXYZ>::Ptr _cloud);

	void LoadPlyFile();
	void DownSampling(float voxelSize);

	void ShowPointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr _cloud);
	void ShowPointCloudRgb(pcl::PointCloud<pcl::PointXYZRGB>::Ptr _cloudRgb);

	void ComputeNormals(pcl::PointCloud<pcl::PointXYZ>::Ptr _cloud);
	void ComputeNormalsRgb(pcl::PointCloud<pcl::PointXYZRGB>::Ptr _cloud);

	pcl::PointCloud<pcl::SHOT352>::Ptr GetDescriptorSHOT();
	std::vector<std::vector<float>> GetVectDescriptorSHOT();

	pcl::PointCloud<pcl::SHOT1344>::Ptr GetDescriptorSHOTRgb();
	std::vector<std::vector<float>> GetVectDescriptorSHOTRgb();

	pcl::PointCloud<pcl::UniqueShapeContext1960>::Ptr GetDescriptorUSC();
	std::vector<std::vector<float>> GetVectDescriptorUSC();

	pcl::PointCloud<pcl::PointXYZ>::Ptr GetCloud();
	pcl::PointCloud<pcl::PointXYZ>::Ptr GetCloudDownSample();
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr GetCloudRgb();
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr GetCloudDownSampleRgb();
	pcl::PointCloud<pcl::Normal>::Ptr GetNormals();

	void ExportDescriptorNpy(std::vector<std::vector<float>> inputVector, std::string npyFileName);

private:
	bool _rgb;
	double _radiusSearch;
	std::string _plyFileName;
	pcl::PointCloud<pcl::PointXYZ>::Ptr _cloud;
	pcl::PointCloud<pcl::PointXYZ>::Ptr _cloudDownSample;
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr _cloudRgb;
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr _cloudDownSampleRgb;
	pcl::PointCloud<pcl::Normal>::Ptr _normals;

	pcl::PointCloud<pcl::SHOT352>::Ptr _descriptorSHOT;
	std::vector<std::vector<float>> _vectDescriptorSHOT;
	pcl::PointCloud<pcl::SHOT1344>::Ptr _descriptorSHOTRgb;
	std::vector<std::vector<float>> _vectDescriptorSHOTRgb;
	pcl::PointCloud<pcl::UniqueShapeContext1960>::Ptr _descriptorUSC;
	std::vector<std::vector<float>> _vectDescriptorUSC;
};

#endif //POINTCLOUDDESCRIPTOR_H
