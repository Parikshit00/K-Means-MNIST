# K-Means Clustering
This code provides the C++ scratch implementation of K-Means clustering algorithm on `MNIST` dataset to classify images in one of the class from `0 or 1 or 2 ...9`.  
Refer to `mnistdataset` folder to see the `uybte`version of this dataset. 
![Output](/media/mnist.webp)


# Requirements
- g++ or clang type of c++ compiler.  
- opencv c++

# Requirements Installation

## Linux:
Refer to this link: https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html

## Macos
```
brew install llvm
brew install opencv
```

# Build the project
In the root directory of this repo:
```
cd code
mkdir build && cd build && cmake ..
make
```
# Run
inside your `build`folder:  
```
./kmeans
```
# Output
The implementation has a accuracy of 60% on test dataset:    
![Output](/media/out.png)

# Refrences:  
+ https://stackoverflow.com/questions/12993941/how-can-i-read-the-mnist-dataset-with-c+ 
+ https://github.com/aditya1601/kmeans-clustering-cpp
