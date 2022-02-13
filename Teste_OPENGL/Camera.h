#pragma once
#include "axx.h"

// Classe camera
class Camera {
public:
    Point eye; //posição do observador
    Point lookAt; //para onde a camera está olhando
    Point viewUp; // ponto de orientação
    Point k; //vetor auxiliar
    Point i; //vetor auxiliar
    Point j; //vetor auxiliar
    double d;
    double plano_tamanho;
    Camera();
    Camera(Point eye, Point lookAt, Point viewUp, int d, int plano_tamanho);
    Matriz worldToCamera(); //Gera a matriz de mudança de coordenadas de mundo para coordenadas de camera
    Matriz cameraToWorld(); //Gera a matriz de mudança de coordenadas de camera para coordenadas de mundo
    void update(); //Atualiza a camera
    void moveX(float x); // muda a posição da camera no eixo X
    void moveY(float y); // muda a posição da camera no eixo Y
    void moveZ(float z); // muda a posição da camera no eixo Z
    void moveTo(Point eye); //move a câmera para um ponto especifico
};