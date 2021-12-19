#include "spreadsheet.h"
#include <QPixmap>
#include <QMenuBar>
#include <QToolBar>
#include <QApplication>
#include <QMessageBox>
#include"QTextStream"
#include <QLineEdit>
#include<QAction>
SpreadSheet::SpreadSheet(QWidget *parent)
    : QMainWindow(parent)
{
    A=new QStringList();
    //Seting the spreadsheet

    setupMainWidget();

    // Creaeting Actions
    createActions();

    // Creating Menus
    createMenus();


    //Creating the tool bar
    createToolBars();

    //making the connexions
    makeConnexions();


    //Creating the labels for the status bar (should be in its proper function)
    cellLocation = new QLabel("(1, 1)");
    cellFormula = new QLabel("");
    statusBar()->addPermanentWidget(cellLocation);
    statusBar()->addPermanentWidget(cellFormula);

    //initier le nom du fichier courant
    currentFile = nullptr;
    //mettre le nom de spreedsheet
    setWindowTitle("Buffer");
}

void SpreadSheet::setupMainWidget()
{
    spreadsheet = new QTableWidget;
    spreadsheet->setRowCount(100);
    spreadsheet->setColumnCount(10);
    setCentralWidget(spreadsheet);

}

SpreadSheet::~SpreadSheet()
{
    delete spreadsheet;

    // --------------- Actions       --------------//
    delete newFile;
    delete open;
    delete save;
    delete saveAs;
    delete exit;
    delete cut;
    delete copy;
    delete paste;
    delete deleteAction;
    delete find;
    delete row;
    delete Column;
    delete all;
    delete goCell;
    delete recalculate;
    delete sort;
    delete showGrid;
    delete auto_recalculate;
    delete about;
    delete aboutQt;
    delete recent;

    // ---------- Menus ----------
    delete FileMenu;
    delete editMenu;
    delete toolsMenu;
    delete optionsMenu;
    delete helpMenu;
}

void SpreadSheet::createActions()
{
    // --------- New File -------------------
   QPixmap newIcon(":/new_file.png");
   newFile = new QAction(newIcon, "&New", this);
   newFile->setShortcut(tr("Ctrl+N"));


    // --------- open file -------------------
   open = new QAction("&Open", this);
   open->setShortcut(tr("Ctrl+O"));

    // --------- open file -------------------
   save = new QAction("&Save", this);
   save->setShortcut(tr("Ctrl+S"));

    // --------- open file -------------------
   saveAs = new QAction("save &As", this);


    // --------- open file -------------------
   QPixmap cutIcon(":/cut_icon.png");
   cut = new QAction(newIcon, "Cu&t", this);
   cut->setShortcut(tr("Ctrl+X"));

   // --------- Cut menu -----------------
   copy = new QAction( "&Copy", this);
   copy->setShortcut(tr("Ctrl+C"));


   paste = new QAction( "&Paste", this);
   paste->setShortcut(tr("Ctrl+V"));


   deleteAction = new QAction( "&Delete", this);
   deleteAction->setShortcut(tr("Del"));


   row  = new QAction("&Row", this);
   Column = new QAction("&Column", this);
   all = new QAction("&All", this);
   all->setShortcut(tr("Ctrl+A"));



   QPixmap findIcon(":/search_icon.png"); find= new QAction(newIcon, "&Find", this);
   find->setShortcut(tr("Ctrl+F"));

   QPixmap goCellIcon(":/go_to_icon.png");
   goCell = new QAction( goCellIcon, "&Go to Cell", this);
   deleteAction->setShortcut(tr("f5"));


   recalculate = new QAction("&Recalculate",this);
   recalculate->setShortcut(tr("F9"));


   sort = new QAction("&Sort");



   showGrid = new QAction("&Show Grid");
   showGrid->setCheckable(true);
   showGrid->setChecked(spreadsheet->showGrid());

   auto_recalculate = new QAction("&Auto-recalculate");
   auto_recalculate->setCheckable(true);
   auto_recalculate->setChecked(true);



   about =  new QAction("&About");
   aboutQt = new QAction("About &Qt");

    // --------- exit -------------------
   QPixmap exitIcon(":/quit_icon.png");
   exit = new QAction(exitIcon,"E&xit", this);
   exit->setShortcut(tr("Ctrl+Q"));

   //-------recent-----
   recent= new QAction( "&Recent", this);
   recent->setShortcut(tr("Ctrl+M"));
}



