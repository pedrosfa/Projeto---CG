#include <Windows.h>
#include <iostream>
#include "C:/Users/pedro/Desktop/cg/openGL/glut.h"

#include "axx.h"
#include "Sphere.h"
#include "Cube.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Scenary.h"
#include "mirroring.h"
#include "rotation.h"
#include "scaling.h"
#include "shearing.h"
#include "translating.h"

#pragma comment(lib, "C:/Users/pedro/Desktop/cg/openGL/glut32.lib")

#define PI 3.14159265359

//definindo materiais
Material GREEN = Material({0.0215, 0.1745, 0.0215}, {0.0756, 0.6142, 0.0756}, {0.6330, 0.7278, 0.6330}, 76.8000);
Material OBS   = Material({0.0537, 0.0500, 0.0662}, {0.1827, 0.1700, 0.2252}, {0.3327, 0.3286, 0.3464}, 38.4000);
Material PC    = Material({0.1912, 0.0735, 0.0225}, {0.7038, 0.2704, 0.0828}, {0.2567, 0.1376, 0.0860}, 12.8000);
Material C     = Material({0.2500, 0.2500, 0.2500}, {0.4000, 0.4000, 0.4000}, {0.7745, 0.7745, 0.7745}, 12.8000);
Material P     = Material({1.0000, 1.0000, 1.0000}, {1.0000, 0.8290, 0.8290}, {0.2966, 0.2966, 0.2966}, 11.2640);
Material O     = Material({1.0000, 0.2735, 0.9000}, {1.0000, 0.2570, 0.9000}, {1.0000, 0.2537, 0.9000}, 11.2640);
Material S     = Material({0.1922, 0.1922, 0.1922}, {0.5075, 0.5075, 0.5075}, {0.5082, 0.5082, 0.5082}, 51.2000);
Material B     = Material({0.2125, 0.1275, 0.0540}, {0.7140, 0.4284, 0.1814}, {0.3935, 0.2719, 0.1667}, 25.6000);
Material R     = Material({0.1745, 0.0117, 0.0117}, {0.6142, 0.0413, 0.0413}, {0.7278, 0.6269, 0.6269}, 76.8000);
Material G     = Material({0.2472, 0.1995, 0.0745}, {0.7516, 0.6064, 0.2264}, {0.6282, 0.5558, 0.3660}, 51.2000);

using namespace std;

/*Matriz de pixels*/
float* test;

void renderScene(void) {
    glDrawPixels(HEIGHT, WIDTH, GL_RGB, GL_FLOAT, test);
    glutSwapBuffers();
    glutPostRedisplay();
}

