#ifndef ABSTRACTPERSISTER_H
#define ABSTRACTPERSISTER_H

#include <QStringList>
#include <QByteArray>

#include "core_traits.h"

namespace core
{
    class AbstractPersister
    {
    public:
        AbstractPersister();
        virtual ~AbstractPersister();

        virtual QStringList avalibleEntries() const = 0;
        virtual QByteArray load(const QString& entry) = 0;
        virtual void save(const QString& entry, const QByteArray& data) = 0;
        virtual void remove(const QString& entry) = 0;
        virtual bool hasEntry(const QString& entry) const = 0;

        virtual QByteArray encode(const QByteArray& data) const;
        virtual QByteArray decode(const QByteArray& data) const;

        void clear();
    };
}

#endif // ABSTRACTPERSISTER_H
