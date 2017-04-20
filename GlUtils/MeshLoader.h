//
// Created by opot on 21.04.17.
//

#ifndef GLUTGL_MESHLOADER_H
#define GLUTGL_MESHLOADER_H

#include <string>

#include "Mesh.h"

namespace fjfj {

    class MeshLoader {
    public:
        static Mesh *LoadMesh(std::string path);
    };

}


#endif //GLUTGL_MESHLOADER_H
