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

#ifndef LANGUAGE_HEADER
#define LANGUAGE_HEADER

#include <QString>
#include <QVector>
// #include <QStringList>

// QString translateString(const QString& id);
class cTranslator
{
    public:
        bool loadTranslation(const QString fname);
    public:
        static QString translate(int id);
        static QString engText[];
    private:
        QString convertString(const QString &s);

    private:
        static QVector<QString> translateTable;
};


enum TR_CONSTS {
    _PROG_NAME = 0,
    _ENDSTREAM, //1
    _BREAK_CONN, //2
    _CONN_SUCCSESS, //3
    _DEMO, //4
    _CONNECTED, //5
    _DEV_NOTFOUND, //6
    _START_STREAM, //7
    _ALREADY_EXISTS, //8
    _NOT_POSSIBLE, //9
    _DISCONNECTING, //10
    _ERR, //11
    _MSG_FOR_DISABLE, //12
    _MSG_NO_CONN, //13
    _MSG_NO_DATA, //14
    _START_PROG, //15
    _START_TASK_AT, //16
    _END_TASK_AT, //17
    _PAUSE, //18
    _OPEN_TITLE, //19
    _LOAD_FROM_FILE, //20
    _DISCONNECT_FROM_DEV, //21
    _CONNECT_TO_DEV, //22
    _START_TASK, //23
    _PAUSE_TASK, //24
    _STOP_TASK, //25
    _RUN_TASK, //26
    _WAIT, //27
    _QUEST_START_FROMLINE, //28
    _QUEST_START_FROMTOLINE, //29
    _RECIEVED_M0, //30
    _PAUSE_G4, //31
    _PAUSE_ACTIVATED, //32
    _POSITION, //33
    _NUM_INSTR, //34
    _MM_MIN, //35
    _NOT_DECODED, //36
    _FILEERR, // 37
    _ABOUT_TITLE, // 38
    _ABOUT_TEXT,  // 39
    _CORRECTURE, // 40
    _PROPORTION, // 41
    _EDITGCODE_TITLE, // 42
    _OFFSET_GCODE, // 43
    _CORRECT_Z, // 44
    _NUMPAD_HELP, // 45
    _VELOCITY, // 46
    _MOUSE_CONTROL, // 47
    _BEG_SURFACE, // 48
    _STEP_PROP, // 49
    _STEP_Y, // 50
    _STEP_X, // 51
    _NUM_X, // 52
    _NUM_Y, // 53
    _SCAN, // 54
    _VIEW_ONLY, // 55
    _TEST_SCAN, // 56
    _RET_MM, // 57
    _VELOSCAN, // 58
    _TABLE_POINT, // 59
    _SET_Z, // 60
    _MOVE_TOPOINT, // 61
    _SCANNING, // 62
    _STOP_SCAN, // 63
    _PULSES_PER_MM, // 64
    _DEV_SIMULATION, // 65
    _DEV_SIM_HELP, // 66
    _CANCEL, // 67
    _APPLY, // 68
    _SETTINGS_TITLE, // 69
    _DISPLAY_SPINDLE, // 70
    _DISPLAY_GRID, // 71
    _STEP, // 72
    _BEGIN, // 73
    _END, // 74
    _DISPLAY_SURFACE, // 75
    _DISPLAY_AXES, // 76
    _BASIC,  // 77
    _RESET, // 78
    _MAXIMUM, // 79
    _MINIMUM, // 80
    _DISPLAY_RANG, // 81
    _ADDITIONAL_3D, // 82
    _SETTINGS3D_TITLE, // 83
    _FILE, // 84
    _OPEN_FILE, // 85
    _WORK_END, // 86
    _CONTROLLER, // 87
    _CONNECT, // 88
    _DISCONNECT, //89
    _CONTR_SETTINGS, // 90
    _HELP, // 91
    _ABOUT, // 92
    _SPINDLE, // 93
    _STOP, // 94
    _ADDITIONAL, // 95
    _SETT_CONTROLLER, // 96
    _SETT_3D, // 97
    _MOD_GENERATION, // 98
    _MANIPULATION, // 99
    _POINTS, // 100
    _COORDINATES, // 101
    _DISPL_LIMITS, // 102
    _MIN, // 103
    _MAX, // 104
    _MANUAL_CONTROL, // 105
    _VELO, // 106
    _NUMPAD_CONTROL, // 107
    _GCODE_RUNNING, // 108
    _MANUAL_VELO, // 109
    _VELO_TRANSMISSION, // 110
    _VELO_MOVING, // 111
    _SOURCE_3D, // 112
    _GEN_SIGNAL, // 113
    _RC, // 114
    _HZ, // 115
    _OFF, // 116
    _VELO_PWM, // 117
    _CHAN_PWM, // 118
    _SEND_COMMAND, // 119
    _ON_SPINDLE, // 120
    _BYTE_19, // 121
    _BYTE_15, // 122
    _BYTE_14, // 123
    _MOVING_TOPOINT, // 124
    _RUN, // 125
    _CLEAN, // 126
    _PROG_RUNNING, // 127
    _FROM_NUM, // 128
    _G_CODE, // 129
    _YES, // 130
    _NO, // 131
    _OK, // 132
    _WRONGLINE, // 133
    _COMMAND, // 134
    _STATE, // 135
    _INFO, // 136
    _ROTATION, // 137
    _EXIT, // 138
    _LANGUAGE, // 139
    _SETTINGS, // 140
    _PROGRAM, // 141
    _DATA, // 142
    _LOG, // 143
    _3D_VIEW, // 144
    _SUBMISSION, // 145
    _MOVING, // 146
    _HOTPLUGED, //  147
    _DETACHED, // 148
    _NULL
};


#endif