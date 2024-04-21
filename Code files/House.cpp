/*this file contains all functions related to drawing the house*/

//utility function to draw a rectangle with given color with side 1 and center at origin
void drawRectangle(float cx, float cy, float cz)
{
   glBegin(GL_QUADS);
   glColor3f(cx, cy, cz); // Green
   glVertex3f(0.0f, 0.0f, 0.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(1.0f, 1.0f, 0.0f);
   glVertex3f(1.0f, 0.0f, 0.0f);
   glEnd();
}

//utility function to draw a triangle with given color
void drawTriangle(float cx, float cy, float cz)
{
   glBegin(GL_TRIANGLES);
   glColor3f(cx, cy, cz); // Green
   glVertex3f(0.0f, 0.0f, 0.0f);
   glVertex3f(1.0f, 1.0f, 0.0f);
   glVertex3f(2.0f, 0.0f, 0.0f);
   glEnd();
}

//utility function to draw a cuboid
void drawCuboid()
{
   glTranslatef(-1,-1,0);
   
   // Front Face
   glPushMatrix();
   glTranslated(0.0f, 0.0f, 0.0f);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(0.65, 0.57, 0.46);
   glColor3f(0.0f, 1.0f, 0.0f);
   glPopMatrix();

   // Back Face
   glPushMatrix();
   glTranslated(0.0f, 0.0f, -2.0f);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(0.65, 0.57, 0.46);
   glColor3f(0.0f, 1.0f, 0.0f);
   glPopMatrix();

   // Top Face
   glPushMatrix();
   glTranslated(0.0f, 2.0f, 0.0f);
   glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(0.65, 0.57, 0.46);
   glColor3f(1.0f, 0.0f, 0.0f);
   glPopMatrix();

   // Bottom Face
   glPushMatrix();
   glTranslated(0.0f, 0.0f, 0.0f);
   glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(0.65, 0.57, 0.46);
   glPopMatrix();

   // Left Face
   glPushMatrix();
   glTranslated(0.0f, 0.0f, 0.0f);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   glScaled(2.0, 2.0, 2.0);
    glColor3f(0 , 1 , 0);   
   drawRectangle(0.65, 0.57, 0.46);
   glPopMatrix();

   // Right Face
   glPushMatrix();
   glTranslated(2.0f, 0.0f, 0.0f);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   glScaled(2.0, 2.0, 2.0);
   glColor3f(0 , 1 , 0);   
   drawRectangle(0.65, 0.57, 0.46);
   glPopMatrix();
}

// function to draw wire board in house
void drawWireBoard(float r, float g, float b)
{

   glTranslatef(-1,-1,0);

   // Front Face
   glPushMatrix();
   glTranslated(0.0f, 0.0f, 0.0f);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(r,g,b);
   glColor3f(r,g,b);
   glPopMatrix();

   // Back Face
   glPushMatrix();
   glTranslated(0.0f, 0.0f, -2.0f);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(r,g,b);
   glColor3f(r,g,b);
   glPopMatrix();

   // Top Face
   glPushMatrix();
   glTranslated(0.0f, 2.0f, 0.0f);
   glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(r,g,b);
   glColor3f(r,g,b);
   glPopMatrix();

   // Bottom Face
   glPushMatrix();
   glTranslated(0.0f, 0.0f, 0.0f);
   glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(r,g,b);
   glPopMatrix();

   // Left Face
   glPushMatrix();
   glTranslated(0.0f, 0.0f, 0.0f);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(r,g,b);
   glPopMatrix();

   // Right Face
   glPushMatrix();
   glTranslated(2.0f, 0.0f, 0.0f);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(r,g,b);
   glPopMatrix();


   glPushMatrix();
   glTranslated(2.0f, 1.4f, -1.0f);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   glScaled(2.0, 2.0, 2.0);
   if(glowHouse)glColor3f(1,1,0);
   else glColor3f(0,0,0);
   drawHemisphere(0.1);
   glPopMatrix();
}

//function to draw the roof of the house 
void drawRoof()
{

   glTranslatef(-1,-1,0);

   // Front Face
   glBegin(GL_TRIANGLES);
   if(enableDay==1){
      glColor3f(0.07,0.04,0.04);
   }
   else if(enableNight==1){
      glColor3f(0.21,0.13,0.13);
   }
   
   glVertex3f(0.0f, 0.0f, 0.0f);
   glVertex3f(1.0f, 1.0f, 0.0f);
   glVertex3f(2.0f, 0.0f, 0.0f);
   glEnd();

   // Back Face
   glBegin(GL_TRIANGLES);
  if(enableDay==1){
      glColor3f(0.07,0.04,0.04);
   }
   else if(enableNight==1){
      glColor3f(0.21,0.13,0.13);
   }
   glVertex3f(0.0f, 0.0f, -2.0f);
   glVertex3f(1.0f, 1.0f, -2.0f);
   glVertex3f(2.0f, 0.0f, -2.0f);
   glEnd();


   // Bottom Face
   glBegin(GL_QUADS);
   if(enableDay==1){
      glColor3f(0.07,0.04,0.04);
   }
   else if(enableNight==1){
      glColor3f(0.21,0.13,0.13);
   }
   glVertex3f(0.0f, 0.0f, -2.0f);
   glVertex3f(0.0f, 0.0f, 0.0f);
   glVertex3f(2.0f, 0.0f, 0.0f);
   glVertex3f(2.0f, 0.0f, -2.0f);
   glEnd();

   glBegin(GL_QUADS);
   if(enableDay==1){
      glColor3f(0.07,0.04,0.04);
   }
   else if(enableNight==1){
      glColor3f(0.21,0.13,0.13);
   }
   glVertex3f(0.0f, 0.0f, -2.0f);
   glVertex3f(0.0f, 0.0f, 0.0f);
   glVertex3f(1.0f, 1.0f, 0.0f);
   glVertex3f(1.0f, 1.0f, -2.0f);
   glEnd();

   glBegin(GL_QUADS);
  if(enableDay==1){
      glColor3f(0.07,0.04,0.04);
   }
   else if(enableNight==1){
      glColor3f(0.21,0.13,0.13);
   }
   glVertex3f(1.0f, 1.0f, -2.0f);
   glVertex3f(1.0f, 1.0f, 0.0f);
   glVertex3f(2.0f, 0.0f, 0.0f);
   glVertex3f(2.0f, 0.0f, -2.0f);
   glEnd();
}

//draws the door the of the house with given color
void drawDoor(float cx, float cy, float cz)
{
   glPushMatrix();
   glTranslated(-0.5f, -0.2f, 0.05f);
   glScaled(1.0, 1.5, 1.0);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   drawRectangle(0.25, 0.14, 0.02);
   glPopMatrix();

   glPushMatrix();
   glTranslated(-0.35f, 0.6f, 0.22f);
   glScaled(1.0, 1.5, 1.0);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   glColor3f(0,0,0);
   drawHemisphere(0.08);
   glPopMatrix();
   
   glPushMatrix();
   glTranslated(-0.35f, 0.6f, 0.22f);
   glScaled(1.0, 1.5, 1.0);
   glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
   glColor3f(0,0,0);
   drawHemisphere(0.08);
   glPopMatrix();

   glPushMatrix();
   glTranslated(-0.35f, 0.6f, 0.05f);
   glScaled(1.0, 1.5, 1.0);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   glColor3f(0,0,0);
   draw_cylinder(0.04, 0.1, 0,0,0);
   glPopMatrix();
}

//the window of house through which we see lights inside
void drawWindow()
{
   glPushMatrix();
   glTranslated(1.03f, 0.5f, -0.5f);
   glScaled(1.0, 1, 1.5);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   if(glowHouse==1){
      int r=0.03*varWindSpeed;
      if(r<0.2){
         drawRectangle(0.37, 0.36, 0.41);
      }
      else{
         drawRectangle(r,r,0);
      }
   }
   else drawRectangle(0,0,0);
   glPopMatrix();

   glPushMatrix();
   glTranslated(1.05f, 0.5f, -0.5f);
   glScaled(1.0, 1, 0.07);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   drawRectangle(0,0,0);
   glPopMatrix();

   glPushMatrix();
   glTranslated(1.05f, 0.5f, -1.2f);
   glScaled(1.0, 1, 0.07);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   drawRectangle(0,0,0);
   glPopMatrix();

   glPushMatrix();
   glTranslated(1.05f, 0.5f, -1.94f);
   glScaled(1.0, 1, 0.07);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   drawRectangle(0,0,0);
   glPopMatrix();

   glPushMatrix();
   glTranslated(1.05f, 0.5f, -0.5f);
   glScaled(1.0, 0.07, 1.5);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   drawRectangle(0,0,0);
   glPopMatrix();

   glPushMatrix();
   glTranslated(1.05f, 1.48f, -0.5f);
   glScaled(1.0, 0.07, 1.5);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   drawRectangle(0,0,0);
   glPopMatrix();

   glPushMatrix();
   glTranslated(1.05f, 1.0f, -0.5f);
   glScaled(1.0, 0.07, 1.5);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   drawRectangle(0,0,0);
   glPopMatrix();
}

//finally combining all above functions we construct our house here at x,y,z cordinate and of required scale
void drawHouse(float x, float y, float z, float sx, float sy, float sz)
{
   glTranslatef(x, y, z);
   glScalef(sx, sy, sz);
   glTranslated(0.0f, 0.0f, -0.5f);

   // walls of house modeled as the cuboid 
   glPushMatrix();
   glTranslated(0.0f, 1.0f, 0.0f);
   glScaled(1, 1.2, 1.3);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   drawCuboid();
   glPopMatrix();

   // Roof of the house
   glPushMatrix();
   glTranslated(0.0f, 3.2f, 0.2f);
   glScaled(1.5, 1.5, 1.5);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   drawRoof();
   glPopMatrix();

   // Door of the house
   glPushMatrix();
   glTranslated(0.0f, 0.0f, 0.0f);
   // glScaled(1.0, 1.5, 1.0);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   drawDoor(1,1,1);
   glPopMatrix();

   // Window
   glPushMatrix();
   glTranslated(0.0f, 0.0f, 0.0f);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   drawWindow();
   glPopMatrix();

   // Ceiling
   glPushMatrix();
   glTranslated(0.0f, 2.2f, 0.23f);
   // glScaled(1.0, 1.5, 1.0);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   if(glowHouse==1){
      int r=0.03*varWindSpeed;
      if(r<0.2){
         drawCircle(0.4,0.37, 0.36, 0.41);
      }
      else{
         drawCircle(0.4,r, r, 0.0);
      }
   }
   else drawCircle(0.4, 0,0,0);
   glPopMatrix();



   glPushMatrix();
   glTranslated(1.0f, 1.0f, -2.1f);
   glScaled(0.1, 0.2, 0.2);
   glColor3f(0,0,0);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   drawWireBoard(0,1,1);
   glPopMatrix();
      
}

