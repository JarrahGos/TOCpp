import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Window 2.1

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Grid {
        id: grid1
        anchors.rightMargin: 0
        anchors.bottomMargin: -1
        anchors.leftMargin: 0
        anchors.topMargin: 1
        anchors.fill: parent
        spacing: 2
        rows: 10
        columns: 10

        Label {
            id: label1
            width: 170
            height: 23
            text: qsTr("Enter Your PMKeyS:")
            anchors.bottom: applicationWindow1.top
            anchors.bottomMargin: -23
            font.pointSize: 13
        }

        TextField {
            id: textField1
            x: 171
            y: 1
            text: "Enter PMKeyS"
            placeholderText: qsTr("Text Field")
        }

        Button {
            id: button1
            x: 280
            width: 29
            height: 21
            text: qsTr("OK")
        }

        Button {
            id: button2
            x: 550
            text: qsTr("Button")
        }
    }
}
