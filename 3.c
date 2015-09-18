#include <GL/glut.h>
#include <math.h>

void display(void) {
	int i, n = 80;
	float theta = 360 / (float) n;
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	for (i = theta; i <= 360; i += theta) {
		glVertex2f(cos(i), sin(i));
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
