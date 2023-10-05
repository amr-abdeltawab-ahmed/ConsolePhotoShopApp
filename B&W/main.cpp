// Program Name: PhotoShopProgram.cpp
// Last Modification Date: 5/10/2023
// Author : Amr Abd-Eltawab Ahmed

#include "bmplib.cpp"
#include "bmplib.h"
#include <iostream>
#include <cmath>
#include <cstring>

unsigned char Image[SIZE][SIZE];
unsigned char Image2[SIZE][SIZE];

// Function to get the image from the User
void InputImage(){
    char InputImageName[98];

    // Get the Name of the image from the User
    cout << "Enter the name of the photo :";
    cin >> InputImageName;

    // Add .bmp to the name of the photo
    strcat(InputImageName, ".bmp");

    // Function from the library to load the photo
    readGSBMP(InputImageName, Image);
}
// Function to get the image from the User
void InputImage2(){
    char InputImageName[98];

    // Get the Name of the image from the User
    cout << "Enter the name of the photo :";
    cin >> InputImageName;

    // Add .bmp to the name of the photo
    strcat(InputImageName, ".bmp");

    // Function from the library to load the photo
    readGSBMP(InputImageName, Image2);
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
    writeGSBMP(InputImageName, Image);
}
void OutputImage2(){
    char InputImageName[98];

    // Get the Name of the image from the User
    cout << "Enter the name of the photo :";
    cin >> InputImageName;

    // Add .bmp to the name of the photo
    strcat(InputImageName, ".bmp");

    // Function from the library to Save the photo
    writeGSBMP(InputImageName, Image2);
}


// ----------------------------------------------------------------------------------- //
// Filter 1
void Black_White_Image1(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            if (Image[i][j] > 127)
                // Convert any pixel > the Pure Gray color to white
                Image[i][j] = 255;
            else
                // Convert any pixel < the Pure Gray color to Black
                Image[i][j] = 0;
        }
    }
}


// ---------------------------------------------------------------------------- //
// Filter 2
void Invert_Image2(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Image[i][j] = 255 - Image[i][j];
        }
    }
}


// ---------------------------------------------------------------------------- //
// Filter 3
void Merge_Image3(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Image[i][j] = (Image2[i][j] + Image[i][j])/2;
        }
    }
}


// ---------------------------------------------------------------------------- //
// Filter 4
void flip_Image4(){
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE; j++) {
            int draft = Image[i][j];
            Image[i][j] = Image[SIZE-i][j];
            Image[SIZE-i][j] = draft;
        }
    }
}


// ---------------------------------------------------------------------------- //
// Filter 5
void Rotate_Image90_5(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = i+1; j < SIZE; j++) {
            swap(Image[i][j], Image[j][i]);
        }
    }
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE; j++) {
            int draft2 = Image[i][j];
            Image[i][j] = Image[SIZE-i][j];
            Image[SIZE-i][j] = draft2;
        }
    }
}
void Rotate_Image180_5(){
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j< SIZE; j++) {
            int draft2 = Image[i][j];
            Image[i][j] = Image[SIZE-i][j];
            Image[SIZE-i][j] = draft2;
        }
    }

}
void Rotate_Image270_5(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = i+1; j < SIZE; j++) {
            swap(Image[i][j], Image[j][i]);
        }
    }

}


// ---------------------------------------------------------------------------- //
// Filter 6
void Darken_Image6(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Image[i][j] -= (Image[i][j]/2);
        }
    }

}
void Lighten_Image6(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            Image[i][j] = (Image[i][j] + 255 ) /2;
        }
    }
}


// ---------------------------------------------------------------------------- //
// Filter 7
void DetectImageEdges7(){
    for (int i = 0; i < SIZE; i += 2){
        for (int j = 0; j < SIZE; j++){
            if (Image[i][j] - Image[i+1][j] >= 80 ) {
                Image[i][j] = 0;
                Image[i+1][j] = 255;
            }
            else {
                Image[i][j] = 255;
                Image[i+1][j] = 255;
            }
        }
    }
}


