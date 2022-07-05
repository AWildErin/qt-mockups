#include "featurewidget.h"

using namespace ui;

CFeatureWidget::CFeatureWidget( QWidget *pParent ) :
	QWidget( pParent )
{
	auto pWidgetLayout = new QVBoxLayout( this );

	pWidgetLayout->setAlignment( Qt::AlignTop );

	auto pShaderLayout = new QHBoxLayout();
	m_pShaderLineEdit = new QLineEdit( "LightmappedGeneric", this );
	m_pShaderLineEdit->setReadOnly( true );

	m_pShadersButton = new QPushButton( "Shaders..." );
	pShaderLayout->addWidget( m_pShaderLineEdit );
	pShaderLayout->addWidget( m_pShadersButton );

	pWidgetLayout->addLayout( pShaderLayout );

	auto pExample1 = new CTitledGroupBox( this, "Transparency", false, false );
	auto pAlphaTest = new QCheckBox( "Alpha Test", pExample1 );
	auto pTranslucent = new QCheckBox( "Translucent", pExample1 );
	pExample1->addWidget( pAlphaTest );
	pExample1->addWidget( pTranslucent );

	pWidgetLayout->addWidget( pExample1 );

};
