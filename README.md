<div id="top"></div>


<!-- PROJECT LOGO -->
<br />
<div align="center">
    <img src="images/spreedsheet icon.jpg" alt="Logo" width="500" height="400">
  
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
        <li><a href="#introduction">Introduction</a></li>
        <li><a href="#features">Features</a></li>
        <li><a href="#Spread-Sheet-Header">Spread Sheet tHeader</a></li>
        <li><a href="#Spread-Sheet-cpp">Spread Sheet Cpp</a></li>
  </ol>
</details>

- # [Introduction](#Introduction)
Spreadsheets are computer applications used to store, analyze, organize, and manipulate data in the rows and columns of a grid. The program works by inserting data, which can be numbers or text, into the cells of tables. most people think of spreadsheets, they think of data entry and simple calculations. But a modern spreadsheet is more than a financial tool. These apps are a robust way to help collect, organize and analyze important data across different areas of life ,& people use it because they are easy-to-read space.
<p align="center">
     <img src="images/example1.gif">
   </p>

- # [Features](#Features)
Common characteristics of spreadsheet software include built-in support for complex mathematical calculations and formulas, the ability to generate graphs and summary "pivot tables" from data and the ability to customize what types of data are stored in which rows and columns.
##  **In our SpreadSheet we obtain an application with:**

 -Menu Bar.
 
 -Two tools bars.
 
 -Status bar to print the informations.
 
 
## **the application looks like that :**
<p align="center">
     <img src="images/logo.png">
   </p>

  - ## [Spread Sheet Header](#Spread-Sheet-Header)
    - ### [The header](#The-header)
    - ### [Protected Functions](#protected-functions)
    - ### [Private Slots](#private-slots)
    - ### [Pointers](#Pointers)



# SpreedSheet Header
## The header
```c++
#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QMainWindow>
#include <QTableWidget>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QLabel>
#include <QStatusBar>
#include "gocell.h"
#include "finddialog.h"
#include<QFileDialog>
#include<QTextStream>

class SpreadSheet : public QMainWindow
{
    Q_OBJECT

public:
    SpreadSheet(QWidget *parent = nullptr);
    ~SpreadSheet();
```
## Protected Functions
```c++
protected:
    void setupMainWidget();
    void createActions();
    void createMenus();
    void createToolBars();
    void makeConnexions();
```
## Private Slots
```c++
private slots:
    void close();
    void updateStatusBar(int, int); //Respond for the call changed
    void goCellSlot();
    void findSlot();
    void deleteslot();
    void saveSlot();//slot pour repondre a l appel save
    void loadslot();//slot pour repondre a l appel load
    void recentfile();
    void selectrow();
    void copyslot();
    void cutslot();
    void pasteslot();
```
##  Pointers
```c++
//Pointers
    void saveContent(QString filename);//methode pour sauvegarder le contenu
    void loadContent(QString filename);

private:

    // --------------- Central Widget -------------//
    QTableWidget *spreadsheet;
    // --------------- Actions       --------------//
    QAction * newFile;
    QAction * open;
    QAction * save;
    QAction * saveAs;
    QAction * exit;
    QAction *cut;
    QAction *copy;
    QAction *paste;
    QAction *deleteAction;
    QAction *find;
    QAction *row;
    QAction *Column;
    QAction *all;
    QAction *goCell;
    QAction*findDialog;
    QAction *recalculate;
    QAction *sort;
    QAction *showGrid;
    QAction *auto_recalculate;
    QAction *about;
    QAction *aboutQt;
    QAction *recent;

    // ---------- Menus ----------
    QMenu *FileMenu;
    QMenu *editMenu;
    QMenu *toolsMenu;
    QMenu *optionsMenu;
    QMenu *helpMenu;


    //  ----- - Widget pouyr la bare d'etat
    QLabel *cellLocation;  //position de la cellule active
    QLabel *cellFormula;   // Formuel de la cellue active
    //-------- Nom de fichier courant
    QString * currentFile;

};

#endif // SPREADSHEET_H
```
  - ## [Spread Sheet Cpp](#Spread-Sheet-Cpp)
    - ### [The code](#The-code)
    - ### [ Functions](#functions)
        - ### [setupMainWidget](#setupMainWidget)
        - ### [createActions](#createActions)
        - ### [createMenus](#createMenus)
        - ### [createToolBars](#createToolBars)
        - ### [updateStatusBar](#updateStatusBar)
        - ### [makeConnexions](#makeConnexions)
    - ### [Slots](#slots)
        - ### [goCellSlot](#goCellSlot)
        - ### [findSlot](#findSlot)
        - ### [saveSlot](#saveSlot)
        - ### [saveContent](#saveContent)
        - ### [loadContent](#loadContent)
        - ### [loadslot](#loadslot)
        - ### [deleteslot](#deleteslot)
        - ### [selectrow](#selectrow)
        - ### [newfile](#newfile)
        - ### [cutslot](#cutslot)
        - ### [copyslot](#copyslot)
        - ### [pasteslots](#pasteslot)
        - ### [close](#close)
        - ### [recentfile](#recentfile)
