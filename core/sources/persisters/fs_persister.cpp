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
    QStringList result =
            m_dir.entryList(QStringList() << QString("*.%1").arg(m_extension),
                            QDir::Files | QDir::NoDotAndDotDot);

    qDebug() << result;
    for (QString& entry: result)
    {
       QStringList splitted = entry.split(".",QString::SkipEmptyParts);
       if (splitted.empty()) continue;
       entry = splitted.first();
    }

    return result;
}

QByteArray FsPersister::load(const QString& entry)
{
    QFile file(this->filepathFromEntry(entry));

    if (!file.open(QFile::ReadOnly)) return QByteArray();
    return this->decode(file.readAll());
}

void FsPersister::save(const QString& entry, const QByteArray& data)
{
    QFile file(this->filepathFromEntry(entry));

    if (!file.open(QFile::WriteOnly)) return;
    file.write(this->encode(data));
}

void FsPersister::remove(const QString& entry)
{
    QFile::remove(this->filepathFromEntry(entry));
}

bool FsPersister::hasEntry(const QString& entry) const
{
    QFile file(this->filepathFromEntry(entry));
    return file.exists();
}

QString FsPersister::filepathFromEntry(const QString& entry) const
{
    QString filepath = m_dir.absoluteFilePath(entry);
    return m_extension.isEmpty() ? filepath :
                filepath + QString(".%1").arg(m_extension);
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


