set(PROJECT_NAME PointCloudDescriptors)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "PointCloudDescriptor.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "main.cpp"
    "PointCloudDescriptor.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

find_package(PCL 1.3 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES} ${PCL_LIBRARIES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE PointCloudDescriptors)

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
endif()
################################################################################
# MSVC runtime library
################################################################################
get_property(MSVC_RUNTIME_LIBRARY_DEFAULT TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY)
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    string(CONCAT "MSVC_RUNTIME_LIBRARY_STR"
        MultiThreaded
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    string(CONCAT "MSVC_RUNTIME_LIBRARY_STR"
        MultiThreaded
    )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES MSVC_RUNTIME_LIBRARY ${MSVC_RUNTIME_LIBRARY_STR})

################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "D:/Usagers/yayad/vcpkg/installed/x64-windows-static/include"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "D:/Usagers/yayad/vcpkg/installed/x64-windows-static/include"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "NOMINMAX;"
        "_CRT_SECURE_NO_WARNINGS;"
        "_MBCS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "BOOST_USE_WINDOWS_H;"
        "NOMINMAX;"
        "_CRT_SECURE_NO_WARNINGS;"
        "_MBCS"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od
            >
            $<$<CONFIG:Release>:
                /O2;
                /Oi;
                /Gy
            >
            /permissive-;
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od
            >
            $<$<CONFIG:Release>:
                /O2;
                /Oi;
                /Gy
            >
            /permissive-;
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /DEBUG:FULL;
            /SUBSYSTEM:CONSOLE
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /DEBUG:FULL;
            /SUBSYSTEM:CONSOLE
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "boost_atomic-vc140-mt;"
        "boost_chrono-vc140-mt;"
        "boost_container-vc140-mt;"
        "boost_context-vc140-mt;"
        "boost_coroutine-vc140-mt;"
        "boost_date_time-vc140-mt;"
        "boost_exception-vc140-mt;"
        "boost_filesystem-vc140-mt;"
        "boost_graph-vc140-mt;"
        "boost_iostreams-vc140-mt;"
        "boost_locale-vc140-mt;"
        "boost_math_c99-vc140-mt;"
        "boost_math_c99f-vc140-mt;"
        "boost_math_c99l-vc140-mt;"
        "boost_math_tr1-vc140-mt;"
        "boost_math_tr1f-vc140-mt;"
        "boost_math_tr1l-vc140-mt;"
        "boost_random-vc140-mt;"
        "boost_regex-vc140-mt;"
        "boost_serialization-vc140-mt;"
        "boost_system-vc140-mt;"
        "boost_thread-vc140-mt;"
        "boost_unit_test_framework-vc140-mt;"
        "boost_wserialization-vc140-mt;"
        "bz2;"
        "double-conversion;"
        "expat;"
        "flann;"
        "flann_cpp;"
        "freetype;"
        "glew32;"
        "jpeg;"
        "jsoncpp;"
        "libcharset;"
        "libcrypto;"
        "libcurl;"
        "libhdf5;"
        "libhdf5_hl;"
        "libhpdf;"
        "libiconv;"
        "libpng16;"
        "libssl;"
        "libszip;"
        "libxml2;"
        "lz4;"
        "lzma;"
        "netcdf;"
        "ogg;"
        "OpenGL32;"
        "pcl_common_release;"
        "pcl_features_release;"
        "pcl_filters_release;"
        "pcl_io_ply_release;"
        "pcl_io_release;"
        "pcl_kdtree_release;"
        "pcl_keypoints_release;"
        "pcl_ml_release;"
        "pcl_octree_release;"
        "pcl_outofcore_release;"
        "pcl_people_release;"
        "pcl_recognition_release;"
        "pcl_registration_release;"
        "pcl_sample_consensus_release;"
        "pcl_search_release;"
        "pcl_segmentation_release;"
        "pcl_stereo_release;"
        "pcl_surface_release;"
        "pcl_tracking_release;"
        "pcl_visualization_release;"
        "proj;"
        "pugixml;"
        "qhullcpp;"
        "qhullstatic;"
        "qhullstatic_r;"
        "sqlite3;"
        "theora;"
        "theoradec;"
        "theoraenc;"
        "tiff;"
        "tiffxx;"
        "turbojpeg;"
        "vtkChartsCore-8.2;"
        "vtkCommonColor-8.2;"
        "vtkCommonComputationalGeometry-8.2;"
        "vtkCommonCore-8.2;"
        "vtkCommonDataModel-8.2;"
        "vtkCommonExecutionModel-8.2;"
        "vtkCommonMath-8.2;"
        "vtkCommonMisc-8.2;"
        "vtkCommonSystem-8.2;"
        "vtkCommonTransforms-8.2;"
        "vtkDICOMParser-8.2;"
        "vtkDomainsChemistry-8.2;"
        "vtkDomainsChemistryOpenGL2-8.2;"
        "vtkexodusII-8.2;"
        "vtkFiltersAMR-8.2;"
        "vtkFiltersCore-8.2;"
        "vtkFiltersExtraction-8.2;"
        "vtkFiltersFlowPaths-8.2;"
        "vtkFiltersGeneral-8.2;"
        "vtkFiltersGeneric-8.2;"
        "vtkFiltersGeometry-8.2;"
        "vtkFiltersHybrid-8.2;"
        "vtkFiltersHyperTree-8.2;"
        "vtkFiltersImaging-8.2;"
        "vtkFiltersModeling-8.2;"
        "vtkFiltersParallel-8.2;"
        "vtkFiltersParallelImaging-8.2;"
        "vtkFiltersPoints-8.2;"
        "vtkFiltersProgrammable-8.2;"
        "vtkFiltersSelection-8.2;"
        "vtkFiltersSMP-8.2;"
        "vtkFiltersSources-8.2;"
        "vtkFiltersStatistics-8.2;"
        "vtkFiltersTexture-8.2;"
        "vtkFiltersTopology-8.2;"
        "vtkFiltersVerdict-8.2;"
        "vtkGeovisCore-8.2;"
        "vtkgl2ps-8.2;"
        "vtkImagingColor-8.2;"
        "vtkImagingCore-8.2;"
        "vtkImagingFourier-8.2;"
        "vtkImagingGeneral-8.2;"
        "vtkImagingHybrid-8.2;"
        "vtkImagingMath-8.2;"
        "vtkImagingMorphological-8.2;"
        "vtkImagingSources-8.2;"
        "vtkImagingStatistics-8.2;"
        "vtkImagingStencil-8.2;"
        "vtkInfovisCore-8.2;"
        "vtkInfovisLayout-8.2;"
        "vtkInteractionImage-8.2;"
        "vtkInteractionStyle-8.2;"
        "vtkInteractionWidgets-8.2;"
        "vtkIOAMR-8.2;"
        "vtkIOAsynchronous-8.2;"
        "vtkIOCityGML-8.2;"
        "vtkIOCore-8.2;"
        "vtkIOEnSight-8.2;"
        "vtkIOExodus-8.2;"
        "vtkIOExport-8.2;"
        "vtkIOExportOpenGL2-8.2;"
        "vtkIOExportPDF-8.2;"
        "vtkIOGeometry-8.2;"
        "vtkIOImage-8.2;"
        "vtkIOImport-8.2;"
        "vtkIOInfovis-8.2;"
        "vtkIOLegacy-8.2;"
        "vtkIOLSDyna-8.2;"
        "vtkIOMINC-8.2;"
        "vtkIOMovie-8.2;"
        "vtkIONetCDF-8.2;"
        "vtkIOParallel-8.2;"
        "vtkIOParallelXML-8.2;"
        "vtkIOPLY-8.2;"
        "vtkIOSegY-8.2;"
        "vtkIOSQL-8.2;"
        "vtkIOTecplotTable-8.2;"
        "vtkIOVeraOut-8.2;"
        "vtkIOVideo-8.2;"
        "vtkIOXML-8.2;"
        "vtkIOXMLParser-8.2;"
        "vtkmetaio-8.2;"
        "vtkParallelCore-8.2;"
        "vtkpugixml-8.2;"
        "vtkRenderingAnnotation-8.2;"
        "vtkRenderingContext2D-8.2;"
        "vtkRenderingContextOpenGL2-8.2;"
        "vtkRenderingCore-8.2;"
        "vtkRenderingFreeType-8.2;"
        "vtkRenderingGL2PSOpenGL2-8.2;"
        "vtkRenderingImage-8.2;"
        "vtkRenderingLabel-8.2;"
        "vtkRenderingLOD-8.2;"
        "vtkRenderingOpenGL2-8.2;"
        "vtkRenderingVolume-8.2;"
        "vtkRenderingVolumeOpenGL2-8.2;"
        "vtksys-8.2;"
        "vtkverdict-8.2;"
        "vtkViewsContext2D-8.2;"
        "vtkViewsCore-8.2;"
        "vtkViewsGeovis-8.2;"
        "vtkViewsInfovis-8.2;"
        "xxhash;"
        "zlib;"
        "zstd_static;"
        "cnpy"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "boost_atomic-vc140-mt;"
        "boost_chrono-vc140-mt;"
        "boost_container-vc140-mt;"
        "boost_context-vc140-mt;"
        "boost_coroutine-vc140-mt;"
        "boost_date_time-vc140-mt;"
        "boost_exception-vc140-mt;"
        "boost_filesystem-vc140-mt;"
        "boost_graph-vc140-mt;"
        "boost_iostreams-vc140-mt;"
        "boost_locale-vc140-mt;"
        "boost_math_c99-vc140-mt;"
        "boost_math_c99f-vc140-mt;"
        "boost_math_c99l-vc140-mt;"
        "boost_math_tr1-vc140-mt;"
        "boost_math_tr1f-vc140-mt;"
        "boost_math_tr1l-vc140-mt;"
        "boost_random-vc140-mt;"
        "boost_regex-vc140-mt;"
        "boost_serialization-vc140-mt;"
        "boost_system-vc140-mt;"
        "boost_thread-vc140-mt;"
        "boost_unit_test_framework-vc140-mt;"
        "boost_wserialization-vc140-mt;"
        "bz2;"
        "double-conversion;"
        "expat;"
        "flann;"
        "flann_cpp;"
        "freetype;"
        "glew32;"
        "jpeg;"
        "jsoncpp;"
        "libcharset;"
        "libcrypto;"
        "libcurl;"
        "libhdf5;"
        "libhdf5_hl;"
        "libhpdf;"
        "libiconv;"
        "libpng16;"
        "libssl;"
        "libszip;"
        "libxml2;"
        "lz4;"
        "lzma;"
        "netcdf;"
        "ogg;"
        "OpenGL32;"
        "pcl_common_release;"
        "pcl_features_release;"
        "pcl_filters_release;"
        "pcl_io_ply_release;"
        "pcl_io_release;"
        "pcl_kdtree_release;"
        "pcl_keypoints_release;"
        "pcl_ml_release;"
        "pcl_octree_release;"
        "pcl_outofcore_release;"
        "pcl_people_release;"
        "pcl_recognition_release;"
        "pcl_registration_release;"
        "pcl_sample_consensus_release;"
        "pcl_search_release;"
        "pcl_segmentation_release;"
        "pcl_stereo_release;"
        "pcl_surface_release;"
        "pcl_tracking_release;"
        "pcl_visualization_release;"
        "proj;"
        "pugixml;"
        "qhullcpp;"
        "qhullstatic;"
        "qhullstatic_r;"
        "sqlite3;"
        "theora;"
        "theoradec;"
        "theoraenc;"
        "tiff;"
        "tiffxx;"
        "turbojpeg;"
        "vtkChartsCore-8.2;"
        "vtkCommonColor-8.2;"
        "vtkCommonComputationalGeometry-8.2;"
        "vtkCommonCore-8.2;"
        "vtkCommonDataModel-8.2;"
        "vtkCommonExecutionModel-8.2;"
        "vtkCommonMath-8.2;"
        "vtkCommonMisc-8.2;"
        "vtkCommonSystem-8.2;"
        "vtkCommonTransforms-8.2;"
        "vtkDICOMParser-8.2;"
        "vtkDomainsChemistry-8.2;"
        "vtkDomainsChemistryOpenGL2-8.2;"
        "vtkexodusII-8.2;"
        "vtkFiltersAMR-8.2;"
        "vtkFiltersCore-8.2;"
        "vtkFiltersExtraction-8.2;"
        "vtkFiltersFlowPaths-8.2;"
        "vtkFiltersGeneral-8.2;"
        "vtkFiltersGeneric-8.2;"
        "vtkFiltersGeometry-8.2;"
        "vtkFiltersHybrid-8.2;"
        "vtkFiltersHyperTree-8.2;"
        "vtkFiltersImaging-8.2;"
        "vtkFiltersModeling-8.2;"
        "vtkFiltersParallel-8.2;"
        "vtkFiltersParallelImaging-8.2;"
        "vtkFiltersPoints-8.2;"
        "vtkFiltersProgrammable-8.2;"
        "vtkFiltersSelection-8.2;"
        "vtkFiltersSMP-8.2;"
        "vtkFiltersSources-8.2;"
        "vtkFiltersStatistics-8.2;"
        "vtkFiltersTexture-8.2;"
        "vtkFiltersTopology-8.2;"
        "vtkFiltersVerdict-8.2;"
        "vtkGeovisCore-8.2;"
        "vtkgl2ps-8.2;"
        "vtkImagingColor-8.2;"
        "vtkImagingCore-8.2;"
        "vtkImagingFourier-8.2;"
        "vtkImagingGeneral-8.2;"
        "vtkImagingHybrid-8.2;"
        "vtkImagingMath-8.2;"
        "vtkImagingMorphological-8.2;"
        "vtkImagingSources-8.2;"
        "vtkImagingStatistics-8.2;"
        "vtkImagingStencil-8.2;"
        "vtkInfovisCore-8.2;"
        "vtkInfovisLayout-8.2;"
        "vtkInteractionImage-8.2;"
        "vtkInteractionStyle-8.2;"
        "vtkInteractionWidgets-8.2;"
        "vtkIOAMR-8.2;"
        "vtkIOAsynchronous-8.2;"
        "vtkIOCityGML-8.2;"
        "vtkIOCore-8.2;"
        "vtkIOEnSight-8.2;"
        "vtkIOExodus-8.2;"
        "vtkIOExport-8.2;"
        "vtkIOExportOpenGL2-8.2;"
        "vtkIOExportPDF-8.2;"
        "vtkIOGeometry-8.2;"
        "vtkIOImage-8.2;"
        "vtkIOImport-8.2;"
        "vtkIOInfovis-8.2;"
        "vtkIOLegacy-8.2;"
        "vtkIOLSDyna-8.2;"
        "vtkIOMINC-8.2;"
        "vtkIOMovie-8.2;"
        "vtkIONetCDF-8.2;"
        "vtkIOParallel-8.2;"
        "vtkIOParallelXML-8.2;"
        "vtkIOPLY-8.2;"
        "vtkIOSegY-8.2;"
        "vtkIOSQL-8.2;"
        "vtkIOTecplotTable-8.2;"
        "vtkIOVeraOut-8.2;"
        "vtkIOVideo-8.2;"
        "vtkIOXML-8.2;"
        "vtkIOXMLParser-8.2;"
        "vtkmetaio-8.2;"
        "vtkParallelCore-8.2;"
        "vtkpugixml-8.2;"
        "vtkRenderingAnnotation-8.2;"
        "vtkRenderingContext2D-8.2;"
        "vtkRenderingContextOpenGL2-8.2;"
        "vtkRenderingCore-8.2;"
        "vtkRenderingFreeType-8.2;"
        "vtkRenderingGL2PSOpenGL2-8.2;"
        "vtkRenderingImage-8.2;"
        "vtkRenderingLabel-8.2;"
        "vtkRenderingLOD-8.2;"
        "vtkRenderingOpenGL2-8.2;"
        "vtkRenderingVolume-8.2;"
        "vtkRenderingVolumeOpenGL2-8.2;"
        "vtksys-8.2;"
        "vtkverdict-8.2;"
        "vtkViewsContext2D-8.2;"
        "vtkViewsCore-8.2;"
        "vtkViewsGeovis-8.2;"
        "vtkViewsInfovis-8.2;"
        "xxhash;"
        "zlib;"
        "zstd_static"
    )
endif()
target_link_libraries(${PROJECT_NAME} ${PCL_LIBRARIES}PRIVATE "${ADDITIONAL_LIBRARY_DEPENDENCIES}") ###// add pcl libraries

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_link_directories(${PROJECT_NAME} PRIVATE
        "D:/Usagers/yayad/vcpkg/installed/x64-windows-static/lib"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_link_directories(${PROJECT_NAME} PRIVATE
        "D:/Usagers/yayad/vcpkg/installed/x64-windows-static/lib"
    )
endif()

