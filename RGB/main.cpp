// Program Name: PhotoShopProgram.cpp
// Last Modification Date: 5/10/2023
// Author : Amr Abd-Eltawab Ahmed

#include "bmplib.cpp"
#include "bmplib.h"
#include <iostream>
#include <cstring>


unsigned char Image[SIZE][SIZE][RGB];
unsigned char Image2[SIZE][SIZE][RGB];


// Function to get the image from the User
void InputImage(){
    char InputImageName[98];

    // Get the Name of the image from the User
    cout << "Enter the name of the photo :";
    cin >> InputImageName;

    // Add .bmp to the name of the photo
    strcat(InputImageName, ".bmp");

    // Function from the library to load the photo
    readRGBBMP(InputImageName, Image);
}
void InputImage2(){
    char InputImageName2[98];

    // Get the Name of the image from the User
    cout << "Enter the name of the photo :";
    cin >> InputImageName2;

    // Add .bmp to the name of the photo
    strcat(InputImageName2, ".bmp");

    // Function from the library to load the photo
    readRGBBMP(InputImageName2, Image2);
}
// Function to Output image to User
void OutputImage(){
    char InputImageName[98];

    // Get the Name of the image from the User
    cout << "Enter the name of the photo :";
    cin >> InputImageName;

    // Add .bmp to the name of the photo
    strcat(InputImageName, ".bmp");

    // Function from the library to Save the photo
    writeRGBBMP(InputImageName, Image);
}
// Function to Output image to User
void OutputImage2(){
    char InputImageName[98];

    // Get the Name of the image from the User
    cout << "Enter the name of the photo :";
    cin >> InputImageName;

    // Add .bmp to the name of the photo
    strcat(InputImageName, ".bmp");

    // Function from the library to Save the photo
    writeRGBBMP(InputImageName, Image2);
}



// ----------------------------------------------------------------------------------- //
// Filter 1
void Black_White_Filter(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k< RGB; k++){

                int avg = (Image[i][j][0]*0.299)+(Image[i][j][1]*0.587)+(Image[i][j][2]*0.114);

                Image[i][j][0] = avg;
                Image[i][j][1] = avg;
                Image[i][j][2] = avg;

                if (Image[i][j][k] > 127) {
                    Image[i][j][0] = avg;
                    Image[i][j][1] = avg;
                    Image[i][j][2] = avg;
                }
                else {
                    Image[i][j][0] = avg;
                    Image[i][j][1] = avg;
                    Image[i][j][2] = avg;
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k< RGB; k++){
                if (Image[i][j][k] > 127) {
                    Image[i][j][k] = 255;
                }
                else {
                    Image[i][j][k] = 0;
                }
            }
        }
    }
}


// ----------------------------------------------------------------------------------- //
// Filter 2
void Invert_Filter(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k< RGB; k++){
                Image[i][j][k] = 255 - Image[i][j][k];
            }
        }
    }
}


// ----------------------------------------------------------------------------------- //
// Filter 3
void MergeImages() {
    // Create a temporary image to store the merged result
    unsigned char temp[SIZE][SIZE][RGB];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                // Calculate the average gray level of the corresponding pixels in both images
                temp[i][j][k] = (Image[i][j][k] + Image2[i][j][k]) / 2;
            }
        }
    }
    // Copy the merged image back to the original image
    memcpy(Image, temp, sizeof(temp));
}


// ----------------------------------------------------------------------------------- //
// Filter 4
void FlipImage() {
    int choice;
    cout << "Choose an option:\n1. Flip horizontally\n2. Flip vertically\nYour choice: ";
    cin >> choice;

    if (choice == 1) {
        // Flip the image horizontally
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int k = 0; k < RGB; k++) {
                    swap(Image[i][j][k], Image[i][SIZE - 1 - j][k]);
                }
            }
        }
    }
    else if (choice == 2) {
        // Flip the image vertically
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    swap(Image[i][j][k], Image[SIZE - 1 - i][j][k]);
                }
            }
        }
    }
    else {
        cout << "Invalid choice. Please choose 1 or 2." << endl;
    }
}


