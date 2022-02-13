#pragma once
#include "axx.h"
#include "Camera.h"
#include "Lighting.h"

//classe do cen�rio
class Scenary
{
public:
    Camera camera; //a camera do cen�rio
    vector<Shape*> shapes; //os objetos do cen�rio
    AmbientLighting ambientLight; // luz ambiente
    vector<Lighting*> lights; //outras ilumina��es
    Point canvas[HEIGHT][WIDTH]; //pontos 
    float* canvas_opengl;
    float frame[HEIGHT * WIDTH * 3]; //imagem
    Scenary();
    void addShape(Shape* shape); //insere objeto
    void addLight(Lighting* light); //insere luz
    void setCamera(Camera camera); //define a camera
    void setAmbientLight(AmbientLighting ambientLight); //define luz ambiente
    void setWorldCoordinates(); //coordenadas de mundo
    void setCameraCoordinates(); //coordenadas de camera
    void rayCasting(); // processo de ray casting e pintura da imagem
};