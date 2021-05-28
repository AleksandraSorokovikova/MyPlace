#ifndef SEARCHACCOUNTS_H
#define SEARCHACCOUNTS_H

#include <QDialog>
#include <QString>

namespace Ui {
class SearchAccounts;
}

class SearchAccounts : public QDialog {
  Q_OBJECT

public:
  explicit SearchAccounts(QWidget *parent = nullptr, QString nickname = "",
                          QString subscribe_ = "", bool is_search_ = true);
  ~SearchAccounts();

private slots:
  void on_subscribe_clicked();

  void on_cancel_clicked();

private:
  Ui::SearchAccounts *ui;
  QString user_id;
  QString subscribe_name;
  bool is_search;
};

#endif // SEARCHACCOUNTS_H
