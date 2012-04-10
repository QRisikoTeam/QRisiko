#ifndef COSTANTI_NAZIONI_H
#define COSTANTI_NAZIONI_H
#include <qpoint.h>
#include <QSize>
#include <QString>
#include <QRect>

class SizPos{
	QSize sz;
	QPoint pt;
public:
	SizPos(int w, int a, int x, int y): sz(w,a), pt(x,y){}
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
	//Funzioni di Riconoscimento
	/*bool isAsia(int stato){return (stato>=0 && stato<=11);}
	bool isOceania(int stato){return (stato>=12 && stato<=15);}
	bool isAfrica(int stato){return (stato>=16 && stato<=21);}
	bool isEuropa(int stato){return (stato>=22 && stato<=28);}
	bool isSudAmerica(int stato){return (stato>=29 && stato<=32);}
	bool isNordAmerica(int stato){return (stato>=33 && stato<=41);}*/
	const QString Nomi_Stati[ID_Stati::num_stati]={
		//Asia
		"giappone",
		"afganistan",
		"urali",
		"siberia",
		"jacuzia",
		"kamchatka",
		"cita",
		"mongolia",
		"cina",
		"medio oriente",
		"india",
		"siam",
		//Oceania
		"australia orientale",
		"australia occidentale",
		"nuova guinea",
		"indonesia",
		//Africa
		"egitto",
		"africa del nord",
		"africa del sud",
		"africa orientale",
		"congo",
		"madagascar",
		//Europa
		"europa meridionale",
		"europa settentrionale",
		"europa occidentale",
		"gran bretagna",
		"scandinavia",
		"islanda",
		"ucraina",
		//Sud America
		"brasile",
		"argentina",
		"venezuela",
		"peru.png",
		//Nord America
		"america centrale",
		"stati uniti occidentali",
		"stati uniti orientali",
		"quebec",
		"ontario",
		"alberta",
		"groenlandia",
		"alaska",
		"territori dell'ovest"
	};
	const SizPos sp_mappa(1024,574,0,0);
	const SizPos PosData_Stati[ID_Stati::num_stati]={
		//Asia
		SizPos(41,92,899,107),
		SizPos(114,103,618,79),
		SizPos(89,104,648,41),
		SizPos(118,110,664,25),
		SizPos(157,62,760,37),
		SizPos(117,103,866,50),
		SizPos(168,52,725,81),
		SizPos(157,76,746,109),
		SizPos(177,124,713,126),
		SizPos(131,118,558,153),
		SizPos(130,132,674,168),
		SizPos(65,110,790,207),
		//Oceania
		SizPos(78,110,920,364),
		SizPos(107,120,855,377),
		SizPos(77,42,931,323),
		SizPos(112,116,806,248),
		//Africa
		SizPos(91,55,503,189),
		SizPos(146,143,410,173),
		SizPos(103,117,511,344),
		SizPos(104,140,546,230),
		SizPos(80,99,501,277),
		SizPos(28,55,619,370),
		//Europa
		SizPos(76,58,492,124),
		SizPos(67,41,482,94),//Europa Settentrionale
		SizPos(59,60,441,119),
		SizPos(37,33,444,90),
		SizPos(74,60,491,46),
		SizPos(39,20,409,71),
		SizPos(126,119,537,50),
		//Sud America
		SizPos(138,156,211,300),
		SizPos(68,149,226,392),
		SizPos(98,67,191,272),
		SizPos(103,117,183,316),
		//Nord America
		SizPos(121,102,78,191),
		SizPos(116,86,68,121),
		SizPos(133,94,130,128),
		SizPos(78,74,233,75),
		SizPos(61,72,174,83),
		SizPos(88,44,87,83),
		SizPos(255,75,203,10),
		SizPos(117,60,5,45),
		SizPos(143,55,82,35)
	};
	const QString img_Stati[ID_Stati::num_stati]={
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
		":/Stati/territori dell'ovest.png"
	};
	const QColor Colori_Nazioni[ID_Stati::num_stati]={
		//Asia
		QColor(0,166,81,255),
		QColor(163,212,156,255),
		QColor(0,88,38,255),
		QColor(57,181,74,255),
		QColor(172,212,115,255),
		QColor(130,123,0,255),
		QColor(0,255,0,255),
		QColor(60,184,120,255),
		QColor(0,88,38,255),
		QColor(64,102,24,255),
		QColor(0,166,81,255),
		QColor(89,133,39,255),
		//Oceania
		QColor(238,20,91,255),
		QColor(237,0,140,255),
		QColor(241,110,170,255),
		QColor(255,0,255,255),
		//Africa
		QColor(140,98,57,255),
		QColor(198,156,109,255),
		QColor(96,57,19,255),
		QColor(166,124,82,255),
		QColor(117,76,36,255),
		QColor(198,156,109,255),
		//Europa
		QColor(55,95,247,255),
		QColor(0,255,255,255),
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
}
/*
Elenco di posizioni e dimensioni degli stati in ordine alfabetico
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
const SizPos sp_venezuela(98,67,191,272);
*/

#endif