#include "MenuPause.h"
#include "Jogo.h"

MenuPause::MenuPause(unsigned int comprimento, unsigned int altura, int tamanho, Jogo* jg):
	Menu(comprimento, altura, tamanho, jg)
{
	Inicializa();
}

MenuPause::~MenuPause()
{
}

void MenuPause::setEstadoAtual(int estadoatual)
{
	EstadoAtual = estadoatual;
}

int MenuPause::getEstadoAtual()
{
	return EstadoAtual;
}

void MenuPause::LoopMenu(sf::Event* evento)
{
	if (evento->type == sf::Event::KeyPressed)
	{
		if (evento->key.code == sf::Keyboard::Key::W)
			moverCima();
		if (evento->key.code == sf::Keyboard::Key::S)
			moverBaixo();
		if (evento->key.code == sf::Keyboard::Key::Enter)
		{
			switch (Indice)
			{
			case 0:
				jogo->setEstado(EstadoAtual);
				break;
			case 1:
				jogo->Salvar();
				break;
			case 2:

				jogo->getMenuColocacao().setEstadoAnterior(6);
				jogo->getMenuColocacao().setEditavel(true);
				jogo->setEstado(3);
				break;
			case 3:
				jogo->setEstado(0);
				break;
			case 4:
				Janela->close();
				break;
			}
		}
	}
}

void MenuPause::Inicializa()
{
	menu = new sf::Text[Tamanho];
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setCharacterSize(24);
	menu[0].setString("Retomar");
	menu[0].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 150));
	menu[0].setFont(Fonte);

	menu[1].setFillColor(sf::Color::Green);
	menu[1].setCharacterSize(24);
	menu[1].setString("Salvar jogo");
	menu[1].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 250));
	menu[1].setFont(Fonte);

	menu[2].setFillColor(sf::Color::Green);
	menu[2].setCharacterSize(24);
	menu[2].setString("Salvar pontua��o");
	menu[2].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 350));
	menu[2].setFont(Fonte);

	menu[3].setFillColor(sf::Color::Green);
	menu[3].setCharacterSize(24);
	menu[3].setString("Voltar ao Menu Principal");
	menu[3].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 450));
	menu[3].setFont(Fonte);	

	menu[4].setFillColor(sf::Color::Green);
	menu[4].setCharacterSize(24);
	menu[4].setString("Sair do Jogo");
	menu[4].setPosition(sf::Vector2f(COMPRIMENTO_RESOLUCAO / 4, 550));
	menu[4].setFont(Fonte);


}
