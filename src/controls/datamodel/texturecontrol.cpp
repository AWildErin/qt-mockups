#include "texturecontrol.h"

using namespace ui;

CTextureControl::CTextureControl( QWidget *pParent, const QString &varName, const QString &texType ) :
	CDmeControl( pParent )
{
	auto pWidgetLayout = new QGridLayout( this );

	auto pTitle = new QLabel( varName, this );
	pWidgetLayout->addWidget( pTitle, 0, 0 );

	auto pLineEdit = new QLineEdit( "Path To Material", this );
	pLineEdit->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );
	pWidgetLayout->addWidget( pLineEdit, 1, 0 );

	auto pTexIcon = new QLabel( this );

	QString iconPath( "toolimages:/met/imagetypes/image_type_%1.png" );
	QFileInfo checkFile( iconPath.arg( texType ) );
	if ( checkFile.exists() )
		pTexIcon->setPixmap( QPixmap( iconPath.arg( texType ) ) );
	else
		pTexIcon->setPixmap( QPixmap( iconPath.arg( "color" ) ) );

	pWidgetLayout->addWidget( pTexIcon, 0, 1, Qt::AlignRight );

	auto pSearchLayout = new QHBoxLayout();

	auto pFolderButton = new QPushButton( this );
	pFolderButton->setIcon( QIcon( "toolimages:/common/folder.png" ) );
	pFolderButton->setFixedWidth( 20 );
	pSearchLayout->addWidget( pFolderButton );

	auto pSearchButton = new QPushButton( this );
	pSearchButton->setIcon( QIcon( "toolimages:/common/browse.png" ) );
	pSearchButton->setFixedWidth( 20 );
	pSearchLayout->addWidget( pSearchButton );

	pWidgetLayout->addLayout( pSearchLayout, 1, 1, Qt::AlignLeft );

	auto pBottomButtons = new QHBoxLayout();

	auto pColorModeButton = new QPushButton( this );
	pColorModeButton->setIcon( QIcon( "toolimages:/met/switch_to_color.png" ) );
	pColorModeButton->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );
	pBottomButtons->addWidget( pColorModeButton );

	auto pSettingsButton = new QPushButton( this );
	pSettingsButton->setIcon( QIcon( "toolimages:/met/state_settings.png" ) );
	pSettingsButton->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );
	pBottomButtons->addWidget( pSettingsButton );

	pWidgetLayout->addLayout( pBottomButtons, 2, 0, Qt::AlignLeft );

	auto pSizeLabel = new QLabel( "1x1", this );
	pWidgetLayout->addWidget( pSizeLabel, 2, 1, Qt::AlignRight | Qt::AlignTop );

	auto pTexPreview = new CTextureButton( this );
	pWidgetLayout->addWidget( pTexPreview, 0, 2, 3, 2, Qt::AlignLeft | Qt::AlignTop );

	auto pMenuButton = new QPushButton( this );
	pMenuButton->setIcon( QIcon( "toolimages:/common/dropdown_menu.png" ) );
	pMenuButton->setFixedWidth( 20 );
	pWidgetLayout->addWidget( pMenuButton, 0, 4, Qt::AlignLeft | Qt::AlignTop );

	this->setAttribute( Qt::WA_StyledBackground );
}

// ==================================================== //

CTextureButton::CTextureButton( QWidget *pParent, const QString &iconPath ) :
	QPushButton( pParent )
{
	this->setFlat( true );

	this->setFixedSize( 100, 100 );
}

void CTextureButton::paintEvent( QPaintEvent *pe )
{
	QPushButton::paintEvent( pe );

	QPainter p( this );

	// We set it to 79 since the pen adds 1 pixels
	QRect rect( 0, 0, 99, 99 );
	//QPoint center( this->rect().center().x() - 1, this->rect().center().y() - 1 );
	//rect.moveCenter( center );
	p.setBrush( Qt::darkGray );
	p.setPen( Qt::black );
	p.drawRect( rect );
}
