import QtQuick 2.1
import presentation 1.0

Rectangle {
    id: root
    color: "#c22959"
    gradient: Gradient {
        GradientStop {
            position: 0.00;
            color: "#16dba7";
        }
        GradientStop {
            position: 1.00;
            color: "#b52459";
        }
    }

    VolumeRenderItem {
        id: rendeder
        anchors.fill: parent
    }
}
