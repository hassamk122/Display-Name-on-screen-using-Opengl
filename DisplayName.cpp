//Must include these parameters in linkers : 
//-lopengl32
//-lglu32
//-lfreeglut
#include <windows.h>
#include <GL/glut.h>

void displayName(const char* text)
{
		glPushMatrix();      
    //          R   G    B  
    glColor3f(1.0, 1.0, 1.0);  //    1,1,1 for white    1,0,0 for red   0,1,0 for green
                               // 0,0,0 for black       0,0,1 for blue   1,1,0 for yellow
	 //  Set position for text   xAxis     yAxis    zAxis
                   glTranslatef(270.0f,   320.0f,   0 );    
      
//	 //   rotate on    angle  xAxis   yAxis   zAxis
               glRotatef(0,     0,     0,      1); 
    // scale on      xAxis   yAxis     zAxis
            glScalef(0.2f,    0.2f,    1.0f);
    // Loop to display the string
    while (*text) {
         glutStrokeCharacter(GLUT_STROKE_ROMAN , *text);
        text++;
    }
    
    glPopMatrix();
    
}

void drawSquare(){
	 //          R   G    B  
    glColor3f(1.0, 0.0, 0.0);  //    1,1,1 for white    1,0,0 for red   0,1,0 for green
                               // 0,0,0 for black       0,0,1 for blue   1,1,0 for yellow
                   
    glBegin(GL_QUADS); // To draw in background
      //            xaxis   y axis
        glVertex2f(100.0f, 100.0f);  // to change Bottom left
        glVertex2f(700.0f, 100.0f);  // to change Bottom right
        glVertex2f(700.0f, 550.0f);  //  to changeTop right
        glVertex2f(100.0f, 550.0f);  // to change Top left
    glEnd();              
                               
}
void render()
{
    glClear(GL_COLOR_BUFFER_BIT);    // Clear the screen
    drawSquare();
    // display function called
   displayName( "Muhammad Hassam");

   
     // make sure program runs smoothly and processed without delay
    glFlush();
}

void init()
{
	//to change background
    //            R    G    B    A                                                               Note : Turning A into 0.0 will make background transparent
    glClearColor(1.0, 1.0, 0.0, 1.0);  //    1,1,1,1 for white    1,0,0,1 for red   0,1,0,1 for green
                                    // 0,0,0,1 for black       0,0,1,1 for blue   1,1,0,1 for yellow
    //Changes made to the projection matrix affect how depth and perspective are calculated when rendering the scene.
    glMatrixMode(GL_PROJECTION);
    
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);  // Set the coordinate for rendering, i have it  same as screen in this case
}

int main(int argc, char** argv)
{
    // to run glut library
    glutInit(&argc, argv);
    
    // selects display mode single is used for drawing and double for animations   GLUT-RBG means color mode is rgb
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    // selects dimensions of window we are displaying on
    glutInitWindowSize(800, 600);
    
    // to display window title
    glutCreateWindow("Muhammad Hassam - Display Name Program");
    
    init();
    // using render function in glut 
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}

