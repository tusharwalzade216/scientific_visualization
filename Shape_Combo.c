// Tushar Walzade (1429@ISSC)

#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
float h;
void display(void) {
	float i, j;
	glClear(GL_COLOR_BUFFER_BIT);
	
	//the rectangle
	glColor3f(0.5f, 0.5f, 0.3f);
	glBegin(GL_QUADS);
	glVertex2f( h, h);       
	glVertex2f( h, -h);
	glVertex2f( -h, -h);
	glVertex2f( -h, h);
	glEnd();
	
	//triangle in first quadrant
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f( h, h);       
	glVertex2f( h, h + h);       
	glVertex2f( h + h, h);       
	glEnd();
	
	//triangle in second quadrant
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f( -h, h);       
	glVertex2f( -h, h + h);       
	glVertex2f( -h - h, h);
	glEnd();
	
	//triangle in third quadrant
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f( -h, -h);       
	glVertex2f( -h, -h - h);       
	glVertex2f( -h - h, -h);       
	glEnd();
	
	//triangle in fourth quadrant
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f( h, -h);       
	glVertex2f( h, -h - h);       
	glVertex2f( h + h, -h);       
	glEnd();
	
	//the circle
	glColor3f(0.3f, 0.3f, 0.5f);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i += 1)
			glVertex2f(cos(i * M_PI / 180), sin(i * M_PI / 180));
	glEnd();
	
	//the points inside polygon
	glColor3f(0.3f, 0.3f, 0.5f);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 360; i += 1)
		for(j = h; j > 0; j -= 0.1)
			glVertex2f(j * cos(i * M_PI / 180), j * sin(i * M_PI / 180));
	glEnd();
	glFlush();	
}

void init(void){
 	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(50,50,50,50,50,50);
	glPopMatrix();	
}

int main(int argc, char** argv) {
	printf("enter height : \t");
	scanf("%f", &h);
	glutInit(&argc, argv);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Cube");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