void SpreadSheet::createMenus()
{
    // --------  File menu -------//
    FileMenu = menuBar()->addMenu("&File");
    FileMenu->addAction(newFile);
    FileMenu->addAction(open);
    FileMenu->addAction(save);
    FileMenu->addAction(saveAs);
    FileMenu->addSeparator();
    FileMenu->addAction(exit);


    //------------- Edit menu --------/
    editMenu = menuBar()->addMenu("&Edit");
    editMenu->addAction(cut);
    editMenu->addAction(copy);
    editMenu->addAction(paste);
    editMenu->addAction(deleteAction);
    editMenu->addSeparator();
    auto select = editMenu->addMenu("&Select");
    select->addAction(row);
    select->addAction(Column);
    select->addAction(all);

    editMenu->addAction(find);
    editMenu->addAction(goCell);
    editMenu->addAction(recent);


    //-------------- Toosl menu ------------
    toolsMenu = menuBar()->addMenu("&Tools");
    toolsMenu->addAction(recalculate);
    toolsMenu->addAction(sort);



    //Optins menus
    optionsMenu = menuBar()->addMenu("&Options");
    optionsMenu->addAction(showGrid);
    optionsMenu->addAction(auto_recalculate);


    //----------- Help menu ------------
    helpMenu = menuBar()->addMenu("&Help");
    helpMenu->addAction(about);
    helpMenu->addAction(aboutQt);
}

void SpreadSheet::createToolBars()
{

    //Creer une bare d'outils
    auto toolbar1 = addToolBar("File");


    //Ajouter des actions acette bar
    toolbar1->addAction(newFile);
    toolbar1->addAction(save);
    toolbar1->addSeparator();
    toolbar1->addAction(exit);


    //Creer une autre tool bar
    auto toolbar2  = addToolBar("ToolS");
    toolbar2->addAction(goCell);
    auto toolbar3  = addToolBar("ToolS");
    toolbar3->addAction(find);
}

void SpreadSheet::updateStatusBar(int row, int col)
{
    QString cell{"(%0, %1)"};
   cellLocation->setText(cell.arg(row+1).arg(col+1));

}

void SpreadSheet::makeConnexions()
{

   // --------- Connexion for the  select all action ----/
   connect(all, &QAction::triggered,
           spreadsheet, &QTableWidget::selectAll);

   // Connection for the  show grid
   connect(showGrid, &QAction::triggered,
           spreadsheet, &QTableWidget::setShowGrid);

   //Connection for the exit button
   connect(exit, &QAction::triggered, this, &SpreadSheet::close);


   //connectting the chane of any element in the spreadsheet with the update status bar
   connect(spreadsheet, &QTableWidget::cellClicked, this,  &SpreadSheet::updateStatusBar);

   connect(goCell, &QAction::triggered, this, &SpreadSheet::goCellSlot);

   connect(find, &QAction::triggered, this, &SpreadSheet::findSlot);

   connect (open,&QAction::triggered, this, &SpreadSheet::loadslot);
   //connection de save slot
   connect(save, &QAction::triggered,this,&SpreadSheet::saveSlot);
   //conncet del_slot
   connect(deleteAction, &QAction::triggered, this, &SpreadSheet::deleteslot);
  //connect select row
   connect(row,&QAction::triggered,this,&SpreadSheet::selectrow);
   //connect select col
   // connect(Column,&QAction::triggered,this,&SpreadSheet::selectcol);
   //connect for the recentfile
   connect(recent,&QAction::triggered,this,&SpreadSheet::recentfile);
   //connect for the newfile
   connect(newFile,&QAction::triggered,this,&SpreadSheet::newfile);
   //connect for the cut
  connect(cut,&QAction::triggered,this,&SpreadSheet::cutslot);
   //connect for the copy
  connect(copy,&QAction::triggered,this,&SpreadSheet::copyslot);
   //connect for the past
  connect(paste,&QAction::triggered,this,&SpreadSheet::pasteslot);
}

