// Example 2-10. The same object can load videos from a camera or a file
// 
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

void help(char** argv ) {
	std::cout << "\n"
	<< "\nxample 2-10. The same object can load videos from a camera or a file"
    << "\nCall:\n"  
	<< argv[0] <<" [path/image]\n"
	<< "\nor, read from camera:\n"
	<< argv[0]
	<< "\nFor example:\n"
	<< argv[0] << " ../tree.avi\n"
	<< std::endl;
}
	

int main( int argc, char** argv ) {
	
	help(argv);



  cv::namedWindow( "Example 2-10", cv::WINDOW_AUTOSIZE );
  cv::VideoCapture cap;

  if (argc==1) {
    cap.open(0); // open the first camera
  } else {
    cap.open(argv[1]);
  }

  if( !cap.isOpened() ) { // check if we succeeded
    std::cerr << "Couldn't open capture." << std::endl;
    return -1;
  }

  cv::Mat frame;
  cv::Mat gray_image;
  for(;;) {

    cap >> frame;

    if( frame.empty() ) break; // Ran out of film

    cv::imshow( "Example 2-10_0", frame );
    cvtColor(frame, gray_image, COLOR_BGR2GRAY);

    cv::imshow( "Example 2-10_1", gray_image );   
    Canny(gray_image, frame, 50, 150, 3); 

    cv::imshow( "Example 2-10_2", frame );

    if( (char) cv::waitKey(33) >= 0 ) break;

  }

  return 0;

}