// function to draw the second house door
void drawDoor2(float cx, float cy, float cz)
{
   glPushMatrix();
   glTranslated(-0.5f, -0.2f, 0.05f);
   glScaled(1.0, 1.5, 1.0);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   drawRectangle(0.25, 0.14, 0.02);
   glPopMatrix();

   glPushMatrix();
   glTranslated(-0.35f, 0.6f, -0.1f);
   glScaled(1.0, 1.5, 1.0);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   glColor3f(0,0,0);
   drawHemisphere(0.08);
   glPopMatrix();
   
   glPushMatrix();
   glTranslated(-0.35f, 0.6f, -0.1f);
   glScaled(1.0, 1.5, 1.0);
   glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
   glColor3f(0,0,0);
   drawHemisphere(0.08);
   glPopMatrix();

   glPushMatrix();
   glTranslated(-0.35f, 0.6f, -0.1f);
   glScaled(1.0, 1.5, 1.0);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   glColor3f(0,0,0);
   draw_cylinder(0.04, 0.1, 0,0,0);
   glPopMatrix();
}
// function to draw a cuboid
void drawCuboid2()
{
   glTranslatef(-1,-1,0);
   
   // Front Face
   glPushMatrix();
   glTranslated(0.0f, 0.0f, 0.0f);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(0, 0, 1);
   glColor3f(0.0f, 1.0f, 0.0f);
   glPopMatrix();

   // Back Face
   glPushMatrix();
   glTranslated(0.0f, 0.0f, -2.0f);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(0, 0, 1);
   glColor3f(0.0f, 1.0f, 0.0f);
   glPopMatrix();

   // Top Face
   glPushMatrix();
   glTranslated(0.0f, 2.0f, 0.0f);
   glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(0, 1, 0);
   glColor3f(1.0f, 0.0f, 0.0f);
   glPopMatrix();

   // Bottom Face
   glPushMatrix();
   glTranslated(0.0f, 0.0f, 0.0f);
   glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(0, 1, 0);
   glPopMatrix();

   // Left Face
   glPushMatrix();
   glTranslated(0.0f, 0.0f, 0.0f);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(1, 1, 1);
   glPopMatrix();

   // Right Face
   glPushMatrix();
   glTranslated(2.0f, 0.0f, 0.0f);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   glScaled(2.0, 2.0, 2.0);
   drawRectangle(1, 1, 1);
   glPopMatrix();
}

