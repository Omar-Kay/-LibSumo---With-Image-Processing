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
 * 02110-1301 USA
 */
#include "image.h"
#include "protocol.h"
#include "iostream"

#include <thread>   
#include <mutex>    
#include <chrono> 
#include <iostream>
#include <unistd.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace sumo;
using namespace std;

void Image::process(Mat& m)
{
	
	
	while (!_stop) 	{
		FILE *p = fopen("new_data","w+");
		uint8_t *b = getMessage();

		if (!b)
			break;
		auto *i = reinterpret_cast<struct image *>(b);

		if (!(i->frame_number%15))
		{
			if (p) {
				fwrite(b + sizeof(*i), 1, i->head.size - sizeof(*i), p);
			}
			fclose(p);
			delete[] b;

			usleep(50);
			m = imread("new_data");
			
		}
		
		
	}
}


