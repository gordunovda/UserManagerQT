import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

ApplicationWindow  {
    id: mainwindow
    visible: true
    width: 400
    height: 100
    title: qsTr("QML Test")

    Connections {
        target: userController
        onUserChanged: {
            button6.visible = userController.IsAllow("button6")
            button5.visible = userController.IsAllow("button5")
            button4.visible = userController.IsAllow("button4")
            button3.visible = userController.IsAllow("button3")
            button2.visible = userController.IsAllow("button2")
            button1.visible = userController.IsAllow("button1")
            newWindowButton.visible = userController.IsAllow("newwindow")

        }
    }
    
    NewWindow {
        id:popupWindow
    }

    Column {
        width: parent.width
        height: parent.height
        Row {
            width: parent.width
            spacing: 5

            TextField {
                id: passwordField
                width: parent.width - button.width - 15
                placeholderText: "Введите пароль"
            }

            Button {
                id: button
                text: "Enter"
                onClicked: {
                    userController.ChangePassword(passwordField.text)
                }
            }
        }

        Row {
            id: buttonRow
            width: parent.width
            spacing: 5

            Button {
                id: button1
                text: "Кнопка 1"
                visible: false
            }

            Button {
                id: button2
                text: "Кнопка 2"
                visible: false
            }

            Button {
                id: button3
                text: "Кнопка 3"
                visible: false
            }

            Button {
                id: button4
                text: "Кнопка 4"
                visible: false
            }

            Button {
                id: button5
                text: "Кнопка 5"
                visible: false
            }

            Button {
                id: button6
                text: "Кнопка 6"
                visible: false
            }
        }
        Row {
            Button {
                id: newWindowButton
                text: "Новое окно"
                visible: false
                onClicked: {
                   popupWindow.visible = true;
                }
            }
        }
    }
}


