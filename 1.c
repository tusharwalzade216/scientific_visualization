#include <GL/glut.h>

void display(void) {
	int i;
	float a[10] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.10}, b[10] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.10};
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	for (i = 0; i < 10; i++) {
		glVertex2f(a[i]/b[i], b[i]/a[i]);
		//glVertex2f(i/(float)100, i/(float)100);
		//glVertex2f(i/(float)1000, i/(float)100);
		//glVertex2f(i/(float)10, i/(float)100);
	}
        glEnd();
	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(300, 150);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Triangle");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
