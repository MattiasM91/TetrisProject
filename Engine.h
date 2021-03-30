#pragma once
#include <SFML/Graphics.hpp>
#include "Movement.h"
#include "Grid.h"
#include "Tetromino.h"
#include "Highscore.h"
#include "Utility.h"
#include "Sound.h"
#include <iostream>

class Engine
{
	friend class Grid;
private:
	sf::Sprite m_BackgroundSprite; //TEST

	int m_TetroId;
	int m_FieldSize;
	sf::Time m_ElapsedTime;

	std::unique_ptr<Grid> m_Grid;
	std::unique_ptr<Tetromino> m_Preview;
	std::shared_ptr<Tetromino> m_Tetromino;
	std::shared_ptr<Tetromino> m_Hold;

	sf::Texture m_Texture;
	sf::Texture m_Background;

	sf::RenderWindow m_Window;
	sf::RectangleShape m_GridBorder;

	sf::RectangleShape m_ScoreBorder;
	sf::RectangleShape m_PreviewBorder;
	sf::RectangleShape m_HoldBorder;

	void update(const sf::Time& gameTime);
	void events();
	void render();
	void createTetromino();
	void rotate();		// TODO: call rotation logic
	void proceed(Movement move);		// TODO: call proceed logic
	void holdAndSwapTetromino();
	void Direction();	// TODO: call Direction logic

	bool CollisionDetection(std::array<sf::Vector2i, 4> block);		// Create grid
	sf::Vector2f m_GridPosition;
	std::shared_ptr<Tetromino> m_CurrentShape;
	std::shared_ptr<Tetromino> m_HoldShape;

	bool isOccupied(int x, int y);
	bool m_HoldEmpty;
	bool m_Swapped;

	Highscore m_HighScore;
	Sound m_Sound;


public:
	Engine();
	void start();
};

