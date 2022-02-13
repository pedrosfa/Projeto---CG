#include "Scenary.h"
#include <numeric>

//Construtor
Scenary::Scenary() {
    canvas_opengl = new float[HEIGHT * WIDTH * 3];
};

//Métodos

//Insere objeto
void Scenary::addShape(Shape* shape)
{
    this->shapes.push_back(shape);
};

//Insere fonte luminosa
void Scenary::addLight(Lighting* light)
{
    this->lights.push_back(light);
};

//Determina a câmera
void Scenary::setCamera(Camera camera)
{
    this->camera = camera;
};

//Determina a iluminação ambiente
void Scenary::setAmbientLight(AmbientLighting ambientLight)
{
    this->ambientLight = ambientLight;
};

//Aplica coordenadas de mundo nos objetos e nas fontes luminosas
void Scenary::setWorldCoordinates()
{
    for (int i = 0; i < this->shapes.size(); i++) {
        this->shapes[i]->setWorldCoordinates(this->camera.cameraToWorld());
    }
    for (int i = 0; i < this->lights.size(); i++) {
        this->lights[i]->setWorldCoordinates(this->camera.cameraToWorld());
    }
};

//Aplica coordenadas de camera nos objetos e nas fontes luminosas
void Scenary::setCameraCoordinates()
{
    for (int i = 0; i < this->shapes.size(); i++) {
        this->shapes[i]->setCameraCoordinates(this->camera.worldToCamera());
    }

    for (int i = 0; i < this->lights.size(); i++) {
        this->lights[i]->setCameraCoordinates(this->camera.worldToCamera());
    }
};


//Realiza o processo de raycasting
void Scenary::rayCasting()
{
    this->setCameraCoordinates(); //aplica coordenadas de camera
    Point intersect;

    double x, y, z;

    z = camera.d; // distancia da camera para o plano de projeção

    double deslocamento = camera.plano_tamanho / HEIGHT; //só faço uma vez visto que os lados têm o mesmo tamanho

    int idx = 0;

    Point rayOrigin = Point(0, 0, 0);
    //Preenche a matriz de pixels
    for (int j = 0; j < HEIGHT; j++)
    {
        //y = camera.plano_tamanho / 2 - deslocamento - j * deslocamento;
        y = -camera.plano_tamanho / 2 + deslocamento + j * deslocamento;
        for (int k = 0; k < WIDTH; k++)
        {
            //x = camera.plano_tamanho / 2 - deslocamento - k * deslocamento;
            x = -camera.plano_tamanho / 2 + deslocamento + k * deslocamento;

            Point nearest_point = Point(MAXFLOAT, MAXFLOAT, MAXFLOAT);

            Point rayDirection = Point(x, y, z);

            Shape* obj;

            for (int i = 0; i < this->shapes.size(); i++)
            {
                intersect = this->shapes[i]->rayIntersect(rayOrigin, rayDirection); //Para cada ponto de interssecção que um raio acha com cada um dos objetos da cena
                if (intersect.norm() < nearest_point.norm()) { // pega o mais próximo da camera
                    nearest_point = intersect;
                    obj = shapes[i];
                }
            }

            if (nearest_point[2] < MAXFLOAT) { //se houve uma interssecção válida calcula a intensidade da luz naquele ponto
                Point intensity = this->ambientLight.ambientIntensity(nearest_point, obj->mat);

                for (int l = 0; l < this->lights.size(); l++) {
                    intensity += this->lights[l]->difuseIntensity(nearest_point, obj->normal(nearest_point), obj->mat);
                    intensity += this->lights[l]->specularIntensity(nearest_point, obj->normal(nearest_point), obj->mat);
                }

                this->frame[idx * 3] = intensity[0];
                this->frame[idx * 3 + 1] = intensity[1];
                this->frame[idx * 3 + 2] = intensity[2];
            }
            else //se não houve interssecção válida, pinta o background
            {
                frame[idx * 3] = BG[0];
                frame[idx * 3 + 1] = BG[1];
                frame[idx * 3 + 2] = BG[2];
            }

            idx++;
        }
    }
};