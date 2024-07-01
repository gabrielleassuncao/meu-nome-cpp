//nome: Gabrielle do Carmo Assuncao

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

GLfloat escalax = 1.0f;
GLfloat escalay = 1.0f;
GLfloat tx = 0.0f;
GLfloat ty = 0.0f;
GLfloat angulo = 0.0f;

void desenha(void) {
    glClear( GL_COLOR_BUFFER_BIT ); //limpar o buffer

    glMatrixMode(GL_PROJECTION); //define que iremos mudar a matrix de trasformacao da camera da projecao
    glLoadIdentity(); //seta a matrix identidade para a matrix de projecao

    gluOrtho2D(0,800,0,600); //projecao ortografica, define posicoes

    glScalef(escalax, escalay, 0);
    glTranslatef(tx, ty, 0);
    glRotatef(angulo, 0 , 0,1);

    glMatrixMode(GL_MODELVIEW); //define que iremos mudar a matri de transformacao dos elementos da cena
    glLoadIdentity(); //seta a matrix identidade para a matrix de transformacao dos elementos da cena

    glLineWidth(8); //define a largura da letra

    glBegin(GL_LINE_STRIP); //letra G

        glVertex3f(320,400,0);
        glVertex3f(270,400,0);
        glVertex3f(270,315,0);
        glVertex3f(320,315,0);
        glVertex3f(320,350,0);
        glVertex3f(290,350,0);
        glEnd();

    glBegin(GL_LINE_STRIP);  //letra A

        glVertex3f(335,314,0);
        glVertex3f(335,320,0);
        glVertex3f(335,400,0);
        glVertex3f(375,400,0);
        glVertex3f(375,320,0);
        glVertex3f(375,314,0);
        glEnd();

    glBegin(GL_LINES); //tracinho da letra A

        glVertex3f(335,350,0);
        glVertex3f(375,350,0);
        glEnd();

    glBegin(GL_LINE_STRIP);  //letra B

        glVertex3f(390,314,0);
        glVertex3f(390,400,0);
        glVertex3f(390,400,0);
        glVertex3f(425,400,0);
        glVertex3f(425,357,0);
        glVertex3f(435,357,0);
        glVertex3f(435,314,0);
        glVertex3f(390,314,0);
        glEnd();

    glBegin(GL_LINES); //tracinho da letra B

        glVertex3f(390,357,0);
        glVertex3f(435,357,0);
        glEnd();


    glBegin(GL_LINES);  //letra i

        glVertex3f(450,400,0);
        glVertex3f(450,314,0);
        glEnd();

        glFlush();// descarrega o que foi para o buffer
}

void teclado(unsigned char tecla, GLint x, GLint y)
{
        switch(tecla){

        case '+': escalax = escalax + 0.5;
                  break;
        case '-': if (escalax > 0.5){
                  escalax -= 0.5;}
                  break;
        case 'a': tx = tx - 1;
                  break;
        case 'd': tx = tx + 1;
                  break;
        case 'w': ty = ty + 1;
                  break;
        case 's': ty = ty - 1;
                  break;
        case 'q': angulo = angulo + 5;
                  break;
        case 'e': angulo = angulo - 5;
                  break;

    }
    desenha();
}

    int main(int argc, char* argv[]){
    glutInit(&argc, argv); //inicia o ambiente glut
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ); //define as especificacoes da janela: tipo de frame buffer e o padrao de cores
    glutInitWindowSize(800,600); //define o tamanho da janela
    glutCreateWindow("Meu nome!"); //define o titulo da janela
    glutKeyboardFunc(teclado); //chamada da funcao teclado
    glutDisplayFunc(desenha);//chamada da funcao desenha
    glClearColor(1.0, 0.7, 0.7, 1.0); //define a cor da janela
    glutMainLoop(); //incia o loop principal
    return 0;
}
