/* Code to make the settings icon with all the different options given to it */
void drawSettingsPart()
{
   glPushMatrix(); 
   glTranslated(-7,3.5,0);
   drawRectangle(1,1,1);
   glPopMatrix();  
    /* Loading the settings icon as a image in the viewport */
   glPushMatrix();
   glTranslatef(-6.5,4,0);
   cobweb();
   glEnable(GL_TEXTURE_2D);
   glBindTexture ( GL_TEXTURE_2D, texture[2] );
   glDisable(GL_TEXTURE_2D);
   glPopMatrix();

    /* Code to display different settings options */
   if(onMouse == 1)
   {

    /* Code to add text at a given location with defined color and given text */
    glColor3f(0,0,1);
   glRasterPos3f(-6.8,3.1,0.1);
   string text1 = "View";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }


    /* Code to add text at a given location with defined color and given text */
   glColor3f(0,0,1);
   glRasterPos3f(-6.8,2.5,0.1);
   text1 = "Mode";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }


    /* Code to add text at a given location with defined color and given text */
   glColor3f(0,0,1);
   glRasterPos3f(-6.8,1.9,0.1);
   text1 = "Instructions";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }


    /* Code to add text at a given location with defined color and given text */
   glColor3f(0,0,1);
   glRasterPos3f(-6.8,1.3,0.1);
   text1 = "Objects";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

   glColor3f(0,0,1);
   glRasterPos3f(-6.8,0.7,0.1);
   text1 = "Wind Direction";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

   glColor3f(0,0,1);
   glRasterPos3f(-6.8,0.1,0.1);
   text1 = "Day/Night";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

    /* Code to make the background color for the first added text */
    //view
      glPushMatrix(); 
      glTranslated(-7,2.95,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();  


    /* Code to add the partition between the different texts */
    // view boundary
      glPushMatrix(); 
      glTranslated(-7,2.9,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();  
      
      //mode
      glPushMatrix(); 
      glTranslated(-7,2.35,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();  

      //mode boundary
      glPushMatrix(); 
      glTranslated(-7,2.3,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();  

      // instructions
      glPushMatrix(); 
      glTranslated(-7,1.75,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();  

      //instructions boundary
      glPushMatrix(); 
      glTranslated(-7,1.7,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();  

      // objects
      glPushMatrix(); 
      glTranslated(-7,1.15,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();  

      // objects boundary
      glPushMatrix(); 
      glTranslated(-7,1.10,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();

      // wind direction
      glPushMatrix(); 
      glTranslated(-7,0.55,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();  
 
      // wind direction boundary
      glPushMatrix(); 
      glTranslated(-7,0.50,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();

      // day/night
      glPushMatrix(); 
      glTranslated(-7,-0.05,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();
   
      // day/night boundary
      glPushMatrix(); 
      glTranslated(-7,-0.10,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();
   } 

   if(onMouse1 == 1)
   {
    glTranslatef(2,0,0);

   
    /* Code to add text at a given location with defined color and given text */
    glColor3f(0,0,1);
    glRasterPos3f(-6.7,3.1,0.1);
   string text1 = "Front View";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

    /* Code to add text at a given location with defined color and given text */
   glColor3f(0,0,1);
   glRasterPos3f(-6.7,2.5,0.1);
   text1 = "CloseUp View";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

    /* Code to add text at a given location with defined color and given text */
    glColor3f(0,0,1);
   glRasterPos3f(-6.7,1.9,0.1);
   text1 = "Left Side View";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

    /* Code to add text at a given location with defined color and given text */
   glColor3f(0,0,1);
   glRasterPos3f(-6.7,1.3,0.1);
   text1 = "Back View";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

    /* Code to add text at a given location with defined color and given text */
   glColor3f(0,0,1);
   glRasterPos3f(-6.7,0.7,0.1);
   text1 = "Top View";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

    /* Code to add text at a given location with defined color and given text */
   glColor3f(0,0,1);
   glRasterPos3f(-6.7,0.1,0.1);
   text1 = "Hill Side View";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }


    /* Adding the arrow defining which section comes to the right portion */
    glPushMatrix(); 
    glTranslatef(-7,3.3,0);
   glRotatef(-90,0,0,1);
   glScaled(0.1, 0.1, 0.1);
    drawTriangle(0,0,0);
   glPopMatrix();

    glTranslatef(0.13,0,0);
    /* Code to make the background color for the first added text */
// VIEW 1
    glPushMatrix(); 
      glTranslated(-7,2.95,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();  


    /* Code to add the partition between the different texts */
      glPushMatrix(); 
      glTranslated(-7,2.9,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();  
      
// VIEW 2
      glPushMatrix(); 
      glTranslated(-7,2.35,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();  

      glPushMatrix(); 
      glTranslated(-7,2.3,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();  

// VIEW 3
      glPushMatrix(); 
      glTranslated(-7,1.75,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();

      glPushMatrix(); 
      glTranslated(-7,1.7,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();  

// VIEW 4
      glPushMatrix(); 
      glTranslated(-7,1.15,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();

      glPushMatrix(); 
      glTranslated(-7,1.1,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();  

// VIEW 5
      glPushMatrix(); 
      glTranslated(-7,0.55,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();

      glPushMatrix(); 
      glTranslated(-7,0.50,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();  

// VIEW 6
      glPushMatrix(); 
      glTranslated(-7,-0.05,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();

    glTranslatef(-0.13,0,0);
      glTranslatef(-2,0,0);
   }

    if(onMouse2 == 1)
   {
    glTranslatef(2,0,0);

    /* Code to add text at a given location with defined color and given text */
    glColor3f(0,0,1);
    glRasterPos3f(-6.7,3.1,0.1);
   string text1 = "Manual";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

    /* Code to add text at a given location with defined color and given text */
   glColor3f(0,0,1);
   glRasterPos3f(-6.7,2.5,0.1);
   text1 = "Auto";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }
/* Adding the arrow defining which section comes to the right portion */
    glPushMatrix(); 
    glTranslatef(-7,2.7,0);
   glRotatef(-90,0,0,1);
   glScaled(0.1, 0.1, 0.1);
    drawTriangle(0,0,0);
   glPopMatrix();

    glTranslatef(0.13,0,0);
    /* Code to make the background color for the first added text */
    glPushMatrix(); 
      glTranslated(-7,2.95,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();  

      glPushMatrix(); 
      glTranslated(-7,2.9,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();  
      

      glPushMatrix(); 
      glTranslated(-7,2.35,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();  

    glTranslatef(-0.13,0,0);
      glTranslatef(-2,0,0);
   }

   if(onMouse3 == 1)
   {
        /* Adding top level text*/
        glColor3f(0,0,0);
        glRasterPos3f(-2.5,3.1,0.1);
        string text = "Instructions";
        for (int i = 0; i < text.length(); i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
        }


        /* Making an array of the text of different lines to be used later */
        vector<string> arr1,arr2;

        arr1.push_back("Press X");
        arr2.push_back("Rotate anti-clockwise about X-axis");
        arr1.push_back("Press x");
        arr2.push_back("Rotate clockwise about X-axis");
        arr1.push_back("Press Y");
        arr2.push_back("Rotate anti-clockwise about Y-axis");
        arr1.push_back("Press y");
        arr2.push_back("Rotate clockwise about Y-axis");
        arr1.push_back("Press Z");
        arr2.push_back("Rotate anti-clockwise about Z-axis");
        arr1.push_back("Press z");
        arr2.push_back("Rotate clockwise about Z-axis");
        

        arr1.push_back("Press <");
        arr2.push_back("Zoom in");
        arr1.push_back("Press >");
        arr2.push_back("Zoom out");


        arr1.push_back("Press B");
        arr2.push_back("Turn on Manual Mode");
        arr1.push_back("Press r");
        arr2.push_back("Blades diverge");
        arr1.push_back("Press R");
        arr2.push_back("Blades converge");
        arr1.push_back("Press A");
        arr2.push_back("Increase the rotation speed of blades");
        arr1.push_back("Press a");
        arr2.push_back("Decrease the rotation speed of blades");
        arr1.push_back("Press C");
        arr2.push_back("Rotation of Head of Windmill from left to right");
        arr1.push_back("Press c");
        arr2.push_back("Rotation of Head of Windmill from right to left");
        arr1.push_back("Press l");
        arr2.push_back("To view from next viewing angle");
        arr1.push_back("Press m");
        arr2.push_back("To view from previous viewing angle");

        arr1.push_back("Press f");
        arr2.push_back("To translate right");

        arr1.push_back("Press e");
        arr2.push_back("To translate left");
        
        arr1.push_back("Press g");
        arr2.push_back("To translate down");

      arr1.push_back("Press h");
      arr2.push_back("To translate up");

      arr1.push_back("Press j");
      arr2.push_back("To translate inwards");
      
      arr1.push_back("Press i");
      arr2.push_back("To translates outwards");

      arr1.push_back("Press n");
      arr2.push_back("To change the day/night mode");

        float y = 2.5;
        /* Looping around the text to display different lines */
        for(int i=0;i<arr1.size();i++)
        {
            glColor3f(0,0,1);
            glRasterPos3f(-4.5,y,0.1);
            string text1 = arr1[i];
            for (int i = 0; i < text1.length(); i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
            }


            glColor3f(0,0,1);
            glRasterPos3f(-3.5,y,0.1);
            text1 = ":";
            for (int i = 0; i < text1.length(); i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
            }

            glColor3f(0,0,1);
            glRasterPos3f(-3.1,y,0.1);
            text1 = arr2[i];
            for (int i = 0; i < text1.length(); i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
            }

            y -= 0.25;
        }
               
   }

   if(onMouse4 == 1)
   {
    glTranslatef(2,0,0);

    /* Code to add text at a given location with defined color and given text */
    glColor3f(0,0,1);
    glRasterPos3f(-6.7,3.1,0.1);
   string text1 = "Windmill";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

    /* Code to add text at a given location with defined color and given text */
   glColor3f(0,0,1);
   glRasterPos3f(-6.7,2.5,0.1);
   text1 = "House";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

    /* Code to add text at a given location with defined color and given text */
    glColor3f(0,0,1);
   glRasterPos3f(-6.7,1.9,0.1);
   text1 = "Transformer";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

    /* Code to add text at a given location with defined color and given text */
   glColor3f(0,0,1);
   glRasterPos3f(-6.7,1.3,0.1);
   text1 = "Background";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

   glColor3f(0,0,1);
   glRasterPos3f(-6.7,0.7,0.1);

   text1 = "Street Light and Road";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

/* Adding the arrow defining which section comes to the right portion */
    glPushMatrix(); 
    glTranslatef(-7,1.5,0);
   glRotatef(-90,0,0,1);
   glScaled(0.1, 0.1, 0.1);
    drawTriangle(0,0,0);
   glPopMatrix();

    glTranslatef(0.13,0,0);
    /* Code to make the background color for the first added text */
    glPushMatrix(); 
      glTranslated(-7,2.95,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();  

    /* Code to add the paritions between different texts*/
      glPushMatrix(); 
      glTranslated(-7,2.9,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();  
      

      glPushMatrix(); 
      glTranslated(-7,2.35,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();  

      glPushMatrix(); 
      glTranslated(-7,2.3,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();  


      glPushMatrix(); 
      glTranslated(-7,1.75,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();

      glPushMatrix(); 
      glTranslated(-7,1.7,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();  


      glPushMatrix(); 
      glTranslated(-7,1.15,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();

      glPushMatrix(); 
      glTranslated(-7,1.1,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix(); 

      glPushMatrix(); 
      glTranslated(-7,0.55,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();
      
      
    glTranslatef(-0.13,0,0);
      glTranslatef(-2,0,0);
   }

   if(onMouse5 == 1){

      glTranslatef(2,0,0);

      /* Code to add text at a given location with defined color and given text */
      glColor3f(0,0,1);
      glRasterPos3f(-6.7,1.3,0.1);
      string text1 = "Left To Right";
      for (int i = 0; i < text1.length(); i++)
      {
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
      }

      /* Code to add text at a given location with defined color and given text */
      glColor3f(0,0,1);
      glRasterPos3f(-6.7,0.7,0.1);
      text1 = "Right to Left";
      for (int i = 0; i < text1.length(); i++)
      {
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
      }
   /* Adding the arrow defining which section comes to the right portion */
      glPushMatrix(); 
      glTranslatef(-7,0.9,0);
      glRotatef(-90,0,0,1);
      glScaled(0.1, 0.1, 0.1);
      drawTriangle(0,0,0);
      glPopMatrix();

      glTranslatef(0.13,0,0);
      /* Code to make the background color for the first added text */
      glPushMatrix(); 
      glTranslated(-7,1.15,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();  


      glPushMatrix(); 
      glTranslated(-7,1.1,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();  
         

      glPushMatrix(); 
      glTranslated(-7,0.55,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();  

      glTranslatef(-0.13,0,0);
      glTranslatef(-2,0,0);

   }

   if(onMouse6 == 1){

      glTranslatef(2,0,0);

      /* Code to add text at a given location with defined color and given text */
      glColor3f(0,0,1);
      glRasterPos3f(-6.7,0.7,0.1);
      string text1 = "Night Mode";
      for (int i = 0; i < text1.length(); i++)
      {
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
      }

      /* Code to add text at a given location with defined color and given text */
      glColor3f(0,0,1);
      glRasterPos3f(-6.7,0.1,0.1);
      text1 = "Day Mode";
      for (int i = 0; i < text1.length(); i++)
      {
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
      }
   /* Adding the arrow defining which section comes to the right portion */
      glPushMatrix(); 
      glTranslatef(-7,0.27,0);
      glRotatef(-90,0,0,1);
      glScaled(0.1, 0.1, 0.1);
      drawTriangle(0,0,0);
      glPopMatrix();

      glTranslatef(0.13,0,0);
      /* Code to make the background color for the first added text */
      
      glPushMatrix(); 
      glTranslated(-7,0.55,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();

      glPushMatrix(); 
      glTranslated(-7,0.50,0);
      glScaled(2,0.05,1);
      drawRectangle(1,1,1);
      glPopMatrix();  

      glPushMatrix(); 
      glTranslated(-7,-0.05,0);
      glScaled(2,0.55,1);
      drawRectangle(1,1,0);
      glPopMatrix();  

      glTranslatef(-0.13,0,0);
      glTranslatef(-2,0,0);

   }
}

void drawVariables()
{
    glPushMatrix(); 
   glTranslated(4,3.5,0);
   glScaled(4,1,1);
   drawRectangle(0,0,0.1);
   glPopMatrix();  

    /* Code to add text at a given location with defined color and given text */
   glColor3f(0,1,0);
   glRasterPos3f(4.2,4.1,0);
   string text1 = "WindSpeed";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

   glColor3f(0,1,0);
   glRasterPos3f(6.0,4.1,0);
   text1 = ":";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

    /* Displaying the wind speed taking the variable and converting it into string */
   glColor3f(0,1,0);
   glRasterPos3f(6.2,4.1,0);
   text1 = to_string(varWindSpeed);
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

   glColor3f(0,1,0);
   glRasterPos3f(6.2+0.11*(text1.size()),4.1,0);
   text1 = "km/h";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

    /* Code to add text at a given location with defined color and given text */
   glColor3f(0,1,0);
   glRasterPos3f(4.2,3.7,0);
   text1 = "Energy Generated";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }
   
   glColor3f(0,1,0);
   glRasterPos3f(6.0,3.7,0);
   text1 = ":";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

    /* Displaying the total energy generated by all the windmills taking the variable and converting it into string */
   glColor3f(0,1,0);
   glRasterPos3f(6.2,3.7,0);
   text1 = to_string(varEnergyGenerated);
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

   glColor3f(0,1,0);
   glRasterPos3f(6.2+0.11*(text1.size()),3.7,0);
   text1 = "G Watts";
   for (int i = 0; i < text1.length(); i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
   }

}
