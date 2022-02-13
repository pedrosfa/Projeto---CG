#pragma once
#include "axx.h"
#include "rotation.h"

class Cube : public Shape
{
public:
    Cube();
    Cube(float side, Point  center, Material mat);
    float side; //tamanho de lado
    float sidex; //variável auxiliar
    float sidey; //variável auxiliar
    float sidez; //variável auxiliar
    Point center; //centro do cubo
    Point v1; //vertice do cubo
    Point v2; //vertice do cubo
    Point v3; //vertice do cubo
    Point v4; //vertice do cubo
    Point v5; //vertice do cubo
    Point v6; //vertice do cubo
    Point v7; //vertice do cubo
    Point v8; //vertice do cubo
    Point vertices[8]; //vetor de vertices
    Face faces[12]; //vetor de faces
    Point normal_intersect; //normal da camera com o ponto que a intercepta
    void Scaling(Point p); //aplica escala
    void Rotate(float angle, Point axis); //aplica rotação
    void Translating(Point p); //aplica translação
    void Mirror(Point axis); //aplica espelhamento
    void setCameraCoordinates(Matriz worldToCamera); //coordenadas de mundo para coordenadas de camera
    void setWorldCoordinates(Matriz cameraToWorld); //coordenadas de camera para coordenadas de mundo
    Point rayIntersect(Point rayOrigin, Point rayDirection); // Verifica se o raio intercepta
    void setNormal(Point intersect); // muda a normal
    Point normal(Point point); // calcula a normal
    //Point* Bounds();
    void updateFaces1(); //atualização das faces
    void updateFaces2(); //atualização das faces
};