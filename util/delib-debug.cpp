#include "delib-debug.h"
#include <stdlib.h>
#include <iostream>
#include <qapplication.h>
#include <QPoint>

//
//  Copyright (C) 2010 - Bernd H Stramm 
//
// This file is distributed under the terms of 
// the GNU General Public License version 2 
//
// This software is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty 
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
//


using namespace std;

namespace deliberate {


static DebugLog *staticLog(0);

void UseMyOwnMessageHandler ()
{
  qInstallMsgHandler (deliberate::MyOwnMessageOutput);
}

void MyOwnMessageOutput (QtMsgType type, const char* msg)
{
#if DELIBERATE_DEBUG
  switch (type) {
  case QtDebugMsg:
    staticLog->Log ("Qt Debug: ");
    break;
  case QtWarningMsg:
    staticLog->Log ("Qt Warn: ");
    break;
  case QtCriticalMsg:
    staticLog->Log ("Qt Critical: ");
    break;
  case QtFatalMsg:
    cout << "Qt Fatal: " << msg << endl;
    staticLog->Log ("Qt Fatal: ");
    abort();
    break;
  default:
    cout << " unknown Qt msg type: " << msg << endl;
    break;
  }
  staticLog->Log ( msg);
#else
  switch (type) {
  case QtFatalMsg:
    cout << "Qt Fatal: " << msg << endl;
    abort();
    break;
  case QtDebugMsg:
  case QtWarningMsg:
  case QtCriticalMsg:
  default:
    // start prayer, maybe it's not a problem
    break;
  }
#endif

}


void
StartDebugLog ()
{
  if (staticLog == 0) {
    staticLog = new DebugLog ;
  }
  staticLog->StartLogging ();
  staticLog->move (QPoint (0,0));
  staticLog->show ();
}

void
StopDebugLog ()
{
  if (staticLog) {
    staticLog->StopLogging ();
    staticLog->hide ();
  }
}

bool
DebugLogRecording ()
{
  if (staticLog) {
    return staticLog->IsLogging();
  } else {
    return false;
  }
}


DebugLog::DebugLog ()
:QDialog(0),
 isLogging (false)
{
  setupUi (this);
  Connect ();
  hide ();
}

DebugLog::DebugLog (QWidget * parent)
:QDialog (parent),
 isLogging (false)
{
  setupUi (this);
  Connect ();
  hide ();
}

void
DebugLog::Connect ()
{
  connect (closeButton, SIGNAL (clicked()), this, SLOT(Close()));
  connect (stopButton, SIGNAL (clicked()), this, SLOT (StopLogging()));
  connect (startButton, SIGNAL (clicked()), this, SLOT (StartLogging()));
}

void
DebugLog::Close ()
{
  isLogging = false;
  hide ();
}

void
DebugLog::quit ()
{
  Close ();
}

void
DebugLog::closeEvent (QCloseEvent *event)
{
  Close ();
}

bool
DebugLog::Log (const char* msg)
{
  if (isLogging) {
    logBox->append (QString(msg));
    update ();
  }
  return isLogging;
}

} // namespace