void SpreadSheet::goCellSlot()
{
    //Creating the dialog
    GoCell D;

    //Executing the dialog and storing the user response
    auto reply = D.exec();

    //Checking if the dialog is accepted
    if(reply == GoCell::Accepted)
    {

        //Getting the cell text
        auto cell = D.cell();

        //letter distance
        int row = cell[0].toLatin1() - 'A';
        cell.remove(0,1);

        //second coordinate
        int col =  cell.toInt();


        //changing the current cell
        spreadsheet->setCurrentCell(row, col-1);
    }
}
void SpreadSheet::findSlot()
{

    FindDialog f;
     auto reply = f.exec();
     if(reply == FindDialog::Accepted)
     {

         auto cellfield = f.textfield();

   for(int i=0;i<spreadsheet->rowCount();i++)
   {
       for(int j=0;j<spreadsheet->columnCount();j++)
       {
           if(spreadsheet->item(i,j))
           {
                if(spreadsheet->item(i,j)->text()==cellfield)
                      spreadsheet->setCurrentCell( i,  j);
           }
       }
   }
 }

}
void SpreadSheet::saveSlot(){
    //verifier si on a pas un nom de fichier
    if(!currentFile)//pointeur non nul
    {
    QFileDialog D;
    auto filename = D.getSaveFileName();

    //changer le nom du fichier
    currentFile = new QString(filename);
    i++;
    if(i<=5)
        A->append(*currentFile);

    setWindowTitle(filename);
    //fonction privee pour sauvegarder
    saveContent(filename);
 }
}
void SpreadSheet::saveContent(QString filename){
    //pointeur sur un fichier
    QFile file(filename);


    //ouvrir le fichier en mode lecture
    if(file.open(QIODevice::WriteOnly)){
        QTextStream out(&file);
        //Boucle sur les cellules pour sauvegarder leur contenu
        for(int i=0;i< spreadsheet->rowCount();i++)
            for(int j=0;j<spreadsheet->columnCount();j++){
                auto cell = spreadsheet->item(i,j);
                if (cell){
                    out << i << "," <<  j << "," << cell->text() << endl;

                }
            }
    }
    //Fermer la connexion avec le fichier
    file.close();

}
void SpreadSheet::loadContent(QString filename)
{
    //ouvrir le pointeur sur le fichier
    QFile file (filename);

    if(file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);

        //parcourir tout le fichier
         while(!in.atEnd()){
        QString line;
        line = in.readLine();

        //separer la ligne par,
        auto tokens = line.split(QChar(','));

        //Row
        int row = tokens[0].toInt();
        int col = tokens[1].toInt();
        auto cell = new QTableWidgetItem(tokens[2]);
        spreadsheet->setItem(row,col,cell);
       }
    }
}
void SpreadSheet::loadslot(){
    QFileDialog D;
    filename= D.getOpenFileName();
//    //changer le nom de dichier
//    currentFile= new QString(filename);
  setWindowTitle(filename);
//     //Fonction pour charger le contenu
//    loadContent(filename);
         setWindowTitle(filename);
          if (currentFile->endsWith(".csv"))
          loadcsv(filename);
          else loadContent(filename);
          if(i<5){
                  recentlist.append(new QAction(*currentFile,this));
                 //recent->addAction(recentlist[i]);
                  connect(recentlist[i], &QAction::triggered, this, &SpreadSheet::recentfile);
                  i++;
          }
          else{
               for (int j=0;j<4 ;j++ ) {
                recentlist[4-j]->setText(recentlist[3-j]->text());
                      }
                      recentlist[0]->setText(*currentFile);
                  }
}

void SpreadSheet::deleteslot(){
    int row = spreadsheet->currentRow();
    int col = spreadsheet->currentColumn();
    spreadsheet->setItem(row, col,new QTableWidgetItem(""));
}
void SpreadSheet::selectrow(){

    int A;
    A=spreadsheet->currentRow();
    spreadsheet->selectRow(A);

}

void SpreadSheet::newfile(){

spreadsheet->clear();
 currentFile=nullptr;
setWindowTitle("buffer");
}
void SpreadSheet::cutslot()
{
    // get the last child widget which has focus and
    // try to cast it as line edit
    QLineEdit* lineEdit = dynamic_cast<QLineEdit*>(focusWidget());
    if (lineEdit)
    {
        // it was a line edit, perform copy
        lineEdit->cut();
    }
}
void SpreadSheet::copyslot()
{
    // get the last child widget which has focus and
    // try to cast it as line edit
    QLineEdit* lineEdit = dynamic_cast<QLineEdit*>(focusWidget());
    if (lineEdit)
    {
        // it was a line edit, perform copy
        lineEdit->copy();
    }
}
void SpreadSheet::pasteslot()
{
    // get the last child widget which has focus and
    // try to cast it as line edit
    QLineEdit* lineEdit = dynamic_cast<QLineEdit*>(focusWidget());
    if (lineEdit)
    {
        // it was a line edit, perform copy
        lineEdit->paste();
    }
}
void SpreadSheet::close()
{

    auto reply = QMessageBox::question(this, "Exit",
                                       "Do you really want to quit?");
    if(reply == QMessageBox::Yes)
        qApp->exit();
}
void SpreadSheet::recentfile() {
    // obtenir le fichier
auto    A = dynamic_cast<QAction*>(sender());
    QFile file(A->text());
    QString line;
     if(file.open(QIODevice::ReadOnly))
     {
     QTextStream in(&file);
     while( !in.atEnd())
         {
             line = in.readLine();
             auto tokens = line.split(QChar(',') );
             int row = tokens[0].toInt();
             int col = tokens[1].toInt();
             spreadsheet->setItem(row, col , new QTableWidgetItem(tokens[2]));
         }
     }
     filename= (A->text());
     // update the title
     setWindowTitle(*currentFile);
     file.close();
}
void SpreadSheet::loadcsv(QString filename){
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly )) {
        QTextStream in(&file);

 int i=0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        auto list = line.split(QChar(';'));
        for(int j=0;j<list.length();j++){
        auto contenu=new  QTableWidgetItem (list[j]);
        spreadsheet->setItem(i,j,contenu);
        }
        i++;
    }
  }
}
