/****************************************************************************
 * Main developer:                                                          *
 * Copyright (C) 2014-2015 by Sergej Zheigurov                              *
 *                                                                          *
 * Qt developing                                                            *
 * Copyright (C) 2015 by Eduard Kalinowski                                  *
 * Germany, Lower Saxony, Hanover                                           *
 * eduard_kalinowski@yahoo.de                                               *
 *                                                                          *
 * ported from C# project CNC-controller-for-mk1                            *
 * https://github.com/selenur/CNC-controller-for-mk1                        *
 *                                                                          *
 * The Qt project                                                           *
 * https://github.com/eduard-x/cnc-qt                                       *
 *                                                                          *
 * CNC-Qt is free software; may be distributed and/or modified under the    *
 * terms of the GNU General Public License version 3 as published by the    *
 * Free Software Foundation and appearing in the file LICENSE_GPLv3         *
 * included in the packaging of this file.                                  *
 *                                                                          *
 * This program is distributed in the hope that it will be useful,          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 * GNU General Public License for more details.                             *
 *                                                                          *
 * You should have received a copy of the GNU Lesser General Public         *
 * License along with CNC-Qt. If not, see  http://www.gnu.org/licenses      *
 ****************************************************************************/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>

#include <QGLPixelBuffer>
#include <QScrollArea>
#include <QGLWidget>

#include <QtOpenGL>
#include <QImage>
#include <QTimeLine>
#include <QSvgRenderer>

#include <deque>
#include <utility>

#include "vec.h"
#include "GLWidget.h"
#include "Reader.h"
#include "mk1Controller.h"
#include "Geometry.h"
#include "Translator.h"
#include "ui_MainWindow.h"


class GLWidget;
class mk1Controller;
class cTranslator;
class Reader;


class MessageTimerBox: public QMessageBox
{
    private:
        int timeout;
        bool autoClose;
        int currentTime;
        QString defaultText;

    public:
        void setTimeout(int t);
        void setDefaultText(const QString &t);
        void setAutoClose(bool a);
        void showEvent ( QShowEvent * event );

    private:
        void timerEvent(QTimerEvent *event);
        //     static int exec(const QString &title, const QString &text, int ticon, int timer);
};


class MessageBox: public cTranslator
{
    public:
        static int exec(void* p, const QString &title, const QString &text, int ticon);
};


//
// Виды статусов выполнения задания
//
enum EStatusTask { Waiting = 0, TaskStart, TaskWorking, TaskPaused, TaskStop };

//
// Класс для работы с заданием для контроллера
//
class Task
{
        //
        // Сво-во для определения режима работы
        //
    public:
        static EStatusTask StatusTask;

        ////
        //// Номер строки с заданием для выполнения
        ////
        //static int indexLineTask = -1;

        ////
        //// Количество выделенных строк (если выделено более 1-й строки, то нужно выполнить задание только по этим строкам)
        ////
        //static int countSelectLineTask = 0;


        //
        // Начальная позиция для выполнения
        //
        static int posCodeStart;
        //
        // Конечная позиция для выполнения
        //
        static int posCodeEnd;
        //
        // Текущая позиция выполнения
        //
        static int posCodeNow;
};


class MainWindow : public QMainWindow, public Ui::MainWindow,  public Reader
{
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();


        void fillListWidget(QStringList listCode);
        double GetDeltaZ(double _x, double _y);

    public:
        // Набор готовых инструкций для станка

        mk1Controller *cnc;

        QVector<QVector<dPoint> > surfaceMatrix; // dataCode

        QString programStyleSheet;

        // Для использования, корректировки положения
        // Необходимость применения корректировки данных
        bool Correction;
        double deltaX;
        double deltaY;
        double deltaZ;
        double koeffSizeX;
        double koeffSizeY;
        bool deltaFeed;
        //

        GLWidget *scene3d; // OpenGL widget


        // 3d Settings
        bool ShowGrate;
        double grateXmin;
        double grateXmax;
        double grateYmin;
        double grateYmax;


        int PosX, PosY, PosZ;
        int PosAngleX, PosAngleY, PosAngleZ;
        int PosZoom;

        bool ShowInstrument;
        bool ShowGrid;
        bool ShowSurface;
        bool ShowAxes;

        int GridXstart;
        int GridXend;
        int GridYstart;
        int GridYend;
        int GrigStep;
        // end of 3d


    public slots:
        // connect to controller
        void onCncMessage(int n_msg);
        //         void onCncConnect();
        void onCncNewData();
        //         void onCncDisconnect();
        void onCncHotplug();
        //         void onCncDetach();


    private slots:
        void onExit();
        //         void onConnect();
        //         void onDisconnect();
        //         void onConnDisconnect();
        void onManualControlDialog();

        void onOpenFile();
        void onSaveFile();

        void onSettings();
        void onLogClear();

        void onSpindel();
        void onEmergyStop();
        void onScanSurface();
        void onEditGCode(int row, int col);
        void onCellSelect(int row, int col);

        void onStartTask();
        void onPauseTask();
        void onStopTask();
        void onMainTaskTimer();

        void onStatus(); // not connected
        void onRunToPoint();
        void onSendCommand();

        void on3dSettings();

        void trackBar1_Scroll(); // not connected
        //         void onLikePoint(); // not connected
        //         void listBox1(); // not connected
        //         void listBox1_DataSourceChanged(); // not connected
        void listBox1_SelectedIndexChanged(); // not connected
        void onGeneratorCode(); // not connected

        bool readLangDir();

        void onAbout();
        void onAboutQt();

        void setLang(QAction* mnu);

    public slots:

        void onButtonXtoZero();
        void onButtonYtoZero();
        void onButtonZtoZero();

        void getZRotation(int z);
        void getYRotation(int y);
        void getXRotation(int x);
        void getScale(int s);


    private:

        void Feed();
        QString getLocaleString();
        bool getLangTable();
        void setLangGUI();
        void displayRotation();
        void addConnections();
        void translateGUI();
        void addStatusWidgets();

        void refreshElementsForms();


        void AddLog(QString _text = "");
        void SendSignal();
        void readGUISettings();
        void readSettings(bool global);
        void writeSettings(bool global);
        void writeGUISettings(void);
        QString selectedLang;

    private:
        QTimer  mainTaskTimer;

        QLabel *statusLabel1;
        QProgressBar *statusProgress;
        QLabel *statusSt;
        QLabel *statLabelNumInstr;

        QTimer  renderTimer;
        QVector<QAction*> actLangSelect;
        //         QVector<QAction*> actFSizeSelect;
        QMenu *langMenu;
        //         QAction* restAct;
        QActionGroup* langGroup;
        QFont sysFont;
        short fontSize;
        //         QString programStyleSheet;
        QStringList langFiles;
        QString langDir;
        QString helpDir;
        QString currentLang;

        int xAngle, yAngle, zAngle;
        int scale;
        QString currentAppDir;
};

#endif // MAINWINDOW_H