void Raycaster() {

    /*--------------------------------------DEFININDO MATERIAIS-----------------------------------------------------------*/
    auto* GREEN = new Material({0.0215, 0.1745, 0.0215}, {0.0756, 0.6142, 0.0756}, {0.6330, 0.7278, 0.6330}, 76.8000);
    auto* OBS   = new Material({0.0537, 0.0500, 0.0662}, {0.1827, 0.1700, 0.2252}, {0.3327, 0.3286, 0.3464}, 38.4000);
    auto* PC    = new Material({0.1912, 0.0735, 0.0225}, {0.7038, 0.2704, 0.0828}, {0.2567, 0.1376, 0.0860}, 12.8000);
    auto* C     = new Material({0.2500, 0.2500, 0.2500}, {0.4000, 0.4000, 0.4000}, {0.7745, 0.7745, 0.7745}, 12.8000);
    auto* P     = new Material({1.0000, 1.0000, 1.0000}, {1.0000, 0.8290, 0.8290}, {0.2966, 0.2966, 0.2966}, 11.2640);
    auto* O     = new Material({1.0000, 0.2735, 0.9000}, {1.0000, 0.2570, 0.9000}, {1.0000, 0.2537, 0.9000}, 11.2640);
    auto* S     = new Material({0.1922, 0.1922, 0.1922}, {0.5075, 0.5075, 0.5075}, {0.5082, 0.5082, 0.5082}, 51.2000);
    auto* B     = new Material({0.2125, 0.1275, 0.0540}, {0.7140, 0.4284, 0.1814}, {0.3935, 0.2719, 0.1667}, 25.6000);
    auto* R     = new Material({0.1745, 0.0117, 0.0117}, {0.6142, 0.0413, 0.0413}, {0.7278, 0.6269, 0.6269}, 76.8000);
    auto* G     = new Material({0.2472, 0.1995, 0.0745}, {0.7516, 0.6064, 0.2264}, {0.6282, 0.5558, 0.3660}, 51.2000);

    /*--------------------------------------CRIANDO OBJETOS--------------------------------------------------------*/

    Matriz rotation_Y = rotateY(-PI / 2);
    Point translation1 = Point(2, 0, -7);
    //Objetos baseados em cubos --- Instanciação
    //Cube(float side, Point  center, Material mat);
    Cube mesa(10, {0, 10, 0}, *GREEN);
    Cube piso(35, {0, 0, 0}, *GREEN);
    Cube p1(10, {2.5, 5, 2.5}, *GREEN);
    Cube p2(10, {2.5, 5, -2.5}, *GREEN);
    Cube p3(10, {-2.5, 5, 2.5}, *GREEN);
    Cube p4(10, {-2.5, 5, -2.5}, *GREEN);
    Cube fio(20, { 0, 27, 0 }, *GREEN);

    //Objetos baseados em cubos --- Transformações
    mesa.Scaling(Point(1, 0.10, 1));
    //mesa.Rotate(-PI/4, Point(0, 1, 0));
    //mesa.Translating(Point(0, 10, 0));

    piso.Scaling(Point(1, 0.010, 0.5));
    //piso.Rotate(-PI / 2, Point(0, 1, 0));
    //piso.Translating(translation1);

    p1.Scaling(Point(0.1, 1, 0.1));
    //p1.Rotate(-PI / 2, Point(0, 1, 0));
    //p1.Translating(translation1);

    p2.Scaling(Point(0.1,1, 0.1));
    //p2.Rotate(-PI / 2, Point(0, 1, 0));
    //p2.Translating(translation1);

    p3.Scaling(Point(0.1,1, 0.1));
    //p3.Rotate(-PI / 2, Point(0, 1, 0));
    //p3.Translating(translation1);

    p4.Scaling(Point(0.1, 1, 0.1));
    //p4.Rotate(-PI / 2, Point(0, 1, 0));
    //p4.Translating(translation1);

    fio.Scaling(Point(0.001, 1, 0.001));

    //Objetos baseados em cilindros - Instanciação
    //Cylinder(float radius, float height, Point center_base, Point axis, Material mat);
    Cylinder prato(1.0, 0.19, {0, 10.75, 0}, {0, 1, 0}, *O);
    Cylinder banco1(2.0, 5.5, {8, 0, 0}, {0, 1, 0}, *OBS);
    Cylinder banco2(2.0, 5.5, {-8, 0, 0}, {0, 1, 0}, *OBS);

    //Objetos baseados em cilindros --- Transformações
    //prato.Rotate(rotateX(PI/6));
    //prato.Translating(Point(0, 12, 6));

    //banco1.Rotate(rotation_Y);
    //banco1.Translating(Point(2, 0, -7));

    //banco2.Rotate(rotation_Y);
    //banco2.Translating(Point(2, 0, -7));
    //Objetos baseados em esferas - Instanciação
    //Sphere(float radius, Point center, Material mat);
    Sphere bolinha1(0.3000, {0.3, 13, 0}, *O);
    Sphere bolinha2(0.3000, {-0.3, 13, 0}, *S);
    Sphere bolinha3(0.3000, {0, 13, 0.3}, *B);
    Sphere bolinha4(0.3000, {0, 13, -0.3}, *R);
    
    //Objetos baseados em esferas - Transformações
    //bolinha1.Rotate(rotation_Y);
    //bolinha2.Rotate(rotation_Y);
    //bolinha3.Rotate(rotation_Y);
    //bolinha4.Rotate(rotation_Y);

    //bolinha1.Translating(translation1);
    //bolinha2.Translating(translation1);
    //bolinha3.Translating(translation1);
    //bolinha4.Translating(translation1);

    //Objetos baseados em cones - Instanciação
    //Cone(float radius, float height, Point center, Point axis, Material mat);

    Cone vaso(0.75, 2, {0, 13, 0}, {0, -1, 0}, *C);
    Cone luz(0.30, 2, {0, 15, 0}, { 0, 1, 0 }, *C);

    //Objetos baseados em cones - Transformações
    //vaso.Rotate(rotation_Y);
    //vaso.Translating(translation1);
    /*------------------------------------------CRIANDO ILUMINAÇÃO------------------------------------------------*/

    //Luzes ambiente
    //AmbientLighting(float r, float g, float b);
    AmbientLighting ambientLight1(1.0000, 1.0000, 1.0000);
    AmbientLighting ambientLight2(0.6500, 0.2000, 0.5500);
    AmbientLighting ambientLight3(0.1500, 1.0000, 0.9000);
    AmbientLighting ambientLight4(0.7500, 0.7500, 0.7500);

    //Luzes pontuais
    //PointLighting(float r, float g, float b, Point position);
    PointLighting pointLight1(0.9000, 0.0000, 0.0000, { 10, 20, 0 });
    PointLighting pointLight2(0.4500, 0.1200, 0.8000, {0, 0, 0});
    PointLighting pointLight3(0.7500, 0.7500, 0.8600, {0, 0, 0});
    PointLighting pointLight4(0.1000, 0.3000, 0.7000, {0, 0, 0});

    //Luzes spot
    //SpotLighting(float r, float g, float b, Point position, Point direction, float angle);
    SpotLighting spotLight1(0.3650, 0.6540, 0.9907, { 5, 20, 0 }, {0, 10, 0}, PI / 2);
    SpotLighting spotLight2(1, 1, 1, {0, 15, 0}, {0, 10, 0}, 17.062);
    SpotLighting spotLight3(0.2760, 0.8500, 0.4250, {0, 0, -15}, {0, 0, -20}, PI / 2.5);
    SpotLighting spotLight4(0.0970, 0.1480, 0.8880, {0, 0, -15}, {0, 0, -20}, PI / 8);

    //Luzes distantes
    //FarLighting(float r, float g, float b, Point direction);
    FarLighting farLight1(0.7500, 0.3570, 0.1230, Point(0, 0, -1));
    FarLighting farLight2(0.5550, 0.2210, 0.3210, Point(0, 0, -1));
    FarLighting farLight3(0.1570, 0.1890, 0.1580, Point(13.5, 0, 0));
    FarLighting farLight4(0.1470, 0.7890, 0.1570, Point(0, 0, -1));


    /*---------------------------------------CRIANDO CAMERAS------------------------------------------------------*/
    //Camera(Point eye, Point lookAt, Point viewUp, int d, int plano_tamanho);
    Camera camera1({0, 20, 30}, {0, 10, 0}, {0, 21, 30}, -4, 4);
    Camera camera2({ 0, 15, 30 }, { 0, 10, 0 }, { 0, 16, 30 }, -4, 4);
    Camera camera3({ 0, 10, 30 }, { 0, 10, 0 }, { 0, 11, 30 }, -4, 4);
    Camera camera4({ 30, 10, 0 }, { 0, 10, 0 }, { 30, 11, 0 }, -4, 4);
    Camera camera5({ 30, 15, 0 }, { 0, 10, 0 }, { 30, 16, 0 }, -4, 4);
    Camera camera6({ 30, 20, 0 }, { 0, 10, 0 }, { 30, 21, 0 }, -4, 4);
    Camera camera7({ 10, 30, 0 }, { 0, 10, 0 }, { 10, 31, 0 }, -1, 4);

    /*-----------------------------MONTANDO CENÁRIO-------------------------------------------------------------*/
    //Instanciação
    Scenary* cenario = new Scenary();

    //Adicionando objetos
    cenario->addShape(&mesa);
    cenario->addShape(&piso);
    cenario->addShape(&p1);
    cenario->addShape(&p2);
    cenario->addShape(&p3);
    cenario->addShape(&p4);
    cenario->addShape(&fio);
    cenario->addShape(&prato);
    cenario->addShape(&banco1);
    cenario->addShape(&banco2);
    cenario->addShape(&vaso);
    cenario->addShape(&luz);
    cenario->addShape(&bolinha1);
    cenario->addShape(&bolinha2);
    cenario->addShape(&bolinha3);
    cenario->addShape(&bolinha4);

    //Adicionando a luz ambiente
    //cenario->setAmbientLight(ambientLight1);
    cenario->setAmbientLight(ambientLight2);
    //cenario->setAmbientLight(ambientLight3);
    //cenario->setAmbientLight(ambientLight4);
    
    //Adicionando luzes pontuais
    cenario->addLight(&pointLight1);
    //cenario->addLight(&pointLight2);
    //cenario->addLight(&pointLight3);
    //cenario->addLight(&pointLight4);

    //Adicionando luzes spot
    //cenario->addLight(&spotLight1);
    cenario->addLight(&spotLight2);
    //cenario->addLight(&spotLight3);
    //cenario->addLight(&spotLight4);

    //Adicionando luzes remotas
    //cenario->addLight(&farLight1);
    //cenario->addLight(&farLight2);
    //cenario->addLight(&farLight3);
    //cenario->addLight(&farLight4);

    //Definindo a camera;
    //cenario->setCamera(camera1);
    //cenario->setCamera(camera2);
    //cenario->setCamera(camera3);
    //cenario->setCamera(camera4);
    //cenario->setCamera(camera5);
    //cenario->setCamera(camera6);
    cenario->setCamera(camera7);

    cenario->rayCasting();

    test = cenario->frame;
}

int main(int argc, char** argv) {

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glClearColor(0, 0, 0, 0);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(HEIGHT, WIDTH);
    glutCreateWindow("Cena - Computação Gráfica I");

    glutPostRedisplay();

    test = new float[HEIGHT * WIDTH * 3];

    Raycaster();

    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);


    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}