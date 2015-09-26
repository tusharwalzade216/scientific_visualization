// Tushar Walzade (1429@ISSC)

#include <GL/glut.h>
#include <math.h>
#define PI 3.14159265

void display(void) {
	int j, n = 1010, n2; 			//set n whatever u want
	n2 = 2 * n;
	float i, theta = 360 / (float) n2;
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	for (i = theta, j = 0; i <= 360, j < n2; i += theta, j++) {
		if(j % 2 == 0)
			glVertex2f(0.5 * cos(i * PI / 180), 0.5 * sin(i * PI / 180));	// 0.5 is the manual radius for inner circle
		else
			glVertex2f(1 * cos(i * PI / 180), 1 * sin(i * PI / 180));	// 1 is the manual radius for outer circle
	}
        glEnd();
	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(300, 150);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Paklya");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
