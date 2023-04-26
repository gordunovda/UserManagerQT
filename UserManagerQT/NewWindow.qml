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
        Row {
            spacing: 10
            anchors.fill: parent
            Text {
                id: text1
                text: "Текст  1"
                visible: userController.IsAllow("level1")
            }

            Text {
                id: text2
                text: "Текст  2"
                visible: userController.IsAllow("level2")
            }

            Text {
                id: text3
                text: "Текст  3"
                visible: userController.IsAllow("level3")
            }

            Text {
                id: text4
                text: "Текст  4"
                visible: userController.IsAllow("level4")
            }

            Text {
                id: text5
                text: "Текст  5"
                visible: userController.IsAllow("level5")
            }

            Text {
                id: text6
                text: "Текст  6"
                visible: userController.IsAllow("level6")
            }

        }
    }
    Connections {
        target: userController
        onUserChanged: {
            text6.visible = userController.IsAllow("level6")
            text5.visible = userController.IsAllow("level5")
            text4.visible = userController.IsAllow("level4")
            text3.visible = userController.IsAllow("level3")
            text2.visible = userController.IsAllow("level2")
            text1.visible = userController.IsAllow("level1")
        }
    }
}
