#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckbox>

#include "../../widgets/titledgroupbox.h"

namespace ui
{
	class CFeatureWidget : public QWidget
	{
		Q_OBJECT;
	public:
		CFeatureWidget( QWidget *pParent = nullptr );

	private:
		QLineEdit *m_pShaderLineEdit;
		QPushButton *m_pShadersButton;
	};
}