#ifndef COSTANTI_NAZIONI_H
#define COSTANTI_NAZIONI_H

namespace ID_Stati{
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
	bool isAsia(int stato){return (stato>=0 && stato<=11)}
	bool isOceania(int stato){return (stato>=12 && stato<=15)}
	bool isAfrica(int stato){return (stato>=16 && stato<=21)}
	bool isEuropa(int stato){return (stato>=22 && stato<=28)}
	bool isSudAmerica(int stato){return (stato>=29 && stato<=32)}
	bool isNordAmerica(int stato){return (stato>=33 && stato<=41)}
}

class SizPos{
	public:
		int larg;
		int alt;
		int x;
		int y;
		int ID;
		SizPos(int w, int a, int px, int py, int iden): larg(w), alt(a), x(px), y(py), iden(ID){}
};

const SizPos sp_mappa(1024,574,0,0,ID_Stati::nullo);
const SizPos sp_afganistan(114,103,618,79,ID_Stati::afganistan);
const SizPos sp_africa_del_nord(146,143,418,173,ID_Stati::africa_del_nord);
const SizPos sp_africa_del_sud(103,117,511,344,ID_Stati::africa_del_sud);
const SizPos sp_africa_orientale(104,140,546,230,ID_Stati::africa_orientale);
const SizPos sp_alaska(117,60,5,45,ID_Stati::alaska);
const SizPos sp_alberta(88,44,87,83,ID_Stati::alberta);
const SizPos sp_america_centrale(121,102,78,191,ID_Stati::america_centrale);
const SizPos sp_argentina(68,149,226,392,ID_Stati::argentina);
const SizPos sp_australia_occidentale(107,120,855,377,ID_Stati::australia_occidentale);
const SizPos sp_australia_orientale(78,110,920,364,ID_Stati::australia_orientale);
const SizPos sp_brasile(138,156,211,300,ID_Stati::brasile);
const SizPos sp_cina(177,124,);
const SizPos sp_cita(768,52,);
const SizPos sp_congo(80,99,);
const SizPos sp_egitto(91,55,);
const SizPos sp_europa_meridionale(76,58,);
const SizPos sp_europa_occidentale(59,60,);
const SizPos sp_europa_settentrionale(67,41,);
const SizPos sp_giappone(41,92,);
const SizPos sp_gran_bretagna(37,33,);
const SizPos sp_groenlandia(255,75,);
const SizPos sp_india(130,132,);
const SizPos sp_indonesia(112,116,);
const SizPos sp_islanda(39,20,);
const SizPos sp_jacuzia(157,62,);
const SizPos sp_kamchatka(117,103,);
const SizPos sp_madagascar(28,55,);
const SizPos sp_medio_oriente(131,118,);
const SizPos sp_mongolia(157,76,);
const SizPos sp_nuova_guinea(77,42,);
const SizPos sp_ontario(61,72,);
const SizPos sp_peru(103,117,);
const SizPos sp_quebec(78,74,);
const SizPos sp_scandinavia(74,60,);
const SizPos sp_siam(65,110,);
const SizPos sp_siberia(118,110,);
const SizPos sp_stati_uniti_occidentali(116,86,);
const SizPos sp_stati_uniti_orientali(133,94,);
const SizPos sp_territori_del_nord_ovest(143,55,);
const SizPos sp_ucraina(126,119,);
const SizPos sp_urali(89,104,);
const SizPos sp_venezuela(98,67,);

#endif