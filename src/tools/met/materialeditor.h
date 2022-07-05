#pragma once

#include <QDialog>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

#include <QSplitter>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QPixmap>
#include <QLabel>

#include "featurewidget.h"
#include "variablewidget.h"
#include "../../widgets/titledgroupbox.h"

namespace ui
{
	class CMaterialEditor : public QDialog
	{
		Q_OBJECT;
	public:
		CMaterialEditor( QWidget *pParent = nullptr );
	};
}