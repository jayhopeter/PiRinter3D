/*
* =================BEGIN GPL LICENSE BLOCK=========================================
* 
*  This program is free software; you can redistribute it and/or 
*  modify it under the terms of the GNU General Public License 
*  as published by the Free Software Foundation; either version 2 
*  of the License, or (at your option) any later version. 
* 
*  This program is distributed in the hope that it will be useful, 
*  but WITHOUT ANY WARRANTY; without even the implied warranty of 
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
*  GNU General Public License for more details. 
* 
*  You should have received a copy of the GNU General Public License 
*  along with this program; if not, write to the Free Software Foundation, 
*  Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA. 
* 
* =================END GPL LICENSE BLOCK=========================================
*/
#ifndef MOTORWORKER_H
#define MOTORWORKER_H
#include <QThread>
#include <QtCore>
#include "steppermotor.h"

class MotorWorker : public QObject
{
    Q_OBJECT
    StepperMotor *_Motor;

public:
    bool StopThread;
    bool IsBusy;
	int StepDelay;

    MotorWorker(StepperMotor *Motor, int MS_Delay = 2)
    {
        this->_Motor = Motor;
        this->StopThread = false;
		this->StepDelay = MS_Delay;
    }

public slots:
    void DoWork()
    {
        qDebug()<< "Firing Thread!";
        while (!this->StopThread)
        {
            _Motor->Rotate(_Motor->Direction, 1, StepDelay);
            qDebug()<< "Stepping";
            emit ProgressChanged(QString::number(_Motor->Position));
        }
        this->StopThread = false;
		emit WorkComplete("Done");
    }

    void Stop()
    {
        qDebug()<< "Setting Stop Flag!";
        this->StopThread = true;
    }

signals:
    void ProgressChanged(QString info);
    void WorkComplete(QString result);
    void Error(QString err);
};

#endif // MOTORWORKER_H
