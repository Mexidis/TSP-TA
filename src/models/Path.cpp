//
// Created by pac61 on 31/08/2025.
//

#include "Path.h"

Path::Path(City origin, City destination, double weigth)
: origin(origin), destination(destination), weigth(weigth)
{
}


City Path::getOrigin() const
{
        return origin;
}

City Path::getDestination() const
{
        return destination;
}

double Path::getWeigth() const
{
        return weigth;
}

void Path::setOrigin(City new_origin)
{
        origin = new_origin;
}

void Path::setDestination(City new_destination)
{
        destination = new_destination;
}

void Path::setWeigth(double new_weigth)
{
        weigth = new_weigth;
}

