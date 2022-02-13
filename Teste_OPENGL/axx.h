#pragma once
#include "eigen-3.4.0/Eigen/Dense"

#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <limits>

#define HEIGHT 500
#define WIDTH 500
#define BG Point(0, 1, 1)

#define MAXFLOAT numeric_limits<float>::max()


using namespace std;

typedef Eigen::Vector3f Point;
typedef Eigen::Vector4f Vertex;
typedef Eigen::Matrix4f Matriz;


//Classe material
class Material
{
public:
    Point ka; //Coeficientes p/ iluminação ambiente
    Point kd; //Coeficientes p/ iluminação difusa
    Point ks; //Coeficientes p/ iluminação especular
    float shininess; //Coeficientes de brilho
    Material();
    Material(Point ka, Point kd, Point ks, float shininess);
};

//Classe shape, todos os objetos herdam dela
class Shape
{
public:
    virtual void setCameraCoordinates(Matriz worldToCamera) = 0; //Muda de coordenadas de mundo para coordenadas de camera
    virtual void setWorldCoordinates(Matriz cameraToWorld) = 0; // Muda de coordenadas de camera para coordenadas de mundo
    virtual Point rayIntersect(Point rayOrigin, Point rayDirection) = 0; // Verifica se um determinado raio intercepta o objeto
    virtual Point normal(Point point) = 0; //calcula uma normal
    //virtual Point Bounds() = 0;
    Material mat;
};

//Função auxiliar (Converte de Vector3f para Vector4f)
Vertex PointToVertex(Point p);

//Função auxiliar (Converte de Vector4f para Vector3f)
Point VertexToPoint(Vertex p);

//Classe da face, utilizada apenas no cubo, e potencialmente em qualquer objeto representado por uma estrutura de dados
class Face {
public:
    Face();
    Face(Point v1, Point v2, Point v3);
    Point v1; //Vértice
    Point v2; //Vértice
    Point v3; //Vértice
    Point v1v2; // Vetor vertice 1 para vertice 2
    Point v1v3; // Vetor vertice 1 para vertice 3
    Point v2v3; // Vetor vertice 2 para vertice 3
    Point v3v1; // Vetor vertice 3 para vertice 1
    Point normal; // Vetor normal a face
    Point planeIntersection(Point rayOrigin, Point rayDirection); //Função que verifica se houve interssecção com o plano
    Point rayIntersection(Point rayOrigin, Point rayDirection); //Função que retorna o ponto caso haja interssecção
    void  SetCameraCoordinates(Matriz worldToCamera); //Aplica as coordenadas de câmera
    void  SetWorldCoordinates(Matriz cameraToWorld); //aplica coordenadas de mundo
    Point getNormal(); //retorna o vetor normal à face
};