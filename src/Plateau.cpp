#include "Plateau.h"
#include <iostream>//

Piece::Piece()
{
    ;
}

Piece::Piece(CouleurPiece couleur,TypePiece type,std::string imgPath) : couleur(couleur),type(type)
{
    this->setSprite(imgPath);
}

Piece::~Piece()
{
    ;
}

void Piece::setSprite(std::string imgPath)
{
    this->image.loadFromFile(imgPath);
    this->texture.loadFromImage(this->image);
    this->sprite.setTexture(this->texture,true);
}

sf::Sprite* Piece::getSprite()
{
    return &this->sprite;
}

CouleurPiece Piece::getCouleur()const
{
    return this->couleur;
}

TypePiece Piece::getType()const
{
    return this->type;
}

void Piece::setCouleur(CouleurPiece couleur)
{
    this->couleur=couleur;
}

void Piece::setType(TypePiece type)
{
    this->type=type;
}

Case::Case() : sf::RectangleShape(sf::Vector2f(Case::TAILLE,Case::TAILLE)),
    piece(new Piece())
{
    ;
}

Case::~Case()
{
    if(this->piece)
        delete(this->piece);
}

Piece* Case::getPiece()const
{
    return this->piece;
}

Plateau::Plateau(sf::RenderWindow* fenetre) : fenetre(fenetre)
{
    for(unsigned short i=0;i<this->cases.size();++i)
    {
        for (auto & ptr: this->cases.at(i)) 
            ptr = nullptr;
    }

    this->dessinerDamier();
    this->dessinerPieces();
}

Plateau::~Plateau()
{
    if(this->fenetre)
        delete(this->fenetre);
    for(unsigned short i=0;i<this->cases.size();++i)
    {
        for(unsigned short j=0;j<this->cases.size();++j)
        {
            if(this->cases.at(i).at(j))
                delete(this->cases.at(i).at(j));
        }
    }
}

std::array<std::array<Case*,Plateau::DIMENSION>,Plateau::DIMENSION> Plateau::getCases()const
{
    return this->cases;
}

void Plateau::dessinerDamier()
{
    Case caseBlanc;
    Case caseNoir;
    float posX;
    float posY=0.0f;
    unsigned short i;
    unsigned short j;

    caseBlanc.setFillColor(this->COULEUR_BLANC);
    caseNoir.setFillColor(this->COULEUR_MARRON);

    for (j=1;j<=this->cases.size();j+=2)
    {
        posX=0.0f;
        for(i=1;i<=4;++i)
        {
            caseBlanc.setPosition(posX,posY);
            this->fenetre->draw(caseBlanc);
            posX+=Case::TAILLE;
            caseNoir.setPosition(posX,posY);
            this->fenetre->draw(caseNoir);
            posX+=Case::TAILLE;
        }
        posY+=2*Case::TAILLE;
    }
    
    posY=Case::TAILLE;
    for (j=2;j<=this->cases.size();j+=2)
    {
        posX=0.0f;
        for(i=1;i<=4;++i)
        {
            caseNoir.setPosition(posX,posY);
            this->fenetre->draw(caseNoir);
            posX+=Case::TAILLE;
            caseBlanc.setPosition(posX,posY);
            this->fenetre->draw(caseBlanc);
            posX+=Case::TAILLE;
        }
        posY+=2*Case::TAILLE;
    }
}

void Plateau::dessinerPieces()
{
   this->dessinerPions();
   this->dessinerTours();
   this->dessinerCavaliers();
   this->dessinerFous();
   this->dessinerReines();
   this->dessinerRois();
}

void Plateau::dessinerPions()
{
    float posX=0.0f;
    unsigned short i;

    for(i=0;i<this->cases.size();++i)
    {
        this->cases.at(i).at(1)=new Case();
        this->cases.at(i).at(1)->getPiece()->setCouleur(CouleurPiece::Noir);
        this->cases.at(i).at(1)->getPiece()->setType(TypePiece::Pion);
        this->cases.at(i).at(1)->getPiece()->setSprite(PION_NOIR_IMG);
        this->cases.at(i).at(1)->getPiece()->getSprite()->setPosition(posX,Case::TAILLE);
        this->fenetre->draw(*this->cases.at(i).at(1)->getPiece()->getSprite());
        posX+=Case::TAILLE;
    }

    posX=0.0f;
    for(i=0;i<this->cases.size();++i)
    {
        this->cases.at(i).at(1)=new Case();
        this->cases.at(i).at(1)->getPiece()->setCouleur(CouleurPiece::Blanc);
        this->cases.at(i).at(1)->getPiece()->setType(TypePiece::Pion);
        this->cases.at(i).at(1)->getPiece()->setSprite(PION_BLANC_IMG);
        this->cases.at(i).at(1)->getPiece()->getSprite()->setPosition(posX,6*Case::TAILLE);
        this->fenetre->draw(*this->cases.at(i).at(1)->getPiece()->getSprite());
        posX+=Case::TAILLE;
    }
}

