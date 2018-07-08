# -LibSumo---With-Image-Processing
Added Functionality to control Parrot's Jumping Sumo Through Image Processing
This is a slight modification to @iloreen/libsumo's reverse engineering of the library, so most credit goes to @iloreen.

To use this modified library, you need to pull and install @iloreen's version https://github.com/iloreen/libsumo, and replace the lib directory with the one provided here.

I've simply added a method that exposes the data to OpenCV easily, for advanced image processing decisions to be taken. You'll notice in test.cpp that adding the output of the Jumping Sumo's video stream is as simple as adding this code:

` Mat imgOriginal;
	sumo::Control c;
	if (!c.open(imgOriginal))
return EXIT_FAILURE;`

Now we can begin doing all sorts of complex processing to the mat, imgOriginal, and based on it, take decisions. In test.cpp, I've decided to create a sample where the sumo follows a ball of a specific color. If you would like to try this out yourself, then all you need to do is adjust the threshold in:

  `inRange(imgHSV, Scalar(104, 31, 43), Scalar(120, 182, 165), imgThresholded);`
  
  To a reasonable range your ball/circle would be within the given lighting.
  
  Enjoy!
