#include "abstract_space.h"

using namespace core;

class AbstractSpace::AbstractSpacePrivate
{
public:

};

AbstractSpace::AbstractSpace():
    d(new AbstractSpacePrivate())
{}

AbstractSpace::~AbstractSpace()
{
    delete d;
}

