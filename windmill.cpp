/*                         
SMINIPROJECT TITLE:spreading awareness about wind energy through animation
CODE :
*/

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
GLfloat WHITE[] = {1, 1, 1};
GLfloat bl[] = {0, 0, 0.7};
GLfloat GREEN[] = {0.5, 1, 0.5};
GLfloat MAGENTA[] = {0.91, 0.73, 0.65};

GLfloat black[] = {0, 0, 0};
GLfloat sand[] = {0.3, 0.9, 0.3};
GLfloat s[] = {0.9, 0.91, 0.18};
GLfloat g[] = {0.5, 0.51, 0.598};

GLfloat y[] = {1, 1, 0};


class Camera {
  double theta;     
  double y;         
  double dTheta;     
  double dy;         
public:
  Camera(): theta(0), y(3), dTheta(0.04), dy(0.2) {}
  double getX() {return 10 * cos(theta);}
  double getY() {return y;}
  double getZ() {return 10 * sin(theta);}
  void moveRight() {theta += dTheta;}
  void moveLeft() {theta -= dTheta;}
  void moveUp() {y += dy;}
  void moveDown() {if (y > dy) y -= dy;}
};
class Checkerboard {
  int displayListId;
  int width;
  int depth;
public:
  Checkerboard(int width, int depth): width(width), depth(depth) {}
  double centerx() {return width / 2;}
  double centerz() {return depth / 2;}
  void create() {
    displayListId = glGenLists(1);
    glNewList(displayListId, GL_COMPILE);
   GLfloat lightPosition[] = {4, 3, 7, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glBegin(GL_QUADS);
    glNormal3d(0, 1, 0);
        
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, sand);
    for (int x = 0; x < width - 1; x++) {
      for (int z = 0; z < depth - 1; z++) {
        glVertex3d(x, 0, z);
        glVertex3d(x+1, 0, z);
        glVertex3d(x+1, 0, z+1);
        glVertex3d(x, 0, z+1);
      }
    }
    glEnd();
    glEndList();
  }
  void draw() {
    glCallList(displayListId);
  }
};

Checkerboard checkerboard(8, 8);
Camera camera;


int frameNumber = 0;


void drawWindmill() {
	int i;
	
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,s);
	glRotated(frameNumber * (180.0/46), 0, 0, 1);

	for (i = 0; i < 3; i++) {
		glRotated(120, 0, 0, 1); 
		
  glEnable(GL_DEPTH_TEST);
		glBegin(GL_POLYGON);
		glVertex3f(0.00,0,0.6);
		glVertex3f(0.86f,0,0.6);
		
		glVertex3f(0.86f,-0.2f,0.6);
		glVertex3f(0.0f, -0.01f,0.6);
		
		glEnd();
	}frameNumber++;
}

  GLfloat* color;
  
void init() {
  glEnable(GL_DEPTH_TEST);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);
  glLightfv(GL_LIGHT0, GL_SPECULAR, WHITE);
  glMaterialfv(GL_FRONT, GL_SPECULAR, WHITE);
  glMaterialf(GL_FRONT, GL_SHININESS, 30);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  checkerboard.create();
}



