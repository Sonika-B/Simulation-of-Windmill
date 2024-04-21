#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h> 
using namespace std;

#define PI 3.14159265359

/* Global variables */
char title[] = "Windmill Simulation";

//variable used for rotation of windmill blade
GLfloat angleBlade = 0.0f; 

//variables used for rotation for 360 degree view
GLfloat angleWindmill = 0.0f;
GLfloat angleWindmillX = 0.0f;
GLfloat angleWindmillY = 0.0f;
GLfloat angleWindmillZ = 0.0f;

//variables for windspeed and energy
float varWindSpeed = 0;
float varEnergyGenerated = 0;
float varChange = 0;


int angleRotateBlade1 = 0;
int angleRotateBlade2 = 0;
int angleRotateBlade3 = 0;
GLfloat windmillSpeed = 1;
GLfloat windmillSpeed1 = 0;

//variable defining autoMode and manual mode
GLfloat autoMode = 1;
GLint Xaxis = 0;
GLint Yaxis = 0;

int glowHouse = 0;
GLfloat scalefactor = 1.0f;
//the refresh display time interval
int refreshMills = 15;

int dir=1;

//variables used to keep track of mouse clicks
int onMouse=0;
int onMouse1=0;
int onMouse2=0;
int onMouse3=0;
int onMouse4=0;
int onMouse5 = 0;  // wind direction
int onMouse6 = 0; // day
int onMouse21=0;
int onMouse22=0;
int viewNumber = 0;
int totalViews = 6;

//variables for displaying individual objects
int enableWindmill = 0;
int enableHouse = 0;
int enableBackground = 0;
int enableTransformer = 0;
int enableComplete = 1;
int enableStreetLight=0;

int enableLeftRight = 0;
int enableRightLeft = 0;

int enableDay=1;
int enableNight=0 ;

GLfloat cloud_pos_x = -10.0f;
GLfloat cloud_pos_y = 5.0f;
GLfloat cloud_speed = 0.02f;
GLfloat cloud_size = 2.0f;
GLfloat cloud_r = 1.0f;
GLfloat cloud_g = 1.0f;
GLfloat cloud_b = 1.0f;
GLfloat cloud_alpha = 0.5f;
int cloud_num_circles = 5;
GLfloat cloud_circle_radius = 0.5f;

GLfloat cloud1=4.0f;
GLfloat cloud2=9.0f;
GLfloat cloud3=20.0f;

GLuint texture[7];

float currentX=0.0f;
float currentY=0.0f;
float currentZ=0.0f;

#define GRID_SIZE 500
#define GRID_SPACING 0.1

/*Include components from the respective files*/


//2-D matrix used to store heights at point x,z
vector <vector<float>> terrain(GRID_SIZE, vector<float>(GRID_SIZE));

GLfloat position[] = { 0.0, 0.0, 1.0, 0.0 };

// initializing the lighting conditions for both day and night mode
void initLighting()
{
   if(enableDay == 1){

      glEnable(GL_COLOR_MATERIAL);
      glEnable(GL_LIGHTING);
      //setting the ambient and diffuse component of the light
      GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };
      GLfloat diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
      GLfloat specular[] = { 0.0, 0.0, 0.0, 1.0 };
       GLfloat position[] = { 0.0, 0.0, 100.0, 0.0 };

      glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
      glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
      glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
      glLightfv(GL_LIGHT0, GL_POSITION, position);
      glEnable(GL_LIGHT0);

      GLfloat ambient1[] = { 0.2, 0.2, 0.2, 1.0 };
      GLfloat diffuse1[] = { 0.6, 0.6, 0.6, 1.0 };
      GLfloat specular1[] = { 0.0, 0.0, 0.0, 1.0 };
      GLfloat position1[] = { 1.0, 0.0, 0.0, 0.0 };

      glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
      glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
      glLightfv(GL_LIGHT1, GL_SPECULAR, specular1);
      glLightfv(GL_LIGHT1, GL_POSITION, position1);
    
      glEnable(GL_LIGHT1);
     
      GLfloat ambient2[] = { 0.2, 0.2, 0.2, 1.0 };
      GLfloat diffuse2[] = { 0.6, 0.6, 0.6, 1.0 };
      GLfloat specular2[] = { 0.0, 0.0, 0.0, 1.0 };
      GLfloat position2[] = { -1.0, 0.0, 0.0, 0.0 };

      glLightfv(GL_LIGHT2, GL_AMBIENT, ambient1);
      glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse1);
      glLightfv(GL_LIGHT2, GL_SPECULAR, specular1);
      glLightfv(GL_LIGHT2, GL_POSITION, position1);
       glEnable(GL_LIGHT2);
       glDisable(GL_LIGHT4);
       glDisable(GL_LIGHT2);


   }else if(enableNight == 1){
      glEnable(GL_COLOR_MATERIAL);
      
      glEnable(GL_LIGHTING);

      // Dim ambient light for night mode
      GLfloat ambient[] = { 0.1, 0.1, 0.1, 1.0 };
      GLfloat diffuse[] = { 0.5, 0.5, 0.5, 1.0 }; // Dim diffuse light
      GLfloat specular[] = { 0.0, 0.0, 0.0, 1.0 };

      // Disable other light sources
      glDisable(GL_LIGHT1);
      glDisable(GL_LIGHT2);
      glDisable(GL_LIGHT3);

      glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
      glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
      glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

      // Move the light to a suitable position for night mode
      GLfloat position[] = { 0.0, 0.0, 100.0, 0.0 };
      glLightfv(GL_LIGHT0, GL_POSITION, position);
      glEnable(GL_LIGHT0);     
   } 

}

