//
// Created by opot on 21.04.17.
//

#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <vector>

#include "MeshLoader.h"



namespace fjfj{

    struct Vertex3{
        float x, y, z;
    };

    struct Vertex2 {
        float x, y;
    };

    struct Face {
        int x, y, z;
    };


    std::istream& operator >>(std::istream &in, Vertex2 & v){
        return in >> v.x >> v.y;
    }
    std::istream& operator >>(std::istream &in, Vertex3 & v){
        return in >> v.x >> v.y >> v.z;
    }
    std::istream& operator >>(std::istream &in, Face & v){
        char buf;
        return in >> v.x >> buf >> v.y >> buf >> v.z;
    }

    Mesh* MeshLoader::LoadMesh(std::string path) {
        std::ifstream fin(path);

        std::vector<Vertex3> vertices;
        std::vector<Vertex3> normals;
        std::vector<Vertex2> texCoords;

        std::vector<Face> faces;

        while(!fin.eof()){
            char type;
            fin >> type;

            if(type == 'v'){
                type = (char)fin.get();

                if(type == ' '){
                    Vertex3 v;
                    fin >> v;
                    vertices.push_back(v);
                }

                if(type == 'n'){
                    Vertex3 v;
                    fin >> v;
                    normals.push_back(v);
                }

                if(type == 't'){
                    Vertex2 v;
                    fin >> v;
                    texCoords.push_back(v);
                }
                continue;
            }

            if(type == 'f'){
                Face v;
                fin >> v;
                faces.push_back(v);
                fin >> v;
                faces.push_back(v);
                fin >> v;
                faces.push_back(v);
                continue;
            }

            char buf[1000];
            fin.getline(buf, 1000);
        }

        GLfloat *vertexData = new GLfloat[faces.size() * 8];
        for(int i = 0; i < faces.size(); i++){
            vertexData[i * 8 + 0] = vertices[faces[i].x - 1].x;
            vertexData[i * 8 + 1] = vertices[faces[i].x - 1].y;
            vertexData[i * 8 + 2] = vertices[faces[i].x - 1].z;

            vertexData[i * 8 + 3] = normals[faces[i].z - 1].x;
            vertexData[i * 8 + 4] = normals[faces[i].z - 1].y;
            vertexData[i * 8 + 5] = normals[faces[i].z - 1].z;

            vertexData[i * 8 + 6] = texCoords[faces[i].y - 1].x;
            vertexData[i * 8 + 7] = 1 - texCoords[faces[i].y - 1].y;
        }

        Mesh* res = new Mesh(vertexData, (int)faces.size());
        delete vertexData;
        fin.close();
        return res;

    }

}