void tower() {
	int q=checkerboard.centerx(),z=checkerboard.centerz();
	

	glColor3f(0.4f, 0.4f, 0.8f);
	

	glPushMatrix();
	 glScalef(0.8, 0.01, 0.10);
	 
  glutSolidCube(1.0);;
	glPopMatrix();

		for (int i = 0; i < 3; i++) {	
  glEnable(GL_DEPTH_TEST);
  glPolygonMode(GL_FRONT,GL_LINE);
  
  glPolygonMode(GL_BACK,GL_LINE);
		glBegin(GL_POLYGON);
		glVertex3f(0,0,0);

		glVertex3f(-0.5,-2,1);
		glVertex3f(0.25,-1,0.5);
		
		glEnd();
		
		glBegin(GL_POLYGON);
		glVertex3f(0,0,0);

		glVertex3f(-0.25,-1,0.5);
		glVertex3f(0.5, -2,1);
		
		glEnd();

		
		glBegin(GL_POLYGON);
		glVertex3f(0,0,0.0);;
		glVertex3f(-0.5,-2,1);
		glVertex3f(-0.25, -1,-0.5);
		
		glEnd();
				
		glBegin(GL_POLYGON);
		glVertex3f(0,0,0.0);;
		glVertex3f(-0.25,-1,0.5);
		glVertex3f(-0.5, -2,-1);
		
		glEnd();
		
		
		glBegin(GL_POLYGON);
		glVertex3f(0,0,0);
		glVertex3f(-0.5,-2,-1);
		glVertex3f(0.25, -1,-0.5);
		
		glEnd();
		
		glBegin(GL_POLYGON);
		glVertex3f(0,0,0);
		glVertex3f(-0.25,-1,-0.5);
		glVertex3f(0.5, -2,-1);
		
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(0,0,0);

		glVertex3f(0.25,-1,-0.5);
		glVertex3f(0.5, -2,1);
		
		glEnd();
		
		glBegin(GL_POLYGON);
		glVertex3f(0,0,0);

		glVertex3f(0.5,-2,-1);
		glVertex3f(0.25, -1,0.5);
		
		glEnd();
		
		
  glPolygonMode(GL_FRONT,GL_FILL);
  
  glPolygonMode(GL_BACK,GL_FILL);
		
		}
		
		
		

		
	}

void mill() {

 
   glPushMatrix();
      
 
    glTranslatef(checkerboard.centerx(), 1.080, checkerboard.centerz());
  glScalef(0.40, 2.4, 0.40);
 
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, WHITE);
  glutSolidCube(1.0);
  glPopMatrix();
  
  
  
	glPushMatrix();
    glTranslatef(checkerboard.centerx(), 2.35, checkerboard.centerz());
	 
	 glScalef(0.14, 0.14, 1.20);
	 
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, WHITE);
  glutSolidCube(1.0);;
	glPopMatrix();
  
  
	glPushMatrix();
    glTranslatef(checkerboard.centerx(), 2.35, checkerboard.centerz());
	glScaled(1.66,1.6,1);
	
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,s);
	drawWindmill();
	glPopMatrix();

  
   glPushMatrix();
    glTranslatef(checkerboard.centerx(), 2.35, checkerboard.centerz()+0.575);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,WHITE);
      glutSolidSphere(0.08,30,30);
    glPopMatrix();
  
  
  
  
	glPushMatrix();
    glTranslatef(checkerboard.centerx(), 0, checkerboard.centerz());

	 glScalef(0.5, 0.07, 0.520);
	 
		glRotated(90, 0, 1, 0); 
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, WHITE);
  glutSolidCube(1.0);;
	glPopMatrix();

  
  }


