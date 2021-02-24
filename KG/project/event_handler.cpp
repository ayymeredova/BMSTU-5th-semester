#include "event_handler.h"



void EventHandler::translate()
{
    r.translate = { vTranslate };
    model_handler(TRANSLATE , r);
}

void EventHandler::transX(int n)
{
    vTranslate.x = n;
    this->translate();
}

void EventHandler::transY(int n)
{
    vTranslate.y = n;
    this->translate();
}

void EventHandler::transZ(int n)
{
    vTranslate.z = n;
    this->translate();
}

void EventHandler::draw(bool checked)
{
    model_handler(DRAW , {});
}
