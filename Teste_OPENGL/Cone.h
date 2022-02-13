#pragma once
#include "axx.h"

//Classe do objeto cone
class Cone : public Shape
{
public:
    float radius; //raio do cone
    float height; // altura do cone
    Point center; //centro da base
    Point axis; //normal
    Point origin; // origem do cone
    Cone();
    Cone(float radius, float height, Point center, Point axis, Material mat);
    void  applyTransform(Matriz transform);
    void  setCameraCoordinates(Matriz worldToCamera);
    void  setWorldCoordinates(Matriz cameraToWorld);
    Point rayIntersect(Point rayOrigin, Point rayDirection);
    Point planeIntersectBase(Point rayOrigin, Point rayDirection); //Valida uma intessec��o com a base do cone
    Point normal(Point point); 
    void  Scaling(Point scale); //Aplica escala
    void  Rotate(Matriz rotate); //Aplica rota��o
    void  Translating(Point translate); //Aplica transla��o
    bool  validate(Point p, Point ray); //valida se o ponto est� de fato interceptando o objeto
    Point base_intesection(Point rayOrigin, Point rayDirection); //
    //Point* Bounds();
};