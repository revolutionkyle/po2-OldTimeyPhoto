#include"bitmap.h"
#include<vector>
#include<string>
using namespace std;
int main()
{
 Bitmap image;
 vector <vector <Pixel> > bmp;
 Pixel rgb;
 int average;
 string pictureLocation;
 char reset;
 string newName;

 do{ cout<< "Please insert the location of the file you would like to convert." << endl;
     cin>> pictureLocation;
 
     image.open(pictureLocation);

     bool validBmp = image.isImage();

     if(validBmp == true)
     {
        bmp = image.toPixelMatrix();
        for(int i =0; i < bmp.size(); i++)
        {   for(int j = 0; j<bmp[0].size(); j++)
            {   rgb = bmp[i][j];
                average = (rgb.red + rgb.blue + rgb.green)/3 ;
                rgb.red = average;
                rgb.blue = average;
                rgb.green = average;
                bmp[i][j] = rgb;
            }
        }
        image.fromPixelMatrix(bmp);
        cout << "What would you like to name your new image file? If you leave it blank it will be saved as OldTimey.bmp." << endl;
        cin >> newName;
        if(newName.size()==0)
        {image.save("OldTimey.bmp");
        }
        else
        {image.save(newName);
        }
    }
    else if(validBmp == false)
    { cout << "That isn't a picture! Please insert a new picture." << endl;
      reset = 'Y';
    }
    cout << "Would you like to insert another picture? Y/N" << endl;
    cin>> reset;
   } while(reset == 'Y'|| reset == 'y');
 return 0;
 }
 