// initializing the material properties
void initMaterial() {
    // Material properties
    GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat specular[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat shininess[] = { 0.5 };
   
    // Set material properties
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
}


// Function to change material properties of a surface
   void materialColor(float r, float g, float b)
   {
      if(enableDay == 1){

         GLfloat ambient[] = { static_cast<GLfloat>(min(r+0.0, 0.3)), static_cast<GLfloat>(min(g+0.0, 0.3)), static_cast<GLfloat>(min(b+0.0, 0.3)), 1.0 };
            if(r + min(r+0.0, 0.3) > 1){
               r = 1 - min(r+0.0, 0.3);
            }
            if(g + min(g+0.0, 0.3)> 1){
               g = 1 - min(g+0.0, 0.3);
            }
            if(b + min(b+0.0, 0.3)> 1){
               b = 1 - min(g+0.0, 0.3);
            }
            GLfloat diffuse[] = { r,g, b, 0.0 };
            GLfloat specular[] = { 0.0, 0.0, 0.0, 1.0 };
            GLfloat shininess[] = { 0.0 };

            glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
            glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

      }else if(enableNight){
      // Adjust the color for night mode
         GLfloat ambient[] = { static_cast<GLfloat>(r * 0.3), static_cast<GLfloat>(g * 0.3), static_cast<GLfloat>(b * 0.3), 1.0 };
         GLfloat diffuse[] = { r, g, b, 0.0 }; // Adjust the diffuse color
         GLfloat specular[] = { 0.0, 0.0, 0.0, 1.0 }; // No specular highlights in night mode
         GLfloat shininess[] = { 0.0 }; // No shininess in night mode

         // Apply material properties
         glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
         glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
         glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
         glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
      }
   
   }

//Include components from the respective files/

#include "Figure.cpp"
#include "Windmill.cpp"
#include "Transformer.cpp"
#include "House.cpp"
#include "Background.cpp"
#include "SOIL.h"

// specifing the textures
int LoadGLTextures(){
   if(enableDay == 1){

      texture[2] = SOIL_load_OGL_texture ( "settings.jpeg",SOIL_LOAD_AUTO, 
                                    SOIL_CREATE_NEW_ID,
                                    SOIL_FLAG_POWER_OF_TWO | 
                                    SOIL_FLAG_MIPMAPS |
                                    SOIL_FLAG_COMPRESS_TO_DXT);
         
         if(texture[0]==0 ){
            return false;
         }
         glBindTexture(GL_TEXTURE_2D, texture[0]);
         glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
         glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
         glEnable(GL_TEXTURE_2D);                // Enable Texture Mapping ( NEW )
         glShadeModel(GL_SMOOTH);                // Enable Smooth Shading
         glClearColor(1.0f, 1.0f, 1.0f, 1.0f);   // Black Background
         glClearDepth(1.0f);                     // Depth Buffer Setup
         glEnable(GL_DEPTH_TEST);                // Enables Depth Testing
         glDepthFunc(GL_LEQUAL);                 // The Type Of Depth Testing To Do
         glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Really Nice Perspective Calculations
         return true; // Return Success

   }else if(enableNight){
      texture[2] = SOIL_load_OGL_texture("settings.jpeg", SOIL_LOAD_AUTO,
                                        SOIL_CREATE_NEW_ID,
                                        SOIL_FLAG_POWER_OF_TWO |
                                        SOIL_FLAG_MIPMAPS |
                                        SOIL_FLAG_COMPRESS_TO_DXT);

      if (texture[2] == 0) {
         return false;
      }
      glBindTexture(GL_TEXTURE_2D, texture[2]);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      glEnable(GL_TEXTURE_2D);
      glShadeModel(GL_SMOOTH);
      return true;

   }
   return true;
}
// to place the settings icon
void cobweb(){
   if(enableDay == 1){

         glPushMatrix();
    
         glEnable(GL_TEXTURE_2D);
         glBindTexture ( GL_TEXTURE_2D, texture[2] );
         
         glScaled(0.5,0.5,0.5);
            glBegin(GL_QUADS);
                  glTexCoord2f(0.0f, 0.0f);    
                  glVertex3f(1,1,0.0);
                  glTexCoord2f(0.0f, 1.0f);         
                  glVertex3f(1,-1,0.0);
               glTexCoord2f(1.0f, 1.0f);      
                  glVertex3f(-1,-1,0.0);
            glTexCoord2f(1.0f, 0.0f);   
            glVertex3f(-1,1,0.0);
         glEnd();
         glDisable(GL_TEXTURE_2D);
         glPopMatrix();


   }else if(enableNight){

      glPushMatrix();
      glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, texture[2]);
      glScaled(0.5, 0.5, 0.5);

      // Apply material properties for night mode
      GLfloat ambient[] = { 0.1, 0.1, 0.1, 1.0 }; // Dark ambient color
      GLfloat diffuse[] = { 0.2, 0.2, 0.2, 1.0 }; // Dark diffuse color
      GLfloat specular[] = { 0.0, 0.0, 0.0, 1.0 }; // No specular highlights

      glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
      glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
      glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

      glBegin(GL_QUADS);
         glTexCoord2f(0.0f, 0.0f);    
         glVertex3f(1, 1, 0.0);
         glTexCoord2f(0.0f, 1.0f);         
         glVertex3f(1, -1, 0.0);
         glTexCoord2f(1.0f, 1.0f);      
         glVertex3f(-1, -1, 0.0);
         glTexCoord2f(1.0f, 0.0f);   
         glVertex3f(-1, 1, 0.0);
      glEnd();
      
      glDisable(GL_TEXTURE_2D);
      glPopMatrix();
   }
  
}

