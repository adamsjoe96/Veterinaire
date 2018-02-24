import QtQuick 2.0

Item {

    Rectangle{
        width : 20
        height: 30
        border.color: 'yellow'
        Text {
            id: texto
            text: qsTr("je suis un maitre")
            anchors.centerIn: parent
        }
    }
}