// ----------------------------------------------------------------------------------- //
// Filter 5
void RotateImage() {
    int choice;
    cout << "Choose an option:\n1. Rotate 90 degrees clockwise\n2. Rotate 180 degrees clockwise\n3. Rotate 270 degrees clockwise\nYour choice: ";
    cin >> choice;

    unsigned char temp[SIZE][SIZE][RGB];

    if (choice == 1) {
        // Rotate 90 degrees clockwise
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    temp[i][j][k] = Image[SIZE - 1 - j][i][k];
                }
            }
        }
    }
    else if (choice == 2) {
        // Rotate 180 degrees clockwise
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    temp[i][j][k] = Image[SIZE - 1 - i][SIZE - 1 - j][k];
                }
            }
        }
    }
    else if (choice == 3) {
        // Rotate 270 degrees clockwise
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    temp[i][j][k] = Image[j][SIZE - 1 - i][k];
                }
            }
        }
    }
    else {
        cout << "Invalid choice. Please choose 1, 2, or 3." << endl;
        return;
    }

    // Copy the rotated image back to the original image
    memcpy(Image, temp, sizeof(temp));
}


// ----------------------------------------------------------------------------------- //
// Filter 6
void DarkenLightenImage() {
    int choice;
    cout << "Choose an option:\n1. Darken the image by 50%\n2. Lighten the image by 50%\nYour choice: ";
    cin >> choice;

    if (choice == 1) {
        // Darken the image by reducing each pixel's intensity by half
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    Image[i][j][k] = max(0, Image[i][j][k] / 2);
                }
            }
        }
    }
    else if (choice == 2) {
        // Lighten the image by increasing each pixel's intensity by half
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    Image[i][j][k] = min(255, Image[i][j][k] + Image[i][j][k] / 2);
                }
            }
        }
    }
    else {
        cout << "Invalid choice. Please choose 1 or 2." << endl;
    }
}


// ----------------------------------------------------------------------------------- //
// Filter 7
void DetectImageEdges() {
    int choice;
    cout << "Choose an option:\n1. Black and White Detected Edges\n2. Colored Detected Edges\nYour choice: ";
    cin >> choice;

    if (choice == 1) {
        // Convert the image to black and white
        Black_White_Filter();

        // Create a temporary image to store detected edges
        unsigned char temp[SIZE][SIZE][RGB];

        for (int i = 1; i < SIZE - 1; i++) {
            for (int j = 1; j < SIZE - 1; j++) {
                for (int k = 0; k < RGB; k++) {
                    // Apply edge detection using a simple convolution filter
                    int edgeValue = (-Image[i - 1][j - 1][k] - Image[i - 1][j][k] - Image[i - 1][j + 1][k]
                                     - Image[i][j - 1][k] + 8 * Image[i][j][k]
                                     - Image[i][j + 1][k] - Image[i + 1][j - 1][k]
                                     - Image[i + 1][j][k] - Image[i + 1][j + 1][k]) / 8;

                    // Set the pixel value based on the edge detection result
                    temp[i][j][k] = edgeValue > 0 ? 255 : 0;
                }
            }
        }

        // Copy the detected edges back to the original image
        memcpy(Image, temp, sizeof(temp));
    }
    else if (choice == 2) {
        // Convert the image to black and white
        Black_White_Filter();

        // Create a temporary image to store detected edges
        unsigned char temp[SIZE][SIZE][RGB];

        for (int i = 1; i < SIZE - 1; i++) {
            for (int j = 1; j < SIZE - 1; j++) {
                for (int k = 0; k < RGB; k++) {
                    // Apply edge detection using a simple convolution filter
                    int edgeValue = (-Image[i - 1][j - 1][k] - Image[i - 1][j][k] - Image[i - 1][j + 1][k]
                                     - Image[i][j - 1][k] + 8 * Image[i][j][k]
                                     - Image[i][j + 1][k] - Image[i + 1][j - 1][k]
                                     - Image[i + 1][j][k] - Image[i + 1][j + 1][k]) / 8;

                    // Set the pixel value based on the edge detection result
                    temp[i][j][k] = edgeValue > 0 ? 255 : 0;
                }
            }
        }

        // Copy the detected edges back to the original image
        memcpy(Image, temp, sizeof(temp));
    }
    else {
        cout << "Invalid choice. Please choose 1 or 2." << endl;
    }
}


