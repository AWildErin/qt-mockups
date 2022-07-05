#include "materialeditor.h"

using namespace ui;

CMaterialEditor::CMaterialEditor( QWidget *pParent ) :
	QDialog( pParent )
{
	this->setWindowTitle( "Material Editor" );
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

	auto pFeaturesWidget = new CFeatureWidget( this );
	pFeaturesWidget->setFixedWidth( 250 );
	pDialogLayout->addWidget( pFeaturesWidget );

	auto pVariablesWidget = new CVariableWidget( this );
	pDialogLayout->addWidget( pVariablesWidget );

	this->setMinimumWidth( 720 );
	this->setMinimumHeight( 480 );
};