// initializing all the above functions
void initGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
   
    initLighting(); // Initialize lighting
    initMaterial(); // Initialize material properties
   
    LoadGLTextures();
   
    // Set background color
    if(enableDay == 1) {
       glClearColor(0.52f, 0.8f, 0.91f, 1.0f);   //morning background
    } else if(enableNight) {
       glClearColor(0.03f, 0.06f, 0.10f, 1.0f);  // Night background
    }
   
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}


/*function to handle key inputs*/
/* Making some customization with the different keys that will change the global variables as a functionality
of the Project */
void processNormalKeys(unsigned char key, int x, int y)
{
   if(key=='x')
   {
        angleWindmillX -= 1;
   }
   if(key=='X')
   {
        angleWindmillX += 1;
   }
   if(key=='y')
   {
        angleWindmillY -= 1;
   }
   if(key=='Y')
   {
        angleWindmillY += 1;
   }
   if(key=='z')
   {
        angleWindmillZ -= 1;
   }
   if(key=='Z')
   {
        angleWindmillZ += 1;
   }

   if (key == '<')
   {
      scalefactor += scalefactor/10;
   }
   if (key == '>')
   {
      scalefactor -= scalefactor/10;
   }
   if(key == 'A')
   {
      if(windmillSpeed<=45)
      windmillSpeed += windmillSpeed/10;
   }
   if(key == 'a')
   {
      windmillSpeed -= windmillSpeed/10;
   }
   if(key == 'C')
   {
      windmillSpeed1 += 1;
   }
   if(key == 'c')
   {
      windmillSpeed1 -= 1;
   }
   if(key == 'B')
   {
      autoMode = 1-autoMode;
   }
   if(key=='R')
   {
      angleRotateBlade1 += 1;
      angleRotateBlade2 += 1;
      angleRotateBlade3 += 1;
   }
   if(key=='r')
   {
      angleRotateBlade1 -= 1;
      angleRotateBlade2 -= 1;
      angleRotateBlade3 -= 1;
   }
   if(key=='l')
   {
      viewNumber = (viewNumber+1)%totalViews;
      angleWindmillX = 0;
      angleWindmillY = 0;
      angleWindmillZ = 0;
   }
   if(key=='m')
   {
      viewNumber = (viewNumber-1+totalViews)%totalViews;
      angleWindmillX = 0;
      angleWindmillY = 0;
      angleWindmillZ = 0;
   }
   if(key=='n'){
      enableDay=1-enableDay;
      enableNight=1-enableNight;
      initGL();
   }
   if(key=='d'){
      enableLeftRight=1-enableLeftRight;
      enableRightLeft=1-enableRightLeft;
   }
   if(key=='e'){ // MOVE LEFT
      currentX+=2.0f;
   }
   if(key=='f'){ // MOVE RIGHT
      currentX-=2.0F;
   }
   if(key=='g'){ // MOVE down
      currentY+=2.0f;
   }
   if(key=='h'){ // MOVE up
      currentY-=2.0F;
   }
   if(key=='i'){ // MOVE front
      currentZ+=2.0f;
   }
   if(key=='j'){ // MOVE back
      currentZ-=2.0F;
   }

   if(key == 's'){
      enableStreetLight = 1-enableStreetLight;
      enableComplete = 1-enableComplete;
   }
}

