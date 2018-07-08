/*
 * This file is part of the libsumo - a reverse-engineered library for
 * controlling Parrot's connected toy: Jumping Sumo
 *
 * Copyright (C) 2014 I. Loreen
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

	Mat image;

	waitKey();
	sumo::Control c;
	if (!c.open(/*image*/))
		return EXIT_FAILURE;
//	namedWindow("test", 0);
//while(1)	
//	imshow("test", image);
#if 0
	for (int i = 0; i < 4; i++) {
		dispatcher.quickTurn(-M_PI/2);
		usleep(1000000);
	}

	for (int i = 0 ; i < 6; i++) {
		dispatcher.quickTurn(M_PI/3);
		usleep(1500000);
	}
#endif
	
//c.move(20, 0);
//c.quickTurnRight();	
	

	getchar(); 

	//c.close();

	//return EXIT_SUCCESS;
return 0;
} 




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





/*#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "control.h"
#include <unistd.h>
char key;
int main(void)
{
	sumo::Control c;
	cv::Mat m;
	if (!c.open(m))
		return EXIT_FAILURE;

#if 0
	for (int i = 0; i < 4; i++) {
		dispatcher.quickTurn(-M_PI/2);
		usleep(1000000);
	}

	for (int i = 0 ; i < 6; i++) {
		dispatcher.quickTurn(M_PI/3);
		usleep(1500000);
	}
#endif

//	c.move(-20, 10);
		//while(1)
		//{
//			sleep(1);
			int i = 1;
			c.quickTurn(45);
			while(i<3)
			{
				c.move(10, 0);
				sleep(1);
				c.move(20, 0);
				sleep(5);
				c.move(10, 0);
				sleep(1);
				c.move(0, 0);
				c.tap();
				c.quickTurn(45);
				i++;
				//break;
			}
			//c.tap();
			
			//sleep(1);
		//}
	getchar(); //dispatcher.wait();



//#define ACCELERATION_CONSTANT 6
//int mod = 0;
	//while(1) {
		
			//mod = ACCELERATION_CONSTANT;
		//else // breaking - we are going reverse 
			//mod = ACCELERATION_CONSTANT * 2;
	//}



	c.close();

	return EXIT_SUCCESS;
}*/
