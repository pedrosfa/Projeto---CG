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
    Point ka; //Coeficientes p/ ilumina��o ambiente
    Point kd; //Coeficientes p/ ilumina��o difusa
    Point ks; //Coeficientes p/ ilumina��o especular
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

//Fun��o auxiliar (Converte de Vector3f para Vector4f)
Vertex PointToVertex(Point p);

//Fun��o auxiliar (Converte de Vector4f para Vector3f)
Point VertexToPoint(Vertex p);

//Classe da face, utilizada apenas no cubo, e potencialmente em qualquer objeto representado por uma estrutura de dados
class Face {
public:
    Face();
    Face(Point v1, Point v2, Point v3);
    Point v1; //V�rtice
    Point v2; //V�rtice
    Point v3; //V�rtice
    Point v1v2; // Vetor vertice 1 para vertice 2
    Point v1v3; // Vetor vertice 1 para vertice 3
    Point v2v3; // Vetor vertice 2 para vertice 3
    Point v3v1; // Vetor vertice 3 para vertice 1
    Point normal; // Vetor normal a face
    Point planeIntersection(Point rayOrigin, Point rayDirection); //Fun��o que verifica se houve interssec��o com o plano
    Point rayIntersection(Point rayOrigin, Point rayDirection); //Fun��o que retorna o ponto caso haja interssec��o
    void  SetCameraCoordinates(Matriz worldToCamera); //Aplica as coordenadas de c�mera
    void  SetWorldCoordinates(Matriz cameraToWorld); //aplica coordenadas de mundo
    Point getNormal(); //retorna o vetor normal � face
};