/*display function*/
#include "Settings.cpp"
// function to draw road
void drawRoad(){
   // road
      glPushMatrix(); 
      glTranslated(5.0f, -1.8f, -15.0f);
      glScaled(3.0, 1.0, 17.0);
      glRotatef(-120.0f, 1.0f, 0.0f, 0.0f);
      glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
      glRotatef(-30.0f, 0.0f, 1.0f, 0.0f);
      glRotatef(60.0f, 0.0f, 1.0f, 0.0f);
      drawRectangle(0, 0, 0);
      glPopMatrix();
      
      //road lines
      //from us 1
      glPushMatrix(); 
      glTranslatef(6.5,-1.8,-1);
      glRotatef(-90,0,0,1);
      glColor3f(1,1,1);
      draw_cylinder(0.08, 1.7,1, 1,1);
      glPopMatrix();
      
      //from us 2
      glPushMatrix(); 
      glTranslatef(6.5,-1.8,-4);
      glRotatef(-90,0,0,1);
      glColor3f(1,1,1);
      draw_cylinder(0.08, 1.7,1, 1,1);
      glPopMatrix();
      
      //from us 3
      glPushMatrix(); 
      glTranslatef(6.5,-1.8,-7);
      glRotatef(-90,0,0,1);
      draw_cylinder(0.08, 1.7,1,1,1 );
      glPopMatrix();
      
      //from us 4
      glPushMatrix(); 
      glTranslatef(6.5,-1.8,-10);
      glRotatef(-90,0,0,1);
      draw_cylinder(0.08, 1.7,1,1,1 );
      glPopMatrix();

       //from us 5
      glPushMatrix(); 
      glTranslatef(6.5,-1.8,-13);
      glRotatef(-90,0,0,1);
      draw_cylinder(0.08, 1.7,1,1,1 );
      glPopMatrix();

      //left main line
      glPushMatrix(); 
      glTranslatef(5.2,-1.8,-14.5);
      glRotatef(-90,0,0,1);
      draw_cylinder(0.03, 16.3,1,1,1 );
      glPopMatrix();

       //right main line
      glPushMatrix(); 
      glTranslatef(7.8,-1.8,-14.5);
      glRotatef(-90,0,0,1);
      draw_cylinder(0.04, 16.3,1,1,1 );
      glPopMatrix();

}
// function to draw street light
void drawStreetLight(){

      if(enableNight ){
         
         glEnable(GL_LIGHTING);

         // Define and enable a light source for the street light
         glEnable(GL_LIGHT4);

         // Position the light source at the location of the street light
         GLfloat streetLightPosition[] = { 6.55, -1.8, -6.5, 1.0 };
         glLightfv(GL_LIGHT4, GL_POSITION, streetLightPosition);

         // Set light properties
         // Set light properties for yellow light
      // Set light properties for light yellow light
       GLfloat darkYellowAmbient[] = {0.6, 0.6, 0.0, 1.0};   // Dark yellow ambient color
      GLfloat darkYellowDiffuse[] = {0.8, 0.8, 0.2, 1.0};   // Dark yellow diffuse color
      GLfloat darkYellowSpecular[] = {0.8, 0.8, 0.2, 1.0};  // Dark yellow specular color

      // Set light color to dark yellow
      glLightfv(GL_LIGHT4, GL_AMBIENT, darkYellowAmbient);
      glLightfv(GL_LIGHT4, GL_DIFFUSE, darkYellowDiffuse);
      glLightfv(GL_LIGHT4, GL_SPECULAR, darkYellowSpecular);



         GLfloat constantAttenuation = 0.3; // Adjust this value as needed
         GLfloat linearAttenuation = 0.1;   // Adjust this value as needed
         GLfloat quadraticAttenuation = 0.1; // Adjust this value as needed

         glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, constantAttenuation);
         glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, linearAttenuation);
         glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, quadraticAttenuation);
      }

       // street light
      //first line
      glPushMatrix();
      glTranslatef(6.85,-1.8,-5);
      glRotatef(-90,1,0,0);
      glTranslatef(1.3,1.0,0);
      draw_cylinder(0.08, 1.7, 0,0,0);
      glPopMatrix();

      //second line
       glPushMatrix();
      glTranslatef(6.85,-1.8,-5);
      glRotatef(-90,0,1,0);
      glTranslatef(-1,1.6,-1.5);

      draw_cylinder(0.05, 0.7, 0,0,0);
      glPopMatrix();

      //hemisphere 
    // Draw the street light
    glPushMatrix();
    glTranslatef(6.85, -1.8, -5);
    glRotatef(90, 1, 0, 0);
    glTranslatef(0.95, -1, -1.6);
    
    // You can draw the street light here, make sure it's lit up properly

      if(enableNight){
         glColor3f(1 , 1 ,0);

      }else{
         glColor3f(1 , 1 , 1);
      }
      drawHemisphere(0.15);
    
    glPopMatrix();
   }


