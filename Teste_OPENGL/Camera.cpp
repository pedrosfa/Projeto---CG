#include "Camera.h"

//Construtores

Camera::Camera() {};

Camera::Camera(Point eye, Point lookAt, Point viewUp, int d, int plano_tamanho) : d(d), plano_tamanho(plano_tamanho) {
    this->eye = eye;
    this->lookAt = lookAt;
    this->viewUp = viewUp;

    this->k = (eye - lookAt).normalized();
    this->i = ((viewUp - eye).cross(k)).normalized();
    this->j = (k.cross(i)).normalized();
};

//Métodos

//gera a matriz de mudança de coordenadas de mundo para camera
Matriz Camera::worldToCamera()
{
    Matriz worldToCamera;
    worldToCamera << i[0], i[1], i[2], -i.dot(eye),
        j[0], j[1], j[2], -j.dot(eye),
        k[0], k[1], k[2], -k.dot(eye),
        0, 0, 0, 1;
    return worldToCamera;
};

//gera a matriz de mudança de coordenadas de camera para mundo
Matriz Camera::cameraToWorld() {
    Matriz cameraToWorld;
    cameraToWorld << i[0], j[0], k[0], eye[0],
        i[1], j[1], k[1], eye[1],
        i[2], j[2], k[2], eye[2],
        0, 0, 0, 1;
    return cameraToWorld;
};

//atualiza a camera
void Camera::update() {
    this->eye = eye;
    this->lookAt = lookAt;
    this->viewUp = viewUp;

    Point k = (eye - lookAt).normalized();

    Point i = (viewUp.cross(k)).normalized();
    Point j = (k.cross(i)).normalized();
};

//move a camera no eixo X
void Camera::moveX(float x)
{
    this->eye.x() += x;
    update();
};

//move a camera no eixo Y
void Camera::moveY(float y)
{
    this->eye.y() += y;
    update();
};

//move a camera no eixo Z
void Camera::moveZ(float z)
{
    this->eye.z() += z;
    update();
};

//move a camera para um ponto especifico
void Camera::moveTo(Point eye)
{
    this->eye = eye;
    update();
};