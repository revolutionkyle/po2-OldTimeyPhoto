// Author: Kyle Hammer
#include<fstream>
#include<"bitmap.h"
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{  // variable declaration for the program
    
    string pictureLocation;
    char reset;
    Bitmap image;
    vector <vector <Pixel> > bmp;
    Pixel rgb;

    // getting users input for a picture
    do while(reset=='Y'||reset=='y')
    cout << "please include an image file." << endl;
    cin >> pictureLocation;
    image.open(pictureLocation);
    bmp = image.toPixelMatrix();


   // take users picture and translate it into a form that a computer can manipulate


   // (extra) ask the user what particular type of color manipulation they want done


   // manipulate each pixel in the picture using a recursive process


   // save the new manipulated image as a picture file


  // ask the user if they want to input another picture to convert. 
  return 0;
}
