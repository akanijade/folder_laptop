#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

uint8_t compute_grey(uint32_t* p);

 

//convert this function into assembly
void gray_scale(Mat* color, Mat* gray) {

for (int r=0; r<color->rows; r++) {
for (int c=0; c<color->cols; c++) {
uint32_t* p = (uint32_t*)color->ptr(r,c);
*gray->ptr(r, c) = compute_grey(p); //(uint8_t) (((*p & 0xff000000) >> 24) + ((*p & 0x00ff0000) >> 16) + ((*p & 0x0000ff00) >> 8))/3 ;
}
}
}

int main( int argc, char** argv )
{
if( argc != 2)
{
cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
return -1;
}

Mat image, gray;
image = imread(argv[1], cv::IMREAD_COLOR); // Read the file
gray.create(image.rows, image.cols, CV_8UC1);

//converting color image to gray scale with C++.
//Add RGB channels and divide by there ... average or all three channels
gray_scale(&image, &gray);

printf("\n***** Input image *****\n");
printf("Dim:%x\n", image.dims);
printf("Rows:%d\n", image.rows);
printf("Cols:%d\n", image.cols);
printf("Channels:%d\n", image.channels());

printf("\n***** Gray image *****\n");
printf("Dim:%x\n", gray.dims);
printf("Rows:%d\n", gray.rows);
printf("Cols:%d\n", gray.cols);
printf("Channels:%d\n", gray.channels());

if(! image.data ) // Check for invalid input
{
printf("Could not open or find the image");
return -1;
}

namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
imshow( "Display window", image ); // Show our image inside it.

namedWindow( "Display gray window", WINDOW_AUTOSIZE );// Create a window for display.
imshow( "Display gray window", gray); // Show our image inside it.
waitKey(0); // Wait for a keystroke in the window
return 0;
}