# SpreedSheet Cpp
 ## The code
we start by declaring the seting spreadsheat "setupMainWidget()", also we create Actions  by  "createActions()", after we create the tool bar by "createToolBars()" and we make connexions by  "makeConnexions()" , we create the labels for the status bar , besides , we initiate the name of the current file  , in the end we should give the name of the spreadsheet by "setWindowTitle".
 
  ```c++ 
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

```
 ## Functions
Now, it's necessary to implement the functions mentioned before:

   #### setupMainWidget
```c++
void SpreadSheet::setupMainWidget()
{
    spreadsheet = new QTableWidget;
    spreadsheet->setRowCount(100);
    spreadsheet->setColumnCount(10);
    setCentralWidget(spreadsheet);

}
```
   #### createActions
   where we create the action for each one using 
   `nameAction = new QAction(ActionIcone, "&Action", this)` , if we want add icons for our actions we use
`QPixmap ActionIcone(":/new_file.png")` , also we can add shortCut by
`ActionIcone->setShortcut(tr("Ctrl+alphabet"))`:
   
```c++
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
```
  #### createMenus
here we add Menus ,we have 5 Name menus "File", "Edit" ,"Toosl", "Optins", "Help"  by 
`NameMenu = menuBar()->addMenu("&Name")`
and we add actions by using 
`NameMenu->addAction(action)`:

<p align="center">
     <img src="images/toolsbar.png">
   </p>

```c++
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



    //--------------Optins menus-------------
    optionsMenu = menuBar()->addMenu("&Options");
    optionsMenu->addAction(showGrid);
    optionsMenu->addAction(auto_recalculate);


    //----------- Help menu ------------
    helpMenu = menuBar()->addMenu("&Help");
    helpMenu->addAction(about);
    helpMenu->addAction(aboutQt);
}
```

  #### createToolBars
where we create the toolbars by 
`auto toolbarName = addToolBar("Name");` and we add for each one the actions by using
`toolbarName->addAction(action);`

```c++
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
```
   ##### updateStatusBars
This function is done just if a new cell has been selected in the toolbar.
```c++
void SpreadSheet::updateStatusBar(int row, int col)
{
    QString cell{"(%0, %1)"};
   cellLocation->setText(cell.arg(row+1).arg(col+1));

}
```
The result:
<p align="center">
     <img src="images/updateStatusBar1.png">
   </p>


