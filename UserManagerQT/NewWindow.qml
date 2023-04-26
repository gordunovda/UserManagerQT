import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    width: 400
    height: 100
    title: qsTr("Non modal window")
    visible: false
    modality: Qt.NonModal
    Rectangle {
        color: "lightgray"
        anchors.fill: parent
        Row{
        anchors.fill: parent
               Button {
                    id: button1
                    text: "Кнопка 1"
                    visible: userController.IsAllow("button1")
                }

                Button {
                    id: button2
                    text: "Кнопка 2"
                    visible: userController.IsAllow("button2")
                }

                Button {
                    id: button3
                    text: "Кнопка 3"
                    visible: userController.IsAllow("button3")
                }

                Button {
                    id: button4
                    text: "Кнопка 4"
                    visible: userController.IsAllow("button4")
                }

                Button {
                    id: button5
                    text: "Кнопка 5"
                    visible: userController.IsAllow("button5")
                }

                Button {
                    id: button6
                    text: "Кнопка 6"
                    visible: userController.IsAllow("button6")
                }
 
    }
    }
    Connections {
        target: userController
        onUserChanged: {
            button6.visible = userController.IsAllow("button6")
            button5.visible = userController.IsAllow("button5")
            button4.visible = userController.IsAllow("button4")
            button3.visible = userController.IsAllow("button3")
            button2.visible = userController.IsAllow("button2")
            button1.visible = userController.IsAllow("button1")
        }
    }
}
