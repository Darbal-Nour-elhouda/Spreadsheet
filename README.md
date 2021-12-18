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
        <li><a href="#Features & Functionality">Features & Functionality</a></li>
        <li><a href="#SpreedSheet Header">SpreedSheet Header</a></li>
        <li><a href="#SpreedSheet cpp">SpreedSheet cpp</a></li>
  </ol>
</details>

- # [Introduction](#introduction)
Spreadsheets are computer applications used to store, analyze, organize, and manipulate data in the rows and columns of a grid. The program works by inserting data, which can be numbers or text, into the cells of tables. most people think of spreadsheets, they think of data entry and simple calculations. But a modern spreadsheet is more than a financial tool. These apps are a robust way to help collect, organize and analyze important data across different areas of life ,& people use it because they are easy-to-read space.
<p align="center">
     <img src="images/example1.gif">
   </p>

- # [Features & Functionality](#features-and-functionality)
## **In our SpreadSheet we obtain an application with:**
 -Menu Bar
 -Two tools bars
 -Status bar to print the informations
 
the application looks like that :
<p align="center">
     <img src="images/logo.png">
   </p>

- # [SpreedSheet Header](#spreedsheet-header)
   - ### [Protected Functions](#protected-functions)
   - ### [Private Slots](#private-slots)
   - ### [Pointers](#pointers)



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
- # [SpreedSheet CPP](#spreedsheet-cpp)
