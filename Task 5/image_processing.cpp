#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// Function prototypes
void loadImage(Mat &image);
void displayImage(const Mat &image, const string &windowName);
void applyGrayscale(Mat &image);
void applyBlur(Mat &image, int kernelSize);
void applySharpen(Mat &image);
void adjustBrightnessContrast(Mat &image, int brightness, int contrast);
void cropImage(Mat &image, Rect roi);
void resizeImage(Mat &image, int width, int height);
void saveImage(const Mat &image, const string &filename);

int main() {
    Mat image;
    string filename="test1.jpeg";
    int choice;

    while (true) {
        cout << "IMAGE PROCESSING TOOL\n";
        cout << "1. Load Image\n";
        cout << "2. Display Image\n";
        cout << "3. Apply Grayscale Filter\n";
        cout << "4. Apply Blur Filter\n";
        cout << "5. Apply Sharpen Filter\n";
        cout << "6. Adjust Brightness and Contrast\n";
        cout << "7. Crop Image\n";
        cout << "8. Resize Image\n";
        cout << "9. Save Image\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                loadImage(image);
                break;
            case 2:
                displayImage(image, "Loaded Image");
                break;
            case 3:
                applyGrayscale(image);
                break;
            case 4: {
                int kernelSize;
                cout << "Enter kernel size for blur (odd number): ";
                cin >> kernelSize;
                applyBlur(image, kernelSize);
                break;
            }
            case 5:
                applySharpen(image);
                break;
            case 6: {
                int brightness, contrast;
                cout << "Enter brightness value (-100 to 100): ";
                cin >> brightness;
                cout << "Enter contrast value (-100 to 100): ";
                cin >> contrast;
                adjustBrightnessContrast(image, brightness, contrast);
                break;
            }
            case 7: {
                int x, y, width, height;
                cout << "Enter x, y, width, height for crop: ";
                cin >> x >> y >> width >> height;
                cropImage(image, Rect(x, y, width, height));
                break;
            }
            case 8: {
                int width, height;
                cout << "Enter new width and height: ";
                cin >> width >> height;
                resizeImage(image, width, height);
                break;
            }
            case 9:
                cout << "Enter filename to save: ";
                // cin >> 
                filename="test1.jpeg";;
                saveImage(image, filename);
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}

void loadImage(Mat &image) {
    string filename;
    cout << "Enter the filename of the image to load: ";
    // cin >>
    filename="test1.jpeg";
    image = imread(filename);
    if (image.empty()) {
        cout << "Error loading image!" << endl;
    } else {
        cout << "Image loaded successfully!" << endl;
    }
}

void displayImage(const Mat &image, const string &windowName) {
    if (image.empty()) {
        cout << "No image to display!" << endl;
        return;
    }
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow(windowName, image);
    waitKey(0); // Wait for a keystroke in the window
    destroyWindow(windowName);
}

void applyGrayscale(Mat &image) {
    if (image.empty()) {
        cout << "No image loaded!" << endl;
        return;
    }
    cvtColor(image, image, COLOR_BGR2GRAY);
    cout << "Applied grayscale filter!" << endl;
}

void applyBlur(Mat &image, int kernelSize) {
    if (image.empty()) {
        cout << "No image loaded!" << endl;
        return;
    }
    if (kernelSize % 2 == 0) {
        cout << "Kernel size must be an odd number!" << endl;
        return;
    }
    blur(image, image, Size(kernelSize, kernelSize));
    cout << "Applied blur filter!" << endl;
}

void applySharpen(Mat &image) {
    if (image.empty()) {
        cout << "No image loaded!" << endl;
        return;
    }
    Mat kernel = (Mat_<float>(3, 3) <<
                  0, -1, 0,
                  -1, 5, -1,
                  0, -1, 0);
    filter2D(image, image, -1, kernel);
    cout << "Applied sharpen filter!" << endl;
}

void adjustBrightnessContrast(Mat &image, int brightness, int contrast) {
    if (image.empty()) {
        cout << "No image loaded!" << endl;
        return;
    }
    image.convertTo(image, -1, 1 + contrast / 100.0, brightness);
    cout << "Adjusted brightness and contrast!" << endl;
}

void cropImage(Mat &image, Rect roi) {
    if (image.empty()) {
        cout << "No image loaded!" << endl;
        return;
    }
    if (roi.x < 0 || roi.y < 0 || roi.width <= 0 || roi.height <= 0 ||
        roi.x + roi.width > image.cols || roi.y + roi.height > image.rows) {
        cout << "Invalid crop region!" << endl;
        return;
    }
    image = image(roi);
    cout << "Cropped image!" << endl;
}

void resizeImage(Mat &image, int width, int height) {
    if (image.empty()) {
        cout << "No image loaded!" << endl;
        return;
    }
    resize(image, image, Size(width, height));
    cout << "Resized image!" << endl;
}

void saveImage(const Mat &image, const string &filename) {
    if (image.empty()) {
        cout << "No image to save!" << endl;
        return;
    }
    imwrite(filename, image);
    cout << "Image saved as " << filename << endl;
}
