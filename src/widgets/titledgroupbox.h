#pragma once

#include <QWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QMenu>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace ui
{
	// todo: Set expanding
	// todo: Add methods to nicely add a menu
	// todo: add methods to nicely add stuff to the group box
	class CTitledGroupBox : public QWidget
	{
		Q_OBJECT;

		Q_PROPERTY( bool settingsButton READ hasSettingsButton WRITE setSettingsButton )
		Q_PROPERTY( bool expandButton READ hasExpandButton WRITE setExpandButton )
		Q_PROPERTY( bool expanded READ isExpanded WRITE setExpanded NOTIFY expandedChanged )
	public:
		CTitledGroupBox( QWidget *pParent = nullptr, const QString &title = "", const bool bSettingsButton = true, const bool bExpandButton = true );

		void addWidget( QWidget *pWidget );

		bool hasSettingsButton() const;
		void setSettingsButton( bool settingsButton );
			
		bool hasExpandButton() const;
		void setExpandButton( bool expandButton );

		bool isExpanded() const;
		void setExpanded( bool expand );

	Q_SIGNALS:
		void expandedChanged( bool expanded );

	private:
		QPushButton *m_pSettingsButton;
		QPushButton *m_pExpandButton;
		QLabel *m_pTitle;

		QFrame *m_pGroupFrame;
		QVBoxLayout *m_pWidgetLayout;

		bool m_bSettingsButton;
		bool m_bExpandButton;
		bool m_bExpanded;

		//bool m_bIsExpanded;
		//bool m_bIsCollapsable;
	};
}