#ifndef FSPERSISTER_H
#define FSPERSISTER_H

#include "abstract_persister.h"

#include <QDir>

namespace core
{
    class FsPersister: public AbstractPersister
    {
    public:
        FsPersister(const QString& extension = "txt",
                    const QString& path = QDir::currentPath());
        virtual ~FsPersister() override;

        virtual QStringList avalibleEntries() const override;
        virtual QByteArray load(const QString& entry) override;
        virtual void save(const QString& entry, const QByteArray& data) override;
        virtual void remove(const QString& entry) override;
        virtual bool hasEntry(const QString& entry) const override;

        QString extension() const;
        void setExtension(const QString& extension);

        QString path() const;
        void setPath(const QString& path);

    protected:
        virtual QString filenameFromEntry(const QString& entry) const;
        virtual QString entryFromFilename(const QString& filename) const;

    private:
        QString m_extension;
        QDir m_dir;
    };
}

#endif // FSPERSISTER_H
