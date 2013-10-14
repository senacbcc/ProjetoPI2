#include "Player.h"
#include "comum.h"
#include "textBox.h"
#include <string.h>

void createDialogs(Dialogs *dialog){
	//Não estou conseguindo quebrar a linha
	strcpy(dialog->menina_texto_1, "Oi tudo bem? Você poderia me ajudar?");
	strcpy(dialog->computador_texto_1, "Que computador velho, será que eu consigo arrumar?");
	strcpy(dialog->menina_texto[0], "Oi tudo bem? Você poderia me ajudar? Estou com um problema");
	strcpy(dialog->menina_texto[1], "na minha máquina de refrigerante, alguma coisa aconteceu");
	strcpy(dialog->menina_texto[2], "e ela não funciona mais.");
}

void TextBoxLoad(ALLEGRO_EVENT *ev, char dialog[])
{
	bool sair = false;
	ALLEGRO_BITMAP *textBox;
	textBox = al_load_bitmap("data/images/textbox.png");
	al_draw_bitmap(textBox, 0, 450, 0);
	al_draw_text(game.fonte_menu, al_map_rgb(0, 0, 0), 15, 472, ALLEGRO_ALIGN_LEFT, dialog);
	while(!sair)
	{
		al_wait_for_event(game.fila_eventos, ev);
		if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			sair = true;
		if(ev->type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev->keyboard.keycode)
			{
			case ALLEGRO_KEY_ENTER:
			case ALLEGRO_KEY_ESCAPE:
				sair = true;
				break;
			}
		}
		al_flip_display();
	}	
}

void TextBoxLoad_matriz(ALLEGRO_EVENT *ev, char *dialog[], int textYPos)
{
	bool sair = false;
	int i = 0;
	//ALLEGRO_BITMAP *textBox;
	//textBox = al_load_bitmap("data/images/textbox.png");
	//al_draw_bitmap(textBox, 0, 450, 0);
	while(!sair)
	{	
		al_draw_text(game.fonte_menu, al_map_rgb(0, 0, 0), 15, textYPos, ALLEGRO_ALIGN_LEFT, dialog);
		al_wait_for_event(game.fila_eventos, ev);
		if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			sair = true;
		if(ev->type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev->keyboard.keycode)
			{
			case ALLEGRO_KEY_ENTER:
			case ALLEGRO_KEY_ESCAPE:
				sair = true;
				break;
			}
		}
		al_flip_display();
	}	
}