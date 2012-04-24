#ifndef COSTANTI_NAZIONI_H
#define COSTANTI_NAZIONI_H
#include <QPoint>
#include <QSize>
#include <QString>
#include <QRect>
#include <QTextStream>
#include <QFile>
#include <QColor>

class SizPos{
	QSize sz;
	QPoint pt;
public:
	SizPos():sz(0,0),pt(0,0){}
	SizPos(int w, int a, int x, int y): sz(w,a), pt(x,y){}
	void setDimensione(const QSize& dim){sz=dim;}
	void setPosizione(const QPoint& posi){pt=posi;}
	QSize dimensione() const {return sz;}
	QPoint posizione() const {return pt;}
	QRect rettangolo() const {return QRect(pt,sz);}
};

namespace ID_Stati{
	const short num_stati=42;
	const short nullo =-1;
	//Asia
	const short giappone=0;
	const short afganistan=1;
	const short urali=2;
	const short siberia=3;
	const short jacuzia=4;
	const short kamchatka=5;
	const short cita=6;
	const short mongolia=7;
	const short cina=8;
	const short medio_oriente=9;
	const short india=10;
	const short siam=11;
	//Oceania
	const short australia_orientale=12;
	const short australia_occidentale=13;
	const short nuova_guinea=14;
	const short indonesia=15;
	//Africa
	const short egitto=16;
	const short africa_del_nord=17;
	const short africa_del_sud=18;
	const short africa_orientale=19;
	const short congo=20;
	const short madagascar=21;
	//Europa
	const short europa_meridionale=22;
	const short europa_settentrionale=23;
	const short europa_occidentale=24;
	const short gran_bretagna=25;
	const short scandinavia=26;
	const short islanda=27;
	const short ucraina=28;
	//Sud America
	const short brasile=29;
	const short argentina=30;
	const short venezuela=31;
	const short peru=32;
	//Nord America
	const short america_centrale=33;
	const short stati_uniti_occidentali=34;
	const short stati_uniti_orientali=35;
	const short quebec=36;
	const short ontario=37;
	const short alberta=38;
	const short groenlandia=39;
	const short alaska=40;
	const short territori_del_nord_ovest=41;

	const QString Nomi_Stati[num_stati]={
		//Asia
		"Giappone",
		"Afganistan",
		"Urali",
		"Siberia",
		"Jacuzia",
		"Kamchatka",
		"Cita",
		"Mongolia",
		"Cina",
		"Medio Oriente",
		"India",
		"Siam",
		//Oceania
		"Australia orientale",
		"Australia occidentale",
		"Nuova guinea",
		"Indonesia",
		//Africa
		"Egitto",
		"Africa del Nord",
		"Africa del Sud",
		"Africa Orientale",
		"Congo",
		"Madagascar",
		//Europa
		"Europa Meridionale",
		"Europa Settentrionale",
		"Europa Occidentale",
		"Gran Bretagna",
		"Scandinavia",
		"Islanda",
		"Ucraina",
		//Sud America
		"Brasile",
		"Argentina",
		"Venezuela",
		"Peru",
		//Nord America
		"America Centrale",
		"Stati Uniti Occidentali",
		"Stati Uniti Orientali",
		"Quebec",
		"Ontario",
		"Alberta",
		"Groenlandia",
		"Alaska",
		"Territori dell'Ovest"
	};