void Plateau::dessinerFous()
{
    this->cases.at(2).at(0)=new Case();
    this->cases.at(2).at(0)->getPiece()->setCouleur(CouleurPiece::Noir);
    this->cases.at(2).at(0)->getPiece()->setType(TypePiece::Fou);
    this->cases.at(2).at(0)->getPiece()->setSprite(FOU_NOIR_IMG);
    this->cases.at(2).at(0)->getPiece()->getSprite()->setPosition(2*Case::TAILLE,0*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(2).at(0)->getPiece()->getSprite());

    this->cases.at(5).at(0)=new Case();
    this->cases.at(5).at(0)->getPiece()->setCouleur(CouleurPiece::Noir);
    this->cases.at(5).at(0)->getPiece()->setType(TypePiece::Fou);
    this->cases.at(5).at(0)->getPiece()->setSprite(FOU_NOIR_IMG);
    this->cases.at(5).at(0)->getPiece()->getSprite()->setPosition(5*Case::TAILLE,0*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(5).at(0)->getPiece()->getSprite());

    this->cases.at(2).at(7)=new Case();
    this->cases.at(2).at(7)->getPiece()->setCouleur(CouleurPiece::Blanc);
    this->cases.at(2).at(7)->getPiece()->setType(TypePiece::Fou);
    this->cases.at(2).at(7)->getPiece()->setSprite(FOU_BLANC_IMG);
    this->cases.at(2).at(7)->getPiece()->getSprite()->setPosition(2*Case::TAILLE,7*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(2).at(7)->getPiece()->getSprite());

    this->cases.at(5).at(7)=new Case();
    this->cases.at(5).at(7)->getPiece()->setCouleur(CouleurPiece::Blanc);
    this->cases.at(5).at(7)->getPiece()->setType(TypePiece::Fou);
    this->cases.at(5).at(7)->getPiece()->setSprite(FOU_BLANC_IMG);
    this->cases.at(5).at(7)->getPiece()->getSprite()->setPosition(5*Case::TAILLE,7*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(5).at(7)->getPiece()->getSprite());
}

void Plateau::dessinerCavaliers()
{
    this->cases.at(1).at(0)=new Case();
    this->cases.at(1).at(0)->getPiece()->setCouleur(CouleurPiece::Noir);
    this->cases.at(1).at(0)->getPiece()->setType(TypePiece::Cavalier);
    this->cases.at(1).at(0)->getPiece()->setSprite(CAVALIER_NOIR_IMG);
    this->cases.at(1).at(0)->getPiece()->getSprite()->setPosition(1*Case::TAILLE,0*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(1).at(0)->getPiece()->getSprite());

    this->cases.at(6).at(0)=new Case();
    this->cases.at(6).at(0)->getPiece()->setCouleur(CouleurPiece::Noir);
    this->cases.at(6).at(0)->getPiece()->setType(TypePiece::Cavalier);
    this->cases.at(6).at(0)->getPiece()->setSprite(CAVALIER_NOIR_IMG);
    this->cases.at(6).at(0)->getPiece()->getSprite()->setPosition(6*Case::TAILLE,0*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(6).at(0)->getPiece()->getSprite());

    this->cases.at(1).at(7)=new Case();
    this->cases.at(1).at(7)->getPiece()->setCouleur(CouleurPiece::Blanc);
    this->cases.at(1).at(7)->getPiece()->setType(TypePiece::Cavalier);
    this->cases.at(1).at(7)->getPiece()->setSprite(CAVALIER_BLANC_IMG);
    this->cases.at(1).at(7)->getPiece()->getSprite()->setPosition(1*Case::TAILLE,7*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(1).at(7)->getPiece()->getSprite());

    this->cases.at(6).at(7)=new Case();
    this->cases.at(6).at(7)->getPiece()->setCouleur(CouleurPiece::Blanc);
    this->cases.at(6).at(7)->getPiece()->setType(TypePiece::Cavalier);
    this->cases.at(6).at(7)->getPiece()->setSprite(CAVALIER_BLANC_IMG);
    this->cases.at(6).at(7)->getPiece()->getSprite()->setPosition(6*Case::TAILLE,7*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(6).at(7)->getPiece()->getSprite());
}

