// Tushar Walzade (1429@ISSC)

#include <stdio.h>
#include <GL/glut.h>

float h, w, l, angle = 1;
float x = -0.5, y = -0.5, z = 0;

void timer(int val) {
	glutPostRedisplay();
	glutTimerFunc(30, timer, 1);
}
void display(void) {
	float i;
	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(angle, 0, 1, 0);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f( x, y, z);       
	glVertex3f( x + l, y, z);       
	glVertex3f( x + l, y + h, z);
	glVertex3f( x, y + h, z);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f( x + w, y + w, z - w);
	glVertex3f( x + l + w, y + w, z - w);
	glVertex3f( x + l + w, y + h + w, z - w);
	glVertex3f( x + w, y + h + w, z - w);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f( x, y, z); 
	glVertex3f( x + w, y + w, z - w);
	glVertex3f( x + w, y + h + w, z - w);
	glVertex3f( x, y + h, z);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f( x + l, y, z);
	glVertex3f( x + l + w, y + w, z - w);
	glVertex3f( x + l + w, y + h + w, z - w);
	glVertex3f( x + l, y + h, z);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f( x, y + h, z);
	glVertex3f( x + l, y + h, z);
	glVertex3f( x + l + w, y + h + w, z - w);
	glVertex3f( x + w, y + h + w, z - w);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f( x, y, z);
	glVertex3f( x + l, y, z);
	glVertex3f( x + l + w, y + w, z - w);
	glVertex3f( x + w, y + w, z - w);
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
	printf("enter height, width, length respectively : \t"); // enter 0.8 0.4 0.6 for the good looking one
	scanf("%f%f%f", &h, &w, &l);
	glutInit(&argc, argv);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Cube");
	glutTimerFunc(30, timer, 1);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
