/*
 * This file is part of the libsumo - a reverse-engineered library for
 * controlling Parrot's connected toy: Jumping Sumo
 *
 * Copyright (C) 2014 I. Loreen
 * Modified by Omar Khafagi
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA*/

#include "control.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

//char key;
int main(void)
{
	
	 Mat imgOriginal;
	int cou=0;
	waitKey();
	sumo::Control c;
	if (!c.open(imgOriginal))
		return EXIT_FAILURE;

 while (true)
    {
       
if(imgOriginal.data)
 {
  resize(imgOriginal, imgOriginal, cvSize(640, 480));
  Mat  imgHSV;

  cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV    "first step"
  GaussianBlur(imgHSV, imgHSV, Size(7,7), 1.5, 1.5); // filter 
	
  
  Mat imgThresholded;

//  inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image  " extract red color"
  
  inRange(imgHSV, Scalar(104, 31, 43), Scalar(120, 182, 165), imgThresholded); //Threshold the image  " extract red color"
      
  //morphological opening (remove small objects from the foreground)
  erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );   // avoid noise 
  dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );  // avoid noise 

  //morphological closing (fill small holes in the foreground)
  dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );   // avoid noise 
  erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );     // avoid noise
medianBlur(imgThresholded,imgThresholded,15);
medianBlur(imgThresholded,imgThresholded,9);
//  Canny(imgHSV, imgHSV, 0, 30, 3);   
 vector<Vec3f> circles;
 
  // Apply the Hough Transform to find the circles
 HoughCircles( imgThresholded, circles, CV_HOUGH_GRADIENT, 1, imgThresholded.rows/2 , 50, 16, 0, 0);


 if (circles.size()<1)
	{
	c.quickTurn(45);
	}
  // Draw the circles detected
 for( size_t i = 0; i < circles.size(); i++ )
  {
if (circles.size()==1)
     {Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      int radius = cvRound(circles[i][2]);     
      circle( imgOriginal, center, 3, Scalar(0,255,0), -1, 8, 0 );// circle center     
     circle( imgOriginal, center, radius, Scalar(0,0,255), 3, 8, 0 );// circle outline
      cout << "center : " << center << "\nradius : " << radius << endl;
	int xcenter = imgOriginal.size().width;
	/*while (!((center.x<(xcenter/2)+(xcenter*0.05))&&(center.x>(xcenter/2)-(xcenter*0.05))))
	{
	int turn = 1;
	if (center.x<(xcenter/2)-(xcenter*0.05))
	turn = -turn;
	//cout<<"centerish"<<endl;
	c.move(10,turn);
	sleep(1);		
	c.move(0,0);
	sleep(1);
	++cou;
	}*/
  }}
//if ()
// / Show your results
  namedWindow( "Hough Circle Transform Demo", 0);
  imshow( "Hough Circle Transform Demo", imgOriginal );
 

  imshow("Thresholded Image", imgThresholded); //show the thresholded image

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
       {
            cout << "esc key is pressed by user" << endl;
            break; 
       }
    }}


 return 0;
} 
