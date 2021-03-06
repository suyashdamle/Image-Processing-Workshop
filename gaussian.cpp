#include <iostream>
#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
using namespace cv;
using namespace std;

#define k_size 3

int main(){
  int K[k_size][k_size]={{1,2,1},
     {2,4,2},
     {1,2,1}};;
  
      
  int rsum,gsum,bsum;
  
  Mat src=imread("img.jpg",1);
   namedWindow( "IP", WINDOW_NORMAL );
    imshow("IP",src);
  
    Mat op(src.rows,src.cols,CV_8UC3,Scalar(0,0,0));
    for(int i=0;i<=src.rows-k_size;i++){
      for(int j=0;j<=src.cols-k_size;j++){
      //working for rectangle beginning at pixel(i,j)
	rsum=bsum=gsum=0;
	for(int l=i;l<i+k_size;l++){
	  for(int m=j;m<j+k_size;m++){
	    bsum+=src.at<Vec3b>(l,m)[0]*K[l-i][m-j];
	    gsum+=src.at<Vec3b>(l,m)[1]*K[l-i][m-j];
	    rsum+=src.at<Vec3b>(l,m)[2]*K[l-i][m-j];
	  }
	}
	op.at<Vec3b>(i+k_size/2,j+k_size/2)[0]=bsum/16;
	op.at<Vec3b>(i+k_size/2,j+k_size/2)[1]=gsum/16;
	op.at<Vec3b>(i+k_size/2,j+k_size/2)[2]=rsum/16;
      }
    }
    namedWindow( "OP", WINDOW_NORMAL );
    imshow("OP",op);
    waitKey(0);
    return 0;
}