	const SizPos sp_mappa(1024,574,0,0);
	const SizPos PosData_Stati[num_stati]={
		//Asia
		SizPos(41,92,899,107),		//Giappone
		SizPos(114,103,617,79),		//Afganistan
		SizPos(89,104,647,41),		//Urali
		SizPos(118,110,663,26),		//Siberia
		SizPos(157,62,760,38),		//Jacuzia
		SizPos(117,103,866,50),		//Kamchatka
		SizPos(168,52,725,81),		//Cita
		SizPos(157,76,746,109),		//Mongolia
		SizPos(177,124,713,125),	//Cina
		SizPos(131,118,558,154),	//Medio Oriente
		SizPos(130,132,674,168),	//India
		SizPos(65,110,789,208),		//Siam
		//Oceania
		SizPos(78,110,920,364),		//Australia Orientale
		SizPos(107,120,856,377),	//Australia Occidentale
		SizPos(77,42,931,323),		//Nuova Guinea
		SizPos(112,116,806,248),	//Indonesia
		//Africa
		SizPos(91,55,503,189),		//Egitto
		SizPos(146,143,410,173),	//Africa del Nord
		SizPos(103,117,511,345),	//Africa del Sud
		SizPos(104,140,547,230),	//Africa Orientale
		SizPos(80,99,501,278),		//Congo
		SizPos(28,55,620,370),		//Madagascar
		//Europa
		SizPos(76,58,492,125),		//Europa Meridionale
		SizPos(67,41,482,94),		//Europa Settentrionale
		SizPos(59,60,441,119),		//Europa Occidentale
		SizPos(37,33,444,90),		//Gran Bretagna
		SizPos(74,60,491,47),		//Scandinavia
		SizPos(39,20,409,71),		//Islanda
		SizPos(126,119,537,51),		//Ucraina
		//Sud America
		SizPos(138,156,210,300),	//Brasile
		SizPos(68,149,226,392),		//Argentina
		SizPos(98,67,191,272),		//Venezuela
		SizPos(103,117,183,316),	//Peru
		//Nord America
		SizPos(121,102,78,191),		//America Centrale
		SizPos(116,86,68,121),		//Stati Uniti Occidentali
		SizPos(133,94,129,128),		//Stati Uniti Orientali
		SizPos(78,74,233,75),		//Quebec
		SizPos(61,72,174,84),		//Ontario
		SizPos(88,44,87,84),		//Alberta
		SizPos(255,75,203,10),		//Groenlandia
		SizPos(117,60,5,45),		//Alaska
		SizPos(143,55,82,35)		//Territori dell'Ovest
	};

	const QString img_Stati[num_stati]={
		//Asia
		":/Stati/giappone.png",
		":/Stati/afganistan.png",
		":/Stati/urali.png",
		":/Stati/siberia.png",
		":/Stati/jacuzia.png",
		":/Stati/kamchatka.png",
		":/Stati/cita.png",
		":/Stati/mongolia.png",
		":/Stati/cina.png",
		":/Stati/medio oriente.png",
		":/Stati/india.png",
		":/Stati/siam.png",
		//Oceania
		":/Stati/australia orientale.png",
		":/Stati/australia occidentale.png",
		":/Stati/nuova guinea.png",
		":/Stati/indonesia.png",
		//Africa
		":/Stati/egitto.png",
		":/Stati/africa del nord.png",
		":/Stati/africa del sud.png",
		":/Stati/africa orientale.png",
		":/Stati/congo.png",
		":/Stati/madagascar.png",
		//Europa
		":/Stati/europa meridionale.png",
		":/Stati/europa settentrionale.png",
		":/Stati/europa occidentale.png",
		":/Stati/gran bretagna.png",
		":/Stati/scandinavia.png",
		":/Stati/islanda.png",
		":/Stati/ucraina.png",
		//Sud America
		":/Stati/brasile.png",
		":/Stati/argentina.png",
		":/Stati/venezuela.png",
		":/Stati/peru.png",
		//Nord America
		":/Stati/america centrale.png",
		":/Stati/stati uniti occidentali.png",
		":/Stati/stati uniti orientali.png",
		":/Stati/quebec.png",
		":/Stati/ontario.png",
		":/Stati/alberta.png",
		":/Stati/groenlandia.png",
		":/Stati/alaska.png",
		":/Stati/territori ovest.png"
	};
	const QString img_Stati_select[num_stati]={
		//Asia
		":/Stati/giappone select.png",
		":/Stati/afganistan select.png",
		":/Stati/urali select.png",
		":/Stati/siberia select.png",
		":/Stati/jacuzia select.png",
		":/Stati/kamchatka select.png",
		":/Stati/cita select.png",
		":/Stati/mongolia select.png",
		":/Stati/cina select.png",
		":/Stati/medio oriente select.png",
		":/Stati/india select.png",
		":/Stati/siam select.png",
		//Oceania
		":/Stati/australia orientale select.png",
		":/Stati/australia occidentale select.png",
		":/Stati/nuova guinea select.png",
		":/Stati/indonesia select.png",
		//Africa
		":/Stati/egitto select.png",
		":/Stati/africa del nord select.png",
		":/Stati/africa del sud select.png",
		":/Stati/africa orientale select.png",
		":/Stati/congo select.png",
		":/Stati/madagascar select.png",
		//Europa
		":/Stati/europa meridionale select.png",
		":/Stati/europa settentrionale select.png",
		":/Stati/europa occidentale select.png",
		":/Stati/gran bretagna select.png",
		":/Stati/scandinavia select.png",
		":/Stati/islanda select.png",
		":/Stati/ucraina select.png",
		//Sud America
		":/Stati/brasile select.png",
		":/Stati/argentina select.png",
		":/Stati/venezuela select.png",
		":/Stati/peru select.png",
		//Nord America
		":/Stati/america centrale select.png",
		":/Stati/stati uniti occidentali select.png",
		":/Stati/stati uniti orientali select.png",
		":/Stati/quebec select.png",
		":/Stati/ontario select.png",
		":/Stati/alberta select.png",
		":/Stati/groenlandia select.png",
		":/Stati/alaska select.png",
		":/Stati/territori ovest select.png"
	};