void display() {



  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(camera.getX(), camera.getY(), camera.getZ(),
            checkerboard.centerx(), 0.0, checkerboard.centerz(),
            0.0, 1.0, 0.0);
  checkerboard.draw();

   mill();
   
	glPushMatrix();
             glTranslatef(2, 0,-1.8);
   mill();
   	glPopMatrix();
  

	glPushMatrix();
    glTranslatef(checkerboard.centerx(), 0.32, checkerboard.centerz()-3.2);

	 glScalef(0.8270, 0.820, 0.820);
	 
		glRotated(90, 0, 1, 0); 
    	
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,g);

  glutSolidCube(1.0);
  
		glBegin(GL_LINE_STRIP);
		glVertex3f(0,0,0);
		glVertex3f(0,0.84,0);

		glEnd();
		
		glBegin(GL_LINE_STRIP);
		glVertex3f(0.3,0,0);
		glVertex3f(0.3,0.84,0);

		glEnd();
	glPopMatrix();

  
	glPushMatrix();
    glTranslatef(checkerboard.centerx()-3, 2, checkerboard.centerz()-3);
    glColor3f(1, 1, 0);
		glBegin(GL_LINE_STRIP);
		glVertex3f(0,0,0);
		glVertex3f(3.0,-1.4,-0.2);

		glEnd();
		
  glPopMatrix();
  
	glPushMatrix();
    glTranslatef(checkerboard.centerx()-3, 0.85, checkerboard.centerz()+1.9);
	 
	 glScalef(1.14, 1.8, 1.20);
	 
		glRotated(90, 0, 1, 0); 
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, bl);
    
  glutSolidCube(1.0);
  
	glPopMatrix();

  
	glPushMatrix();
    glTranslatef(checkerboard.centerx()-3, 2, checkerboard.centerz()-3);
    glColor3f(1, 1, 0);
		glBegin(GL_LINE_STRIP);
		glVertex3f(0,0,0);
		glVertex3f(0.075,-0.4,4.5);

		glEnd();
		
  glPopMatrix();

  
	glPushMatrix();
    glTranslatef(checkerboard.centerx()-2.423, 0.85, checkerboard.centerz()+1.5);
    glColor3f(1, 1, 0);
		glBegin(GL_POLYGON);
		glVertex3f(0,0,0);
		glVertex3f(0,0,0.5);
		glVertex3f(0,-0.85,0.5);
		
		glVertex3f(0,-0.85,0);
		glEnd();
		
  glPopMatrix();

	glPushMatrix();
    glTranslatef(checkerboard.centerx()-3, 2, checkerboard.centerz()-3);
	glScaled(1,1,0.52);

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,black);
	tower();

	glPopMatrix();

	glPushMatrix();
    glTranslatef(checkerboard.centerx(), 0.01, checkerboard.centerz());
    glColor3f(1, 1, 0);
		glBegin(GL_POLYGON);
		glVertex3f(0,0,0);
		glVertex3f(0.2,0,0);
		glVertex3f(0.2,0,-3.5);
		
		glVertex3f(0,0,-3.50);
		glEnd();
		
  glPopMatrix();
  
	glPushMatrix();
    glTranslatef(checkerboard.centerx()+2, 0.01, checkerboard.centerz()-2.5);
    glColor3f(1, 1, 0);
		glBegin(GL_POLYGON);
		glVertex3f(0,0,0);
		glVertex3f(0,0,0.1);
		glVertex3f(-2.015,0,0.1);
		
		glVertex3f(-2.015,0,0);
		glEnd();
		
		glBegin(GL_POLYGON);
		glVertex3f(0,0,0);
		glVertex3f(0.2,0,0);
		glVertex3f(0.2,0,0.5);
		
		glVertex3f(0,0,0.50);
		glEnd();
		
  glPopMatrix();
    glTranslatef(checkerboard.centerx()-3, 1, checkerboard.centerz()+2.253);
    glColor3f(1, 1, 0);
    glScaled(0.5,0.5,0.52);
   glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,  y);    
  glutSolidCube(1.0);
  
	glPopMatrix();
  glFlush();
  glutSwapBuffers();
}


void reshape(GLint w, GLint h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(40.0, GLfloat(w) / GLfloat(h), 1.0, 150.0);
  glMatrixMode(GL_MODELVIEW);
}

void timer(int v) {
  glutPostRedisplay();
  glutTimerFunc(1000/60, timer, v);
}

void special(int key, int, int) {
  switch (key) {
    case GLUT_KEY_LEFT: camera.moveLeft(); break;
    case GLUT_KEY_RIGHT: camera.moveRight(); break;
    case GLUT_KEY_UP: camera.moveUp(); break;
    case GLUT_KEY_DOWN: camera.moveDown(); break;
  }
  glutPostRedisplay();
}
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 600);
  glutCreateWindow("3d Windmill ");
  glClearColor(0,0.9,1,1);       
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutSpecialFunc(special);
  glutTimerFunc(100, timer, 0);
  init();
  glutMainLoop();
}



