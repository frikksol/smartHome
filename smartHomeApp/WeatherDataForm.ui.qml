import QtQuick 2.7
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Universal 2.0
import QtQuick.Templates 2.1

Item {
    id: item1
    width: 400
    height: 400
    property alias indoorTemperatureText: indoorTemperatureText

    Text {
        id: weatherDataText
        y: 9
        text: qsTr("Weather Data")
        font.family: "Tahoma"
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.top: parent.top
        anchors.topMargin: 8
        font.pixelSize: 20
    }

    Text {
        id: indoorText
        y: 324
        text: qsTr("Indoor")
        anchors.left: parent.left
        anchors.leftMargin: 60
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 60
        font.pixelSize: 12
    }

    Text {
        id: outdoorText
        x: 294
        y: 324
        text: qsTr("Outdoor")
        anchors.right: parent.right
        anchors.rightMargin: 60
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 60
        font.pixelSize: 12
    }

    Text {
        id: indoorTemperatureText
        x: 65
        y: 304
        text: qsTr("Text")
        anchors.bottom: indoorText.top
        anchors.bottomMargin: 6
        anchors.horizontalCenter: indoorText.horizontalCenter
        font.pixelSize: 12
    }
}
