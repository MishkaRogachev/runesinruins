#include "fs_persister.h"

#include <QFile>
#include <QDir>

using namespace core;

FsPersister::FsPersister():
    AbstractPersister(),
    m_dir(QDir::current())
{}

FsPersister::FsPersister(const QString& path):
    AbstractPersister(),
    m_dir(path)
{}

FsPersister::~FsPersister()
{}

QStringList FsPersister::avalibleEntries() const
{
    return m_dir.entryList();
}

QByteArray FsPersister::load(const QString& entry)
{
    QFile file(m_dir.absoluteFilePath(entry));

    if (!file.open(QFile::ReadOnly)) return QByteArray();
    return this->decode(file.readAll());
}

void FsPersister::save(const QString& entry, const QByteArray& data)
{
    QFile file(m_dir.absoluteFilePath(entry));

    if (!file.open(QFile::WriteOnly)) return;
    file.write(this->encode(data));
}

void FsPersister::remove(const QString& entry)
{
    QFile::remove(m_dir.absoluteFilePath(entry));
}

bool FsPersister::hasEntry(const QString& entry) const
{
    QFile file(m_dir.absoluteFilePath(entry));
    return file.exists();
}