// function to draw second house
void drawHouse2(float x, float y, float z, float sx, float sy, float sz)
{
   glTranslatef(x, y, z);
   glScalef(sx, sy, sz);
   glTranslated(0.0f, 0.0f, -0.5f);

   // walls of house modeled as the cuboid 
   glPushMatrix();
   glTranslated(0.0f, 1.0f, 0.0f);
   glScaled(1, 1.2, 1.3);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   drawCuboid();
   glPopMatrix();

   // Roof of the house
   glPushMatrix();
   glTranslated(0.0f, 3.2f, 0.2f);
   glScaled(1.5, 1.5, 1.5);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   drawRoof();
   glPopMatrix();

   // Door of the house
   glPushMatrix();
   glTranslated(0.0f, 0.0f, -2.75f);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   drawDoor2(1,1,1);
   glPopMatrix();

   // Window
   glPushMatrix();
   glTranslated(0.0f, 0.0f, 0.0f);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   drawWindow();
   glPopMatrix();

   // Ceiling
   glPushMatrix();
   glTranslated(0.0f, 2.2f, -2.85f);
   // glScaled(1.0, 1.5, 1.0);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   if(glowHouse==1){
      int r=0.03*varWindSpeed;
      if(r<0.2){
         drawCircle(0.4,0.37, 0.36, 0.41);
      }
      else{
         drawCircle(0.4,r, r, 0.0);
      }
   }
   else drawCircle(0.4, 0.03*varWindSpeed,0.03*varWindSpeed,0);
   glPopMatrix();

   glPushMatrix();
   glTranslated(1.0f, 1.0f, -2.1f);
   glScaled(0.1, 0.2, 0.2);
   glColor3f(0,0,0);
   glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
   drawWireBoard(0,1,1);
   glPopMatrix();
      
}
