#include "ressources.h"

#include <SFML/Graphics.hpp>

#include <array>

#define PLATEAU_H
#ifdef PLATEAU_H

enum class CouleurPiece
{
    Blanc,
    Noir
};

enum class TypePiece
{
    Roi,
    Reine,
    Fou,
    Tour,
    Cavalier,
    Pion
};

class Piece
{
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    CouleurPiece couleur;
    TypePiece type;

    public:
        Piece();
        Piece(CouleurPiece couleur,TypePiece type,std::string imgPath);
        ~Piece();
        void setSprite(std::string imgPath);
        sf::Sprite* getSprite();
        CouleurPiece getCouleur()const;
        void setCouleur(CouleurPiece couleur);
        TypePiece getType()const;
        void setType(TypePiece type);
};

class Case : public sf::RectangleShape
{
    Piece* piece;
    public:
        static const unsigned short TAILLE=60;
        Case();
        ~Case();
        Piece* getPiece()const;
};

class Plateau
{
    sf::RenderWindow* fenetre;
    std::array<std::array<Case*,8>,8>cases;

    const sf::Color COULEUR_MARRON=sf::Color(112,72,60);
    const sf::Color COULEUR_BLANC=sf::Color::White;
    static const unsigned short DIMENSION=8;

    void dessinerDamier();
    void dessinerPieces();
    void dessinerPions();
    void dessinerFous();
    void dessinerCavaliers();
    void dessinerTours();
    void dessinerReines();
    void dessinerRois();
    public:
        Plateau(sf::RenderWindow* fenetre);
        ~Plateau();
        //un tab de tab de pointeurs
        std::array<std::array<Case*,8>,8> getCases()const;
};
#endif