#include "axx.h"

//função auxiliar de conversão
Vertex PointToVertex(Point p) {
    Vertex r(p[0], p[1], p[2], 1);
    return r;
}
//função auxiliar de conversão
Point VertexToPoint(Vertex p) {
    Point r(p[0], p[1], p[2]);
    return r;
}

//------------------------Material--------------------------//

//Construtores
Material::Material() {};
Material::Material(Point ka, Point kd, Point ks, float shininess)
{
    this->ka = ka;
    this->kd = kd;
    this->ks = ks;
    this->shininess = shininess;
};

//------------------------Face---------------------------//

//Construtores

Face::Face() {
    v1 = Point(MAXFLOAT, MAXFLOAT, MAXFLOAT);
    v2 = Point(MAXFLOAT, MAXFLOAT, MAXFLOAT);
    v3 = Point(MAXFLOAT, MAXFLOAT, MAXFLOAT);
};

Face::Face(Point vertex1, Point vertex2, Point vertex3) {
    this->v1 = vertex1;
    this->v2 = vertex2;
    this->v3 = vertex3;
    this->v1v2 = this->v2 - this->v1;
    this->v1v3 = this->v3 - this->v1;
    this->v2v3 = this->v3 - this->v2;
    this->v3v1 = this->v1 - this->v3;

    this->normal = (v1v2.cross(v1v3)).normalized();
}

//Métodos
//verifica se um raio intercepta o plano da face, retornar um ponto inválido caso não
Point Face::planeIntersection(Point rayOrigin, Point rayDirection)
{
    float t;
    Point v_aux1 = this->v1 - rayOrigin;
    float prod = this->normal.dot(rayDirection);

    if (prod == 0)
    {
        return Point(MAXFLOAT, MAXFLOAT, MAXFLOAT);
    }

    else
    {
        t = (this->normal.dot(v_aux1)) / prod;
    }
    Point planeIntersection = rayOrigin + (rayDirection * t);
    return planeIntersection;
};

//verifica se o raio tem alguma interssecção válida com a face
Point Face::rayIntersection(Point rayOrigin, Point rayDirection)
{
    //vê se há interssecção
    Point planeIntersection = this->planeIntersection(rayOrigin, rayDirection);

    //verifica se há interssecção válida
    if (planeIntersection[2] == MAXFLOAT)
    {
        return Point(MAXFLOAT, MAXFLOAT, MAXFLOAT);
    }

    //Verifica se, caso a interssecação com o plano da face seja válida, se está dentro dos limites da face

    Point p1p2 = this->v2 - this->v1;
    Point p1p3 = this->v3 - this->v1;
    Point p2p3 = this->v3 - this->v2;
    Point p3p1 = this->v1 - this->v3;

    Point n = (p1p2.cross(p1p3)).normalized();

    Point p1pi = planeIntersection - this->v1;
    Point p2pi = planeIntersection - this->v2;
    Point p3pi = planeIntersection - this->v3;


    if (p1p2.cross(p1pi).dot(p1p2.cross(p1p3)) < 0)
        return Point(MAXFLOAT, MAXFLOAT, MAXFLOAT);

    if (p2p3.cross(p2pi).dot(p1p2.cross(p1p3)) < 0)
        return Point(MAXFLOAT, MAXFLOAT, MAXFLOAT);

    if (p3p1.cross(p3pi).dot(p1p2.cross(p1p3)) < 0)
        return Point(MAXFLOAT, MAXFLOAT, MAXFLOAT);


    return planeIntersection;
}

//aplica coordenadas de camera
void Face::SetCameraCoordinates(Matriz worldToCamera)
{
    Vertex a = PointToVertex(this->v1v2);
    Vertex b = PointToVertex(this->v1v3);
    Vertex c = PointToVertex(this->v2v3);
    Vertex d = PointToVertex(this->v3v1);

    a = worldToCamera * a;
    b = worldToCamera * b;
    c = worldToCamera * c;
    d = worldToCamera * d;

    v1v2 = VertexToPoint(a);
    v1v3 = VertexToPoint(b);
    v2v3 = VertexToPoint(c);
    v3v1 = VertexToPoint(d);

    this->normal = v1v2.cross(v1v3).normalized();
}

//Aplica coordenadas de mundo
void Face::SetWorldCoordinates(Matriz cameraToWorld)
{
    Vertex a = PointToVertex(this->v1v2);
    Vertex b = PointToVertex(this->v1v3);
    Vertex c = PointToVertex(this->v2v3);
    Vertex d = PointToVertex(this->v3v1);

    a = cameraToWorld * a;
    b = cameraToWorld * b;
    c = cameraToWorld * c;
    d = cameraToWorld * d;

    v1v2 = VertexToPoint(a);
    v1v3 = VertexToPoint(b);
    v2v3 = VertexToPoint(c);
    v3v1 = VertexToPoint(d);

    this->normal = v1v2.cross(v1v3).normalized();
}

//Retorna a normal
Point Face::getNormal()
{
    return this->normal;
};