// ---------------------------------------------------------------------------- //
// Filter 8
void Enlarge_Image8(){
    int opp;
    cout << "Which Quarter do you want to Enlarge?\nEnter Your Choice:";
    cin >> opp;
    if (opp == 1) {
        for (int i = 0, k=0 ; i<SIZE ; k++ ,i+=2) {
            for (int j = 0, z=0 ; j<SIZE ; z++ ,j+=2) {
                Image2[i][j] = Image[k][z];
                Image2[i+1][j] = Image[k][z];
                Image2[i][j+1] = Image[k][z];
                Image2[i+1][j+1] = Image[k][z];
            }
        }
    }
    if (opp == 2) {
        for (int i = 0, k=0 ; i<SIZE ; k++ ,i+=2) {
            for (int j = 0, z=128 ; j<SIZE ; z++ ,j+=2) {
                Image2[i][j] = Image[k][z];
                Image2[i+1][j] = Image[k][z];
                Image2[i][j+1] = Image[k][z];
                Image2[i+1][j+1] = Image[k][z];
            }
        }
    }
    if (opp == 3) {
        for (int i = 0, k=128 ; i<SIZE ; k++ ,i+=2) {
            for (int j = 0, z=0 ; j<SIZE ; z++ ,j+=2) {
                Image2[i][j] = Image[k][z];
                Image2[i+1][j] = Image[k][z];
                Image2[i][j+1] = Image[k][z];
                Image2[i+1][j+1] = Image[k][z];
            }
        }
    }
    if (opp == 4) {
        for (int i = 0, k=128 ; i<SIZE ; k++ ,i+=2) {
            for (int j = 0, z=128 ; j<SIZE ; z++ ,j+=2) {
                Image2[i][j] = Image[k][z];
                Image2[i+1][j] = Image[k][z];
                Image2[i][j+1] = Image[k][z];
                Image2[i+1][j+1] = Image[k][z];
            }
        }
    }

}


// ---------------------------------------------------------------------------- //
// Filter 9
void Shrink_1BY3_Image(){
    for (int i = 0; i < SIZE; i += 2){
        for (int j = 0; j < SIZE; j++){
            Image[i/3][j/3] = Image[i][j];
            Image2[i][j] = Image[i/3][j/3];
        }
    }
    for (int i = 85; i < SIZE; i ++){
        for (int j = 85; j < SIZE; j++){
            Image[i][j] = 255;
        }
    }
    for (int i = 0; i < SIZE; i ++){
        for (int j = 85; j < SIZE; j++){
            Image[i][j] = 255;
        }
    }
    for (int i = 85; i < SIZE; i ++){
        for (int j = 0; j < SIZE; j++){
            Image[i][j] = 255;
        }
    }
}
void Shrink_1BY2_Image(){
    for (int i = 0; i < SIZE; i += 2){
        for (int j = 0; j < SIZE; j++){
            Image[i/2][j/2] = Image[i][j];
            Image2[i][j] = Image[i/2][j/2];
        }
    }
    for (int i = 127; i < SIZE; i ++){
        for (int j = 127; j < SIZE; j++){
            Image[i][j] = 255;
        }
    }
    for (int i = 0; i < SIZE; i ++){
        for (int j = 127; j < SIZE; j++){
            Image[i][j] = 255;
        }
    }
    for (int i = 127; i < SIZE; i ++){
        for (int j = 0; j < SIZE; j++){
            Image[i][j] = 255;
        }
    }
}
void Shrink_1BY4_Image(){
    for (int i = 0; i < SIZE; i += 2){
        for (int j = 0; j < SIZE; j++){
            Image[i/4][j/4] = Image[i][j];
            Image2[i][j] = Image[i/4][j/4];
        }
    }
    for (int i = 64; i < SIZE; i ++){
        for (int j = 64; j < SIZE; j++){
            Image[i][j] = 255;
        }
    }
    for (int i = 0; i < SIZE; i ++){
        for (int j = 64; j < SIZE; j++){
            Image[i][j] = 255;
        }
    }
    for (int i = 64; i < SIZE; i ++){
        for (int j = 0; j < SIZE; j++){
            Image[i][j] = 255;
        }
    }
}


