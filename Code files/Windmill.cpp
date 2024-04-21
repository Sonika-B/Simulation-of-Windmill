/*This file contains code for the windmill structure*/

//this function creates a individual blade of windmill

void drawBlade_basic()
{
   glBegin(GL_TRIANGLES); 
   // Define vertices in counter-clockwise (CCW) order with normal pointing out

   // Front Left Top face of blade
   glColor3f(0.135f, 0.151f, 0.182f); // Green
   glVertex3f(0.0f, 0.0f, 0.0f);
   glVertex3f(0.2f, 0.2f, 0.0f);
   glVertex3f(0.2f, 0.0f, 0.2f);

   // Front Right Top face of blade
   glColor3f(0.135f, 0.151f, 0.182f); // Green
   glVertex3f(0.2f, 0.2f, 0.0f);
   glVertex3f(1.5f, 0.0f, 0.0f);
   glVertex3f(0.2f, 0.0f, 0.2f);

   // Front Right Bottom face of blade
   glColor3f(0.607f, 0.643f, 0.706f); // Yellow
   glVertex3f(0.2f, 0.0f, 0.2f);
   glVertex3f(1.5f, 0.0f, 0.0f);
   glVertex3f(0.2f, -0.2f, 0.0f);

   // Front Left Bottom face of blade
   glColor3f(0.607f, 0.643f, 0.706f); // Yellow
   glVertex3f(0.0f, 0.0f, 0.0f);
   glVertex3f(0.2f, 0.0f, 0.2f);
   glVertex3f(0.2f, -0.2f, 0.0f);

   // Back Left Top face of blade
  glColor3f(0.135f, 0.151f, 0.182f); // Red
   glVertex3f(0.0f, 0.0f, 0.0f);
   glVertex3f(0.2f, 0.2f, 0.0f);
   glVertex3f(0.2f, 0.0f, -0.2f);

   // Back Right Top face of blade
   glColor3f(0.135f, 0.151f, 0.182f); // Red
   glVertex3f(0.2f, 0.2f, 0.0f);
   glVertex3f(1.5f, 0.0f, 0.0f);
   glVertex3f(0.2f, 0.0f, -0.2f);

   // Back Right Bottom face of blade
   glColor3f(0.607f, 0.643f, 0.706f); // Blue
   glVertex3f(0.2f, 0.0f, -0.2f);
   glVertex3f(1.5f, 0.0f, 0.0f);
   glVertex3f(0.2f, -0.2f, 0.0f);

   // Back Left Bottom face of blade
   glColor3f(0.607f, 0.643f, 0.706f); // Blue
   glVertex3f(0.0f, 0.0f, 0.0f);
   glVertex3f(0.2f, 0.0f, -0.2f);
   glVertex3f(0.2f, -0.2f, 0.0f);
   glEnd(); 
}

//orients the raw drawn blade in proper position
void drawBlade()
{
   glPushMatrix();
   glTranslated(0.20f, 0.0f, 0.0f);
   glScalef(1.2f, 1.0f, 1.0f);
   drawBlade_basic();
   glPopMatrix();
}

//function to calculate the rotation angle of the windmill
int calculateRotationAngle(int angle)
{
   //angle should lie between 0 to 90
   angle%=90;
   if(angle<0)angle+=90; //if angle negative add 90
   if(angle>=0 && angle<=45)return angle;
   if(angle>=45 && angle<=90)return (45-(angle-45));
   return angle;
}

/*combine windmill parts to create the whole structure at co-ordinate x,y,z*/
void drawWindmill(float x, float y, float z, float sx, float sy, float sz )
{
   glTranslatef(x,y,z); 
   glScalef(sx, sy, sz);
   glRotatef(windmillSpeed1, 0, 1,0);
   glRotatef(180, 0.0f, 1.0f, 0.0f);
   glTranslated(0.0f, 0.0f, -0.5f);

   //drawing three blades and rotating them periodically using global variable angleBlade
   glPushMatrix(); 
   glTranslated(0.0f, 1.0f, 0.0f);
   glRotatef(angleBlade, 0.0f, 0.0f, 1.0f); 
   glRotatef(calculateRotationAngle(angleRotateBlade1), 0.0f, 1.0f, 0.0f);
   // glRotatef(angleBlade, 0.0f, 1.0f, 0.0f);
   drawBlade();
   glPopMatrix();

   glPushMatrix();
   glTranslated(0.0f, 1.0f, 0.0f);
   glRotatef(120.0f, 0.0f, 0.0f, 1.0f);
   glRotatef(angleBlade, 0.0f, 0.0f, 1.0f);
   glRotatef(calculateRotationAngle(angleRotateBlade2), 0.0f, 1.0f, 0.0f);
   drawBlade();
   glPopMatrix();

   glPushMatrix();
   glTranslated(0.0f, 1.0f, 0.0f);
   glRotatef(240.0f, 0.0f, 0.0f, 1.0f);
   glRotatef(angleBlade, 0.0f, 0.0f, 1.0f);
   glRotatef(calculateRotationAngle(angleRotateBlade3), 0.0f, 1.0f, 0.0f);
   drawBlade();
   glPopMatrix();

   //draw the axle
   glPushMatrix();
   glTranslatef(0.0f, 1.0f, 0.0f);
   glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
   glColor3f(0.36, 0.34, 0.34);
   drawHemisphere(0.2);
   glPopMatrix();

   //draw the energy tower modeled as a frustum
   glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.5f);
    draw_frustrum(0.1f, 0.4f, 3.0f, 0.37, 0.36, 0.41); 
    glPopMatrix();

   //drawing the base of the windmill
   
    // windmill cylinder 
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    draw_cylinder(0.2f, 1.0f, 0.12, 0.11, 0.11);
    glPopMatrix();


    //base ring 
    glPushMatrix();
    glTranslatef(0.0f, -1.8f, 0.5f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    draw_cylinder(0.6f, 0.2f, 0.735f, 0.751f, 0.7182f);
    glPopMatrix();


    //base 
    glPushMatrix();
    glTranslatef(0.0f, -1.9f, 0.5f);
    draw_frustrum(0.6f, 0.9f, 0.2f, 0.37, 0.36, 0.41);
    glPopMatrix();


}

