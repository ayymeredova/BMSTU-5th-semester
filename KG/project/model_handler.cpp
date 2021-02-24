#include "model_handler.h"
#include <iostream>
#include <fstream>
#include <string>
//#include "tree.h"
#include "leaf.h"
//#include "branch.h"

Error_t model_handler(Action action, Request r)
{
    static Model3D *m = model3d_init();
    Error_t rc = OK;

    switch (action)
    {
    case GET:
        rc = get_model(*m, r.get);
        break;
    case TRANSLATE:
        m->transform->setTranslation(QVector3D(r.translate.vec.x, r.translate.vec.y, r.translate.vec.z));
        break;
    case DRAW:
    {
        /*int maxDist = 10;
        int minDist = 100;
        Tree theTree(10, 100); */ //max and min distant

        auto leaves = QVector<Line>{
            {{ 0, 0, 0 }, { 0, 0, 0 }},
            {{ 0, 0, 0 }, { 0,0, 0 }}
        };

//        auto branches = QVector<Line>{
//            {{ 0, 0, 0 }, { 0, 0, 0 }},
//            {{ 0, 0, 0 }, { 0,0, 0 }}
//        };




        // TODO
        // Read points file
        // Create fractal -> lines
        auto points = read_points("points.txt");
        bool foundLeaf = false;

        // visualization, удалить потом
        int leafX, leafY, leafZ;
        float branchX, branchY, branchZ;

        while(!foundLeaf)
        {
            auto l = points.length();
            printf("SIZE = %d", l);
            for (int i = 0; i < l; i++)
            {
                auto& t = points[i];
                lines.push_back({t, {t.x(), t.y(), t.z()}});
    //                printf("\n%f %f %f", t.x(), t.y(), t.z());
            }
        }

        drawLines(lines, m->mesh);
        break;
    }

    default:
        rc = ERR_CMD;
    }

    return rc;
}