	const QColor Colori_Nazioni[num_stati]={
		//Asia
		QColor(0,166,81,255),
		QColor(163,212,156,255),
		QColor(171,160,0,255),
		QColor(57,181,74,255),
		QColor(172,212,115,255),
		QColor(130,123,0,255),
		QColor(0,89,82,255),
		QColor(60,184,120,255),
		QColor(0,88,38,255),
		QColor(64,102,24,255),
		QColor(0,166,81,255),
		QColor(89,133,39,255),
		//Oceania
		QColor(238,20,91,255),
		QColor(237,0,140,255),
		QColor(241,110,170,255),
		QColor(229,72,123,255),
		//Africa
		QColor(140,98,57,255),
		QColor(198,156,109,255),
		QColor(96,57,19,255),
		QColor(166,124,82,255),
		QColor(117,76,36,255),
		QColor(198,156,109,255),
		//Europa
		QColor(55,95,247,255),
		QColor(125,167,217,255),
		QColor(0,74,128,255),
		QColor(109,208,247,255),
		QColor(0,91,127,255),
		QColor(46,49,146,255),
		QColor(0,84,166,255),
		//Sud America
		QColor(163,212,156,255),
		QColor(89,133,39,255),
		QColor(124,197,118,255),
		QColor(0,114,54,255),
		//Nord America
		QColor(249,199,57,255),
		QColor(248,148,29,255),
		QColor(251,175,93,255),
		QColor(249,212,130,255),
		QColor(248,148,75,255),
		QColor(249,199,57,255),
		QColor(248,148,29,255),
		QColor(249,184,57,255),
		QColor(253,198,137,255),
	};
	const int Numero_Obbiettivi=13;
	const QString TestoObbiettivi[Numero_Obbiettivi]={
		"Devi conquistare 18 territori ed occupare ciascuno di essi con almeno due armate",
		"Conquista Nord America e Oceania",
		"Conquista Nord America e Africa",
		"Conquista Asia e Africa",
		"Conquista Asia e Sud America",
		"Conquista Europa, Sud America pi� un terzo continente di tua scelta",
		"Conquista Europa Oceania pi� un terzo continente di tua scelta",
		"Devi distruggere le armate Gialle. Se sei tu stesso o il giocatore proprietario � eliminato da un altro giocatore il tuo obiettivo diventa: conquista 24 territori",
		"Devi distruggere le armate Blu. Se sei tu stesso o il giocatore proprietario � eliminato da un altro giocatore il tuo obiettivo diventa: conquista 24 territori",
		"Devi distruggere le armate Rosse. Se sei tu stesso o il giocatore proprietario � eliminato da un altro giocatore il tuo obiettivo diventa: conquista 24 territori",
		"Devi distruggere le armate Nere. Se sei tu stesso o il giocatore proprietario � eliminato da un altro giocatore il tuo obiettivo diventa: conquista 24 territori",
		"Devi distruggere le armate Viola. Se sei tu stesso o il giocatore proprietario � eliminato da un altro giocatore il tuo obiettivo diventa: conquista 24 territori",
		"Devi distruggere le armate Verde. Se sei tu stesso o il giocatore proprietario � eliminato da un altro giocatore il tuo obiettivo diventa: conquista 24 territori"
	};
	const int Cannone=0;
	const int Fante=1;
	const int Cavaliere=2;
	const int Compagini [num_stati]={
		//Asia
		Fante,
		Fante,
		Cavaliere,
		Cannone,
		Cavaliere,
		Cavaliere,
		Fante,
		Cannone,
		Cavaliere,
		Cannone,
		Fante,
		Cannone,
		//Oceania
		Fante,
		Cannone,
		Cavaliere,
		Cavaliere,
		//Africa
		Fante,
		Fante,
		Cannone,
		Cannone,
		Cavaliere,
		Fante,
		//Europa
		Cavaliere,
		Cavaliere,
		Fante,
		Cavaliere,
		Cannone,
		Fante,
		Cannone,
		//Sud America
		Cannone,
		Fante,
		Cannone,
		Cavaliere,
		//Nord America
		Cavaliere,
		Fante,
		Cannone,
		Cannone,
		Cavaliere,
		Fante,
		Cavaliere,
		Fante,
		Cannone
	};
	
}