// ----------------------------------------------------------------------------------- //
// Filter 8
void Enlarge_Image(){
    int opp;
    cout << "Which Quarter do you want to Enlarge?\nEnter Your Choice:";
    cin >> opp;

    if (opp == 1) {
        for (int i = 0, k=0 ; i<SIZE ; k++ ,i+=2) {
            for (int j = 0, z=0 ; j<SIZE ; z++ ,j+=2) {
                for (int d = 0, y=0 ; d< RGB; y++,d++){
                    Image2[i][j][d] = Image[k][z][y];
                    Image2[i][j+1][d] = Image[k][z][y];
                    Image2[i+1][j][d] = Image[k][z][y];
                    Image2[i+1][j+1][d] = Image[k][z][y];
                }
            }
        }
    }

    if (opp == 2) {
        for (int i = 0, k=0 ; i<SIZE ; k++ ,i+=2) {
            for (int j = 0, z=128 ; j<SIZE ; z++ ,j+=2) {
                for (int d = 0, y=0 ; d< RGB; y++,d++){
                    Image2[i][j][d] = Image[k][z][y];
                    Image2[i][j+1][d] = Image[k][z][y];
                    Image2[i+1][j][d] = Image[k][z][y];
                    Image2[i+1][j+1][d] = Image[k][z][y];
                }
            }
        }
    }

    if (opp == 3) {
        for (int i = 0, k=128 ; i<SIZE ; k++ ,i+=2) {
            for (int j = 0, z=0 ; j<SIZE ; z++ ,j+=2) {
                for (int d = 0, y=0 ; d< RGB; y++,d++){
                    Image2[i][j][d] = Image[k][z][y];
                    Image2[i][j+1][d] = Image[k][z][y];
                    Image2[i+1][j][d] = Image[k][z][y];
                    Image2[i+1][j+1][d] = Image[k][z][y];
                }
            }
        }
    }

    if (opp == 4) {
        for (int i = 0, k=128 ; i<SIZE ; k++ ,i+=2) {
            for (int j = 0, z=128 ; j<SIZE ; z++ ,j+=2) {
                for (int d = 0, y=0 ; d< RGB; y++,d++){
                    Image2[i][j][d] = Image[k][z][y];
                    Image2[i][j+1][d] = Image[k][z][y];
                    Image2[i+1][j][d] = Image[k][z][y];
                    Image2[i+1][j+1][d] = Image[k][z][y];
                }
            }
        }
    }
}


// ----------------------------------------------------------------------------------- //
// Filter 9
void Shrink_1BY2_Image(){
    for (int i = 0; i < SIZE; i += 2){
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k< RGB; k++){
                Image[i/2][j/2][k] = Image[i][j][k];
                Image2[i][j][k] = Image[i/2][j/2][k];
            }
        }
    }
    for (int i = 127; i < SIZE; i ++){
        for (int j = 127; j < SIZE; j++){
            for (int k = 0; k< RGB; k++){
                Image[i][j][k] = 255;
            }
        }
    }
    for (int i = 0; i < SIZE; i ++){
        for (int j = 127; j < SIZE; j++){
            for (int k = 0; k< RGB; k++){
                Image[i][j][k] = 255;
            }
        }
    }
    for (int i = 127; i < SIZE; i ++){
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k< RGB; k++){
                Image[i][j][k] = 255;
            }
        }
    }
}
void Shrink_1BY3_Image(){
    for (int i = 0; i < SIZE; i += 2){
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k< RGB; k++){
                Image[i/3][j/3][k] = Image[i][j][k];
                Image2[i][j][k] = Image[i/3][j/3][k];
            }
        }
    }
    for (int i = 85; i < SIZE; i ++){
        for (int j = 85; j < SIZE; j++){
            for (int k = 0; k< RGB; k++){
                Image[i][j][k] = 255;
            }
        }
    }
    for (int i = 0; i < SIZE; i ++){
        for (int j = 85; j < SIZE; j++){
            for (int k = 0; k< RGB; k++){
                Image[i][j][k] = 255;
            }
        }
    }
    for (int i = 85; i < SIZE; i ++){
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k< RGB; k++){
                Image[i][j][k] = 255;
            }
        }
    }
}
void Shrink_1BY4_Image(){
    for (int i = 0; i < SIZE; i += 2){
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k< RGB; k++){
                Image[i/4][j/4][k] = Image[i][j][k];
                Image2[i][j][k] = Image[i/4][j/4][k];
            }
        }
    }
    for (int i = 64; i < SIZE; i ++){
        for (int j = 64; j < SIZE; j++){
            for (int k = 0; k< RGB; k++){
                Image[i][j][k] = 255;
            }
        }
    }
    for (int i = 0; i < SIZE; i ++){
        for (int j = 64; j < SIZE; j++){
            for (int k = 0; k< RGB; k++){
                Image[i][j][k] = 255;
            }
        }
    }
    for (int i = 64; i < SIZE; i ++){
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k< RGB; k++){
                Image[i][j][k] = 255;
            }
        }
    }
}


