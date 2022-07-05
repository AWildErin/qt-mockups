#pragma once

#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QPixmap>
#include <QSplitter>
#include <QToolBar>
#include <QVBoxLayout>

namespace ui
{
	class CDmeShowcase : public QDialog
	{
		Q_OBJECT;

	public:
		CDmeShowcase( QWidget *pParent = nullptr );
	};
} // namespace ui