//////#include "selectFrame.h"
//////int main()
//////{
//////	cv::VideoCapture video_in;
//////
//////	return 0;
//////}
////
////
////
////
////
////
////
///////////////////////////////////
////#include "opencv2/imgcodecs.hpp"
////#include "opencv2/highgui.hpp"
////#include "opencv2/imgproc.hpp"
////
////#include <opencv2/core.hpp>
////#include <opencv2/videoio.hpp>
////#include <iostream>
////#include <opencv2/core/hal/interface.h>
////
////enum transform_type
////{
////	morph_rect,
////	morph_cross,
////	morph_ellipsemorp
////};
////
////void find_mask(cv::Mat& hsv_frame, std::vector<uint8_t> bounding_upper, std::vector<uint8_t> bounding_lower);
////cv::Mat calculate_morphological_transform(cv::Mat& hsv_frame, int morph_type, int dilation_size, cv::Point point);
////void find_contour(cv::Mat& masked_frame, cv::Mat& frame, std::string color_name, int color = (0, 0, 255));
////
////int main() {
////	cv::Mat frame, hsv_frame;
////	cv::VideoCapture cap;
////	int deviceID = 0;
////	std::vector<uint8_t> red_lower = { 136, 87, 11 };
////	std::vector<uint8_t> red_upper = { 180, 255, 255 };
////	cap.open(deviceID, cv::CAP_ANY);
////
////	if (!cap.isOpened())
////	{
////		std::cerr << "Cap not opened!" << std::endl;
////		return -1;
////	}
////
////	for (;;) {
////		cap.read(frame);
////		if (frame.empty()) {
////			std::cerr << "Frame empty" << std::endl;
////			return -2;
////		}
////		cv::imshow("Capture", frame);
////		if (cv::waitKey(5) >= 0)
////			break;
////		cv::cvtColor(frame, hsv_frame, cv::COLOR_BGR2HSV);
////		find_mask(hsv_frame, red_upper, red_lower);
////		auto morph = calculate_morphological_transform(hsv_frame, morph_rect, 5, cv::Point(5, 5));
////		find_contour(morph, frame, "red");
////	}
////	return 0;
////}
////
////void find_mask(cv::Mat& hsv_frame, std::vector<uint8_t> bounding_upper, std::vector<uint8_t> bounding_lower)
////{
////	cv::inRange(hsv_frame, bounding_lower, bounding_upper, hsv_frame);
////}
////cv::Mat calculate_morphological_transform(cv::Mat& hsv_frame, int morph_type, int dilation_size, cv::Point point)
////{
////	cv::Mat masked_frame;
////	cv::Mat transformed_frame;
////
////	auto M = cv::Mat::ones(5, 5, CV_8U);
////	auto anchor = cv::Point(-1, -1);
////	// You can try more different parameters
////
////	cv::dilate(hsv_frame, masked_frame, M, anchor, 1, cv::BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
////	cv::bitwise_and(hsv_frame, masked_frame, transformed_frame);
////	return transformed_frame;
////}
////// TODO Pelin ::  TRY Sobel Filter
////
////void find_contour(cv::Mat& masked_frame, cv::Mat& frame, std::string color_name, int color)
////{
////	cv::Mat canny_edge;
////	std::vector<std::vector<cv::Point> > contours;
////	std::vector<cv::Vec4i> hierarchy;
////	cv::findContours(masked_frame, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
////	for (auto contour : contours) {
////		auto area = cv::contourArea(contour);
////		if (area > 300) {
////			cv::putText(frame, color_name, cv::Point(5, 5), cv::FONT_HERSHEY_SCRIPT_SIMPLEX, 1.0, color);
////		}
////	}
////}
//
///*
////
////#include <opencv2/core/hal/interface.h>
//
////enum transform_type
////{
////	morph_rect,
////	morph_cross,
////	morph_ellipsemorp
////};
////
////void find_mask(cv::Mat& hsv_frame, std::vector<uint8_t> bounding_upper, std::vector<uint8_t> bounding_lower);
////cv::Mat calculate_morphological_transform(cv::Mat& hsv_frame, int morph_type, int dilation_size, cv::Point point);
////void find_contour(cv::Mat& masked_frame, cv::Mat& frame, std::string color_name, int color = (0, 0, 255));
//// /*cv::cvtColor(frame, hsv_frame, cv::COLOR_BGR2HSV);
//find_mask(hsv_frame, red_upper, red_lower);
//auto morph = calculate_morphological_transform(hsv_frame, morph_rect, 5, cv::Point(5, 5));
//find_contour(morph, frame, "red"); */
////void find_mask(cv::Mat& hsv_frame, std::vector<uint8_t> bounding_upper, std::vector<uint8_t> bounding_lower)
////{
////	cv::inRange(hsv_frame, bounding_lower, bounding_upper, hsv_frame);
////}
////cv::Mat calculate_morphological_transform(cv::Mat& hsv_frame, int morph_type, int dilation_size, cv::Point point)
////{
////	cv::Mat masked_frame;
////	cv::Mat transformed_frame;
////
////	auto M = cv::Mat::ones(5, 5, CV_8U);
////	auto anchor = cv::Point(-1, -1);
////	// You can try more different parameters
////
////	cv::dilate(hsv_frame, masked_frame, M, anchor, 1, cv::BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
////	cv::bitwise_and(hsv_frame, masked_frame, transformed_frame);
////	return transformed_frame;
////}
////// TODO Pelin ::  TRY Sobel Filter
////
////void find_contour(cv::Mat& masked_frame, cv::Mat& frame, std::string color_name, int color)
////{
////	cv::Mat canny_edge;
////	std::vector<std::vector<cv::Point> > contours;
////	std::vector<cv::Vec4i> hierarchy;
////	cv::findContours(masked_frame, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
////	for (auto contour : contours) {
////		auto area = cv::contourArea(contour);
////		if (area > 300) {
////			cv::putText(frame, color_name, cv::Point(5, 5), cv::FONT_HERSHEY_SCRIPT_SIMPLEX, 1.0, color);
////		}
////	}
////}*/
//
///*
////#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/imgproc.hpp"
//
//#include <opencv2/core.hpp>
//#include <opencv2/videoio.hpp>
//#include <thread>
//#include <iostream>
//#ifdef _WIN32
//#include <Windows.h>
//#else
//#include <unistd.h>
//#endif
//
//cv::Scalar red_upperb(179, 255, 255);
//cv::Scalar red_lowerb(170, 150, 60);
//cv::Scalar green_upperb(102, 255, 255);
//cv::Scalar green_lowerb(25, 72, 72);
//void previous_cross(cv::Mat& p_oldCrossCorr, cv::Mat & crossCorr, float p_cross) {
//	p_oldCrossCorr = crossCorr;
//	p_cross = p_oldCrossCorr.at<float>(0, 0);
//	Sleep(20);
//}
//int main()
//{
//	std::thread async(previous_cross);
//	float dM01, dM10, dArea, posX, posY;
//	float last_x = -1, last_y = -1;
//	float t_oldC=0.0f, c =0.0f;
//	int deviceID = 0;
//	std::string cap_name = "The Frame";
//	cv::Mat frame, hsv_frame;
//	cv::VideoCapture cap;
//	cv::Mat img_crop, img_tresholded, crossCorr, t_oldCrossCorr, t_oldFrame;
//	cap.open(deviceID, cv::CAP_DSHOW);
//	cv::namedWindow(cap_name, cv::WINDOW_NORMAL);
//	if (!cap.isOpened())
//	{
//		std::cerr << "Cap not opened!" << std::endl;
//		return -1;
//	}
//
//	while (cv::waitKey(1) < 1)
//	{
//		cap >> frame;
//		cv::resizeWindow(cap_name, frame.size());
//		cv::imshow(cap_name, frame);
//
//	}
//	cv::Mat img_lined = cv::Mat::zeros(frame.size(), CV_8UC3);;
//	cv::Rect uBox = cv::selectROI(cap_name, frame);
//
//	bool isFirst = true;
//	for (;;)
//	{
//
//
//		cap >> frame;
//		if (frame.empty()) {
//			std::cerr << "Frame empty" << std::endl;
//			std::cerr << "Frame empty" << std::endl;
//			return -2;
//		}
//		img_crop = frame(uBox);
//		cv::imshow("Capture2", img_crop);
//		if (!isFirst)
//		{
//			if(c > t_oldC)
//				cv::putText(frame, "ON", cv::Point(static_cast<float>(uBox.x), static_cast<float>(uBox.y)), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 255, 0));
//			else
//				cv::putText(frame, "OFF", cv::Point(static_cast<float>(uBox.x), static_cast<float>(uBox.y)), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 255, 0));
//
//			t_oldFrame = frame;
//			cv::matchTemplate(img_crop, t_oldFrame, crossCorr, cv::TM_CCORR_NORMED);
//			c = crossCorr.at<float>(0, 0);
//			std::cout << crossCorr.at<float>(0, 0) << std::endl;
//
//			async.join();
//
//		}
//		cv::imshow(cap_name, frame);
//
//
//		isFirst = false;
//#ifdef  color_detection
//	/*	cv::imshow(cap_name, frame);*/
//	//convert bgr to hsv
//	//treshold image (green)
//	//cv::inRange(hsv_frame, green_lowerb, green_upperb, img_tresholded);
//cv::cvtColor(img_crop, hsv_frame, cv::COLOR_BGR2HSV);
//
////treshold image (red)
//cv::inRange(hsv_frame, red_lowerb, red_upperb, img_tresholded);
//
//cv::dilate(img_tresholded, img_tresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));
//cv::erode(img_tresholded, img_tresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));
//
//
//cv::Moments t_moments = cv::moments(img_tresholded);
//dM01 = t_moments.m01; //for y mean
//dM10 = t_moments.m10; // for x mean
//dArea = t_moments.m00;
//posX = dM10 / dArea;
//posY = dM01 / dArea;
//
//
//if (dArea > 10000)
//{
//	//calculate the light
//
//	//Inform state of the selected led source
//	if (last_x >= 0 && last_y >= 0 && posX >= 0 && posY >= 0)
//	{
//		cv::putText(frame, "ON", cv::Point(static_cast<float>(uBox.x), static_cast<float>(uBox.y)), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 255, 0));
//
//	}
//
//	last_x = posX;
//	last_y = posY;
//}
//else
//cv::putText(frame, "OFF", cv::Point(static_cast<float>(uBox.x), static_cast<float>(uBox.y)), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 0, 255));
//
//cv::imshow("Capture", img_tresholded);
//frame += img_lined;
//cv::imshow(cap_name, frame);
//#endif //  colordetection
//if (cv::waitKey(5) >= 0)
//break;
//
//	}
//	return 0;
//}
//*/