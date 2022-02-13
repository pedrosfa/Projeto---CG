#pragma once
#include "axx.h"

//classe da esfera
class Sphere : public Shape {
public:
    float radius; //raio
    Point center; //posição do centro
    Sphere();
    Sphere(float radius, Point center, Material mat);
    void  applyTransform(Matriz transform);
    void  setCameraCoordinates(Matriz worldToCamera);
    void  setWorldCoordinates(Matriz cameraToWorld);
    Point rayIntersect(Point rayOrigin, Point rayDirection);
    Point normal(Point point);
    void  Scaling(Point scale);
    void  Rotate(Matriz rotate);
    void  Translating(Point translate);
    //Point* Bounds();
};