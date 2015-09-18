#include <GL/glut.h>

void display(void) {
	int i;
	float x = 0.25, y = 0.25, a = 0.5;
	float avg = (x + y) / (float)2;
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	//for (x = 0, y = 0; x < 1, y < 1; x++, y++) {
		glVertex2f(-x, y);
		glVertex2f(-x + a, y);
		glVertex2f(-x, y - a);
		glVertex2f(-x + a, y - a);
		glVertex2f(-avg + a / (float)2, avg + a);
		glVertex2f(-avg + a / (float)2, -avg - a);
		glVertex2f(-avg - a, avg - a / (float)2);
		glVertex2f(avg + a, avg - a / (float)2);
		//glVertex2f((-x + y - a) / (float)2, (-x + y - a) / (float)2);
	//}
        glEnd();
	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(300, 150);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Paklya");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
