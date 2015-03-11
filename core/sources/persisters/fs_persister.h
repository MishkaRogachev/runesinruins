#ifndef FSPERSISTER_H
#define FSPERSISTER_H

#include "abstract_persister.h"

#include <QDir>

namespace core
{
    class FsPersister: public AbstractPersister
    {
    public:
        FsPersister();
        FsPersister(const QString& path);
        virtual ~FsPersister() override;

        virtual QStringList avalibleEntries() const override;
        virtual QByteArray load(const QString& entry) override;
        virtual void save(const QString& entry, const QByteArray& data) override;
        virtual void remove(const QString& entry) override;
        virtual bool hasEntry(const QString& entry) const override;

    private:
        QDir m_dir;
    };
}

#endif // FSPERSISTER_H
