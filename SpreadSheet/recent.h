#ifndef RECENT_H
#define RECENT_H

#include <QWidget>

namespace Ui {
class recent;
}

class recent : public QWidget
{
    Q_OBJECT

public:
    explicit recent(QWidget *parent = nullptr);
    QString recenttext() const;
    ~recent();

private:
    Ui::recent *ui;
};

#endif // RECENT_H
