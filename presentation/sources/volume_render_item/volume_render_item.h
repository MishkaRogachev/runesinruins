#ifndef VOLUME_RENDER_ITEM_H
#define VOLUME_RENDER_ITEM_H

#include <QQuickItem>

namespace presentation
{
    class VolumeRenderItem: public QQuickItem
    {
        Q_OBJECT

    public:
        VolumeRenderItem(QQuickItem* parent = nullptr);
        virtual ~VolumeRenderItem() override;
    };
}
#endif // VOLUME_RENDER_ITEM_H
