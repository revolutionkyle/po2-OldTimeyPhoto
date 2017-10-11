// Author: Kyle Hammer
#include<fstream>
#include"bitmap.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int NUMC = 3; // Number of available colors for each of the pixels. Can be changed if you somehow get one of those crazy 4 color TV's
int main()
{  // variable declaration for the program
    
    string pictureLocation;
    char reset;
    Bitmap image;
    vector <vector <Pixel> > bmp;
    Pixel rgb;
    bool isImage();
    int average;
    // getting users input for a picture
    reset = 'Y';
    while(reset =='Y' || reset == 'y')
    {
        cout << "Please enter a picture location." << endl;
        cin >> pictureLocation;

        image.open(pictureLocation);
    

   // take users picture and translate it into a form that a computer can manipulate
        if(image.isImage()==1)
        {   bmp = image.toPixelMatrix();
            // Find the average color and then set each color value to the average
            for(int i = 0;i<bmp.size();i++)
            {   for(int j =0;j<bmp[0].size();j++)
                {
                    rgb = bmp[i][j];
                    average = rgb.red + rgb.blue + rgb.green % NUMC; 
                    rgb.red = average;
                    rgb.blue = average;
                    rgb.green = average;
                    bmp[i][j] = rgb;
                 }
             }
         }
         // Convert the matrix back into an image file and save the file
         image.fromPixelMatrix(bmp);
         image.save("OldTimey.bmp");

     
        if(image.isImage()==0)
        {cout << "That is not an image! Please insert an image" << endl;
        reset =='Y';
        }

  // ask the user if they want to input another picture to convert.
  cout << "Do you want to insert another image? Y/N " << endl;
  cin >> reset;
  }
  return 0;
}
