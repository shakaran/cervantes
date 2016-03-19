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

#ifndef BROWSERFAVOITEM_H
#define BROWSERFAVOITEM_H

#include "GestureWidget.h"
#include "ui_BrowserFavoItem.h"


class BrowserFavoItem :  public GestureWidget, Ui::BrowserFavoItem
{
    Q_OBJECT

public:
                    BrowserFavoItem                          (QWidget*);
    virtual         ~BrowserFavoItem                         ();
    void            setItem                                  ( const QString& , const QString& );
    void            hideItem                                 ();
    void            setChecked                               (bool);
    bool            isChecked                                ();


public slots:
    //void            handleTap                           ();
    void            paintEvent                          (QPaintEvent *);

signals:
    void            handleTap                           (QString);
    void            select                              ();

protected slots:
    void            handleTap                           ();
    void            handleCheckBtn                      ();

protected:
    bool            m_checked;
    QString         m_url;

};
#endif // BROWSERFAVOITEM_H
