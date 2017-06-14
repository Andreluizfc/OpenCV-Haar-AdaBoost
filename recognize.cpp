#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

std::string DoubleToString (double a)
{

  std::ostringstream temp;
  temp<<a;
  return temp.str();
}

std::string IntToString (int a)
{

  std::ostringstream temp;
  temp<<a;
  return temp.str();
}

int main (int argc, char** argv) {


  Mat img = imread(argv[1]);
  Mat grey;

  cvtColor(img, grey, COLOR_BGR2GRAY );
  //equalizeHist(grey, grey);

  CascadeClassifier cascade;
  if (cascade.load("cascade.xml")) {
    vector<double> weights;
    vector<int> levels;
    vector<Rect> detections;
    vector<int> numDetections;
    //cascade.detectMultiScale(img, detections, 1.05, 3, CV_HAAR_DO_CANNY_PRUNING, Size(100, 100), Size(600, 600));
    //cascade.detectMultiScale(grey, detections, levels, weights, 1.05, 10, 0, Size(400, 600), Size(1000,1500), true);
    cascade.detectMultiScale(grey, detections, numDetections, 1.05, 6, 0, Size(400, 600), Size(1000,1500));

    printf("%zd objects(s) are found.\n", detections.size());
    

    Scalar color2 = Scalar( 0, 0, 255 );

    for (int i = 0; i < detections.size(); i++) {
      Rect r = detections[i];
      printf("a object is found at Rect(%d,%d,%d,%d).\n", r.x, r.y, r.width, r.height);

      rectangle(img, r.tl(), r.br(), color2, 2, 8);
      //cerr << levels[i] << " " << weights[i] << "\t" << detections[i] << endl;
      putText(img, IntToString(numDetections[i]), Point(detections[i].x, detections[i].y), 3, 2, Scalar(0,0,255));

    }
  }

  namedWindow("image", CV_WINDOW_NORMAL);
  resizeWindow("image",600,600);
  imshow("image",img);
  waitKey(0);
  waitKey(0);
  return 0;
}