// ----------------------------------------------------------------------------------- //
// Filter a
void MirrorImage_Lower_1over2_a(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k< RGB; k++){
                Image[i][j][k] = Image[SIZE-i][j][k];
            }
        }
    }
}
void MirrorImage_Right_1over2_a(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k< RGB; k++){
                Image[i][j][k] = Image[i][SIZE-j][k];
            }
        }
    }
}
void MirrorImage_Left_1over2_a(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE/2; j < SIZE; j++) {
            for (int k = 0; k< RGB; k++){
                Image[i][j][k] = Image[i][256-j][k];
            }
        }
    }
}
void MirrorImage_Upper_1over2_a(){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k< RGB; k++){
                Image[SIZE-1-i][j][k]= Image[i][j][k];
            }
        }
    }
}


// ----------------------------------------------------------------------------------- //
// Filter b
void Shuffle_Image(){

    int order1;
    cout << "Enter The Number Of The First Quarter(only 1 number):";
    cin >> order1;

    if (order1 == 1) {
        for (int i=0,k=0;i<SIZE/2;k++,i++) {
            for (int j=0,z=0;j<SIZE/2;z++,j++) {
                for (int t=0,q=0;t<RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }
    else if (order1 == 2) {
        for (int i=0,k=0;i<SIZE/2;k++,i++) {
            for (int j=128,z=0;j<SIZE;z++,j++) {
                for (int t=0,q=0;t<RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }
    else if (order1 == 3) {
        for (int i=128,k=0;i<SIZE;k++,i++) {
            for (int j=0,z=0;j<SIZE/2;z++,j++) {
                for (int t=0,q=0;t< RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }
    else if (order1 == 4) {
        for (int i=128,k=0;i<SIZE;k++,i++) {
            for (int j=128,z=0;j<SIZE;z++,j++) {
                for (int t=0,q=0; t< RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }

    int order2;
    cout << "Enter The Number Of The second Quarter (only 1 number):";
    cin >> order2;

    if (order2 == 1) {
        for (int i=0,k=0;i<SIZE/2;k++,i++) {
            for (int j=0,z=128;j<SIZE/2;z++,j++) {
                for (int t=0,q=0; t< RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }
    else if (order2 == 2) {
        for (int i=0,k=0;i<SIZE/2;k++,i++) {
            for (int j=128,z=128;j<SIZE;z++,j++) {
                for (int t=0,q=0; t< RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }
    else if (order2 == 3) {
        for (int i=128,k=0;i<SIZE;k++,i++) {
            for (int j=0,z=128;j<SIZE/2;z++,j++) {
                for (int t=0,q=0; t< RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }
    else if (order2 == 4) {
        for (int i=128,k=0;i<SIZE;k++,i++) {
            for (int j=128,z=128;j<SIZE;z++,j++) {
                for (int t=0,q=0; t< RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }

    int order3;
    cout << "Enter The Number Of The third Quarter (only 1 number):";
    cin >> order3;

    if (order3 == 1) {
        for (int i=0,k=128;i<SIZE/2;k++,i++) {
            for (int j=0,z=0;j<SIZE/2;z++,j++) {
                for (int t=0,q=0; t< RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }
    else if (order3 == 2) {
        for (int i=0,k=128;i<SIZE/2;k++,i++) {
            for (int j=128,z=0;j<SIZE;z++,j++) {
                for (int t=0,q=0; t< RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }
    else if (order3 == 3) {
        for (int i=128,k=128;i<SIZE;k++,i++) {
            for (int j=0,z=0;j<SIZE/2;z++,j++) {
                for (int t=0,q=0; t< RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }
    else if (order3 == 4) {
        for (int i=128,k=128;i<SIZE;k++,i++) {
            for (int j=128,z=0;j<SIZE;z++,j++) {
                for (int t=0,q=0; t< RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }

    int order4;
    cout << "Enter The Number Of The Fourth Quarter (only 1 number):";
    cin >> order4;

    if (order4 == 1) {
        for (int i=0,k=128;i<SIZE/2;k++,i++) {
            for (int j=0,z=128;j<SIZE/2;z++,j++) {
                for (int t=0,q=0; t< RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }
    else if (order4 == 2) {
        for (int i=0,k=128;i<SIZE/2;k++,i++) {
            for (int j=128,z=128;j<SIZE;z++,j++) {
                for (int t=0,q=0; t< RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }
    else if (order4 == 3) {
        for (int i=128,k=128;i<SIZE;k++,i++) {
            for (int j=0,z=128;j<SIZE/2;z++,j++) {
                for (int t=0,q=0; t< RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }
    else if (order4 == 4) {
        for (int i=128,k=128;i<SIZE;k++,i++) {
            for (int j=128,z=128;j<SIZE;z++,j++) {
                for (int t=0,q=0; t< RGB;q++,t++){
                    Image2[k][z][q] = Image[i][j][t];
                }
            }
        }
    }
}


// ----------------------------------------------------------------------------------- //
// Filter c
void Blur_Image() {
    unsigned char temp[SIZE][SIZE][RGB];

    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            for (int k = 0; k < RGB; k++) {
                // Apply a simple 3x3 averaging filter
                int sum = Image[i - 1][j - 1][k] + Image[i - 1][j][k] + Image[i - 1][j + 1][k]
                          + Image[i][j - 1][k] + Image[i][j][k] + Image[i][j + 1][k]
                          + Image[i + 1][j - 1][k] + Image[i + 1][j][k] + Image[i + 1][j + 1][k];
                temp[i][j][k] = sum / 9; // Average the values
            }
        }
    }

    // Copy the blurred image back to the original image
    memcpy(Image, temp, sizeof(temp));
}





int main(){
    int Op_choice;
    cout<<"enter num :";
    cin>>Op_choice;
    switch (Op_choice) {
        case 1:
            InputImage();
            Black_White_Filter();
            OutputImage();
            break;
        case 2:
            InputImage();
            Invert_Filter();
            OutputImage();
            break;
        case 3:
            InputImage();
            InputImage2();
            MergeImages();
            OutputImage();
            break;
        case 4:
            InputImage();
            FlipImage();
            OutputImage();
            break;
        case 5:
            InputImage();
            RotateImage();
            OutputImage();
            break;
        case 6:
            InputImage();
            DarkenLightenImage();
            OutputImage();
            break;
        case 7:
            InputImage();
            DetectImageEdges();
            OutputImage();
            break;
        case 8:
            InputImage();
            Enlarge_Image();
            OutputImage2();
            break;
        case 9:
            int y1;
            cout<<"Enter (1) if you want to Shrink the image by 1/2.\nEnter (2) if you want to Shrink the image by 1/3.\nEnter (3) if you want to Shrink the image by 1/4.\nYour Choice :";
            cin>>y1;
            if(y1 == 1){
                InputImage();
                Shrink_1BY2_Image();
                OutputImage();
                break;
            }
            else if(y1 == 2){
                InputImage();
                Shrink_1BY3_Image();
                OutputImage();
                break;
            }
            else if(y1 == 3){
                InputImage();
                Shrink_1BY4_Image();
                OutputImage();
                break;
            }
        case 'a':
            int x1;
            cout<<"Enter (1) if you want to Mirror Image Left 1/2.\nEnter (2) if you want to Mirror Image Right 1/2.\nEnter (3) if you want to Mirror Image Upper 1/2.\nEnter (4) if you want to Mirror Image Lower 1/2.\nYour choice :";
            cin>> x1;
            if (x1 == 1) {
                InputImage();
                MirrorImage_Left_1over2_a();
                OutputImage();
                break;
            }
            else if(x1 == 2){
                InputImage();
                MirrorImage_Right_1over2_a();
                OutputImage();
                break;
            }
            else if(x1 ==3){
                InputImage();
                MirrorImage_Upper_1over2_a();
                OutputImage();
                break;
            }
            else if(x1 == 4){
                InputImage();
                MirrorImage_Lower_1over2_a();
                OutputImage();
                break;
            }
        case 'b':
            InputImage();
            Shuffle_Image();
            OutputImage2();
            break;
        case 'c':
            InputImage();
            Blur_Image();
            OutputImage();
            break;
        case 's':
            InputImage();
            OutputImage();
            break;
        case 0:
            return 0;
        default:
            cout<<"Wrong choice!!!\nChoose Again :";
            main();
    }
}