/* Connecting all the wires from the windmill to the transformer and from the transformer to the house */
void drawWires()
{

   glPushMatrix(); 
      glTranslated(-8.5,-1.8,-7.0);
      glRotatef(90,0,1,0);
      draw_cylinder(0.02, 5.5 ,0,0,0);
      glPopMatrix();

   
   glPushMatrix(); 
      glTranslated(-10.0,-1.8,-5.0);
      glRotatef(90,0,1,0);
      draw_cylinder(0.02,7,0,0,0); //4 to 7
      glPopMatrix();

   glPushMatrix(); 
      glTranslated(-3.0,-1.8,-7.0);
      glRotatef(0,0,1,0);
      draw_cylinder(0.02,2,0,0,0);
      glPopMatrix();

   //ground to tower
   glPushMatrix(); 
      glTranslated(-3.0,-1.8,-7.0);
      glRotatef(63,0,0,1);
      glRotatef(90,0,1,0);
      draw_cylinder(0.02,2.62,0,0,0);
      glPopMatrix();
   
   //in tower
   glPushMatrix(); 
      glTranslated(-1.8,0.53,-7.0);
      glRotatef(90,0,1,0);
      draw_cylinder(0.02,13.9,0,0,0);
      glPopMatrix();

   //connecting the house
   glPushMatrix(); 
      glTranslated(0.1,0.53,-7.0);
      glRotatef(90,0,1,0);
      glRotatef(22,0,0,1);
      glRotatef(-50,0,1,0);
      draw_cylinder(0.02,5,0,0,0);
      glPopMatrix();

//connecting the second house 2-2

      glPushMatrix(); 
      glTranslated(12,0.53,-7.0);
      glRotatef(55,0,1,0);
      glRotatef(15,0,0,1);
      glRotatef(-85,0,1,0);
      draw_cylinder(0.02,7,0,0,0);
      glPopMatrix();
  
}