// ---------------------------------------------------------------------------- //
// Filter a
void Mirror_Image10() {
    char mirrorChoice;
    cout << "Mirror Options: (L)eft 1/2, (R)ight 1/2, (U)pper 1/2, (D)lower 1/2\nEnter Your Choice (L/R/U/D): ";
    cin >> mirrorChoice;

    if (mirrorChoice == 'L' || mirrorChoice == 'l') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                Image[i][SIZE - 1 - j] = Image[i][j];
            }
        }
    } else if (mirrorChoice == 'R' || mirrorChoice == 'r') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                Image[i][j] = Image[i][SIZE - 1 - j];
            }
        }
    } else if (mirrorChoice == 'U' || mirrorChoice == 'u') {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                Image[SIZE - 1 - i][j] = Image[i][j];
            }
        }
    } else if (mirrorChoice == 'D' || mirrorChoice == 'd') {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                Image[i][j] = Image[SIZE - 1 - i][j];
            }
        }
    } else {
        cout << "Invalid choice. Choose either (L/R/U/D)." << endl;
    }
}


// ---------------------------------------------------------------------------- //
// Filter b
void Shuffle_Image(){
    int order1;
    cout << "Enter The Number Of The First Quarter (only 1 number):";
    cin >> order1;

    if (order1 == 1) {
        for (int i=0,k=0;i<SIZE/2;k++,i++) {
            for (int j=0,z=0;j<SIZE/2;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }
    }
    else if (order1 == 2) {
        for (int i=0,k=0;i<SIZE/2;k++,i++) {
            for (int j=128,z=0;j<SIZE;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }

    }
    else if (order1 == 3) {
        for (int i=128,k=0;i<SIZE;k++,i++) {
            for (int j=0,z=0;j<SIZE/2;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }
    }
    else if (order1 == 4) {
        for (int i=128,k=0;i<SIZE;k++,i++) {
            for (int j=128,z=0;j<SIZE;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }
    }
    int order2;
    cout << "Enter The Number Of The Second Quarter (only 1 number):";
    cin >> order2;
    if (order2 == 1) {
        for (int i=0,k=0;i<SIZE/2;k++,i++) {
            for (int j=0,z=128;j<SIZE/2;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }
    }
    else if (order2 == 2) {
        for (int i=0,k=0;i<SIZE/2;k++,i++) {
            for (int j=128,z=128;j<SIZE;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }
    }
    else if (order2 == 3) {
        for (int i=128,k=0;i<SIZE;k++,i++) {
            for (int j=0,z=128;j<SIZE/2;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }
    }
    else if (order2 == 4) {
        for (int i=128,k=0;i<SIZE;k++,i++) {
            for (int j=128,z=128;j<SIZE;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }
    }
    int order3;
    cout << "Enter The Number Of The Third Quarter (only 1 number):";
    cin >> order3;
    if (order3 == 1) {
        for (int i=0,k=128;i<SIZE/2;k++,i++) {
            for (int j=0,z=0;j<SIZE/2;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }
    }
    else if (order3 == 2) {
        for (int i=0,k=128;i<SIZE/2;k++,i++) {
            for (int j=128,z=0;j<SIZE;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }
    }
    else if (order3 == 3) {
        for (int i=128,k=128;i<SIZE;k++,i++) {
            for (int j=0,z=0;j<SIZE/2;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }
    }
    else if (order3 == 4) {
        for (int i=128,k=128;i<SIZE;k++,i++) {
            for (int j=128,z=0;j<SIZE;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }
    }
    int order4;
    cout << "Enter The Number Of The Fourth Quarter (only 1 number):";
    cin >> order4;
    if (order4 == 1) {
        for (int i=0,k=128;i<SIZE/2;k++,i++) {
            for (int j=0,z=128;j<SIZE/2;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }
    }
    else if (order4 == 2) {
        for (int i=0,k=128;i<SIZE/2;k++,i++) {
            for (int j=128,z=128;j<SIZE;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }
    }
    else if (order4 == 3) {
        for (int i=128,k=128;i<SIZE;k++,i++) {
            for (int j=0,z=128;j<SIZE/2;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }
    }
    else if (order4 == 4) {
        for (int i=128,k=128;i<SIZE;k++,i++) {
            for (int j=128,z=128;j<SIZE;z++,j++) {
                Image2[k][z] = Image[i][j];
            }
        }
    }

}


// ---------------------------------------------------------------------------- //
// Filter c
void Blur_Image12() {
    unsigned char TempImage[SIZE][SIZE];
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            int sum = 0;
            // Calculate the average value in a 3x3 neighborhood
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    sum += Image[i + k][j + l];
                }
            }
            TempImage[i][j] = static_cast<unsigned char>(sum / 9);
        }
    }
    // Copy the blurred image back to the original
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            Image[i][j] = TempImage[i][j];
        }
    }
}


// ---------------------------------------------------------------------------- //
// Main Func
int main(){

    int Op_choice;
    cout<<"1- Black & White Filter\n2- Invert Filter\n3- Merge Filter\n4- Flip Image\n5- Rotate Image\n6- Darken and Lighten Image\n7- Detect Image Edges\n8- Enlarge Image\n9- Shrink Image\na- Mirror 1/2 Image\nb- Shuffle Image\nc- Blur Image\ns- Save the image to a file\n0- Exit.\nPlease select a filter to apply or 0 to exit :";
    cin>>Op_choice;

    switch (Op_choice)
    {
        case 1:
            InputImage();
            Black_White_Image1();
            OutputImage();
            break;
        case 2:
            InputImage();
            Invert_Image2();
            OutputImage();
            break;
        case 3:
            InputImage();
            InputImage2();
            Merge_Image3();
            OutputImage();
            break;
        case 4:
            InputImage();
            flip_Image4();
            OutputImage();
            break;
        case 5:
            int x;
            cout<<"Enter (1) if you want to Rotate the image by 90.\nEnter (2) if you want to Rotate the image by 180.\nEnter (3) if you want to Rotate the image by 270.\nYour Choice :";
            cin>>x;
            if(x == 1){
                InputImage();
                Rotate_Image90_5();
                OutputImage();
                break;
            }
            else if(x == 2){
                InputImage();
                Rotate_Image180_5();
                OutputImage();
                break;
            }
            else if(x == 3){
                InputImage();
                Rotate_Image270_5();
                OutputImage();
                break;
            }
            break;
        case 6:
            int z;
            cout<<"Enter (1) if you wants to Darken the photo by 50%.\nEnter (2) if you want to Lighten the photo by 50%.\nYour choice :";
            cin>>z;
            if(z == 1){
                InputImage();
                Darken_Image6();
                OutputImage();
                break;
            }
            else if (z == 2){
                InputImage();
                Lighten_Image6();
                OutputImage();
                break;
            }
            break;
        case 7:
            InputImage();
            DetectImageEdges7();
            OutputImage();
            break;
        case 8:
            InputImage();
            Enlarge_Image8();
            OutputImage2();
            break;
        case 9:
            int y;
            cout<<"Enter (1) if you want to Shrink the image by 1/2.\nEnter (2) if you want to Shrink the image by 1/3.\nEnter (3) if you want to Shrink the image by 1/4.\nYour Choice :";
            cin>>y;
            if(y == 1){
                InputImage();
                Shrink_1BY2_Image();
                OutputImage();
                break;
            }
            else if(y == 2){
                InputImage();
                Shrink_1BY3_Image();
                OutputImage();
                break;
            }
            else if(y == 3){
                InputImage();
                Shrink_1BY4_Image();
                OutputImage();
                break;
            }
            break;
        case 'a':
            InputImage();
            Mirror_Image10();
            OutputImage();
            break;
        case 'b':
            InputImage();
            Shuffle_Image();
            OutputImage2();
            break;
        case 'c':
            InputImage();
            Blur_Image12();
            OutputImage();
            break;
        case 's':
            InputImage();
            OutputImage();
            break;
        case 0:
            return 0;
        default:
            cout<<"Wrong choice!!!\n~~Choose Agin~~\n";
            main();
    }
}
