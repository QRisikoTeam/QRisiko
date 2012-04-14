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