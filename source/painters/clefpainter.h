/*
  * Copyright (C) 2011 Cameron White
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
  
#ifndef CLEFPAINTER_H
#define CLEFPAINTER_H

#include "painterbase.h"

#include <QStaticText>
#include <boost/shared_ptr.hpp>

class StaffData;
class Staff;

class ClefPainter : public PainterBase
{
public:
    ClefPainter(boost::shared_ptr<const Staff> staff,
                const QFont& musicFont);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    void init();

    boost::shared_ptr<const Staff> staff;
    const QFont& musicFont;
    QStaticText displayText;
};

#endif // CLEFPAINTER_H
