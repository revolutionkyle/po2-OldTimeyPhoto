#include"bitmap.h"
#include<vector>
#include<string>
#include<cmath>
using namespace std;
int const NUMCOLORS = 3;
int main()
{ //Variables that will be used to convert the image.
 Bitmap image;
 vector <vector <Pixel> > bmp;
 Pixel rgb;
 int average;
 string pictureLocation;
 char reset;
 string newName;

 do{ // Get users input for an image to convert.
     cout<< "Please insert the location of the file you would like to convert." << endl;
     cin>> pictureLocation;
 
     image.open(pictureLocation);
     //Test to see if what the user input is an image.
     bool validBmp = image.isImage();

     if(validBmp == true)
     {  //Covert image into a a matrix and begin looping through matrix.
        bmp = image.toPixelMatrix();
        for(int i =0; i < bmp.size(); i++)
        {   for(int j = 0; j<bmp[0].size(); j++)
            {   //Convert each pixel to black and white by averaging the color at each pixel.
                rgb = bmp[i][j];
                average = (rgb.red+rgb.blue+rgb.green)/NUMCOLORS; 
                rgb.red = average;
                rgb.blue = average;
                rgb.green = average;
                bmp[i][j] = rgb;
            }
        }
        //Covert matrix back into an image.
        image.fromPixelMatrix(bmp);
        //Ask the user for what they would like to name the file. (Extra)
        cout << "What would you like to name your new image file? Don't forget to put .bmp at the end of the file name!" << endl;
        cin >> newName;
        image.save(newName);
        //Ask the user if they want to input another image for converting.
        cout << "Would you like to insert another picture for converting into black and white? Y/N" << endl;
        cin >> reset;
    }
    //In case the user does not input a picture. (so the program doesn't crash)
    else if(validBmp == false)
    { cout << "That isn't a picture! Please insert a new picture." << endl;
      reset = 'Y';
    }
   } while(reset == 'Y'|| reset == 'y');
 return 0;
 }
 