/* Main display function connecting all the functionalities together to obtain the final product */
void display()
{
   /* Defining the Wind Speed and the total energy genrated by the windmills to be displaying in the
   home screen */

   if(autoMode == 1)
   {
      varWindSpeed = windmillSpeed*10;
      varEnergyGenerated = 0.1*(varWindSpeed*1/3.6)*(varWindSpeed*1/3.6)*(varWindSpeed*1/3.6);
   }
   else
   {
      varWindSpeed = varChange*10;
      varEnergyGenerated += varWindSpeed*0.001;
      varChange = 0;
   }
   glEnable(GL_DEPTH_TEST);

   glMatrixMode(GL_PROJECTION);
   glMatrixMode(GL_MODELVIEW);                         // To operate on model-view matrix
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                // Reset the model-view matrix

   glTranslatef(0.0f, 0.0f, -7.0f); // Move right and into the screen
   glScalef(0.6, 0.6, 0.6);

   /* Displaying the settings part in the code */
   glDisable(GL_LIGHTING);
   drawSettingsPart();
   if(onMouse3 == 0 && enableComplete == 1)
   {
      drawVariables();
   }
   if(viewNumber == 0)
    {
      glEnable(GL_LIGHTING);
    }

   /* Displaying only windmill without anything in the background*/
   if(enableWindmill == 1 )
   {
      glScalef(scalefactor, scalefactor, scalefactor);
      glTranslatef(currentX,currentY,currentZ);
      glRotatef(angleWindmillX, 1.0f, 0.0f, 0.0f);
      glTranslatef(0,0,-3);
      glRotatef(angleWindmillY, 0.0f, 1.0f, 0.0f);
      glTranslatef(0,0,3);
      glRotatef(angleWindmillZ, 0.0f, 0.0f, 1.0f);

      glDisable(GL_LIGHTING);
      glPushMatrix();
      glEnable(GL_LIGHT4);
      glTranslatef(2,0,0);
      glScaled(2,2,2);
      drawWindmill(-1.0, 0.0, -1.0, 0.5, 0.5, 0.5);
      glPopMatrix();
      glEnable(GL_LIGHTING);
   }

   /* Displaying only house without anything in the background*/
   if(enableHouse == 1)
   {
      glScalef(scalefactor, scalefactor, scalefactor);
      glTranslatef(currentX,currentY,currentZ);
      glRotatef(angleWindmillX, 1.0f, 0.0f, 0.0f);
      glTranslatef(0,0,-3);
      glRotatef(angleWindmillY, 0.0f, 1.0f, 0.0f);
      glTranslatef(0,0,3);
      glRotatef(angleWindmillZ, 0.0f, 0.0f, 1.0f);

      glDisable(GL_LIGHTING);

      glPushMatrix(); 
      glTranslatef(-3,0,0);
      glScaled(3,3,3);
      drawHouse(2.0, 0.0, 0.0, 0.5, 0.5, 0.5);
      glPopMatrix();
      glEnable(GL_LIGHTING);
   }

   /* Displaying only transformer without anything in the background*/
   if(enableTransformer == 1)
   {
      glScalef(scalefactor, scalefactor, scalefactor);
      glTranslatef(currentX,currentY,currentZ);
      glRotatef(angleWindmillX, 1.0f, 0.0f, 0.0f);
      glTranslatef(0,0,-3);
      glRotatef(angleWindmillY, 0.0f, 1.0f, 0.0f);
      glTranslatef(0,0,3);
      glRotatef(angleWindmillZ, 0.0f, 0.0f, 1.0f);

      glDisable(GL_LIGHTING);
      glPushMatrix(); 
      glTranslatef(-3,-1,-7);
      glScaled(3,3,3);
      drawTransformer(2.0, 0.0, 0.0, 0.5, 0.5, 0.5, 0.05);
      glPopMatrix();
      glEnable(GL_LIGHTING);

      
   }

   /* Displaying only hills with the sun and clouds without anything in the background*/
   if(enableBackground == 1)
   {
      glScalef(scalefactor, scalefactor, scalefactor);
      glTranslatef(currentX,currentY,currentZ);
      glRotatef(angleWindmillX, 1.0f, 0.0f, 0.0f);
      glTranslatef(0,0,-3);
      glRotatef(angleWindmillY, 0.0f, 1.0f, 0.0f);
      glTranslatef(0,0,3);
      glRotatef(angleWindmillZ, 0.0f, 0.0f, 1.0f);

      glDisable(GL_LIGHTING);
      glPushMatrix(); 
      glTranslated(10,0,0);
      glRotatef(170,0,1,0);
      drawBackground();
      glPopMatrix();
      glEnable(GL_LIGHTING);
   }

   if (enableStreetLight == 1) {
    // Transformations for the street light
    glScalef(scalefactor, scalefactor, scalefactor);
    glTranslatef(currentX, currentY, currentZ);
    glRotatef(angleWindmillX, 1.0f, 0.0f, 0.0f);
    glTranslatef(0, 0, -3);
    glRotatef(angleWindmillY, 0.0f, 1.0f, 0.0f);
    glTranslatef(0, 0, 3);
    glRotatef(angleWindmillZ, 0.0f, 0.0f, 1.0f);

    // Save the current modelview matrix state
    glPushMatrix();

    // Set up the light source
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT5); // Enable light source 0

    // Define the position and properties of the light
    GLfloat lightPosition[] = {-25.0f, 3.0f, -7.0f, 1.0f}; // Position of the light
    GLfloat lightAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};     // Ambient light color
    GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};     // Diffuse light color
    GLfloat lightSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};    // Specular light color

    // Set light parameters
    glLightfv(GL_LIGHT5, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT5, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT5, GL_SPECULAR, lightSpecular);

    // Draw the street light
    glDisable(GL_LIGHTING);
      glPushMatrix(); 
    drawStreetLight();
    drawRoad();
      glTranslatef(-3,-1,-7);
      glScaled(3,3,3);
    // Restore the previous modelview matrix state
    glPopMatrix();
}

   /* Displaying all the objects together */
   if(onMouse3 == 0 && enableComplete == 1)
   {

      /* Defining the functionalities to rotate about axis and scaling and translating
       the complete scene or the viewport */
      glScalef(scalefactor, scalefactor, scalefactor);
      glTranslatef(currentX,currentY,currentZ);
      glRotatef(angleWindmillX, 1.0f, 0.0f, 0.0f);
      glTranslatef(0,0,-3);
      glRotatef(angleWindmillY, 0.0f, 1.0f, 0.0f);
      glTranslatef(0,0,3);
      glRotatef(angleWindmillZ, 0.0f, 0.0f, 1.0f);
      position[2] = position[2]*cos(angleWindmillX*3.14/180);
      glLightfv(GL_LIGHT0, GL_POSITION, position);


      /* Displaying the left close up view */
      if(viewNumber == 1)
      {
         gluLookAt(-3,0,-6, 4,1,-9, 0,1,0);
      }

      /* Displaying the left side view */
      if(viewNumber == 2)
      {
         float x = 0.9;
         glScalef(x, x, x);
         glRotatef(8, 1.0f, 0.0f, 0.0f);
         glTranslatef(0,0,-3);
         glRotatef(35, 0.0f, 1.0f, 0.0f);
         glTranslatef(0,0,3);
         glRotatef(0, 0.0f, 0.0f, 1.0f);
      }

      /* Displaying the back view */
      if(viewNumber == 3)
      {
         float x = 0.8;
         glScalef(x, x, x);
         glRotatef(25, 1.0f, 0.0f, 0.0f);
         glTranslatef(0,0,-3);
         glRotatef(155, 0.0f, 1.0f, 0.0f);
         glTranslatef(0,0,3);
         glRotatef(0, 0.0f, 0.0f, 1.0f);
      }

      /* Displaying the top view */
      if(viewNumber == 4)
      {
         gluLookAt(5,12,-10, 1,0,0, 0,1,0);
      }

      /* Displaying the right side view */
      if(viewNumber == 5)
      {
         float x = 1;
         glScalef(x, x, x);
         glRotatef(30, 1.0f, 0.0f, 0.0f);
         glTranslatef(0,0,-3);
         glRotatef(210, 0.0f, 1.0f, 0.0f);
         glTranslatef(0,0,3);
         glRotatef(0, 0.0f, 0.0f, 1.0f);
      }
      
      /* Function to call background object */
      glPushMatrix(); 
      glTranslated(10,0,0);
      glRotatef(170,0,1,0);

      if(enableRightLeft==1){
         dir=0;
         drawBackground();
       }else if(enableLeftRight==1){
         dir=1;
         drawBackground(); //1 indicates left to right
       }else{
         dir=1;
         drawBackground();
       }
      glPopMatrix();

      /* Function to call 3rd windmill object    leftmost-back*/
      glPushMatrix(); 
      glTranslatef(-5.5,-0.8,-6);
      drawWindmill(-3.0, 0.0, -1.0, 0.5, 0.5, 0.5);
      glPopMatrix();

      /* Function to call 4th windmill object */ //right-front
      glPushMatrix(); 
      glTranslatef(-5,-0.8,-6);
      drawWindmill(0.0, 0.0, 1.0, 0.5, 0.5, 0.5);
      glPopMatrix();


      glPushMatrix();  
      glTranslatef(-7,-0.8,-6);
      drawWindmill(-3.0, 0.0, 1.0, 0.5, 0.5, 0.5);
      glPopMatrix();

      /* Function to call house object */
      glPushMatrix(); 
      glTranslatef(2.85,-1.8,-5);
      glRotatef(-90,0,1,0);
      drawHouse2(2.0, 0.0, 0.0, 0.5, 0.5, 0.5);
      glPopMatrix();

      drawRoad();
     drawStreetLight();

      //front house 
      glPushMatrix(); 
      glTranslatef(8,-1.8,-3);
      glRotatef(-90,0,1,0);
      drawHouse(2.0, 0.0, 0.0, 0.5, 0.5, 0.5);
      glPopMatrix();


      /* Function to call transformer object */
      glPushMatrix(); 
      glTranslatef(-3,-1,-7);
      drawTransformer(2.0, 0.0, 0.0, 0.5, 0.5, 0.5, 0.05);
      glPopMatrix();

      glPushMatrix(); 
      glTranslatef(9,-1,-7);
      drawTransformer(2.0, 0.0, 0.0, 0.5, 0.5, 0.5, 0.05);
      glPopMatrix();

      /* Function to call Conecting wires in the Home screen */
      glPushMatrix(); 
      drawWires();
      glPopMatrix();

   }
   // Render a pyramid consists of 4 triangles
   glLoadIdentity(); // Reset the model-view matrix

   glutSwapBuffers(); // Swap the front and back frame buffers (double buffering)

   // Update the rotational angle after each refresh [NEW]
   /* Code to change the view in each frame 
   Rotating the windmill blades */
   if(autoMode==1){
      if(dir == 0){
         angleBlade -= windmillSpeed;
      }else{
         angleBlade += windmillSpeed;
      }
      
   }
   if(autoMode==1)glowHouse=1;
   else glowHouse=0;
}