void Plateau::dessinerTours()
{
    this->cases.at(0).at(0)=new Case();
    this->cases.at(0).at(0)->getPiece()->setCouleur(CouleurPiece::Noir);
    this->cases.at(0).at(0)->getPiece()->setType(TypePiece::Tour);
    this->cases.at(0).at(0)->getPiece()->setSprite(TOUR_NOIR_IMG);
    this->cases.at(0).at(0)->getPiece()->getSprite()->setPosition(0*Case::TAILLE,0*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(0).at(0)->getPiece()->getSprite());

    this->cases.at(7).at(0)=new Case();
    this->cases.at(7).at(0)->getPiece()->setCouleur(CouleurPiece::Noir);
    this->cases.at(7).at(0)->getPiece()->setType(TypePiece::Fou);
    this->cases.at(7).at(0)->getPiece()->setSprite(TOUR_NOIR_IMG);
    this->cases.at(7).at(0)->getPiece()->getSprite()->setPosition(7*Case::TAILLE,0*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(7).at(0)->getPiece()->getSprite());

    this->cases.at(0).at(7)=new Case();
    this->cases.at(0).at(7)->getPiece()->setCouleur(CouleurPiece::Blanc);
    this->cases.at(0).at(7)->getPiece()->setType(TypePiece::Fou);
    this->cases.at(0).at(7)->getPiece()->setSprite(TOUR_BLANC_IMG);
    this->cases.at(0).at(7)->getPiece()->getSprite()->setPosition(0*Case::TAILLE,7*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(0).at(7)->getPiece()->getSprite());

    this->cases.at(7).at(7)=new Case();
    this->cases.at(7).at(7)->getPiece()->setCouleur(CouleurPiece::Blanc);
    this->cases.at(7).at(7)->getPiece()->setType(TypePiece::Fou);
    this->cases.at(7).at(7)->getPiece()->setSprite(TOUR_BLANC_IMG);
    this->cases.at(7).at(7)->getPiece()->getSprite()->setPosition(7*Case::TAILLE,7*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(7).at(7)->getPiece()->getSprite());
}

void Plateau::dessinerReines()
{
    this->cases.at(3).at(0)=new Case();
    this->cases.at(3).at(0)->getPiece()->setCouleur(CouleurPiece::Noir);
    this->cases.at(3).at(0)->getPiece()->setType(TypePiece::Reine);
    this->cases.at(3).at(0)->getPiece()->setSprite(REINE_NOIR_IMG);
    this->cases.at(3).at(0)->getPiece()->getSprite()->setPosition(3*Case::TAILLE,0*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(3).at(0)->getPiece()->getSprite());

    this->cases.at(3).at(7)=new Case();
    this->cases.at(3).at(7)->getPiece()->setCouleur(CouleurPiece::Blanc);
    this->cases.at(3).at(7)->getPiece()->setType(TypePiece::Reine);
    this->cases.at(3).at(7)->getPiece()->setSprite(REINE_BLANC_IMG);
    this->cases.at(3).at(7)->getPiece()->getSprite()->setPosition(3*Case::TAILLE,7*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(3).at(7)->getPiece()->getSprite());
}

void Plateau::dessinerRois()
{
    this->cases.at(4).at(0)=new Case();
    this->cases.at(4).at(0)->getPiece()->setCouleur(CouleurPiece::Noir);
    this->cases.at(4).at(0)->getPiece()->setType(TypePiece::Roi);
    this->cases.at(4).at(0)->getPiece()->setSprite(ROI_NOIR_IMG);
    this->cases.at(4).at(0)->getPiece()->getSprite()->setPosition(4*Case::TAILLE,0*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(4).at(0)->getPiece()->getSprite());

    this->cases.at(4).at(7)=new Case();
    this->cases.at(4).at(7)->getPiece()->setCouleur(CouleurPiece::Blanc);
    this->cases.at(4).at(7)->getPiece()->setType(TypePiece::Roi);
    this->cases.at(4).at(7)->getPiece()->setSprite(ROI_BLANC_IMG);
    this->cases.at(4).at(7)->getPiece()->getSprite()->setPosition(4*Case::TAILLE,7*Case::TAILLE);
    this->fenetre->draw(*this->cases.at(4).at(7)->getPiece()->getSprite());
}

#ifndef NDEBUG
#include <cassert>
#ifdef _PLATEAU_UT_
//g++ -o bin/Plateau_UT src/Plateau.cpp -I src -lsfml-graphics -lsfml-system -lsfml-window -D _PLATEAU_UT_
int main()
{
    sf::RenderWindow* fenetre=new sf::RenderWindow(sf::VideoMode(480,480),"Chess",
        sf::Style::Close | sf::Style::Titlebar);
    Plateau plateau(fenetre);
    //sf::RectangleShape test(sf::Vector2f(100,100));//

    while(fenetre->isOpen())
    {
        sf::Event evt;
        while(fenetre->pollEvent(evt))
        {
            if(evt.type==sf::Event::Closed)
                fenetre->close();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                //test.setPosition(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);
                //fenetre->draw(test);
            }
        }
        //fenetre->clear();//
        fenetre->display();
    }

    return 0;
}
#endif
#endif