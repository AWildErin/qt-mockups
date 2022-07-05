#include "titledgroupbox.h"

#include <QDebug>

using namespace ui;

CTitledGroupBox::CTitledGroupBox( QWidget *pParent, const QString &title, const bool bSettingsButton, const bool bExpandButton ) :
	QWidget( pParent )
{
	m_bSettingsButton = bSettingsButton;
	m_bExpandButton = bExpandButton;

	QVBoxLayout *pRootLayout = new QVBoxLayout( this );

	auto pHeaderLayout = new QHBoxLayout();
	pHeaderLayout->setSpacing( 0 );
	pRootLayout->addLayout( pHeaderLayout );

	m_pGroupFrame = new QFrame( this );
	pRootLayout->addWidget( m_pGroupFrame );

	m_pWidgetLayout = new QVBoxLayout( m_pGroupFrame );

	if ( hasSettingsButton() )
	{
		m_pSettingsButton = new QPushButton( this );
		m_pSettingsButton->setIcon( QIcon( "toolimages:/common/options.png" ) );
		m_pSettingsButton->setObjectName( "GroupSettings" );
		m_pSettingsButton->setFlat( true );
		pHeaderLayout->addWidget( m_pSettingsButton );
	}

	m_pTitle = new QLabel( title );
	m_pTitle->setObjectName( "GroupTitle" );
	m_pTitle->setAlignment( Qt::AlignCenter );
	// Allow the label to expand horizontally, but not vertically
	m_pTitle->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );
	pHeaderLayout->addWidget( m_pTitle );

	if ( hasExpandButton() )
	{
		m_pExpandButton = new QPushButton( this );
		m_pExpandButton->setIcon( QIcon( "toolimages:/propertyeditor/hierarchy_expanded.png" ) );
		m_pExpandButton->setObjectName( "GroupExpand" );
		m_pExpandButton->setCheckable( true );
		m_pExpandButton->setChecked( true );
		m_pExpandButton->setFlat( true );

		connect( m_pExpandButton, &QPushButton::toggled, this, &CTitledGroupBox::setExpanded );

		pHeaderLayout->addWidget( m_pExpandButton );
	}

	// Start expanded
	setExpanded( true );

	this->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );
	this->setAttribute( Qt::WA_StyledBackground );
};

void CTitledGroupBox::addWidget( QWidget *pWidget )
{
	m_pWidgetLayout->addWidget( pWidget );
};

bool CTitledGroupBox::hasSettingsButton() const
{
	return m_bSettingsButton;
};

void CTitledGroupBox::setSettingsButton( bool settingsButton )
{
	m_bSettingsButton = settingsButton;
};

bool CTitledGroupBox::hasExpandButton() const
{
	return m_bExpandButton;
};

void CTitledGroupBox::setExpandButton( bool expandButton )
{
	m_bExpandButton = expandButton;
}

bool CTitledGroupBox::isExpanded() const
{
	return m_bExpanded;
}

void CTitledGroupBox::setExpanded( bool expand )
{
	// Update the button icon if it exists
	if ( m_bExpandButton )
	{
		// FIX ME: This makes the button expand by a few pixels, not too sure why
		QString iconPath = expand ? "toolimages:/propertyeditor/hierarchy_expanded.png" : "toolimages:/propertyeditor/hierarchy_collapsed.png";
		m_pExpandButton->setIcon( QIcon( iconPath ) );
	}

	m_bExpanded = expand;
	m_pGroupFrame->setVisible( expand );

	Q_EMIT expandedChanged( expand );
}
