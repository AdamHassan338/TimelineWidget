#ifndef TRACK_H
#define TRACK_H

#include "Clip.h"
#include <vector>

struct Track
{
    Track() {}
    std::vector<Clip> clips;

};

#endif // TRACK_H
