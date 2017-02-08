import QtQuick 2.4
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Item {
    id: item1
    width: 400
    height: 400

    GridLayout {
        id: gridLayout
        anchors.fill: parent

        Label {
            id: bonsaiLabel
            text: qsTr("Bonsai Tree")
            font.pointSize: 20
            verticalAlignment: Text.AlignTop
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 20
        }
    }
}
