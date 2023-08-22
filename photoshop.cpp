// Program Name: PhotoShopProgram.cpp
// Last Modification Date: 20/4/2022
// Author : Amr Abd-Eltawab Ahmed 

#include "bmplib.cpp"
#include "bmplib.h"
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
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

// Function to get the image from the User
void InputImage2(){
   char InputImageName[98];

   // Get the Name of the image from the User
   cout << "Enter the name of the photo :";
   cin >> InputImageName;

   // Add .bmp to the name of the photo
   strcat(InputImageName, ".bmp");

   // Function from the library to load the photo
   readRGBBMP(InputImageName, Image2);
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


void Invert_Filter(){        
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k< RGB; k++){
                Image[i][j][k] = 255 - Image[i][j][k];
            }
        }
    }
}



void DetectImageEdges(){              
    cout<<"What do you want to convert the image to?\n1-Black and White Detected\n2-Colored Detected.\nYour choice :";
    int detect_x;\
    cin>>detect_x;
    if (detect_x == 1) {
        bool temp[SIZE][SIZE][RGB];
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
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int k = 0; k< RGB; k++){
                    temp[i][j][k]=Image[i][j][k];
                    if (Image [i][j+1][k]==0 && Image[i][j-1][k]==0 && Image[i+1][j][k]==0 && Image[i-1][j][k]==0 && Image[i+1][j+1][k]==0 && Image[i+1][j-1][k]==0 && Image[i-1][j+1][k]==0 && Image[i-1][j-1][k]==0){
                        temp[i][j][k]=true;
                    }
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int k = 0; k< RGB; k++){
                    if (temp[i][j][k]==1){
                        Image[i][j][k]=255;
                    }
                }
            }
        }
    }

    else if (detect_x == 2){
        bool temp[SIZE][SIZE][RGB];
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
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int k = 0; k< RGB; k++){
                    temp[i][j][k]=Image[i][j][k];
                    if (Image [i][j+1][k]==0 && Image[i][j-1][k]==0 && Image[i+1][j][k]==0 && Image[i-1][j][k]==0 && Image[i+1][j+1][k]==0 && Image[i+1][j-1][k]==0 && Image[i-1][j+1][k]==0 && Image[i-1][j-1][k]==0){
                        temp[i][j][k]=true;
                    }
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int k = 0; k< RGB; k++){
                    if (temp[i][j][k]==1){
                        Image[i][j][k]=255;
                    }
                }
            }
        }
    }
}




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



void Blur_Image(){              
    for (int i = 1; i < SIZE; i++) {
        for (int j = 1; j< SIZE; j++) {
            for (int k = 0; k< RGB; k++){
                Image[i][j][k] = (Image[i][j][k]+Image[i-1][j][k]+Image[i][j-1][k]+Image[i+1][j][k]+Image[i][j+1][k]+Image[i+1][j+1][k]+Image[i+1][j-1][k]+Image[i-1][j+1][k]+Image[i-1][j-1][k]+Image[i-2][j][k]+Image[i-2][j+1][k]+Image[i-2][j+2][k]+Image[i-2][j-1][k]+Image[i-2][j-2][k]+Image[i-2][j-2][k]+Image[i-1][j+2][k])/16;
            }
        }
    }
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
        DetectImageEdges();
        OutputImage();
        break;
    case 4:
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
    case 10:
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
        MirrorImage_Upper_1over2_a(); // Coming soon
        OutputImage();
        break;
        }
        else if(x1 == 4){
        InputImage();
        MirrorImage_Lower_1over2_a();
        OutputImage();
        break;
        }
    case 11:
        InputImage();
        Shuffle_Image();
        OutputImage2();
        break;
    case 12:
        InputImage();    // Done
        Blur_Image();
        OutputImage();
        break;
    default:
        cout<<"Wrong choice!!!\nChoose Again :";
        main();
    }
}
