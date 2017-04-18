import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls.Material 2.1

ApplicationWindow {
    visible: true
    width: 480
    height: 320
    title: qsTr("smartHomeApp")

    Material.theme: Material.Dark
    Material.accent: Material.Cyan
    Material.foreground: Material.Cyan
    Material.primary: Material.Orange

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        WeatherData {
        }
        Page{
        }

        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("First")
        }
        TabButton {
            text: qsTr("Bonsai")
        }
        TabButton {
            text: qsTr("Last")
        }
    }
}
