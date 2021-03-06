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

#include "MiniatureViewLandscape.h"

#include <QDebug>
#include <QPainter>

#include "QBookApp.h"
#include "Viewer.h"

#define BORDER_OFFSET           2
#define FRAME_WIDTH             2
#define SCREENSHOT_MARGIN       6

#define PAGE_FORMAT QString("%1/%2")
//const QString PAGE_FORMAT("%1/%2");
const QString PERCENT_FORMAT("%1%");

MiniatureViewLandscape::MiniatureViewLandscape(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    /// Values from viewer_styles.qss -> #miniatureRightSpacer
    if (QBook::getResolution() == QBook::RES600x800) WIDGET_ASPECT_RATIO = 148.0 / 125.0;
    else                                             WIDGET_ASPECT_RATIO = 189.0 / 160.0;
}

MiniatureViewLandscape::~MiniatureViewLandscape()
{
    qDebug() << Q_FUNC_INFO;
}

void MiniatureViewLandscape::paintEvent (QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void MiniatureViewLandscape::changeAspectRatio(QRectF docRect)
{
    double w = 0.0, h = 0.0;
    int xOff = 0,
        yOff = BORDER_OFFSET,
        maxWidth  = miniatureRightSpacer->width(),
        maxHeight = miniatureRightSpacer->height();

    /// WIDTH:HEIGHT
    m_aspectRatio = (double)docRect.height() / (double)docRect.width(); // transformation is done here.
    if (m_aspectRatio > WIDGET_ASPECT_RATIO)
    {
        w = maxWidth - 2*SCREENSHOT_MARGIN;
        h = w/m_aspectRatio;
    }
    else
    {
        h = maxHeight - 2*SCREENSHOT_MARGIN;
        w = h*m_aspectRatio;
    }

    // Centering.
    xOff += (maxWidth  - w)/2;
    yOff += (maxHeight - h)/2;
    // Add space to zoom and page labels.
    xOff += width() - maxWidth;

    screenshotLbl->setGeometry(xOff, yOff, w, h);
}

void MiniatureViewLandscape::setFrameGeometry(const double xoP, const double yoP, const double xfP, const double yfP)
{
    QPoint oP = screenshotLbl->mapTo(this, QPoint(0, 0));
    int x = oP.x() + xoP * screenshotLbl->width();
    int y = oP.y() + yoP * screenshotLbl->height();
    int w = (xfP-xoP) * screenshotLbl->width();
    int h = (yfP-yoP) * screenshotLbl->height();

    if (w+4 <= screenshotLbl->width()  && xfP != 1) w += 4;
    if (h+2 <= screenshotLbl->height() && yfP != 1) h += 2;

    frame->setGeometry(x, y, w, h);
}

void MiniatureViewLandscape::setPageChanged(int page, int, int total)
{
    /// FORMAT: page/total
    pageValueLbl->setText(PAGE_FORMAT.arg(page).arg(total));
}

void MiniatureViewLandscape::setZoomChanged(double newZoom)
{
    /// FORMAT: zoom%
    zoomValueLbl->setText(PERCENT_FORMAT.arg((int)(newZoom*100)));
}

void MiniatureViewLandscape::updatePdfMiniatureScreenshot(QPixmap& screenshot)
{
    if (screenshot.isNull()) return;
    m_screenshot = screenshot;
    screenshotLbl->setPixmap(screenshot.scaled(screenshotLbl->size()));
}
