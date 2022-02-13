#pragma once
#include "axx.h"

//Classe de luz, todas herdam (menos ambiente)
class Lighting {
public:
    float r; // Red
    float g; // Green
    float b; // Blue
    virtual float difuseFactor(Point point, Point normal) = 0; //calculo do fator difuso
    virtual float specularFactor(Point point, Point normal) = 0; //calculo do fator especular
    virtual Point difuseIntensity(Point point, Point normal, Material mat) = 0; // calcula intesidade difusa
    virtual Point specularIntensity(Point point, Point normal, Material mat) = 0; // calcula intensidade especular
    virtual void setCameraCoordinates(Matriz worldToCamera) = 0; //mudança de sistema de coordenadas
    virtual void setWorldCoordinates(Matriz cameraToWorld) = 0; //mudança de sistema de coordenadas
    Lighting();
};
//Luz ambiente
class AmbientLighting
{
public:
    float r;
    float g;
    float b;
    AmbientLighting();
    Point ambientIntensity(Point point, Material mat); //Calcula a intensidade ambiente
    AmbientLighting(float r, float g, float b);
};

//Luz spot
class SpotLighting : public Lighting
{
public:
    Point position; //posição
    Point direction; //direção
    float angle; //angulo de abertura
    SpotLighting(float r, float g, float b, Point position, Point direction, float angle);
    float difuseFactor(Point point, Point normal);
    float specularFactor(Point point, Point normal);
    Point difuseIntensity(Point point, Point normal, Material mat);
    Point specularIntensity(Point point, Point normal, Material mat);
    void setCameraCoordinates(Matriz worldToCamera);
    void setWorldCoordinates(Matriz cameraToWorld);
};
// Luz remota
class FarLighting : public Lighting
{
public:
    Point direction; //direção
    FarLighting(float r, float g, float b, Point direction);
    float difuseFactor(Point point, Point normal);
    float specularFactor(Point point, Point normal);
    Point difuseIntensity(Point point, Point normal, Material mat);
    Point specularIntensity(Point point, Point normal, Material mat);
    void setCameraCoordinates(Matriz worldToCamera);
    void setWorldCoordinates(Matriz cameraToWorld);
};

//Luz pontual 
class PointLighting : public Lighting
{
public:
    Point position; //posição
    PointLighting(float r, float g, float b, Point position);
    float difuseFactor(Point point, Point normal);
    float specularFactor(Point point, Point normal);
    Point difuseIntensity(Point point, Point normal, Material mat);
    Point specularIntensity(Point point, Point normal, Material mat);
    void setCameraCoordinates(Matriz worldToCamera);
    void setWorldCoordinates(Matriz cameraToWorld);
};