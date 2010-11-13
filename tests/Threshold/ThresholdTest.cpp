#include <unistd.h>
#include <iostream>

#include "Threshold.h"
#include "ImageComparator.h"

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace cv;

#define DATA_DIR "../../../tests/data/Threshold/"

BOOST_AUTO_TEST_CASE( PWD )
{
	char *pwd = get_current_dir_name();
	cout << "Current working directory: \"" << pwd << "\"\n";
	// workspace/image_segmentation/build/tests/Threshold
	free(pwd);
}

BOOST_AUTO_TEST_CASE( GraySquareOnGrayBackground )
{
	Mat image = imread(DATA_DIR "5.bmp");
	Mat mask = Mat::ones(image.size(), CV_8U);

	BOOST_CHECK(image.size() == Size(50, 50));
	BOOST_CHECK(image.type() == CV_8U);

	BOOST_CHECK( ImageComparator::isEqual<u_char>(image1, image2) );
}

