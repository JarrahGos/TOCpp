import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Window 2.1

ApplicationWindow {
    id: userWindow
    visible: true
    width: 1024
    height: 576
    title: qsTr("TOC19")

//    menuBar: MenuBar {
//        Menu {
//            title: qsTr("File")
//            MenuItem {
//                text: qsTr("Exit")
//                onTriggered: Qt.quit();
//            }
//        }
//    }

    ListView {
        id: productListView
        x: 8
        y: 64
        width: 768
        height: 454
        antialiasing: true
        boundsBehavior: Flickable.DragAndOvershootBounds
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row1
                spacing: 10
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
            }
        }
        model: ListModel {
            //ListElement {
            //    name: "Grey"
            //    colorCode: "grey"
            //}

            //ListElement {
            //    name: "Red"
            //    colorCode: "red"
            //}

            //ListElement {
            //    name: "Blue"
            //    colorCode: "blue"
            //}

            //ListElement {
            //    name: "Green"
            //    colorCode: "green"
            //}
        }
    }

    ListView {
        id: priceListView
        x: 782
        y: 64
        width: 234
        height: 454
        antialiasing: true
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row2
                spacing: 10
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
            }
        }
        model: ListModel {
            //ListElement {
            //    name: "Grey"
            //    colorCode: "grey"
            //}

            //ListElement {
            //    name: "Red"
            //    colorCode: "red"
            //}

            //ListElement {
            //    name: "Blue"
            //    colorCode: "blue"
            //}

            //ListElement {
            //    name: "Green"
            //    colorCode: "green"
            //}
        }
    }

    Button {
        id: adminButton
        x: 8
        y: 524
        width: 121
        height: 44
        text: qsTr("Enter Admin Mode")
    }

    Label {
        id: textEntryLabel
        x: 8
        y: 10
        width: 174
        height: 48
        text: qsTr("Enter Your PMKeyS")
        clip: false
        style: Text.Normal
        font.pointSize: 14
        verticalAlignment: Text.AlignVCenter
    }

    TextField {
        id: entryTextField
        x: 188
        y: 9
        width: 180
        height: 49
        placeholderText: qsTr("Text Field")
    }

    Button {
        id: enterTextFieldButton
        x: 374
        y: 8
        width: 50
        height: 50
        text: qsTr("OK")
        onButtonClick: workingUser.getPMKeyS(input);
    }

    Button {
        id: cancelButton
        x: 936
        y: 15
        width: 80
        height: 35
        text: qsTr("Cancel")
        onButtonClick: workingUser.logout()
    }

    Label {
        id: totalPriceLabel
        x: 675
        y: 524
        width: 101
        height: 45
        text: qsTr("Total Price:")
        horizontalAlignment: Text.AlignRight
        font.pointSize: 14
        verticalAlignment: Text.AlignVCenter
    }

    TextField {
        id: totalPriceTextField
        x: 782
        y: 524
        width: 102
        height: 48
        font.pointSize: 13
        readOnly: true
        placeholderText: qsTr("Total Price")
    }

    Button {
        id: purchaseButton
        x: 890
        y: 524
        width: 126
        height: 44
        text: qsTr("Purchase")
        onButtonClick: workingUser.buyProducts()
    }

    Text {
        id: nameText
        x: 466
        y: 17
        width: 390
        height: 33
        text: qsTr("")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 13
    }
    
    Button {
        id: button1
        x: 579
        y: 524
        width: 90
        height: 44
        text: qsTr("Delete Item")
    }
}
