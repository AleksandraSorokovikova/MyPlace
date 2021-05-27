import QtQuick 2.0
import QtQuick.Window 2.14
import QtLocation 5.6
import QtPositioning 5.6
import QtQuick.Controls 2.2


Rectangle {
    width: 960
    height: 730
    visible: true

        Plugin {
            id: mapPlugin
            name: "osm" // "mapboxgl", "esri", ...
            // specify plugin parameters if necessary
            // PluginParameter {
            //     name:
            //     value:
            // }
        }

        Map {
            id: map
            anchors.fill: parent
            plugin: mapPlugin
            center: QtPositioning.coordinate(59.92, 30.22) // Saint-Peterburg
            zoomLevel: 10

            MapQuickItem {
                    id:marker
                    sourceItem: Image{
                        id: image
                        source: "flags.png"

                    }
                    coordinate: map.center
                    anchorPoint.x: image.width / 2
                    anchorPoint.y: image.height / 2
                }

                MouseArea {
                    anchors.fill: parent
                    onPressed: {
                        marker.coordinate = map.toCoordinate(Qt.point(mouse.x,mouse.y))
                    }
                }
        }


}
