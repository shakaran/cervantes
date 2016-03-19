/*************************************************************************

bq Cervantes e-book reader application
Copyright (C) 2011-2016  Mundoreader, S.L

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with the source code.  If not, see <http://www.gnu.org/licenses/>.

*************************************************************************/

#ifndef SETTINGSPAGERCONT_H
#define SETTINGSPAGERCONT_H

#include "ui_SettingsPagerCont.h"
#include "QBookForm.h"

class FullScreenWidget;

class SettingsPagerCont : public QWidget, protected Ui::SettingsPagerCont{

    Q_OBJECT

public:
                    SettingsPagerCont                           (QWidget* parent = 0);
    virtual         ~SettingsPagerCont                          ();

    void            setup                                       (int);
    void            hidePages                                   ();

signals:

    void            nextPageReq                                 ();
    void            previousPageReq                             ();
    void            firstPage                                   ();
    void            lastPage                                    ();

public slots:

    void            nextPage                                    ();
    void            previousPage                                ();
    void            handleSwipe                                 (int);

protected:

    /* http://qt-project.org/forums/viewthread/7340 */
    void            paintEvent                                  (QPaintEvent *);
};

#endif // SETTINGSPAGERCONT_H