namespace Giocatori{
	const int Max_Giocatori=6;
	const int Giallo=0;
	const int Blu=1;
	const int Rosso=2;
	const int Nero=3;
	const int Viola=4;
	const int Verde=5;
	const QColor Colori[Max_Giocatori]={
		QColor(255,242,0,255), //Giallo
		QColor(0,84,166,255), //Blu
		QColor(237,28,36), //Rosso
		QColor(0,0,0,255), //Nero
		QColor(236,0,140), //Viola
		QColor(0,166,81,255) //Verde
	};

	const QString PathToHttpServer("http://oratoriomomo.org/Risiqo");
	const int MinButtonWidth(170);
}

class Continente{
	public:
		//Funzioni di Riconoscimento
		static bool isAsia(const int& stato){return (stato>=0 && stato<=11);}
		static bool isOceania(const int& stato){return (stato>=12 && stato<=15);}
		static bool isAfrica(const int& stato){return (stato>=16 && stato<=21);}
		static bool isEuropa(const int& stato){return (stato>=22 && stato<=28);}
		static bool isSudAmerica(const int& stato){return (stato>=29 && stato<=32);}
		static bool isNordAmerica(const int& stato){return (stato>=33 && stato<=41);}
		static QString Regole(){
			QFile file(":/Generale/Regole.txt");
			QString regole("");
			if(file.open(QIODevice::ReadOnly)) {
				QTextStream in(&file);
				while(!in.atEnd()) {
					regole.append(in.readLine());        	
				}
			}
			file.close();
			return regole;
		}
};

namespace CSS{
	const QString MainWindow_CentralCSS(
		"#centralWidget{"
			"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
			"stop: 0 #a6a6a6, stop: 0.08 #7f7f7f,"
			"stop: 0.39999 #717171, stop: 0.4 #626262,"
			"stop: 0.9 #4c4c4c, stop: 1 #333333);"
		"}"
	);

