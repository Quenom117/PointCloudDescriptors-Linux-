# PointCloudDescriptors

***A simple command line program to generate relevant descriptors from point cloud data (.PCD files) before exporting the results into Numpy Files (.NPY files) used with python.***

---

## Build

1. mkdir build
2. cd build
3. cmake ../src/
4. make

If the above commands crash, execute `sudo apt install libpcl-*` and try again.

## Run

`./PointCloudDescriptors 1 ../resources/apple.pcd ./appel.npy 0.05 0.01`

## References

**[1]** `Salti, S., Tombari, F., & Di Stefano, L. (2014). SHOT: Unique signatures of histograms for surface and texture description. Computer Vision and Image Understanding, 125, 251-264.`

**[2]** `Tombari, F., Salti, S., & Di Stefano, L. (2010, October). Unique shape context for 3D data description. In Proceedings of the ACM workshop on 3D object retrieval (pp. 57-62).`

## License

[![License](http://img.shields.io/:license-mit-blue.svg?style=flat-square)](http://opensource.org/licenses/mit-license.php)
