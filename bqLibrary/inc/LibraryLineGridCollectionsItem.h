/*************************************************************************

bq Cervantes e-book reader application
Copyright (C) 2011-2013  Mundoreader, S.L

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

#ifndef LIBRARYLINEGRIDCOLLECTIONSITEM_H
#define LIBRARYLINEGRIDCOLLECTIONSITEM_H

#include "LibraryGridViewerItem.h"
#include "ui_LibraryLineGridCollectionsItem.h"

class LibraryLineGridCollectionsItem : public LibraryGridViewerItem, protected Ui::LibraryLineGridCollectionsItem
{
    Q_OBJECT

public:
                                    LibraryLineGridCollectionsItem         (QWidget * parent = 0);
    virtual                          ~LibraryLineGridCollectionsItem();

    void                            setCollection                           ( const QString& collectionName, const int booksNumber );
    virtual void                    setBook                                 ( const BookInfo* book, Library::ELibraryFilterMode filter ) {}
    virtual void                    setFile                                 ( const QFileInfo* file ) {}
    virtual void                    setArrow                                ( const QString& path ) {}
    virtual void                    select                                  () {}
    virtual void                    unselect                                () {}

signals:

    void                            deleteCollection                        (const QString&);
    void                            editCollection                          (const QString&);

protected slots:

    void                            deleteCollection                        ();
    void                            editCollection                          ();

    /* http://qt-project.org/forums/viewthread/7340 */
    void                            paintEvent                              (QPaintEvent *);

};


#endif // LIBRARYLINEGRIDCOLLECTIONSITEM_H