	const QString MainWindow_BottomFrameCSS(
		"#BottomFrameCover{"
			"background-color: rgb(187,171,123);"
			"font: bold;"
			"font-size: 60px;"
			"color: black;"
			"border: 3px inset #333;"
			"border-top-left-radius: 12px;"
			"border-top-right-radius: 12px;"
		"}"

		"#BottomFrame {"
			"border: 3px inset #333;"
			"border-top-left-radius: 12px;"
			"border-top-right-radius: 12px;"
			"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
			"stop: 0 #a6a6a6, stop: 0.08 #7f7f7f,"
			"stop: 0.39999 #717171, stop: 0.4 #626262,"
			"stop: 0.9 #4c4c4c, stop: 1 #333333);"
		"}"

		"#BottomFrame QPushButton {"
			"color: #333;"
			"border: 2px solid #555;"
			"border-radius: 11px;"
			"padding: 5px;"
			"background: qradialgradient(cx: 0.3, cy: -0.4,"
			"fx: 0.3, fy: -0.4,"
			"radius: 1.35, stop: 0 #fff, stop: 1 #888);"
		"}"

		"#BottomFrame QPushButton:hover {"
			"background: qradialgradient(cx: 0.3, cy: -0.4,"
			"fx: 0.3, fy: -0.4,"
			"radius: 1.35, stop: 0 #fff, stop: 1 #bbb);"
		"}"

		"#BottomFrame QPushButton:pressed {"
			"background: qradialgradient(cx: 0.4, cy: -0.1,"
			"fx: 0.4, fy: -0.1,"
			"radius: 1.35, stop: 0 #fff, stop: 1 #ddd);"
		"}"

		"#Log{"
			"border-width: 1px;"
			"border-color: rgb(0, 0, 0);"
			"border-style: inset;"
			"background-color: rgba(255, 255, 255, 255);"
			"border-radius: 12px;"
			"selection-background-color: ltblue; "
			"padding: 7px;"
		"}"
	);
	const QString MainWindow_TopFrame(
		"QRisiko #Sfondo{"
			"border: 3px inset #333;"
			"border-bottom-left-radius: 12px;"
			"border-bottom-right-radius: 12px;"
		"}"

		"TopMenu #Sfondo{"
			"border: 3px inset #333;"
			"border-radius: 12px;"
			"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
			"stop: 0 #a6a6a6, stop: 0.08 #7f7f7f,"
			"stop: 0.39999 #717171, stop: 0.4 #626262,"
			"stop: 0.9 #4c4c4c, stop: 1 #333333);"
		"}"

		"MenuPrincipale #Sfondo{"
			"border: 3px inset #333;"
			"border-radius: 12px;"
			"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
			"stop: 0 #a6a6a6, stop: 0.08 #7f7f7f,"
			"stop: 0.39999 #717171, stop: 0.4 #626262,"
			"stop: 0.9 #4c4c4c, stop: 1 #333333);"
		"}"

		"#MenuPrincipale QPushButton {"
			"color: #222;"
			"font: bold;"
			"border: 2px solid #555;"
			"border-radius: 11px;"
			"padding: 5px;"
			"background: qradialgradient(cx: 0.3, cy: -0.4,"
			"fx: 0.3, fy: -0.4,"
			"radius: 1.35, stop: 0 #fff, stop: 1 #888);"
		"}"

		"#MenuPrincipale QPushButton:hover {"
			"background: qradialgradient(cx: 0.3, cy: -0.4,"
			"fx: 0.3, fy: -0.4,"
			"radius: 1.35, stop: 0 #fff, stop: 1 #bbb);"
		"}"

		"#MenuPrincipale QPushButton:pressed {"
			"background:"
			" qradialgradient(cx: 0.4, cy: -0.1,"
			"fx: 0.4, fy: -0.1,"
			"radius: 1.35, stop: 0 #fff, stop: 1 #ddd);"
		"}"

		

		"ServerSelector #Sfondo {"
			"border: 3px inset #333;"
			"border-radius: 12px;"
			"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
			"stop: 0 #a6a6a6, stop: 0.08 #7f7f7f,"
			"stop: 0.39999 #717171, stop: 0.4 #626262,"
			"stop: 0.9 #4c4c4c, stop: 1 #333333);"
		"}"
		"ServerSelector #label{"
			"font: bold;"
		"}"

		"ServerSelector #TabellaServer{"
			"border-width: 1px;"
			"border-color: rgb(0, 0, 0);"
			"border-style: inset;"
			"border-radius: 12px;"
			"selection-background-color: ltblue;"
			"padding: 7px;"
		"}"

		"ServerSelector QPushButton {"
		"color: #222;"
		"font: bold;"
		"border: 2px solid #555;"
		"border-radius: 11px;"
		"padding: 5px;"
		"background: qradialgradient(cx: 0.3, cy: -0.4,"
		"fx: 0.3, fy: -0.4,"
		"radius: 1.35, stop: 0 #fff, stop: 1 #888);"
		"}"

		"ServerSelector QPushButton:hover {"
		"background: qradialgradient(cx: 0.3, cy: -0.4,"
		"fx: 0.3, fy: -0.4,"
		"radius: 1.35, stop: 0 #fff, stop: 1 #bbb);"
		"}"

		"ServerSelector QPushButton:pressed {"
		"background:"
		" qradialgradient(cx: 0.4, cy: -0.1,"
		"fx: 0.4, fy: -0.1,"
		"radius: 1.35, stop: 0 #fff, stop: 1 #ddd);"
		"}"

		"TopMenu QPushButton {"
			"color: #222;"
			"font: bold;"
			"border: 2px solid #555;"
			"border-radius: 11px;"
			"padding: 5px;"
			"background: qradialgradient(cx: 0.3, cy: -0.4,"
			"fx: 0.3, fy: -0.4,"
			"radius: 1.35, stop: 0 #fff, stop: 1 #888);"
		"}"

		"TopMenu QPushButton:hover {"
			"background: qradialgradient(cx: 0.3, cy: -0.4,"
			"fx: 0.3, fy: -0.4,"
			"radius: 1.35, stop: 0 #fff, stop: 1 #bbb);"
		"}"

		"TopMenu QPushButton:pressed {"
			"background:"
			" qradialgradient(cx: 0.4, cy: -0.1,"
			"fx: 0.4, fy: -0.1,"
			"radius: 1.35, stop: 0 #fff, stop: 1 #ddd);"
		"}"

		"#Regolamento QTextBrowser {"
			"border-width: 1px;"
			"border-color: rgb(0, 0, 0);"
			"border-style: inset;"
			"background-color: rgba(255, 255, 255, 255);"
			"border-radius: 12px;"
			"selection-background-color: ltblue; "
			"padding: 7px;"
		"}"

		"#Regolamento QPushButton {"
			"color: #222;"
			"font: bold;"
			"border: 2px solid #555;"
			"border-radius: 11px;"
			"padding: 5px;"
			"background: qradialgradient(cx: 0.3, cy: -0.4,"
			"fx: 0.3, fy: -0.4,"
			"radius: 1.35, stop: 0 #fff, stop: 1 #888);"
		"}"

		"#Regolamento QPushButton:hover {"
			"background: qradialgradient(cx: 0.3, cy: -0.4,"
			"fx: 0.3, fy: -0.4,"
			"radius: 1.35, stop: 0 #fff, stop: 1 #bbb);"
		"}"

		"#Regolamento QPushButton:pressed {"
			"background:"
			" qradialgradient(cx: 0.4, cy: -0.1,"
			"fx: 0.4, fy: -0.1,"
			"radius: 1.35, stop: 0 #fff, stop: 1 #ddd);"
		"}"

	);
}

