QRisiko è un progetto con lo scopo di creare una versione digitale del celebre gioco da tavolo Risiko nella sua versione Italiana.
Il codice contenuto in questo progetto in forma sorgete o binaria è sottoposto a licenza GNU General Public License versione 3.0

Descrizione Contenuti:

Finestra Principale:
	Descrizione Sorgenti:
		MainWindow -> Finestra Principale che per il momento mostra la mappa di gioco (Widget Mappa), la chat (Chat Widget) e un pulsante di chiusura
	Molto rimane ancora da implementare in questa sezione
	
Chat Widget:
	Descrizione Sorgenti:
		Chatconst.h -> Contiene le costanti che definiscono il path alle immagini degli smiles, i codici degli smiles e il colore che usa il server per comunicare in chat
		SmileButton -> Classe che eridita da QPushButton e emette il segnale click con un identificativo di quale smile è stato premuto
		Smile Selector -> Widget per la selezione dello smile da inserire
		Chat Server -> classe che eredita da QTCPServer utilizzata per impostare un server di trasmissione per la chat a più client
		Chat Thread -> classe che eredita da QThread che gestisce la comunicazione del server con ogni client
		Client Soket -> Interfaccia implementata in ogni ChatThread per comunicare con i rispettivi client
		Chat.ui -> Interfaccia grafica di base per il widget chat
		ChatWidget -> Implementazione delle funzioni dell'interfaccia grafica
	Patches Welcome:
		Chat Widget.cpp -> ChatWidget::closeEvent rimozione di QTest::qwait(250); e sostituzione con sistema di comunicazione tra server e client che si assicuri che il messaggio di abbandono della conversazione sia stato ricevuto per intero dal server prima di chiudere la connessione

Widget Mappa:
	Descrizione Sorgenti:
		Immagine Cliccabile -> classe che eredita da QLabel usata per mostrare gli stati, registra anche quale stato rappresenta
		qrisiko -> widget che rappresenta la mappa principale, è composto dallo sfondo e da 41 stati cliccabili
	Molto rimane ancora da implementare in questa sezione