In the end off the functions mentionned before we find the important one the :
  ####  makeConnexions
 here we make connexion of the chane of any element in the spreadsheet with the update status barby using
 `connect(action,&QAction::triggered,name,&QTableWidger::actionSlot)`
 
 ```c++
 void SpreadSheet::makeConnexions()
{

   // --------- Connexion for the  select all action ----/
   connect(all, &QAction::triggered,spreadsheet, &QTableWidget::selectAll);

   // ----------Connection for the  show grid---------
   connect(showGrid, &QAction::triggered,spreadsheet, &QTableWidget::setShowGrid);

   //--------Connection for the exit button----------
   connect(exit, &QAction::triggered, this, &SpreadSheet::close);


   //connectting the chane of any element in the spreadsheet with the update status bar
   connect(spreadsheet, &QTableWidget::cellClicked, this,  &SpreadSheet::updateStatusBar);

   connect(goCell, &QAction::triggered, this, &SpreadSheet::goCellSlot);

   connect(find, &QAction::triggered, this, &SpreadSheet::findSlot);

   connect (open,&QAction::triggered, this, &SpreadSheet::loadslot);
   
   //connection de save slot
   connect(save, &QAction::triggered,this,&SpreadSheet::saveSlot);
   
   //conncet delete_slot
   connect(deleteAction, &QAction::triggered, this, &SpreadSheet::deleteslot);
   
   //conncet cut_slot
   connect(cut, &QAction ::triggered, this, &SpreadSheet::cutslot);
   
   //conncet copy_slot
   connect(copy, &QAction ::triggered, this, &SpreadSheet::copyslot);
   
   //conncet past_slot
   connect(paste, &QAction ::triggered, this, &SpreadSheet::pastslot);
   
   //connect select row
   connect(row,&QAction::triggered,this,&SpreadSheet::selectrow);
   
   //connect select Column
   connect(Column,&QAction::triggered,this,&SpreadSheet::selectcol);
  
  //connect for the recentfile
   connect(recent,&QAction::triggered,this,&SpreadSheet::recentfile);

   
}
 ```
## The slots 
 ####  goCellSlot
 ```c++
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
```

<p align="center">
     <img src="images/gocell.png">
   </p>

#### findSlot
 ```c++
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
```
<p align="center">
     <img src="images/find.png">
   </p>
   

#### saveSlot
 ```c++
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
```

   

####  saveContent
 ```c++
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
```
<p align="center">
     <img src="images/save.png">
   </p>
   

####  loadContent
 ```c++
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
```

####  loadslot
 ```c++
void SpreadSheet::loadslot(){
    QFileDialog D;
    auto filename = D.getOpenFileName();
    //changer le nom de dichier
    currentFile= new QString(filename);
    setWindowTitle(*currentFile);
     //Fonction pour charger le contenu
    loadContent(filename);
}
```

####  deleteslot
 ```c++

void SpreadSheet::deleteslot(){
    int row = spreadsheet->currentRow();
    int col = spreadsheet->currentColumn();
    spreadsheet->setItem(row, col,new QTableWidgetItem(""));
}
```
<p align="center">
     <img src="images/delete.png">
   </p>

####  selectrow
 ```c++
void SpreadSheet::selectrow(){

    int A;
    A=spreadsheet->currentRow();
    spreadsheet->selectRow(A);

}
```
<p align="center">
     <img src="images/row.png">
   </p>


####  newfile
 ```c++
void SpreadSheet::newfile(){

spreadsheet->clear();
 currentFile=nullptr;
setWindowTitle("buffer");
}
```
|     example image              |       new file                 |
| -------------------------------| ------------------------------ |
|  <p >                          |   <p>                          |
| <img src="images/example.png"> |  <img src="images/newfile.png">|
|   </p>                         | </p>                           |



#### cutslot
```c++
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
```
<p align="center">
     <img src="images/cut.png">
   </p>

####  copyslot
 ```c++
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
```
<p align="center">
     <img src="images/copy.png">
   </p>

#### pasteslot
 ```c++
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
```
<p align="center">
     <img src="images/paste.png">
   </p>
   

####  close
 ```c++
void SpreadSheet::close()
{

    auto reply = QMessageBox::question(this, "Exit",
                                       "Do you really want to quit?");
    if(reply == QMessageBox::Yes)
        qApp->exit();
}
```
<p align="center">
     <img src="images/close.png">
   </p>
   
####  recentfile
 ```c++
void SpreadSheet::recentfile() {
    // obtenir le fichier
auto b = dynamic_cast<QAction*>(sender());
    QFile file(b->text());
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
     // update the title
     setWindowTitle(*currentFile);
     file.close();
}

 ```
















Our Team -[DARBAL nour-elhouda](https://github.com/teamkhaoulanour) -[MZOUDI Khaoula](https://github.com/KhaoulaMzoudi)

Project Link: [SpreadSheet](https://github.com/Darbal-Nour-elhouda/Spreadsheet)

Encadré par : [Mr.Belcaid Anass](https://)


<p align="right">(<a href="#top">back to top</a>)</p>
