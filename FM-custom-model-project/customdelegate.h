#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H

#include <QStyledItemDelegate>

class CustomDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CustomDelegate(QObject *parent = 0);
    QWidget* createEditor ( QWidget* parent, const QStyleOptionViewItem &option, const QModelIndex & index ) const;
    void setEditorData ( QWidget * editor, const QModelIndex & index ) const;
    void setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const;
    
public slots:
    void commitAndCloseEditor();
    void cancelEditor();
};

#endif // CUSTOMDELEGATE_H