/* Called back when timer expired [NEW] */
void timer(int value)
{
   glutPostRedisplay();                   // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height){
   // Compute aspect ratio of the new window
   if (height == 0)
      height = 1; // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
   glLoadIdentity();            // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/* Code to merge the Cursor to the Project */
/* It will detect the cursor movement and will provide the results to be used further in the code */
void motion(int x, int y) {
   /* Detecting the distance the cursor moves in the time interval */
   GLfloat dy = (y - Yaxis);
   GLfloat dx = (x - Xaxis);
   GLfloat difference = sqrt(dx * dx + dy * dy);


   Yaxis = y;
   Xaxis = x;

   /* If the mode is set to be manual then take the values from the above and define the variables 
   to define the windmill speed and total energy generated */
   varChange = 0;
   if(autoMode == 0)
   {
      if(dx<0) angleBlade += difference*0.9*-1;
      if(dx>=0) angleBlade += difference*0.9;
      if(difference>0)glowHouse=1;
      else glowHouse=0;
      varChange = (difference*0.9);
   }

   display();
}

// Actions for different mouse clicks
void mouseClicks(int button, int state, int x, int y) {
   // cout<<x<<" "<<y<<"\n";
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      //settings 
      if(x>=190 && x<=290 && y>=35 && y<=135)
      {
         onMouse = 1-onMouse;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5 = 0;
         onMouse6=0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
      } //view
      else if(x>=190 && x<=393 && y>=143 && y<=190 && onMouse==1)
      {
         onMouse1 = 1-onMouse1;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
      } //mode
      else if(x>=190 && x<=393 && y>=206 && y<=250 && onMouse==1)
      {
         onMouse2 = 1-onMouse2;
         onMouse1 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
      } //instructions
      else if(x>=190 && x<=393 && y>=265 && y<=320 && onMouse==1)
      {
         onMouse3 = 1;
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
      }//objects 
      else if(x>=190 && x<=393 && y>=332 && y<=384 && onMouse==1)
      {
         onMouse4 = 1 -onMouse4;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse5=0;
         onMouse6=0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
      }//winddirection
      else if(x>=190 && x<=393 && y>=392 && y<=444 && onMouse==1)
      {
         onMouse5 = 1 -onMouse5;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4=0;
         onMouse6=0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
      }//manual 
      else if(x>=413 && x<=617 && y>=145 && y<=188 && onMouse2==1)
      {
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         onMouse21 = 1;
         autoMode = 0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
      }//auto 
      else if(x>=413 && x<=617 && y>=206 && y<=253 && onMouse2==1)
      {
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         onMouse22 = 1;
         autoMode = 1;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
      }// view 1 
      else if(x>=413 && x<=617 && y>=145 && y<=188 && onMouse1==1)
      {
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         onMouse21 = 1;
         viewNumber = 0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
      }// view 2 
      else if(x>=413 && x<=617 && y>=206 && y<=253 && onMouse1==1)
      {
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         onMouse22 = 1;
         viewNumber = 1;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
      } // view 3 
      else if(x>=413 && x<=617 && y>=268 && y<=316 && onMouse1==1)
      {
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         onMouse22 = 1;
         viewNumber = 2;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
      }// view 4 
      else if(x>=413 && x<=617 && y>=333 && y<=382 && onMouse1==1)
      {
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         onMouse22 = 1;
         viewNumber = 3;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
      } // view 5 
      else if(x>=413 && x<=617 && y>=395 && y<=446 && onMouse1==1)
      {
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         onMouse22 = 1;
         viewNumber = 4;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
      } // view 6 
      else if(x>=413 && x<=617 && y>=455 && y<=508 && onMouse1==1)
      {
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         onMouse22 = 1;
         viewNumber = 5;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
      }else if(x>=413 && x<=617 && y>=145 && y<=188 && onMouse4==1)
      {
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableWindmill = 1;
         enableComplete = 0;
         enableStreetLight=0;
      }
      else if(x>=413 && x<=617 && y>=206 && y<=253 && onMouse4==1)
      {
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableHouse = 1;
         enableComplete = 0;
         enableStreetLight=0;
      }
      else if(x>=413 && x<=617 && y>=268 && y<=316 && onMouse4==1)
      {
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableTransformer = 1;
         enableComplete = 0;
         enableStreetLight=0;
      }
      else if(x>=413 && x<=617 && y>=333 && y<=382 && onMouse4==1)
      {  
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableBackground = 1;
         enableComplete = 0;
         enableStreetLight=0;
      
      }
      else if(x>=413 && x<=617 && y>=395 && y<=446 && onMouse4==1)
      {
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 0;
         enableStreetLight=1;
      }
      else if(x>=413 && x<=617 && y>=333 && y<=382 && onMouse5==1)
      {
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableWindmill = 0;
         enableComplete = 1;
         enableLeftRight = 1;
         enableRightLeft = 0;
         enableStreetLight=0;
      }
      else if(x>=413 && x<=617 && y>=395 && y<=446 && onMouse5==1)
      {
         onMouse = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         onMouse6=0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableLeftRight = 0;
         enableRightLeft = 1;
         enableStreetLight=0;
      }
      else if(x>=190 && x<=393 && y>=452 && y<=504 && onMouse==1)
      {
         onMouse6 = 1-onMouse6;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5 = 0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
      }
      else if(x>=413 && x<=617 && y>=395 && y<=446 && onMouse6==1)
      {
         onMouse = 0;
         onMouse6 = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5 = 0;
         enableDay=0;
         enableNight=1;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         enableStreetLight=0;
         initLighting();
         initMaterial();
         LoadGLTextures();
         cobweb();
         initGL();

      }
      else if(x>=413 && x<=617 && y>=455 && y<=508  && onMouse6==1)
      {

         onMouse = 0;
         onMouse6 = 0;
         onMouse1 = 0;
         onMouse2 = 0;
         onMouse3 = 0;
         onMouse4 = 0;
         onMouse5=0;
         enableDay=1;
         enableNight=0;
         enableWindmill = 0;
         enableHouse = 0;
         enableTransformer = 0;
         enableBackground = 0;
         enableComplete = 1;
         initLighting();
         initMaterial();
         LoadGLTextures();
         cobweb();
         initGL();

      }
      
    }
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char **argv)
{
   glutInit(&argc, argv);                         // Initialize GLUT
   // initStaticObjects();

   glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // Enable double buffered mode
   glutInitWindowSize(1000, 780);                  // Set the window's initial width & height
   glutInitWindowPosition(100, 100);                // Position the window's initial top-left corner
   glutCreateWindow(title);                       // Create window with the given title
   glutDisplayFunc(display);                      // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);                      // Register callback handler for window re-size event  
   glutMotionFunc(motion);
   glutKeyboardFunc(processNormalKeys);
   glutMouseFunc(mouseClicks);
   initGL();                   // Our own OpenGL initialization
   // includeBulb();
   initTerrain();
   glutTimerFunc(0, timer, 0); // First timer call immediately [NEW]
   glutMainLoop();             // Enter the infinite event-processing loop
   return 0;
}
