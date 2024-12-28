#include <opencv2/opencv.hpp>
#include <iostream>



int main() {
    // Initialize video capture (0 is the default camera)
    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cerr << "Error: Cannot open the camera." << std::endl;
        return -1;
    }

    // Set desired frame width and height (optional)
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    cap.set(cv::CAP_PROP_FPS, 30);

    cv::Mat frame;
    while (true) {
        // Capture frame-by-frame
        cap >> frame;

        // Check if frame is empty
        if (frame.empty()) {
            std::cerr << "Error: Blank frame grabbed." << std::endl;
            break;
        }

        // Display the resulting frame (optional)
        cv::imshow("Camera Feed", frame);

        // Press 'q' to exit the loop
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    // Release the video capture object and close windows
    cap.release();
    cv::destroyAllWindows();

    return 0;
}