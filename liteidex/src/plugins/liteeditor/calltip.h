/**************************************************************************
** This file is part of LiteIDE
**
** Copyright (c) 2011-2014 LiteIDE Team. All rights reserved.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
**
** In addition, as a special exception,  that plugins developed for LiteIDE,
** are allowed to remain closed sourced and can be distributed under any license .
** These rights are included in the file LGPL_EXCEPTION.txt in this package.
**
**************************************************************************/
// Module: calltip.h
// Creator: visualfc <visualfc@gmail.com>

#ifndef CALLTIP_H
#define CALLTIP_H

#include <QObject>
#include <QWidget>

class CallTipWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CallTipWidget(QWidget *parent = 0);
    ~CallTipWidget();
    void setInfo(QString info);
    void showPopup(QRect rc);
signals:
    void mouseClick();
protected:
    virtual void paintEvent(QPaintEvent *e);
    virtual void mousePressEvent(QMouseEvent *event);
protected:
    QString m_info;
};

class CallTip : public QObject
{
    Q_OBJECT
public:
    explicit CallTip(QObject *parent = 0);
    ~CallTip();
    QWidget* widget();
    void CallTipStart(int pos, const QRect& rect, QString text, QWidget *parent);
    void ShowTip();
    bool InCallTipMode() const { return m_inCallTipMode; }
    int posStartCallTip() const { return m_pos; }
    void showPopup(const QRect& rect, QWidget *parent);
signals:
public slots:
    void CallTipCancel();
protected:
    CallTipWidget *popup;
    bool     m_inCallTipMode;
    int      m_pos;
};

#endif // CALLTIP_H