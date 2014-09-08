import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Window 2.1

ApplicationWindow {
    id: adminWindow
    visible: true
    width: 1024
    height: 576
    title: qsTr("TOC19")

    Column {
        id: lhsColomn
        x: 0
        y: 0
        width: 242
        height: 576

        ListView {
            id: menu
            anchors.fill: parent
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
                        font.bold: true
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
            }
        }
    }

    Row {
        id: topMunuRow
        x: 248
        width: 767
        height: 48
        anchors.top: parent.top
        anchors.topMargin: 0

        Button {
            id: peopleButton
            x: 0
            y: 0
            height: 40
            text: qsTr("People")
            anchors.verticalCenter: parent.verticalCenter
        }

        Button {
            id: productButton
            x: 0
            y: 0
            height: 40
            text: qsTr("Products")
            anchors.verticalCenter: parent.verticalCenter
        }

        Button {
            id: adminButton
            x: 0
            y: 0
            height: 40
            text: qsTr("Admin")
            anchors.verticalCenter: parent.verticalCenter
        }

        Button {
            id: logoutButton
            x: 240
            y: 4
            height: 40
            text: qsTr("Logout")
        }
    }
    Grid {

            id: selectedInterfaceGrid
            x: 248
            y: 54
            width: 767
            height: 508

            states: [
                         State {
                             name: "addPerson"

                             PropertyChanges {
                                 target: addPersonState
                                 visible: true
                             }
                         },
                         State {
                            name: "removePerson"

                            PropertyChanges {
                                target: removePersonState
                                visible: true
                            }
                        },
                        State {
                           name: "listPeople"
        
                           PropertyChanges {
                               target: listPersonState
                               visible: true
                           }
                       },
                        State {
                           name: "lockPeopleOut"
        
                           PropertyChanges {
                               target: lockPeopleOutState
                               visible: true
                           }
                       },
                        State {
                           name: "savePersonDatabase"
        
                           PropertyChanges {
                               target: savePersonDatabaseState
                               visible: true
                           }
                       },
                        State {
                           name: "addProducts"
        
                           PropertyChanges {
                               target: addProductsState
                               visible: true
                           }
                       },
                        State {
                           name: "removeProducts"
        
                           PropertyChanges {
                               target: removeProductsState
                               visible: true
                           }
                       },
                        State {
                           name: "changeProduct"
        
                           PropertyChanges {
                               target: changeProductState
                               visible: true
                           }
                       },
                        State {
                           name: "enterStockCounts"
        
                           PropertyChanges {
                               target: enterStockCountsState
                               visible: true
                           }
                       },
                        State {
                           name: "listProducts"
        
                           PropertyChanges {
                               target: listProductsState
                               visible: true
                           }
                       },
                        State {
                           name: "saveProductDatabase"
        
                           PropertyChanges {
                               target: saveProductDatabaseState
                               visible: true
                           }
                       },
                        State {
                           name: "resetBills"
        
                           PropertyChanges {
                               target: resetBillsState
                               visible: true
                           }
                       },
                        State {
                           name: "changePassword"
        
                           PropertyChanges {
                               target: changePasswordState
                               visible: true
                           }
                       },
                        State {
                           name: "saveDatabasesToUSB"
        
                           PropertyChanges {
                               target: saveDatabasesToUSBState
                               visible: true
                           }
                       },
                        State {
                           name: "closeProgram"
        
                           PropertyChanges {
                               target: closeTheProgramState
                               visible: true
                           }
                       }
                     ]

            Rectangle {
                id: addPersonState
                color: "#ffffff"
                z: 14
                anchors.fill: parent

                TextEdit {
                    id: pmkeysTextField
                    x: 190
                    y: 60
                    width: 110
                    height: 40
                    text: qsTr("Text Edit")
                    z: 1
                    anchors.left: parent.left
                    anchors.leftMargin: 391
                    anchors.top: parent.top
                    anchors.topMargin: 60
                    font.pixelSize: 20
                }

                Text {
                    id: pmkeysLabel
                    x: 140
                    y: 60
                    width: 68
                    height: 40
                    text: qsTr("Text")
                    z: 2
                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                    anchors.top: parent.top
                    anchors.topMargin: 60
                    anchors.left: parent.left
                    anchors.leftMargin: 317
                    font.pixelSize: 20
                }

                TextEdit {
                    id: nameTextField
                    x: 190
                    y: 20
                    width: 110
                    height: 40
                    text: qsTr("Text Edit")
                    z: 3
                    anchors.left: parent.left
                    anchors.leftMargin: 391
                    anchors.top: nameLabel.bottom
                    anchors.topMargin: -40
                    font.pixelSize: 20
                }

                Text {
                    id: nameLabel
                    x: 140
                    y: 20
                    width: 68
                    height: 40
                    text: qsTr("Name:")
                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                    visible: true
                    anchors.left: parent.left
                    anchors.leftMargin: 317
                    anchors.top: parent.top
                    anchors.topMargin: 20
                    font.pixelSize: 20
                }

                Button {
                    id: savePersonButton
                    x: 421
                    y: 106
                    width: 80
                    height: 33
                    text: qsTr("Save")
                }
            }

            Rectangle {
                id: removePersonState
                color: "#ffffff"
                z: 15
                anchors.fill: parent

                ListView {
                    id: removePeopleListView
                    x: 0
                    y: 0
                    width: 297
                    height: 508
                    model: ListModel {
                        ListElement {
                            name: "Grey"
                            colorCode: "grey"
                        }

                        ListElement {
                            name: "Red"
                            colorCode: "red"
                        }

                        ListElement {
                            name: "Blue"
                            colorCode: "blue"
                        }

                        ListElement {
                            name: "Green"
                            colorCode: "green"
                        }
                    }
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
                                font.bold: true
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }
                    }
                }

                Button {
                    id: removePersonButton
                    x: 303
                    y: 132
                    width: 80
                    height: 44
                    text: qsTr("Remove")
                }
            }

            Rectangle {
                id: listPersonState
                color: "#ffffff"
                z: 16
                anchors.fill: parent

                TextArea {
                    id: listPeopleOutput
                    x: 0
                    y: 0
                    width: 759
                    height: 500
                }
            }

            Rectangle {
                id: lockPeopleOutState
                color: "#ffffff"
                z: 17
                anchors.fill: parent

                ListView {
                    id: lockPersonListView
                    x: 0
                    y: 0
                    width: 268
                    height: 500
                    model: ListModel {
                        ListElement {
                            name: "Grey"
                            colorCode: "grey"
                        }

                        ListElement {
                            name: "Red"
                            colorCode: "red"
                        }

                        ListElement {
                            name: "Blue"
                            colorCode: "blue"
                        }

                        ListElement {
                            name: "Green"
                            colorCode: "green"
                        }
                    }
                    delegate: Item {
                        x: 5
                        width: 80
                        height: 40
                        Row {
                            id: row3
                            spacing: 10
                            Rectangle {
                                width: 40
                                height: 40
                                color: colorCode
                            }

                            Text {
                                text: name
                                font.bold: true
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }
                    }
                }

                ComboBox {
                    id: lockOutCombobox
                    x: 285
                    y: 211
                }
            }

            Rectangle {
                id: savePersonDatabaseState
                color: "#ffffff"
                z: 6
                anchors.fill: parent

                Label {
                    id: savePersonDatabaseLabel
                    x: 41
                    y: 0
                    text: qsTr("Save person database to adminPersonDatabase.txt?")
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                    font.pointSize: 20
                }

                Button {
                    id: savePersonDatabaseButton
                    x: 344
                    y: 36
                    width: 80
                    height: 30
                    text: qsTr("Save")
                }
            }

            Rectangle {
                id: addProductsState
                color: "#ffffff"
                z: 10
                anchors.fill: parent
                Text {
                    id: productNameLabel
                    width: 88
                    height: 40
                    text: qsTr("Name:")
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                    anchors.left: parent.left
                    anchors.leftMargin: 140
                    anchors.top: parent.top
                    anchors.topMargin: 14
                    font.pixelSize: 20
                }

                TextEdit {
                    id: productNameTextField
                    y: 14
                    width: 110
                    height: 40
                    text: qsTr("Text Edit")
                    anchors.left: parent.left
                    anchors.leftMargin: 228
                    anchors.top: nameLabel.bottom
                    anchors.topMargin: -40
                    font.pixelSize: 20
                }

                Text {
                    id: barCodeLabel
                    width: 88
                    height: 40
                    text: qsTr("Barcode:")
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                    anchors.top: parent.top
                    anchors.topMargin: 60
                    anchors.left: parent.left
                    anchors.leftMargin: 140
                    font.pixelSize: 20
                }

                TextEdit {
                    id: barCodeText
                    x: 249
                    width: 110
                    height: 40
                    text: qsTr("Text Edit")
                    anchors.left: parent.left
                    anchors.leftMargin: 228
                    anchors.top: parent.top
                    anchors.topMargin: 60
                    font.pixelSize: 20
                }
                Text {
                    id: priceLabel
                    width: 88
                    height: 40
                    text: qsTr("Price:")
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                    anchors.top: parent.top
                    anchors.topMargin: 106
                    anchors.left: parent.left
                    anchors.leftMargin: 140
                    font.pixelSize: 20
                }

                TextEdit {
                    id: priceText
                    width: 110
                    height: 40
                    text: qsTr("Text Edit")
                    anchors.left: parent.left
                    anchors.leftMargin: 228
                    anchors.top: parent.top
                    anchors.topMargin: 106
                    font.pixelSize: 20
                }

                Button {
                    id: saveProductButton
                    x: 228
                    y: 152
                    width: 110
                    height: 25
                    text: qsTr("Save")
                }
            }

            Rectangle {
                id: removeProductsState
                color: "#ffffff"
                z: 7
                anchors.fill: parent

                ListView {
                    id: removeProductsListView
                    x: 0
                    y: 0
                    width: 297
                    height: 508
                    model: ListModel {
                        ListElement {
                            name: "Grey"
                            colorCode: "grey"
                        }

                        ListElement {
                            name: "Red"
                            colorCode: "red"
                        }

                        ListElement {
                            name: "Blue"
                            colorCode: "blue"
                        }

                        ListElement {
                            name: "Green"
                            colorCode: "green"
                        }
                    }
                    delegate: Item {
                        x: 5
                        width: 80
                        height: 40
                        Row {
                            id: row5
                            spacing: 10
                            Rectangle {
                                width: 40
                                height: 40
                                color: colorCode
                            }

                            Text {
                                text: name
                                font.bold: true
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }
                    }
                }
                Button {
                    id: removeProductButton
                    x: 303
                    y: 132
                    width: 80
                    height: 44
                    text: qsTr("Remove")
                }
            }

            Rectangle {
                id: changeProductState
                color: "#ffffff"
                z: 8
                anchors.fill: parent

                ListView {
                    id: listView1
                    x: 0
                    y: 0
                    width: 283
                    height: 500
                    model: ListModel {
                        ListElement {
                            name: "Grey"
                            colorCode: "grey"
                        }

                        ListElement {
                            name: "Red"
                            colorCode: "red"
                        }

                        ListElement {
                            name: "Blue"
                            colorCode: "blue"
                        }

                        ListElement {
                            name: "Green"
                            colorCode: "green"
                        }
                    }
                    delegate: Item {
                        x: 5
                        width: 80
                        height: 40
                        Row {
                            id: row4
                            spacing: 10
                            Rectangle {
                                width: 40
                                height: 40
                                color: colorCode
                            }

                            Text {
                                text: name
                                font.bold: true
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }
                    }
                }

                Label {
                    id: changeProductNameLabel
                    x: 301
                    y: 148
                    text: qsTr("Name:")
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                    font.pointSize: 20
                }


                Label {
                    id: changeProductBarCodeLabel
                    x: 301
                    y: 199
                    text: "Barcode:"
                    font.pointSize: 20
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                }
                Label {
                    id: changeProductPriceLabel
                    x: 301
                    y: 249
                    text: qsTr("Price:")
                    font.pointSize: 20
                    horizontalAlignment: Text.AlignRight
                }

                TextField {
                    id: changeProductNameTextField
                    x: 423
                    y: 156
                    placeholderText: qsTr("Text Field")
                }

                TextField {
                    id: changeProductBarCodeTextField
                    x: 424
                    y: 207
                    placeholderText: qsTr("Text Field")
                }

                TextField {
                    id: changeProductPriceTextField
                    x: 424
                    y: 257
                    placeholderText: qsTr("Text Field")
                }

                Button {
                    id: changeProductSaveButton
                    x: 446
                    y: 302
                    text: qsTr("Save")
                }
            }

            Rectangle {
                id: enterStockCountsState
                color: "#ffffff"
                z: 9
                anchors.fill: parent

                ListView {
                    id: stockCountsListView
                    x: 8
                    y: 8
                    width: 291
                    height: 492
                    model: ListModel {
                        ListElement {
                            name: "Grey"
                            colorCode: "grey"
                        }

                        ListElement {
                            name: "Red"
                            colorCode: "red"
                        }

                        ListElement {
                            name: "Blue"
                            colorCode: "blue"
                        }

                        ListElement {
                            name: "Green"
                            colorCode: "green"
                        }
                    }
                    delegate: Item {
                        x: 5
                        width: 80
                        height: 40
                        Row {
                            id: row6
                            spacing: 10
                            Rectangle {
                                width: 40
                                height: 40
                                color: colorCode
                            }

                            Text {
                                text: name
                                font.bold: true
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }
                    }
                }

                Button {
                    id: stockCountsSaveButton
                    x: 396
                    y: 253
                    width: 102
                    height: 33
                    text: qsTr("Save")
                }

                Label {
                    id: stockCountLabel
                    x: 305
                    y: 217
                    text: qsTr("Count:")
                    font.pointSize: 20
                }

                TextField {
                    id: stockCountTextField
                    x: 396
                    y: 217
                    width: 102
                    height: 30
                    placeholderText: qsTr("Text Field")
                }
            }

            Rectangle {
                id: listProductsState
                color: "#ffffff"
                anchors.fill: parent

                TextArea {
                    id: listProductsOutput
                    x: 0
                    y: 0
                    width: 759
                    height: 500
                }
            }

            Rectangle {
                id: saveProductDatabaseState
                color: "#ffffff"
                anchors.fill: parent
                Label {
                    id: saveProductDatabaseLabel
                    x: 41
                    y: 0
                    text: qsTr("Save product database to adminProductDatabase.txt?")
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                    font.pointSize: 20
                }

                Button {
                    id: saveProductDatabaseButton
                    x: 344
                    y: 36
                    width: 80
                    height: 30
                    text: qsTr("Save")
                }
            }

            Rectangle {
                id: resetBillsState
                color: "#ffffff"
                z: 11
                anchors.fill: parent

                Text {
                    id: questionText
                    x: 258
                    y: 8
                    text: qsTr("Are you sure you would like to reset bills?")
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: Text.WordWrap
                    textFormat: Text.RichText
                    font.pixelSize: 12
                }

                Text {
                    id: assertionText
                    x: 313
                    y: 28
                    text: qsTr("This cannot be undone.")
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 12
                }

                Button {
                    id: resetBillsButton
                    x: 344
                    y: 48
                    width: 80
                    height: 32
                    text: qsTr("Reset Bills")
                }
            }
            
            Rectangle {
                id: changePasswordState
                color: "#ffffff"
                z: 18
                anchors.fill: parent
                
                Label {
                    id: origionalPasswordLabel
                    x: 309
                    y: 149
                    width: 69
                    height: 22
                    text: qsTr("New Password:")
                    font.pointSize: 13
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                }
                
                Label {
                    id: newPasswordLabel
                    x: 309
                    y: 121
                    width: 69
                    height: 22
                    text: qsTr("New Password:")
                    font.pointSize: 13
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                }
                
                Label {
                    id: repeatlabel
                    x: 309
                    y: 93
                    width: 69
                    height: 22
                    text: qsTr("Old Password:")
                    font.bold: false
                    font.pointSize: 13
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                }
                
                TextField {
                    id: originalPassword
                    x: 384
                    y: 93
                    placeholderText: qsTr("Text Field")
                }
                
                TextField {
                    id: newPassword
                    x: 384
                    y: 121
                    placeholderText: qsTr("Text Field")
                }
                
                TextField {
                    id: repeatPassword
                    x: 384
                    y: 149
                    placeholderText: qsTr("Text Field")
                }
                
                Button {
                    id: acceptPasswordButton
                    x: 384
                    y: 177
                    width: 102
                    height: 26
                    text: qsTr("Accept")
                }
            }

            Rectangle {
                id: saveDatabasesToUSBState
                color: "#ffffff"
                z: 12
                anchors.fill: parent

                Text {
                    id: unimplemented
                    x: 250
                    y: 8
                    text: qsTr("This Feature has not yet been implemented.")
                    font.pixelSize: 12
                }
            }

            Rectangle {
                id: closeTheProgramState
                color: "#ffffff"
                z: 13
                anchors.fill: parent

                Button {
                    id: closeProgramButton
                    x: 344
                    y: 8
                    width: 80
                    height: 36
                    text: qsTr("Quit")
                }
            }

    }


}
