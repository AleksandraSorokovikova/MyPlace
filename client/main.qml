import QtQuick 2.0
import QtQuick.Window 2.14
import QtLocation 5.15
import QtPositioning 5.6
import QtQuick.Controls 2.2


Rectangle {
    width: 960
    height: 730
    visible: true
    objectName: "rectangle"

        Plugin {
            id: mapPlugin
            name:  "osm" // mapboxgl", "esri", ...
        }

        Map {
            id: map
            anchors.fill: parent
            plugin: mapPlugin
            center: QtPositioning.coordinate(59.92, 30.22) // Saint-Peterburg
            zoomLevel: 10
                    MapItemView{
                               model: markerModel
                               delegate: mapcomponent

                           }

                    MouseArea {
                            anchors.fill: parent
                            onDoubleClicked:  {
                                var coordinate = map.toCoordinate(Qt.point(mouse.x,mouse.y))
                                geocodeModel.query = coordinate;
                                geocodeModel.update();
                                if (geocodeModel.count > 0) {
                                   markerModel.set_address(geocodeModel.get(0).address.street + ", " +
                                                            geocodeModel.get(0).address.city + ", " + geocodeModel.get(0).address.country);
                                    markerModel.addMarker();
                                }
                            }
                        }
            }

                Component {
                        id: mapcomponent
                        MapQuickItem {
                            id: marker
                            anchorPoint.x: image.width/4
                            anchorPoint.y: image.height
                            coordinate: position

                            sourceItem: Image {
                                id: image
                                source: "qrc:/img/img/flags.png"
                                width: 20; height: 20
                            }
                            zoomLevel: map.zoomLevel


                        }
                    }

                GeocodeModel {
                    id: geocodeModel
                    objectName: "geocode"
                    plugin: mapPlugin
                    autoUpdate: false
                }
}



