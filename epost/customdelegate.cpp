#include "customdelegate.h"

CustomDelegate::CustomDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

QWidget *CustomDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    Q_UNUSED(option);
    Editor *editor = new Editor(parent);
    connect(editor, SIGNAL(accepted()), this, SLOT(commitAndCloseEditor()));
    connect(editor, SIGNAL(rejected()), this, SLOT(cancelEditor()));
    return editor;
}

void CustomDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    const QAbstractItemModel *model = index.model();
    int row = index.row();
    QString str = model->index(row,0).data(Qt::EditRole).toString();
    int i = model->index(row, 1).data(Qt::EditRole).toInt();
    Editor *customEditor = qobject_cast<Editor*>(editor);
    if(customEditor){
        customEditor->setString(str);
        customEditor->setInt(i);
    }
}

void CustomDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    int row = index.row();
    Editor *customEditor = qobject_cast<Editor*>(editor);
    if(customEditor){
        // Get values before calling setData, otherwise values will be reset
        QString s = customEditor->getString();
        int i = customEditor->getInt();
        model->setData(model->index(row,0), s, Qt::EditRole);
        model->setData(model->index(row,1), i, Qt::EditRole);
    }
}

void CustomDelegate::commitAndCloseEditor()
 {
     Editor *editor = qobject_cast<Editor *>(sender());
     emit commitData(editor);
     emit closeEditor(editor);
 }

void CustomDelegate::cancelEditor()
{
    Editor *editor = qobject_cast<Editor *>(sender());
    emit closeEditor(editor);
}
