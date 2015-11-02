/****************************************************************************
 * Main developer, C# developing:                                           *
 * Copyright (C) 2014-2016 by Sergey Zheigurov                              *
 * Russia, Novy Urengoy                                                     *
 * zheigurov@gmail.com                                                      *
 *                                                                          *
 * C# to Qt portation, Linux developing                                     *
 * Copyright (C) 2015-2016 by Eduard Kalinowski                             *
 * Germany, Lower Saxony, Hanover                                           *
 * eduard_kalinowski@yahoo.de                                               *
 *                                                                          *
 * C# project CNC-controller-for-mk1                                        *
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

#include <QtGui>


#include "includes/CuttingCalc.h"


/******************************************************************************
** CuttingCalcDialog
*/

// http://www.gravman.ru/speed.htm
// tables: http://www.pdsspindles.com/engineering-speeds


CuttingCalc::CuttingCalc(QWidget *p)
    : QDialog(p)
{
    setupUi(this);

    parent = static_cast<MainWindow*>(p);

    setStyleSheet(parent->programStyleSheet);

    connect(checkCorrecture, SIGNAL(stateChanged ( int)), this, SLOT(checkedChanged( int )));

    checkCorrecture->setChecked(true);
    checkCorrecture->setChecked(false); // toggle

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(onSaveChange()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    doubleSpinOffsetX->setValue(parent->deltaX);
    doubleSpinOffsetY->setValue(parent->deltaY);
    doubleSpinOffsetZ->setValue(parent->deltaZ);

    checkBoxZ->setChecked(parent->deltaFeed);

    doubleSpinResizeX->setValue(parent->koeffSizeX);
    doubleSpinResizeY->setValue(parent->koeffSizeY);

    //     checkResizeZ->setChecked();

    translateDialog();

    adjustSize();
}


void CuttingCalc::translateDialog()
{
    setWindowTitle(translate(_EDITGCODE_TITLE));
    checkCorrecture->setText(translate(_CORRECTURE));
    groupResize->setTitle(translate(_PROPORTION));
    groupOffset->setTitle(translate(_OFFSET_GCODE));
    checkBoxZ->setText(translate(_CORRECT_Z));
}


void CuttingCalc::checkedChanged( int state)
{
    bool check = checkCorrecture->isChecked();
    groupOffset->setEnabled(check);
    groupResize->setEnabled(check);
}


void CuttingCalc::onSaveChange()
{
    if (checkCorrecture->isChecked()) {
        parent->deltaX = doubleSpinOffsetX->value();
        parent->deltaY = doubleSpinOffsetY->value();
        parent->deltaZ = doubleSpinOffsetZ->value();

        parent->deltaFeed = checkBoxZ->isChecked();

        parent->koeffSizeX = doubleSpinResizeX->value();
        parent->koeffSizeY = doubleSpinResizeY->value();
    }

    emit accept();
}
