#include "dmeshowcase.h"

using namespace ui;

CDmeShowcase::CDmeShowcase( QWidget *pParent ) :
	QDialog( pParent )
{
	this->setWindowTitle( "Datamodel Controls Showcase" );
	this->setWindowIcon( QIcon( "toolimages:/met/appicon.ico" ) );

	Qt::WindowFlags flags = Qt::WindowMinimizeButtonHint & Qt::WindowMaximizeButtonHint;
	this->setWindowFlags( flags );

	auto pDialogLayout = new QHBoxLayout( this );
	pDialogLayout->setAlignment( Qt::AlignTop );

	auto pMenuBar = new QMenuBar( this );
	auto pFile = pMenuBar->addMenu( "File" );
	pFile->addAction( "Open..." );
	pMenuBar->addMenu( "Tools" );
	pMenuBar->addMenu( "View" );
	pMenuBar->addMenu( "Help" );

	pDialogLayout->setMenuBar( pMenuBar );

	this->setMinimumWidth( 720 );
	this->setMinimumHeight( 480 );
};