namespace Comunicazioni{
	const unsigned int DefaultTCPPort=7676;
	enum{
		RichiediInfo=0
	};
}

/*Elenco di posizioni e dimensioni degli stati in ordine alfabetico

const SizPos sp_afganistan(114,103,618,79);
const SizPos sp_africa_del_nord(146,143,410,173);
const SizPos sp_africa_del_sud(103,117,511,344);
const SizPos sp_africa_orientale(104,140,546,230);
const SizPos sp_alaska(117,60,5,45);
const SizPos sp_alberta(88,44,87,83);
const SizPos sp_america_centrale(121,102,78,191);
const SizPos sp_argentina(68,149,226,392);
const SizPos sp_australia_occidentale(107,120,855,377);
const SizPos sp_australia_orientale(78,110,920,364);
const SizPos sp_brasile(138,156,211,300);
const SizPos sp_cina(177,124,713,126);
const SizPos sp_cita(768,52,725,81);
const SizPos sp_congo(80,99,501,277);
const SizPos sp_egitto(91,55,503,189);
const SizPos sp_europa_meridionale(76,58,492,124);
const SizPos sp_europa_occidentale(59,60,441,119);
const SizPos sp_europa_settentrionale(67,41,482,94);
const SizPos sp_giappone(41,92,899,107);
const SizPos sp_gran_bretagna(37,33,444,90);
const SizPos sp_groenlandia(255,75,203,10);
const SizPos sp_india(130,132,674,168);
const SizPos sp_indonesia(112,116,806,248);
const SizPos sp_islanda(39,20,409,71);
const SizPos sp_jacuzia(157,62,760,37);
const SizPos sp_kamchatka(117,103,866,50);
const SizPos sp_madagascar(28,55,619,370);
const SizPos sp_medio_oriente(131,118,558,153);
const SizPos sp_mongolia(157,76,746,109);
const SizPos sp_nuova_guinea(77,42,931,323);
const SizPos sp_ontario(61,72,174,83);
const SizPos sp_peru(103,117,183,316);
const SizPos sp_quebec(78,74,232,75);
const SizPos sp_scandinavia(74,60,491,46);
const SizPos sp_siam(65,110,789,207);
const SizPos sp_siberia(118,110,664,25);
const SizPos sp_stati_uniti_occidentali(116,86,68,121);
const SizPos sp_stati_uniti_orientali(133,94,129,128);
const SizPos sp_territori_del_nord_ovest(143,55,82,35);
const SizPos sp_ucraina(126,119,537,50);
const SizPos sp_urali(89,104,648,41);
const SizPos sp_venezuela(98,67,191,272);*/

#endif