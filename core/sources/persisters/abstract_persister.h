#ifndef ABSTRACTPERSISTER_H
#define ABSTRACTPERSISTER_H

#include <iostream>
#include <list>
#include "core_traits.h"

namespace core
{
        class AbstractPersister
        {
        public:
            AbstractPersister();
            virtual ~AbstractPersister();

            virtual std::ostream& out(const std::string& entry) = 0;
            virtual std::istream& in(const std::string& entry) = 0;
            virtual bool hasEntry(const std::string& entry) const = 0;
            virtual std::list<std::string> avalibleEntries() const = 0;
        };
}

#endif // ABSTRACTPERSISTER_H
