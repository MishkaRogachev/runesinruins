#ifndef ABSTRACTSPACE_H
#define ABSTRACTSPACE_H

namespace core
{
    class AbstractSpace
    {
    public:
        AbstractSpace();
        virtual ~AbstractSpace();

    private:
        class AbstractSpacePrivate;
        AbstractSpacePrivate* d;
    };
}
#endif // ABSTRACTSPACE_H
