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
        <li><a href="#Introduction">introduction</a></li>
        <li><a href="#Functionality">Functionality</a></li>
        <li><a href="#SpreedSheet Header">SpreedSheet Header</a></li>
        <li><a href="#SpreedSheet cpp">SpreedSheet cpp</a></li>
  </ol>
</details>

- # [Introduction]
Spreadsheets are computer applications used to store, analyze, organize and manipulate data in the rows and columns of a grid. The program operates by taking in data, which can be numbers or text, into the cells of tables.
<p align="center">
     <img src="images/example1.gif">
   </p>

- # [Functionality]


- ## [SpreedSheet Header](#spreedsheet-header)
   - ### [Protected Functions](#protected-functions)
   - ### [Private Slots](#private-slots)
   - ### [Pointers](#pointers)
- ## [SpreedSheet CPP](#spreedsheet-cpp)


## SpreedSheet Header:

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
## Protected Functions:
```c++
protected:
    void setupMainWidget();
    void createActions();
    void createMenus();
    void createToolBars();
    void makeConnexions();
```
## Private Slots:
```c++
private slots:
    void close();
    void updateStatusBar(int, int); //Respond for the call changed
    void goCellSlot();
    void findSlot();
    void deleteslot();
    void saveSlot();//slot pour repondre a l appel save
    void loadslot();//slot pour repondre a l appel load
```
## Pointers:
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
