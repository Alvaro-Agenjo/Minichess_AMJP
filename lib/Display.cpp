//////#include "freeglut.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//////// ///////////////////////////////////////////////////////////////////////////////////////////////////
//////// aqui se inlcuirá la interfaz del tablero creada en freeglut, ahora mismo es codigo de referencia
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//////#include "freeglut.h"
//////#include <iostream>
//////#include <cmath>
//////
//////
//////
//////void OnDraw(void);		 //esta funcion sera llamada para dibujar
//////void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
//////void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
//////
//////
//////int main(int argc, char* argv[])
//////{
//////	//Inicializar el gestor de ventanas GLUT
//////	//y crear la ventana
//////	glutInit(&argc, argv);
//////	glutInitWindowSize(800, 600);
//////	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//////	glutCreateWindow("MiJuego");
//////
//////	//habilitar luces y definir perspectiva
//////	glEnable(GL_LIGHT0);
//////	glEnable(GL_LIGHTING);
//////	glEnable(GL_DEPTH_TEST);
//////	glEnable(GL_COLOR_MATERIAL);
//////	glMatrixMode(GL_PROJECTION);
//////	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
//////
//////	//Registrar los callbacks
//////	glutDisplayFunc(OnDraw);
//////	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
//////	glutKeyboardFunc(OnKeyboardDown);
//////
//////	//inicialización de los datos de la simulación
//////	
//////	//pasarle el control a FREEGLUT,que llamara a los callbacks
//////	glutKeyboardFunc(OnKeyboardDown);
//////	//pasarle el control a FREEGLUT,que llamara a los callbacks
//////	glutMainLoop();
//////	return 0;
//////}
//////
//////void OnDraw(void)
//////{
//////	//Borrado de la pantalla	
//////	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//////
//////	//Para definir el punto de vista
//////	glMatrixMode(GL_MODELVIEW);
//////	glLoadIdentity();
//////	gluLookAt(0,0,10,  // posicion del ojo, de momento aproximado
//////		0, 0, 0,      // hacia que punto mira  (0,0,0)   p.x2, p.y2, p.z2,
//////		0, 1, 0);      // definimos hacia arriba (eje Y) 
//////	//aqui es donde hay que poner el código de dibujo
//////	
//////	glBegin(GL_POLYGON);
//////	glColor3ub(255, 255, 255);
//////	glVertex3f(-5.0f, 0.0f, -5.0f);
//////	glColor3ub(255, 255, 255);
//////	glVertex3f(-5.0f, 0.0f, 5.0f);
//////	glColor3ub(255, 255, 255);
//////	glVertex3f(5.0f, 0.0f, 5.0f);
//////	glColor3ub(255, 255, 255);
//////	glVertex3f(5.0f, 0.0f, -5.0f);
//////	glEnd();
//////	
//////	glDisable(GL_LIGHTING);
//////	glBegin(GL_LINE_LOOP);
//////	glVertex3f(-5.0f, 0, -5.0f);
//////	glVertex3f(-5.0f, 0, 5.0f);
//////	glVertex3f(5.0f, 0, 5.0f);
//////	glVertex3f(5.0f, 0, -5.0f);
//////	glEnd();
//////	glEnable(GL_LIGHTING);
//////
//////	//no borrar esta linea ni poner nada despues
//////	glutSwapBuffers();
//////
//////}
//////void OnKeyboardDown(unsigned char key, int x_t, int y_t)
//////{
//////	//poner aqui el código de teclado
//////	p.tecla(key);
//////	/*
//////	if (key == '+' && esfera2.radio < 3)
//////		esfera2.radio += 0.5f;
//////	if (key == '-' && esfera2.radio > 1)
//////		esfera2.radio -= 0.5f;
//////	if (key == 'r')esfera.setColor(255, 0, 0);
//////	if (key == 'g')esfera.setColor(0, 255, 0);
//////	if (key == 'b')esfera.setColor(0, 0, 255);
//////	if (key == 'a')
//////		esfera2.x -= 0.1f;
//////	if (key == 'd')
//////		esfera2.x += 0.1f;
//////	if (key == 's')
//////		esfera2.y -= 0.1f;
//////	if (key == 'w')
//////		esfera2.y += 0.1f;
//////		*/
//////	glutPostRedisplay();
//////}
//////
//////void OnTimer(int value)
//////{
//////	//poner aqui el código de animacion
//////	p.mover();
//////	//codigo del cambio de POI
//////	//p.rotarOjo();
//////	/*
//////	float d = sqrt(perfil.x_ojo * perfil.x_ojo + perfil.z_ojo * perfil.z_ojo);
//////	float T = atan2(perfil.z_ojo, perfil.x_ojo);
//////	T = T + 0.01;
//////		perfil.x_ojo = d * cos(T);
//////		perfil.z_ojo = d * sin(T);
//////
//////		*/
//////		//poner aqui el código de animacion
//////		/*
//////	Mueve(&esfera);
//////	Mueve(&esfera2);
//////	glutTimerFunc(25, OnTimer, 0);
//////	glutPostRedisplay();
//////	*/
//////	//no borrar estas lineas
//////	glutTimerFunc(25, OnTimer, 0);
//////	glutPostRedisplay();
//////}
