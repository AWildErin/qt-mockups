#include <QApplication>
#include <QIcon>
#include <QFile>
#include <QDir>
#include <QDirIterator>
#include <QDebug>

#include "tools/met/materialeditor.h"
#include "tools/dmeshowcase.h"

// Todo: Move both to resource manager?
void SetupStylesheets();
void SetupSearchPaths();

int main(int argc, char** argv)
{
	QApplication app( argc, argv );

	SetupSearchPaths();
	SetupStylesheets();

	QApplication::setAttribute( Qt::AA_DisableWindowContextHelpButton );
	QApplication::setWindowIcon( QIcon( "toolimages:/appicon_tools.ico" ) );

	auto pDialog = new ui::CMaterialEditor( nullptr );
	pDialog->show();

	return QApplication::exec();
}

void SetupStylesheets()
{
	// Manual Stylesheet files
	QStringList files = { 
		":/resource/base_style.qss",

		// Valve
		//":/resource/styles/valve/widget.qss",
		//":/resource/styles/valve/frame.qss",
		//":/resource/styles/valve/scrollarea.qss",
		//":/resource/styles/valve/menubar.qss",
		//":/resource/styles/valve/menu.qss",
		//":/resource/styles/valve/tabwidget.qss",
		//":/resource/styles/valve/tabbar.qss",
		//":/resource/styles/valve/abstractitemview.qss",
		//":/resource/styles/valve/headerview.qss",
		//":/resource/styles/valve/treeview.qss",
		//":/resource/styles/valve/tableview.qss",
		//":/resource/styles/valve/scrollbar.qss",
		//":/resource/styles/valve/pushbutton.qss",
		//":/resource/styles/valve/toolbutton.qss",
		//":/resource/styles/valve/toolbar.qss",
		//":/resource/styles/valve/messagebox.qss",
		//":/resource/styles/valve/dialogbuttonbox.qss",
		//":/resource/styles/valve/combobox.qss",
		//":/resource/styles/valve/radiobutton.qss",
		//":/resource/styles/valve/plaintextedit.qss",
		//":/resource/styles/valve/global.qss",
		//":/resource/styles/valve/checkbox.qss",
		//":/resource/styles/valve/tooltip.qss",
		//":/resource/styles/valve/abstractspinbox.qss",
		//":/resource/styles/valve/groupbox.qss",
		//":/resource/styles/valve/progressbar.qss",
		//":/resource/styles/valve/slider.qss",
		//":/resource/styles/valve/splitter.qss",
		//":/resource/styles/valve/lineedit.qss",

		// Controls
		":/resource/styles/titledgroupbox.qss",
		":/resource/styles/texturecontrol.qss"
	};

	QStringList rawStyleSheets;

	for ( QString fileName : files )
	{
		QFile file( fileName );
		file.open( QFile::ReadOnly );
		rawStyleSheets.append( file.readAll() );
	}

	qApp->setStyleSheet( rawStyleSheets.join( "\n" ) );
}

void SetupSearchPaths()
{
	QDir::setSearchPaths( "tools", QStringList( "./tools" ) );
	QDir::setSearchPaths( "toolimages", QStringList( "tools:/images" ) );
}
