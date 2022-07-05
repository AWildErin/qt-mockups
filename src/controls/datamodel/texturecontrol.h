#pragma once

#include <QGridLayout>
#include <QLineEdit>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QPainter>
#include <QFileInfo>

#include "dmecontrol.h"

namespace ui
{
	class CTextureControl : public CDmeControl
	{
		Q_OBJECT;
	public:
		CTextureControl( QWidget *pParent = nullptr, const QString &varName = "", const QString &texType = "color" );
	};

	// ==================================================== //

	class CTextureButton : public QPushButton
	{
		Q_OBJECT;
	public:
		CTextureButton( QWidget *pParent = nullptr, const QString &iconPath = "" );

	protected:
		void paintEvent( QPaintEvent *pe ) override;

	private:
		QString m_ImagePath;
		QPixmap m_ImagePixmap;
	};
} // namespace ui