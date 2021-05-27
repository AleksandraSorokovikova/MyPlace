#ifndef MARKERMODEL_H
#define MARKERMODEL_H

#include <QAbstractListModel>
#include <QGeoCoordinate>
#include "createrlabel.h"

class MarkerModel : public QAbstractListModel
{
    Q_OBJECT

public:
    using QAbstractListModel::QAbstractListModel;
    enum MarkerRoles{positionRole = Qt::UserRole + 1};

    void set_user(const QString& user) {
        user_id = user;
    }

     Q_INVOKABLE void set_address(const QString& address_) {
        address = address_;
    }

    Q_INVOKABLE void addMarker(const QGeoCoordinate &coordinate = QGeoCoordinate(0, 0)){
        CreaterLabel creater(user_id, coordinate, address);
        creater.setModal(true);
        creater.exec();
        address = "default";
    }

    Q_INVOKABLE void insertMarker(const QGeoCoordinate &coordinate) {
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        m_coordinates.append(coordinate);
        endInsertRows();
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent)
        return m_coordinates.count();
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (index.row() < 0 || index.row() >= m_coordinates.count())
            return QVariant();
        if(role== MarkerModel::positionRole)
            return QVariant::fromValue(m_coordinates[index.row()]);
        return QVariant();
    }

    QHash<int, QByteArray> roleNames() const override {
        QHash<int, QByteArray> roles;
        roles[positionRole] = "position";
        return roles;
    }

    QList<QGeoCoordinate> m_coordinates;

private:
    QString user_id = "default";
    QString address = "default";
};

#endif // MARKERMODEL_H
