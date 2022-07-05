#pragma once

#include <QCheckbox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include "../../widgets/titledgroupbox.h"
#include "../../controls/datamodel/texturecontrol.h"

namespace ui
{
	class CVariableWidget : public QWidget
	{
		Q_OBJECT;

	public:
		CVariableWidget( QWidget *pParent = nullptr );
	};
} // namespace ui