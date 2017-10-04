// Author: Kyle Hammer
#include<fstream>
#include"bitmap.h"
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
    bool isImage();
    // getting users input for a picture
    reset = 'Y';
    while(reset =='Y' || reset == 'y')
    {
        cout << "Please enter a picture location." << endl;
        cin >> pictureLocation;

        image.open(pictureLocation);
    

   // take users picture and translate it into a form that a computer can manipulate
        if(image.isImage()==1)
        { bmp = image.toPixelMatrix();
      
        cout << pictureLocation << " has been loaded. It is " << bmp[0].size() << "pixels wide and " << bmp.size() << "pixels high" << endl;

        }
        if(image.isImage()==0)
        {cout << "That is not an image! Please insert an image" << endl;
        reset =='Y';
        }
   // (extra) ask the user what particular type of color manipulation they want done


   // manipulate each pixel in the picture using a recursive process


   // save the new manipulated image as a picture file


  // ask the user if they want to input another picture to convert.
  cout << "Do you want to insert another image? Y/N " << endl;
  cin >> reset;
  }
  return 0;
}
