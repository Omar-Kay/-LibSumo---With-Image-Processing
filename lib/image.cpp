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
//#include <mutex>
//#include <condition_variable>


using namespace sumo;


void Image::process(/*cv::Mat& m*/)
{
	
	//FILE *p = popen("mplayer -cache 32 -demuxer lavf -lavfdopts format=mjpeg -dumpstream -dumpfile yourfile.mjp", "w");
	//FILE *p = popen("mplayer -cache 32 -demuxer lavf -lavfdopts format=mjpeg - >/home/cse/libsumo/libsumo/lol.mjp", "w");
	FILE *p = popen("mplayer -cache 32 -demuxer lavf -lavfdopts format=mjpeg - >/dev/null 2>&1", "w");
	//FILE *p = popen("mplayer -cache 32 -demuxer lavf -lavfdopts format=mjpeg", "w");
	//FILE *p = fopen("data.txt","ab+");
	unsigned char* buffer;
	//mutex imageLock;
	//bool newImageAvailable;
	while (!_stop) {
//if (!(i->frame_number%15))
//	{
		//unique_lock<mutex> ulock(imageLock);
        	//imageAqcuired.wait(ulock,[&](){return !newImageAvailable;});
		uint8_t *b = getMessage();
		if (!b)
			break;
		auto *i = reinterpret_cast<struct image *>(b);
		//uint8_t *lol = b + sizeof(*i);
		//printf("pixel val: %d, fno: %d size: %d \n", lol[0]/*i->head.size*/, i->frame_number,i->head.size - sizeof(*i));
		if (p)
		{fwrite(b + sizeof(*i), 1, i->head.size - sizeof(*i), p);
		/*m = cv::imread("data.txt", CV_LOAD_IMAGE_COLOR);
		cv::namedWindow("test", 0);
//while(1)	
		cv::imshow("test", m);*/	
		}
		//ulock.unlock();
        	//newImageAvailable = true;
        	//imageAqcuired.notify_one();
		
	delete[] b;
	}
//}
	pclose(p);
}


