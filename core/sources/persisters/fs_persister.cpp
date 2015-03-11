#include "fs_persister.h"

#include <QFile>
#include <QDir>

using namespace core;

FsPersister::FsPersister():
    AbstractPersister(),
    m_dir(QDir::current()),
    m_extension("txt")
{}

FsPersister::FsPersister(const QString& path, const QString& extension):
    AbstractPersister(),
    m_dir(path),
    m_extension(extension)
{}

FsPersister::~FsPersister()
{}

#include <QDebug>
QStringList FsPersister::avalibleEntries() const
{
    QStringList entries;
    for (QString& filename: m_dir.entryList(QDir::Files |
                                            QDir::NoDotAndDotDot))
    {

       QString entry  = this->entryFromFilename(filename);
       if (entry.isEmpty()) continue;
       entries.append(entry);
    }
    return entries;
}

QByteArray FsPersister::load(const QString& entry)
{
    QFile file(m_dir.absoluteFilePath(this->filenameFromEntry(entry)));

    if (!file.open(QFile::ReadOnly)) return QByteArray();
    return this->decode(file.readAll());
}

void FsPersister::save(const QString& entry, const QByteArray& data)
{
    QFile file(m_dir.absoluteFilePath(this->filenameFromEntry(entry)));

    if (!file.open(QFile::WriteOnly)) return;
    file.write(this->encode(data));
}

void FsPersister::remove(const QString& entry)
{
    QFile::remove(m_dir.absoluteFilePath(this->filenameFromEntry(entry)));
}

bool FsPersister::hasEntry(const QString& entry) const
{
    QFile file(m_dir.absoluteFilePath(this->filenameFromEntry(entry)));
    return file.exists();
}

QString FsPersister::path() const
{
    return m_dir.path();
}

void FsPersister::setPath(const QString& path)
{
    m_dir.setPath(path);
}

QString FsPersister::extension() const
{
    return m_extension;
}

void FsPersister::setExtension(const QString& extension)
{
    m_extension = extension;
}

QString FsPersister::filenameFromEntry(const QString& entry) const
{
    return m_extension.isEmpty() ? entry : entry + QString(".") + m_extension;
}

QString FsPersister::entryFromFilename(const QString& filename) const
{
    if (m_extension.isEmpty())
    {
        return filename.contains(".") ? QString() : filename;
    }

    int index = filename.lastIndexOf("." + m_extension);
    if (index == -1) return QString();
    return filename.left(index);
}

