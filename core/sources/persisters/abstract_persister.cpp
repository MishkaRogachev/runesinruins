#include "abstract_persister.h"

using namespace core;

AbstractPersister::AbstractPersister()
{}

AbstractPersister::~AbstractPersister()
{}

void AbstractPersister::clear()
{
    for (const QString& entry: this->avalibleEntries())
    {
        this->remove(entry);
    }
}

