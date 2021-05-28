#ifndef MARKERMODEL_H
#define MARKERMODEL_H

#include "client.h"
#include "createrlabel.h"
#include "label.h"
#include "openlabel.h"
#include <QAbstractListModel>
#include <QGeoCoordinate>
#include <QMessageBox>
#include <QTextStream>
#include <map>

class MarkerModel : public QAbstractListModel {
  Q_OBJECT

public:
  using QAbstractListModel::QAbstractListModel;
  enum MarkerRoles { positionRole = Qt::UserRole + 1 };

  void set_user(const QString &user) { user_id = user; }

  Q_INVOKABLE void set_address(const QString &address_) { address = address_; }

  Q_INVOKABLE void set_coordinate(const QGeoCoordinate &coordinate_) {
    coordinate = coordinate_;
  }

  Q_INVOKABLE QString get_address() { return address; }

  Q_INVOKABLE void
  addMarker(const QGeoCoordinate &coordinate = QGeoCoordinate(0, 0)) {
    CreaterLabel creater(user_id, coordinate, address);
    creater.setModal(true);
    creater.exec();
    address = "default";
  }

  Q_INVOKABLE void showMarker(double longitude, double latitude) {
    auto label = labels_on_coordinate1[std::make_pair(longitude, latitude)];
    OpenLabel open(label);
    open.setModal(true);
    open.exec();
  }

  Q_INVOKABLE void insertMarker(const QGeoCoordinate &coordinate) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_coordinates.append(coordinate);
    endInsertRows();
    address = "default";
  }

  int rowCount(const QModelIndex &parent = QModelIndex()) const override {
    Q_UNUSED(parent)
    return m_coordinates.count();
  }

  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override {
    if (index.row() < 0 || index.row() >= m_coordinates.count())
      return QVariant();
    if (role == MarkerModel::positionRole)
      return QVariant::fromValue(m_coordinates[index.row()]);
    return QVariant();
  }

  QHash<int, QByteArray> roleNames() const override {
    QHash<int, QByteArray> roles;
    roles[positionRole] = "position";
    return roles;
  }

  QList<QGeoCoordinate> m_coordinates;
  QString address = "default";
  QGeoCoordinate coordinate;
  std::map<std::pair<double, double>, Label> labels_on_coordinate1;

signals:
  void propertyChanged(const QString &address_);

public slots:
  void changeGeocode() { emit propertyChanged(address); }

private:
  QString user_id = "default";
};

#endif // MARKERMODEL_H
