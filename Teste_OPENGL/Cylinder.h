//#include "C:/Users/Derley/Downloads/eigen-3.4.0/eigen-3.4.0/Eigen/Dense"
//
//typedef Eigen::Vector4d Vertex;
//typedef Eigen::Matrix4d Matrix;
//
//class Cylinder {
//public:
//    float radius;
//    float height;
//    Vertex center_base;
//    Vertex center_top;
//    Vertex axis;
//    Cylinder();
//    Cylinder(float radius, float height, Vertex center_base, Vertex axis);
//    void applyTransform(Matrix transform);
//    void setCameraCoordinates(Matrix worldToCamera);
//    void setWorldCoordinates(Matrix cameraToWorld);
//    Vertex planeIntersectBase(Vertex rayOrigin, Vertex rayDirection);
//    Vertex planeIntersectTop(Vertex rayOrigin, Vertex rayDirection);
//    Vertex normal(Vertex point);
//
//    bool ValidatePoint(Vertex pint);
//    Vertex PrimeiraIntersecao(Vertex pP0, Vertex pVetor0);
//};
#pragma once
#include "axx.h"
#include "eigen-3.4.0/Eigen/Dense"

class Cylinder : public Shape
{
public:
    float radius;// raio do cilindro
    float height; //altura do cilindro
    Point center_base; //centro da base 
    Point center_top; //centro do topo
    Point axis; //eixo
    Cylinder();
    Cylinder(float radius, float height, Point center_base, Point axis, Material mat);
    void applyTransform(Matriz transform);
    void setCameraCoordinates(Matriz worldToCamera);
    void setWorldCoordinates(Matriz cameraToWorld);
    Point rayIntersect(Point rayOrigin, Point rayDirection);
    Point planeIntersectBase(Point rayOrigin, Point rayDirection); //calcula a interssecção com a base
    Point planeIntersectTop(Point rayOrigin, Point rayDirection); //calcula a interssecção com o topo
    void  Scaling(Point scale); // aplica escala
    void  Rotate(Matriz rotate); //aplica rotação
    void  Translating(Point translate); //aplica translação
    Point normal(Point point); //calcula a normal
    bool validate(Point p); //valida um ponto
    //Point* Bounds();
};