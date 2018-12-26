#include <iostream>

#include <SFML/Graphics.hpp>

//sudo apt-get install libsfml-dev
//g++ -o ../bin/game game.cpp -lsfml-graphics -lsfml-system -lsfml-window&&../bin/game
int main()
{
    sf::RenderWindow window(sf::VideoMode(480,480),"SFML Tutorial",sf::Style::Close | 
        sf::Style::Titlebar);

    sf::RectangleShape caseBlanche(sf::Vector2f(60,60));
    sf::RectangleShape caseNoire(sf::Vector2f(60,60));
    caseNoire.setFillColor(sf::Color(112,72,60));
    caseBlanche.setFillColor(sf::Color::White);

//DEBUT Creation du damier

    float posX;
    float posY=0.0f;
    for (unsigned j=1;j<=8;j+=2)
    {
        posX=0.0f;
        for(unsigned i=1;i<=4;++i)
        {
            caseBlanche.setPosition(posX,posY);
            window.draw(caseBlanche);
            posX+=60.0f;
            caseNoire.setPosition(posX,posY);
            window.draw(caseNoire);
            posX+=60.0f;
        }
        posY+=120.0f;
    }
    
    posY=60.0f;
    for (unsigned j=2;j<=8;j+=2)
    {
        posX=0.0f;
        for(unsigned i=1;i<=4;++i)
        {
            caseNoire.setPosition(posX,posY);
            window.draw(caseNoire);
            posX+=60.0f;
            caseBlanche.setPosition(posX,posY);
            window.draw(caseBlanche);
            posX+=60.0f;
        }
        posY+=120.0f;
    }

//FIN Creation du damier

//DEBUT Placement des pieces

//pions noirs
sf::Image imgPionNoir;
imgPionNoir.loadFromFile("img/pionNoir.png");
sf::Texture txPionNoir;
txPionNoir.loadFromImage(imgPionNoir);
sf::Sprite spPionNoir;
spPionNoir.setTexture(txPionNoir,true);
posX=0.0f;
for(unsigned i=1;i<=8;++i)
{
    spPionNoir.setPosition(posX,60.0f);
    window.draw(spPionNoir);
    posX+=60.0f;
}

//pions blancs
sf::Image imgPionBlanc;
imgPionBlanc.loadFromFile("img/pionBlanc.png");
sf::Texture txPionBlanc;
txPionBlanc.loadFromImage(imgPionBlanc);
sf::Sprite spPionBlanc;
spPionBlanc.setTexture(txPionBlanc,true);
posX=0.0f;
for(unsigned i=1;i<=8;++i)
{
    spPionBlanc.setPosition(posX,360.0f);
    window.draw(spPionBlanc);
    posX+=60.0f;
}

//tours blanc
sf::Image imgTourBlanc;
imgTourBlanc.loadFromFile("img/TourBlanc.png");
sf::Texture txTourBlanc;
txTourBlanc.loadFromImage(imgTourBlanc);
sf::Sprite spTourBlanc;
spTourBlanc.setTexture(txTourBlanc,true);
spTourBlanc.setPosition(0.0f,420.0f);
window.draw(spTourBlanc);
spTourBlanc.setPosition(420.0f,420.0f);
window.draw(spTourBlanc);

//cavaliers blanc
sf::Image imgCavalierBlanc;
imgCavalierBlanc.loadFromFile("img/CavalierBlanc.png");
sf::Texture txCavalierBlanc;
txCavalierBlanc.loadFromImage(imgCavalierBlanc);
sf::Sprite spCavalierBlanc;
spCavalierBlanc.setTexture(txCavalierBlanc,true);
spCavalierBlanc.setPosition(60.0f,420.0f);
window.draw(spCavalierBlanc);
spCavalierBlanc.setPosition(360.0f,420.0f);
window.draw(spCavalierBlanc);

//fous blanc
sf::Image imgFouBlanc;
imgFouBlanc.loadFromFile("img/FouBlanc.png");
sf::Texture txFouBlanc;
txFouBlanc.loadFromImage(imgFouBlanc);
sf::Sprite spFouBlanc;
spFouBlanc.setTexture(txFouBlanc,true);
spFouBlanc.setPosition(120.0f,420.0f);
window.draw(spFouBlanc);
spFouBlanc.setPosition(300.0f,420.0f);
window.draw(spFouBlanc);

//reine blanc
sf::Image imgReineBlanc;
imgReineBlanc.loadFromFile("img/ReineBlanc.png");
sf::Texture txReineBlanc;
txReineBlanc.loadFromImage(imgReineBlanc);
sf::Sprite spReineBlanc;
spReineBlanc.setTexture(txReineBlanc,true);
spReineBlanc.setPosition(180.0f,420.0f);
window.draw(spReineBlanc);

//roi blanc
sf::Image imgRoiBlanc;
imgRoiBlanc.loadFromFile("img/RoiBlanc.png");
sf::Texture txRoiBlanc;
txRoiBlanc.loadFromImage(imgRoiBlanc);
sf::Sprite spRoiBlanc;
spRoiBlanc.setTexture(txRoiBlanc,true);
spRoiBlanc.setPosition(240.0f,420.0f);
window.draw(spRoiBlanc);

//tours Noir
sf::Image imgTourNoir;
imgTourNoir.loadFromFile("img/TourNoir.png");
sf::Texture txTourNoir;
txTourNoir.loadFromImage(imgTourNoir);
sf::Sprite spTourNoir;
spTourNoir.setTexture(txTourNoir,true);
spTourNoir.setPosition(0.0f,0.0f);
window.draw(spTourNoir);
spTourNoir.setPosition(420.0f,0.0f);
window.draw(spTourNoir);

//cavaliers Noir
sf::Image imgCavalierNoir;
imgCavalierNoir.loadFromFile("img/CavalierNoir.png");
sf::Texture txCavalierNoir;
txCavalierNoir.loadFromImage(imgCavalierNoir);
sf::Sprite spCavalierNoir;
spCavalierNoir.setTexture(txCavalierNoir,true);
spCavalierNoir.setPosition(60.0f,0.0f);
window.draw(spCavalierNoir);
spCavalierNoir.setPosition(360.0f,0.0f);
window.draw(spCavalierNoir);

//fous Noir
sf::Image imgFouNoir;
imgFouNoir.loadFromFile("img/FouNoir.png");
sf::Texture txFouNoir;
txFouNoir.loadFromImage(imgFouNoir);
sf::Sprite spFouNoir;
spFouNoir.setTexture(txFouNoir,true);
spFouNoir.setPosition(120.0f,0.0f);
window.draw(spFouNoir);
spFouNoir.setPosition(300.0f,0.0f);
window.draw(spFouNoir);

//reine Noir
sf::Image imgReineNoir;
imgReineNoir.loadFromFile("img/ReineNoir.png");
sf::Texture txReineNoir;
txReineNoir.loadFromImage(imgReineNoir);
sf::Sprite spReineNoir;
spReineNoir.setTexture(txReineNoir,true);
spReineNoir.setPosition(180.0f,0.0f);
window.draw(spReineNoir);

//roi Noir
sf::Image imgRoiNoir;
imgRoiNoir.loadFromFile("img/RoiNoir.png");
sf::Texture txRoiNoir;
txRoiNoir.loadFromImage(imgRoiNoir);
sf::Sprite spRoiNoir;
spRoiNoir.setTexture(txRoiNoir,true);
spRoiNoir.setPosition(240.0f,0.0f);
window.draw(spRoiNoir);

//FIN Placement des pieces



    while(window.isOpen())
    {
        sf::Event evt;
        while(window.pollEvent(evt))
        {
            if(evt.type==sf::Event::Closed)
                window.close();
        }
        window.display();
    }
}
