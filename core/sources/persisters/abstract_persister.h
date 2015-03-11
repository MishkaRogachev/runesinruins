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

            virtual bool hasEntry(const QString& entry) const = 0;
            virtual const QStringList& avalibleEntries() const = 0;
        };
}

#endif // ABSTRACTPERSISTER_H
