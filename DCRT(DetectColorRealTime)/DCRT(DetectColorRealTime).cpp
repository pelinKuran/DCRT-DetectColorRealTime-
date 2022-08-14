//#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#define red

cv::Scalar red_upperb(179, 255, 255);
cv::Scalar red_lowerb(170, 150, 60);

cv::Scalar green_upperb(102, 255, 255);
cv::Scalar green_lowerb(25, 72, 72);
int main()
{ 
	double dM01, dM10, dArea, posX, posY;
	double last_x = -1, last_y = -1;
	int deviceID = 0;
	std::string cap_name = "The Frame";
	cv::Mat frame, hsv_frame;
	cv::VideoCapture cap;
	cv::Mat img_crop, img_tresholded;
	cap.open(deviceID, cv::CAP_DSHOW);
	cv::namedWindow(cap_name, cv::WINDOW_NORMAL);

	if (!cap.isOpened())
	{
		std::cerr << "Cap not opened!" << std::endl;
		return -1;
	}

	while (cv::waitKey(1) < 1)
	{
		cap >> frame;
		cv::resizeWindow(cap_name, frame.size());
		cv::imshow(cap_name, frame);

	}
	cv::Mat img_lined = cv::Mat::zeros(frame.size(), CV_8UC3);;
	cv::Rect uBox = cv::selectROI(cap_name, frame);


	for (;;)
	{
		cap >> frame;
		if (frame.empty()) {
			std::cerr << "Frame empty" << std::endl;
			std::cerr << "Frame empty" << std::endl;
			return -2;
		}
		img_crop = frame(uBox);
	
		cv::imshow("Capture2", img_crop);

		//convert bgr to hsv
		cv::cvtColor(img_crop, hsv_frame, cv::COLOR_BGR2HSV);

		#ifdef green
				cv::inRange(hsv_frame, green_lowerb, green_upperb, img_tresholded);
		#endif // !greenColor

		#ifdef red
				cv::inRange(hsv_frame, red_lowerb, red_upperb, img_tresholded);
		#endif // !redColor


		cv::dilate(img_tresholded, img_tresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));
		cv::erode(img_tresholded, img_tresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));


		cv::Moments t_moments = cv::moments(img_tresholded);
		dM01 = t_moments.m01; //for y mean
		dM10 = t_moments.m10; // for x mean
		dArea = t_moments.m00;
		posX = dM10 / dArea;
		posY = dM01 / dArea;

		
		if (dArea > 10000)
		{
			//Inform state of the selected led source
			if (last_x >= 0 && last_y >= 0 && posX >= 0 && posY >= 0 )
			{
				cv::putText(frame, "ON", cv::Point(static_cast<float>(uBox.x), static_cast<float>(uBox.y)), cv::FONT_HERSHEY_PLAIN,1, cv::Scalar(0, 255, 0));
				
			}
			
			last_x = posX;
			last_y = posY;
		}
		else
			cv::putText(frame, "OFF", cv::Point(static_cast<float>(uBox.x), static_cast<float>(uBox.y)), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 0, 255));

		cv::imshow("Capture", img_tresholded);
		frame += img_lined;

		cv::imshow(cap_name, frame);

		if (cv::waitKey(5) >= 0)
			break;		
	}

	return 0;
}
