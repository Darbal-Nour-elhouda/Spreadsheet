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

# Introduction:

<p align="center">
     <img src="images/Network-arch.png">
   </p>

# Functionality

>

# SpreedSheet Header
     (#spreedsheet-header)
   - ### [Protected Functions](#protected-functions)
   - ### [Private Slots](#private-slots)
   - ### [Pointers](#pointers)
# SpreedSheet CPP(#spreedsheet-cpp)


## SpreedSheet Header

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

