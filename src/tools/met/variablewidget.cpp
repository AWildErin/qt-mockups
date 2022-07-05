#include "variablewidget.h"

using namespace ui;

CVariableWidget::CVariableWidget( QWidget *pParent ) :
	QWidget( pParent )
{
	auto pWidgetLayout = new QVBoxLayout( this );

	auto pColorGroup = new CTitledGroupBox( this, "Color" );
	pColorGroup->addWidget( new CTextureControl( pColorGroup, "Base Texture" ) );

	auto pLightingGroup = new CTitledGroupBox( this, "Lighting" );
	pLightingGroup->addWidget( new CTextureControl( pLightingGroup, "Bump Map", "normal" ) );
	pLightingGroup->addWidget( new CTextureControl( pLightingGroup, "Lightwarp Texture", "diffusewarp" ) );

	auto pReflection = new CTitledGroupBox( this, "Reflection" );
	//pColorGroup->layout()->addWidget( new CTextureControl( pColorGroup, "Base Texture" ) );

	pWidgetLayout->addWidget( pColorGroup );
	pWidgetLayout->addWidget( pLightingGroup );
	pWidgetLayout->addWidget( pReflection );
};
