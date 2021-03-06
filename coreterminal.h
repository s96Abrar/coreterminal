/*
CoreTerminal is a terminal emulator.

CoreBox is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see {http://www.gnu.org/licenses/}. */

#ifndef CORETERMWIDGET_H
#define CORETERMWIDGET_H

#pragma once

#include <qtermwidget5/qtermwidget.h>

#include <iostream>
#include <fstream>
#include <QFileSystemWatcher>
#include <QFileInfo>
#include <QProcessEnvironment>
#include <QCloseEvent>
#include <QWidget>
#include <QDebug>
#include <QTabWidget>
#include <QShortcut>
#include <QString>
#include <QIcon>

#include <cprime/utilities.h>


class coreterminal : public QTermWidget
{
    Q_OBJECT

public :
    coreterminal(QWidget *parent =nullptr);
    coreterminal(const QString &workDir, QWidget *parent = nullptr);
    coreterminal(const QString &workDir, const QString &command, QWidget *parent = nullptr);
    QString currentWorkingDirectory();

private:
    QString oldCWD;

private slots:
    void handleFSWSignals(QString);

protected:
    void closeEvent(QCloseEvent *cEvent);

Q_SIGNALS:
    void chDir(QString);

};

static QFileSystemWatcher *watcher = new QFileSystemWatcher();

#endif // CORETERMWIDGET_H
