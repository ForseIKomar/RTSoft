// Example 2-10. The same object can load videos from a camera or a file
// 
#include <opencv2/opencv.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

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
  cv::Point pt1(50, 50), pt2(100, 100);
  int x = 50;
  int y = 50;
  int pol = 1;
  for(;;) {

    cap >> frame;
    
    if( frame.empty() ) break; // Ran out of film
    
    pol++;

    x = (x * y + pol * x + rand() % 50) % 444;
    y = (y + pol * y + rand() % 50) % 333;

    pt1.x = x;
    pt1.y = y;
    pt2.x = x + 50;
    pt2.y = y + 50;
    cv::rectangle(frame, pt1, pt2, cv::Scalar::all(0));

    cv::imshow( "Example 2-10", frame );

    if( (char) cv::waitKey(33) >= 0 ) break;

  }

  return 0;

}
