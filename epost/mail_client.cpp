#include "mail_client.h"

mail_client::mail_client(QWidget *parent): QWidget(parent){
    check_button = new QPushButton("Check");
    del_button = new QPushButton("Delete");
    new_button = new QPushButton("New");
    list_view = new QListView();
    model = new list_model(this);

    list_view->setModel(model);
    list_view->setSelectionMode(QAbstractItemView::ExtendedSelection);
    right_layout = new QVBoxLayout();
    main_layout = new QHBoxLayout(this);


    right_layout->addWidget(check_button);
    right_layout->addWidget(del_button);
    right_layout->addWidget(new_button);
    right_layout->addStretch();

    main_layout->addWidget(list_view);
    main_layout->addLayout(right_layout);

    connect(check_button,SIGNAL(clicked(bool)),this,SLOT(check()));
    connect(del_button,SIGNAL(clicked(bool)),this,SLOT(del()));
    connect(new_button,SIGNAL(clicked(bool)),this,SLOT(ny()));


}
void mail_client::check(){
    qDebug() << "check";
}
void mail_client::del(){
    qDebug() << "delete";

    QList<QPersistentModelIndex> indexes;
    foreach(QModelIndex i, list_view->selectionModel()->selectedIndexes()) {
        indexes.append(i);
    }

    foreach(QModelIndex index, indexes) {
        model->removeValue(index);
    }


}
void mail_client::ny(){
    qDebug() << "new";
    compose_mail *cm = new compose_mail();
    connect(cm, SIGNAL(send_til_model(QString,QString,QString)), model,SLOT(addValue(QString,QString,QString)) );
    cm->setAttribute( Qt::WA_DeleteOnClose );  //OBS compose_mail må slettes siden den ikke har en "parent",og den ligger på heap
    cm->show();
}
mail_client::~mail_client(){

}
