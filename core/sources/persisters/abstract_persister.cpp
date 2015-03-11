#include "abstract_persister.h"

using namespace core;

AbstractPersister::AbstractPersister()
{}

AbstractPersister::~AbstractPersister()
{}

QByteArray AbstractPersister::encode(const QByteArray& data) const
{
    return data;
}

QByteArray AbstractPersister::decode(const QByteArray& data) const
{
    return data;
}

void AbstractPersister::clear()
{
    for (const QString& entry: this->avalibleEntries())
    {
        this->remove(entry);
    }
}

